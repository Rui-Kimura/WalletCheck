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
		private:
			System::Windows::Forms::MenuStrip^ menuStrip1;

			System::Windows::Forms::DataGridView^ history_grid;
			System::Windows::Forms::TabControl^ tabs;
			System::Windows::Forms::TabPage^ main_page;
			System::Windows::Forms::TabPage^ balance_tab;




			System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^ CreateNewToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^ OpenToolStripMenuItem;

			System::Windows::Forms::Label^ month_label;
			System::Windows::Forms::Label^ bookname_label;
			System::Windows::Forms::Button^ next_button;
			System::Windows::Forms::Button^ previous_button;
			System::Windows::Forms::Button^ add_data_button;

			System::Windows::Forms::ToolStripSeparator^ toolStripMenuItem1;
			System::Windows::Forms::ToolStripMenuItem^ ExitToolStripMenuItem;

			System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;

			System::Windows::Forms::DataGridViewTextBoxColumn^ date_text;
			System::Windows::Forms::DataGridViewTextBoxColumn^ category;
			System::Windows::Forms::DataGridViewTextBoxColumn^ memo;
			System::Windows::Forms::DataGridViewTextBoxColumn^ payment_method;
			System::Windows::Forms::DataGridViewTextBoxColumn^ amount_of_money;
			System::Windows::Forms::ToolStripSeparator^ toolStripMenuItem2;
			System::Windows::Forms::ToolStripMenuItem^ RecentBookToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^ Recent1toolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^ Recent2toolStripMenuItem5;
			System::Windows::Forms::ToolStripMenuItem^ Recent3toolStripMenuItem6;
			System::Windows::Forms::ToolStripMenuItem^ Recent4toolStripMenuItem7;
			System::Windows::Forms::ToolStripMenuItem^ Recent5toolStripMenuItem8;
			System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ monthly_balance_chart;











			System::ComponentModel::Container^ components;
#pragma endregion
#pragma region WindowsFormDesignerによって生成されたコード
		/// <summary>DO NOT EDIT</summary>
			void InitializeComponent(void)
			{
				System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
				System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
				System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
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
				this->history_grid = (gcnew System::Windows::Forms::DataGridView());
				this->date_text = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->category = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->memo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->payment_method = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->amount_of_money = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				this->tabs = (gcnew System::Windows::Forms::TabControl());
				this->main_page = (gcnew System::Windows::Forms::TabPage());
				this->add_data_button = (gcnew System::Windows::Forms::Button());
				this->balance_tab = (gcnew System::Windows::Forms::TabPage());
				this->monthly_balance_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->month_label = (gcnew System::Windows::Forms::Label());
				this->next_button = (gcnew System::Windows::Forms::Button());
				this->previous_button = (gcnew System::Windows::Forms::Button());
				this->bookname_label = (gcnew System::Windows::Forms::Label());
				this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
				this->menuStrip1->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->history_grid))->BeginInit();
				this->tabs->SuspendLayout();
				this->main_page->SuspendLayout();
				this->balance_tab->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->monthly_balance_chart))->BeginInit();
				this->SuspendLayout();
				// 
				// menuStrip1
				// 
				this->menuStrip1->BackColor = System::Drawing::Color::DarkGreen;
				this->menuStrip1->ForeColor = System::Drawing::Color::White;
				this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
				this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
				this->menuStrip1->Location = System::Drawing::Point(0, 0);
				this->menuStrip1->Name = L"menuStrip1";
				this->menuStrip1->Padding = System::Windows::Forms::Padding(5, 2, 0, 2);
				this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
				this->menuStrip1->Size = System::Drawing::Size(780, 28);
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
				this->fileToolStripMenuItem->Size = System::Drawing::Size(82, 24);
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
				this->CreateNewToolStripMenuItem->Size = System::Drawing::Size(188, 26);
				this->CreateNewToolStripMenuItem->Text = L"新規作成(&N)";
				this->CreateNewToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::CreateNewToolStripMenuItem_Click);
				// 
				// OpenToolStripMenuItem
				// 
				this->OpenToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 9));
				this->OpenToolStripMenuItem->Name = L"OpenToolStripMenuItem";
				this->OpenToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::O));
				this->OpenToolStripMenuItem->ShowShortcutKeys = false;
				this->OpenToolStripMenuItem->Size = System::Drawing::Size(188, 26);
				this->OpenToolStripMenuItem->Text = L"開く(&O)";
				this->OpenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::OpenToolStripMenuItem_Click);
				// 
				// toolStripMenuItem2
				// 
				this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
				this->toolStripMenuItem2->Size = System::Drawing::Size(185, 6);
				// 
				// RecentBookToolStripMenuItem
				// 
				this->RecentBookToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
					this->Recent1toolStripMenuItem,
						this->Recent2toolStripMenuItem5, this->Recent3toolStripMenuItem6, this->Recent4toolStripMenuItem7, this->Recent5toolStripMenuItem8
				});
				this->RecentBookToolStripMenuItem->Enabled = false;
				this->RecentBookToolStripMenuItem->Name = L"RecentBookToolStripMenuItem";
				this->RecentBookToolStripMenuItem->Size = System::Drawing::Size(188, 26);
				this->RecentBookToolStripMenuItem->Text = L"最近のBook";
				// 
				// Recent1toolStripMenuItem
				// 
				this->Recent1toolStripMenuItem->Name = L"Recent1toolStripMenuItem";
				this->Recent1toolStripMenuItem->ShowShortcutKeys = false;
				this->Recent1toolStripMenuItem->Size = System::Drawing::Size(100, 26);
				this->Recent1toolStripMenuItem->Text = L"1";
				this->Recent1toolStripMenuItem->Visible = false;
				this->Recent1toolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::RecenttoolStripMenuItem_Click);
				// 
				// Recent2toolStripMenuItem5
				// 
				this->Recent2toolStripMenuItem5->Name = L"Recent2toolStripMenuItem5";
				this->Recent2toolStripMenuItem5->Size = System::Drawing::Size(100, 26);
				this->Recent2toolStripMenuItem5->Text = L"2";
				this->Recent2toolStripMenuItem5->Visible = false;
				this->Recent2toolStripMenuItem5->Click += gcnew System::EventHandler(this, &MainForm::RecenttoolStripMenuItem_Click);
				// 
				// Recent3toolStripMenuItem6
				// 
				this->Recent3toolStripMenuItem6->Name = L"Recent3toolStripMenuItem6";
				this->Recent3toolStripMenuItem6->Size = System::Drawing::Size(100, 26);
				this->Recent3toolStripMenuItem6->Text = L"3";
				this->Recent3toolStripMenuItem6->Visible = false;
				this->Recent3toolStripMenuItem6->Click += gcnew System::EventHandler(this, &MainForm::RecenttoolStripMenuItem_Click);
				// 
				// Recent4toolStripMenuItem7
				// 
				this->Recent4toolStripMenuItem7->Name = L"Recent4toolStripMenuItem7";
				this->Recent4toolStripMenuItem7->Size = System::Drawing::Size(100, 26);
				this->Recent4toolStripMenuItem7->Text = L"4";
				this->Recent4toolStripMenuItem7->Visible = false;
				this->Recent4toolStripMenuItem7->Click += gcnew System::EventHandler(this, &MainForm::RecenttoolStripMenuItem_Click);
				// 
				// Recent5toolStripMenuItem8
				// 
				this->Recent5toolStripMenuItem8->Name = L"Recent5toolStripMenuItem8";
				this->Recent5toolStripMenuItem8->Size = System::Drawing::Size(100, 26);
				this->Recent5toolStripMenuItem8->Text = L"5";
				this->Recent5toolStripMenuItem8->Visible = false;
				this->Recent5toolStripMenuItem8->Click += gcnew System::EventHandler(this, &MainForm::RecenttoolStripMenuItem_Click);
				// 
				// toolStripMenuItem1
				// 
				this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
				this->toolStripMenuItem1->Size = System::Drawing::Size(185, 6);
				// 
				// ExitToolStripMenuItem
				// 
				this->ExitToolStripMenuItem->Name = L"ExitToolStripMenuItem";
				this->ExitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::X));
				this->ExitToolStripMenuItem->Size = System::Drawing::Size(188, 26);
				this->ExitToolStripMenuItem->Text = L"終了(&X)";
				this->ExitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ExitToolStripMenuItem_Click);
				// 
				// history_grid
				// 
				this->history_grid->AllowUserToAddRows = false;
				this->history_grid->AllowUserToDeleteRows = false;
				this->history_grid->AllowUserToResizeRows = false;
				this->history_grid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					| System::Windows::Forms::AnchorStyles::Left)
					| System::Windows::Forms::AnchorStyles::Right));
				this->history_grid->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
				this->history_grid->ColumnHeadersHeight = 30;
				this->history_grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
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
				this->history_grid->Size = System::Drawing::Size(772, 370);
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
				this->date_text->Width = 78;
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
				// 
				// payment_method
				// 
				this->payment_method->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
				this->payment_method->HeaderText = L"決済方法";
				this->payment_method->MinimumWidth = 6;
				this->payment_method->Name = L"payment_method";
				this->payment_method->ReadOnly = true;
				this->payment_method->Resizable = System::Windows::Forms::DataGridViewTriState::False;
				this->payment_method->Width = 118;
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
				this->amount_of_money->Width = 78;
				// 
				// tabs
				// 
				this->tabs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					| System::Windows::Forms::AnchorStyles::Left)
					| System::Windows::Forms::AnchorStyles::Right));
				this->tabs->Controls->Add(this->main_page);
				this->tabs->Controls->Add(this->balance_tab);
				this->tabs->DrawMode = System::Windows::Forms::TabDrawMode::OwnerDrawFixed;
				this->tabs->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(128)));
				this->tabs->Location = System::Drawing::Point(0, 89);
				this->tabs->Margin = System::Windows::Forms::Padding(2);
				this->tabs->Name = L"tabs";
				this->tabs->SelectedIndex = 0;
				this->tabs->Size = System::Drawing::Size(780, 463);
				this->tabs->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
				this->tabs->TabIndex = 2;
				this->tabs->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &MainForm::tabs_DrawItem);
				this->tabs->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::tabs_SelectedIndexChanged);
				// 
				// main_page
				// 
				this->main_page->BackColor = System::Drawing::Color::DarkGreen;
				this->main_page->Controls->Add(this->add_data_button);
				this->main_page->Controls->Add(this->history_grid);
				this->main_page->ForeColor = System::Drawing::SystemColors::ControlText;
				this->main_page->Location = System::Drawing::Point(4, 30);
				this->main_page->Margin = System::Windows::Forms::Padding(2);
				this->main_page->Name = L"main_page";
				this->main_page->Padding = System::Windows::Forms::Padding(2);
				this->main_page->Size = System::Drawing::Size(772, 429);
				this->main_page->TabIndex = 0;
				this->main_page->Text = L"一覧";
				// 
				// add_data_button
				// 
				this->add_data_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
				this->add_data_button->BackColor = System::Drawing::Color::DarkGreen;
				this->add_data_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->add_data_button->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(128)));
				this->add_data_button->ForeColor = System::Drawing::Color::White;
				this->add_data_button->Location = System::Drawing::Point(689, 375);
				this->add_data_button->Name = L"add_data_button";
				this->add_data_button->Size = System::Drawing::Size(75, 45);
				this->add_data_button->TabIndex = 2;
				this->add_data_button->Text = L"追加";
				this->add_data_button->UseVisualStyleBackColor = false;
				this->add_data_button->Click += gcnew System::EventHandler(this, &MainForm::add_data_button_Click);
				// 
				// balance_tab
				// 
				this->balance_tab->Controls->Add(this->monthly_balance_chart);
				this->balance_tab->Controls->Add(this->label1);
				this->balance_tab->Location = System::Drawing::Point(4, 30);
				this->balance_tab->Margin = System::Windows::Forms::Padding(2);
				this->balance_tab->Name = L"balance_tab";
				this->balance_tab->Padding = System::Windows::Forms::Padding(2);
				this->balance_tab->Size = System::Drawing::Size(772, 429);
				this->balance_tab->TabIndex = 1;
				this->balance_tab->Text = L"収支";
				this->balance_tab->UseVisualStyleBackColor = true;
				// 
				// monthly_balance_chart
				// 
				chartArea1->Name = L"ChartArea1";
				this->monthly_balance_chart->ChartAreas->Add(chartArea1);
				this->monthly_balance_chart->Location = System::Drawing::Point(12, 25);
				this->monthly_balance_chart->Name = L"monthly_balance_chart";
				series1->ChartArea = L"ChartArea1";
				series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Doughnut;
				series1->CustomProperties = L"PieStartAngle=270";
				series1->Label = L"#LEGENDTEXT\\n#VAL{C}";
				series1->Name = L"monthly_balance_graph";
				series1->YValuesPerPoint = 4;
				this->monthly_balance_chart->Series->Add(series1);
				this->monthly_balance_chart->Size = System::Drawing::Size(352, 206);
				this->monthly_balance_chart->TabIndex = 1;
				this->monthly_balance_chart->Text = L"chart1";
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(8, 2);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(95, 20);
				this->label1->TabIndex = 0;
				this->label1->Text = L"n月の収支";
				// 
				// month_label
				// 
				this->month_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
				this->month_label->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 12));
				this->month_label->ForeColor = System::Drawing::Color::White;
				this->month_label->Location = System::Drawing::Point(310, 55);
				this->month_label->Name = L"month_label";
				this->month_label->Size = System::Drawing::Size(161, 33);
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
				this->next_button->Location = System::Drawing::Point(477, 61);
				this->next_button->Name = L"next_button";
				this->next_button->Size = System::Drawing::Size(35, 23);
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
				this->previous_button->Location = System::Drawing::Point(269, 61);
				this->previous_button->Name = L"previous_button";
				this->previous_button->Size = System::Drawing::Size(35, 23);
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
				this->bookname_label->Location = System::Drawing::Point(0, 28);
				this->bookname_label->Name = L"bookname_label";
				this->bookname_label->Size = System::Drawing::Size(780, 30);
				this->bookname_label->TabIndex = 7;
				this->bookname_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				// 
				// MainForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
				this->BackColor = System::Drawing::Color::DarkGreen;
				this->ClientSize = System::Drawing::Size(780, 551);
				this->Controls->Add(this->bookname_label);
				this->Controls->Add(this->previous_button);
				this->Controls->Add(this->next_button);
				this->Controls->Add(this->month_label);
				this->Controls->Add(this->tabs);
				this->Controls->Add(this->menuStrip1);
				this->MainMenuStrip = this->menuStrip1;
				this->Margin = System::Windows::Forms::Padding(2);
				this->MinimumSize = System::Drawing::Size(620, 176);
				this->Name = L"MainForm";
				this->Text = L"w";
				this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
				this->menuStrip1->ResumeLayout(false);
				this->menuStrip1->PerformLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->history_grid))->EndInit();
				this->tabs->ResumeLayout(false);
				this->main_page->ResumeLayout(false);
				this->balance_tab->ResumeLayout(false);
				this->balance_tab->PerformLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->monthly_balance_chart))->EndInit();
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

		private:
			String ^_opening_bookpath;
			int _opening_year;
			int _opening_month;

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
			Void _SaveBook(String^ bookpath_s, int year, int month);

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
			Void _load_grid(Object^ targetform,String^ gridname, List<List <String^>^>% values);

			/// <summary>
			/// ToolStripMenuの”最近のBook”に最近使ったBookをConfigより取得して表示します。
			/// </summary>
			Void _show_recentbook_toolstripmenu();


			int _sort_donutdata(DonutData^ a, DonutData^ b);

			Void _load_donut_graph(Object^ sender, String^ chartname,List<DonutData^ >% donutdata);

			Void _load_monthly_balance_graph();
#pragma endregion
#pragma region イベントハンドラ等
		private:
			Void MainForm_Load(Object^ sender, EventArgs^ e);
			Void tabs_DrawItem(Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e);
			Void ExitToolStripMenuItem_Click(Object^ sender, EventArgs^ e);
			Void CreateNewToolStripMenuItem_Click(Object^ sender, EventArgs^ e);
			Void OpenToolStripMenuItem_Click(Object^ sender, EventArgs^ e);
			Void RecenttoolStripMenuItem_Click(Object^ sender, EventArgs^ e);
			Void previous_button_Click(Object^ sender, EventArgs^ e);
			Void next_button_Click(Object^ sender, EventArgs^ e);
			Void add_data_button_Click(Object^ sender, EventArgs^ e);
			Void history_grid_SortCompare(Object^ sender, System::Windows::Forms::DataGridViewSortCompareEventArgs^ e);
			Void tabs_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
#pragma endregion

	};
}
