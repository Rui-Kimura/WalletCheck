#pragma once

namespace csv
{
	public ref class csv_manager
	{
		public:
			/// <summary>
			/// 1�s��csv��List�ɂ��ĕԂ��܂��B
			/// </summary>
			/// <param name="csv_s">�FSystem::String�`����csv</param>
			/// <param name="list">�F�i�[���List</param>
			static System::Void Parse(System::String^ csv_s, System::Collections::Generic::List<System::String^>% list);

			/// <summary>
			/// csv�ɒǉ�����f�[�^�ɕs���ȕ������܂܂�Ă��Ȃ����������A�C�����܂��B
			/// �ΏہF �R���}�A���s
			/// </summary>
			/// <param name="csv_s">�FSystem::String�`���̕�����</param>
			/// <returns>�C����̒l</returns>
			static System::String^ ShapeValue(System::String^ csv_value_s);
	};
}