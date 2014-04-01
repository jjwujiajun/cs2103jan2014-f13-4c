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
}

void Manager::receiveInput(string input) {
	assert(input.size() > 0);
	log.log(LOG_STRING_USERINPUT + input);
	userInput = input;

	log.log("Manager: Start initialising userInput processing");
	init();
}

vector<Task> Manager::getTaskList() {
	log.log("Manager: getTaskList from worker");
	GUITaskList = worker.getTaskList();

	log.endLog();
	return GUITaskList;
}

string Manager::getFeedback() {
	return GUIfeedbackBox;
}

string Manager::getInputField() {
	return GUIInputField;
}

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
	parsedInput  = parser.completeParse (userInput);

	log.log(LOG_MANAGER_TO_WORKER);
	feedback = worker.takeparsedCommand(parsedInput);
		
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

	log.log("Manager: Find help headings .txt file");
	fileName = FILE_HELP_HEADINGS + TYPE_TEXTFILE;
	log.log("Manager: Open file and push_back every line into GUIHelpHeadings");
	file.open(fileName);
	for (int i = 0; i < HELP_NUMBER_OF_SECTIONS; ++i) {
		getline(file, heading);
		GUIHelpHeadings.push_back(heading);
	}
	log.log("Manager: Close file");
	file.close();

	for (int i = 0; i < HELP_NUMBER_OF_SECTIONS; ++i) {
		string instructionParagraph;
		string instructionLine;

		log.log("Manager: Find help instructions[i] .txt file");
		fileName = FILE_HELP_INSTRUCTIONS + to_string(i+1) + TYPE_TEXTFILE;
		log.log("Manager: Open file and concatonate every line into instructionParagraph");
		file.open(fileName);
		getline(file, instructionLine);
		while (getline(file, instructionLine)) {
			instructionParagraph += instructionLine + SYSTEM_ENDL;
		}
		log.log("Manager: push_back instructionParagraph into GUIHelpInstructions");
		GUIHelpInstructions.push_back(instructionParagraph);
		log.log("Manager: Close file");
		file.close();
	}
}

themeColor Manager::getPresetTheme(){
	ifstream presetTheme;
	string fileStoredTheme;
	themeColor theme;

	presetTheme.open(FILE_SETTINGS_THEME);
	getline(presetTheme, fileStoredTheme);

	if (fileStoredTheme == FILE_STRING_BLUETHEME) {
		theme = BLUE;
	} else if (fileStoredTheme == FILE_STRING_METALTHEME) {
		theme = METAL;
	} else {
		theme = WHITE;
	}
	presetTheme.close();
	return theme;
}

bool Manager::getPresetFeedbackToggleSetting() {
	string fileStoredFeedbackSetting;
	ifstream presetFeedback;
	bool setting;

	presetFeedback.open(FILE_SETTING_FEEDBACK);
	getline(presetFeedback, fileStoredFeedbackSetting);

	setting = fileStoredFeedbackSetting == FILE_STRING_TRUE;

	return setting;
}

bool Manager::getPresetHelpTabSetting() {
	string fileStoredHelpTabSetting;
	ifstream presetHelpTab;
	bool setting;

	presetHelpTab.open(FILE_SETTING_HELPTAB);
	getline(presetHelpTab, fileStoredHelpTabSetting);

	setting = fileStoredHelpTabSetting == FILE_STRING_TRUE;

	return setting;
}

bool Manager::getPresetSettingsTabSetting() {
	string fileStoreSettingTabSetting;
	ifstream presetSettingsTab;
	bool setting;

	presetSettingsTab.open(FILE_SETTING_SETTINGSTAB);
	getline(presetSettingsTab, fileStoreSettingTabSetting);

	setting = (fileStoreSettingTabSetting == FILE_STRING_TRUE);

	return setting;
}

void Manager::saveTheme(themeColor theme) {
	ofstream presetTheme;
	string fileStoredTheme;
	presetTheme.open(FILE_SETTINGS_THEME, ios::trunc);

	if (theme == WHITE) {
		presetTheme << FILE_STRING_WHITETHEME << endl;
	} else if (theme == BLUE) {
		presetTheme << FILE_STRING_BLUETHEME << endl;
	} else if (theme == METAL) {
		presetTheme << FILE_STRING_METALTHEME << endl;
	}
}

void Manager::saveFeedbackBoxSetting(bool isOn) {
	ofstream presetFeedbackSetting;
	
	presetFeedbackSetting.open(FILE_SETTING_FEEDBACK, ios::trunc);
	if (isOn) {
		presetFeedbackSetting << FILE_STRING_TRUE;
	} else {
		presetFeedbackSetting << FILE_STRING_FALSE;
	}
}

void Manager::saveHelpTabSetting(bool isOn) {
	ofstream presetHelpTabSetting;

	presetHelpTabSetting.open(FILE_SETTING_HELPTAB, ios::trunc);
	if (isOn) {
		presetHelpTabSetting << FILE_STRING_TRUE;
	} else {
		presetHelpTabSetting << FILE_STRING_FALSE;
	}
}
void Manager::saveSettingTabSetting(bool isOn) {
	ofstream presetSettingsTabSetting;

	presetSettingsTabSetting.open(FILE_SETTING_SETTINGSTAB, ios::trunc);
	if (isOn) {
		presetSettingsTabSetting << FILE_STRING_TRUE;
	} else {
		presetSettingsTabSetting << FILE_STRING_FALSE;
	}
}