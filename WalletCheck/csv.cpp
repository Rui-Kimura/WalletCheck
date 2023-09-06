#include "csv.h"
#include "string_convertr.h"
#include "MainForm.h"
#include <sstream>

using namespace string_converter;

using namespace std;
using namespace System;
using namespace System::Collections::Generic;

/// <summary>
/// 1行のcsvをListにして返します。
/// </summary>
/// <param name="csv_s">：System::String形式のcsv</param>
Void csv::csv_manager::Parse(String^ csv_s, List<String^>% list)
{
	string csv_string = string_convert::SystemString_to_string(csv_s);	//Ssytem::String型のcsv_sをstd::stringに変換

	istringstream csv_stream(csv_string);	//stringのcsvを文字列ストリームに
	string bufstr_conma;	//コンマ区切りで取得した文字列を仮置きする変数
	while (getline(csv_stream, bufstr_conma, ','))	//コンマ区切りでデータを読み取り
	{
		list.Add(string_convert::string_to_SystemString(bufstr_conma));	//vector末尾に追加
	}
}

String^ csv::csv_manager::ShapeValue(String^ csv_value_s)
{
	csv_value_s = csv_value_s->Replace(",", "，");
	csv_value_s = csv_value_s->Replace("\n", "|");
	return csv_value_s;
}