#pragma once

namespace csv
{
	public ref class csv_manager
	{
		public:
			/// <summary>
			/// 1行のcsvをListにして返します。
			/// </summary>
			/// <param name="csv_s">：System::String形式のcsv</param>
			/// <param name="list">：格納先のList</param>
			static System::Void Parse(System::String^ csv_s, System::Collections::Generic::List<System::String^>% list);

			/// <summary>
			/// csvに追加するデータに不正な文字が含まれていないか検査し、修正します。
			/// 対象： コンマ、改行
			/// </summary>
			/// <param name="csv_s">：System::String形式の文字列</param>
			/// <returns>修正後の値</returns>
			static System::String^ ShapeValue(System::String^ csv_value_s);
	};
}