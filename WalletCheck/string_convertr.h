/*
	string_converter.h
	C++<-->C++/CLI�Ԃ̕�����ϊ����s���N���X�ł��B
*/

#pragma once

#include <string>


namespace string_converter
{
	/// <summary>
	/// C++<-->C++/CLI�Ԃ̕�����ϊ����s���܂��B
	/// </summary>
	public ref class string_convert
	{
		public:
			/// <summary>
			/// System::String��char[]�ɕϊ����܂��B
			/// </summary>
			/// <param name="sysstr">�F�ϊ�����System::String������</param>
			/// <param name="str">�F�i�[���char�z��</param>
			static System::Void SystemString_to_CString(System::String^ sysstr, char str[]);

			/// <summary>
			/// System::String��std::string�ɕϊ����܂��B
			/// </summary>
			/// <param name="sysstr">�F�ϊ�����System::String������</param>
			///	<returns>�ϊ����std::string</returns>
			static std::string SystemString_to_string(System::String^ sysstr);

			/// <summary>
			/// std::string��System::String�ɕϊ����܂��B
			/// </summary>
			/// <param name="str">�ϊ�����std::string</param>
			/// <returns>�ϊ����System::String</returns>
			static System::String^ string_to_SystemString(std::string str);
		private:
	};
}