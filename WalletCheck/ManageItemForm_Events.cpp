#include "ManageItemsForm.h"
#include "app_config.h"
#include "csv.h"

using namespace System::Collections::Generic;
using namespace csv;
using namespace app_config;
using namespace System;

//Form���[�h���̃C�x���g
Void WalletCheck::ManageItemsForm::ManageItemsForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	this->Text = _itemname + "�̊Ǘ�";	//Form�̃^�C�g����ύX
	Column1->HeaderText = _itemname;	//�R�����̖��O��ύX

	String^ csv_from_setting = config::Get(_keyname);	//csv�`���̃A�C�e���ꗗ���擾
	List<String^> csv_L;
	csv_manager::Parse(csv_from_setting,csv_L);	//csv��vector��

	for (int i = 0; i < csv_L.Count; i++)	//vector�̂��ׂĂ̒l��\�ɒǉ�
	{
		data_grid->Rows->Add(csv_L[i]);
	}
	data_grid->Rows[0]->Visible = false;	//1�߂̗v�f�͊���Ƃ���̂ŉB��
}


//OK�{�^���������ꂽ���̃C�x���g
Void WalletCheck::ManageItemsForm::ok_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ config_string = "";
	String^ add_string = "";
	for (int i = 0; i < data_grid->Rows->Count - 2; i++)
	{
		add_string = csv_manager::ShapeValue(data_grid->Rows[i]->Cells[0]->Value->ToString());
		if (add_string != "" && add_string != " " && add_string != "�@")
		{
			config_string += add_string + ","; 	//�\�̒l��String�^��csv��
		}
	}
	config_string += data_grid->Rows[data_grid->Rows->Count - 2]->Cells[0]->Value;	//�Ō�̓R���}���Ȃ�
	config::Set(_keyname, config_string);	//config�ɓo�^
	this->DialogResult = System::Windows::Forms::DialogResult::OK;	//Form�̕ԓ���OK��
	this->Close();	//Form�����
}

//�L�����Z���{�^���������ꂽ���̃C�x���g
Void WalletCheck::ManageItemsForm::cancel_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();	//Form�����
}