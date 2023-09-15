/*
	string_converter.cpp
	string_converter.hの処理です。
*/

#include "string_convertr.h"
#include <string.h>

using namespace std;
using namespace System;
using namespace Runtime::InteropServices;

/// <summary>
/// System::Stringをchar[]に変換します。
/// </summary>
/// <param name="sysstr">：変換元のSystem::String文字列</param>
/// <param name="str">：格納先のchar配列</param>
Void string_converter::string_convert::SystemString_to_CString(String^ sysstr, char str[])
{
	//System::StringをANSIに変換してメモリにコピー
	char* cache = (char*)Marshal::StringToHGlobalAnsi(sysstr).ToPointer();
	strcpy(str, cache);	//引数から受け取ったchar配列にコピー
	Marshal::FreeHGlobal((IntPtr)cache);	//cacheのメモリを開放
}

/// <summary>
/// System::Stringをstd::stringに変換します。
/// </summary>
/// <param name="sysstr">：変換元のSystem::String文字列</param>
///	<returns>変換後のstd::string</returns>
string string_converter::string_convert::SystemString_to_string(String^ sysstr)
{
	string str;
	const char* chars =(const char*)(Marshal::StringToHGlobalAnsi(sysstr)).ToPointer();
	str = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return str;
}

/// <summary>
/// std::stringをSystem::Stringに変換します。
/// </summary>
/// <param name="str">変換元のstd::string</param>
/// <returns>変換後のSystem::String</returns>
String^ string_converter::string_convert::string_to_SystemString(string str)
{
	//std::stringのstrからc言語形式(char*)の文字列を取り出しSystem::Stringに
	return gcnew String(str.c_str());	
}



