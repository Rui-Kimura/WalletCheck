/*
	MainForm_Events.cpp
	MainForm�̃C�x���g�ł��B
*/

#define TRUE "True"
#define FALSE "False"

#include "MainForm.h"
#include "ApplicationInfoForm.h"
#include "SettingForm.h"
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

// MainForm�����[�h���ꂽ���̃C�x���g
Void WalletCheck::MainForm::MainForm_Load(Object^ sender, EventArgs^ e)
{
	_form_height = this->Height;
	_resize_fontsize(this->Controls->Find("tabs",true)[0], e);	//�^�u�̃t�H���g�T�C�Y�𒲐�
	String^ recent_bookpath = config::Get("RecentBook0");	// �Ō�ɓǂݍ��܂ꂽ�t�@�C���̃p�X��ݒ肩��擾����
	if (config::Get("OpenLastFile") == TRUE && recent_bookpath != "")	//�����Ō�Ɏg�����t�@�C���̓ǂݍ��݂��L���ŁA�p�X����������
	{
		_opening_year = _GetYear();	// �J���Ă���N�ɍ��̔N���Z�b�g
		_opening_month = _GetMonth();	// �J���Ă��錎�ɍ��̌����Z�b�g
		_OpenBook(recent_bookpath);
		_load_grid_and_graph();
	}
	_show_recentbook_toolstripmenu();

	if (config::Get("CheckUpdate") == TRUE)
	{
		String^ lastupdate = config::Get("LastUpdate");	//�ŏI�A�b�v�f�[�g�`�F�b�N���Ԃ�config����擾
		if (lastupdate == "")
		{
			lastupdate = DateTime::Now.ToString();
			config::Set("LastUpdate", lastupdate);
		}
		DateTime lastupdatedate = DateTime::Parse(lastupdate);
		DateTime nowdate = DateTime::Now;
		int not_updated = (nowdate - lastupdatedate).TotalDays;
		if (not_updated > 10)	//10���ȏ�A�b�v�f�[�g�`�F�b�N���Ă��Ȃ�������
		{
			_check_update();
		}
	}

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

	// �e�L�X�g�̃T�C�Y�ɍ��킹�ă^�u�̃T�C�Y��ύX
	SizeF^ sizef = e->Graphics->MeasureString(tab_str,e->Font);
	if (tabs->ItemSize.Height < sizef->Height)
		tabs->ItemSize.Height = sizef->Height;
	
	if (tabs->ItemSize.Width < sizef->Width) + 5;
		tabs->ItemSize.Width = sizef->Width + 5;

	/// TODO:�X�P�[����200%�̏ꍇ�e�L�X�g���͂ݏo������C������

	e->Graphics->FillRectangle(background_brush, e->Bounds);	//�w�i��h��Ԃ�
	e->Graphics->DrawString(tab_str, e->Font, text_brush, e->Bounds, sformat);	//�e�L�X�g��`��

}

//�^�u�R���g���[�������T�C�Y���ꂽ�Ƃ��̃C�x���g
System::Void WalletCheck::MainForm::tabs_Resize(System::Object^ sender, System::EventArgs^ e)
{
	TabControl^ tabcontrol = (TabControl^)sender;
	for each (Control ^ c in tabcontrol->Controls)
	{
		for each (Control ^ cc in c->Controls)
		{
			if (cc->GetType()->Equals(SplitContainer::typeid))
			{
				SplitContainer^ sc = (SplitContainer^)cc;
				sc->SplitterDistance = sc->Width / 2;
			}
		}
	}
}

// �^�u��Enable���ύX���ꂽ���̃C�x���g
Void WalletCheck::MainForm::tabs_VisibleChanged(Object^ sender, EventArgs^ e)
{
	_set_parent(sender);
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
	_load_grid_and_graph();
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
	_load_grid_and_graph();
}

/*----------TooLStripMenu�̃C�x���g�n���h��----------*/

//�V�K�쐬�{�^���������ꂽ���̃C�x���g
Void WalletCheck::MainForm::CreateNewToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	_CreateBook();
}

//�J���{�^���������ꂽ���̃C�x���g
Void WalletCheck::MainForm::OpenToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	if (folderBrowserDialog1->ShowDialog().ToString() == "OK")	//�t�H���_�I���_�C�A���O��\�����Č��ʂ�OK���m���߂�
	{
		_opening_bookpath = folderBrowserDialog1->SelectedPath;
		_OpenBook(_opening_bookpath);
		_load_grid_and_graph();
		tabs->Enabled = true;
		tabs->SelectedIndex = 0;
	}
}

//�ŋ߂�Book�������ꂽ�Ƃ��̃C�x���g
Void WalletCheck::MainForm::RecenttoolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	ToolStripMenuItem^ RecentToolStripMenuItem = (ToolStripMenuItem^)sender;	//Object�^sender��ToolStripMenuItem�^�ɃL���X�g
	String^ bookpath_s = RecentToolStripMenuItem->Text;	//MenuItem�ɕ\������Ă���e�L�X�g���p�X
	_OpenBook(bookpath_s);
	_load_grid_and_graph();
	tabs->Enabled = true;
	tabs->SelectedIndex = 0;
}

//�I���{�^���������ꂽ���̃C�x���g
Void WalletCheck::MainForm::ExitToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	this->Close();
}

//�ݒ肪�����ꂽ���̃C�x���g
System::Void WalletCheck::MainForm::SettingToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	Form^ settingform = gcnew SettingForm();
	settingform->ShowDialog();
}

//�A�v���P�[�V������񂪉����ꂽ���̃C�x���g
Void WalletCheck::MainForm::ApplicationInfoToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	Form^ infoform = gcnew ApplicationInfoForm();
	infoform->ShowDialog();
}

