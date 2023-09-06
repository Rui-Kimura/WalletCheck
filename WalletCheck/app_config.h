#pragma once

using namespace System;
using namespace System::Configuration;

namespace app_config
{
	public ref class config
	{
		public:
			/// <summary>
			/// Configに値を保存します。
			/// </summary>
			/// <param name="keyname">：Configのキー名</param>
			/// <param name="value">：保存する値</param>
			static Void Set(String^ keyname,String^ value);

			/// <summary>
			/// Configの値を取得します。
			/// </summary>
			/// <param name="keyname">：Configのキー名</param>
			/// <returns>取得した値</returns>
			static String^ Get(String^ keyname);

			/// <summary>
			/// Configのキーを追加します。
			/// </summary>
			/// <param name="keyname">：Configのキー名</param>
			/// <param name="value">：Configの値</param>
			static Void Add(String^ keyname,String^ value);

			/// <summary>
			/// Configのキーを削除します。
			/// </summary>
			/// <param name="keyname">：Configのキー名</param>
			static Void Remove(String^ keyname);
		private:

	};
}

