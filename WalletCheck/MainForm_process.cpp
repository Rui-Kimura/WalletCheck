/*
	MainForm_Process.cpp
	MainFormの定義処理です。
*/

#define UPDATE_CHECK_URL "http://runachama.com/WalletCheck/files/newest/version.txt"	
#define UPDATER_URL "http://runachama.com/WalletCheck/files/newest/Update.zip"
#define UPDATER_ZIP "Update.zip"
#define UPDATER_NAME "Update.exe"

//最新のバージョン情報のURL（GoogleDriveファイル直リンク）

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
using namespace System::Drawing;
using namespace System::Diagnostics;
using namespace System::IO;
using namespace System::IO::Compression;
using namespace System::Net;
using namespace System::Windows::Forms;

//Public

/// <summary>メッセージダイアログ表示します。</summary>
Void WalletCheck::MainForm::Message(String^ message, String^ title)
{
	MessageBox::Show(message, title, MessageBoxButtons::OK);
}

int WalletCheck::MainForm::check_update()
{
	return _check_update();
}

//Private

/// <summary>対象の型の呼び出し元以下の子コントロールを列挙します。</summary>
Void WalletCheck::MainForm::find_control(Object ^ sender, Type ^ type, List<Control^>% list)
{
	Control^ sender_control = (Control^)sender;

	for each (Control ^ c_control in sender_control->Controls)
	{
		if (c_control->GetType()->Equals(type))	//求めている型と同じだったら
		{
			list.Add(c_control);
		}
		if (!c_control->GetType()->Equals(FlowLayoutPanel::typeid))	//FlowLayoutPanelはレイアウトに影響を与えるので除外
			find_control(c_control, type, list);
	}
}

//コントロールの親を設定します。
Void WalletCheck::MainForm::_set_parent(Object^ sender)
{
	List<Control^> panels;
	find_control(sender,Panel::typeid, panels);
	for each (Control ^ control in panels)
	{
		List<Control^> chart;
		List<Control^> other_controls;

		find_control(control, Chart::typeid, chart);	//chartを探す
		find_control(control, Label::typeid, other_controls);	//labelを探す
		find_control(control, FlowLayoutPanel::typeid, other_controls);	//FlowLayoutPanelを探す
		if (chart.Count > 0 && other_controls.Count > 0)
		{
			for each (Control ^ c_control in other_controls)
			{
				c_control->Parent = chart[0];	//label,FlowLayoutPanelの親にchartを設定
			}
		}
	}
}



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

/// <summary>ページのパスから年、月を抜き出します。</summary>
Void WalletCheck::MainForm::_GetYearMonth_From_PagePath(String^ pagepath, int% year, int% month)
{
	String^ cache_year;	
	String^ cache_month;

	pagepath = pagepath->Replace(_opening_bookpath + "\\", "");	//\以前の文字列を削除
	pagepath = pagepath->Replace(".wc.csv", "");	//拡張子部分を削除
	for (int i = 0; i < pagepath->Length; i++)	//年を取り出し
	{
		wchar_t letter = pagepath[i];
		if (letter == '_')	//文字がアンダーバーだったら
			break;			//for停止

		cache_year += letter;
	}
	cache_month = pagepath->Replace(cache_year + "_", "");//YYYY_MMからYYYY_を削除

	year = _StringToInt(cache_year);
	month = _StringToInt(cache_month);
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
		String^ bookpath_s = CreateNewForm::GetBookPath();	// Formに入力されたパスを取得
		char bookpath[CHAR_STR_BUF];	//char配列形式でpathを保存する変数
		string_convert::SystemString_to_CString(bookpath_s, bookpath);	//filepathをString→char[]

		if (_mkdir(bookpath) != 0)	//filepathをもとにディレクトリを作成　失敗 
		{
			Message(bookpath_s + "を作成できません。\n既に存在しているか、使用できないBook名です。", "エラー");
			return;
		}

		//以下ディレクトリを作成できたとき
		char pagepath[CHAR_STR_BUF];
		int year = _GetYear();	//開いている年を今年に
		int month = _GetMonth();	//開いている月を今月に
		string_convert::SystemString_to_CString(_MakePagePath(bookpath_s, year,month), pagepath);	//ページのpathを作成＆char[]に変換
		ofstream file_stream(pagepath);	//今月のページを作成
		_register_recently(bookpath_s);	//アプリケーション設定の最近使用したファイルに追加
		List<List<String^>^> page_data;
		_OpenBookPage(bookpath_s, year, month, page_data);
		_SetOpening(bookpath_s,year,month);
		_load_grid_and_graph();
		tabs->SelectedIndex = 0;
		tabs->Enabled = true;
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
	_register_recently(bookpath_s);	//最近開いたファイルに登録
	int year = _GetYear();	// 開いている年を今の年に
	int month = _GetMonth();	//開いている月を今の月に
	auto filenames = Directory::GetFiles(bookpath_s, "*.wc.csv");	//パス内のファイル一覧を取得
	for (int i = 0; i < filenames->Length; i++)	//ファイル分繰り返す	
	{
		// 今年、今月のファイルがあるか調べる
		if (filenames[i] == _MakePagePath(bookpath_s, year, month))
		{
			List<List<String^>^> page_data;
			_OpenBookPage(bookpath_s, year, month, page_data);	//あったら開く
			_SetOpening(bookpath_s, year, month);
			return;
		}
	}

	/*以下今月のファイルが無かった時*/
	/*フォルダ内の一番初めに見つかったファイルを開く*/
	//ファイル名から年、月を取り出すための仮置き変数
	_GetYearMonth_From_PagePath(filenames[0], year, month);
	List<List<String^>^> page_data;
	_OpenBookPage(bookpath_s, year, month, page_data);
	_SetOpening(bookpath_s, year, month);
}

/// <summary>Bookのページを開きます。</summary>
Void WalletCheck::MainForm::_OpenBookPage(System::String^ bookpath_s, int year, int month,List<List<String^>^>% return_L)
{
	char pagepath[CHAR_STR_BUF];	//ページへのpathをchar[]に入れる変数
	string_convert::SystemString_to_CString(_MakePagePath(bookpath_s, year, month), pagepath);
	
	if (filesystem::is_regular_file(pagepath) == false)	//ページのファイルが存在しなかったら
	{
		ofstream output_file(pagepath);	//ページのファイルを新規作成
		_OpenBookPage(bookpath_s, year, month,return_L);	//再帰的にOpenBookPage
		return;	//中断
	}
	
	// 以下ページのファイルが存在したとき
	ifstream input_file(pagepath);	//入力ファイルストリーム
	string bufstr;	// 1行ごとに取得する文字列を仮置きする変数
	

	while (getline(input_file, bufstr))	//行単位で文字列を取得
	{
		//1行のcsvをvectorに変換
		List<String^> str_comma_L;
		csv_manager::Parse(string_convert::string_to_SystemString(bufstr),str_comma_L);
		if (str_comma_L.Count != 5)	//データ列が5個でなかったら
		{
			Message("破損したデータです。破損したデータは削除されます。", "エラー");
		}
		else
		{
			return_L.Add(% str_comma_L);
		}
	}
}

Void WalletCheck::MainForm::_SetOpening(String^ bookpath, int year, int month)
{
	_opening_bookpath = bookpath;
	_opening_year = year;
	_opening_month = month;
}

/// <summary>Bookを保存します。</summary>
Void WalletCheck::MainForm::_SaveBookPage(System::String^ bookpath_s, int year, int month)
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
Void WalletCheck::MainForm::_load_grid(String^ gridname, List<List<String^>^>% values)
{
	DataGridView^ grid = (DataGridView^)this->Controls->Find(gridname, true)[0];
	grid->Rows->Clear();
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
	_diaplay_pageinfo();
}

/// <summary>ページの情報をラベルなどに表示します。</summary>
Void WalletCheck::MainForm::_diaplay_pageinfo()
{
	String^ bookname = _GetBookname_From_Path(_opening_bookpath);	//Book名をパスから取得＆ラベルを更新

	month_label->Text = _opening_year + "年 " + _opening_month + "月";	//年月ラベルを開いているファイルの物に更新
	bookname_label->Text = bookname;
	this->Text = bookname + " - WalletCheck";

	previous_button->Enabled = true;	//前後のページに移動できるようにする
	next_button->Enabled = true;
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

Void WalletCheck::MainForm::_sort_donutdata_list(List<DonutData^>% list)
{
	//データを値で整列する
	/// TODO:余裕があればクイックソートなどに変更する
	for (int i = 0; i < list.Count; i++)
	{
		int max_index = 0;
		for (int n = i; n < list.Count; n++)
		{
			if (abs(list[n]->value) < abs(list[i]->value))
			{
				max_index = n;
			}
		}
		DonutData^ d = list[i];
		list[i] = list[max_index];
		list[max_index] = d;
	}

	//その他は一番最後にする
	for (int i = 0; i < list.Count; i++)
	{
		if (list[i]->text == "その他")
		{
			DonutData^ cache = list[i];
			list.RemoveAt(i);
			list.Add(cache);
		}
	}
}
/// <summary>グラフを描画します。</summary>
Void WalletCheck::MainForm::_load_donut_graph(Object^ targetform, String^ chartname,List<DonutData^>% donutdata)
{
	Form^ form = (Form^)targetform;
	Chart^ chart = (Chart^)form->Controls->Find(chartname,true)[0];
	chart->Series[0]->Points->Clear();

	_sort_donutdata_list(donutdata);

	for (int i = 0; i < donutdata.Count; i++)
	{
		DataPoint^ dp = gcnew DataPoint(0,donutdata[i]->value);
		chart->Series[0]->Points->Add(dp);
		chart->Series[0]->Points[i]->LegendText = donutdata[i]->text;
	}
}

/// <summary>収支のグラフを読み込みます。</summary>
Void WalletCheck::MainForm::_load_balance_graph(String^ chartname, long long% spending, long long% income)
{
	Chart^ chart  = (Chart^)this->Controls->Find(chartname, true)[0];

	List<DonutData^> donut_data;
	DonutData^ data = gcnew DonutData(spending, "支出");
	donut_data.Add(data);
	data = gcnew DonutData(income, "収入");
	donut_data.Add(data);
	_load_donut_graph(this, chartname, donut_data);
	if (abs(spending) > income)
	{
		chart->Series[0]->Points[0]->Color = Color::DeepPink;
		chart->Series[0]->Points[1]->Color = Color::DeepSkyBlue;
	}
	else
	{
		chart->Series[0]->Points[0]->Color = Color::DeepSkyBlue;
		chart->Series[0]->Points[1]->Color = Color::DeepPink;
	}
}

/// <summary>月間収支を取得します。</summary>
Void WalletCheck::MainForm::_get_monthly_spending_and_income(int year, int month, long long% spending, long long% income)
{
	List<List<String^>^> grid_data;
	_OpenBookPage(_opening_bookpath, year, month, grid_data);

	for each(List<String^>^ row in grid_data)
	{
		long long money = _StringToInt(row[4]);
		if (money > 0)	//金額が正なら収入
		{
			income += money;
		}
		else
		{
			spending += money;
		}
	}
}

/// <summary>月間収支のグラフを読み込みます。</summary>
Void WalletCheck::MainForm::_load_monthly_balance_graph()
{

	long long spending = 0;
	long long income = 0;
	_get_monthly_spending_and_income(_opening_year, _opening_month, spending, income);
	_load_balance_graph("monthly_balance_chart",spending,income);
	monthly_label->Text = _opening_month + "月の収支";
	monthly_income->Text = "収入：" + income.ToString("C0");
	monthly_spending->Text = "支出：" + spending.ToString("C0");

};

/// <summary>年間収支を取得します。</summary>
Void WalletCheck::MainForm::_get_yearly_spending_and_income(int year, long long% spending, long long% income)
{
	spending = 0;
	income = 0;
	for (int i = 1; i <= 12; i++)	//12カ月繰り返す
	{
		int month = i;	
		_get_monthly_spending_and_income(year, month, spending, income);
	}
}

/// <summary>年間収支のグラフを読み込みます。</summary>
Void WalletCheck::MainForm::_load_yearly_balance_graph()
{
	long long spending = 0;
	long long income = 0;
	_get_yearly_spending_and_income(_opening_year, spending, income);
	_load_balance_graph("yearly_balance_chart", spending, income);
	yearly_label->Text = _opening_year + "年の収支";
	yearly_income->Text = "収入：" + income.ToString("C0");
	yearly_spending->Text = "支出：" + spending.ToString("C0");
}

/// <summary>カテゴリ別月間収支を取得します。</summary>
Void WalletCheck::MainForm::_get_monthly_category(int year, int month, List<DonutData^>% data,bool type)
{

	List<List<String^>^> bookdata;
	_OpenBookPage(_opening_bookpath, year, month, bookdata);
	for each(List<String^>^ row in bookdata)
	{
		long long money = _StringToInt(row[4]);
		if (money < 0 && type)
			continue;
		if (money > 0 && !type)
			continue;
		String^ category = row[1];
		int data_index = -1;

		// data内に既に存在するカテゴリか調べ、存在していたらindexを取得する
		for (int i = 0; i < data.Count; i++)
		{
			if (data[i]->text == category)
			{
				data_index = i;
				break;
			}
		}

		if (data_index == -1)	//indexが初期値のまま＝新しいカテゴリ
		{
			DonutData^ donutdata = gcnew DonutData(money, category);
			data.Add(donutdata);
		}
		else	//指定のindexのカテゴリの金額に追加
		{
			data[data_index]->value += money;
		}
	}
}

/// <summary>カテゴリ別月間支出のグラフを読み込みます。</summary>
Void WalletCheck::MainForm::_load_monthly_category_spending_graph()
{
	List<DonutData^> data;
	long long spending = 0;
	long long income = 0;
	_get_monthly_spending_and_income(_opening_year, _opening_month, spending,income);
	_get_monthly_category(_opening_year, _opening_month, data,false);
	_load_donut_graph(this, "monthly_category_spending_chart", data);
	monthly_category_spending_label->Text = _opening_month + "月のカテゴリ別支出";
	monthly_category_spending->Text = "支出：" + spending.ToString("C0");
}

/// <summary>カテゴリ別年間支出を読み込みます。</summary>
Void WalletCheck::MainForm::_get_yearly_category(int year, List<DonutData^>% data,bool type)
{
	for (int i = 1; i <= 12; i++)
	{
		int month = i;
		_get_monthly_category(year, month, data,type);
	}
}

/// <summary>カテゴリ別年間支出のグラフを読み込みます。 </summary>
Void WalletCheck::MainForm::_load_yearly_category_spending_graph()
{
	List<DonutData^> data;
	long long spending = 0;
	long long income = 0;
	_get_yearly_spending_and_income(_opening_year,spending, income);
	_get_yearly_category(_opening_year, data,false);
	_load_donut_graph(this, "yearly_category_spending_chart", data);
	yearly_category_spending_label->Text = _opening_year + "年のカテゴリ別支出";
	yearly_category_spending->Text = "支出：" + spending.ToString("C0");
}

/// <summary>カテゴリ別月間収入のグラフを読み込みます。</summary>
Void WalletCheck::MainForm::_load_monthly_category_income_graph()
{
	List<DonutData^> data;
	long long spending = 0;
	long long income = 0;
	_get_monthly_spending_and_income(_opening_year, _opening_month, spending, income);
	_get_monthly_category(_opening_year, _opening_month, data, true);
	_load_donut_graph(this, "monthly_category_income_chart", data);
	monthly_category_income_label->Text = _opening_month + "月のカテゴリ別収入";
	monthly_category_income->Text = "収入：" + income.ToString("C0");
}

/// <summary>カテゴリ別年間収入のグラフを読み込みます。</summary>
Void WalletCheck::MainForm::_load_yearly_category_income_graph()
{
	List<DonutData^> data;
	long long spending = 0;
	long long income = 0;
	_get_yearly_spending_and_income(_opening_year, spending, income);
	_get_yearly_category(_opening_year, data, true);
	_load_donut_graph(this, "yearly_category_income_chart", data);
	yearly_category_income_label->Text = _opening_year + "年のカテゴリ別収入";
	yearly_category_income->Text = "収入：" + income.ToString("C0");
}

/// <summary>支払別予算を取得します。</summary>
Void WalletCheck::MainForm::_get_budget_payment(List<DonutData^>% data)
{
	List<DonutData^> donutdata_L;
	auto filenames = Directory::GetFiles(_opening_bookpath, "*.wc.csv");	//パス内の.wc.csvファイル一覧を取得
	for each (String^ filename in filenames)
	{
		List<List<String^>^> pagedata;
		int year, month;
		_GetYearMonth_From_PagePath(filename,year,month);
		_OpenBookPage(_opening_bookpath, year, month,pagedata);

		
		for each (List<String^> ^ row in pagedata)
		{
			long long money = _StringToInt(row[4]);
			String^ payment = row[3];
			int data_index = -1;
			// data内に既に存在するカテゴリか調べ、存在していたらindexを取得する
			for (int i = 0; i < data.Count; i++)
			{
				if (data[i]->text == payment)
				{
					data_index = i;
					break;
				}
			}
			if (data_index == -1)	//indexが初期値のまま＝新しいカテゴリ
			{
				DonutData^ donutdata = gcnew DonutData(money, payment);
				data.Add(donutdata);
			}
			else	//指定のindexのカテゴリの金額に追加
			{
				data[data_index]->value += money;
			}
		}
	}
}

/// <summary>予算のグラフを読み込みます。</summary>
Void WalletCheck::MainForm::_load_budget_graph()
{
	List<DonutData^> donutdata;
	_get_budget_payment(donutdata);
	_load_donut_graph(this, "budget_chart", donutdata);
	DataPointCollection^ dpc = budget_chart->Series[0]->Points;
	long long budget = 0;
	for each (DataPoint ^ dp in dpc)
	{
		budget += dp->YValues[0];
	}
	budget_value->Text = "総予算：" + budget.ToString("C0");
}

/// <summary>支払別予算を読み込みます。</summary>
Void WalletCheck::MainForm::_load_budget_payment()
{
	FlowLayoutPanel^ fp = (FlowLayoutPanel^)splitContainer4->Panel2->Controls->Find("flowLayoutPanel3",true)[0];
	DataPointCollection^ dpc = budget_chart->Series[0]->Points;
	
	int count = 0;
	fp->Controls->Clear();
	for each (DataPoint^ dp in dpc)
	{
		Label^ label = gcnew Label();
		label->Name = "payment" + count;
		label->Text = dp->LegendText + "\n" + dp->YValues[0].ToString("C0");
		label->Font = fp->Font;
		label->AutoSize = true;
		label->Visible = true;
		label->Margin = System::Windows::Forms::Padding(5);
		fp->Controls->Add(label);
	}
}

/// <summary>表とグラフを読み込みます。</summary>
Void WalletCheck::MainForm::_load_grid_and_graph()
{
	List<List<String^>^> grid_data;
	_OpenBookPage(_opening_bookpath, _opening_year, _opening_month, grid_data);
	_load_grid("history_grid", grid_data);	//表を読み込む
	_load_yearly_balance_graph();	//月間収支を読み込む
	_load_monthly_balance_graph();	//年間収支を読み込む
	_load_monthly_category_spending_graph();	//カテゴリ別月間支出を読み込む
	_load_yearly_category_spending_graph();		//カテゴリ別年間支出を読み込む
	_load_monthly_category_income_graph();		//カテゴリ別月間収入を読み込む
	_load_yearly_category_income_graph();		//カテゴリ別年間収入を読み込む
	_load_budget_graph();	//予算のグラフを読み込む
	_load_budget_payment();	//決済別予算一覧を読み込む*/
	tabs->Enabled = true;
	delete_data_button->Enabled = true;
}

/// <summary>フォントサイズをフォームの高さによって調節します。</summary>
Void WalletCheck::MainForm::_resize_fontsize(Object^ sender, EventArgs^ e)
{
	Control^ control = (Control^)sender;
	float px = ((float)this->Height / (float)_form_height) * 12.0;
	px = px < 12 ? 12 : px;

	for each (Control ^ c in control->Controls)
	{
		c->Font = gcnew System::Drawing::Font(c->Font->OriginalFontName, px);
		_resize_fontsize(c,e);	//再帰的に子コントロール以下すべてのコントロールに適用する。
	}
}

int WalletCheck::MainForm::_check_update()
{
	String^ newest;
	WebClient^ wc = gcnew WebClient();
	try
	{
		newest = wc->DownloadString(UPDATE_CHECK_URL)->ToString();	//最新のバージョン情報を取得
	}
	catch(Exception^ e)
	{
		return -1;
	}
	String^ now = Application::ProductVersion;	//現在のバージョン
	config::Set("LastUpdate", DateTime::Now.ToString());
	if (now != newest)	//最新バージョンでなかったら
	{
		String^ msg = "新しいバージョン" + newest + "があります。\nアップデートしますか？";
		if (MessageBox::Show(msg,"アップデート", MessageBoxButtons::YesNo).ToString() == "Yes")
		{
			if (_download_updater() == 0)
			{
				Process::Start("Update.exe");
				Application::Exit();
				return 0;
			}
			else
			{
				Message("アップデーターのダウンロードに失敗しました。", "");
				return -1;
			}

		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

int WalletCheck::MainForm::_download_updater()
{
	WebClient^ wc = gcnew WebClient();
	try
	{
		wc->DownloadFile(UPDATER_URL, UPDATER_ZIP);	//最新のアップデーターを取得
	}
	catch (Exception^ e)
	{
		return -1;
	}

	try
	{
		File::Delete(UPDATER_NAME);	//既存のアップデーターを消す
	}
	catch (Exception^ e){}
	ZipFile::ExtractToDirectory(UPDATER_ZIP,"./");	//Zipを展開する
	File::Delete(UPDATER_ZIP);
	
	return 0;
}