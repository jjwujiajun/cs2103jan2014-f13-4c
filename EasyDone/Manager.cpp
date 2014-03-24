#include "Manager.h"

using namespace std;

Manager::Manager(void) {
	log.clear();

	GUIfeedbackBox = FEEDBACK_MESSAGE_WELCOME;
	GUIfeedbackBox += FEEDBACK_PROMPT_START;

	loadHelpPage();
}


Manager::~Manager(void) {
}

void Manager::receiveInput(string input) {
	assert(input.size() > 0);
	string logInput = LOG_STRING_USERINPUT + input;
	log.log(logInput);

	userInput = input;
	init();
}

vector<Task>& Manager::getTaskList() {
	GUITaskList = worker.getTaskList();
	return GUITaskList;
}

string& Manager::getFeedback() {
	return GUIfeedbackBox;
}

string& Manager::getInputField() {
	return GUIInputField;
}

vector<string>& Manager::getHelpHeadings() {
	return GUIHelpHeadings;
}

vector<string>& Manager::getHelpInstructions() {
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
	GUIfeedbackBox = feedback;
	GUIfeedbackBox += FEEDBACK_PROMPT_OTHERS;

	GUIInputField = NULL_STRING;

	log.endLog();
	
}

void Manager::loadHelpPage() {
	string fileName;
	ifstream file;
	string heading;

	GUIHelpHeadings.clear();
	GUIHelpInstructions.clear();

	fileName = HELP_FILE_HEADINGS + TYPE_TEXTFILE;
	file.open(fileName);
	for (int i = 0; i < HELP_NUMBER_OF_SECTIONS; ++i) {
		getline(file, heading);
		GUIHelpHeadings.push_back(heading);
	}
	file.close();

	for (int i = 0; i < HELP_NUMBER_OF_SECTIONS; ++i) {
		string instructionParagraph;
		string instructionLine;

		fileName = HELP_FILE_INSTRUCTIONS + to_string(i+1) + TYPE_TEXTFILE;
		file.open(fileName);
		getline(file, instructionLine);
		while (getline(file, instructionLine)) {
			instructionParagraph += instructionLine + SYSTEM_ENDL;
		}
		GUIHelpInstructions.push_back(instructionParagraph);
		file.close();
	}
}