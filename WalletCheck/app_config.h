#pragma once

using namespace System;
using namespace System::Configuration;

namespace app_config
{
	public ref class config
	{
		public:
			/// <summary>
			/// Config�ɒl��ۑ����܂��B
			/// </summary>
			/// <param name="keyname">�FConfig�̃L�[��</param>
			/// <param name="value">�F�ۑ�����l</param>
			static Void Set(String^ keyname,String^ value);

			/// <summary>
			/// Config�̒l���擾���܂��B
			/// </summary>
			/// <param name="keyname">�FConfig�̃L�[��</param>
			/// <returns>�擾�����l</returns>
			static String^ Get(String^ keyname);

			/// <summary>
			/// Config�̃L�[��ǉ����܂��B
			/// </summary>
			/// <param name="keyname">�FConfig�̃L�[��</param>
			/// <param name="value">�FConfig�̒l</param>
			static Void Add(String^ keyname,String^ value);

			/// <summary>
			/// Config�̃L�[���폜���܂��B
			/// </summary>
			/// <param name="keyname">�FConfig�̃L�[��</param>
			static Void Remove(String^ keyname);
		private:

	};
}

