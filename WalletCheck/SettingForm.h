 /*----------SettingForm.h---------*/

#pragma once
#include "MainForm.h"

namespace WalletCheck {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// アプリケーション設定のフォーム
	/// </summary>
	public ref class SettingForm : public System::Windows::Forms::Form
	{
		public:
			SettingForm(void)
			{
				InitializeComponent();
			}

		protected:
			/// <summary>
			/// 使用中のリソースをすべてクリーンアップします。
			/// </summary>
			~SettingForm()
			{
				if (components)
				{
					delete components;
				}
			}
		private:
			System::Windows::Forms::CheckBox^ open_lastbook_check;
		protected:
		private:

			System::Windows::Forms::Label^ label1;
			Windows::Forms::Button^ manage_category_button;
			System::Windows::Forms::Button^ manage_payment_button;




			System::Windows::Forms::Label^ label2;
			System::Windows::Forms::Label^ label3;
			System::Windows::Forms::Label^ label4;
			System::Windows::Forms::CheckBox^ check_update_check;


			System::Windows::Forms::Button^ update_button;
			System::Windows::Forms::Label^ label5;
			System::Windows::Forms::Label^ label6;
			System::Windows::Forms::Button^ setting_button;
			System::Windows::Forms::Button^ cancel_button;



		protected:

		private:
			/// <summary>
			/// 必要なデザイナー変数です。
			/// </summary>
			System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			/// <summary>
			/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
			/// コード エディターで変更しないでください。
			/// </summary>
			void InitializeComponent(void)
			{
				this->open_lastbook_check = (gcnew System::Windows::Forms::CheckBox());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->manage_category_button = (gcnew System::Windows::Forms::Button());
				this->manage_payment_button = (gcnew System::Windows::Forms::Button());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->check_update_check = (gcnew System::Windows::Forms::CheckBox());
				this->update_button = (gcnew System::Windows::Forms::Button());
				this->label5 = (gcnew System::Windows::Forms::Label());
				this->label6 = (gcnew System::Windows::Forms::Label());
				this->setting_button = (gcnew System::Windows::Forms::Button());
				this->cancel_button = (gcnew System::Windows::Forms::Button());
				this->SuspendLayout();
				// 
				// open_lastbook_check
				// 
				this->open_lastbook_check->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->open_lastbook_check->Location = System::Drawing::Point(13, 33);
				this->open_lastbook_check->Margin = System::Windows::Forms::Padding(4);
				this->open_lastbook_check->Name = L"open_lastbook_check";
				this->open_lastbook_check->Size = System::Drawing::Size(306, 32);
				this->open_lastbook_check->TabIndex = 1;
				this->open_lastbook_check->Text = L"起動時に前回のBookを開く";
				this->open_lastbook_check->UseVisualStyleBackColor = true;
				// 
				// label1
				// 
				this->label1->Location = System::Drawing::Point(15, 146);
				this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(69, 20);
				this->label1->TabIndex = 2;
				this->label1->Text = L"カテゴリ";
				// 
				// manage_category_button
				// 
				this->manage_category_button->Location = System::Drawing::Point(115, 142);
				this->manage_category_button->Name = L"manage_category_button";
				this->manage_category_button->Size = System::Drawing::Size(75, 29);
				this->manage_category_button->TabIndex = 3;
				this->manage_category_button->Text = L"管理";
				this->manage_category_button->UseVisualStyleBackColor = true;
				this->manage_category_button->Click += gcnew System::EventHandler(this, &SettingForm::manage_category_button_Click);
				// 
				// manage_payment_button
				// 
				this->manage_payment_button->Location = System::Drawing::Point(115, 171);
				this->manage_payment_button->Name = L"manage_payment_button";
				this->manage_payment_button->Size = System::Drawing::Size(75, 29);
				this->manage_payment_button->TabIndex = 5;
				this->manage_payment_button->Text = L"管理";
				this->manage_payment_button->UseVisualStyleBackColor = true;
				this->manage_payment_button->Click += gcnew System::EventHandler(this, &SettingForm::manage_payment_button_Click);
				// 
				// label2
				// 
				this->label2->Location = System::Drawing::Point(15, 175);
				this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(93, 20);
				this->label2->TabIndex = 4;
				this->label2->Text = L"決済方法";
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Location = System::Drawing::Point(12, 9);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(131, 16);
				this->label3->TabIndex = 6;
				this->label3->Text = L"アプリケーション設定";
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->Location = System::Drawing::Point(12, 117);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(72, 16);
				this->label4->TabIndex = 7;
				this->label4->Text = L"Book設定";
				// 
				// check_update_check
				// 
				this->check_update_check->AutoSize = true;
				this->check_update_check->Location = System::Drawing::Point(12, 72);
				this->check_update_check->Name = L"check_update_check";
				this->check_update_check->Size = System::Drawing::Size(160, 20);
				this->check_update_check->TabIndex = 8;
				this->check_update_check->Text = L"自動アップデート確認";
				this->check_update_check->UseVisualStyleBackColor = true;
				// 
				// update_button
				// 
				this->update_button->Location = System::Drawing::Point(217, 69);
				this->update_button->Name = L"update_button";
				this->update_button->Size = System::Drawing::Size(102, 29);
				this->update_button->TabIndex = 9;
				this->update_button->Text = L"手動確認";
				this->update_button->UseVisualStyleBackColor = true;
				this->update_button->Click += gcnew System::EventHandler(this, &SettingForm::update_button_Click);
				// 
				// label5
				// 
				this->label5->BackColor = System::Drawing::SystemColors::ControlDark;
				this->label5->Location = System::Drawing::Point(4, 106);
				this->label5->Name = L"label5";
				this->label5->Size = System::Drawing::Size(324, 1);
				this->label5->TabIndex = 10;
				// 
				// label6
				// 
				this->label6->BackColor = System::Drawing::SystemColors::ControlDark;
				this->label6->Location = System::Drawing::Point(4, 211);
				this->label6->Name = L"label6";
				this->label6->Size = System::Drawing::Size(324, 1);
				this->label6->TabIndex = 11;
				// 
				// setting_button
				// 
				this->setting_button->Location = System::Drawing::Point(244, 219);
				this->setting_button->Name = L"setting_button";
				this->setting_button->Size = System::Drawing::Size(75, 30);
				this->setting_button->TabIndex = 12;
				this->setting_button->Text = L"設定";
				this->setting_button->UseVisualStyleBackColor = true;
				this->setting_button->Click += gcnew System::EventHandler(this, &SettingForm::setting_button_Click);
				// 
				// cancel_button
				// 
				this->cancel_button->Location = System::Drawing::Point(115, 219);
				this->cancel_button->Name = L"cancel_button";
				this->cancel_button->Size = System::Drawing::Size(123, 30);
				this->cancel_button->TabIndex = 13;
				this->cancel_button->Text = L"キャンセル";
				this->cancel_button->UseVisualStyleBackColor = true;
				this->cancel_button->Click += gcnew System::EventHandler(this, &SettingForm::cancel_button_Click);
				// 
				// SettingForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
				this->ClientSize = System::Drawing::Size(332, 261);
				this->Controls->Add(this->cancel_button);
				this->Controls->Add(this->setting_button);
				this->Controls->Add(this->label6);
				this->Controls->Add(this->label5);
				this->Controls->Add(this->update_button);
				this->Controls->Add(this->check_update_check);
				this->Controls->Add(this->label4);
				this->Controls->Add(this->label3);
				this->Controls->Add(this->manage_payment_button);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->manage_category_button);
				this->Controls->Add(this->label1);
				this->Controls->Add(this->open_lastbook_check);
				this->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
				this->Margin = System::Windows::Forms::Padding(4);
				this->Name = L"SettingForm";
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
				this->Text = L"設定";
				this->Load += gcnew System::EventHandler(this, &SettingForm::SettingForm_Load);
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion

#pragma region ユーザー定義
			System::Void _load_settings();
			System::Void _set_settings();

#pragma endregion

#pragma region イベントハンドラ等
		private:
			System::Void SettingForm_Load(System::Object^ sender, System::EventArgs^ e);
			System::Void update_button_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void setting_button_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void manage_payment_button_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void cancel_button_Click(System::Object^ sender, System::EventArgs^ e);
			System::Void manage_category_button_Click(System::Object^ sender, System::EventArgs^ e);
#pragma endregion

	};
}
