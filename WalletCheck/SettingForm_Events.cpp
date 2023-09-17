/*
	SettingForm_Events.cpp
	SettingForm�̃C�x���g�ł��B
*/

#include "SettingForm.h"
#include "ManageItemsForm.h"

/// <summary>�t�H�[�������[�h���ꂽ���̃C�x���g�ł��B</summary>
System::Void WalletCheck::SettingForm::SettingForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	_load_settings();	//�ݒ��ǂݍ���Ńt�H�[���ɔ��f������
}

/// <summary>�A�b�v�f�[�g�蓮�m�F�{�^���������ꂽ���̃C�x���g�ł��B</summary>
System::Void WalletCheck::SettingForm::update_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	int update = MainForm::check_update();//�A�b�v�f�[�g���m�F
	if(update == 0)	
	{
		MessageBox::Show("�ŐV�łł��B");
	}
	else if (update == -1)
	{
		MessageBox::Show("�X�V�̓L�����Z������܂����B");
	}
	else
	{
		MessageBox::Show("�A�b�v�f�[�g�Ɏ��s���܂����B");
	}
}

/// <summary>�J�e�S���Ǘ��{�^���������ꂽ���̃C�x���g�ł��B</summary>
System::Void WalletCheck::SettingForm::manage_category_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	Form^ ManageItemsDialog = gcnew ManageItemsForm("�J�e�S���[", "Categories");
}

/// <summary>���ϕ��@�Ǘ��{�^���������ꂽ���̃C�x���g�ł��B</summary>
System::Void WalletCheck::SettingForm::manage_payment_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	Form^ ManageItemsDialog = gcnew ManageItemsForm("���ϕ��@", "PaymentMethods");
}

/// <summary>�L�����Z���{�^���������ꂽ���̃C�x���g�ł��B</summary>
System::Void WalletCheck::SettingForm::cancel_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();	//�t�H�[�������
}

/// <summary>�ݒ�{�^���������ꂽ���̃C�x���g�ł��B</summary>
System::Void WalletCheck::SettingForm::setting_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	_set_settings();	//�ݒ���t�@�C���ɃZ�b�g
	this->Close();	//�t�H�[�������
}