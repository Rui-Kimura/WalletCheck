/*
	graph.h
	Formで使うグラフ用のクラスです。
*/

#pragma once

namespace graph
{
	/// <summary>
	/// ドーナツグラフ用データ型
	/// </summary>
	public ref class DonutData
	{
		public:
			long long value;
			System::String^ text;

			DonutData(int v,System::String^ str) {
				value = v;
				text = str;
			}
	};
}