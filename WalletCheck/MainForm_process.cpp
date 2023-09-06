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
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::IO;

//Public

/// <summary>���b�Z�[�W�_�C�A���O�\�����܂��B</summary>
Void WalletCheck::MainForm::Message(String^ message, String^ title)
{
	MessageBox::Show(message, title, MessageBoxButtons::OK);
}

//Private

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
		_opening_bookpath = CreateNewForm::GetBookPath();	// Form�ɓ��͂��ꂽ�p�X���擾
		char bookpath[CHAR_STR_BUF];	//char�z��`����path��ۑ�����ϐ�
		string_convert::SystemString_to_CString(_opening_bookpath, bookpath);	//filepath��String��char[]

		if (_mkdir(bookpath) != 0)	//filepath�����ƂɃf�B���N�g�����쐬�@���s 
		{
			Message(_opening_bookpath + "���쐬�ł��܂���B\n���ɑ��݂��Ă��邩�A�g�p�ł��Ȃ�Book���ł��B", "�G���[");
			return;
		}

		//�ȉ��f�B���N�g�����쐬�ł����Ƃ�
		char pagepath[CHAR_STR_BUF];
		_opening_year = _GetYear();	//�J���Ă���N�����N��
		_opening_month = _GetMonth();	//�J���Ă��錎��������
		string_convert::SystemString_to_CString(_MakePagePath(_opening_bookpath, _opening_year,_opening_month), pagepath);	//�y�[�W��path���쐬��char[]�ɕϊ�
		ofstream file_stream(pagepath);	//�����̃y�[�W���쐬
		_register_recently(_opening_bookpath);	//�A�v���P�[�V�����ݒ�̍ŋߎg�p�����t�@�C���ɒǉ�
		List<List<String^>^> page_data;
		_OpenBookPage(_opening_bookpath, _opening_year, _opening_month,page_data);
		_load_grid(this,"history_grid", page_data);
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
	_opening_bookpath = bookpath_s;
	_register_recently(_opening_bookpath);	//�ŋߊJ�����t�@�C���ɓo�^
	_opening_year = _GetYear();	// �J���Ă���N�����̔N��
	_opening_month = _GetMonth();	//�J���Ă��錎�����̌���
	auto filenames = Directory::GetFiles(_opening_bookpath, "*.wc.csv");	//�p�X���̃t�@�C���ꗗ���擾
	for (int i = 0; i < filenames->Length; i++)	//�t�@�C�����J��Ԃ�	
	{
		// ���N�A�����̃t�@�C�������邩���ׂ�
		if (filenames[i] == _MakePagePath(_opening_bookpath, _opening_year, _opening_month))
		{
			List<List<String^>^> page_data;
			_OpenBookPage(_opening_bookpath, _opening_year, _opening_month,page_data);	//��������J��
			_load_grid(this,"history_grid",page_data);
			return;
		}
	}
	/*�ȉ������̃t�@�C��������������*/
	/*�t�H���_���̈�ԏ��߂Ɍ��������t�@�C�����J��*/
	//�t�@�C��������N�A�������o�����߂̉��u���ϐ�
	String^ cache_ym;	//YYY
	String^ cache_year;
	String^ cache_month;

	cache_ym = filenames[0]->Replace(_opening_bookpath + "\\", "");	//\�ȑO�̕�������폜
	cache_ym = cache_ym->Replace(".wc.csv", "");	//�g���q�������폜
	for (int i = 0; i < 4; i++)	//�N�����o��
	{
		cache_year += cache_ym[i];
	}
	cache_month = cache_ym->Replace(cache_year + "_", "");//YYYY_MM����YYYY_���폜
	_opening_year = _StringToInt(cache_year);
	_opening_month = _StringToInt(cache_month);
	List<List<String^>^> page_data;
	_OpenBookPage(_opening_bookpath, _opening_year, _opening_month,page_data);
	_load_grid(this,"history_grid", page_data);
}

/// <summary>Book�̃y�[�W���J���܂��B</summary>
Void WalletCheck::MainForm::_OpenBookPage(System::String^ bookpath_s, int year, int month,List<List<String^>^>% return_L)
{
	char pagepath[CHAR_STR_BUF];	//�y�[�W�ւ�path��char[]�ɓ����ϐ�
	history_grid->Rows->Clear();	//�\�̍��ڂ�S�폜
	string_convert::SystemString_to_CString(_MakePagePath(bookpath_s, year, month), pagepath);
	if (filesystem::is_regular_file(pagepath) == false)	//�y�[�W�̃t�@�C�������݂��Ȃ�������
	{
		ofstream output_file(pagepath);	//�y�[�W�̃t�@�C����V�K�쐬
		_OpenBookPage(bookpath_s, year, month,return_L);	//�ċA�I��OpenBookPage
		_load_grid(this,"history_grid",return_L);
		return;	//���f
	}
	
	// �ȉ��y�[�W�̃t�@�C�������݂����Ƃ�
	ifstream input_file(pagepath);	//���̓t�@�C���X�g���[��
	string bufstr;	// 1�s���ƂɎ擾���镶��������u������ϐ�


	while (getline(input_file, bufstr))	//�s�P�ʂŕ�������擾
	{
		//1�s��csv��vector�ɕϊ�
		List<String^> str_comma_L;
		csv_manager::Parse(string_convert::string_to_SystemString(bufstr),str_comma_L);;
		return_L.Add(%str_comma_L);
	}
	month_label->Text = year + "�N " + month + "��";	//�N�����x�����J���Ă���t�@�C���̕��ɍX�V
	bookname_label->Text = _GetBookname_From_Path(bookpath_s);	//Book�����p�X����擾�����x�����X�V

	previous_button->Enabled = true;	//�O��̃y�[�W�Ɉړ��ł���悤�ɂ���
	next_button->Enabled = true;
}

/// <summary>Book��ۑ����܂��B</summary>
Void WalletCheck::MainForm::_SaveBook(System::String^ bookpath_s, int year, int month)
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
Void WalletCheck::MainForm::_load_grid(Object^ sender,String^ gridname, List<List<String^>^>% values)
{
	DataGridView^ grid = (DataGridView^)this->Controls->Find(gridname, true)[0];

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

int WalletCheck::MainForm::_sort_donutdata(DonutData^ a, DonutData^ b)
{

	return 0;
}

/// <summary>�O���t��`�悵�܂��B</summary>
Void WalletCheck::MainForm::_load_donut_graph(Object^ targetform, String^ chartname,List<DonutData^>% donutdata)
{
	Form^ form = (Form^)targetform;
	Chart^ chart = (Chart^)form->Controls->Find(chartname,true)[0];
	chart->Series[0]->Points->Clear();

	//donutdata.Sort();

	for (int i = 0; i < donutdata.Count; i++)
	{
		DataPoint^ dp = gcnew DataPoint(0,donutdata[i]->value);
		chart->Series[0]->Points->Add(dp);
		chart->Series[0]->Points[i]->LegendText = donutdata[i]->text;
	}
	
}

Void WalletCheck::MainForm::_load_monthly_balance_graph()
{
	
	List<List<String^>^> grid_data;
	_OpenBookPage(_opening_bookpath, _opening_year, _opening_month,grid_data);

	int spending = 0;
	int income = 0;
	for (int i = 0; i < grid_data.Count; i++)
	{
		
		List<String^>^ row = grid_data[i];
		
		if (Int64::Parse(row[4]) > 0)
		{
			income += Int64::Parse(row[4]);
		}
		else
		{
			spending += Int64::Parse(row[4]);
		}
		
		List<DonutData^> donut_data;
		DonutData^ data = gcnew DonutData;
		data->value = spending;
		data->text = "�x�o";
		donut_data.Add(data);
		data = gcnew DonutData;
		data->value = income;
		data->text = "����";
		donut_data.Add(data);

		_load_donut_graph(this,"monthly_balance_chart", donut_data);
	}
};


