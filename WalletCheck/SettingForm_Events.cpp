/*
	SettingForm_Events.cpp
	SettingFormのイベントです。
*/

#include "SettingForm.h"
#include "ManageItemsForm.h"

/// <summary>フォームがロードされた時のイベントです。</summary>
System::Void WalletCheck::SettingForm::SettingForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	_load_settings();	//設定を読み込んでフォームに反映させる
}

/// <summary>アップデート手動確認ボタンが押された時のイベントです。</summary>
System::Void WalletCheck::SettingForm::update_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	if(MainForm::check_update() == 0)	//アップデートを確認
	{
		MessageBox::Show("最新版です。");
	}
	else
	{
		MessageBox::Show("アップデートに失敗しました。");
	}
}

/// <summary>カテゴリ管理ボタンが押された時のイベントです。</summary>
System::Void WalletCheck::SettingForm::manage_category_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	Form^ ManageItemsDialog = gcnew ManageItemsForm("カテゴリー", "Categories");
}

/// <summary>決済方法管理ボタンが押された時のイベントです。</summary>
System::Void WalletCheck::SettingForm::manage_payment_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	Form^ ManageItemsDialog = gcnew ManageItemsForm("決済方法", "PaymentMethods");
}

/// <summary>キャンセルボタンが押された時のイベントです。</summary>
System::Void WalletCheck::SettingForm::cancel_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();	//フォームを閉じる
}

/// <summary>設定ボタンが押された時のイベントです。</summary>
System::Void WalletCheck::SettingForm::setting_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	_set_settings();	//設定をファイルにセット
	this->Close();	//フォームを閉じる
}