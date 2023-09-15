/*
	MainForm_Events.cpp
	MainFormのイベントです。
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

// MainFormがロードされた時のイベント
Void WalletCheck::MainForm::MainForm_Load(Object^ sender, EventArgs^ e)
{
	_form_height = this->Height;
	_resize_fontsize(this->Controls->Find("tabs",true)[0], e);	//タブのフォントサイズを調整
	String^ recent_bookpath = config::Get("RecentBook0");	// 最後に読み込まれたファイルのパスを設定から取得する
	if (config::Get("OpenLastFile") == TRUE && recent_bookpath != "")	//もし最後に使ったファイルの読み込みが有効で、パスがあったら
	{
		_opening_year = _GetYear();	// 開いている年に今の年をセット
		_opening_month = _GetMonth();	// 開いている月に今の月をセット
		_OpenBook(recent_bookpath);
		_load_grid_and_graph();
	}
	_show_recentbook_toolstripmenu();

	if (config::Get("CheckUpdate") == TRUE)
	{
		String^ lastupdate = config::Get("LastUpdate");	//最終アップデートチェック時間をconfigから取得
		if (lastupdate == "")
		{
			lastupdate = DateTime::Now.ToString();
			config::Set("LastUpdate", lastupdate);
		}
		DateTime lastupdatedate = DateTime::Parse(lastupdate);
		DateTime nowdate = DateTime::Now;
		int not_updated = (nowdate - lastupdatedate).TotalDays;
		if (not_updated > 10)	//10日以上アップデートチェックしていなかったら
		{
			_check_update();
		}
	}

}

// タブに描画更新が起きたときのイベント
System::Void WalletCheck::MainForm::tabs_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e)
{
	TabControl^ tabs = (TabControl^)sender;	//tabのオブジェクトを取得
	String^ tab_str = tabs->TabPages[e->Index]->Text;	//タブのテキストを取得
	Brush^ background_brush;	//背景色のブラシ
	Brush^ text_brush;	//テキスト色のブラシ
	if ((e->State & DrawItemState::Selected) == DrawItemState::Selected)	//タブが選択されていたら
	{
		background_brush = Brushes::MAINCOLOR_LIGHT;
		text_brush = Brushes::TEXTCOLOR_LIGHT;
	}
	else	//タブが選択されていなかったら
	{
		background_brush = Brushes::MAINCOLOR_DARK;
		text_brush = Brushes::TEXTCOLOR_DARK;
	}

	StringFormat^ sformat = gcnew StringFormat();	//文字列のフォーマットスタイルをインスタンス化
	sformat->Alignment = StringAlignment::Center;	//左右中央揃え
	sformat->LineAlignment = StringAlignment::Center;	//上下中央揃え

	// テキストのサイズに合わせてタブのサイズを変更
	SizeF^ sizef = e->Graphics->MeasureString(tab_str,e->Font);
	if (tabs->ItemSize.Height < sizef->Height)
		tabs->ItemSize.Height = sizef->Height;
	
	if (tabs->ItemSize.Width < sizef->Width) + 5;
		tabs->ItemSize.Width = sizef->Width + 5;

	/// TODO:スケールが200%の場合テキストがはみ出る問題を修正する

	e->Graphics->FillRectangle(background_brush, e->Bounds);	//背景を塗りつぶす
	e->Graphics->DrawString(tab_str, e->Font, text_brush, e->Bounds, sformat);	//テキストを描画

}

//タブコントロールがリサイズされたときのイベント
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

// タブのEnableが変更された時のイベント
Void WalletCheck::MainForm::tabs_VisibleChanged(Object^ sender, EventArgs^ e)
{
	_set_parent(sender);
}

/*----------ボタンのイベントハンドラ----------*/

// Previous（戻る）ボタンのイベント
System::Void WalletCheck::MainForm::previous_button_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (_opening_month == 1)	//今1月を開いていたら
	{
		_opening_year--;		//1年前の
		_opening_month = 12;	//12月に
	}
	else
	{
		_opening_month--;	//1月戻る
	}
	_load_grid_and_graph();
}

// Next（次へ）ボタンのイベント
System::Void WalletCheck::MainForm::next_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (_opening_month == 12)	//今12月を開いていたら
	{
		_opening_year++;		//1年後の
		_opening_month = 1;		//1月に
	}
	else
	{
		_opening_month++;		//1月進む
	}
	_load_grid_and_graph();
}

/*----------TooLStripMenuのイベントハンドラ----------*/

//新規作成ボタンが押された時のイベント
Void WalletCheck::MainForm::CreateNewToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	_CreateBook();
}

//開くボタンが押された時のイベント
Void WalletCheck::MainForm::OpenToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	if (folderBrowserDialog1->ShowDialog().ToString() == "OK")	//フォルダ選択ダイアログを表示して結果がOKか確かめる
	{
		_opening_bookpath = folderBrowserDialog1->SelectedPath;
		_OpenBook(_opening_bookpath);
		_load_grid_and_graph();
		tabs->Enabled = true;
		tabs->SelectedIndex = 0;
	}
}

//最近のBookが押されたときのイベント
Void WalletCheck::MainForm::RecenttoolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	ToolStripMenuItem^ RecentToolStripMenuItem = (ToolStripMenuItem^)sender;	//Object型senderをToolStripMenuItem型にキャスト
	String^ bookpath_s = RecentToolStripMenuItem->Text;	//MenuItemに表示されているテキスト＝パス
	_OpenBook(bookpath_s);
	_load_grid_and_graph();
	tabs->Enabled = true;
	tabs->SelectedIndex = 0;
}

//終了ボタンが押された時のイベント
Void WalletCheck::MainForm::ExitToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	this->Close();
}

//設定が押された時のイベント
System::Void WalletCheck::MainForm::SettingToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	Form^ settingform = gcnew SettingForm();
	settingform->ShowDialog();
}

//アプリケーション情報が押された時のイベント
Void WalletCheck::MainForm::ApplicationInfoToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	Form^ infoform = gcnew ApplicationInfoForm();
	infoform->ShowDialog();
}

