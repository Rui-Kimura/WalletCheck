/*
	AddDataForm_Process.cpp
	AddDataFormの定義した処理です。
*/

#include "AddDataForm.h"
#include "ManageItemsForm.h"
#include "app_config.h"
#include "csv.h"

using namespace app_config;
using namespace csv;

using namespace System;

//Public

/// <summary>追加するデータを取得します。</summary>
array<Object^>^ WalletCheck::AddDataForm::GetAddData()
{
	//値の入ってる変数を配列にまとめて返す
	return 	gcnew array<Object^>{ _day, _category, _memo, _payment, _money };
}

/// <summary>追加するデータの年月を取得します。</summary>
int WalletCheck::AddDataForm::GetAddDate(char type)
{
	switch (type)
	{
		//年を返す
		case 'y':
			return _year;
		break;

		//月を返す
		case 'm':
			return _month;
			break;
		//日を返す
		case 'd':
			return _day;
		break;

		default:
			return -1;
	}
}

//Private

//管理ボタンが押された時の共通イベント
Void WalletCheck::AddDataForm::_manage_items_button_click(Object^ sender,String^ comboboxname,String^ itemname, String^ keyname)
{
	Form^ ManageItemsDialog= gcnew ManageItemsForm(itemname,keyname);	//アイテム管理のForm
	if (ManageItemsDialog->ShowDialog().ToString() == "OK")	//Formを開いて返答がOKか確かめる
	{
		_reload_combobox(sender,comboboxname, keyname);	//comboboxを更新
	}
}

Void WalletCheck::AddDataForm::_reload_combobox(Object^ sender,String^ combobox_controlname, String^ keyname)
{
	ComboBox^ combobox;	//comboboxのコントロールを入れておく変数
	Control^ sender_control = (Control^)sender;	//senderのObjectをControlにキャスト
	Type^ sendertype = sender->GetType();	//senderのtypeを取得
	try
	{
		combobox = (ComboBox^)sender_control->Parent->Controls->Find(combobox_controlname, false)[0];	//指定の名前のcomboboxを見つける
	}
	catch(Exception^ e)
	{
		combobox = (ComboBox^)sender_control->Controls->Find(combobox_controlname, false)[0];	//指定の名前のcomboboxを見つける
	}


	combobox->Items->Clear();	//combobox内のアイテムを全削除
	String^ csv_items_s = config::Get(keyname);	//configからアイテム一覧のStringを取得
	List<String^> csv_items_L;
	csv_manager::Parse(csv_items_s,csv_items_L);	//String状態のcsvをvectorに
	for (int i = 0; i < csv_items_L.Count; i++)	//vectorのすべての値をcomboboxに追加していく
	{
		combobox->Items->Add(csv_items_L[i]);
	}
	combobox->SelectedItem = combobox->Items[0];	//既定の値を選択
}