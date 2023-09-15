/*
	CreateNewForm_Events.cpp
	CreateNewFormのイベントです。
*/

#include "MainForm.h"
#include "CreateNewForm.h"
#include "app_config.h"

using namespace app_config;

/// <summary>Formロード時のイベント</summary>
System::Void WalletCheck::CreateNewForm::CreateNewForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	String^ folderpath = config::Get("FolderPath");	//以前のフォルダパスを復元
	if (folderpath == "")	//以前のフォルダパスが無かった時
	{
		folderpath = System::Environment::GetFolderPath(Environment::SpecialFolder::Personal);	//UserのDocumentを既定に
	}
	path_textbox->Text = folderpath;
}
/// <summary>参照ボタンが押された時のイベント</summary>
System::Void WalletCheck::CreateNewForm::browse_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (folderBrowserDialog1->ShowDialog().ToString() == "OK")	//フォルダブラウザダイアログを表示して結果がOKか確かめる
	{
		path_textbox->Text = folderBrowserDialog1->SelectedPath;	//テキストボックスに選択したパスを表示	
		config::Set("FolderPath",path_textbox->Text);	//configにパスを書き込み
	}
}

/// <summary>book名のテキストが変更された時のイベント</summary>
Void WalletCheck::CreateNewForm::bookname_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	array<wchar_t>^ char_cannnotuse = System::IO::Path::GetInvalidFileNameChars();	//ファイル名、フォルダ名に使用できない文字一覧
	TextBox^ thisbox = (TextBox^)sender;	//テキストボックスのオブジェクト
	String^ bookname_text = thisbox->Text->ToString();	//テキストボックスのテキストを取得
	for (int i = 0; i < bookname_text->Length; i++)
	{
		for (int n = 0; n < char_cannnotuse->Length; n++)
		{
			if (bookname_text[i] == char_cannnotuse[n])
			{
				MessageBox::Show("使用できない文字です。", "エラー");
				bookname_text = bookname_text->Replace(bookname_text[i].ToString(), "");
				thisbox->Text = bookname_text;
				return;
			}
		}
	}

}

/// <summary>作成ボタンが押された時のイベント</summary>
System::Void WalletCheck::CreateNewForm::create_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ bookname = bookname_textbox->Text;
	_bookpath = path_textbox->Text +"\\" + bookname_textbox->Text;	//Bookのパスを指定パス+Book名に
	if (_bookname == "") //Book名が入力されていなかったら
	{
		MainForm::Message((String^)"Book名を入力してください。", "エラー"); //aleart to user
		return;
	}

	this->DialogResult = Forms::DialogResult::OK;	//新規作成ダイアログ（このForm）の結果をOKに
	this->Close();
}

/// <summary>キャンセルボタンが押されたときのイベント</summary>
System::Void WalletCheck::CreateNewForm::cancel_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
