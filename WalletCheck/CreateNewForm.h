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

	/// <summary>
	/// Bookを新規作成するForm
	/// </summary>
	public ref class CreateNewForm : public System::Windows::Forms::Form
	{
		public:
			CreateNewForm(void)
			{
				InitializeComponent();
			}

		protected:
			/// <summary>
			/// 使用中のリソースをすべてクリーンアップします。
			/// </summary>
			~CreateNewForm()
			{
				if (components)
				{
					delete components;
				}
			}
#pragma region フォームコントロールの生成
		private:
			System::Windows::Forms::Label^ savefolder_label;
			System::Windows::Forms::TextBox^ path_textbox;
			System::Windows::Forms::TextBox^ bookname_textbox;
			System::Windows::Forms::Button^ browse_button;
			System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;


			System::Windows::Forms::Label^ label1;
			System::Windows::Forms::Button^ create_button;
			System::Windows::Forms::Button^ cancel_button;

			System::ComponentModel::Container^ components;
#pragma endregion
#pragma region WindowsFormDesignerによって生成されたコード
			/// <summary>
			/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
			/// コード エディターで変更しないでください。
			/// </summary>
			void InitializeComponent(void)
			{
				this->savefolder_label = (gcnew System::Windows::Forms::Label());
				this->path_textbox = (gcnew System::Windows::Forms::TextBox());
				this->browse_button = (gcnew System::Windows::Forms::Button());
				this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->create_button = (gcnew System::Windows::Forms::Button());
				this->cancel_button = (gcnew System::Windows::Forms::Button());
				this->bookname_textbox = (gcnew System::Windows::Forms::TextBox());
				this->SuspendLayout();
				// 
				// savefolder_label
				// 
				this->savefolder_label->AutoSize = true;
				this->savefolder_label->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->savefolder_label->Location = System::Drawing::Point(9, 7);
				this->savefolder_label->Name = L"savefolder_label";
				this->savefolder_label->Size = System::Drawing::Size(126, 20);
				this->savefolder_label->TabIndex = 0;
				this->savefolder_label->Text = L"保存先フォルダ";
				// 
				// path_textbox
				// 
				this->path_textbox->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->path_textbox->Location = System::Drawing::Point(12, 30);
				this->path_textbox->Name = L"path_textbox";
				this->path_textbox->ReadOnly = true;
				this->path_textbox->Size = System::Drawing::Size(371, 27);
				this->path_textbox->TabIndex = 1;
				// 
				// browse_button
				// 
				this->browse_button->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->browse_button->Location = System::Drawing::Point(389, 30);
				this->browse_button->Name = L"browse_button";
				this->browse_button->Size = System::Drawing::Size(81, 27);
				this->browse_button->TabIndex = 2;
				this->browse_button->Text = L"参照";
				this->browse_button->UseVisualStyleBackColor = true;
				this->browse_button->Click += gcnew System::EventHandler(this, &CreateNewForm::browse_button_Click);
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->label1->Location = System::Drawing::Point(12, 75);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(69, 20);
				this->label1->TabIndex = 4;
				this->label1->Text = L"帳簿名";
				// 
				// create_button
				// 
				this->create_button->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->create_button->Location = System::Drawing::Point(395, 134);
				this->create_button->Name = L"create_button";
				this->create_button->Size = System::Drawing::Size(75, 33);
				this->create_button->TabIndex = 5;
				this->create_button->Text = L"作成";
				this->create_button->UseVisualStyleBackColor = true;
				this->create_button->Click += gcnew System::EventHandler(this, &CreateNewForm::create_button_Click);
				// 
				// cancel_button
				// 
				this->cancel_button->DialogResult = System::Windows::Forms::DialogResult::Cancel;
				this->cancel_button->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->cancel_button->Location = System::Drawing::Point(296, 134);
				this->cancel_button->Name = L"cancel_button";
				this->cancel_button->Size = System::Drawing::Size(93, 33);
				this->cancel_button->TabIndex = 6;
				this->cancel_button->Text = L"キャンセル";
				this->cancel_button->UseVisualStyleBackColor = true;
				this->cancel_button->Click += gcnew System::EventHandler(this, &CreateNewForm::cancel_button_Click);
				// 
				// bookname_textbox
				// 
				this->bookname_textbox->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->bookname_textbox->Location = System::Drawing::Point(12, 98);
				this->bookname_textbox->Name = L"bookname_textbox";
				this->bookname_textbox->Size = System::Drawing::Size(458, 27);
				this->bookname_textbox->TabIndex = 3;
				this->bookname_textbox->TextChanged += gcnew System::EventHandler(this, &CreateNewForm::bookname_textbox_TextChanged);
				// 
				// CreateNewForm
				// 
				this->AcceptButton = this->create_button;
				this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->CancelButton = this->cancel_button;
				this->ClientSize = System::Drawing::Size(482, 178);
				this->Controls->Add(this->cancel_button);
				this->Controls->Add(this->create_button);
				this->Controls->Add(this->label1);
				this->Controls->Add(this->bookname_textbox);
				this->Controls->Add(this->browse_button);
				this->Controls->Add(this->path_textbox);
				this->Controls->Add(this->savefolder_label);
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
				this->Name = L"CreateNewForm";
				this->ShowIcon = false;
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
				this->Text = L"新規作成";
				this->Load += gcnew System::EventHandler(this, &CreateNewForm::CreateNewForm_Load);
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion
#pragma region ユーザー定義
			public:
				/// <summary>
				/// 新規作成したBookのパスを取得します。
				/// </summary>
				/// <returns>：新規作成したBookのパス</returns>
				static String^ GetBookPath();

		private:
			static String^ _bookname;
			static String^ _bookpath;
#pragma endregion
#pragma region イベントハンドラ等
		private: 
			Void CreateNewForm_Load(System::Object^ sender, System::EventArgs^ e);

			Void browse_button_Click(System::Object^ sender, System::EventArgs^ e);
			Void create_button_Click(System::Object^ sender, System::EventArgs^ e);
			Void cancel_button_Click(System::Object^ sender, System::EventArgs^ e);
			Void bookname_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e);
#pragma endregion
			
};
}
