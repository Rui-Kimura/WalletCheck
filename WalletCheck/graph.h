/*
	graph.h
	Form�Ŏg���O���t�p�̃N���X�ł��B
*/

#pragma once

namespace graph
{
	/// <summary>
	/// �h�[�i�c�O���t�p�f�[�^�^
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