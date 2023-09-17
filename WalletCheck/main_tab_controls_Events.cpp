/*
	main_tab_controls_Events.cpp
	MainFormのmain_tabのイベントです。
*/

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
		int add_year = AddDataForm::GetAddDate('y');	//データ追加Formから年を取得
		int add_month = AddDataForm::GetAddDate('m');	//データ追加Formから月を取得
		
		_SetOpening(_opening_bookpath, add_year, add_month);
		_load_grid_and_graph();
		history_grid->Rows->Add(AddDataForm::GetAddData());	//追加フォームから追加データを取得して表に追加
		_SaveBookPage(_opening_bookpath, add_year, add_month);
		tabs->SelectedIndex = 0;
		_load_grid_and_graph();
	}
}

Void WalletCheck::MainForm::delete_data_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	DataGridViewSelectedRowCollection^ rows = history_grid->SelectedRows;	//選択されている行をすべて取得
	if (rows->Count == 0)	//選択されていなかったら
	{
		Message("削除するデータの行を選択してください。\nCtrl + クリックで複数行選択できます。", "ヘルプ");
		return;
	}

	for each (DataGridViewRow ^ row in rows)
	{
		history_grid->Rows->RemoveAt(row->Index);	//選択されている行を削除
		_SaveBookPage(_opening_bookpath, _opening_year, _opening_month);	//保存
	}
	_load_grid_and_graph();
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