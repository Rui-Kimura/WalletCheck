/*
	ApplicationInfo.cpp
	ApplicationInfoForm�̃C�x���g�A�����ł��B
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



String^ _GetCopyright()	//�������擾
{
	Assembly^ mainAsm = Assembly::GetExecutingAssembly();
	auto fileversioninfo = FileVersionInfo::GetVersionInfo(mainAsm->Location);
	return 	fileversioninfo->LegalCopyright;
}

String^ _GetDescription()	//�������擾
{
	Assembly^ mainAsm = Assembly::GetExecutingAssembly();
	auto fileversioninfo = FileVersionInfo::GetVersionInfo(mainAsm->Location);
	return 	fileversioninfo->FileDescription;
}

System::Void WalletCheck::ApplicationInfoForm::ApplicationInfo_Load(System::Object^ sender, System::EventArgs^ e)
{
	company_label->Text = Application::CompanyName;	//��Ж����擾
	applicationname_label->Text = Application::ProductName;	//���i�����擾
	version_label->Text =  "ver." + Application::ProductVersion;	//�o�[�W�������擾
	copyright_label->Text = _GetCopyright();
	description_label->Text = _GetDescription();
}
