#include "Interface.h"

using namespace System; 
using namespace System::Windows::Forms; 

[STAThread] 
void main(array<String^>^ args) { 
 Application::EnableVisualStyles(); 
 Application::SetCompatibleTextRenderingDefault(false); 
 
 GUI::Interface mainWindow; 
 Application::Run(%mainWindow); 
} 

GUI::Interface::Interface(void) {
	InitializeComponent();
	log = new Log();
	log->clear();

	log->log("GUI: Instatiate new manager");
	manager = new Manager();
	
	log->log("GUI: Set numRowsToDisplay to 20 lines");
	numRowsToDisplay = TASKLIST_RETRACT_ROW;

	log->log("GUI: display taskListBox, feedbackBox");
	displayTasksListBox();
	displayFeedbackBox();

	log->log("GUI: get helpBox display");
	getHelpBoxDisplay();

	log->log("GUI: Hide windowIsExtend, helpIsShow, settingIsShown");
	windowIsExtended = false;
	helpIsShown = false;
	settingIsShown = false;

	log->endLog();
}

GUI::Interface::~Interface() {
	log->log("GUI: delete manager");
	delete manager;
	delete log;
	if (components)	{
		delete components;
	}

	log->endLog();
}

void GUI::Interface::operateUserRequest() {
	log->log("GUI: receiveUserInput");
	receiveUserInput();

	log->log("GUI: display taskListBox, feedbackBox, inputField");
	displayTasksListBox();
	displayFeedbackBox();
	displayInputField();

	log->endLog();
}

// input functions
void GUI::Interface::receiveUserInput() {
	String ^inputString;
	std::string convertedInputString;

	log->log("GUI: receive inputField->Text, convert to std:string");
	inputString = inputField->Text;
	convertSysToStdString(inputString, convertedInputString);

	log->log("GUI: Pass convertedInputString to manager");
	manager->receiveInput(convertedInputString);

	log->endLog();
}

void GUI::Interface::retractWindow() {
	this->ClientSize = System::Drawing::Size(FORM_X_RETRACT, FORM_Y);
	this->helpDivider->Visible = !this->helpDivider->Visible;

	this->helpTab->Location = System::Drawing::Point(TAB_X_RETRACT, TAB_Y_HELP);
	this->settingsTab->Location = System::Drawing::Point(TAB_X_RETRACT, TAB_Y_SETTING);

	windowIsExtended = !windowIsExtended;
	log->log("GUI: window is retracted");
}

void GUI::Interface::extendWindow() {
	this->ClientSize = System::Drawing::Size(FORM_X_EXTENT, FORM_Y);
	this->helpDivider->Visible = !this->helpDivider->Visible;

	this->helpTab->Location = System::Drawing::Point(TAB_X_EXTENT, TAB_Y_HELP);
	this->settingsTab->Location = System::Drawing::Point(TAB_X_EXTENT, TAB_Y_SETTING);

	windowIsExtended = !windowIsExtended;
	log->log("GUI: window is extended");
}

void GUI::Interface::toggleHelpSection() {
	assert(helpIsShown == this->helpBox->Visible);

	this->helpBox->Visible = !this->helpBox->Visible;
	this->helpTitle->Visible = !this->helpTitle->Visible;
	this->helpIntro->Visible = !this->helpIntro->Visible;
	helpIsShown = !helpIsShown;

	if (helpIsShown) {
		this->helpTab->BackColor = TAB_SELECTED_COLOUR();
	} else {
		this->helpTab->BackColor = TAB_NOT_SELECTED_COLOUR();
	}

	log->log("GUI: help section is toggled");
}

void GUI::Interface::toggleSettingSection() {
	this->settingsTitle->Visible = !this->settingsTitle->Visible;
	this->feedbackSetting->Visible = !this->feedbackSetting->Visible;
	this->feedbackButton->Visible = !this->feedbackButton->Visible;
	this->helpTabSetting->Visible = !this->helpTabSetting->Visible;
	this->helpTabSettingButton->Visible = !this->helpTabSettingButton->Visible;
	this->settingTabSetting->Visible = !this->settingTabSetting->Visible;
	this->settingsTabSettingButton->Visible = !this->settingsTabSettingButton->Visible;
	this->themeSettingLabel->Visible = !this->themeSettingLabel->Visible;
	this->whiteThemeLabel->Visible = !this->whiteThemeLabel->Visible;
	this->blueThemeLabel->Visible = !this->blueThemeLabel->Visible;
	this->whiteThemeButton->Visible = !this->whiteThemeButton->Visible;
	this->blueThemeButton->Visible = !this->blueThemeButton->Visible ;
	settingIsShown = !settingIsShown;

	if (settingIsShown) {
		this->settingsTab->BackColor = TAB_SELECTED_COLOUR();
	} else {
		this->settingsTab->BackColor = TAB_NOT_SELECTED_COLOUR();
	}

	log->log("GUI: setting section is toggled");
}

void GUI::Interface::toggleFeedback() {
	this->feedbackBox->Visible = !this->feedbackBox->Visible;
	bool feedbackIsShown = this->feedbackBox->Visible;

	if (feedbackIsShown) {
		this->richTaskList->Size = System::Drawing::Size(TASKLIST_X, TASKLIST_Y_RETRACT);
		numRowsToDisplay = TASKLIST_RETRACT_ROW;
		feedbackButton->Text = "Hide";
	} else {
		this->richTaskList->Size = System::Drawing::Size(TASKLIST_X, TASKLIST_Y_EXTENT);
		numRowsToDisplay = TASKLIST_EXTENT_ROW;
		feedbackButton->Text = "Show";
	}
	log->log("GUI: feedback is toggled");
	log->log("GUI: taskListBox is displayed");
	displayTasksListBox();
}

void GUI::Interface::toggleHelpTab() {
	this->helpTab->Visible = !this->helpTab->Visible;

	bool helpTabIsVisible = this->helpTab->Visible;
	if (this->helpTab->Visible) {
		helpTabSettingButton->Text = "Hide";
	} else {
		helpTabSettingButton->Text = "Show";
	}
	log->log("GUI: helpTab is toggled");
}

void GUI::Interface::toggleSettingsTab() {
	this->settingsTab->Visible = !this->settingsTab->Visible;

	bool settingTabIsVisible = this->settingsTab->Visible;
	if (settingTabIsVisible) {
		settingsTabSettingButton->Text = "Hide";
	} else {
		settingsTabSettingButton->Text = "Show";
	}
	log->log("GUI: settingsTab is toggled");
}

void GUI::Interface::selectWhiteTheme() {
	this->BackColor = ThemeWhite::background();
	this->title->BackColor = ThemeWhite::background();
	this->title->ForeColor = ThemeWhite::label();
	this->richTaskList->BackColor = ThemeWhite::background();
	this->helpTitle->BackColor = ThemeWhite::background();
	this->helpTitle->ForeColor = ThemeWhite::label();
	this->settingsTitle->BackColor = ThemeWhite::background();
	this->settingsTitle->ForeColor = ThemeWhite::label();
	this->feedbackSetting->ForeColor = ThemeWhite::label();
	this->helpTabSetting->ForeColor = ThemeWhite::label();
	this->settingTabSetting->ForeColor = ThemeWhite::label();
	this->themeSettingLabel->ForeColor = ThemeWhite::label();
	indexColor = ThemeWhite::index();

	this->blueThemeButton->Text = "Choose me!";
	this->whiteThemeButton->Text = "Yay!";
	displayTasksListBox();
}

void GUI::Interface::selectBlueTheme() {
	this->BackColor = ThemeBlue::background();
	this->title->BackColor = ThemeBlue::background();
	this->title->ForeColor = ThemeBlue::label();
	this->richTaskList->BackColor = ThemeBlue::background();
	this->helpTitle->BackColor = ThemeBlue::background();
	this->helpTitle->ForeColor = ThemeBlue::label();
	this->settingsTitle->BackColor = ThemeBlue::background();
	this->settingsTitle->ForeColor = ThemeBlue::label();
	this->feedbackSetting->ForeColor = ThemeBlue::label();
	this->helpTabSetting->ForeColor = ThemeBlue::label();
	this->settingTabSetting->ForeColor = ThemeBlue::label();
	this->themeSettingLabel->ForeColor = ThemeBlue::label();
	indexColor = ThemeBlue::index();

	this->blueThemeButton->Text = "Yay!";
	this->whiteThemeButton->Text = "Choose me!";
	displayTasksListBox();
}

// display functions
void GUI::Interface::displayTasksListBox() {
	std::vector<Task> receivedTaskList;
	int i = 0;

	receivedTaskList = manager->getTaskList();

	richTaskList->Clear();
	while (i < (int)receivedTaskList.size() && i < numRowsToDisplay) {
		displayTask(receivedTaskList[i]);
		i++;
	}
}

void GUI::Interface::displayFeedbackBox() {
	String ^feedbackToDisplay;
	std::string receivedFeedback;

	receivedFeedback = manager->getFeedback();
	convertStdToSysString(receivedFeedback, feedbackToDisplay);
	feedbackBox->Text = feedbackToDisplay;

	delete feedbackToDisplay;
}

void GUI::Interface::displayInputField() {
	String ^inputToDisplay;
	std::string receivedInput;

	receivedInput = manager->getInputField();
	convertStdToSysString(receivedInput, inputToDisplay);
	inputField->Text = inputToDisplay;

	delete inputToDisplay;
}

void GUI::Interface::getHelpBoxDisplay() {
	vector<string> helpHeadings = manager->getHelpHeadings();
	vector<string> helpInstructions = manager->getHelpInstructions();
	
	for (int i = 0; i < HELP_NUMBER_OF_SECTIONS; ++i) {
		String ^heading;
		String ^instruction;
		convertStdToSysString(helpHeadings[i], heading);
		convertStdToSysString(helpInstructions[i], instruction);

		helpBox->SelectionFont = gcnew System::Drawing::Font("Calibri", 12, FontStyle::Bold);
		helpBox->SelectionColor = Color::CornflowerBlue;

		helpBox->SelectedText = heading;
		helpBox->SelectedText = "\n";
		delete helpBox->SelectionFont;

		helpBox->SelectionFont = gcnew System::Drawing::Font("Calibri", 10, FontStyle::Regular);
		helpBox->SelectionColor = Color::Black;

		helpBox->SelectedText = instruction;
		helpBox->SelectedText = "\n";
		delete helpBox->SelectionFont;

		delete heading;
		delete instruction;
	}
}

// string conversion functions
void GUI::Interface::convertSysToStdString(String ^s, string &os) {
	using namespace Runtime::InteropServices;
	const char* chars = 
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

void GUI::Interface::convertStdToSysString(string &os, String^ &s) {
	s = gcnew String(os.c_str());
}

// taskList display functions
void GUI::Interface::displayTask(const Task &task) {
	displayTaskIndex(task);
	displayTaskInformation(task);
}

void GUI::Interface::displayTaskIndex(const Task &task) {
	if (task.isBold) {
		richTaskList->SelectionFont = gcnew System::Drawing::Font("Calibri", 8, FontStyle::Bold);
	} else {
		richTaskList->SelectionFont = gcnew System::Drawing::Font("Calibri", 8, FontStyle::Regular);
	}
	richTaskList->SelectionColor = indexColor;
			
	String ^index = gcnew String(task.taskID.c_str());
	richTaskList->SelectedText = "  ";
	richTaskList->SelectedText = index;

	delete richTaskList->SelectionFont;
	delete index;
}

void GUI::Interface::displayTaskInformation(const Task &task) {
	if (task.isBold) {
		richTaskList->SelectionFont = gcnew System::Drawing::Font("Calibri", 11, FontStyle::Bold);
	} else {
		richTaskList->SelectionFont = gcnew System::Drawing::Font("Calibri", 11, FontStyle::Regular);
	}
	richTaskList->SelectionColor = Color::Black;

	// ~~Spacing~~
	richTaskList->SelectedText = "\t";
	// - Date
	String ^startDate = gcnew String(task.startDate.c_str());
	richTaskList->SelectedText = startDate;
	// ~~Spacing~~
	richTaskList->SelectedText = "\t";
	// - Time
	String ^startTime = gcnew String(task.startTime.c_str());
	richTaskList->SelectedText = startTime;
	// ~~Spacing~~
	richTaskList->SelectedText = "\t";
	// - Description
	String ^taskName = gcnew String(task.taskName.c_str());
	richTaskList->SelectedText = taskName;
	// ~~NewLine~~
	richTaskList->SelectedText = "\n";

	delete richTaskList->SelectionFont;
	delete startDate;
	delete startTime;
	delete taskName;
}

void GUI::Interface::displayTodayLabel() {
	richTaskList->SelectionFont = gcnew System::Drawing::Font("Broadway", 12);
	richTaskList->SelectionColor = Color::CornflowerBlue;
	richTaskList->SelectedText = "Today \n";

	delete richTaskList->SelectionFont;
}

void GUI::Interface::displayAllTaskLabel() {	
	richTaskList->SelectionFont = gcnew System::Drawing::Font("Broadway", 12);
	richTaskList->SelectionColor = Color::CornflowerBlue;
	richTaskList->SelectedText = "All Tasks \n";

	delete richTaskList->SelectionFont;
}
