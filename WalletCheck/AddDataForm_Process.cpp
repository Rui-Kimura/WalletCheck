/*
	AddDataForm_Process.cpp
	AddDataForm�̒�`���������ł��B
*/

#include "AddDataForm.h"
#include "ManageItemsForm.h"
#include "app_config.h"
#include "csv.h"

using namespace app_config;
using namespace csv;

using namespace System;

//Public

/// <summary>�ǉ�����f�[�^���擾���܂��B</summary>
array<Object^>^ WalletCheck::AddDataForm::GetAddData()
{
	//�l�̓����Ă�ϐ���z��ɂ܂Ƃ߂ĕԂ�
	return 	gcnew array<Object^>{ _day, _category, _memo, _payment, _money };
}

/// <summary>�ǉ�����f�[�^�̔N�����擾���܂��B</summary>
int WalletCheck::AddDataForm::GetAddDate(char type)
{
	switch (type)
	{
		//�N��Ԃ�
		case 'y':
			return _year;
		break;

		//����Ԃ�
		case 'm':
			return _month;
			break;
		//����Ԃ�
		case 'd':
			return _day;
		break;

		default:
			return -1;
	}
}

//Private

//�Ǘ��{�^���������ꂽ���̋��ʃC�x���g
Void WalletCheck::AddDataForm::_manage_items_button_click(Object^ sender,String^ comboboxname,String^ itemname, String^ keyname)
{
	Form^ ManageItemsDialog= gcnew ManageItemsForm(itemname,keyname);	//�A�C�e���Ǘ���Form
	if (ManageItemsDialog->ShowDialog().ToString() == "OK")	//Form���J���ĕԓ���OK���m���߂�
	{
		_reload_combobox(sender,comboboxname, keyname);	//combobox���X�V
	}
}

Void WalletCheck::AddDataForm::_reload_combobox(Object^ sender,String^ combobox_controlname, String^ keyname)
{
	ComboBox^ combobox;	//combobox�̃R���g���[�������Ă����ϐ�
	Control^ sender_control = (Control^)sender;	//sender��Object��Control�ɃL���X�g
	Type^ sendertype = sender->GetType();	//sender��type���擾
	try
	{
		combobox = (ComboBox^)sender_control->Parent->Controls->Find(combobox_controlname, false)[0];	//�w��̖��O��combobox��������
	}
	catch(Exception^ e)
	{
		combobox = (ComboBox^)sender_control->Controls->Find(combobox_controlname, false)[0];	//�w��̖��O��combobox��������
	}


	combobox->Items->Clear();	//combobox���̃A�C�e����S�폜
	String^ csv_items_s = config::Get(keyname);	//config����A�C�e���ꗗ��String���擾
	List<String^> csv_items_L;
	csv_manager::Parse(csv_items_s,csv_items_L);	//String��Ԃ�csv��vector��
	for (int i = 0; i < csv_items_L.Count; i++)	//vector�̂��ׂĂ̒l��combobox�ɒǉ����Ă���
	{
		combobox->Items->Add(csv_items_L[i]);
	}
	combobox->SelectedItem = combobox->Items[0];	//����̒l��I��
}