/*
	string_converter.h
	C++<-->C++/CLI間の文字列変換を行うクラスです。
*/

#pragma once

#include <string>


namespace string_converter
{
	/// <summary>
	/// C++<-->C++/CLI間の文字列変換を行います。
	/// </summary>
	public ref class string_convert
	{
		public:
			/// <summary>
			/// System::Stringをchar[]に変換します。
			/// </summary>
			/// <param name="sysstr">：変換元のSystem::String文字列</param>
			/// <param name="str">：格納先のchar配列</param>
			static System::Void SystemString_to_CString(System::String^ sysstr, char str[]);

			/// <summary>
			/// System::Stringをstd::stringに変換します。
			/// </summary>
			/// <param name="sysstr">：変換元のSystem::String文字列</param>
			///	<returns>変換後のstd::string</returns>
			static std::string SystemString_to_string(System::String^ sysstr);

			/// <summary>
			/// std::stringをSystem::Stringに変換します。
			/// </summary>
			/// <param name="str">変換元のstd::string</param>
			/// <returns>変換後のSystem::String</returns>
			static System::String^ string_to_SystemString(std::string str);
		private:
	};
}