#include "csv.h"
#include "string_convertr.h"
#include "MainForm.h"
#include <sstream>

using namespace string_converter;

using namespace std;
using namespace System;
using namespace System::Collections::Generic;

/// <summary>
/// 1�s��csv��List�ɂ��ĕԂ��܂��B
/// </summary>
/// <param name="csv_s">�FSystem::String�`����csv</param>
Void csv::csv_manager::Parse(String^ csv_s, List<String^>% list)
{
	string csv_string = string_convert::SystemString_to_string(csv_s);	//Ssytem::String�^��csv_s��std::string�ɕϊ�

	istringstream csv_stream(csv_string);	//string��csv�𕶎���X�g���[����
	string bufstr_conma;	//�R���}��؂�Ŏ擾��������������u������ϐ�
	while (getline(csv_stream, bufstr_conma, ','))	//�R���}��؂�Ńf�[�^��ǂݎ��
	{
		list.Add(string_convert::string_to_SystemString(bufstr_conma));	//vector�����ɒǉ�
	}
}

String^ csv::csv_manager::ShapeValue(String^ csv_value_s)
{
	csv_value_s = csv_value_s->Replace(",", "�C");
	csv_value_s = csv_value_s->Replace("\n", "|");
	return csv_value_s;
}