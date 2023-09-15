/*----------ApplicationInfo.h----------*/

#pragma once

namespace WalletCheck {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// アプリケーション情報を表示するフォーム
	/// </summary>
	public ref class ApplicationInfoForm : public System::Windows::Forms::Form
	{
		public:
			ApplicationInfoForm(void)
			{
				InitializeComponent();
			}

		protected:
		private:
			/// <summary>
			/// 使用中のリソースをすべてクリーンアップします。
			/// </summary>
			~ApplicationInfoForm()
			{
				if (components)
				{
					delete components;
				}
			}
			System::Windows::Forms::Label^ applicationname_label;
			System::Windows::Forms::PictureBox^ icon_picturebox;

			System::Windows::Forms::Label^ version_label;

			System::Windows::Forms::Label^ copyright_label;
			System::Windows::Forms::Label^ description_label;
			System::Windows::Forms::Label^ company_label;


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
				System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ApplicationInfoForm::typeid));
				this->applicationname_label = (gcnew System::Windows::Forms::Label());
				this->icon_picturebox = (gcnew System::Windows::Forms::PictureBox());
				this->version_label = (gcnew System::Windows::Forms::Label());
				this->copyright_label = (gcnew System::Windows::Forms::Label());
				this->description_label = (gcnew System::Windows::Forms::Label());
				this->company_label = (gcnew System::Windows::Forms::Label());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->icon_picturebox))->BeginInit();
				this->SuspendLayout();
				// 
				// applicationname_label
				// 
				this->applicationname_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					| System::Windows::Forms::AnchorStyles::Left)
					| System::Windows::Forms::AnchorStyles::Right));
				this->applicationname_label->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(128)));
				this->applicationname_label->Location = System::Drawing::Point(93, 12);
				this->applicationname_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				this->applicationname_label->Name = L"applicationname_label";
				this->applicationname_label->Size = System::Drawing::Size(237, 64);
				this->applicationname_label->TabIndex = 0;
				this->applicationname_label->Text = L"ApplicationName";
				this->applicationname_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				// 
				// icon_picturebox
				// 
				this->icon_picturebox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"icon_picturebox.Image")));
				this->icon_picturebox->Location = System::Drawing::Point(12, 12);
				this->icon_picturebox->Name = L"icon_picturebox";
				this->icon_picturebox->Size = System::Drawing::Size(74, 74);
				this->icon_picturebox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
				this->icon_picturebox->TabIndex = 1;
				this->icon_picturebox->TabStop = false;
				// 
				// version_label
				// 
				this->version_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					| System::Windows::Forms::AnchorStyles::Left)
					| System::Windows::Forms::AnchorStyles::Right));
				this->version_label->Location = System::Drawing::Point(2, 63);
				this->version_label->Name = L"version_label";
				this->version_label->Size = System::Drawing::Size(418, 30);
				this->version_label->TabIndex = 2;
				this->version_label->Text = L"version 0.0.0.0";
				this->version_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				// 
				// copyright_label
				// 
				this->copyright_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					| System::Windows::Forms::AnchorStyles::Left)
					| System::Windows::Forms::AnchorStyles::Right));
				this->copyright_label->Location = System::Drawing::Point(2, 94);
				this->copyright_label->Name = L"copyright_label";
				this->copyright_label->Size = System::Drawing::Size(418, 30);
				this->copyright_label->TabIndex = 3;
				this->copyright_label->Text = L"copyright(C)2022-2023 runa-chama@github";
				this->copyright_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				// 
				// description_label
				// 
				this->description_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					| System::Windows::Forms::AnchorStyles::Left)
					| System::Windows::Forms::AnchorStyles::Right));
				this->description_label->Location = System::Drawing::Point(1, 124);
				this->description_label->Name = L"description_label";
				this->description_label->Size = System::Drawing::Size(421, 80);
				this->description_label->TabIndex = 4;
				this->description_label->Text = L"説明";
				this->description_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				// 
				// company_label
				// 
				this->company_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					| System::Windows::Forms::AnchorStyles::Left)
					| System::Windows::Forms::AnchorStyles::Right));
				this->company_label->Location = System::Drawing::Point(95, 0);
				this->company_label->Name = L"company_label";
				this->company_label->Size = System::Drawing::Size(232, 30);
				this->company_label->TabIndex = 5;
				this->company_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				// 
				// ApplicationInfoForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
				this->ClientSize = System::Drawing::Size(422, 203);
				this->Controls->Add(this->icon_picturebox);
				this->Controls->Add(this->company_label);
				this->Controls->Add(this->description_label);
				this->Controls->Add(this->copyright_label);
				this->Controls->Add(this->version_label);
				this->Controls->Add(this->applicationname_label);
				this->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
				this->Margin = System::Windows::Forms::Padding(4);
				this->Name = L"ApplicationInfoForm";
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
				this->Text = L"アプリケーション情報";
				this->Load += gcnew System::EventHandler(this, &ApplicationInfoForm::ApplicationInfo_Load);
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->icon_picturebox))->EndInit();
				this->ResumeLayout(false);

			}
#pragma endregion

#pragma region イベントハンドラ等
		private:
			System::Void ApplicationInfo_Load(System::Object^ sender, System::EventArgs^ e);
#pragma endregion
	};
}
