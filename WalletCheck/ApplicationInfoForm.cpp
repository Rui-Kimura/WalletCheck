/*
	ApplicationInfo.cpp
	ApplicationInfoFormのイベント、処理です。
*/

#include <typeinfo>
#include "ApplicationInfoForm.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Diagnostics;
using namespace System::Reflection;
using namespace System::Windows::Forms;
using namespace System::Resources;
using namespace System::Runtime::InteropServices;



String^ _GetCopyright()	//権利情報取得
{
	Assembly^ mainAsm = Assembly::GetExecutingAssembly();
	auto fileversioninfo = FileVersionInfo::GetVersionInfo(mainAsm->Location);
	return 	fileversioninfo->LegalCopyright;
}

String^ _GetDescription()	//説明を取得
{
	Assembly^ mainAsm = Assembly::GetExecutingAssembly();
	auto fileversioninfo = FileVersionInfo::GetVersionInfo(mainAsm->Location);
	return 	fileversioninfo->FileDescription;
}

System::Void WalletCheck::ApplicationInfoForm::ApplicationInfo_Load(System::Object^ sender, System::EventArgs^ e)
{
	company_label->Text = Application::CompanyName;	//会社名を取得
	applicationname_label->Text = Application::ProductName;	//製品名を取得
	version_label->Text =  "ver." + Application::ProductVersion;	//バージョンを取得
	copyright_label->Text = _GetCopyright();
	description_label->Text = _GetDescription();
}
