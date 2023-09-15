/*
	string_converter.cpp
	string_converter.h�̏����ł��B
*/

#include "string_convertr.h"
#include <string.h>

using namespace std;
using namespace System;
using namespace Runtime::InteropServices;

/// <summary>
/// System::String��char[]�ɕϊ����܂��B
/// </summary>
/// <param name="sysstr">�F�ϊ�����System::String������</param>
/// <param name="str">�F�i�[���char�z��</param>
Void string_converter::string_convert::SystemString_to_CString(String^ sysstr, char str[])
{
	//System::String��ANSI�ɕϊ����ă������ɃR�s�[
	char* cache = (char*)Marshal::StringToHGlobalAnsi(sysstr).ToPointer();
	strcpy(str, cache);	//��������󂯎����char�z��ɃR�s�[
	Marshal::FreeHGlobal((IntPtr)cache);	//cache�̃��������J��
}

/// <summary>
/// System::String��std::string�ɕϊ����܂��B
/// </summary>
/// <param name="sysstr">�F�ϊ�����System::String������</param>
///	<returns>�ϊ����std::string</returns>
string string_converter::string_convert::SystemString_to_string(String^ sysstr)
{
	string str;
	const char* chars =(const char*)(Marshal::StringToHGlobalAnsi(sysstr)).ToPointer();
	str = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return str;
}

/// <summary>
/// std::string��System::String�ɕϊ����܂��B
/// </summary>
/// <param name="str">�ϊ�����std::string</param>
/// <returns>�ϊ����System::String</returns>
String^ string_converter::string_convert::string_to_SystemString(string str)
{
	//std::string��str����c����`��(char*)�̕���������o��System::String��
	return gcnew String(str.c_str());	
}



