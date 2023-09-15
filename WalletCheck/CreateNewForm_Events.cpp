/*
	CreateNewForm_Events.cpp
	CreateNewForm�̃C�x���g�ł��B
*/

#include "MainForm.h"
#include "CreateNewForm.h"
#include "app_config.h"

using namespace app_config;

/// <summary>Form���[�h���̃C�x���g</summary>
System::Void WalletCheck::CreateNewForm::CreateNewForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	String^ folderpath = config::Get("FolderPath");	//�ȑO�̃t�H���_�p�X�𕜌�
	if (folderpath == "")	//�ȑO�̃t�H���_�p�X������������
	{
		folderpath = System::Environment::GetFolderPath(Environment::SpecialFolder::Personal);	//User��Document�������
	}
	path_textbox->Text = folderpath;
}
/// <summary>�Q�ƃ{�^���������ꂽ���̃C�x���g</summary>
System::Void WalletCheck::CreateNewForm::browse_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (folderBrowserDialog1->ShowDialog().ToString() == "OK")	//�t�H���_�u���E�U�_�C�A���O��\�����Č��ʂ�OK���m���߂�
	{
		path_textbox->Text = folderBrowserDialog1->SelectedPath;	//�e�L�X�g�{�b�N�X�ɑI�������p�X��\��	
		config::Set("FolderPath",path_textbox->Text);	//config�Ƀp�X����������
	}
}

/// <summary>book���̃e�L�X�g���ύX���ꂽ���̃C�x���g</summary>
Void WalletCheck::CreateNewForm::bookname_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	array<wchar_t>^ char_cannnotuse = System::IO::Path::GetInvalidFileNameChars();	//�t�@�C�����A�t�H���_���Ɏg�p�ł��Ȃ������ꗗ
	TextBox^ thisbox = (TextBox^)sender;	//�e�L�X�g�{�b�N�X�̃I�u�W�F�N�g
	String^ bookname_text = thisbox->Text->ToString();	//�e�L�X�g�{�b�N�X�̃e�L�X�g���擾
	for (int i = 0; i < bookname_text->Length; i++)
	{
		for (int n = 0; n < char_cannnotuse->Length; n++)
		{
			if (bookname_text[i] == char_cannnotuse[n])
			{
				MessageBox::Show("�g�p�ł��Ȃ������ł��B", "�G���[");
				bookname_text = bookname_text->Replace(bookname_text[i].ToString(), "");
				thisbox->Text = bookname_text;
				return;
			}
		}
	}

}

/// <summary>�쐬�{�^���������ꂽ���̃C�x���g</summary>
System::Void WalletCheck::CreateNewForm::create_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ bookname = bookname_textbox->Text;
	_bookpath = path_textbox->Text +"\\" + bookname_textbox->Text;	//Book�̃p�X���w��p�X+Book����
	if (_bookname == "") //Book�������͂���Ă��Ȃ�������
	{
		MainForm::Message((String^)"Book������͂��Ă��������B", "�G���["); //aleart to user
		return;
	}

	this->DialogResult = Forms::DialogResult::OK;	//�V�K�쐬�_�C�A���O�i����Form�j�̌��ʂ�OK��
	this->Close();
}

/// <summary>�L�����Z���{�^���������ꂽ�Ƃ��̃C�x���g</summary>
System::Void WalletCheck::CreateNewForm::cancel_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
