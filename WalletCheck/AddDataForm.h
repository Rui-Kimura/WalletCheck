/*----------AddDataForm.h----------*/

#pragma once

namespace WalletCheck {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Configuration;
	using namespace System::Windows;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace WalletCheck;
	using namespace System::Collections::Generic;

	/// <summary>
	/// データを追加するForm
	/// </summary>
	public ref class AddDataForm : public System::Windows::Forms::Form
	{
		public:
			AddDataForm(void)
			{
				InitializeComponent();
			}

		protected:
			~AddDataForm()
			{
				if (components)
				{
					delete components;
				}
			}
#pragma region フォームコントロールの生成
		private:
			System::Windows::Forms::Label^ date_label;
			System::Windows::Forms::Label^ month_label;
			System::Windows::Forms::NumericUpDown^ month_num;
			System::Windows::Forms::NumericUpDown^ day_num;


			System::Windows::Forms::Label^ day_label;
			System::Windows::Forms::Label^ label1;
			System::Windows::Forms::ComboBox^ category_box;

			System::Windows::Forms::Label^ label2;
			System::Windows::Forms::TextBox^ memo_box;

			System::Windows::Forms::Label^ label3;
			System::Windows::Forms::ComboBox^ payment_box;
			System::Windows::Forms::NumericUpDown^ money_box;


			System::Windows::Forms::Label^ label4;
			System::Windows::Forms::Button^ add_button;
			System::Windows::Forms::Button^ cancel_button;
			System::Windows::Forms::NumericUpDown^ year_num;
			System::Windows::Forms::Label^ label5;
			System::Windows::Forms::RadioButton^ spending_radiobutton;
			System::Windows::Forms::RadioButton^ income_radiobutton;
			System::Windows::Forms::Button^ category_manage_button;
			System::Windows::Forms::Button^ payment_manage_button;


		   System::ComponentModel::Container^ components;
#pragma endregion

#pragma region WindowsFormDesignerによって生成されたコード
			void InitializeComponent(void)
			{
				this->date_label = (gcnew System::Windows::Forms::Label());
				this->month_label = (gcnew System::Windows::Forms::Label());
				this->month_num = (gcnew System::Windows::Forms::NumericUpDown());
				this->day_num = (gcnew System::Windows::Forms::NumericUpDown());
				this->day_label = (gcnew System::Windows::Forms::Label());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->category_box = (gcnew System::Windows::Forms::ComboBox());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->memo_box = (gcnew System::Windows::Forms::TextBox());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->payment_box = (gcnew System::Windows::Forms::ComboBox());
				this->money_box = (gcnew System::Windows::Forms::NumericUpDown());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->add_button = (gcnew System::Windows::Forms::Button());
				this->cancel_button = (gcnew System::Windows::Forms::Button());
				this->year_num = (gcnew System::Windows::Forms::NumericUpDown());
				this->label5 = (gcnew System::Windows::Forms::Label());
				this->spending_radiobutton = (gcnew System::Windows::Forms::RadioButton());
				this->income_radiobutton = (gcnew System::Windows::Forms::RadioButton());
				this->category_manage_button = (gcnew System::Windows::Forms::Button());
				this->payment_manage_button = (gcnew System::Windows::Forms::Button());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->month_num))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->day_num))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->money_box))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->year_num))->BeginInit();
				this->SuspendLayout();
				// 
				// date_label
				// 
				this->date_label->AutoSize = true;
				this->date_label->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->date_label->Location = System::Drawing::Point(9, 11);
				this->date_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				this->date_label->Name = L"date_label";
				this->date_label->Size = System::Drawing::Size(39, 16);
				this->date_label->TabIndex = 14;
				this->date_label->Text = L"日付";
				// 
				// month_label
				// 
				this->month_label->AutoSize = true;
				this->month_label->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->month_label->Location = System::Drawing::Point(192, 11);
				this->month_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				this->month_label->Name = L"month_label";
				this->month_label->Size = System::Drawing::Size(23, 16);
				this->month_label->TabIndex = 16;
				this->month_label->Text = L"月";
				// 
				// month_num
				// 
				this->month_num->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->month_num->Location = System::Drawing::Point(134, 10);
				this->month_num->Margin = System::Windows::Forms::Padding(2);
				this->month_num->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
				this->month_num->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
				this->month_num->Name = L"month_num";
				this->month_num->Size = System::Drawing::Size(53, 23);
				this->month_num->TabIndex = 2;
				this->month_num->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				this->month_num->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
				// 
				// day_num
				// 
				this->day_num->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->day_num->Location = System::Drawing::Point(218, 10);
				this->day_num->Margin = System::Windows::Forms::Padding(2);
				this->day_num->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
				this->day_num->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
				this->day_num->Name = L"day_num";
				this->day_num->Size = System::Drawing::Size(53, 23);
				this->day_num->TabIndex = 3;
				this->day_num->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				this->day_num->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
				// 
				// day_label
				// 
				this->day_label->AutoSize = true;
				this->day_label->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->day_label->Location = System::Drawing::Point(276, 11);
				this->day_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				this->day_label->Name = L"day_label";
				this->day_label->Size = System::Drawing::Size(23, 16);
				this->day_label->TabIndex = 17;
				this->day_label->Text = L"日";
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->label1->Location = System::Drawing::Point(9, 40);
				this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(64, 16);
				this->label1->TabIndex = 18;
				this->label1->Text = L"カテゴリー";
				// 
				// category_box
				// 
				this->category_box->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->category_box->FormattingEnabled = true;
				this->category_box->Location = System::Drawing::Point(80, 38);
				this->category_box->Margin = System::Windows::Forms::Padding(2);
				this->category_box->Name = L"category_box";
				this->category_box->Size = System::Drawing::Size(134, 24);
				this->category_box->TabIndex = 4;
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->label2->Location = System::Drawing::Point(9, 67);
				this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(30, 16);
				this->label2->TabIndex = 19;
				this->label2->Text = L"メモ";
				// 
				// memo_box
				// 
				this->memo_box->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->memo_box->Location = System::Drawing::Point(80, 65);
				this->memo_box->Margin = System::Windows::Forms::Padding(2);
				this->memo_box->Name = L"memo_box";
				this->memo_box->Size = System::Drawing::Size(218, 23);
				this->memo_box->TabIndex = 6;
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->label3->Location = System::Drawing::Point(9, 94);
				this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(71, 16);
				this->label3->TabIndex = 20;
				this->label3->Text = L"決済方法";
				// 
				// payment_box
				// 
				this->payment_box->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->payment_box->FormattingEnabled = true;
				this->payment_box->Location = System::Drawing::Point(80, 91);
				this->payment_box->Margin = System::Windows::Forms::Padding(2);
				this->payment_box->Name = L"payment_box";
				this->payment_box->Size = System::Drawing::Size(134, 24);
				this->payment_box->TabIndex = 7;
				// 
				// money_box
				// 
				this->money_box->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->money_box->Location = System::Drawing::Point(174, 118);
				this->money_box->Margin = System::Windows::Forms::Padding(2);
				this->money_box->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1874919423, 2328306, 0, 0 });
				this->money_box->Name = L"money_box";
				this->money_box->Size = System::Drawing::Size(120, 23);
				this->money_box->TabIndex = 11;
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->label4->Location = System::Drawing::Point(9, 121);
				this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(39, 16);
				this->label4->TabIndex = 21;
				this->label4->Text = L"金額";
				// 
				// add_button
				// 
				this->add_button->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->add_button->Location = System::Drawing::Point(219, 145);
				this->add_button->Margin = System::Windows::Forms::Padding(2);
				this->add_button->Name = L"add_button";
				this->add_button->Size = System::Drawing::Size(79, 33);
				this->add_button->TabIndex = 13;
				this->add_button->Text = L"追加";
				this->add_button->UseVisualStyleBackColor = true;
				this->add_button->Click += gcnew System::EventHandler(this, &AddDataForm::add_button_Click);
				// 
				// cancel_button
				// 
				this->cancel_button->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->cancel_button->Location = System::Drawing::Point(134, 145);
				this->cancel_button->Margin = System::Windows::Forms::Padding(2);
				this->cancel_button->Name = L"cancel_button";
				this->cancel_button->Size = System::Drawing::Size(81, 33);
				this->cancel_button->TabIndex = 12;
				this->cancel_button->Text = L"キャンセル";
				this->cancel_button->UseVisualStyleBackColor = true;
				this->cancel_button->Click += gcnew System::EventHandler(this, &AddDataForm::cancel_button_Click);
				// 
				// year_num
				// 
				this->year_num->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->year_num->Location = System::Drawing::Point(50, 10);
				this->year_num->Margin = System::Windows::Forms::Padding(2);
				this->year_num->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9999, 0, 0, 0 });
				this->year_num->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
				this->year_num->Name = L"year_num";
				this->year_num->Size = System::Drawing::Size(53, 23);
				this->year_num->TabIndex = 1;
				this->year_num->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
				this->year_num->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
				// 
				// label5
				// 
				this->label5->AutoSize = true;
				this->label5->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->label5->Location = System::Drawing::Point(108, 11);
				this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				this->label5->Name = L"label5";
				this->label5->Size = System::Drawing::Size(23, 16);
				this->label5->TabIndex = 15;
				this->label5->Text = L"年";
				// 
				// spending_radiobutton
				// 
				this->spending_radiobutton->AutoSize = true;
				this->spending_radiobutton->Checked = true;
				this->spending_radiobutton->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->spending_radiobutton->Location = System::Drawing::Point(60, 119);
				this->spending_radiobutton->Margin = System::Windows::Forms::Padding(2);
				this->spending_radiobutton->Name = L"spending_radiobutton";
				this->spending_radiobutton->Size = System::Drawing::Size(57, 20);
				this->spending_radiobutton->TabIndex = 9;
				this->spending_radiobutton->TabStop = true;
				this->spending_radiobutton->Text = L"支出";
				this->spending_radiobutton->UseVisualStyleBackColor = true;
				// 
				// income_radiobutton
				// 
				this->income_radiobutton->AutoSize = true;
				this->income_radiobutton->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->income_radiobutton->Location = System::Drawing::Point(117, 119);
				this->income_radiobutton->Margin = System::Windows::Forms::Padding(2);
				this->income_radiobutton->Name = L"income_radiobutton";
				this->income_radiobutton->Size = System::Drawing::Size(57, 20);
				this->income_radiobutton->TabIndex = 10;
				this->income_radiobutton->Text = L"収入";
				this->income_radiobutton->UseVisualStyleBackColor = true;
				// 
				// category_manage_button
				// 
				this->category_manage_button->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->category_manage_button->Location = System::Drawing::Point(218, 38);
				this->category_manage_button->Margin = System::Windows::Forms::Padding(2);
				this->category_manage_button->Name = L"category_manage_button";
				this->category_manage_button->Size = System::Drawing::Size(78, 25);
				this->category_manage_button->TabIndex = 5;
				this->category_manage_button->Text = L"管理";
				this->category_manage_button->UseVisualStyleBackColor = true;
				this->category_manage_button->Click += gcnew System::EventHandler(this, &AddDataForm::category_manage_button_Click);
				// 
				// payment_manage_button
				// 
				this->payment_manage_button->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->payment_manage_button->Location = System::Drawing::Point(218, 90);
				this->payment_manage_button->Margin = System::Windows::Forms::Padding(2);
				this->payment_manage_button->Name = L"payment_manage_button";
				this->payment_manage_button->Size = System::Drawing::Size(78, 25);
				this->payment_manage_button->TabIndex = 8;
				this->payment_manage_button->Text = L"管理";
				this->payment_manage_button->UseVisualStyleBackColor = true;
				this->payment_manage_button->Click += gcnew System::EventHandler(this, &AddDataForm::payment_manage_button_Click);
				// 
				// AddDataForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
				this->ClientSize = System::Drawing::Size(305, 186);
				this->Controls->Add(this->payment_manage_button);
				this->Controls->Add(this->category_manage_button);
				this->Controls->Add(this->income_radiobutton);
				this->Controls->Add(this->spending_radiobutton);
				this->Controls->Add(this->label5);
				this->Controls->Add(this->year_num);
				this->Controls->Add(this->cancel_button);
				this->Controls->Add(this->add_button);
				this->Controls->Add(this->label4);
				this->Controls->Add(this->money_box);
				this->Controls->Add(this->payment_box);
				this->Controls->Add(this->label3);
				this->Controls->Add(this->memo_box);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->category_box);
				this->Controls->Add(this->label1);
				this->Controls->Add(this->day_label);
				this->Controls->Add(this->day_num);
				this->Controls->Add(this->month_num);
				this->Controls->Add(this->month_label);
				this->Controls->Add(this->date_label);
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
				this->Margin = System::Windows::Forms::Padding(2);
				this->Name = L"AddDataForm";
				this->ShowIcon = false;
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
				this->Text = L"データを追加";
				this->Load += gcnew System::EventHandler(this, &AddDataForm::AddDataForm_Load);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->month_num))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->day_num))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->money_box))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->year_num))->EndInit();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion

#pragma region ユーザー定義
		public:
			/// <summary>
			/// 追加されるデータを取得します。
			/// </summary>
			/// <returns>追加されるデータの配列（Object型）</returns>
			static array<Object^>^ GetAddData();

			/// <summary>
			/// 追加されるデータの日付を取得します。
			/// </summary>
			/// <param name="type">：日付のタイプ　（y = 年、m = 月、d = 日にち）</param>
			/// <returns>指定のタイプの日付（int）</returns>
			static int GetAddDate(char type);

		private:
			static int _year, _month,_day;
			static long long _money;
			static String^ _category;
			static String^ _memo;
			static String^ _payment;

			/// <summary>
			/// コンボボックスの管理ボタンが押された時の共通イベントです。
			/// </summary>
			/// <param name="sender">：呼び出し元のObject</param>
			/// <param name="comboboxname">：管理するコンボボックスの名前</param>
			/// <param name="itemname">：管理するアイテム名</param>
			/// <param name="keyname">：Configファイルの保存先キー</param>
			static Void _manage_items_button_click(Object^ sender, String^ comboboxname, String^ itemname, String^ keyname);
			
			/// <summary>
			/// コンボボックスを再読み込みします。
			/// </summary>
			/// <param name="sender">：呼び出し元のObject</param>
			/// <param name="combobox_controlname">：再読み込みするコンボボックスの名前</param>
			/// <param name="keyname">：読み込むConfigファイルの保存先キー</param>
			static Void _reload_combobox(Object^ sender,String^ combobox_controlname,String^ keyname);
#pragma endregion 

#pragma region イベントハンドラ等
			Void AddDataForm_Load(System::Object^ sender, System::EventArgs^ e);
			Void cancel_button_Click(System::Object^ sender, System::EventArgs^ e);
			Void add_button_Click(System::Object^ sender, System::EventArgs^ e);
			Void category_manage_button_Click(System::Object^ sender, System::EventArgs^ e);
			Void payment_manage_button_Click(System::Object^ sender, System::EventArgs^ e);
#pragma endregion
};
}
