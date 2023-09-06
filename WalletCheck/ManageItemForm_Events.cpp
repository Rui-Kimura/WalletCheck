#include "ManageItemsForm.h"
#include "app_config.h"
#include "csv.h"

using namespace System::Collections::Generic;
using namespace csv;
using namespace app_config;
using namespace System;

//Formロード時のイベント
Void WalletCheck::ManageItemsForm::ManageItemsForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	this->Text = _itemname + "の管理";	//Formのタイトルを変更
	Column1->HeaderText = _itemname;	//コラムの名前を変更

	String^ csv_from_setting = config::Get(_keyname);	//csv形式のアイテム一覧を取得
	List<String^> csv_L;
	csv_manager::Parse(csv_from_setting,csv_L);	//csvをvectorに

	for (int i = 0; i < csv_L.Count; i++)	//vectorのすべての値を表に追加
	{
		data_grid->Rows->Add(csv_L[i]);
	}
	data_grid->Rows[0]->Visible = false;	//1つめの要素は既定とするので隠す
}


//OKボタンが押された時のイベント
Void WalletCheck::ManageItemsForm::ok_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ config_string = "";
	String^ add_string = "";
	for (int i = 0; i < data_grid->Rows->Count - 2; i++)
	{
		add_string = csv_manager::ShapeValue(data_grid->Rows[i]->Cells[0]->Value->ToString());
		if (add_string != "" && add_string != " " && add_string != "　")
		{
			config_string += add_string + ","; 	//表の値をString型のcsvに
		}
	}
	config_string += data_grid->Rows[data_grid->Rows->Count - 2]->Cells[0]->Value;	//最後はコンマがない
	config::Set(_keyname, config_string);	//configに登録
	this->DialogResult = System::Windows::Forms::DialogResult::OK;	//Formの返答をOKに
	this->Close();	//Formを閉じる
}

//キャンセルボタンが押された時のイベント
Void WalletCheck::ManageItemsForm::cancel_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();	//Formを閉じる
}