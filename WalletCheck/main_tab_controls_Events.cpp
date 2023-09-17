/*
	main_tab_controls_Events.cpp
	MainForm��main_tab�̃C�x���g�ł��B
*/

#include "MainForm.h"
#include"CreateNewForm.h"
#include "AddDataForm.h"

using namespace WalletCheck;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;

/*----------�{�^���̃C�x���g�n���h��----------*/

// add_data�i�ǉ��j�{�^���̃C�x���g
System::Void WalletCheck::MainForm::add_data_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (_opening_bookpath == "")	//��book���J���Ă��Ȃ�������
	{
		// ���[�U�[�ɒm�点�č쐬���邩�q�˂�
		if (MessageBox::Show("Book���J���Ă��܂���B\n�V�����쐬���܂����H", "", MessageBoxButtons::OKCancel).ToString() == "OK")	//���ʂ�OK�Ȃ�
		{
			_CreateBook();
		}
		return;
	}

	// �ȉ�book���J���Ă���Ƃ�
	Form^ AddDataDialog = gcnew AddDataForm();	//�f�[�^�ǉ�Form��gcnew����
	if (AddDataDialog->ShowDialog(this).ToString() == "OK")	//Form��\�����Č��ʂ�OK�Ȃ�
	{
		int add_year = AddDataForm::GetAddDate('y');	//�f�[�^�ǉ�Form����N���擾
		int add_month = AddDataForm::GetAddDate('m');	//�f�[�^�ǉ�Form���猎���擾
		
		_SetOpening(_opening_bookpath, add_year, add_month);
		_load_grid_and_graph();
		history_grid->Rows->Add(AddDataForm::GetAddData());	//�ǉ��t�H�[������ǉ��f�[�^���擾���ĕ\�ɒǉ�
		_SaveBookPage(_opening_bookpath, add_year, add_month);
		tabs->SelectedIndex = 0;
		_load_grid_and_graph();
	}
}

Void WalletCheck::MainForm::delete_data_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	DataGridViewSelectedRowCollection^ rows = history_grid->SelectedRows;	//�I������Ă���s�����ׂĎ擾
	if (rows->Count == 0)	//�I������Ă��Ȃ�������
	{
		Message("�폜����f�[�^�̍s��I�����Ă��������B\nCtrl + �N���b�N�ŕ����s�I���ł��܂��B", "�w���v");
		return;
	}

	for each (DataGridViewRow ^ row in rows)
	{
		history_grid->Rows->RemoveAt(row->Index);	//�I������Ă���s���폜
		_SaveBookPage(_opening_bookpath, _opening_year, _opening_month);	//�ۑ�
	}
	_load_grid_and_graph();
}

/*----------���̑��̃C�x���g----------*/

// �\�ɕ��בւ����N�����Ƃ��̃C�x���g
Void WalletCheck::MainForm::history_grid_SortCompare(Object^ sender, System::Windows::Forms::DataGridViewSortCompareEventArgs^ e)
{
	if (e->Column == history_grid->Columns[0])	//0�Ԗڂ̃R�����̕��ёւ��̎�
	{
		e->SortResult = _StringToInt(e->CellValue1->ToString()) - _StringToInt(e->CellValue2->ToString()); //���ёւ��̏�����l�̍����Ɂ����l���ɂȂ�
		e->Handled = true;
	}
}