#include "Headers.h"
#include "Manager.h"

#pragma once

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Interface
	/// </summary>
	public ref class Interface : public System::Windows::Forms::Form
	{
	public:
		Interface(void);
		void operateUserRequest();
		void extendWindow();
		void retractWindow();
		void toggleHelpSection();
		void toggleSettingSection();
		void toggleFeedback();
		void toggleHelpTab();
		void toggleSettingsTab();
		void convertSysToStdString(String ^, string&);
		void convertStdToSysString(string &, String ^&);

	protected:
		~Interface();

	private:
		// input functions
		void receiveUserInput();

		// display functions
		void displayTasksListBox();
		void displayFeedbackBox();
		void displayInputField();
		void getHelpBoxDisplay();

		// taskList display functions
		void displayTodayLabel();
		void displayAllTaskLabel();
		void displayTask(const Task &task);
		void displayTaskIndex(const Task &task);
		void displayTaskInformation(const Task &task);
		
		Manager *manager;
		Log *log;
		bool windowIsExtended;
		bool helpIsShown;
		bool settingIsShown;
		int numRowsToDisplay;

	private: System::Windows::Forms::TextBox^  inputField;
	private: System::Windows::Forms::TextBox^  feedbackBox;
	private: System::Windows::Forms::Label^  title;
	private: System::Windows::Forms::RichTextBox^  richTaskList;
	private: System::Windows::Forms::Label^  IDLabel;
	private: System::Windows::Forms::Label^  dateLabel;
	private: System::Windows::Forms::Label^  timeLabel;
	private: System::Windows::Forms::Label^  taskLabel;
	private: System::Windows::Forms::RichTextBox^  helpBox;
	private: System::Windows::Forms::Label^  helpDivider;
	private: System::Windows::Forms::Label^  settingsTitle;
	private: System::Windows::Forms::Label^  feedbackSetting;
	private: System::Windows::Forms::Button^  feedbackButton;
	private: System::Windows::Forms::Label^  helpTitle;
	private: System::Windows::Forms::TextBox^  helpIntro;
	private: System::Windows::Forms::Label^  helpTab;
	private: System::Windows::Forms::Label^  settingsTab;
	private: System::Windows::Forms::Label^  helpTabSetting;
	private: System::Windows::Forms::Label^  settingTabSetting;
	private: System::Windows::Forms::Button^  helpTabSettingButton;
	private: System::Windows::Forms::Button^  settingsTabSettingButton;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->inputField = (gcnew System::Windows::Forms::TextBox());
			this->feedbackBox = (gcnew System::Windows::Forms::TextBox());
			this->title = (gcnew System::Windows::Forms::Label());
			this->richTaskList = (gcnew System::Windows::Forms::RichTextBox());
			this->IDLabel = (gcnew System::Windows::Forms::Label());
			this->dateLabel = (gcnew System::Windows::Forms::Label());
			this->timeLabel = (gcnew System::Windows::Forms::Label());
			this->taskLabel = (gcnew System::Windows::Forms::Label());
			this->helpBox = (gcnew System::Windows::Forms::RichTextBox());
			this->helpDivider = (gcnew System::Windows::Forms::Label());
			this->settingsTitle = (gcnew System::Windows::Forms::Label());
			this->feedbackSetting = (gcnew System::Windows::Forms::Label());
			this->feedbackButton = (gcnew System::Windows::Forms::Button());
			this->helpTitle = (gcnew System::Windows::Forms::Label());
			this->helpIntro = (gcnew System::Windows::Forms::TextBox());
			this->helpTab = (gcnew System::Windows::Forms::Label());
			this->settingsTab = (gcnew System::Windows::Forms::Label());
			this->helpTabSetting = (gcnew System::Windows::Forms::Label());
			this->settingTabSetting = (gcnew System::Windows::Forms::Label());
			this->helpTabSettingButton = (gcnew System::Windows::Forms::Button());
			this->settingsTabSettingButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// inputField
			// 
			this->inputField->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->inputField->BackColor = System::Drawing::Color::White;
			this->inputField->ForeColor = System::Drawing::SystemColors::WindowText;
			this->inputField->Location = System::Drawing::Point(12, 555);
			this->inputField->Name = L"inputField";
			this->inputField->Size = System::Drawing::Size(351, 20);
			this->inputField->TabIndex = 0;
			this->inputField->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Interface::keyPressed);
			// 
			// feedbackBox
			// 
			this->feedbackBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->feedbackBox->BackColor = System::Drawing::Color::White;
			this->feedbackBox->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->feedbackBox->Location = System::Drawing::Point(12, 453);
			this->feedbackBox->Multiline = true;
			this->feedbackBox->Name = L"feedbackBox";
			this->feedbackBox->ReadOnly = true;
			this->feedbackBox->Size = System::Drawing::Size(351, 96);
			this->feedbackBox->TabIndex = 1;
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->BackColor = System::Drawing::Color::White;
			this->title->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->title->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->title->Location = System::Drawing::Point(138, 9);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(97, 29);
			this->title->TabIndex = 3;
			this->title->Text = L"EasyDone";
			this->title->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// richTaskList
			// 
			this->richTaskList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left));
			this->richTaskList->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTaskList->Font = (gcnew System::Drawing::Font(L"Broadway", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTaskList->ForeColor = System::Drawing::SystemColors::InactiveCaption;
			this->richTaskList->Location = System::Drawing::Point(12, 61);
			this->richTaskList->Name = L"richTaskList";
			this->richTaskList->Size = System::Drawing::Size(351, 386);
			this->richTaskList->TabIndex = 4;
			this->richTaskList->Text = L"";
			// 
			// IDLabel
			// 
			this->IDLabel->AutoSize = true;
			this->IDLabel->ForeColor = System::Drawing::Color::SkyBlue;
			this->IDLabel->Location = System::Drawing::Point(27, 42);
			this->IDLabel->Name = L"IDLabel";
			this->IDLabel->Size = System::Drawing::Size(18, 13);
			this->IDLabel->TabIndex = 5;
			this->IDLabel->Text = L"ID";
			// 
			// dateLabel
			// 
			this->dateLabel->AutoSize = true;
			this->dateLabel->ForeColor = System::Drawing::Color::SkyBlue;
			this->dateLabel->Location = System::Drawing::Point(63, 42);
			this->dateLabel->Name = L"dateLabel";
			this->dateLabel->Size = System::Drawing::Size(30, 13);
			this->dateLabel->TabIndex = 6;
			this->dateLabel->Text = L"Date";
			// 
			// timeLabel
			// 
			this->timeLabel->AutoSize = true;
			this->timeLabel->ForeColor = System::Drawing::Color::SkyBlue;
			this->timeLabel->Location = System::Drawing::Point(111, 42);
			this->timeLabel->Name = L"timeLabel";
			this->timeLabel->Size = System::Drawing::Size(30, 13);
			this->timeLabel->TabIndex = 7;
			this->timeLabel->Text = L"Time";
			// 
			// taskLabel
			// 
			this->taskLabel->AutoSize = true;
			this->taskLabel->ForeColor = System::Drawing::Color::SkyBlue;
			this->taskLabel->Location = System::Drawing::Point(160, 42);
			this->taskLabel->Name = L"taskLabel";
			this->taskLabel->Size = System::Drawing::Size(31, 13);
			this->taskLabel->TabIndex = 8;
			this->taskLabel->Text = L"Task";
			// 
			// helpBox
			// 
			this->helpBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->helpBox->BackColor = System::Drawing::Color::White;
			this->helpBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->helpBox->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->helpBox->Location = System::Drawing::Point(376, 105);
			this->helpBox->Name = L"helpBox";
			this->helpBox->ReadOnly = true;
			this->helpBox->Size = System::Drawing::Size(293, 467);
			this->helpBox->TabIndex = 9;
			this->helpBox->Text = L"";
			this->helpBox->Visible = false;
			// 
			// helpDivider
			// 
			this->helpDivider->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->helpDivider->Location = System::Drawing::Point(372, 16);
			this->helpDivider->Name = L"helpDivider";
			this->helpDivider->Size = System::Drawing::Size(1, 560);
			this->helpDivider->TabIndex = 10;
			this->helpDivider->Visible = false;
			// 
			// settingsTitle
			// 
			this->settingsTitle->AutoSize = true;
			this->settingsTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->settingsTitle->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->settingsTitle->Location = System::Drawing::Point(487, 18);
			this->settingsTitle->Name = L"settingsTitle";
			this->settingsTitle->Size = System::Drawing::Size(70, 21);
			this->settingsTitle->TabIndex = 11;
			this->settingsTitle->Text = L"Settings";
			this->settingsTitle->Visible = false;
			// 
			// feedbackSetting
			// 
			this->feedbackSetting->AutoSize = true;
			this->feedbackSetting->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->feedbackSetting->ForeColor = System::Drawing::Color::RoyalBlue;
			this->feedbackSetting->Location = System::Drawing::Point(379, 61);
			this->feedbackSetting->Name = L"feedbackSetting";
			this->feedbackSetting->Size = System::Drawing::Size(104, 20);
			this->feedbackSetting->TabIndex = 12;
			this->feedbackSetting->Text = L"Feedback Box";
			this->feedbackSetting->Visible = false;
			// 
			// feedbackButton
			// 
			this->feedbackButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->feedbackButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->feedbackButton->Location = System::Drawing::Point(589, 61);
			this->feedbackButton->Name = L"feedbackButton";
			this->feedbackButton->Size = System::Drawing::Size(75, 23);
			this->feedbackButton->TabIndex = 13;
			this->feedbackButton->Text = L"Hide";
			this->feedbackButton->UseVisualStyleBackColor = true;
			this->feedbackButton->Visible = false;
			this->feedbackButton->Click += gcnew System::EventHandler(this, &Interface::feedbackToggle);
			// 
			// helpTitle
			// 
			this->helpTitle->AutoSize = true;
			this->helpTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpTitle->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->helpTitle->Location = System::Drawing::Point(500, 18);
			this->helpTitle->Name = L"helpTitle";
			this->helpTitle->Size = System::Drawing::Size(45, 21);
			this->helpTitle->TabIndex = 14;
			this->helpTitle->Text = L"Help";
			this->helpTitle->Visible = false;
			// 
			// helpIntro
			// 
			this->helpIntro->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->helpIntro->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpIntro->Location = System::Drawing::Point(376, 41);
			this->helpIntro->Multiline = true;
			this->helpIntro->Name = L"helpIntro";
			this->helpIntro->Size = System::Drawing::Size(278, 84);
			this->helpIntro->TabIndex = 15;
			this->helpIntro->Text = L"Here are some information to help you get started. Follow the examples below to t" 
				L"ry out the various command. Have fun~! :) The task ID is displayed to the left o" 
				L"f your tasks.";
			this->helpIntro->Visible = false;
			// 
			// helpTab
			// 
			this->helpTab->AutoSize = true;
			this->helpTab->BackColor = System::Drawing::Color::WhiteSmoke;
			this->helpTab->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->helpTab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpTab->Location = System::Drawing::Point(354, 327);
			this->helpTab->Name = L"helpTab";
			this->helpTab->Size = System::Drawing::Size(21, 80);
			this->helpTab->TabIndex = 16;
			this->helpTab->Text = L" F1\r\n\r\n H\r\n E\r\n L\r\n P";
			// 
			// settingsTab
			// 
			this->settingsTab->AutoSize = true;
			this->settingsTab->BackColor = System::Drawing::Color::WhiteSmoke;
			this->settingsTab->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->settingsTab->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->settingsTab->Location = System::Drawing::Point(355, 417);
			this->settingsTab->Name = L"settingsTab";
			this->settingsTab->Size = System::Drawing::Size(20, 119);
			this->settingsTab->TabIndex = 17;
			this->settingsTab->Text = L"F2\r\n\r\n S\r\n E\r\n T\r\n T\r\n I\r\n N\r\n G";
			// 
			// helpTabSetting
			// 
			this->helpTabSetting->AutoSize = true;
			this->helpTabSetting->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpTabSetting->ForeColor = System::Drawing::Color::RoyalBlue;
			this->helpTabSetting->Location = System::Drawing::Point(379, 116);
			this->helpTabSetting->Name = L"helpTabSetting";
			this->helpTabSetting->Size = System::Drawing::Size(74, 21);
			this->helpTabSetting->TabIndex = 18;
			this->helpTabSetting->Text = L"Help Tab";
			this->helpTabSetting->Visible = false;
			// 
			// settingTabSetting
			// 
			this->settingTabSetting->AutoSize = true;
			this->settingTabSetting->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->settingTabSetting->ForeColor = System::Drawing::Color::RoyalBlue;
			this->settingTabSetting->Location = System::Drawing::Point(379, 171);
			this->settingTabSetting->Name = L"settingTabSetting";
			this->settingTabSetting->Size = System::Drawing::Size(99, 21);
			this->settingTabSetting->TabIndex = 19;
			this->settingTabSetting->Text = L"Settings Tab";
			this->settingTabSetting->Visible = false;
			// 
			// helpTabSettingButton
			// 
			this->helpTabSettingButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->helpTabSettingButton->Location = System::Drawing::Point(589, 116);
			this->helpTabSettingButton->Name = L"helpTabSettingButton";
			this->helpTabSettingButton->Size = System::Drawing::Size(75, 23);
			this->helpTabSettingButton->TabIndex = 20;
			this->helpTabSettingButton->Text = L"Hide";
			this->helpTabSettingButton->UseMnemonic = false;
			this->helpTabSettingButton->UseVisualStyleBackColor = true;
			this->helpTabSettingButton->Visible = false;
			this->helpTabSettingButton->Click += gcnew System::EventHandler(this, &Interface::helpTabSettingToggle);
			// 
			// settingsTabSettingButton
			// 
			this->settingsTabSettingButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->settingsTabSettingButton->Location = System::Drawing::Point(589, 171);
			this->settingsTabSettingButton->Name = L"settingsTabSettingButton";
			this->settingsTabSettingButton->Size = System::Drawing::Size(75, 23);
			this->settingsTabSettingButton->TabIndex = 21;
			this->settingsTabSettingButton->Text = L"Hide";
			this->settingsTabSettingButton->UseMnemonic = false;
			this->settingsTabSettingButton->UseVisualStyleBackColor = true;
			this->settingsTabSettingButton->Visible = false;
			this->settingsTabSettingButton->Click += gcnew System::EventHandler(this, &Interface::settingTabSettingToggle);
			// 
			// Interface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(375, 587);
			this->ControlBox = false;
			this->Controls->Add(this->settingsTabSettingButton);
			this->Controls->Add(this->helpTabSettingButton);
			this->Controls->Add(this->settingTabSetting);
			this->Controls->Add(this->helpTabSetting);
			this->Controls->Add(this->settingsTab);
			this->Controls->Add(this->helpTab);
			this->Controls->Add(this->helpIntro);
			this->Controls->Add(this->helpTitle);
			this->Controls->Add(this->feedbackButton);
			this->Controls->Add(this->feedbackSetting);
			this->Controls->Add(this->settingsTitle);
			this->Controls->Add(this->helpDivider);
			this->Controls->Add(this->helpBox);
			this->Controls->Add(this->taskLabel);
			this->Controls->Add(this->timeLabel);
			this->Controls->Add(this->dateLabel);
			this->Controls->Add(this->IDLabel);
			this->Controls->Add(this->richTaskList);
			this->Controls->Add(this->title);
			this->Controls->Add(this->feedbackBox);
			this->Controls->Add(this->inputField);
			this->MaximizeBox = false;
			this->Name = L"Interface";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//
		// function: press enter to take in string
		//
	private: System::Void keyPressed(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  keyPressed) {
				 if (inputField->Text == "live search") {
					 feedbackBox->Text = "live search!";
				 }
				 if (keyPressed->KeyCode == Keys::F2) {
					 log->log("User: F2 is pressed, toggleSettingSection()");
					 if (windowIsExtended) {
						 if (helpIsShown) toggleHelpSection();
						 else retractWindow();
					 } else {
						 extendWindow();
					 }
					 toggleSettingSection();
				 }
				 if (keyPressed->KeyCode == Keys::F1) {
					 log->log("User: F1 is pressed, toggleHelpSetion()");
					 if (windowIsExtended) {
						 if (helpIsShown) retractWindow();
						 else toggleSettingSection();
					 } else {
						 extendWindow();
					 }
					 toggleHelpSection();
				 }
				 if (keyPressed->KeyCode == Keys::Enter) {
					 log->log("User: Enter is pressed, operateUserRequest()");
					 operateUserRequest();
				 }
			 }
private: System::Void feedbackToggle(System::Object^  sender, System::EventArgs^  feedbackToggled) {
			 log->log("User: Settings toggled feedback show/hide");
			 toggleFeedback();
		 }

private: System::Void settingTabSettingToggle(System::Object^  sender, System::EventArgs^  settingTabToggled) {
			 log->log("User: Settings toggled settingTab show/hide");
			 toggleSettingsTab();
		 }

private: System::Void helpTabSettingToggle(System::Object^  sender, System::EventArgs^  helpTabToggled) {
			 log->log("User: Settings toggled helpTab show/hide");
			 toggleHelpTab();
		 }
};
}
