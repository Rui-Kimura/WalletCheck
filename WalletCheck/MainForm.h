/*----------MainForm.h----------*/
#pragma once

#define  MAINCOLOR_LIGHT ForestGreen
#define MAINCOLOR_DARK DarkGreen
#define TEXTCOLOR_LIGHT White
#define TEXTCOLOR_DARK Gray
#define CHAR_STR_BUF 512

#include "graph.h"

using namespace graph;

using namespace System;
using namespace System::Collections::Generic;

namespace WalletCheck
{

	/// <summary>
	/// メインForm
	/// </summary>
	public ref  class MainForm : public System::Windows::Forms::Form
	{

	public:
		MainForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
#pragma region フォームコントロールの生成

		/// MEMO:Systemなどusingしても消すとデザイナーエラーになるのでusingしないで残す
	private:
		System::Windows::Forms::MenuStrip^ menuStrip1;

		System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ CreateNewToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ OpenToolStripMenuItem;
		System::Windows::Forms::Label^ month_label;
		System::Windows::Forms::Label^ bookname_label;
		System::Windows::Forms::Button^ next_button;
		System::Windows::Forms::Button^ previous_button;

		System::Windows::Forms::ToolStripSeparator^ toolStripMenuItem1;
		System::Windows::Forms::ToolStripMenuItem^ ExitToolStripMenuItem;
		System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
		System::Windows::Forms::ToolStripSeparator^ toolStripMenuItem2;
		System::Windows::Forms::ToolStripMenuItem^ RecentBookToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ Recent1toolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ Recent2toolStripMenuItem5;
		System::Windows::Forms::ToolStripMenuItem^ Recent3toolStripMenuItem6;
		System::Windows::Forms::ToolStripMenuItem^ Recent4toolStripMenuItem7;
		System::Windows::Forms::ToolStripMenuItem^ Recent5toolStripMenuItem8;
		System::Windows::Forms::TabPage^ spending_category_tab;
		System::Windows::Forms::SplitContainer^ splitContainer2;
		System::Windows::Forms::Panel^ panel3;
		System::Windows::Forms::Label^ monthly_category_spending;
		System::Windows::Forms::Label^ monthly_category_spending_label;
		System::Windows::Forms::DataVisualization::Charting::Chart^ monthly_category_spending_chart;


		System::Windows::Forms::Panel^ panel4;
		System::Windows::Forms::Label^ yearly_category_spending;
		System::Windows::Forms::Label^ yearly_category_spending_label;
		System::Windows::Forms::DataVisualization::Charting::Chart^ yearly_category_spending_chart;


		System::Windows::Forms::TabPage^ balance_ym_tab;
		System::Windows::Forms::SplitContainer^ splitContainer1;


		System::Windows::Forms::Panel^ panel1;
		System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
		System::Windows::Forms::Label^ monthly_income;
		System::Windows::Forms::Label^ monthly_spending;
		System::Windows::Forms::Label^ monthly_label;
		System::Windows::Forms::DataVisualization::Charting::Chart^ monthly_balance_chart;
		System::Windows::Forms::Panel^ panel2;
		System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
		System::Windows::Forms::Label^ yearly_income;
		System::Windows::Forms::Label^ yearly_spending;
		System::Windows::Forms::Label^ yearly_label;
		System::Windows::Forms::DataVisualization::Charting::Chart^ yearly_balance_chart;
		System::Windows::Forms::TabPage^ main_tab;
		System::Windows::Forms::Button^ delete_data_button;
		System::Windows::Forms::Button^ add_data_button;
		System::Windows::Forms::DataGridView^ history_grid;
		System::Windows::Forms::DataGridViewTextBoxColumn^ date_text;
		System::Windows::Forms::DataGridViewTextBoxColumn^ category;
		System::Windows::Forms::DataGridViewTextBoxColumn^ memo;
		System::Windows::Forms::DataGridViewTextBoxColumn^ payment_method;
		System::Windows::Forms::DataGridViewTextBoxColumn^ amount_of_money;
		System::Windows::Forms::TabControl^ tabs;
		System::Windows::Forms::TabPage^ income_category_tab;


		System::Windows::Forms::SplitContainer^ splitContainer3;
		System::Windows::Forms::Panel^ panel5;
		System::Windows::Forms::Label^ monthly_category_income;

		System::Windows::Forms::Label^ monthly_category_income_label;
		System::Windows::Forms::DataVisualization::Charting::Chart^ monthly_category_income_chart;


		System::Windows::Forms::Panel^ panel6;
		System::Windows::Forms::Label^ yearly_category_income;

		System::Windows::Forms::Label^ yearly_category_income_label;
		System::Windows::Forms::DataVisualization::Charting::Chart^ yearly_category_income_chart;
		System::Windows::Forms::TabPage^ budget_tab;
		System::Windows::Forms::SplitContainer^ splitContainer4;
		System::Windows::Forms::Panel^ panel7;
		System::Windows::Forms::Label^ budget_value;
		System::Windows::Forms::Label^ budtet_label;
		System::Windows::Forms::DataVisualization::Charting::Chart^ budget_chart;
		System::Windows::Forms::Panel^ panel8;
		System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel3;
		System::Windows::Forms::ToolStripMenuItem^ DisplayStripMenuItem3;
		System::Windows::Forms::ToolStripMenuItem^ ApplicationInfoToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ SettingToolStripMenuItem;
		System::Windows::Forms::ToolStripSeparator^ toolStripMenuItem3;

		System::ComponentModel::Container^ components;
#pragma endregion
#pragma region WindowsFormDesignerによって生成されたコード
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea6 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea7 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CreateNewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OpenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->RecentBookToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Recent1toolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Recent2toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Recent3toolStripMenuItem6 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Recent4toolStripMenuItem7 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Recent5toolStripMenuItem8 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->ExitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DisplayStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SettingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->ApplicationInfoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->month_label = (gcnew System::Windows::Forms::Label());
			this->next_button = (gcnew System::Windows::Forms::Button());
			this->previous_button = (gcnew System::Windows::Forms::Button());
			this->bookname_label = (gcnew System::Windows::Forms::Label());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->spending_category_tab = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->monthly_category_spending = (gcnew System::Windows::Forms::Label());
			this->monthly_category_spending_label = (gcnew System::Windows::Forms::Label());
			this->monthly_category_spending_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->yearly_category_spending = (gcnew System::Windows::Forms::Label());
			this->yearly_category_spending_label = (gcnew System::Windows::Forms::Label());
			this->yearly_category_spending_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->balance_ym_tab = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->monthly_income = (gcnew System::Windows::Forms::Label());
			this->monthly_spending = (gcnew System::Windows::Forms::Label());
			this->monthly_label = (gcnew System::Windows::Forms::Label());
			this->monthly_balance_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->yearly_income = (gcnew System::Windows::Forms::Label());
			this->yearly_spending = (gcnew System::Windows::Forms::Label());
			this->yearly_label = (gcnew System::Windows::Forms::Label());
			this->yearly_balance_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->main_tab = (gcnew System::Windows::Forms::TabPage());
			this->delete_data_button = (gcnew System::Windows::Forms::Button());
			this->add_data_button = (gcnew System::Windows::Forms::Button());
			this->history_grid = (gcnew System::Windows::Forms::DataGridView());
			this->date_text = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->category = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->memo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->payment_method = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->amount_of_money = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabs = (gcnew System::Windows::Forms::TabControl());
			this->income_category_tab = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->monthly_category_income = (gcnew System::Windows::Forms::Label());
			this->monthly_category_income_label = (gcnew System::Windows::Forms::Label());
			this->monthly_category_income_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->yearly_category_income = (gcnew System::Windows::Forms::Label());
			this->yearly_category_income_label = (gcnew System::Windows::Forms::Label());
			this->yearly_category_income_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->budget_tab = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer4 = (gcnew System::Windows::Forms::SplitContainer());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->budget_value = (gcnew System::Windows::Forms::Label());
			this->budtet_label = (gcnew System::Windows::Forms::Label());
			this->budget_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->menuStrip1->SuspendLayout();
			this->spending_category_tab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->monthly_category_spending_chart))->BeginInit();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yearly_category_spending_chart))->BeginInit();
			this->balance_ym_tab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->monthly_balance_chart))->BeginInit();
			this->panel2->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yearly_balance_chart))->BeginInit();
			this->main_tab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->history_grid))->BeginInit();
			this->tabs->SuspendLayout();
			this->income_category_tab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->BeginInit();
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->monthly_category_income_chart))->BeginInit();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yearly_category_income_chart))->BeginInit();
			this->budget_tab->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer4))->BeginInit();
			this->splitContainer4->Panel1->SuspendLayout();
			this->splitContainer4->Panel2->SuspendLayout();
			this->splitContainer4->SuspendLayout();
			this->panel7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->budget_chart))->BeginInit();
			this->panel8->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::DarkGreen;
			this->menuStrip1->ForeColor = System::Drawing::Color::White;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->DisplayStripMenuItem3
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menuStrip1->Size = System::Drawing::Size(624, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->BackColor = System::Drawing::Color::ForestGreen;
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->CreateNewToolStripMenuItem,
					this->OpenToolStripMenuItem, this->toolStripMenuItem2, this->RecentBookToolStripMenuItem, this->toolStripMenuItem1, this->ExitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9));
			this->fileToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(67, 20);
			this->fileToolStripMenuItem->Text = L"ファイル(&F)";
			// 
			// CreateNewToolStripMenuItem
			// 
			this->CreateNewToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->CreateNewToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9));
			this->CreateNewToolStripMenuItem->ForeColor = System::Drawing::SystemColors::MenuText;
			this->CreateNewToolStripMenuItem->Name = L"CreateNewToolStripMenuItem";
			this->CreateNewToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::N));
			this->CreateNewToolStripMenuItem->ShowShortcutKeys = false;
			this->CreateNewToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->CreateNewToolStripMenuItem->Text = L"新規作成(&N)";
			this->CreateNewToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::CreateNewToolStripMenuItem_Click);
			// 
			// OpenToolStripMenuItem
			// 
			this->OpenToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9));
			this->OpenToolStripMenuItem->Name = L"OpenToolStripMenuItem";
			this->OpenToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::O));
			this->OpenToolStripMenuItem->ShowShortcutKeys = false;
			this->OpenToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->OpenToolStripMenuItem->Text = L"開く(&O)";
			this->OpenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::OpenToolStripMenuItem_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(147, 6);
			// 
			// RecentBookToolStripMenuItem
			// 
			this->RecentBookToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->Recent1toolStripMenuItem,
					this->Recent2toolStripMenuItem5, this->Recent3toolStripMenuItem6, this->Recent4toolStripMenuItem7, this->Recent5toolStripMenuItem8
			});
			this->RecentBookToolStripMenuItem->Enabled = false;
			this->RecentBookToolStripMenuItem->Name = L"RecentBookToolStripMenuItem";
			this->RecentBookToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->RecentBookToolStripMenuItem->Text = L"最近のBook";
			// 
			// Recent1toolStripMenuItem
			// 
			this->Recent1toolStripMenuItem->Name = L"Recent1toolStripMenuItem";
			this->Recent1toolStripMenuItem->ShowShortcutKeys = false;
			this->Recent1toolStripMenuItem->Size = System::Drawing::Size(80, 22);
			this->Recent1toolStripMenuItem->Text = L"1";
			this->Recent1toolStripMenuItem->Visible = false;
			this->Recent1toolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::RecenttoolStripMenuItem_Click);
			// 
			// Recent2toolStripMenuItem5
			// 
			this->Recent2toolStripMenuItem5->Name = L"Recent2toolStripMenuItem5";
			this->Recent2toolStripMenuItem5->Size = System::Drawing::Size(80, 22);
			this->Recent2toolStripMenuItem5->Text = L"2";
			this->Recent2toolStripMenuItem5->Visible = false;
			this->Recent2toolStripMenuItem5->Click += gcnew System::EventHandler(this, &MainForm::RecenttoolStripMenuItem_Click);
			// 
			// Recent3toolStripMenuItem6
			// 
			this->Recent3toolStripMenuItem6->Name = L"Recent3toolStripMenuItem6";
			this->Recent3toolStripMenuItem6->Size = System::Drawing::Size(80, 22);
			this->Recent3toolStripMenuItem6->Text = L"3";
			this->Recent3toolStripMenuItem6->Visible = false;
			this->Recent3toolStripMenuItem6->Click += gcnew System::EventHandler(this, &MainForm::RecenttoolStripMenuItem_Click);
			// 
			// Recent4toolStripMenuItem7
			// 
			this->Recent4toolStripMenuItem7->Name = L"Recent4toolStripMenuItem7";
			this->Recent4toolStripMenuItem7->Size = System::Drawing::Size(80, 22);
			this->Recent4toolStripMenuItem7->Text = L"4";
			this->Recent4toolStripMenuItem7->Visible = false;
			this->Recent4toolStripMenuItem7->Click += gcnew System::EventHandler(this, &MainForm::RecenttoolStripMenuItem_Click);
			// 
			// Recent5toolStripMenuItem8
			// 
			this->Recent5toolStripMenuItem8->Name = L"Recent5toolStripMenuItem8";
			this->Recent5toolStripMenuItem8->Size = System::Drawing::Size(80, 22);
			this->Recent5toolStripMenuItem8->Text = L"5";
			this->Recent5toolStripMenuItem8->Visible = false;
			this->Recent5toolStripMenuItem8->Click += gcnew System::EventHandler(this, &MainForm::RecenttoolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(147, 6);
			// 
			// ExitToolStripMenuItem
			// 
			this->ExitToolStripMenuItem->Name = L"ExitToolStripMenuItem";
			this->ExitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::X));
			this->ExitToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->ExitToolStripMenuItem->Text = L"終了(&X)";
			this->ExitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ExitToolStripMenuItem_Click);
			// 
			// DisplayStripMenuItem3
			// 
			this->DisplayStripMenuItem3->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->SettingToolStripMenuItem,
					this->toolStripMenuItem3, this->ApplicationInfoToolStripMenuItem
			});
			this->DisplayStripMenuItem3->Name = L"DisplayStripMenuItem3";
			this->DisplayStripMenuItem3->Size = System::Drawing::Size(58, 20);
			this->DisplayStripMenuItem3->Text = L"表示(&V)";
			// 
			// SettingToolStripMenuItem
			// 
			this->SettingToolStripMenuItem->Name = L"SettingToolStripMenuItem";
			this->SettingToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->SettingToolStripMenuItem->Text = L"設定(&S)";
			this->SettingToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::SettingToolStripMenuItem_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(164, 6);
			// 
			// ApplicationInfoToolStripMenuItem
			// 
			this->ApplicationInfoToolStripMenuItem->Name = L"ApplicationInfoToolStripMenuItem";
			this->ApplicationInfoToolStripMenuItem->Size = System::Drawing::Size(167, 22);
			this->ApplicationInfoToolStripMenuItem->Text = L"アプリケーション情報";
			this->ApplicationInfoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ApplicationInfoToolStripMenuItem_Click);
			// 
			// month_label
			// 
			this->month_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->month_label->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
			this->month_label->ForeColor = System::Drawing::Color::White;
			this->month_label->Location = System::Drawing::Point(248, 44);
			this->month_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->month_label->Name = L"month_label";
			this->month_label->Size = System::Drawing::Size(129, 26);
			this->month_label->TabIndex = 4;
			this->month_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// next_button
			// 
			this->next_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->next_button->BackColor = System::Drawing::Color::DarkGreen;
			this->next_button->Enabled = false;
			this->next_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->next_button->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->next_button->ForeColor = System::Drawing::Color::White;
			this->next_button->Location = System::Drawing::Point(382, 49);
			this->next_button->Margin = System::Windows::Forms::Padding(2);
			this->next_button->Name = L"next_button";
			this->next_button->Size = System::Drawing::Size(28, 18);
			this->next_button->TabIndex = 5;
			this->next_button->Text = L">";
			this->next_button->UseVisualStyleBackColor = false;
			this->next_button->Click += gcnew System::EventHandler(this, &MainForm::next_button_Click);
			// 
			// previous_button
			// 
			this->previous_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->previous_button->BackColor = System::Drawing::Color::DarkGreen;
			this->previous_button->Enabled = false;
			this->previous_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->previous_button->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->previous_button->ForeColor = System::Drawing::Color::White;
			this->previous_button->Location = System::Drawing::Point(215, 49);
			this->previous_button->Margin = System::Windows::Forms::Padding(2);
			this->previous_button->Name = L"previous_button";
			this->previous_button->Size = System::Drawing::Size(28, 18);
			this->previous_button->TabIndex = 6;
			this->previous_button->Text = L"<";
			this->previous_button->UseVisualStyleBackColor = false;
			this->previous_button->Click += gcnew System::EventHandler(this, &MainForm::previous_button_Click);
			// 
			// bookname_label
			// 
			this->bookname_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->bookname_label->BackColor = System::Drawing::Color::ForestGreen;
			this->bookname_label->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
			this->bookname_label->ForeColor = System::Drawing::Color::White;
			this->bookname_label->Location = System::Drawing::Point(0, 22);
			this->bookname_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->bookname_label->Name = L"bookname_label";
			this->bookname_label->Size = System::Drawing::Size(624, 24);
			this->bookname_label->TabIndex = 7;
			this->bookname_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// spending_category_tab
			// 
			this->spending_category_tab->BackColor = System::Drawing::Color::White;
			this->spending_category_tab->Controls->Add(this->splitContainer2);
			this->spending_category_tab->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->spending_category_tab->Location = System::Drawing::Point(4, 29);
			this->spending_category_tab->Margin = System::Windows::Forms::Padding(2);
			this->spending_category_tab->Name = L"spending_category_tab";
			this->spending_category_tab->Padding = System::Windows::Forms::Padding(2);
			this->spending_category_tab->Size = System::Drawing::Size(616, 338);
			this->spending_category_tab->TabIndex = 2;
			this->spending_category_tab->Text = L"カテゴリ別支出";
			this->spending_category_tab->Resize += gcnew System::EventHandler(this, &MainForm::_resize_fontsize);
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->IsSplitterFixed = true;
			this->splitContainer2->Location = System::Drawing::Point(2, 2);
			this->splitContainer2->Margin = System::Windows::Forms::Padding(2);
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->panel3);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->panel4);
			this->splitContainer2->Size = System::Drawing::Size(612, 309);
			this->splitContainer2->SplitterDistance = 306;
			this->splitContainer2->SplitterWidth = 3;
			this->splitContainer2->TabIndex = 5;
			// 
			// panel3
			// 
			this->panel3->AutoScroll = true;
			this->panel3->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel3->Controls->Add(this->monthly_category_spending);
			this->panel3->Controls->Add(this->monthly_category_spending_label);
			this->panel3->Controls->Add(this->monthly_category_spending_chart);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(306, 309);
			this->panel3->TabIndex = 8;
			// 
			// monthly_category_spending
			// 
			this->monthly_category_spending->AutoSize = true;
			this->monthly_category_spending->BackColor = System::Drawing::Color::Transparent;
			this->monthly_category_spending->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->monthly_category_spending->Location = System::Drawing::Point(0, 285);
			this->monthly_category_spending->Margin = System::Windows::Forms::Padding(4);
			this->monthly_category_spending->Name = L"monthly_category_spending";
			this->monthly_category_spending->Padding = System::Windows::Forms::Padding(4);
			this->monthly_category_spending->Size = System::Drawing::Size(55, 24);
			this->monthly_category_spending->TabIndex = 3;
			this->monthly_category_spending->Text = L"支出：";
			// 
			// monthly_category_spending_label
			// 
			this->monthly_category_spending_label->AutoSize = true;
			this->monthly_category_spending_label->BackColor = System::Drawing::Color::Transparent;
			this->monthly_category_spending_label->Dock = System::Windows::Forms::DockStyle::Top;
			this->monthly_category_spending_label->Location = System::Drawing::Point(0, 0);
			this->monthly_category_spending_label->Margin = System::Windows::Forms::Padding(4);
			this->monthly_category_spending_label->Name = L"monthly_category_spending_label";
			this->monthly_category_spending_label->Padding = System::Windows::Forms::Padding(4);
			this->monthly_category_spending_label->Size = System::Drawing::Size(148, 24);
			this->monthly_category_spending_label->TabIndex = 0;
			this->monthly_category_spending_label->Text = L"M月のカテゴリ別支出";
			// 
			// monthly_category_spending_chart
			// 
			chartArea1->Name = L"ChartArea1";
			this->monthly_category_spending_chart->ChartAreas->Add(chartArea1);
			this->monthly_category_spending_chart->Dock = System::Windows::Forms::DockStyle::Fill;
			this->monthly_category_spending_chart->Location = System::Drawing::Point(0, 0);
			this->monthly_category_spending_chart->Margin = System::Windows::Forms::Padding(4);
			this->monthly_category_spending_chart->Name = L"monthly_category_spending_chart";
			this->monthly_category_spending_chart->Padding = System::Windows::Forms::Padding(4);
			this->monthly_category_spending_chart->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Berry;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Doughnut;
			series1->CustomProperties = L"PieStartAngle=270";
			series1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			series1->Label = L"#LEGENDTEXT\\n#VAL{C}";
			series1->Name = L"monthly_category_graph";
			series1->YValuesPerPoint = 4;
			this->monthly_category_spending_chart->Series->Add(series1);
			this->monthly_category_spending_chart->Size = System::Drawing::Size(306, 309);
			this->monthly_category_spending_chart->TabIndex = 1;
			this->monthly_category_spending_chart->Text = L"chart1";
			// 
			// panel4
			// 
			this->panel4->AutoScroll = true;
			this->panel4->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel4->Controls->Add(this->yearly_category_spending);
			this->panel4->Controls->Add(this->yearly_category_spending_label);
			this->panel4->Controls->Add(this->yearly_category_spending_chart);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
			this->panel4->Location = System::Drawing::Point(0, 0);
			this->panel4->Margin = System::Windows::Forms::Padding(2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(303, 309);
			this->panel4->TabIndex = 9;
			// 
			// yearly_category_spending
			// 
			this->yearly_category_spending->AutoSize = true;
			this->yearly_category_spending->BackColor = System::Drawing::Color::Transparent;
			this->yearly_category_spending->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->yearly_category_spending->Location = System::Drawing::Point(0, 285);
			this->yearly_category_spending->Margin = System::Windows::Forms::Padding(4);
			this->yearly_category_spending->Name = L"yearly_category_spending";
			this->yearly_category_spending->Padding = System::Windows::Forms::Padding(4);
			this->yearly_category_spending->Size = System::Drawing::Size(55, 24);
			this->yearly_category_spending->TabIndex = 3;
			this->yearly_category_spending->Text = L"支出：";
			// 
			// yearly_category_spending_label
			// 
			this->yearly_category_spending_label->AutoSize = true;
			this->yearly_category_spending_label->BackColor = System::Drawing::Color::Transparent;
			this->yearly_category_spending_label->Dock = System::Windows::Forms::DockStyle::Top;
			this->yearly_category_spending_label->Location = System::Drawing::Point(0, 0);
			this->yearly_category_spending_label->Margin = System::Windows::Forms::Padding(4);
			this->yearly_category_spending_label->Name = L"yearly_category_spending_label";
			this->yearly_category_spending_label->Padding = System::Windows::Forms::Padding(4);
			this->yearly_category_spending_label->Size = System::Drawing::Size(168, 24);
			this->yearly_category_spending_label->TabIndex = 0;
			this->yearly_category_spending_label->Text = L"yyyy年のカテゴリ別支出";
			// 
			// yearly_category_spending_chart
			// 
			chartArea2->Name = L"ChartArea1";
			this->yearly_category_spending_chart->ChartAreas->Add(chartArea2);
			this->yearly_category_spending_chart->Dock = System::Windows::Forms::DockStyle::Fill;
			this->yearly_category_spending_chart->Location = System::Drawing::Point(0, 0);
			this->yearly_category_spending_chart->Margin = System::Windows::Forms::Padding(4);
			this->yearly_category_spending_chart->Name = L"yearly_category_spending_chart";
			this->yearly_category_spending_chart->Padding = System::Windows::Forms::Padding(4);
			this->yearly_category_spending_chart->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Berry;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Doughnut;
			series2->CustomProperties = L"PieStartAngle=270";
			series2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			series2->Label = L"#LEGENDTEXT\\n#VAL{C}";
			series2->Name = L"monthly_balance_graph";
			series2->YValuesPerPoint = 4;
			this->yearly_category_spending_chart->Series->Add(series2);
			this->yearly_category_spending_chart->Size = System::Drawing::Size(303, 309);
			this->yearly_category_spending_chart->TabIndex = 1;
			this->yearly_category_spending_chart->Text = L"chart1";
			// 
			// balance_ym_tab
			// 
			this->balance_ym_tab->BackColor = System::Drawing::Color::White;
			this->balance_ym_tab->Controls->Add(this->splitContainer1);
			this->balance_ym_tab->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->balance_ym_tab->Location = System::Drawing::Point(4, 29);
			this->balance_ym_tab->Margin = System::Windows::Forms::Padding(2);
			this->balance_ym_tab->Name = L"balance_ym_tab";
			this->balance_ym_tab->Padding = System::Windows::Forms::Padding(2);
			this->balance_ym_tab->Size = System::Drawing::Size(616, 338);
			this->balance_ym_tab->TabIndex = 1;
			this->balance_ym_tab->Text = L"年月別収支";
			this->balance_ym_tab->Resize += gcnew System::EventHandler(this, &MainForm::_resize_fontsize);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->IsSplitterFixed = true;
			this->splitContainer1->Location = System::Drawing::Point(2, 2);
			this->splitContainer1->Margin = System::Windows::Forms::Padding(2);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->panel1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->panel2);
			this->splitContainer1->Size = System::Drawing::Size(612, 309);
			this->splitContainer1->SplitterDistance = 306;
			this->splitContainer1->SplitterWidth = 3;
			this->splitContainer1->TabIndex = 5;
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->Controls->Add(this->flowLayoutPanel1);
			this->panel1->Controls->Add(this->monthly_label);
			this->panel1->Controls->Add(this->monthly_balance_chart);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(306, 309);
			this->panel1->TabIndex = 8;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoSize = true;
			this->flowLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::Transparent;
			this->flowLayoutPanel1->Controls->Add(this->monthly_income);
			this->flowLayoutPanel1->Controls->Add(this->monthly_spending);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 269);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Padding = System::Windows::Forms::Padding(4);
			this->flowLayoutPanel1->Size = System::Drawing::Size(306, 40);
			this->flowLayoutPanel1->TabIndex = 4;
			// 
			// monthly_income
			// 
			this->monthly_income->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->monthly_income->AutoSize = true;
			this->monthly_income->Location = System::Drawing::Point(8, 8);
			this->monthly_income->Margin = System::Windows::Forms::Padding(4);
			this->monthly_income->Name = L"monthly_income";
			this->monthly_income->Padding = System::Windows::Forms::Padding(4);
			this->monthly_income->Size = System::Drawing::Size(55, 24);
			this->monthly_income->TabIndex = 2;
			this->monthly_income->Text = L"収入：";
			// 
			// monthly_spending
			// 
			this->monthly_spending->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->monthly_spending->AutoSize = true;
			this->monthly_spending->Location = System::Drawing::Point(71, 8);
			this->monthly_spending->Margin = System::Windows::Forms::Padding(4);
			this->monthly_spending->Name = L"monthly_spending";
			this->monthly_spending->Padding = System::Windows::Forms::Padding(4);
			this->monthly_spending->Size = System::Drawing::Size(55, 24);
			this->monthly_spending->TabIndex = 3;
			this->monthly_spending->Text = L"支出：";
			// 
			// monthly_label
			// 
			this->monthly_label->AutoSize = true;
			this->monthly_label->BackColor = System::Drawing::Color::Transparent;
			this->monthly_label->Location = System::Drawing::Point(-3, 0);
			this->monthly_label->Margin = System::Windows::Forms::Padding(4);
			this->monthly_label->Name = L"monthly_label";
			this->monthly_label->Padding = System::Windows::Forms::Padding(4);
			this->monthly_label->Size = System::Drawing::Size(88, 24);
			this->monthly_label->TabIndex = 0;
			this->monthly_label->Text = L"M月の収支";
			// 
			// monthly_balance_chart
			// 
			chartArea3->Name = L"ChartArea1";
			this->monthly_balance_chart->ChartAreas->Add(chartArea3);
			this->monthly_balance_chart->Dock = System::Windows::Forms::DockStyle::Fill;
			this->monthly_balance_chart->Location = System::Drawing::Point(0, 0);
			this->monthly_balance_chart->Margin = System::Windows::Forms::Padding(4);
			this->monthly_balance_chart->Name = L"monthly_balance_chart";
			this->monthly_balance_chart->Padding = System::Windows::Forms::Padding(4);
			this->monthly_balance_chart->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::None;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Doughnut;
			series3->CustomProperties = L"PieStartAngle=270";
			series3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			series3->Label = L"#LEGENDTEXT\\n#VAL{C}";
			series3->Name = L"monthly_balance_graph";
			series3->YValuesPerPoint = 4;
			this->monthly_balance_chart->Series->Add(series3);
			this->monthly_balance_chart->Size = System::Drawing::Size(306, 309);
			this->monthly_balance_chart->TabIndex = 1;
			this->monthly_balance_chart->Text = L"chart1";
			this->monthly_balance_chart->Resize += gcnew System::EventHandler(this, &MainForm::_resize_fontsize);
			// 
			// panel2
			// 
			this->panel2->AutoScroll = true;
			this->panel2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel2->Controls->Add(this->flowLayoutPanel2);
			this->panel2->Controls->Add(this->yearly_label);
			this->panel2->Controls->Add(this->yearly_balance_chart);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(303, 309);
			this->panel2->TabIndex = 9;
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->AutoSize = true;
			this->flowLayoutPanel2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->flowLayoutPanel2->BackColor = System::Drawing::Color::Transparent;
			this->flowLayoutPanel2->Controls->Add(this->yearly_income);
			this->flowLayoutPanel2->Controls->Add(this->yearly_spending);
			this->flowLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->flowLayoutPanel2->Location = System::Drawing::Point(0, 269);
			this->flowLayoutPanel2->Margin = System::Windows::Forms::Padding(4);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Padding = System::Windows::Forms::Padding(4);
			this->flowLayoutPanel2->Size = System::Drawing::Size(303, 40);
			this->flowLayoutPanel2->TabIndex = 4;
			// 
			// yearly_income
			// 
			this->yearly_income->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->yearly_income->AutoSize = true;
			this->yearly_income->Location = System::Drawing::Point(8, 8);
			this->yearly_income->Margin = System::Windows::Forms::Padding(4);
			this->yearly_income->Name = L"yearly_income";
			this->yearly_income->Padding = System::Windows::Forms::Padding(4);
			this->yearly_income->Size = System::Drawing::Size(55, 24);
			this->yearly_income->TabIndex = 2;
			this->yearly_income->Text = L"収入：";
			// 
			// yearly_spending
			// 
			this->yearly_spending->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->yearly_spending->AutoSize = true;
			this->yearly_spending->Location = System::Drawing::Point(71, 8);
			this->yearly_spending->Margin = System::Windows::Forms::Padding(4);
			this->yearly_spending->Name = L"yearly_spending";
			this->yearly_spending->Padding = System::Windows::Forms::Padding(4);
			this->yearly_spending->Size = System::Drawing::Size(55, 24);
			this->yearly_spending->TabIndex = 3;
			this->yearly_spending->Text = L"支出：";
			// 
			// yearly_label
			// 
			this->yearly_label->AutoSize = true;
			this->yearly_label->BackColor = System::Drawing::Color::Transparent;
			this->yearly_label->Location = System::Drawing::Point(0, 0);
			this->yearly_label->Margin = System::Windows::Forms::Padding(4);
			this->yearly_label->Name = L"yearly_label";
			this->yearly_label->Padding = System::Windows::Forms::Padding(4);
			this->yearly_label->Size = System::Drawing::Size(108, 24);
			this->yearly_label->TabIndex = 0;
			this->yearly_label->Text = L"yyyy年の収支";
			// 
			// yearly_balance_chart
			// 
			chartArea4->Name = L"ChartArea1";
			this->yearly_balance_chart->ChartAreas->Add(chartArea4);
			this->yearly_balance_chart->Dock = System::Windows::Forms::DockStyle::Fill;
			this->yearly_balance_chart->Location = System::Drawing::Point(0, 0);
			this->yearly_balance_chart->Margin = System::Windows::Forms::Padding(4);
			this->yearly_balance_chart->Name = L"yearly_balance_chart";
			this->yearly_balance_chart->Padding = System::Windows::Forms::Padding(4);
			this->yearly_balance_chart->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::None;
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Doughnut;
			series4->CustomProperties = L"PieStartAngle=270";
			series4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			series4->Label = L"#LEGENDTEXT\\n#VAL{C}";
			series4->Name = L"monthly_balance_graph";
			series4->YValuesPerPoint = 4;
			this->yearly_balance_chart->Series->Add(series4);
			this->yearly_balance_chart->Size = System::Drawing::Size(303, 309);
			this->yearly_balance_chart->TabIndex = 1;
			this->yearly_balance_chart->Text = L"chart1";
			// 
			// main_tab
			// 
			this->main_tab->BackColor = System::Drawing::Color::DarkGreen;
			this->main_tab->Controls->Add(this->delete_data_button);
			this->main_tab->Controls->Add(this->add_data_button);
			this->main_tab->Controls->Add(this->history_grid);
			this->main_tab->ForeColor = System::Drawing::SystemColors::ControlText;
			this->main_tab->Location = System::Drawing::Point(4, 29);
			this->main_tab->Margin = System::Windows::Forms::Padding(2);
			this->main_tab->Name = L"main_tab";
			this->main_tab->Padding = System::Windows::Forms::Padding(2);
			this->main_tab->Size = System::Drawing::Size(616, 338);
			this->main_tab->TabIndex = 0;
			this->main_tab->Text = L"一覧";
			// 
			// delete_data_button
			// 
			this->delete_data_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->delete_data_button->BackColor = System::Drawing::Color::DarkGreen;
			this->delete_data_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->delete_data_button->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->delete_data_button->ForeColor = System::Drawing::Color::White;
			this->delete_data_button->Location = System::Drawing::Point(479, 294);
			this->delete_data_button->Margin = System::Windows::Forms::Padding(2);
			this->delete_data_button->Name = L"delete_data_button";
			this->delete_data_button->Size = System::Drawing::Size(60, 36);
			this->delete_data_button->TabIndex = 3;
			this->delete_data_button->Text = L"削除";
			this->delete_data_button->UseVisualStyleBackColor = false;
			this->delete_data_button->Click += gcnew System::EventHandler(this, &MainForm::delete_data_button_Click);
			// 
			// add_data_button
			// 
			this->add_data_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->add_data_button->BackColor = System::Drawing::Color::DarkGreen;
			this->add_data_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->add_data_button->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->add_data_button->ForeColor = System::Drawing::Color::White;
			this->add_data_button->Location = System::Drawing::Point(549, 294);
			this->add_data_button->Margin = System::Windows::Forms::Padding(2);
			this->add_data_button->Name = L"add_data_button";
			this->add_data_button->Size = System::Drawing::Size(60, 36);
			this->add_data_button->TabIndex = 2;
			this->add_data_button->Text = L"追加";
			this->add_data_button->UseVisualStyleBackColor = false;
			this->add_data_button->Click += gcnew System::EventHandler(this, &MainForm::add_data_button_Click);
			// 
			// history_grid
			// 
			this->history_grid->AllowUserToAddRows = false;
			this->history_grid->AllowUserToDeleteRows = false;
			this->history_grid->AllowUserToResizeColumns = false;
			this->history_grid->AllowUserToResizeRows = false;
			this->history_grid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->history_grid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::ColumnHeader;
			this->history_grid->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->history_grid->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			this->history_grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->history_grid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->date_text,
					this->category, this->memo, this->payment_method, this->amount_of_money
			});
			this->history_grid->Location = System::Drawing::Point(0, 0);
			this->history_grid->Margin = System::Windows::Forms::Padding(2);
			this->history_grid->Name = L"history_grid";
			this->history_grid->ReadOnly = true;
			this->history_grid->RowHeadersWidth = 50;
			this->history_grid->RowTemplate->Height = 24;
			this->history_grid->Size = System::Drawing::Size(618, 290);
			this->history_grid->TabIndex = 1;
			this->history_grid->SortCompare += gcnew System::Windows::Forms::DataGridViewSortCompareEventHandler(this, &MainForm::history_grid_SortCompare);
			// 
			// date_text
			// 
			this->date_text->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->date_text->HeaderText = L"日付";
			this->date_text->MinimumWidth = 6;
			this->date_text->Name = L"date_text";
			this->date_text->ReadOnly = true;
			this->date_text->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->date_text->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->date_text->Width = 43;
			// 
			// category
			// 
			this->category->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->category->FillWeight = 30;
			this->category->HeaderText = L"カテゴリ";
			this->category->MinimumWidth = 6;
			this->category->Name = L"category";
			this->category->ReadOnly = true;
			this->category->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->category->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// memo
			// 
			this->memo->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->memo->FillWeight = 70;
			this->memo->HeaderText = L"メモ";
			this->memo->MinimumWidth = 6;
			this->memo->Name = L"memo";
			this->memo->ReadOnly = true;
			this->memo->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->memo->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// payment_method
			// 
			this->payment_method->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->payment_method->HeaderText = L"決済方法";
			this->payment_method->MinimumWidth = 6;
			this->payment_method->Name = L"payment_method";
			this->payment_method->ReadOnly = true;
			this->payment_method->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->payment_method->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->payment_method->Width = 73;
			// 
			// amount_of_money
			// 
			this->amount_of_money->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleRight;
			dataGridViewCellStyle1->Format = L"C0";
			dataGridViewCellStyle1->NullValue = nullptr;
			this->amount_of_money->DefaultCellStyle = dataGridViewCellStyle1;
			this->amount_of_money->HeaderText = L"金額";
			this->amount_of_money->MinimumWidth = 6;
			this->amount_of_money->Name = L"amount_of_money";
			this->amount_of_money->ReadOnly = true;
			this->amount_of_money->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->amount_of_money->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->amount_of_money->Width = 43;
			// 
			// tabs
			// 
			this->tabs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabs->Controls->Add(this->main_tab);
			this->tabs->Controls->Add(this->balance_ym_tab);
			this->tabs->Controls->Add(this->spending_category_tab);
			this->tabs->Controls->Add(this->income_category_tab);
			this->tabs->Controls->Add(this->budget_tab);
			this->tabs->DrawMode = System::Windows::Forms::TabDrawMode::OwnerDrawFixed;
			this->tabs->Enabled = false;
			this->tabs->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11));
			this->tabs->ItemSize = System::Drawing::Size(150, 25);
			this->tabs->Location = System::Drawing::Point(0, 71);
			this->tabs->Margin = System::Windows::Forms::Padding(2);
			this->tabs->Name = L"tabs";
			this->tabs->SelectedIndex = 0;
			this->tabs->Size = System::Drawing::Size(624, 371);
			this->tabs->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
			this->tabs->TabIndex = 2;
			this->tabs->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &MainForm::tabs_DrawItem);
			this->tabs->VisibleChanged += gcnew System::EventHandler(this, &MainForm::tabs_VisibleChanged);
			this->tabs->Resize += gcnew System::EventHandler(this, &MainForm::tabs_Resize);
			// 
			// income_category_tab
			// 
			this->income_category_tab->BackColor = System::Drawing::Color::White;
			this->income_category_tab->Controls->Add(this->splitContainer3);
			this->income_category_tab->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->income_category_tab->Location = System::Drawing::Point(4, 29);
			this->income_category_tab->Margin = System::Windows::Forms::Padding(2);
			this->income_category_tab->Name = L"income_category_tab";
			this->income_category_tab->Padding = System::Windows::Forms::Padding(2);
			this->income_category_tab->Size = System::Drawing::Size(616, 338);
			this->income_category_tab->TabIndex = 3;
			this->income_category_tab->Text = L"カテゴリ別収入";
			this->income_category_tab->Resize += gcnew System::EventHandler(this, &MainForm::_resize_fontsize);
			// 
			// splitContainer3
			// 
			this->splitContainer3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer3->IsSplitterFixed = true;
			this->splitContainer3->Location = System::Drawing::Point(2, 2);
			this->splitContainer3->Margin = System::Windows::Forms::Padding(2);
			this->splitContainer3->Name = L"splitContainer3";
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->Controls->Add(this->panel5);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->Controls->Add(this->panel6);
			this->splitContainer3->Size = System::Drawing::Size(612, 309);
			this->splitContainer3->SplitterDistance = 306;
			this->splitContainer3->SplitterWidth = 3;
			this->splitContainer3->TabIndex = 5;
			// 
			// panel5
			// 
			this->panel5->AutoScroll = true;
			this->panel5->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel5->Controls->Add(this->monthly_category_income);
			this->panel5->Controls->Add(this->monthly_category_income_label);
			this->panel5->Controls->Add(this->monthly_category_income_chart);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel5->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
			this->panel5->Location = System::Drawing::Point(0, 0);
			this->panel5->Margin = System::Windows::Forms::Padding(2);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(306, 309);
			this->panel5->TabIndex = 8;
			// 
			// monthly_category_income
			// 
			this->monthly_category_income->AutoSize = true;
			this->monthly_category_income->BackColor = System::Drawing::Color::Transparent;
			this->monthly_category_income->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->monthly_category_income->Location = System::Drawing::Point(0, 285);
			this->monthly_category_income->Margin = System::Windows::Forms::Padding(4);
			this->monthly_category_income->Name = L"monthly_category_income";
			this->monthly_category_income->Padding = System::Windows::Forms::Padding(4);
			this->monthly_category_income->Size = System::Drawing::Size(55, 24);
			this->monthly_category_income->TabIndex = 3;
			this->monthly_category_income->Text = L"収入：";
			// 
			// monthly_category_income_label
			// 
			this->monthly_category_income_label->AutoSize = true;
			this->monthly_category_income_label->BackColor = System::Drawing::Color::Transparent;
			this->monthly_category_income_label->Dock = System::Windows::Forms::DockStyle::Top;
			this->monthly_category_income_label->Location = System::Drawing::Point(0, 0);
			this->monthly_category_income_label->Margin = System::Windows::Forms::Padding(4);
			this->monthly_category_income_label->Name = L"monthly_category_income_label";
			this->monthly_category_income_label->Padding = System::Windows::Forms::Padding(4);
			this->monthly_category_income_label->Size = System::Drawing::Size(148, 24);
			this->monthly_category_income_label->TabIndex = 0;
			this->monthly_category_income_label->Text = L"M月のカテゴリ別収入";
			// 
			// monthly_category_income_chart
			// 
			chartArea5->Name = L"ChartArea1";
			this->monthly_category_income_chart->ChartAreas->Add(chartArea5);
			this->monthly_category_income_chart->Dock = System::Windows::Forms::DockStyle::Fill;
			this->monthly_category_income_chart->Location = System::Drawing::Point(0, 0);
			this->monthly_category_income_chart->Margin = System::Windows::Forms::Padding(4);
			this->monthly_category_income_chart->Name = L"monthly_category_income_chart";
			this->monthly_category_income_chart->Padding = System::Windows::Forms::Padding(4);
			this->monthly_category_income_chart->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::SeaGreen;
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Doughnut;
			series5->CustomProperties = L"PieStartAngle=270";
			series5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			series5->Label = L"#LEGENDTEXT\\n#VAL{C}";
			series5->Name = L"monthly_category_graph";
			series5->YValuesPerPoint = 4;
			this->monthly_category_income_chart->Series->Add(series5);
			this->monthly_category_income_chart->Size = System::Drawing::Size(306, 309);
			this->monthly_category_income_chart->TabIndex = 1;
			this->monthly_category_income_chart->Text = L"chart1";
			// 
			// panel6
			// 
			this->panel6->AutoScroll = true;
			this->panel6->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel6->Controls->Add(this->yearly_category_income);
			this->panel6->Controls->Add(this->yearly_category_income_label);
			this->panel6->Controls->Add(this->yearly_category_income_chart);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel6->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
			this->panel6->Location = System::Drawing::Point(0, 0);
			this->panel6->Margin = System::Windows::Forms::Padding(2);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(303, 309);
			this->panel6->TabIndex = 9;
			// 
			// yearly_category_income
			// 
			this->yearly_category_income->AutoSize = true;
			this->yearly_category_income->BackColor = System::Drawing::Color::Transparent;
			this->yearly_category_income->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->yearly_category_income->Location = System::Drawing::Point(0, 285);
			this->yearly_category_income->Margin = System::Windows::Forms::Padding(4);
			this->yearly_category_income->Name = L"yearly_category_income";
			this->yearly_category_income->Padding = System::Windows::Forms::Padding(4);
			this->yearly_category_income->Size = System::Drawing::Size(55, 24);
			this->yearly_category_income->TabIndex = 3;
			this->yearly_category_income->Text = L"収入：";
			// 
			// yearly_category_income_label
			// 
			this->yearly_category_income_label->AutoSize = true;
			this->yearly_category_income_label->BackColor = System::Drawing::Color::Transparent;
			this->yearly_category_income_label->Dock = System::Windows::Forms::DockStyle::Top;
			this->yearly_category_income_label->Location = System::Drawing::Point(0, 0);
			this->yearly_category_income_label->Margin = System::Windows::Forms::Padding(4);
			this->yearly_category_income_label->Name = L"yearly_category_income_label";
			this->yearly_category_income_label->Padding = System::Windows::Forms::Padding(4);
			this->yearly_category_income_label->Size = System::Drawing::Size(168, 24);
			this->yearly_category_income_label->TabIndex = 0;
			this->yearly_category_income_label->Text = L"yyyy年のカテゴリ別収入";
			// 
			// yearly_category_income_chart
			// 
			chartArea6->Name = L"ChartArea1";
			this->yearly_category_income_chart->ChartAreas->Add(chartArea6);
			this->yearly_category_income_chart->Dock = System::Windows::Forms::DockStyle::Fill;
			this->yearly_category_income_chart->Location = System::Drawing::Point(0, 0);
			this->yearly_category_income_chart->Margin = System::Windows::Forms::Padding(4);
			this->yearly_category_income_chart->Name = L"yearly_category_income_chart";
			this->yearly_category_income_chart->Padding = System::Windows::Forms::Padding(4);
			this->yearly_category_income_chart->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::SeaGreen;
			series6->ChartArea = L"ChartArea1";
			series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Doughnut;
			series6->CustomProperties = L"PieStartAngle=270";
			series6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			series6->Label = L"#LEGENDTEXT\\n#VAL{C}";
			series6->Name = L"monthly_balance_graph";
			series6->YValuesPerPoint = 4;
			this->yearly_category_income_chart->Series->Add(series6);
			this->yearly_category_income_chart->Size = System::Drawing::Size(303, 309);
			this->yearly_category_income_chart->TabIndex = 1;
			this->yearly_category_income_chart->Text = L"chart1";
			// 
			// budget_tab
			// 
			this->budget_tab->BackColor = System::Drawing::Color::White;
			this->budget_tab->Controls->Add(this->splitContainer4);
			this->budget_tab->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->budget_tab->Location = System::Drawing::Point(4, 29);
			this->budget_tab->Margin = System::Windows::Forms::Padding(2);
			this->budget_tab->Name = L"budget_tab";
			this->budget_tab->Padding = System::Windows::Forms::Padding(2);
			this->budget_tab->Size = System::Drawing::Size(616, 338);
			this->budget_tab->TabIndex = 4;
			this->budget_tab->Text = L"決済別予算";
			this->budget_tab->Resize += gcnew System::EventHandler(this, &MainForm::_resize_fontsize);
			// 
			// splitContainer4
			// 
			this->splitContainer4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer4->IsSplitterFixed = true;
			this->splitContainer4->Location = System::Drawing::Point(2, 2);
			this->splitContainer4->Margin = System::Windows::Forms::Padding(2);
			this->splitContainer4->Name = L"splitContainer4";
			// 
			// splitContainer4.Panel1
			// 
			this->splitContainer4->Panel1->Controls->Add(this->panel7);
			// 
			// splitContainer4.Panel2
			// 
			this->splitContainer4->Panel2->Controls->Add(this->panel8);
			this->splitContainer4->Size = System::Drawing::Size(612, 309);
			this->splitContainer4->SplitterDistance = 428;
			this->splitContainer4->SplitterWidth = 3;
			this->splitContainer4->TabIndex = 5;
			// 
			// panel7
			// 
			this->panel7->AutoScroll = true;
			this->panel7->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel7->Controls->Add(this->budget_value);
			this->panel7->Controls->Add(this->budtet_label);
			this->panel7->Controls->Add(this->budget_chart);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel7->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
			this->panel7->Location = System::Drawing::Point(0, 0);
			this->panel7->Margin = System::Windows::Forms::Padding(2);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(428, 309);
			this->panel7->TabIndex = 8;
			// 
			// budget_value
			// 
			this->budget_value->AutoSize = true;
			this->budget_value->BackColor = System::Drawing::Color::Transparent;
			this->budget_value->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->budget_value->Location = System::Drawing::Point(0, 285);
			this->budget_value->Margin = System::Windows::Forms::Padding(4);
			this->budget_value->Name = L"budget_value";
			this->budget_value->Padding = System::Windows::Forms::Padding(4);
			this->budget_value->Size = System::Drawing::Size(71, 24);
			this->budget_value->TabIndex = 3;
			this->budget_value->Text = L"総予算：";
			// 
			// budtet_label
			// 
			this->budtet_label->AutoSize = true;
			this->budtet_label->BackColor = System::Drawing::Color::Transparent;
			this->budtet_label->Dock = System::Windows::Forms::DockStyle::Top;
			this->budtet_label->Location = System::Drawing::Point(0, 0);
			this->budtet_label->Margin = System::Windows::Forms::Padding(4);
			this->budtet_label->Name = L"budtet_label";
			this->budtet_label->Padding = System::Windows::Forms::Padding(4);
			this->budtet_label->Size = System::Drawing::Size(63, 24);
			this->budtet_label->TabIndex = 0;
			this->budtet_label->Text = L"総予算";
			// 
			// budget_chart
			// 
			chartArea7->Name = L"ChartArea1";
			this->budget_chart->ChartAreas->Add(chartArea7);
			this->budget_chart->Dock = System::Windows::Forms::DockStyle::Fill;
			this->budget_chart->Location = System::Drawing::Point(0, 0);
			this->budget_chart->Margin = System::Windows::Forms::Padding(4);
			this->budget_chart->Name = L"budget_chart";
			this->budget_chart->Padding = System::Windows::Forms::Padding(4);
			this->budget_chart->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Pastel;
			series7->ChartArea = L"ChartArea1";
			series7->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Doughnut;
			series7->CustomProperties = L"PieStartAngle=270";
			series7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			series7->Label = L"#LEGENDTEXT\\n#VAL{C}";
			series7->Name = L"monthly_category_graph";
			series7->YValuesPerPoint = 4;
			this->budget_chart->Series->Add(series7);
			this->budget_chart->Size = System::Drawing::Size(428, 309);
			this->budget_chart->TabIndex = 1;
			// 
			// panel8
			// 
			this->panel8->AutoScroll = true;
			this->panel8->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel8->Controls->Add(this->flowLayoutPanel3);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel8->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
			this->panel8->Location = System::Drawing::Point(0, 0);
			this->panel8->Margin = System::Windows::Forms::Padding(2);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(181, 309);
			this->panel8->TabIndex = 9;
			// 
			// flowLayoutPanel3
			// 
			this->flowLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel3->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel3->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel3->Margin = System::Windows::Forms::Padding(2);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(181, 309);
			this->flowLayoutPanel3->TabIndex = 0;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::Color::DarkGreen;
			this->ClientSize = System::Drawing::Size(624, 441);
			this->Controls->Add(this->bookname_label);
			this->Controls->Add(this->previous_button);
			this->Controls->Add(this->next_button);
			this->Controls->Add(this->month_label);
			this->Controls->Add(this->tabs);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MinimumSize = System::Drawing::Size(499, 328);
			this->Name = L"MainForm";
			this->Text = L"WalletCheck";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->spending_category_tab->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->monthly_category_spending_chart))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yearly_category_spending_chart))->EndInit();
			this->balance_ym_tab->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->monthly_balance_chart))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yearly_balance_chart))->EndInit();
			this->main_tab->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->history_grid))->EndInit();
			this->tabs->ResumeLayout(false);
			this->income_category_tab->ResumeLayout(false);
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->EndInit();
			this->splitContainer3->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->monthly_category_income_chart))->EndInit();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->yearly_category_income_chart))->EndInit();
			this->budget_tab->ResumeLayout(false);
			this->splitContainer4->Panel1->ResumeLayout(false);
			this->splitContainer4->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer4))->EndInit();
			this->splitContainer4->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->budget_chart))->EndInit();
			this->panel8->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region ユーザー定義
	public:
		/// <summary>
		/// メッセージボックスを表示します。
		/// </summary>
		/// <param name="message">：表示するメッセージ</param>
		/// <param name="title">：メッセージボックスのタイトル</param>
		static Void Message(String^ message, String^ title);

		/// <summary>
		/// アップデートをチェックします
		/// </summary>
		/// <returns>：0 = 成功 / -1 = 失敗</returns>
		static int check_update();

	private:
		int _form_height = 500;

		String^ _opening_bookpath;
		int _opening_year;
		int _opening_month;

		/// <summary>
		/// 対象の型の呼び出し元以下の子コントロールを列挙します。
		/// </summary>
		/// <param name="sender">：呼び出し元</param>
		/// <param name="type">：型</param>
		/// <param name="list">：列挙先</param>
		Void find_control(Object^ sender, Type^ type, List<Control^>% list);

		/// <summary>
		/// グラフ領域の親子関係を設定します。
		/// </summary>
		/// <param name="sender">：呼び出し元</param>
		Void _set_parent(Object^ sender);

		/// <summary>
		/// 現在の年を取得します。
		/// </summary>
		/// <returns>現在の年（int）</returns>
		int _GetYear();

		/// <summary>
		/// 現在の月を取得します。
		/// </summary>
		/// <returns>現在の月（int）</returns>
		int _GetMonth();

		/// <summary>
		/// BookのパスからBook名を抜き出します。
		/// </summary>
		/// <param name="path">：Bookのパス</param>
		/// <returns>Book名（System::String）</returns>
		String^ _GetBookname_From_Path(String^ path);


		/// <summary>
		/// ページのパスから年、月を抜き出します。
		/// </summary>
		/// <param name="pagepath">：抜き出し対象のページのパス</param>
		/// <param name="year">：年を保存する変数</param>
		/// <param name="month">：月を保存する変数</param>
		/// <returns></returns>
		Void _GetYearMonth_From_PagePath(String^ pagepath, int% year, int% month);

		/// <summary>
		/// Bookのパス、年、月から指定のページのパスを作成します。
		/// </summary>
		/// <param name="bookpath_s">：Bookのパス</param>
		/// <param name="year">：ページの年</param>
		/// <param name="month">：ページの月</param>
		/// <returns>ページのパス</returns>
		String^ _MakePagePath(String^ bookpath_s, int year, int month);

		/// <summary>
		/// System::Stringの数値を整数型の数値にします。
		/// </summary>
		/// <param name="strnum">：System::String型の数値</param>
		/// <returns>数値（long long）</returns>
		long long _StringToInt(String^ strnum);

		/// <summary>
		/// Bookを新規作成するFormを表示し、Bookを作成します。
		/// </summary>
		Void _CreateBook();

		/// <summary>
		/// 指定パスのBookを開きます。
		/// </summary>
		/// <param name="bookpath_s">：Bookのパス</param>
		Void _OpenBook(String^ bookpath_s);

		/// <summary>
		/// Bookのページを開きます。
		/// </summary>
		/// <param name="bookpath_s">：Bookのパス</param>
		/// <param name="year">：開くページの年</param>
		/// <param name="month">：開くページの月</param>
		Void _OpenBookPage(String^ bookpath_s, int year, int month, List<List<String^>^>% return_L);

		/// <summary>
		/// Bookを保存します。
		/// </summary>
		/// <param name="bookpath_s">：Bookのパス</param>
		/// <param name="year">：保存するページの年</param>
		/// <param name="month">：保存するページの月</param>
		Void _SaveBookPage(String^ bookpath_s, int year, int month);

		/// <summary>
		/// 現在開いているbookの情報を変更します。
		/// </summary>
		/// <param name="bookpath">：bookのパス</param>
		/// <param name="year">：年</param>
		/// <param name="month">：月</param>
		Void _SetOpening(String^ bookpath, int year, int month);

		/// <summary>
		/// 指定のBookを最近使ったBookに追加します。
		/// </summary>
		/// <param name="bookpath_s">：追加するBookのパス</param>
		Void _register_recently(String^ bookpath_s);

		/// <summary>
		/// DataGridViewに値を追加します。
		/// </summary>
		/// <param name="targetform">：DataGridViewが所属するForm</param>
		/// <param name="gridname">：DataGridViewの名前</param>
		/// <param name="values">：追加する値</param>
		Void _load_grid(String^ gridname, List<List <String^>^>% values);

		/// <summary>
		/// 開いているページの情報をラベルに表示します。
		/// </summary>
		Void _diaplay_pageinfo();

		/// <summary>
		/// ToolStripMenuの”最近のBook”に最近使ったBookをConfigより取得して表示します。
		/// </summary>
		Void _show_recentbook_toolstripmenu();

		/// <summary>
		/// DonutDataのListをソートします。
		/// </summary>
		/// <param name="list">ソートするDonutDataのlistです。</param>
		Void _sort_donutdata_list(List<DonutData^>% list);

		/// <summary>
		/// ドーナツ型グラフを読み込みます。
		/// </summary>
		/// <param name="sender">：呼び出し元Object</param>
		/// <param name="chartname">：対象のChart名</param>
		/// <param name="donutdata">：読み込むDonutData</param>
		Void _load_donut_graph(Object^ sender, String^ chartname, List<DonutData^ >% donutdata);

		/// <summary>
		/// 収支のグラフを読み込みます。
		/// </summary>
		/// <param name="chartname">：対象のグラフ名</param>
		/// <param name="spending">：支出の値</param>
		/// <param name="income">：収入の値</param>
		Void _load_balance_graph(String^ chartname, long long% spending, long long% income);

		/// <summary>
		/// 月間収支を取得します。
		/// </summary>
		/// <param name="year">：年</param>
		/// <param name="month">：月</param>
		/// <param name="spending">：支出の値を入れる変数</param>
		/// <param name="income">：収入の値を入れる変数</param>
		Void _get_monthly_spending_and_income(int year, int month, long long% spending, long long% income);

		/// <summary>
		/// 月間の収支のグラフを読み込みます。
		/// </summary>
		Void _load_monthly_balance_graph();

		/// <summary>
		/// 年間の収支を取得します。
		/// </summary>
		/// <param name="year"：年></param>
		/// <param name="spending">：支出の値を入れる変数</param>
		/// <param name="income">：収入の値を入れる変数</param>
		Void _get_yearly_spending_and_income(int year, long long% spending, long long% income);

		/// <summary>
		/// 年間の収支のグラフを読み込みます。
		/// </summary>
		Void _load_yearly_balance_graph();


		/// <summary>
		/// カテゴリ別月間収支を取得します。
		/// </summary>
		/// <param name="year">：年</param>
		/// <param name="month">：月</param>
		/// <param name="data">：データ保存先</param>
		/// <param name="type">:ture=収入　false=支出</param>
		/// <returns></returns>
		Void _get_monthly_category(int year, int month, List<DonutData^>% data, bool type);

		/// <summary>
		/// カテゴリ別月間支出のグラフを読み込みます。
		/// </summary>
		Void _load_monthly_category_spending_graph();

		/// <summary>
		/// カテゴリ別年間支出を読み込みます。
		/// </summary>
		/// <param name="year">：年</param>
		/// <param name="data">：月</param>
		/// <param name="type">：ture=収入　false=支出</param>
		Void _get_yearly_category(int year, List<DonutData^>% data, bool type);

		/// <summary>
		/// カテゴリ別年間支出のグラフを読み込みます。
		/// </summary>
		Void _load_yearly_category_spending_graph();

		/// <summary>
		/// カテゴリ別月間収入のグラフを読み込みます。
		/// </summary>
		Void _load_monthly_category_income_graph();

		/// <summary>
		/// カテゴリ別年間収入のグラフを読み込みます。
		/// </summary>
		Void _load_yearly_category_income_graph();

		/// <summary>
		/// 支払別予算を取得します。
		/// </summary>
		Void _get_budget_payment(List<DonutData^>% data);

		/// <summary>
		/// 予算のグラフを読み込みます。
		/// </summary>
		Void _load_budget_graph();

		/// <summary>
		/// 支払別予算を読み込みます。
		/// </summary>
		Void _load_budget_payment();

		/// <summary>
		/// 表とグラフを読み込みます。
		/// </summary>
		Void _load_grid_and_graph();

		/// <summary>
		/// フォントサイズをフォームの高さによって調節します。
		/// </summary>
		Void _resize_fontsize(Object^ sender, EventArgs^ e);

		/// <summary>
		/// アップデートが存在するか確かめます。
		/// </summary>
		/// <returns>：0 = 成功 / -1 = 失敗</returns>
		static int _check_update();

		/// <summary>
		/// アップデーターをダウンロードします。
		/// </summary>
		/// <returns>0 = 成功 / -1 = 失敗</returns>
		static int _download_updater();

#pragma endregion
#pragma region イベントハンドラ等
	private:
		Void MainForm_Load(Object^ sender, EventArgs^ e);
		Void tabs_DrawItem(Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e);
		Void CreateNewToolStripMenuItem_Click(Object^ sender, EventArgs^ e);
		Void OpenToolStripMenuItem_Click(Object^ sender, EventArgs^ e);
		Void RecenttoolStripMenuItem_Click(Object^ sender, EventArgs^ e);
		Void ExitToolStripMenuItem_Click(Object^ sender, EventArgs^ e);
		Void ApplicationInfoToolStripMenuItem_Click(Object^ sender, EventArgs^ e);
		Void OfficialSiteToolStripMenuItem_Click(Object^ sender, EventArgs^ e);


		Void previous_button_Click(Object^ sender, EventArgs^ e);
		Void next_button_Click(Object^ sender, EventArgs^ e);
		Void add_data_button_Click(Object^ sender, EventArgs^ e);
		Void delete_data_button_Click(System::Object^ sender, System::EventArgs^ e);
		Void history_grid_SortCompare(Object^ sender, System::Windows::Forms::DataGridViewSortCompareEventArgs^ e);
#pragma endregion

		System::Void SettingToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void tabs_Resize(System::Object^ sender, System::EventArgs^ e);

		System::Void tabs_VisibleChanged(System::Object^ sender, System::EventArgs^ e);
	};
}