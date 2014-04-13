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
	log->log("GUI: Load in all the preset theme colors");
	theme = prepareThemes();
	
	log->log("GUI: Set numRowsToDisplay to 20 lines");
	log->log("GUI: display taskListBox, feedbackBox");
	pageNumber = 0;
	numRowsToDisplay = TASKLIST_RETRACT_ROW;
	displaySummaryTaskListBox();
	displayFeedbackBox();
	summaryTaskListIsShown = true;
	allTaskListIsShown = false;
	doneTaskListIsShown = false;

	log->log("GUI: Hide windowIsExtend, helpIsShow, settingIsShown");
	windowIsExtended = false;
	helpIsShown = false;
	settingIsShown = false;

	bool feedbackSetting;
	bool helpTabSetting;
	bool settingTabSetting;

	color = manager->getPresetTheme();
	manager->getPresetSettingFor(feedbackSetting, helpTabSetting, settingTabSetting);

	feedbackIsVisible = feedbackSetting;
	helpTabIsVisible = helpTabSetting;
	settingsTabIsVisible = settingTabSetting;

	selectTheme(color);
	if (!feedbackIsVisible) toggleFeedback();
	if (!helpTabIsVisible) toggleHelpTab();
	if (!settingsTabIsVisible) toggleSettingsTab();

	log->log("GUI: get helpBox display");
	getHelpBoxDisplay(); // comes at the end because it depends on selected theme.

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
	if (inputField->Text == "exit") {
		Application::Exit();
		return;
	}

	log->log("GUI: receiveUserInput");
	receiveUserInput();

	log->log("GUI: display taskListBox, feedbackBox, inputField");
	if (summaryTaskListIsShown) {
		displaySummaryTaskListBox();
	} else if (allTaskListIsShown) {
		vector<Task> listToBeDisplayed = showSelectedPageOfTasklist(manager->getAllTaskList());
		displayTasksListBoxUsingList(listToBeDisplayed);
	} else if (doneTaskListIsShown) {
		vector<Task> listToBeDisplayed = showSelectedPageOfTasklist(manager->getDoneTaskList());
		displayTasksListBoxUsingList(listToBeDisplayed);
	}
	displayFeedbackBox();

	log->endLog();
}

void GUI::Interface::operateUserSearchRequest() {
	log->log("GUI: receiveUserInput");
	receiveUserInput();

	log->log("GUI: display taskListBox, feedbackBox, inputField");
	vector<Task> listToBeDisplayed = showSelectedPageOfTasklist(manager->getSearchedList());
	displayTasksListBoxUsingList(listToBeDisplayed); 
}

void GUI::Interface::showLiveFeedback() {
	if (isSearching) {
		operateUserSearchRequest();
		displayFeedbackBox();
	}
	string receivedFeedbackToDisplay;
	String ^feedbackToDisplay;

	receivedFeedbackToDisplay = manager->getFeedback();
	convertStdToSysString(receivedFeedbackToDisplay, feedbackToDisplay);
	feedbackBox->Text = feedbackToDisplay;
}

void GUI::Interface::togglePaneLeft() {
	pageNumber = 0;
	if (summaryTaskListIsShown) {
		switchToDoneTaskListDisplay();
	} else if (allTaskListIsShown) {
		switchToSummaryTaskListDisplay();
	} else if (doneTaskListIsShown) {
		switchToAllTaskListDisplay();
	}
}

void GUI::Interface::togglePaneRight() {
	pageNumber = 0;
	if (summaryTaskListIsShown) {
		switchToAllTaskListDisplay();
	} else if (allTaskListIsShown) {
		switchToDoneTaskListDisplay();
	} else if (doneTaskListIsShown) {
		switchToSummaryTaskListDisplay();
	}
}

void GUI::Interface::switchToSummaryTaskListDisplay() {
	summaryTaskListIsShown = true;
	allTaskListIsShown = false;
	doneTaskListIsShown = false;

	displaySummaryTaskListBox();
	this->title->Text = TITLE_SUMMARY;

	this->radioDotSummary->ForeColor = theme[color]->label;
	this->radioDotAll->ForeColor = theme[color]->words;
	this->radioDotDone->ForeColor = theme[color]->words;
}

void GUI::Interface::switchToAllTaskListDisplay() {
	summaryTaskListIsShown = false;
	allTaskListIsShown = true;
	doneTaskListIsShown = false;

	vector<Task> listToBeDisplayed = showSelectedPageOfTasklist(manager->getAllTaskList());
	displayTasksListBoxUsingList(listToBeDisplayed);	
	this->title->Text = TITLE_ALLTASKS;

	this->radioDotSummary->ForeColor = theme[color]->words;
	this->radioDotAll->ForeColor = theme[color]->label;
	this->radioDotDone->ForeColor = theme[color]->words;
}

void GUI::Interface::switchToDoneTaskListDisplay() {
	summaryTaskListIsShown = false;
	allTaskListIsShown = false;
	doneTaskListIsShown = true;

	vector<Task> listToBeDisplayed = showSelectedPageOfTasklist(manager->getDoneTaskList());
	displayTasksListBoxUsingList(listToBeDisplayed);
	this->title->Text = TITLE_DONETASKS;

	this->radioDotSummary->ForeColor = theme[color]->words;
	this->radioDotAll->ForeColor = theme[color]->words;
	this->radioDotDone->ForeColor = theme[color]->label;
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

// window opening functions
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
	this->metalThemeLabel->Visible = settingIsShown;
	this->whiteThemeButton->Visible = settingIsShown;
	this->blueThemeButton->Visible = settingIsShown;
	this->metalThemeButton->Visible = settingIsShown;

	if (settingIsShown) {
		this->settingsTab->BackColor = TAB_SELECTED_COLOUR();
	} else {
		this->settingsTab->BackColor = TAB_NOT_SELECTED_COLOUR();
	}

	log->log("GUI: setting section is toggled");
}

// setting selection functions
void GUI::Interface::toggleFeedback() {
	feedbackIsVisible = !feedbackIsVisible;
	
	if (feedbackIsVisible) {
		this->feedbackBox->Hide();
		this->richTaskList->Size = System::Drawing::Size(TASKLIST_X, TASKLIST_Y_EXTENT);
		this->radioDotSummary->Location = System::Drawing::Point(RADIO_X_SUMMARY, RADIO_Y_EXTENT);
		this->radioDotAll->Location = System::Drawing::Point(RADIO_X_ALL, RADIO_Y_EXTENT);
		this->radioDotDone->Location = System::Drawing::Point(RADIO_X_DONE, RADIO_Y_EXTENT);
		this->toggleLeftPaneLabel->Location = System::Drawing::Point(HELP_TOGGLE_LEFT_LABEL_X, HELP_TOGGLE_LABEL_EXTENT_Y);
		this->toggleRightPaneLabel->Location = System::Drawing::Point(HELP_TOGGLE_RIGHT_LABEL_X, HELP_TOGGLE_LABEL_EXTENT_Y);
		numRowsToDisplay = TASKLIST_EXTENT_ROW;
		feedbackButton->Text = BUTTON_SHOW;
		manager->saveFeedbackBoxSetting(false);
	} else {
		this->feedbackBox->Show();
		this->richTaskList->Size = System::Drawing::Size(TASKLIST_X, TASKLIST_Y_RETRACT);
		this->radioDotSummary->Location = System::Drawing::Point(RADIO_X_SUMMARY, RADIO_Y_RETRACT);
		this->radioDotAll->Location = System::Drawing::Point(RADIO_X_ALL, RADIO_Y_RETRACT);
		this->radioDotDone->Location = System::Drawing::Point(RADIO_X_DONE, RADIO_Y_RETRACT);
		this->toggleLeftPaneLabel->Location = System::Drawing::Point(HELP_TOGGLE_LEFT_LABEL_X, HELP_TOGGLE_LABEL_RETRACT_Y);
		this->toggleRightPaneLabel->Location = System::Drawing::Point(HELP_TOGGLE_RIGHT_LABEL_X, HELP_TOGGLE_LABEL_RETRACT_Y);
		numRowsToDisplay = TASKLIST_RETRACT_ROW;
		feedbackButton->Text = BUTTON_HIDE;
		manager->saveFeedbackBoxSetting(true);
	}
	log->log("GUI: feedback is toggled");
	log->log("GUI: taskListBox is displayed");
	if (summaryTaskListIsShown) {
		displaySummaryTaskListBox();
	} else if (allTaskListIsShown) {
		vector<Task> listToBeDisplayed = showSelectedPageOfTasklist(manager->getAllTaskList());
		displayTasksListBoxUsingList(listToBeDisplayed);
	} else if (doneTaskListIsShown) {
		vector<Task> listToBeDisplayed = showSelectedPageOfTasklist(manager->getDoneTaskList());
		displayTasksListBoxUsingList(listToBeDisplayed);
	}
}

void GUI::Interface::toggleHelpTab() {
	helpTabIsVisible = !helpTabIsVisible;
	
	if (helpTabIsVisible) {
		this->helpTab->Hide();
		this->toggleLeftPaneLabel->Hide();
		this->toggleRightPaneLabel->Hide();
		helpTabSettingButton->Text = BUTTON_SHOW;
		manager->saveHelpTabSetting(false);
	} else {
		this->helpTab->Show();
		this->toggleLeftPaneLabel->Show();
		this->toggleRightPaneLabel->Show();
		helpTabSettingButton->Text = BUTTON_HIDE;
		manager->saveHelpTabSetting(true);
	}
	log->log("GUI: helpTab is toggled");
}

void GUI::Interface::toggleSettingsTab() {
	settingsTabIsVisible = !settingsTabIsVisible;
	
	if (settingsTabIsVisible) {
		this->settingsTab->Hide();
		settingsTabSettingButton->Text = "Show";
		manager->saveSettingTabSetting(false);
	} else {
		this->settingsTab->Show();
		settingsTabSettingButton->Text = "Hide";
		manager->saveSettingTabSetting(true);
	}
	log->log("GUI: settingsTab is toggled");
}

void GUI::Interface::toggleTheme() {
	if (this->BackColor == theme[WHITE]->background) {
		selectTheme(BLUE);
	} else if (this->BackColor == theme[BLUE]->background) {
		selectTheme(METAL);
	} else if (this->BackColor == theme[METAL]->background) {
		selectTheme(WHITE);
	}
}

void GUI::Interface::selectTheme(themeColor color) {
	this->BackColor = theme[color]->background;
	this->title->BackColor = theme[color]->background;
	this->title->ForeColor = theme[color]->label;
	this->richTaskList->BackColor = theme[color]->background;
	this->helpTitle->BackColor = theme[color]->background;
	this->helpTitle->ForeColor = theme[color]->label;
	this->helpIntro->BackColor = theme[color]->background;
	this->helpBox->BackColor = theme[color]->background;
	this->settingsTitle->BackColor = theme[color]->background;
	this->settingsTitle->ForeColor = theme[color]->label;
	this->feedbackSetting->ForeColor = theme[color]->label;
	this->helpTabSetting->ForeColor = theme[color]->label;
	this->settingTabSetting->ForeColor = theme[color]->label;
	this->themeSettingLabel->ForeColor = theme[color]->label;
	this->IDLabel->ForeColor = theme[color]->label;
	this->dateLabel->ForeColor = theme[color]->label;
	this->timeLabel->ForeColor = theme[color]->label;
	this->taskLabel->ForeColor = theme[color]->label;
	this->radioDotAll->BackColor = theme[color]->background;
	this->radioDotSummary->BackColor = theme[color]->background;
	this->radioDotDone->BackColor = theme[color]->background;
	this->color = color;

	if (color == WHITE) {
		this->blueThemeButton->Text = BUTTON_THEME_NOT_SELECTED;
		this->whiteThemeButton->Text = BUTTON_THEME_SELECTED;
		this->metalThemeButton->Text = BUTTON_THEME_NOT_SELECTED;
		manager->saveTheme(WHITE);
	} else if (color == BLUE) {
		this->blueThemeButton->Text = BUTTON_THEME_SELECTED;
		this->whiteThemeButton->Text = BUTTON_THEME_NOT_SELECTED;
		this->metalThemeButton->Text = BUTTON_THEME_NOT_SELECTED;
		manager->saveTheme(BLUE);
	} else if (color == METAL) {
		this->blueThemeButton->Text = BUTTON_THEME_NOT_SELECTED;
		this->whiteThemeButton->Text = BUTTON_THEME_NOT_SELECTED;
		this->metalThemeButton->Text = BUTTON_THEME_SELECTED;
		manager->saveTheme(METAL);
	}
	if (summaryTaskListIsShown) {
		displaySummaryTaskListBox();
		radioDotAll->ForeColor = theme[color]->words;
		radioDotSummary->ForeColor = theme[color]->label;
		radioDotDone->ForeColor = theme[color]->words;
	} else if (allTaskListIsShown) {
		vector<Task> listToBeDisplayed = showSelectedPageOfTasklist(manager->getAllTaskList());
		displayTasksListBoxUsingList(listToBeDisplayed);
		radioDotAll->ForeColor = theme[color]->label;
		radioDotSummary->ForeColor = theme[color]->words;
		radioDotDone->ForeColor = theme[color]->words;
	} else if (doneTaskListIsShown) {
		vector<Task> listToBeDisplayed = showSelectedPageOfTasklist(manager->getDoneTaskList());
		displayTasksListBoxUsingList(listToBeDisplayed);
		radioDotAll->ForeColor = theme[color]->words;
		radioDotSummary->ForeColor = theme[color]->words;
		radioDotDone->ForeColor = theme[color]->label;
	}
	getHelpBoxDisplay();
}

// window level display function
void GUI::Interface::activateHelpPage() {
	log->log("User: F1 is pressed, toggleHelpSetion()");
	if (windowIsExtended) {
		if (helpIsShown) retractWindow();
		else toggleSettingSection();
	} 
	else extendWindow();

	toggleHelpSection();
}

void GUI::Interface::activateSettingsPage() {
	log->log("User: F2 is pressed, toggleSettingSection()");
	if (windowIsExtended) {
		if (helpIsShown) toggleHelpSection();
		else retractWindow();
	}
	else extendWindow();

	toggleSettingSection();
}

// display functions
vector<Task> GUI::Interface::showSelectedPageOfTasklist(vector<Task> tasklist) {
	vector<vector<Task>> arrayOfPages;
	vector<Task> page;
	int taskIndex = 0;
	int numRowsToDisplayHere;

	if(isSearching) {
		numRowsToDisplayHere = numRowsToDisplay/2;
	} else {
		numRowsToDisplayHere = numRowsToDisplay;
	}

	while (taskIndex < tasklist.size()) {
		page.clear();
		for (int i = 0; i < numRowsToDisplayHere && taskIndex < tasklist.size(); ++i) {
			page.push_back(tasklist[taskIndex]);
			++taskIndex;
		}
		arrayOfPages.push_back(page);
	}
	if (pageNumber >= arrayOfPages.size()) {
		pageNumber = arrayOfPages.size() - 1;
	}

	if (pageNumber >= 0) {
		return arrayOfPages[pageNumber];
	}
	return tasklist;
}

void GUI::Interface::displayNormalInterfaceState() {
	log->log("User: No input, show normal texts");
	if (summaryTaskListIsShown) {
		displaySummaryTaskListBox();
	} else if (allTaskListIsShown) {
		vector<Task> listToBeDisplayed = showSelectedPageOfTasklist(manager->getAllTaskList());
		displayTasksListBoxUsingList(listToBeDisplayed);
	} else if (doneTaskListIsShown) {
		vector<Task> listToBeDisplayed = showSelectedPageOfTasklist(manager->getDoneTaskList());
		displayTasksListBoxUsingList(listToBeDisplayed);
	}
	String ^convertedFeedback;
	string feedback = manager->getFeedback();
	convertStdToSysString(feedback, convertedFeedback);
	feedbackBox->Text = convertedFeedback;
}

void GUI::Interface::displayTasksListBoxUsingList(const vector<Task>& receivedTaskList) {
	int i = 0;
	bool isLastRow;
	bool isShowingEndTime;
	if (isSearching) {
		isShowingEndTime = true;
	} else {
		if (summaryTaskListIsShown) {
			isShowingEndTime = true;
		} else {
			isShowingEndTime = false;
		}
	}

	richTaskList->Clear();

	while (i < (int)receivedTaskList.size() && i < numRowsToDisplay) {
		isLastRow = (i == (int) receivedTaskList.size()-1 || i == numRowsToDisplay-1);
		displayTask(receivedTaskList[i], isLastRow, isShowingEndTime);
		i++;
	}
}

void GUI::Interface::displaySummaryTaskListBox() {
	std::vector<Task> receivedDueTaskList = manager->getDueTaskList();;
	std::vector<Task> receivedTodayTaskList = manager->getTodayTaskList();
	std::vector<Task> receivedTomorrowTaskList = manager->getTomorrowTaskList();
	int taskListBoxRow = 0;
	int numRowsToDisplayForSummary = numRowsToDisplay;
	bool isLastRow;
	bool isSummaryDisplay = summaryTaskListIsShown;
	int i = 0;

	richTaskList->Clear();

	displayTodayLabel();
	++taskListBoxRow;
	if (receivedTodayTaskList.empty()) {
		richTaskList->SelectionFont = gcnew System::Drawing::Font(TASKLIST_FONT_TASK, TASKLIST_SIZE_TASKINFO, FontStyle::Regular);
		richTaskList->SelectionColor = theme[color]->words;
		richTaskList->SelectedText = "No task today :)\n";
		++taskListBoxRow;
	} else {
		while (i < (int)receivedTodayTaskList.size() && taskListBoxRow < numRowsToDisplayForSummary) {
			isLastRow = taskListBoxRow == numRowsToDisplayForSummary-1;
			displayTask(receivedTodayTaskList[i], isLastRow, isSummaryDisplay);
			taskListBoxRow += 2;
			++i;
		}
	}
	if (taskListBoxRow < numRowsToDisplayForSummary) {
		displayTomorrowLabel();
		++taskListBoxRow;
	}
	if (receivedTomorrowTaskList.empty() && taskListBoxRow < numRowsToDisplayForSummary) {
		richTaskList->SelectionFont = gcnew System::Drawing::Font(TASKLIST_FONT_TASK, TASKLIST_SIZE_TASKINFO, FontStyle::Regular);
		richTaskList->SelectionColor = theme[color]->words;
		richTaskList->SelectedText = "No task tomorrow :)\n";
		++taskListBoxRow;
	} else {
		i = 0;
		while (i < (int)receivedTomorrowTaskList.size() && taskListBoxRow < numRowsToDisplayForSummary) {
			isLastRow = taskListBoxRow == numRowsToDisplayForSummary-1;
			displayTask(receivedTomorrowTaskList[i], isLastRow, isSummaryDisplay);
			taskListBoxRow += 2;
			++i;
		}
	}

	if (!receivedDueTaskList.empty() && taskListBoxRow < numRowsToDisplayForSummary) {
		displayDueLabel();
		i = 0;
		while (i < (int)receivedDueTaskList.size() && taskListBoxRow < numRowsToDisplayForSummary) {
			isLastRow = taskListBoxRow == numRowsToDisplayForSummary-1;
			displayTask(receivedDueTaskList[i], isLastRow, !isSummaryDisplay);
			++taskListBoxRow;
			++i;
		}
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
	helpBox->Clear();
	
	for (int i = 0; i < HELP_NUMBER_OF_SECTIONS; ++i) {
		String ^heading;
		String ^instruction;
		convertStdToSysString(helpHeadings[i], heading);
		convertStdToSysString(helpInstructions[i], instruction);

		helpBox->SelectionFont = gcnew System::Drawing::Font(HELP_FONT_HEADING, HELP_SIZE_HEADING, HELP_FONTSTYLE_HEADING());
		helpBox->SelectionColor = theme[color]->label;

		helpBox->SelectedText = heading;
		helpBox->SelectedText = ENDL;
		delete helpBox->SelectionFont;

		helpBox->SelectionFont = gcnew System::Drawing::Font(HELP_FONT_INSTRUCTION, HELP_SIZE_INSTRUCTION, HELP_FONTSTYLE_INSTRUCTION());
		helpBox->SelectionColor = HELP_COLOR_INSTRUCTION();

		helpBox->SelectedText = instruction;
		if (i != HELP_NUMBER_OF_SECTIONS-1) {
			helpBox->SelectedText = ENDL;
		}
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
void GUI::Interface::displayTask(const Task &task, const bool &isLastRow, const bool& isSummaryPane) {
	displayTaskIndex(task);
	if (isSummaryPane) {
		displayTaskInformation(task, false);
		displayTaskExtraInformation(task, isLastRow);
	} else {
		displayTaskInformation(task, isLastRow);
	}
}

void GUI::Interface::displayTaskIndex(const Task &task) {
	richTaskList->SelectionFont = gcnew System::Drawing::Font(TASKLIST_FONT_TASK, TASKLIST_SIZE_INDEX, TASKLIST_FONTSTYLE_INDEX());
	richTaskList->SelectionColor = theme[color]->index;
			
	String ^index = gcnew String(task.taskID.c_str());
	richTaskList->SelectedText = TASKLIST_FORMATTING_INDEX + index;

	delete richTaskList->SelectionFont;
	delete index;
}

void GUI::Interface::displayTaskInformation(const Task &task, const bool &isLastRow) {
	if (task.isBold) {
		richTaskList->SelectionFont = gcnew System::Drawing::Font(TASKLIST_FONT_TASK, TASKLIST_SIZE_TASKINFO, FontStyle::Bold);
	} else {
		richTaskList->SelectionFont = gcnew System::Drawing::Font(TASKLIST_FONT_TASK, TASKLIST_SIZE_TASKINFO, FontStyle::Regular);
	}
	if (task.isRed) {
		richTaskList->SelectionColor = TASK_OVERDUE();
	} else {
		richTaskList->SelectionColor = theme[color]->words;
	}
	// ~~Spacing~~
	richTaskList->SelectedText = TABL;
	// - Date
	String ^endDate = gcnew String(task.endDate.c_str());
	String ^startDate = gcnew String(task.startDate.c_str());
	if (isSearchingEndTime) {
		richTaskList->SelectedText = endDate;
	} else {
		richTaskList->SelectedText = startDate;
	}
	// ~~Spacing~~
	richTaskList->SelectedText = TABL;
	// - Time
	String ^endTime = gcnew String(task.endTime.c_str());
	String ^startTime = gcnew String(task.startTime.c_str());
	if (isSearchingEndTime) {
		richTaskList->SelectedText = endTime;
	} else {
		richTaskList->SelectedText = startTime;
	}
	// ~~Spacing~~
	richTaskList->SelectedText = TABL;
	// - Description
	String ^taskName = gcnew String(task.taskName.c_str());
	richTaskList->SelectedText = taskName;
	// ~~NewLine~~
	if (!isLastRow) {
		richTaskList->SelectedText = ENDL;
	}

	delete richTaskList->SelectionFont;
	delete startDate;
	delete startTime;
	delete endTime;
	delete endDate;
	delete taskName;
}

void GUI::Interface::displayTaskExtraInformation(const Task& task, const bool& isLastRow) {
	if (task.isBold) {
		richTaskList->SelectionFont = gcnew System::Drawing::Font(TASKLIST_FONT_TASK, TASKLIST_SIZE_TASKINFO, FontStyle::Bold);
	} else {
		richTaskList->SelectionFont = gcnew System::Drawing::Font(TASKLIST_FONT_TASK, TASKLIST_SIZE_TASKINFO, FontStyle::Regular);
	}
	//if (task.isRed) {
		//richTaskList->SelectionColor = TASK_OVERDUE();
	//} else {
		richTaskList->SelectionColor = theme[color]->words;
	//}

	// ~~Spacing~~
	richTaskList->SelectedText = TABL;
	// - Date
	String ^endDate = gcnew String(task.endDate.c_str());
	richTaskList->SelectedText = endDate;
	// ~~Spacing~~
	richTaskList->SelectedText = TABL;
	// - Time
	String ^endTime = gcnew String(task.endTime.c_str());
	richTaskList->SelectedText = endTime;
	// ~~NewLine~~
	if (!isLastRow) {
		richTaskList->SelectedText = ENDL;
	}

	delete richTaskList->SelectionFont;
	delete endDate;
	delete endTime;
}

void GUI::Interface::displayTodayLabel() {
	richTaskList->SelectionFont = gcnew System::Drawing::Font(TASKLIST_FONT_HEADING, TASKLIST_SIZE_HEADING);
	richTaskList->SelectionColor = theme[color]->taskListHeadings;
	richTaskList->SelectedText = TASKLIST_HEADING_TODAY;

	delete richTaskList->SelectionFont;
}

void GUI::Interface::displayTomorrowLabel() {	
	richTaskList->SelectionFont = gcnew System::Drawing::Font(TASKLIST_FONT_HEADING, TASKLIST_SIZE_HEADING);
	richTaskList->SelectionColor = theme[color]->taskListHeadings;
	richTaskList->SelectedText = TASKLIST_HEADING_TOMORROW;

	delete richTaskList->SelectionFont;
}

void GUI::Interface::displayDueLabel() {	
	richTaskList->SelectionFont = gcnew System::Drawing::Font(TASKLIST_FONT_HEADING, TASKLIST_SIZE_HEADING);
	richTaskList->SelectionColor = theme[color]->taskListHeadings;
	richTaskList->SelectedText = TASKLIST_HEADING_DUE;

	delete richTaskList->SelectionFont;
}