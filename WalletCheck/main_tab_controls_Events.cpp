#include "MainForm.h"
#include"CreateNewForm.h"
#include "AddDataForm.h"

using namespace WalletCheck;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;

/*----------ボタンのイベントハンドラ----------*/

// add_data（追加）ボタンのイベント
System::Void WalletCheck::MainForm::add_data_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (_opening_bookpath == "")	//今bookを開いていなかったら
	{
		// ユーザーに知らせて作成するか尋ねる
		if (MessageBox::Show("Bookを開いていません。\n新しく作成しますか？", "", MessageBoxButtons::OKCancel).ToString() == "OK")	//結果がOKなら
		{
			_CreateBook();
		}
		return;
	}

	// 以下bookを開いているとき
	Form^ AddDataDialog = gcnew AddDataForm();	//データ追加Formをgcnewする
	if (AddDataDialog->ShowDialog(this).ToString() == "OK")	//Formを表示して結果がOKなら
	{
		_opening_year = AddDataForm::GetAddDate('y');	//データ追加Formから年を取得
		_opening_month = AddDataForm::GetAddDate('m');	//データ追加Formから月を取得

		List<List<String^>^> grid_data;
		_OpenBookPage(_opening_bookpath, _opening_year, _opening_month, grid_data);
		_load_grid(this,"history_grid", grid_data);
		history_grid->Rows->Add(AddDataForm::GetAddData());	//追加フォームから追加データを取得して表に追加
		_SaveBook(_opening_bookpath, _opening_year, _opening_month);
	}
}

/*----------TooLStripMenuのイベントハンドラ----------*/

//新規作成ボタンが押された時のイベント
Void MainForm::CreateNewToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	_CreateBook();
}

//開くボタンが押された時のイベント
Void MainForm::OpenToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	if (folderBrowserDialog1->ShowDialog().ToString() == "OK")	//フォルダ選択ダイアログを表示して結果がOKか確かめる
	{
		_opening_bookpath = folderBrowserDialog1->SelectedPath;
		_OpenBook(_opening_bookpath);
	}
}

//最近のBookが押されたときのイベント
Void WalletCheck::MainForm::RecenttoolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	ToolStripMenuItem^ RecentToolStripMenuItem = (ToolStripMenuItem^)sender;	//Object型senderをToolStripMenuItem型にキャスト
	String^ bookpath_s = RecentToolStripMenuItem->Text;	//MenuItemに表示されているテキスト＝パス
	_OpenBook(bookpath_s);
}

//終了ボタンが押された時のイベント
Void MainForm::ExitToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	this->Close();
}

/*----------その他のイベント----------*/

// 表に並べ替えが起きたときのイベント
Void WalletCheck::MainForm::history_grid_SortCompare(Object^ sender, System::Windows::Forms::DataGridViewSortCompareEventArgs^ e)
{
	if (e->Column == history_grid->Columns[0])	//0番目のコラムの並び替えの時
	{
		e->SortResult = _StringToInt(e->CellValue1->ToString()) - _StringToInt(e->CellValue2->ToString()); //並び替えの順序を値の差分に→数値順になる
		e->Handled = true;
	}
}