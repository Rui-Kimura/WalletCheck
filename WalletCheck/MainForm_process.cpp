/*
	MainForm_Process.cpp
	MainForm�̒�`�����ł��B
*/

#define UPDATE_CHECK_URL "http://runachama.com/WalletCheck/files/newest/version.txt"	
#define UPDATER_URL "http://runachama.com/WalletCheck/files/newest/Update.zip"
#define UPDATER_ZIP "Update.zip"
#define UPDATER_NAME "Update.exe"

//�ŐV�̃o�[�W��������URL�iGoogleDrive�t�@�C���������N�j

#include "MainForm.h"
#include "CreateNewForm.h"
#include "AddDataForm.h"
#include "app_config.h"
#include "string_convertr.h"
#include "csv.h"
#include <fstream>
#include <sstream>
#include <direct.h>
#include <filesystem>
using namespace System::Windows::Forms::DataVisualization::Charting;

using namespace app_config;
using namespace string_converter;
using namespace csv;

using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Configuration;
using namespace System::Drawing;
using namespace System::Diagnostics;
using namespace System::IO;
using namespace System::IO::Compression;
using namespace System::Net;
using namespace System::Windows::Forms;

//Public

/// <summary>���b�Z�[�W�_�C�A���O�\�����܂��B</summary>
Void WalletCheck::MainForm::Message(String^ message, String^ title)
{
	MessageBox::Show(message, title, MessageBoxButtons::OK);
}

int WalletCheck::MainForm::check_update()
{
	return _check_update();
}

//Private

/// <summary>�Ώۂ̌^�̌Ăяo�����ȉ��̎q�R���g���[����񋓂��܂��B</summary>
Void WalletCheck::MainForm::find_control(Object ^ sender, Type ^ type, List<Control^>% list)
{
	Control^ sender_control = (Control^)sender;

	for each (Control ^ c_control in sender_control->Controls)
	{
		if (c_control->GetType()->Equals(type))	//���߂Ă���^�Ɠ�����������
		{
			list.Add(c_control);
		}
		if (!c_control->GetType()->Equals(FlowLayoutPanel::typeid))	//FlowLayoutPanel�̓��C�A�E�g�ɉe����^����̂ŏ��O
			find_control(c_control, type, list);
	}
}

//�R���g���[���̐e��ݒ肵�܂��B
Void WalletCheck::MainForm::_set_parent(Object^ sender)
{
	List<Control^> panels;
	find_control(sender,Panel::typeid, panels);
	for each (Control ^ control in panels)
	{
		List<Control^> chart;
		List<Control^> other_controls;

		find_control(control, Chart::typeid, chart);	//chart��T��
		find_control(control, Label::typeid, other_controls);	//label��T��
		find_control(control, FlowLayoutPanel::typeid, other_controls);	//FlowLayoutPanel��T��
		if (chart.Count > 0 && other_controls.Count > 0)
		{
			for each (Control ^ c_control in other_controls)
			{
				c_control->Parent = chart[0];	//label,FlowLayoutPanel�̐e��chart��ݒ�
			}
		}
	}
}



/// <summary>�����̌����擾���܂��B</summary>
int WalletCheck::MainForm::_GetYear()
{
	return _StringToInt(System::DateTime::Now.ToString("yyyy"));
}

/// <summary>���̌����擾���܂��B</summary>
int WalletCheck::MainForm::_GetMonth()
{
	return _StringToInt(System::DateTime::Now.ToString("MM"));
}

/// <summary>Book�̃p�X����Book���𔲂��o���܂��B</summary>
String^ WalletCheck::MainForm::_GetBookname_From_Path(System::String^ path)
{
	System::String^ bookname;
	int count = (int)(path->Length) - 1;	// ���݂̕�����path��ł̃J�[�\���ʒu
	while (path[count] != '\\')
	{
		bookname = path[count] + bookname;
		count--;	//�E���獶��\�𑖍����Ă���
	}

	return bookname;
}

/// <summary>�y�[�W�̃p�X����N�A���𔲂��o���܂��B</summary>
Void WalletCheck::MainForm::_GetYearMonth_From_PagePath(String^ pagepath, int% year, int% month)
{
	String^ cache_year;	
	String^ cache_month;

	pagepath = pagepath->Replace(_opening_bookpath + "\\", "");	//\�ȑO�̕�������폜
	pagepath = pagepath->Replace(".wc.csv", "");	//�g���q�������폜
	for (int i = 0; i < pagepath->Length; i++)	//�N�����o��
	{
		wchar_t letter = pagepath[i];
		if (letter == '_')	//�������A���_�[�o�[��������
			break;			//for��~

		cache_year += letter;
	}
	cache_month = pagepath->Replace(cache_year + "_", "");//YYYY_MM����YYYY_���폜

	year = _StringToInt(cache_year);
	month = _StringToInt(cache_month);
}

/// <summary>���������ƂɃy�[�W�̃p�X���쐬���܂��B</summary>
String^ WalletCheck::MainForm::_MakePagePath(String^ bookpath_s, int year, int month)
{
	return bookpath_s + "\\" + year + "_" + month + ".wc.csv";	///�p�X���`\book��\YYYY_M.csv�ɐ��`
}

/// <summary>String��int�ɕϊ����܂��B</summary>
long long  WalletCheck::MainForm::_StringToInt(String^ strnum)
{
	return Int64::Parse(strnum);
}

/// <summary>Book��V�K�ɍ쐬���܂��B</summary>
Void WalletCheck::MainForm::_CreateBook()
{
	Form^ createnewdialog = gcnew CreateNewForm();	// Book�V�K�쐬����Form��gcnew����
	if (createnewdialog->ShowDialog(this).ToString() == "OK")		//Form��\�����Č��ʂ�OK���m���߂�
	{
		String^ bookpath_s = CreateNewForm::GetBookPath();	// Form�ɓ��͂��ꂽ�p�X���擾
		char bookpath[CHAR_STR_BUF];	//char�z��`����path��ۑ�����ϐ�
		string_convert::SystemString_to_CString(bookpath_s, bookpath);	//filepath��String��char[]

		if (_mkdir(bookpath) != 0)	//filepath�����ƂɃf�B���N�g�����쐬�@���s 
		{
			Message(bookpath_s + "���쐬�ł��܂���B\n���ɑ��݂��Ă��邩�A�g�p�ł��Ȃ�Book���ł��B", "�G���[");
			return;
		}

		//�ȉ��f�B���N�g�����쐬�ł����Ƃ�
		char pagepath[CHAR_STR_BUF];
		int year = _GetYear();	//�J���Ă���N�����N��
		int month = _GetMonth();	//�J���Ă��錎��������
		string_convert::SystemString_to_CString(_MakePagePath(bookpath_s, year,month), pagepath);	//�y�[�W��path���쐬��char[]�ɕϊ�
		ofstream file_stream(pagepath);	//�����̃y�[�W���쐬
		_register_recently(bookpath_s);	//�A�v���P�[�V�����ݒ�̍ŋߎg�p�����t�@�C���ɒǉ�
		List<List<String^>^> page_data;
		_OpenBookPage(bookpath_s, year, month, page_data);
		_SetOpening(bookpath_s,year,month);
		_load_grid_and_graph();
		tabs->SelectedIndex = 0;
		tabs->Enabled = true;
	}
}

/// <summary>Book���J���܂��B</summary>
Void WalletCheck::MainForm::_OpenBook(String^ bookpath_s)
{
	if (Directory::GetFiles(bookpath_s, "*.wc.csv")->Length < 1)	//����csv�t�@�C��������������
	{
		Message("Book�̃y�[�W��������܂���ł����B", "�G���[");
		_opening_bookpath = "";
		return;
	}
	//�ȉ�csv�t�@�C��������������
	_register_recently(bookpath_s);	//�ŋߊJ�����t�@�C���ɓo�^
	int year = _GetYear();	// �J���Ă���N�����̔N��
	int month = _GetMonth();	//�J���Ă��錎�����̌���
	auto filenames = Directory::GetFiles(bookpath_s, "*.wc.csv");	//�p�X���̃t�@�C���ꗗ���擾
	for (int i = 0; i < filenames->Length; i++)	//�t�@�C�����J��Ԃ�	
	{
		// ���N�A�����̃t�@�C�������邩���ׂ�
		if (filenames[i] == _MakePagePath(bookpath_s, year, month))
		{
			List<List<String^>^> page_data;
			_OpenBookPage(bookpath_s, year, month, page_data);	//��������J��
			_SetOpening(bookpath_s, year, month);
			return;
		}
	}

	/*�ȉ������̃t�@�C��������������*/
	/*�t�H���_���̈�ԏ��߂Ɍ��������t�@�C�����J��*/
	//�t�@�C��������N�A�������o�����߂̉��u���ϐ�
	_GetYearMonth_From_PagePath(filenames[0], year, month);
	List<List<String^>^> page_data;
	_OpenBookPage(bookpath_s, year, month, page_data);
	_SetOpening(bookpath_s, year, month);
}

/// <summary>Book�̃y�[�W���J���܂��B</summary>
Void WalletCheck::MainForm::_OpenBookPage(System::String^ bookpath_s, int year, int month,List<List<String^>^>% return_L)
{
	char pagepath[CHAR_STR_BUF];	//�y�[�W�ւ�path��char[]�ɓ����ϐ�
	string_convert::SystemString_to_CString(_MakePagePath(bookpath_s, year, month), pagepath);
	
	if (filesystem::is_regular_file(pagepath) == false)	//�y�[�W�̃t�@�C�������݂��Ȃ�������
	{
		ofstream output_file(pagepath);	//�y�[�W�̃t�@�C����V�K�쐬
		_OpenBookPage(bookpath_s, year, month,return_L);	//�ċA�I��OpenBookPage
		return;	//���f
	}
	
	// �ȉ��y�[�W�̃t�@�C�������݂����Ƃ�
	ifstream input_file(pagepath);	//���̓t�@�C���X�g���[��
	string bufstr;	// 1�s���ƂɎ擾���镶��������u������ϐ�
	

	while (getline(input_file, bufstr))	//�s�P�ʂŕ�������擾
	{
		//1�s��csv��vector�ɕϊ�
		List<String^> str_comma_L;
		csv_manager::Parse(string_convert::string_to_SystemString(bufstr),str_comma_L);
		if (str_comma_L.Count != 5)	//�f�[�^��5�łȂ�������
		{
			Message("�j�������f�[�^�ł��B�j�������f�[�^�͍폜����܂��B", "�G���[");
		}
		else
		{
			return_L.Add(% str_comma_L);
		}
	}
}

Void WalletCheck::MainForm::_SetOpening(String^ bookpath, int year, int month)
{
	_opening_bookpath = bookpath;
	_opening_year = year;
	_opening_month = month;
}

/// <summary>Book��ۑ����܂��B</summary>
Void WalletCheck::MainForm::_SaveBookPage(System::String^ bookpath_s, int year, int month)
{
	history_grid->Sort(history_grid->Columns[0], ListSortDirection::Ascending);	//���t�����Ƃɕ��ёւ�

	char bookpath[CHAR_STR_BUF];	//book�̃p�X��char�z��Ŋi�[����
	string_convert::SystemString_to_CString(_MakePagePath(bookpath_s, year, month), bookpath);

	ofstream output_file(bookpath, ios::trunc);	//�㏑�����[�h�ŏo�̓t�@�C���X�g���[��

	for (int i = 0; i < history_grid->Rows->Count; i++)	//�s�̕��J��Ԃ�
	{
		char cell[5][128];	//�Z���̓��e��char�z��ɂ��Ċi�[���Ă����ϐ�
		for (int n = 0; n < 5; n++)	//5�񕪌J��Ԃ�
		{
			string_convert::SystemString_to_CString(history_grid->Rows[i]->Cells[n]->Value->ToString(), cell[n]);	//char�z��ɃZ���̓��e���i�[
		}

		for (int i = 0; i < 4; i++)	//4��J��Ԃ�
		{
			output_file << cell[i] << ',';	//�t�@�C���ɏ�������
		}

		output_file << cell[4] << endl;;	//�Ōゾ���R���}�Ȃ����s
	}
}

/// <summary>DataGridView�ɒl��ǉ����܂��B</summary>
Void WalletCheck::MainForm::_load_grid(String^ gridname, List<List<String^>^>% values)
{
	DataGridView^ grid = (DataGridView^)this->Controls->Find(gridname, true)[0];
	grid->Rows->Clear();
	for (int i = 0; i < values.Count; i++)
	{
		grid->Rows->Add();	//�\�ɋ�̍s��ǉ�
		int endofindex = grid->Rows->Count - 1;	// ���[�̍s=�ǉ�������̍s��index
		for (int n = 0; n < values[i]->Count; n++)	//�s�̕��J��Ԃ�
		{
			List <String^>^ value_s = values[i];
			int bufi;
			if (Int32::TryParse(value_s[n], bufi))	///�l�����l�Ȃ�
			{
				grid->Rows[endofindex]->Cells[n]->Value = _StringToInt(value_s[n]);	//�Z���ɐ��l�Ƃ��Ēǉ�
			}
			else
			{
				grid->Rows[endofindex]->Cells[n]->Value = value_s[n];	//����ȊO�͕�����
			}
		}
	}
	_diaplay_pageinfo();
}

/// <summary>�y�[�W�̏������x���Ȃǂɕ\�����܂��B</summary>
Void WalletCheck::MainForm::_diaplay_pageinfo()
{
	String^ bookname = _GetBookname_From_Path(_opening_bookpath);	//Book�����p�X����擾�����x�����X�V

	month_label->Text = _opening_year + "�N " + _opening_month + "��";	//�N�����x�����J���Ă���t�@�C���̕��ɍX�V
	bookname_label->Text = bookname;
	this->Text = bookname + " - WalletCheck";

	previous_button->Enabled = true;	//�O��̃y�[�W�Ɉړ��ł���悤�ɂ���
	next_button->Enabled = true;
}

/// <summary>�A�v���P�[�V�����ݒ�̍ŋߎg�����t�@�C���ɓo�^���܂��B</summary>
Void WalletCheck::MainForm::_register_recently(String^ bookpath_s)
{
	String^ path_to_write = config::Get("RecentBook0");	//�������ރp�X
	String^ cache;	//�������ݐ�̃f�[�^�����ۑ����ĕی삷��ϐ�
	for (int i = 1; i < 5; i++)	//5���闚�𕪌J��Ԃ�
	{
		if (path_to_write == bookpath_s)	//�������ރp�X�����ꂩ��o�^����p�X�ƈ�v������
			break;	//���f�������̏d���΍�

		cache = config::Get("RecentBook" + i);	//�������ݐ�̃p�X���㏑�������̂Ŏ��o���ĕی�
		config::Set("RecentBook" + i, path_to_write);	//���̗����ɏ�������
		path_to_write = cache;	//�������ރp�X�ɕی삵���p�X��o�^
	}
	config::Set("RecentBook0", bookpath_s);
	_show_recentbook_toolstripmenu();
/*
[�����]
_____________________________________________________________________________________________
����0|	path1									path6									path3
����1|	path2									path1									path6
����2|	path3	��	������path6��o�^�����	��	path2	��	������path3��o�^�����	��	path1
����3|	path4									path3									path2
����4|	path5									path4									path4
_____________________________________________________________________________________________	
*/
}

/// <summary>ToolStrip�̍ŋߎg����Book��\�����܂��B</summary>
Void WalletCheck::MainForm::_show_recentbook_toolstripmenu()
{
	String^ recentbookpath;
	for (int i = 0; i < 5; i++)
	{
		recentbookpath = config::Get("RecentBook" + i);	//i�Ԗڂ̗�����config����擾
		if (recentbookpath != "")
		{
			RecentBookToolStripMenuItem->Enabled = true;	//�h�ŋ߂̃t�@�C���h��L����
			RecentBookToolStripMenuItem->DropDownItems[i]->Visible = true;	//i�Ԗڂ̗����̃A�C�e����\��
			RecentBookToolStripMenuItem->DropDownItems[i]->Text = recentbookpath;	//�A�C�e���̃e�L�X�g���p�X��
		}
	}
}

Void WalletCheck::MainForm::_sort_donutdata_list(List<DonutData^>% list)
{
	//�f�[�^��l�Ő��񂷂�
	/// TODO:�]�T������΃N�C�b�N�\�[�g�ȂǂɕύX����
	for (int i = 0; i < list.Count; i++)
	{
		int max_index = 0;
		for (int n = i; n < list.Count; n++)
		{
			if (abs(list[n]->value) < abs(list[i]->value))
			{
				max_index = n;
			}
		}
		DonutData^ d = list[i];
		list[i] = list[max_index];
		list[max_index] = d;
	}

	//���̑��͈�ԍŌ�ɂ���
	for (int i = 0; i < list.Count; i++)
	{
		if (list[i]->text == "���̑�")
		{
			DonutData^ cache = list[i];
			list.RemoveAt(i);
			list.Add(cache);
		}
	}
}
/// <summary>�O���t��`�悵�܂��B</summary>
Void WalletCheck::MainForm::_load_donut_graph(Object^ targetform, String^ chartname,List<DonutData^>% donutdata)
{
	Form^ form = (Form^)targetform;
	Chart^ chart = (Chart^)form->Controls->Find(chartname,true)[0];
	chart->Series[0]->Points->Clear();

	_sort_donutdata_list(donutdata);

	for (int i = 0; i < donutdata.Count; i++)
	{
		DataPoint^ dp = gcnew DataPoint(0,donutdata[i]->value);
		chart->Series[0]->Points->Add(dp);
		chart->Series[0]->Points[i]->LegendText = donutdata[i]->text;
	}
}

/// <summary>���x�̃O���t��ǂݍ��݂܂��B</summary>
Void WalletCheck::MainForm::_load_balance_graph(String^ chartname, long long% spending, long long% income)
{
	Chart^ chart  = (Chart^)this->Controls->Find(chartname, true)[0];

	List<DonutData^> donut_data;
	DonutData^ data = gcnew DonutData(spending, "�x�o");
	donut_data.Add(data);
	data = gcnew DonutData(income, "����");
	donut_data.Add(data);
	_load_donut_graph(this, chartname, donut_data);
	if (abs(spending) > income)
	{
		chart->Series[0]->Points[0]->Color = Color::DeepPink;
		chart->Series[0]->Points[1]->Color = Color::DeepSkyBlue;
	}
	else
	{
		chart->Series[0]->Points[0]->Color = Color::DeepSkyBlue;
		chart->Series[0]->Points[1]->Color = Color::DeepPink;
	}
}

/// <summary>���Ԏ��x���擾���܂��B</summary>
Void WalletCheck::MainForm::_get_monthly_spending_and_income(int year, int month, long long% spending, long long% income)
{
	List<List<String^>^> grid_data;
	_OpenBookPage(_opening_bookpath, year, month, grid_data);

	for each(List<String^>^ row in grid_data)
	{
		long long money = _StringToInt(row[4]);
		if (money > 0)	//���z�����Ȃ����
		{
			income += money;
		}
		else
		{
			spending += money;
		}
	}
}

/// <summary>���Ԏ��x�̃O���t��ǂݍ��݂܂��B</summary>
Void WalletCheck::MainForm::_load_monthly_balance_graph()
{

	long long spending = 0;
	long long income = 0;
	_get_monthly_spending_and_income(_opening_year, _opening_month, spending, income);
	_load_balance_graph("monthly_balance_chart",spending,income);
	monthly_label->Text = _opening_month + "���̎��x";
	monthly_income->Text = "�����F" + income.ToString("C0");
	monthly_spending->Text = "�x�o�F" + spending.ToString("C0");

};

/// <summary>�N�Ԏ��x���擾���܂��B</summary>
Void WalletCheck::MainForm::_get_yearly_spending_and_income(int year, long long% spending, long long% income)
{
	spending = 0;
	income = 0;
	for (int i = 1; i <= 12; i++)	//12�J���J��Ԃ�
	{
		int month = i;	
		_get_monthly_spending_and_income(year, month, spending, income);
	}
}

/// <summary>�N�Ԏ��x�̃O���t��ǂݍ��݂܂��B</summary>
Void WalletCheck::MainForm::_load_yearly_balance_graph()
{
	long long spending = 0;
	long long income = 0;
	_get_yearly_spending_and_income(_opening_year, spending, income);
	_load_balance_graph("yearly_balance_chart", spending, income);
	yearly_label->Text = _opening_year + "�N�̎��x";
	yearly_income->Text = "�����F" + income.ToString("C0");
	yearly_spending->Text = "�x�o�F" + spending.ToString("C0");
}

/// <summary>�J�e�S���ʌ��Ԏ��x���擾���܂��B</summary>
Void WalletCheck::MainForm::_get_monthly_category(int year, int month, List<DonutData^>% data,bool type)
{

	List<List<String^>^> bookdata;
	_OpenBookPage(_opening_bookpath, year, month, bookdata);
	for each(List<String^>^ row in bookdata)
	{
		long long money = _StringToInt(row[4]);
		if (money < 0 && type)
			continue;
		if (money > 0 && !type)
			continue;
		String^ category = row[1];
		int data_index = -1;

		// data���Ɋ��ɑ��݂���J�e�S�������ׁA���݂��Ă�����index���擾����
		for (int i = 0; i < data.Count; i++)
		{
			if (data[i]->text == category)
			{
				data_index = i;
				break;
			}
		}

		if (data_index == -1)	//index�������l�̂܂܁��V�����J�e�S��
		{
			DonutData^ donutdata = gcnew DonutData(money, category);
			data.Add(donutdata);
		}
		else	//�w���index�̃J�e�S���̋��z�ɒǉ�
		{
			data[data_index]->value += money;
		}
	}
}

/// <summary>�J�e�S���ʌ��Ԏx�o�̃O���t��ǂݍ��݂܂��B</summary>
Void WalletCheck::MainForm::_load_monthly_category_spending_graph()
{
	List<DonutData^> data;
	long long spending = 0;
	long long income = 0;
	_get_monthly_spending_and_income(_opening_year, _opening_month, spending,income);
	_get_monthly_category(_opening_year, _opening_month, data,false);
	_load_donut_graph(this, "monthly_category_spending_chart", data);
	monthly_category_spending_label->Text = _opening_month + "���̃J�e�S���ʎx�o";
	monthly_category_spending->Text = "�x�o�F" + spending.ToString("C0");
}

/// <summary>�J�e�S���ʔN�Ԏx�o��ǂݍ��݂܂��B</summary>
Void WalletCheck::MainForm::_get_yearly_category(int year, List<DonutData^>% data,bool type)
{
	for (int i = 1; i <= 12; i++)
	{
		int month = i;
		_get_monthly_category(year, month, data,type);
	}
}

/// <summary>�J�e�S���ʔN�Ԏx�o�̃O���t��ǂݍ��݂܂��B </summary>
Void WalletCheck::MainForm::_load_yearly_category_spending_graph()
{
	List<DonutData^> data;
	long long spending = 0;
	long long income = 0;
	_get_yearly_spending_and_income(_opening_year,spending, income);
	_get_yearly_category(_opening_year, data,false);
	_load_donut_graph(this, "yearly_category_spending_chart", data);
	yearly_category_spending_label->Text = _opening_year + "�N�̃J�e�S���ʎx�o";
	yearly_category_spending->Text = "�x�o�F" + spending.ToString("C0");
}

/// <summary>�J�e�S���ʌ��Ԏ����̃O���t��ǂݍ��݂܂��B</summary>
Void WalletCheck::MainForm::_load_monthly_category_income_graph()
{
	List<DonutData^> data;
	long long spending = 0;
	long long income = 0;
	_get_monthly_spending_and_income(_opening_year, _opening_month, spending, income);
	_get_monthly_category(_opening_year, _opening_month, data, true);
	_load_donut_graph(this, "monthly_category_income_chart", data);
	monthly_category_income_label->Text = _opening_month + "���̃J�e�S���ʎ���";
	monthly_category_income->Text = "�����F" + income.ToString("C0");
}

/// <summary>�J�e�S���ʔN�Ԏ����̃O���t��ǂݍ��݂܂��B</summary>
Void WalletCheck::MainForm::_load_yearly_category_income_graph()
{
	List<DonutData^> data;
	long long spending = 0;
	long long income = 0;
	_get_yearly_spending_and_income(_opening_year, spending, income);
	_get_yearly_category(_opening_year, data, true);
	_load_donut_graph(this, "yearly_category_income_chart", data);
	yearly_category_income_label->Text = _opening_year + "�N�̃J�e�S���ʎ���";
	yearly_category_income->Text = "�����F" + income.ToString("C0");
}

/// <summary>�x���ʗ\�Z���擾���܂��B</summary>
Void WalletCheck::MainForm::_get_budget_payment(List<DonutData^>% data)
{
	List<DonutData^> donutdata_L;
	auto filenames = Directory::GetFiles(_opening_bookpath, "*.wc.csv");	//�p�X����.wc.csv�t�@�C���ꗗ���擾
	for each (String^ filename in filenames)
	{
		List<List<String^>^> pagedata;
		int year, month;
		_GetYearMonth_From_PagePath(filename,year,month);
		_OpenBookPage(_opening_bookpath, year, month,pagedata);

		
		for each (List<String^> ^ row in pagedata)
		{
			long long money = _StringToInt(row[4]);
			String^ payment = row[3];
			int data_index = -1;
			// data���Ɋ��ɑ��݂���J�e�S�������ׁA���݂��Ă�����index���擾����
			for (int i = 0; i < data.Count; i++)
			{
				if (data[i]->text == payment)
				{
					data_index = i;
					break;
				}
			}
			if (data_index == -1)	//index�������l�̂܂܁��V�����J�e�S��
			{
				DonutData^ donutdata = gcnew DonutData(money, payment);
				data.Add(donutdata);
			}
			else	//�w���index�̃J�e�S���̋��z�ɒǉ�
			{
				data[data_index]->value += money;
			}
		}
	}
}

/// <summary>�\�Z�̃O���t��ǂݍ��݂܂��B</summary>
Void WalletCheck::MainForm::_load_budget_graph()
{
	List<DonutData^> donutdata;
	_get_budget_payment(donutdata);
	_load_donut_graph(this, "budget_chart", donutdata);
	DataPointCollection^ dpc = budget_chart->Series[0]->Points;
	long long budget = 0;
	for each (DataPoint ^ dp in dpc)
	{
		budget += dp->YValues[0];
	}
	budget_value->Text = "���\�Z�F" + budget.ToString("C0");
}

/// <summary>�x���ʗ\�Z��ǂݍ��݂܂��B</summary>
Void WalletCheck::MainForm::_load_budget_payment()
{
	FlowLayoutPanel^ fp = (FlowLayoutPanel^)splitContainer4->Panel2->Controls->Find("flowLayoutPanel3",true)[0];
	DataPointCollection^ dpc = budget_chart->Series[0]->Points;
	
	int count = 0;
	fp->Controls->Clear();
	for each (DataPoint^ dp in dpc)
	{
		Label^ label = gcnew Label();
		label->Name = "payment" + count;
		label->Text = dp->LegendText + "\n" + dp->YValues[0].ToString("C0");
		label->Font = fp->Font;
		label->AutoSize = true;
		label->Visible = true;
		label->Margin = System::Windows::Forms::Padding(5);
		fp->Controls->Add(label);
	}
}

/// <summary>�\�ƃO���t��ǂݍ��݂܂��B</summary>
Void WalletCheck::MainForm::_load_grid_and_graph()
{
	List<List<String^>^> grid_data;
	_OpenBookPage(_opening_bookpath, _opening_year, _opening_month, grid_data);
	_load_grid("history_grid", grid_data);	//�\��ǂݍ���
	_load_yearly_balance_graph();	//���Ԏ��x��ǂݍ���
	_load_monthly_balance_graph();	//�N�Ԏ��x��ǂݍ���
	_load_monthly_category_spending_graph();	//�J�e�S���ʌ��Ԏx�o��ǂݍ���
	_load_yearly_category_spending_graph();		//�J�e�S���ʔN�Ԏx�o��ǂݍ���
	_load_monthly_category_income_graph();		//�J�e�S���ʌ��Ԏ�����ǂݍ���
	_load_yearly_category_income_graph();		//�J�e�S���ʔN�Ԏ�����ǂݍ���
	_load_budget_graph();	//�\�Z�̃O���t��ǂݍ���
	_load_budget_payment();	//���ϕʗ\�Z�ꗗ��ǂݍ���*/
	tabs->Enabled = true;
	delete_data_button->Enabled = true;
}

/// <summary>�t�H���g�T�C�Y���t�H�[���̍����ɂ���Ē��߂��܂��B</summary>
Void WalletCheck::MainForm::_resize_fontsize(Object^ sender, EventArgs^ e)
{
	Control^ control = (Control^)sender;
	float px = ((float)this->Height / (float)_form_height) * 12.0;
	px = px < 12 ? 12 : px;

	for each (Control ^ c in control->Controls)
	{
		c->Font = gcnew System::Drawing::Font(c->Font->OriginalFontName, px);
		_resize_fontsize(c,e);	//�ċA�I�Ɏq�R���g���[���ȉ����ׂẴR���g���[���ɓK�p����B
	}
}

int WalletCheck::MainForm::_check_update()
{
	String^ newest;
	WebClient^ wc = gcnew WebClient();
	try
	{
		newest = wc->DownloadString(UPDATE_CHECK_URL)->ToString();	//�ŐV�̃o�[�W���������擾
	}
	catch(Exception^ e)
	{
		return -1;
	}
	String^ now = Application::ProductVersion;	//���݂̃o�[�W����
	config::Set("LastUpdate", DateTime::Now.ToString());
	if (now != newest)	//�ŐV�o�[�W�����łȂ�������
	{
		String^ msg = "�V�����o�[�W����" + newest + "������܂��B\n�A�b�v�f�[�g���܂����H";
		if (MessageBox::Show(msg,"�A�b�v�f�[�g", MessageBoxButtons::YesNo).ToString() == "Yes")
		{
			if (_download_updater() == 0)
			{
				Process::Start("Update.exe");
				Application::Exit();
				return 0;
			}
			else
			{
				Message("�A�b�v�f�[�^�[�̃_�E�����[�h�Ɏ��s���܂����B", "");
				return -1;
			}

		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

int WalletCheck::MainForm::_download_updater()
{
	WebClient^ wc = gcnew WebClient();
	try
	{
		wc->DownloadFile(UPDATER_URL, UPDATER_ZIP);	//�ŐV�̃A�b�v�f�[�^�[���擾
	}
	catch (Exception^ e)
	{
		return -1;
	}

	try
	{
		File::Delete(UPDATER_NAME);	//�����̃A�b�v�f�[�^�[������
	}
	catch (Exception^ e){}
	ZipFile::ExtractToDirectory(UPDATER_ZIP,"./");	//Zip��W�J����
	File::Delete(UPDATER_ZIP);
	
	return 0;
}