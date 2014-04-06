#include "Headers.h"
#include "Manager.h"
#include "Themes.h"
#pragma once

using namespace System::Drawing;
const Color TAB_SELECTED_COLOUR() {return Color::Silver;}
const Color TAB_NOT_SELECTED_COLOUR() {return Color::WhiteSmoke;}
const Color HELP_COLOR_HEADING() {return Color::CornflowerBlue;}
const Color HELP_COLOR_INSTRUCTION() {return Color::Black;}
//const Color TASKLIST_COLOR_TASKINFO() {return Color::Black;}
//const Color TASKLIST_COLOR_HEADING() {return Color::CornflowerBlue;}
const FontStyle HELP_FONTSTYLE_HEADING() {return FontStyle::Bold;}
const FontStyle HELP_FONTSTYLE_INSTRUCTION() {return FontStyle::Regular;}
const FontStyle TASKLIST_FONTSTYLE_INDEX() {return FontStyle::Regular;}

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
	private:
		// ***MAGIC STRINGS***
		literal String ^TITLE_ALLTASKS = "All Tasks";
		literal String ^TITLE_SUMMARY = "Summary";
		literal String ^TITLE_DONETASKS = "Archive";
		literal String ^TASKLIST_HEADING_TODAY = "Today \n";
		literal String ^TASKLIST_HEADING_TOMORROW = "Tomorrow \n";
		literal String ^BUTTON_HIDE = "Hide";
		literal String ^BUTTON_SHOW = "Show";
		literal String ^BUTTON_THEME_SELECTED = "Yay :)";
		literal String ^BUTTON_THEME_NOT_SELECTED = "Choose me!";
		literal String ^TASKLIST_FONT_TASK = "Calibri";
		literal String ^HELP_FONT_HEADING = "Calibri";
		literal String ^HELP_FONT_INSTRUCTION = "Calibri";
		literal String ^TASKLIST_FONT_HEADING = "Broadway";
		literal String ^ENDL = "\n";
		literal String ^TABL = "\t";
		literal String ^TASKLIST_FORMATTING_INDEX = "  ";

		// ***ATTRIBUTES***
		// Interface's esternal libraries
		Manager *manager;
		Log *log;
		array<Theme^> ^theme;

		// state of the window's attributes
		bool summaryTaskListIsShown;
		bool allTaskListIsShown;
		bool doneTaskListIsShown;
		bool windowIsExtended;
		bool helpIsShown;
		bool settingIsShown;
		bool feedbackIsVisible;
		bool helpTabIsVisible;
		bool settingsTabIsVisible;
		themeColor color;
		
		// variable display values in interface.
		// delete this
		String ^titleName;
		int numRowsToDisplay;

		// ***FUNCTIONS***
		// input functions
		void receiveUserInput(); // sub-function of public: operateUserRequest()
		
		// display funcitons - window's aspect
		void extendWindow();
		void retractWindow();
		void toggleHelpSection();
		void toggleSettingSection();

		// display functions - content aspect
		void displayTasksListBoxUsingList(const vector<Task>&);
		void displaySummaryTaskListBox();
		void displayFeedbackBox();
		void displayInputField();
		void getHelpBoxDisplay();

		// display functions - content aspect (taskList specific)
		void displayTodayLabel();
		void displayTomorrowLabel();
		void displayTask(const Task&, const bool&);
		void displayTaskIndex(const Task&);
		void displayTaskInformation(const Task&, const bool&);

		// string conversion functions
		void convertSysToStdString(String ^, string &);
		void convertStdToSysString(string &, String ^&);
		
	public:
		Interface(void);
		~Interface(void);

		// userInput function
		void operateUserRequest(const bool& isSearchCommand);
		
		// pane switching function
		void switchToSummaryTaskListDisplay();
		void switchToAllTaskListDisplay();
		void switchToDoneTaskListDisplay();

		// windowSize changing functions
		void activateHelpPage();
		void activateSettingsPage();

		// settings functions
		void toggleFeedback();
		void toggleHelpTab();
		void toggleSettingsTab();
		void selectTheme(themeColor);

		// form
	private: System::Windows::Forms::Label^  helpDivider;
	private: System::Windows::Forms::Label^  helpTab;
	private: System::Windows::Forms::Label^  settingsTab;
		// main Display
	private: System::Windows::Forms::Label^  title;
	private: System::Windows::Forms::RichTextBox^  richTaskList;
	private: System::Windows::Forms::TextBox^  feedbackBox;
	private: System::Windows::Forms::TextBox^  inputField;
	private: System::Windows::Forms::RichTextBox^  radioDotAll;
	private: System::Windows::Forms::RichTextBox^  radioDotSummary;
	private: System::Windows::Forms::RichTextBox^  radioDotDone;
		// taskList Labels
	private: System::Windows::Forms::Label^  IDLabel;
	private: System::Windows::Forms::Label^  dateLabel;
	private: System::Windows::Forms::Label^  timeLabel;
	private: System::Windows::Forms::Label^  taskLabel;
		// help Section
	private: System::Windows::Forms::Label^  helpTitle;
	private: System::Windows::Forms::TextBox^  helpIntro;
	private: System::Windows::Forms::RichTextBox^  helpBox;
		// settings Section
	private: System::Windows::Forms::Label^  settingsTitle;
			 // feedback setting
	private: System::Windows::Forms::Label^  feedbackSetting;
	private: System::Windows::Forms::Button^  feedbackButton;
			 // helpTab setting
	private: System::Windows::Forms::Label^  helpTabSetting;
	private: System::Windows::Forms::Button^  helpTabSettingButton;
			 // settingTab setting
	private: System::Windows::Forms::Label^  settingTabSetting;
	private: System::Windows::Forms::Button^  settingsTabSettingButton;
			 // theme setting
	private: System::Windows::Forms::Label^  themeSettingLabel;
	private: System::Windows::Forms::Label^  whiteThemeLabel;
	private: System::Windows::Forms::Label^  blueThemeLabel;
	private: System::Windows::Forms::Label^  metalThemeLabel;
	private: System::Windows::Forms::Button^  whiteThemeButton;
	private: System::Windows::Forms::Button^  blueThemeButton;
	private: System::Windows::Forms::Button^  metalThemeButton;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Interface::typeid));
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
			this->themeSettingLabel = (gcnew System::Windows::Forms::Label());
			this->whiteThemeLabel = (gcnew System::Windows::Forms::Label());
			this->blueThemeLabel = (gcnew System::Windows::Forms::Label());
			this->whiteThemeButton = (gcnew System::Windows::Forms::Button());
			this->blueThemeButton = (gcnew System::Windows::Forms::Button());
			this->metalThemeLabel = (gcnew System::Windows::Forms::Label());
			this->metalThemeButton = (gcnew System::Windows::Forms::Button());
			this->radioDotAll = (gcnew System::Windows::Forms::RichTextBox());
			this->radioDotSummary = (gcnew System::Windows::Forms::RichTextBox());
			this->radioDotDone = (gcnew System::Windows::Forms::RichTextBox());
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
			this->title->Font = (gcnew System::Drawing::Font(L"Buxton Sketch", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->title->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->title->Location = System::Drawing::Point(116, 3);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(158, 39);
			this->title->TabIndex = 3;
			this->title->Text = L"At a glance...";
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
			this->helpBox->Location = System::Drawing::Point(376, 143);
			this->helpBox->Name = L"helpBox";
			this->helpBox->ReadOnly = true;
			this->helpBox->Size = System::Drawing::Size(293, 429);
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
			this->feedbackSetting->Size = System::Drawing::Size(134, 20);
			this->feedbackSetting->TabIndex = 12;
			this->feedbackSetting->Text = L"Feedback Box [F9]";
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
			this->helpIntro->Size = System::Drawing::Size(278, 98);
			this->helpIntro->TabIndex = 15;
			this->helpIntro->Text = resources->GetString(L"helpIntro.Text");
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
			this->helpTabSetting->Size = System::Drawing::Size(111, 21);
			this->helpTabSetting->TabIndex = 18;
			this->helpTabSetting->Text = L"Help Tab [F10]";
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
			this->settingTabSetting->Size = System::Drawing::Size(133, 21);
			this->settingTabSetting->TabIndex = 19;
			this->settingTabSetting->Text = L"Settings Tab [F11]";
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
			// themeSettingLabel
			// 
			this->themeSettingLabel->AutoSize = true;
			this->themeSettingLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->themeSettingLabel->ForeColor = System::Drawing::Color::RoyalBlue;
			this->themeSettingLabel->Location = System::Drawing::Point(379, 223);
			this->themeSettingLabel->Name = L"themeSettingLabel";
			this->themeSettingLabel->Size = System::Drawing::Size(97, 21);
			this->themeSettingLabel->TabIndex = 22;
			this->themeSettingLabel->Text = L"Theme [F12]";
			this->themeSettingLabel->Visible = false;
			// 
			// whiteThemeLabel
			// 
			this->whiteThemeLabel->AutoSize = true;
			this->whiteThemeLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->whiteThemeLabel->Location = System::Drawing::Point(422, 271);
			this->whiteThemeLabel->Name = L"whiteThemeLabel";
			this->whiteThemeLabel->Size = System::Drawing::Size(44, 17);
			this->whiteThemeLabel->TabIndex = 23;
			this->whiteThemeLabel->Text = L"White";
			this->whiteThemeLabel->Visible = false;
			// 
			// blueThemeLabel
			// 
			this->blueThemeLabel->AutoSize = true;
			this->blueThemeLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->blueThemeLabel->Location = System::Drawing::Point(422, 327);
			this->blueThemeLabel->Name = L"blueThemeLabel";
			this->blueThemeLabel->Size = System::Drawing::Size(34, 17);
			this->blueThemeLabel->TabIndex = 24;
			this->blueThemeLabel->Text = L"Blue";
			this->blueThemeLabel->Visible = false;
			// 
			// whiteThemeButton
			// 
			this->whiteThemeButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->whiteThemeButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->whiteThemeButton->Location = System::Drawing::Point(531, 269);
			this->whiteThemeButton->Name = L"whiteThemeButton";
			this->whiteThemeButton->Size = System::Drawing::Size(99, 23);
			this->whiteThemeButton->TabIndex = 25;
			this->whiteThemeButton->Text = L"Yay :)";
			this->whiteThemeButton->UseVisualStyleBackColor = true;
			this->whiteThemeButton->Visible = false;
			this->whiteThemeButton->Click += gcnew System::EventHandler(this, &Interface::whiteThemeClicked);
			// 
			// blueThemeButton
			// 
			this->blueThemeButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->blueThemeButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->blueThemeButton->Location = System::Drawing::Point(531, 327);
			this->blueThemeButton->Name = L"blueThemeButton";
			this->blueThemeButton->Size = System::Drawing::Size(99, 23);
			this->blueThemeButton->TabIndex = 26;
			this->blueThemeButton->Text = L"Choose me!";
			this->blueThemeButton->UseVisualStyleBackColor = true;
			this->blueThemeButton->Visible = false;
			this->blueThemeButton->Click += gcnew System::EventHandler(this, &Interface::blueThemeClicked);
			// 
			// metalThemeLabel
			// 
			this->metalThemeLabel->AutoSize = true;
			this->metalThemeLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->metalThemeLabel->Location = System::Drawing::Point(422, 383);
			this->metalThemeLabel->Name = L"metalThemeLabel";
			this->metalThemeLabel->Size = System::Drawing::Size(74, 17);
			this->metalThemeLabel->TabIndex = 23;
			this->metalThemeLabel->Text = L"Metal Gray";
			this->metalThemeLabel->Visible = false;
			// 
			// metalThemeButton
			// 
			this->metalThemeButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->metalThemeButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->metalThemeButton->Location = System::Drawing::Point(531, 383);
			this->metalThemeButton->Name = L"metalThemeButton";
			this->metalThemeButton->Size = System::Drawing::Size(99, 23);
			this->metalThemeButton->TabIndex = 26;
			this->metalThemeButton->Text = L"Choose me!";
			this->metalThemeButton->UseVisualStyleBackColor = true;
			this->metalThemeButton->Visible = false;
			this->metalThemeButton->Click += gcnew System::EventHandler(this, &Interface::metalThemeClicked);
			// 
			// radioDotAll
			// 
			this->radioDotAll->BackColor = System::Drawing::Color::White;
			this->radioDotAll->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->radioDotAll->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioDotAll->Location = System::Drawing::Point(180, 433);
			this->radioDotAll->Name = L"radioDotAll";
			this->radioDotAll->ReadOnly = true;
			this->radioDotAll->Size = System::Drawing::Size(10, 15);
			this->radioDotAll->TabIndex = 28;
			this->radioDotAll->Text = L"•";
			// 
			// radioDotSummary
			// 
			this->radioDotSummary->BackColor = System::Drawing::Color::White;
			this->radioDotSummary->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->radioDotSummary->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioDotSummary->Location = System::Drawing::Point(165, 433);
			this->radioDotSummary->Name = L"radioDotSummary";
			this->radioDotSummary->ReadOnly = true;
			this->radioDotSummary->Size = System::Drawing::Size(10, 15);
			this->radioDotSummary->TabIndex = 29;
			this->radioDotSummary->Text = L"•";
			// 
			// radioDotDone
			// 
			this->radioDotDone->BackColor = System::Drawing::Color::White;
			this->radioDotDone->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->radioDotDone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->radioDotDone->Location = System::Drawing::Point(194, 433);
			this->radioDotDone->Name = L"radioDotDone";
			this->radioDotDone->ReadOnly = true;
			this->radioDotDone->Size = System::Drawing::Size(10, 15);
			this->radioDotDone->TabIndex = 30;
			this->radioDotDone->Text = L"•";
			// 
			// Interface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(375, 587);
			this->ControlBox = false;
			this->Controls->Add(this->radioDotDone);
			this->Controls->Add(this->radioDotSummary);
			this->Controls->Add(this->radioDotAll);
			this->Controls->Add(this->metalThemeButton);
			this->Controls->Add(this->metalThemeLabel);
			this->Controls->Add(this->blueThemeButton);
			this->Controls->Add(this->whiteThemeButton);
			this->Controls->Add(this->blueThemeLabel);
			this->Controls->Add(this->whiteThemeLabel);
			this->Controls->Add(this->themeSettingLabel);
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
				 if (keyPressed->KeyCode == Keys::F1) {
					 activateHelpPage();
				 } else if (keyPressed->KeyCode == Keys::F2) {
					 activateSettingsPage();
				 } else if (keyPressed->KeyCode == Keys::F5) {
					 if (summaryTaskListIsShown) {
						 switchToDoneTaskListDisplay();
					 } else if (allTaskListIsShown) {
						 switchToSummaryTaskListDisplay();
					 } else if (doneTaskListIsShown) {
						 switchToAllTaskListDisplay();
					 }
				 } else if (keyPressed->KeyCode == Keys::F6) {
					 if (summaryTaskListIsShown) {
						 switchToAllTaskListDisplay();
					 } else if (allTaskListIsShown) {
						 switchToDoneTaskListDisplay();
					 } else if (doneTaskListIsShown) {
						 switchToSummaryTaskListDisplay();
					 }
				 } else if (keyPressed->KeyCode == Keys::F9) {
					 toggleFeedback();
				 } else if (keyPressed->KeyCode == Keys::F10) {
					 toggleHelpTab();
				 } else if (keyPressed->KeyCode == Keys::F11) {
					 toggleSettingsTab();
				 } else if (keyPressed->KeyCode == Keys::F12) {
					 if (this->BackColor == theme[WHITE]->background) {
						 selectTheme(BLUE);
					 } else if (this->BackColor == theme[BLUE]->background) {
						 selectTheme(METAL);
					 } else if (this->BackColor == theme[METAL]->background) {
						 selectTheme(WHITE);
					 }
				 } else if (keyPressed->KeyCode == Keys::Enter || inputField->Text->Contains("search")) {
					 log->log("User: Enter is pressed, operateUserRequest()");
					 operateUserRequest(inputField->Text->Contains("search"));
				 } else {
					 log->log("User: Not searching, show normal texts");
					 if (summaryTaskListIsShown) {
						 displaySummaryTaskListBox();
					 } else {
						 displayTasksListBoxUsingList(manager->getAllTaskList());
					 }
					 String ^convertedFeedback;
					 string feedback = manager->getFeedback();
					 convertStdToSysString(feedback, convertedFeedback);
					 feedbackBox->Text = convertedFeedback;
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

private: System::Void whiteThemeClicked(System::Object^  sender, System::EventArgs^  buttonClicked) {
			 selectTheme(WHITE);
		 }
private: System::Void blueThemeClicked(System::Object^  sender, System::EventArgs^  buttonClicked) {
			 selectTheme(BLUE);
		 }
private: System::Void metalThemeClicked(System::Object^  sender, System::EventArgs^  buttonClicked) {
			 selectTheme(METAL);
		 }
};
}
