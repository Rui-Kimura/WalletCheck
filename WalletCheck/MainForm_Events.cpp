#include "MainForm.h"
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

// MainFormがロード刺された時のイベント
Void WalletCheck::MainForm::MainForm_Load(Object^ sender, EventArgs^ e)
{
	_opening_bookpath = config::Get("RecentBook0");	// 最後に読み込まれたファイルのパスを設定から取得する
	if (config::Get("OpenLastFile") == "true" && _opening_bookpath != "")	//もし最後に使ったファイルの読み込みが有効で、パスがあったら
	{
		_opening_year = _GetYear();	// 開いている年に今の年をセット
		_opening_month = _GetMonth();	// 開いている月に今の月をセット
		char bookpath[CHAR_STR_BUF];//bookのパスを入れておくchar配列
		string_convert::SystemString_to_CString(_opening_bookpath, bookpath);
		List<List<String^>^> grid_data;
		_OpenBookPage(_opening_bookpath, _opening_year, _opening_month,grid_data);
		_load_grid(this,"history_grid", grid_data);
	}
	_show_recentbook_toolstripmenu();

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

	e->Graphics->FillRectangle(background_brush, e->Bounds);	//背景を塗りつぶす
	e->Graphics->DrawString(tab_str, e->Font, text_brush, e->Bounds, sformat);	//テキストを描画

}

Void WalletCheck::MainForm::tabs_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	TabControl^ tab = (TabControl^)sender;
	if (tab->SelectedIndex == 1 && _opening_bookpath != "")
	{
		_load_monthly_balance_graph();
	}
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
	List<List<String^>^> grid_data;
	_OpenBookPage(_opening_bookpath, _opening_year, _opening_month,grid_data);
	_load_grid(this,"history_grid", grid_data);
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
	List<List<String^>^> grid_data;
	_OpenBookPage(_opening_bookpath, _opening_year, _opening_month, grid_data);
	_load_grid(this,"history_grid", grid_data);
}