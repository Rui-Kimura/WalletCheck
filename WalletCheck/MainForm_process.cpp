#include "MainForm.h"
#include "CreateNewForm.h"
#include "AddDataForm.h"
#include "app_config.h"
#include "string_convertr.h"
#include "csv.h"
#include <fstream>
#include <sstream>
#include <direct.h>
#include <filesystem>
using namespace System::Windows::Forms::DataVisualization::Charting;

using namespace app_config;
using namespace string_converter;
using namespace csv;

using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Configuration;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::IO;

//Public

/// <summary>メッセージダイアログ表示します。</summary>
Void WalletCheck::MainForm::Message(String^ message, String^ title)
{
	MessageBox::Show(message, title, MessageBoxButtons::OK);
}

//Private

/// <summary>今日の月を取得します。</summary>
int WalletCheck::MainForm::_GetYear()
{
	return _StringToInt(System::DateTime::Now.ToString("yyyy"));
}

/// <summary>今の月を取得します。</summary>
int WalletCheck::MainForm::_GetMonth()
{
	return _StringToInt(System::DateTime::Now.ToString("MM"));
}

/// <summary>BookのパスからBook名を抜き出します。</summary>
String^ WalletCheck::MainForm::_GetBookname_From_Path(System::String^ path)
{
	System::String^ bookname;
	int count = (int)(path->Length) - 1;	// 現在の文字列path上でのカーソル位置
	while (path[count] != '\\')
	{
		bookname = path[count] + bookname;
		count--;	//右から左へ\を走査していく
	}

	return bookname;
}

/// <summary>引数をもとにページのパスを作成します。</summary>
String^ WalletCheck::MainForm::_MakePagePath(String^ bookpath_s, int year, int month)
{
	return bookpath_s + "\\" + year + "_" + month + ".wc.csv";	///パスを～\book名\YYYY_M.csvに整形
}



/// <summary>Stringをintに変換します。</summary>
long long  WalletCheck::MainForm::_StringToInt(String^ strnum)
{
	return Int64::Parse(strnum);
}

/// <summary>Bookを新規に作成します。</summary>
Void WalletCheck::MainForm::_CreateBook()
{
	Form^ createnewdialog = gcnew CreateNewForm();	// Book新規作成するFormをgcnewする
	if (createnewdialog->ShowDialog(this).ToString() == "OK")		//Formを表示して結果がOKか確かめる
	{
		_opening_bookpath = CreateNewForm::GetBookPath();	// Formに入力されたパスを取得
		char bookpath[CHAR_STR_BUF];	//char配列形式でpathを保存する変数
		string_convert::SystemString_to_CString(_opening_bookpath, bookpath);	//filepathをString→char[]

		if (_mkdir(bookpath) != 0)	//filepathをもとにディレクトリを作成　失敗 
		{
			Message(_opening_bookpath + "を作成できません。\n既に存在しているか、使用できないBook名です。", "エラー");
			return;
		}

		//以下ディレクトリを作成できたとき
		char pagepath[CHAR_STR_BUF];
		_opening_year = _GetYear();	//開いている年を今年に
		_opening_month = _GetMonth();	//開いている月を今月に
		string_convert::SystemString_to_CString(_MakePagePath(_opening_bookpath, _opening_year,_opening_month), pagepath);	//ページのpathを作成＆char[]に変換
		ofstream file_stream(pagepath);	//今月のページを作成
		_register_recently(_opening_bookpath);	//アプリケーション設定の最近使用したファイルに追加
		List<List<String^>^> page_data;
		_OpenBookPage(_opening_bookpath, _opening_year, _opening_month,page_data);
		_load_grid(this,"history_grid", page_data);
	}
}

/// <summary>Bookを開きます。</summary>
Void WalletCheck::MainForm::_OpenBook(String^ bookpath_s)
{
	if (Directory::GetFiles(bookpath_s, "*.wc.csv")->Length < 1)	//中にcsvファイルが無かったら
	{
		Message("Bookのページが見つかりませんでした。", "エラー");
		_opening_bookpath = "";
		return;
	}
	//以下csvファイルが見つかった時
	_opening_bookpath = bookpath_s;
	_register_recently(_opening_bookpath);	//最近開いたファイルに登録
	_opening_year = _GetYear();	// 開いている年を今の年に
	_opening_month = _GetMonth();	//開いている月を今の月に
	auto filenames = Directory::GetFiles(_opening_bookpath, "*.wc.csv");	//パス内のファイル一覧を取得
	for (int i = 0; i < filenames->Length; i++)	//ファイル分繰り返す	
	{
		// 今年、今月のファイルがあるか調べる
		if (filenames[i] == _MakePagePath(_opening_bookpath, _opening_year, _opening_month))
		{
			List<List<String^>^> page_data;
			_OpenBookPage(_opening_bookpath, _opening_year, _opening_month,page_data);	//あったら開く
			_load_grid(this,"history_grid",page_data);
			return;
		}
	}
	/*以下今月のファイルが無かった時*/
	/*フォルダ内の一番初めに見つかったファイルを開く*/
	//ファイル名から年、月を取り出すための仮置き変数
	String^ cache_ym;	//YYY
	String^ cache_year;
	String^ cache_month;

	cache_ym = filenames[0]->Replace(_opening_bookpath + "\\", "");	//\以前の文字列を削除
	cache_ym = cache_ym->Replace(".wc.csv", "");	//拡張子部分を削除
	for (int i = 0; i < 4; i++)	//年を取り出し
	{
		cache_year += cache_ym[i];
	}
	cache_month = cache_ym->Replace(cache_year + "_", "");//YYYY_MMからYYYY_を削除
	_opening_year = _StringToInt(cache_year);
	_opening_month = _StringToInt(cache_month);
	List<List<String^>^> page_data;
	_OpenBookPage(_opening_bookpath, _opening_year, _opening_month,page_data);
	_load_grid(this,"history_grid", page_data);
}

/// <summary>Bookのページを開きます。</summary>
Void WalletCheck::MainForm::_OpenBookPage(System::String^ bookpath_s, int year, int month,List<List<String^>^>% return_L)
{
	char pagepath[CHAR_STR_BUF];	//ページへのpathをchar[]に入れる変数
	history_grid->Rows->Clear();	//表の項目を全削除
	string_convert::SystemString_to_CString(_MakePagePath(bookpath_s, year, month), pagepath);
	if (filesystem::is_regular_file(pagepath) == false)	//ページのファイルが存在しなかったら
	{
		ofstream output_file(pagepath);	//ページのファイルを新規作成
		_OpenBookPage(bookpath_s, year, month,return_L);	//再帰的にOpenBookPage
		_load_grid(this,"history_grid",return_L);
		return;	//中断
	}
	
	// 以下ページのファイルが存在したとき
	ifstream input_file(pagepath);	//入力ファイルストリーム
	string bufstr;	// 1行ごとに取得する文字列を仮置きする変数


	while (getline(input_file, bufstr))	//行単位で文字列を取得
	{
		//1行のcsvをvectorに変換
		List<String^> str_comma_L;
		csv_manager::Parse(string_convert::string_to_SystemString(bufstr),str_comma_L);;
		return_L.Add(%str_comma_L);
	}
	month_label->Text = year + "年 " + month + "月";	//年月ラベルを開いているファイルの物に更新
	bookname_label->Text = _GetBookname_From_Path(bookpath_s);	//Book名をパスから取得＆ラベルを更新

	previous_button->Enabled = true;	//前後のページに移動できるようにする
	next_button->Enabled = true;
}

/// <summary>Bookを保存します。</summary>
Void WalletCheck::MainForm::_SaveBook(System::String^ bookpath_s, int year, int month)
{
	history_grid->Sort(history_grid->Columns[0], ListSortDirection::Ascending);	//日付をもとに並び替え

	char bookpath[CHAR_STR_BUF];	//bookのパスをchar配列で格納する
	string_convert::SystemString_to_CString(_MakePagePath(bookpath_s, year, month), bookpath);

	ofstream output_file(bookpath, ios::trunc);	//上書きモードで出力ファイルストリーム

	for (int i = 0; i < history_grid->Rows->Count; i++)	//行の分繰り返し
	{
		char cell[5][128];	//セルの内容をchar配列にして格納しておく変数
		for (int n = 0; n < 5; n++)	//5列分繰り返し
		{
			string_convert::SystemString_to_CString(history_grid->Rows[i]->Cells[n]->Value->ToString(), cell[n]);	//char配列にセルの内容を格納
		}

		for (int i = 0; i < 4; i++)	//4回繰り返す
		{
			output_file << cell[i] << ',';	//ファイルに書き込み
		}

		output_file << cell[4] << endl;;	//最後だけコンマなし改行
	}
}


/// <summary>DataGridViewに値を追加します。</summary>
Void WalletCheck::MainForm::_load_grid(Object^ sender,String^ gridname, List<List<String^>^>% values)
{
	DataGridView^ grid = (DataGridView^)this->Controls->Find(gridname, true)[0];

	for (int i = 0; i < values.Count; i++)
	{
		grid->Rows->Add();	//表に空の行を追加
		int endofindex = grid->Rows->Count - 1;	// 末端の行=追加した空の行のindex
		for (int n = 0; n < values[i]->Count; n++)	//行の分繰り返す
		{
			List <String^>^ value_s = values[i];
			int bufi;
			if (Int32::TryParse(value_s[n], bufi))	///値が数値なら
			{
				grid->Rows[endofindex]->Cells[n]->Value = _StringToInt(value_s[n]);	//セルに数値として追加
			}
			else
			{
				grid->Rows[endofindex]->Cells[n]->Value = value_s[n];	//それ以外は文字列
			}
		}
	}
}

/// <summary>アプリケーション設定の最近使ったファイルに登録します。</summary>
Void WalletCheck::MainForm::_register_recently(String^ bookpath_s)
{
	String^ path_to_write = config::Get("RecentBook0");	//書き込むパス
	String^ cache;	//書き込み先のデータを仮保存して保護する変数
	for (int i = 1; i < 5; i++)	//5つある履歴分繰り返す
	{
		if (path_to_write == bookpath_s)	//書き込むパスがこれから登録するパスと一致したら
			break;	//中断→履歴の重複対策

		cache = config::Get("RecentBook" + i);	//書き込み先のパスが上書きされるので取り出して保護
		config::Set("RecentBook" + i, path_to_write);	//次の履歴に書き込み
		path_to_write = cache;	//書き込むパスに保護したパスを登録
	}
	config::Set("RecentBook0", bookpath_s);
	_show_recentbook_toolstripmenu();
/*
[動作例]
_____________________________________________________________________________________________
履歴0|	path1									path6									path3
履歴1|	path2									path1									path6
履歴2|	path3	→	ここにpath6を登録すると	→	path2	→	ここにpath3を登録すると	→	path1
履歴3|	path4									path3									path2
履歴4|	path5									path4									path4
_____________________________________________________________________________________________	
*/
}

/// <summary>ToolStripの最近使ったBookを表示します。</summary>
Void WalletCheck::MainForm::_show_recentbook_toolstripmenu()
{
	String^ recentbookpath;
	for (int i = 0; i < 5; i++)
	{
		recentbookpath = config::Get("RecentBook" + i);	//i番目の履歴をconfigから取得
		if (recentbookpath != "")
		{
			RecentBookToolStripMenuItem->Enabled = true;	//”最近のファイル”を有効化
			RecentBookToolStripMenuItem->DropDownItems[i]->Visible = true;	//i番目の履歴のアイテムを表示
			RecentBookToolStripMenuItem->DropDownItems[i]->Text = recentbookpath;	//アイテムのテキストをパスに
		}
	}
}

int WalletCheck::MainForm::_sort_donutdata(DonutData^ a, DonutData^ b)
{

	return 0;
}

/// <summary>グラフを描画します。</summary>
Void WalletCheck::MainForm::_load_donut_graph(Object^ targetform, String^ chartname,List<DonutData^>% donutdata)
{
	Form^ form = (Form^)targetform;
	Chart^ chart = (Chart^)form->Controls->Find(chartname,true)[0];
	chart->Series[0]->Points->Clear();

	//donutdata.Sort();

	for (int i = 0; i < donutdata.Count; i++)
	{
		DataPoint^ dp = gcnew DataPoint(0,donutdata[i]->value);
		chart->Series[0]->Points->Add(dp);
		chart->Series[0]->Points[i]->LegendText = donutdata[i]->text;
	}
	
}

Void WalletCheck::MainForm::_load_monthly_balance_graph()
{
	
	List<List<String^>^> grid_data;
	_OpenBookPage(_opening_bookpath, _opening_year, _opening_month,grid_data);

	int spending = 0;
	int income = 0;
	for (int i = 0; i < grid_data.Count; i++)
	{
		
		List<String^>^ row = grid_data[i];
		
		if (Int64::Parse(row[4]) > 0)
		{
			income += Int64::Parse(row[4]);
		}
		else
		{
			spending += Int64::Parse(row[4]);
		}
		
		List<DonutData^> donut_data;
		DonutData^ data = gcnew DonutData;
		data->value = spending;
		data->text = "支出";
		donut_data.Add(data);
		data = gcnew DonutData;
		data->value = income;
		data->text = "収入";
		donut_data.Add(data);

		_load_donut_graph(this,"monthly_balance_chart", donut_data);
	}
};


