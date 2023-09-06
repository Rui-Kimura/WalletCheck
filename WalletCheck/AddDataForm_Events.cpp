#include "AddDataForm.h"
#include "MainForm.h"
#include "csv.h"

using namespace csv;

/// <summary>Form���[�h���̃C�x���g</summary>
System::Void WalletCheck::AddDataForm::AddDataForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	// Form�̓��t���͗��ɍ����̓��t������
	year_num->Value = Int32::Parse(System::DateTime::Now.ToString("yyyy")->ToString());
	month_num->Value = Int32::Parse(System::DateTime::Now.ToString("MM")->ToString());
	day_num->Value = Int32::Parse(System::DateTime::Now.ToString("dd")->ToString());

	_reload_combobox(sender,"category_box","Categories");
	_reload_combobox(sender, "payment_box", "PaymentMethods");

}

Void WalletCheck::AddDataForm::category_manage_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	_manage_items_button_click(sender,"category_box", "�J�e�S���[", "Categories");	//�J�e�S���[�̕ҏWForm
}

Void WalletCheck::AddDataForm::payment_manage_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	_manage_items_button_click(sender,"payment_box", "���ϕ��@", "PaymentMethods");	//�x�����@�̕ҏWForm
}

/// <summary>�L�����Z���{�^�����������Ƃ��̃C�x���g</summary>
System::Void WalletCheck::AddDataForm::cancel_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

/// <summary>�ǉ��{�^�����������Ƃ��̃C�x���g</summary>
System::Void WalletCheck::AddDataForm::add_button_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Form�ɓ��͂��ꂽ�l��ϐ��Ɋi�[
	//������̓R���}�������ĂȂ����`�F�b�N����csv������Ȃ��悤�΍�
	_year = Decimal::ToInt32(year_num->Value);
	_month = Decimal::ToInt32(month_num->Value);
	_day = Decimal::ToInt32(day_num->Value);
	_category = csv_manager::ShapeValue(category_box->Text == "" ? "���̑�" : category_box->Text);
	_memo = csv_manager::ShapeValue(memo_box->Text == "" ? "-" : memo_box->Text);
	_payment = csv_manager::ShapeValue(payment_box->Text);
	_money = Decimal::ToInt64(money_box->Value);
	if (spending_radiobutton->Checked)	//�x�o�Ƀ`�F�b�N�������Ă�����
	{
		_money *= -1;	//���z���}�C�i�X��
	}
	this->DialogResult = Forms::DialogResult::OK;	//Form�̌��ʂ�OK��
	this->Close();
}