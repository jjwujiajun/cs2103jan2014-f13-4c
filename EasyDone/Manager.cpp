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

vector<Task> Manager::getAllTaskList() {
	log.log("Manager: getTaskList from worker");
	GUITaskList = worker.getTaskList();

	log.endLog();
	return GUITaskList;
}

vector<Task> Manager::getDueTaskList() {
	vector<Task> temp;
	return temp;
}
vector<Task> Manager::getTodayTaskList() {
	return worker.getTasksDueTodayList();
}
vector<Task> Manager::getTomorrowTaskList() {
	return worker.getTasksDueTomorrowList();
}

vector<Task> Manager::getSearchedList() {
	return worker.getSearchedList();
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