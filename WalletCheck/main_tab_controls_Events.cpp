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
		_opening_year = AddDataForm::GetAddDate('y');	//�f�[�^�ǉ�Form����N���擾
		_opening_month = AddDataForm::GetAddDate('m');	//�f�[�^�ǉ�Form���猎���擾

		List<List<String^>^> grid_data;
		_OpenBookPage(_opening_bookpath, _opening_year, _opening_month, grid_data);
		_load_grid(this,"history_grid", grid_data);
		history_grid->Rows->Add(AddDataForm::GetAddData());	//�ǉ��t�H�[������ǉ��f�[�^���擾���ĕ\�ɒǉ�
		_SaveBook(_opening_bookpath, _opening_year, _opening_month);
	}
}

/*----------TooLStripMenu�̃C�x���g�n���h��----------*/

//�V�K�쐬�{�^���������ꂽ���̃C�x���g
Void MainForm::CreateNewToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	_CreateBook();
}

//�J���{�^���������ꂽ���̃C�x���g
Void MainForm::OpenToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	if (folderBrowserDialog1->ShowDialog().ToString() == "OK")	//�t�H���_�I���_�C�A���O��\�����Č��ʂ�OK���m���߂�
	{
		_opening_bookpath = folderBrowserDialog1->SelectedPath;
		_OpenBook(_opening_bookpath);
	}
}

//�ŋ߂�Book�������ꂽ�Ƃ��̃C�x���g
Void WalletCheck::MainForm::RecenttoolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	ToolStripMenuItem^ RecentToolStripMenuItem = (ToolStripMenuItem^)sender;	//Object�^sender��ToolStripMenuItem�^�ɃL���X�g
	String^ bookpath_s = RecentToolStripMenuItem->Text;	//MenuItem�ɕ\������Ă���e�L�X�g���p�X
	_OpenBook(bookpath_s);
}

//�I���{�^���������ꂽ���̃C�x���g
Void MainForm::ExitToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
{
	this->Close();
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