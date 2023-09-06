#include "AddDataForm.h"
#include "MainForm.h"
#include "csv.h"

using namespace csv;

/// <summary>Formロード時のイベント</summary>
System::Void WalletCheck::AddDataForm::AddDataForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	// Formの日付入力欄に今日の日付を入れる
	year_num->Value = Int32::Parse(System::DateTime::Now.ToString("yyyy")->ToString());
	month_num->Value = Int32::Parse(System::DateTime::Now.ToString("MM")->ToString());
	day_num->Value = Int32::Parse(System::DateTime::Now.ToString("dd")->ToString());

	_reload_combobox(sender,"category_box","Categories");
	_reload_combobox(sender, "payment_box", "PaymentMethods");

}

Void WalletCheck::AddDataForm::category_manage_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	_manage_items_button_click(sender,"category_box", "カテゴリー", "Categories");	//カテゴリーの編集Form
}

Void WalletCheck::AddDataForm::payment_manage_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	_manage_items_button_click(sender,"payment_box", "決済方法", "PaymentMethods");	//支払方法の編集Form
}

/// <summary>キャンセルボタンを押したときのイベント</summary>
System::Void WalletCheck::AddDataForm::cancel_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

/// <summary>追加ボタンを押したときのイベント</summary>
System::Void WalletCheck::AddDataForm::add_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Formに入力された値を変数に格納
	//文字列はコンマが入ってないかチェックしてcsvが狂わないよう対策
	_year = Decimal::ToInt32(year_num->Value);
	_month = Decimal::ToInt32(month_num->Value);
	_day = Decimal::ToInt32(day_num->Value);
	_category = csv_manager::ShapeValue(category_box->Text == "" ? "その他" : category_box->Text);
	_memo = csv_manager::ShapeValue(memo_box->Text == "" ? "-" : memo_box->Text);
	_payment = csv_manager::ShapeValue(payment_box->Text);
	_money = Decimal::ToInt64(money_box->Value);
	if (spending_radiobutton->Checked)	//支出にチェックが入っていたら
	{
		_money *= -1;	//金額をマイナスに
	}
	this->DialogResult = Forms::DialogResult::OK;	//Formの結果をOKに
	this->Close();
}