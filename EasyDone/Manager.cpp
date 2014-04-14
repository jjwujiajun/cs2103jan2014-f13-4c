//@author A0100705Y
//Manager.cpp
#include "Manager.h"

using namespace std;

Manager::Manager(void) {
	log.log("Manager is instanstiated");
	log.endLog();

	log.log("Manager: Format GUITaskList by getTaskList from worker");
	GUITaskList = worker.getTaskList();

	log.log("Manager: Format GUIFeedbackBox to be displayed in GUI");
	GUIfeedbackBox = FEEDBACK_MESSAGE_WELCOME;
	GUIfeedbackBox += FEEDBACK_PROMPT_START;
	log.endLog();

	log.log("Manager: LoadHelpPage");
	loadHelpPage();
	log.log("Manager instantiation end");
	log.endLog();
}


Manager::~Manager(void) {
	delete GUITaskList;
}

void Manager::receiveInput(string input) {

	log.log(LOG_STRING_USERINPUT + input);
	userInput = input;

	log.log("Manager: Start initialising userInput processing");
	try {
		init();
	} catch (string error) {
		throw error;
	}
}

// display
bool Manager::hasFeedbackForGivenInput(const string& input) {
	inputIsSearchQuery = false;
	string text = input.substr(0, 7);
	string textPlus = input.substr(0, 11);

	if(text.find(KEYWORD_ADD) != string::npos) {
		GUIfeedbackBox = LIVE_FEEDBACK_ADD;
		if (input.find(KEYWORD_ON) != string::npos) {
			GUIfeedbackBox += LIVE_FEEDBACK_ADD_HINTDATE;
			GUIfeedbackBox += LIVE_SEARCH_ENTER;
		} else {
			GUIfeedbackBox += LIVE_FEEDBACK_ADD_FORMAT;
		}
		return true;
	} else if (text.find(KEYWORD_DELETE) != string::npos) {
		GUIfeedbackBox = LIVE_FEEDBACK_DELETE;
		GUIfeedbackBox += LIVE_SEARCH_ENTER;
		return true;
	} else if (text.find(KEYWORD_DISPLAY) != string::npos) {
		GUIfeedbackBox = LIVE_FEEDBACK_DISPLAY;
		GUIfeedbackBox += LIVE_SEARCH_ENTER;
		return true;
	} else if (text.find(KEYWORD_UPDATE) != string::npos) {
		GUIfeedbackBox = LIVE_FEEDBACK_UPDATE;
		if (textPlus.find(KEYWORD_TASK) != string::npos) {
			GUIfeedbackBox += LIVE_FEEDBACK_UPDATE_TASK;
			GUIfeedbackBox += LIVE_SEARCH_ENTER;
		} else if (textPlus.find(KEYWORD_STARTDATE) != string::npos ||
			input.find(KEYWORD_ENDDATE) != string::npos ) {
			GUIfeedbackBox += LIVE_FEEDBACK_UPDATE_DATE;
			GUIfeedbackBox += LIVE_SEARCH_ENTER;
		} else if (textPlus.find(KEYWORD_STARTTIME) != string::npos ||
			input.find(KEYWORD_ENDTIME) != string::npos ) {
			GUIfeedbackBox += LIVE_FEEDBACK_UPDATE_TIME;
			GUIfeedbackBox += LIVE_SEARCH_ENTER;
		} else {
			GUIfeedbackBox += LIVE_FEEDBACK_UPDATE_FIELD;
		}
		return true;
	} else if (text.find(KEYWORD_SEARCH) != string::npos) {
		GUIfeedbackBox = LIVE_FEEDBACK_SEARCH;
		if (input.size() > 9) {
			inputIsSearchQuery = true;
		}
		return true;
	} else if (text.find(KEYWORD_DONE) != string::npos) {
		GUIfeedbackBox = LIVE_FEEDBACK_DONE;
		return true;
	}
	GUIfeedbackBox = FEEDBACK_PROMPT_OTHERS;
	return false;
}

bool Manager::checkInputIsSearchQuery() {
	return inputIsSearchQuery;
}

string Manager::getFeedback() {
	return GUIfeedbackBox;
}

string Manager::getInputField() {
	return GUIInputField;
}

// task list functions
vector<Task> Manager::getAllTaskList() {
	log.log("Manager: getTaskList from worker");
	assert(GUITaskList != NULL);
	delete GUITaskList;
	GUITaskList = worker.getTasksUndoneList();

	log.endLog();
	return *GUITaskList;
}

vector<Task> Manager::getDueTaskList() {
	assert(GUITaskList != NULL);
	delete GUITaskList;
	GUITaskList = worker.getTasksOverdueList();
	return *GUITaskList;
}
vector<Task> Manager::getTodayTaskList() {
	assert(GUITaskList != NULL);
	delete GUITaskList;
	GUITaskList = worker.getTasksDueTodayList();
	return *GUITaskList;
}
vector<Task> Manager::getTomorrowTaskList() {
	assert(GUITaskList != NULL);
	delete GUITaskList;
	GUITaskList = worker.getTasksDueTomorrowList();	
	return *GUITaskList;
}

vector<Task> Manager::getDoneTaskList() {
	assert(GUITaskList != NULL);
	delete GUITaskList;
	GUITaskList = worker.getTasksDoneList();
	return *GUITaskList;
}

vector<Task> Manager::getSearchedList() {
	assert(GUITaskList != NULL);
	delete GUITaskList;
	GUITaskList = worker.getSearchedList();
	return *GUITaskList;
}

// start up
vector<string> Manager::getHelpHeadings() {
	return GUIHelpHeadings;
}

vector<string> Manager::getHelpInstructions() {
	return GUIHelpInstructions;
}

void Manager::init() {

	vector<string> parsedInput;
	string feedback;
	string logInput;

	// improve: return by pointer
	log.log(LOG_MANAGER_TO_PARSER);
	try {
		parsedInput  = parser.completeParse (userInput);
	} catch (string error) {
		throw error;
	}

	log.log(LOG_MANAGER_TO_WORKER);
	try {
		feedback = worker.takeParsedCommand(parsedInput);
	} catch (string error) {
		throw error;
	}
		
	// set GUITaskList;
	log.log("Manager: Format GUIFeedback to be displayed in GUI");
	GUIfeedbackBox = feedback;
	GUIfeedbackBox += FEEDBACK_PROMPT_OTHERS;

	log.log("Manager: Format GUIInputField to be displayed in GUI");
	GUIInputField = NULL_STRING;

	log.endLog();
	
}

void Manager::loadHelpPage() {
	string fileName;
	ifstream file;
	string heading;

	log.log("Manager: Clear GUIHelp field");
	GUIHelpHeadings.clear();
	GUIHelpInstructions.clear();
	
	fileHandler.createHelpHeadingInVector(GUIHelpHeadings);
	fileHandler.createHelpInstructionsInVector(GUIHelpInstructions);
}

themeColor Manager::getPresetTheme(){
	return fileHandler.getPresetTheme();
}

void Manager::getPresetSettingFor(bool &feedback, bool &helpTab, bool &settingsTab) {
	feedback = fileHandler.getPresetSetting(FILE_SETTING_FEEDBACK);
	helpTab = fileHandler.getPresetSetting(FILE_SETTING_HELPTAB);
	settingsTab = fileHandler.getPresetSetting(FILE_SETTING_SETTINGSTAB);
}

void Manager::saveTheme(themeColor theme) {
	fileHandler.saveTheme(theme);
}

void Manager::saveFeedbackBoxSetting(bool isOn) {
	fileHandler.saveSettingForFile(isOn, FILE_SETTING_FEEDBACK);
}

void Manager::saveHelpTabSetting(bool isOn) {
	fileHandler.saveSettingForFile(isOn, FILE_SETTING_HELPTAB);
}
void Manager::saveSettingTabSetting(bool isOn) {
	fileHandler.saveSettingForFile(isOn, FILE_SETTING_SETTINGSTAB);
}