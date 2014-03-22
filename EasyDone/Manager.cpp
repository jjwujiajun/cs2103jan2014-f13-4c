#include "Manager.h"

using namespace std;

Manager::Manager(void) {
	log.clear();

	GUIfeedbackBox = FEEDBACK_MESSAGE_WELCOME;
	GUIfeedbackBox += FEEDBACK_PROMPT_START;
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

vector<Task> Manager::getTaskList() {
	return worker.getTaskList();
}

string Manager::getFeedback() {
	return GUIfeedbackBox;
}

string Manager::getInputField() {
	return GUIInputField;
}

vector<string> Manager::getHelpHeadings() {
	ifstream headingFile("helpHeadings.txt");
	vector<string> helpHeadings;
	string heading;

	for (int i = 0; i < HELP_NUMBER_OF_SECTIONS; ++i) {
		getline(headingFile, heading);
		helpHeadings.push_back(heading);
	}
	headingFile.close();

	return helpHeadings;
}

vector<string> Manager::getHelpInstructions() {
	ifstream instructionFile;
	vector<string> helpInstructions;
	string fileName;

	for (int i = 0; i < HELP_NUMBER_OF_SECTIONS; ++i) {
		string instructionParagraph;
		string instructionLine;

		fileName = "helpInstruction" + to_string(i+1) + ".txt";
		instructionFile.open(fileName);
		getline(instructionFile, instructionLine);
		while (getline(instructionFile, instructionLine)) {
			instructionParagraph += instructionLine + "\r\n";
		}
		helpInstructions.push_back(instructionParagraph);
		instructionFile.close();
	}

	return helpInstructions;
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