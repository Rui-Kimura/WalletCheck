#include "MainForm.h"
#include "app_config.h"
#include "string_convertr.h"
#include <filesystem>
using namespace System::Windows::Forms::DataVisualization::Charting;

using namespace app_config;
using namespace string_converter;

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Configuration;
using namespace System::Collections::Generic;

// MainForm�����[�h�h���ꂽ���̃C�x���g
Void WalletCheck::MainForm::MainForm_Load(Object^ sender, EventArgs^ e)
{
	_opening_bookpath = config::Get("RecentBook0");	// �Ō�ɓǂݍ��܂ꂽ�t�@�C���̃p�X��ݒ肩��擾����
	if (config::Get("OpenLastFile") == "true" && _opening_bookpath != "")	//�����Ō�Ɏg�����t�@�C���̓ǂݍ��݂��L���ŁA�p�X����������
	{
		_opening_year = _GetYear();	// �J���Ă���N�ɍ��̔N���Z�b�g
		_opening_month = _GetMonth();	// �J���Ă��錎�ɍ��̌����Z�b�g
		char bookpath[CHAR_STR_BUF];//book�̃p�X�����Ă���char�z��
		string_convert::SystemString_to_CString(_opening_bookpath, bookpath);
		List<List<String^>^> grid_data;
		_OpenBookPage(_opening_bookpath, _opening_year, _opening_month,grid_data);
		_load_grid(this,"history_grid", grid_data);
	}
	_show_recentbook_toolstripmenu();

}

// �^�u�ɕ`��X�V���N�����Ƃ��̃C�x���g
System::Void WalletCheck::MainForm::tabs_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e)
{
	TabControl^ tabs = (TabControl^)sender;	//tab�̃I�u�W�F�N�g���擾
	String^ tab_str = tabs->TabPages[e->Index]->Text;	//�^�u�̃e�L�X�g���擾
	Brush^ background_brush;	//�w�i�F�̃u���V
	Brush^ text_brush;	//�e�L�X�g�F�̃u���V
	if ((e->State & DrawItemState::Selected) == DrawItemState::Selected)	//�^�u���I������Ă�����
	{
		background_brush = Brushes::MAINCOLOR_LIGHT;
		text_brush = Brushes::TEXTCOLOR_LIGHT;
	}
	else	//�^�u���I������Ă��Ȃ�������
	{
		background_brush = Brushes::MAINCOLOR_DARK;
		text_brush = Brushes::TEXTCOLOR_DARK;
	}

	StringFormat^ sformat = gcnew StringFormat();	//������̃t�H�[�}�b�g�X�^�C�����C���X�^���X��
	sformat->Alignment = StringAlignment::Center;	//���E��������
	sformat->LineAlignment = StringAlignment::Center;	//�㉺��������

	e->Graphics->FillRectangle(background_brush, e->Bounds);	//�w�i��h��Ԃ�
	e->Graphics->DrawString(tab_str, e->Font, text_brush, e->Bounds, sformat);	//�e�L�X�g��`��

}

Void WalletCheck::MainForm::tabs_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	TabControl^ tab = (TabControl^)sender;
	if (tab->SelectedIndex == 1 && _opening_bookpath != "")
	{
		_load_monthly_balance_graph();
	}
}

/*----------�{�^���̃C�x���g�n���h��----------*/

// Previous�i�߂�j�{�^���̃C�x���g
System::Void WalletCheck::MainForm::previous_button_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (_opening_month == 1)	//��1�����J���Ă�����
	{
		_opening_year--;		//1�N�O��
		_opening_month = 12;	//12����
	}
	else
	{
		_opening_month--;	//1���߂�
	}
	List<List<String^>^> grid_data;
	_OpenBookPage(_opening_bookpath, _opening_year, _opening_month,grid_data);
	_load_grid(this,"history_grid", grid_data);
}

// Next�i���ցj�{�^���̃C�x���g
System::Void WalletCheck::MainForm::next_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (_opening_month == 12)	//��12�����J���Ă�����
	{
		_opening_year++;		//1�N���
		_opening_month = 1;		//1����
	}
	else
	{
		_opening_month++;		//1���i��
	}
	List<List<String^>^> grid_data;
	_OpenBookPage(_opening_bookpath, _opening_year, _opening_month, grid_data);
	_load_grid(this,"history_grid", grid_data);
}