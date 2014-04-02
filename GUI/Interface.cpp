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

	theme = prepareThemes();

	log->endLog();
}

GUI::Interface::~Interface() {
	log->log("GUI: delete manager");
	delete manager;
	delete log;
	if (components)	{
		delete components;
	}
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
	log->log("User: F1 is pressed, toggleHelpSetion()");

	helpIsShown = !helpIsShown;
	this->helpBox->Visible = helpIsShown;
	this->helpTitle->Visible = helpIsShown;
	this->helpIntro->Visible = helpIsShown;

	if (helpIsShown) {
		this->helpTab->BackColor = TAB_SELECTED_COLOUR();
	} else {
		this->helpTab->BackColor = TAB_NOT_SELECTED_COLOUR();
	}

	log->log("GUI: help section is toggled");
}

void GUI::Interface::toggleSettingSection() {
	assert(helpIsShown == this->helpBox->Visible);
	log->log("User: F2 is pressed, toggleSettingSection()");

	settingIsShown = !settingIsShown;
	this->settingsTitle->Visible = settingIsShown;
	this->feedbackSetting->Visible = settingIsShown;
	this->feedbackButton->Visible = settingIsShown;
	this->helpTabSetting->Visible = settingIsShown;
	this->helpTabSettingButton->Visible = settingIsShown;
	this->settingTabSetting->Visible = settingIsShown;
	this->settingsTabSettingButton->Visible = settingIsShown;
	this->themeSettingLabel->Visible = settingIsShown;
	this->whiteThemeLabel->Visible = settingIsShown;
	this->blueThemeLabel->Visible = settingIsShown;
	this->whiteThemeButton->Visible = settingIsShown;
	this->blueThemeButton->Visible = settingIsShown;

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
		feedbackButton->Text = BUTTON_HIDE;
	} else {
		this->richTaskList->Size = System::Drawing::Size(TASKLIST_X, TASKLIST_Y_EXTENT);
		numRowsToDisplay = TASKLIST_EXTENT_ROW;
		feedbackButton->Text = BUTTON_SHOW;
	}
	log->log("GUI: feedback is toggled");
	log->log("GUI: taskListBox is displayed");
	displayTasksListBox();
}

void GUI::Interface::toggleHelpTab() {
	this->helpTab->Visible = !this->helpTab->Visible;

	bool helpTabIsVisible = this->helpTab->Visible;
	if (this->helpTab->Visible) {
		helpTabSettingButton->Text = BUTTON_HIDE;
	} else {
		helpTabSettingButton->Text = BUTTON_SHOW;
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

void GUI::Interface::selectTheme(themeColor color) {
	this->BackColor = theme[color]->background;
	this->title->BackColor = theme[color]->background;
	this->title->ForeColor = theme[color]->label;
	this->richTaskList->BackColor = theme[color]->background;
	this->helpTitle->BackColor = theme[color]->background;
	this->helpTitle->ForeColor = theme[color]->label;
	this->settingsTitle->BackColor = theme[color]->background;
	this->settingsTitle->ForeColor = theme[color]->label;
	this->feedbackSetting->ForeColor = theme[color]->label;
	this->helpTabSetting->ForeColor = theme[color]->label;
	this->settingTabSetting->ForeColor = theme[color]->label;
	this->themeSettingLabel->ForeColor = theme[color]->label;
	indexColor = theme[color]->index;

	if (color == WHITE) {
		this->blueThemeButton->Text = BUTTON_THEME_NOT_SELECTED;
		this->whiteThemeButton->Text = BUTTON_THEME_SELECTED;
	} else if (color == BLUE) {
		this->blueThemeButton->Text = BUTTON_THEME_SELECTED;
		this->whiteThemeButton->Text = BUTTON_THEME_NOT_SELECTED;
	}

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

		helpBox->SelectionFont = gcnew System::Drawing::Font(HELP_FONT_HEADING, HELP_SIZE_HEADING, HELP_FONTSTYLE_HEADING());
		helpBox->SelectionColor = HELP_COLOR_HEADING();

		helpBox->SelectedText = heading;
		helpBox->SelectedText = ENDL;
		delete helpBox->SelectionFont;

		helpBox->SelectionFont = gcnew System::Drawing::Font(HELP_FONT_INSTRUCTION, HELP_SIZE_INSTRUCTION, HELP_FONTSTYLE_INSTRUCTION());
		helpBox->SelectionColor = HELP_COLOR_INSTRUCTION();

		helpBox->SelectedText = instruction;
		helpBox->SelectedText = ENDL;
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
	if (task.isToday) {
		richTaskList->SelectionFont = gcnew System::Drawing::Font(TASKLIST_FONT_TASK, TASKLIST_SIZE_INDEX, FontStyle::Bold);
	} else {
		richTaskList->SelectionFont = gcnew System::Drawing::Font(TASKLIST_FONT_TASK, TASKLIST_SIZE_INDEX, FontStyle::Regular);
	}
	richTaskList->SelectionColor = indexColor;
			
	String ^index = gcnew String(task.taskID.c_str());
	richTaskList->SelectedText = TASKLIST_FORMATTING_INDEX;
	richTaskList->SelectedText = index;

	delete richTaskList->SelectionFont;
	delete index;
}

void GUI::Interface::displayTaskInformation(const Task &task) {
	if (task.isToday) {
		richTaskList->SelectionFont = gcnew System::Drawing::Font(TASKLIST_FONT_TASK, TASKLIST_SIZE_TASKINFO, FontStyle::Bold);
	} else {
		richTaskList->SelectionFont = gcnew System::Drawing::Font(TASKLIST_FONT_TASK, TASKLIST_SIZE_TASKINFO, FontStyle::Regular);
	}
	richTaskList->SelectionColor = TASKLIST_COLOR_TASKINFO();

	// ~~Spacing~~
	richTaskList->SelectedText = TABL;
	// - Date
	String ^startDate = gcnew String(task.startDate.c_str());
	richTaskList->SelectedText = startDate;
	// ~~Spacing~~
	richTaskList->SelectedText = TABL;
	// - Time
	String ^startTime = gcnew String(task.startTime.c_str());
	richTaskList->SelectedText = startTime;
	// ~~Spacing~~
	richTaskList->SelectedText = TABL;
	// - Description
	String ^taskName = gcnew String(task.taskName.c_str());
	richTaskList->SelectedText = taskName;
	// ~~NewLine~~
	richTaskList->SelectedText = ENDL;

	delete richTaskList->SelectionFont;
	delete startDate;
	delete startTime;
	delete taskName;
}

void GUI::Interface::displayTodayLabel() {
	richTaskList->SelectionFont = gcnew System::Drawing::Font(TASKLIST_FONT_HEADING, TASKLIST_SIZE_HEADING);
	richTaskList->SelectionColor = TASKLIST_COLOR_HEADING();
	richTaskList->SelectedText = TASKLIST_HEADING_TODAY;

	delete richTaskList->SelectionFont;
}

void GUI::Interface::displayAllTaskLabel() {	
	richTaskList->SelectionFont = gcnew System::Drawing::Font(TASKLIST_FONT_HEADING, TASKLIST_SIZE_HEADING);
	richTaskList->SelectionColor = TASKLIST_COLOR_HEADING();
	richTaskList->SelectedText = TASKLIST_HEADING_ALL;

	delete richTaskList->SelectionFont;
}
