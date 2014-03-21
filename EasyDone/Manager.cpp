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