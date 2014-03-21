#include "Manager.h"

using namespace std;

string MESSAGE_WELCOME = "Hi! Welcome to EasyDone!\r\n";
string USER_PROMPT = "What would you like to do today?\r\n";
string EXIT = "exit";
string FILE_NAME = "storageFile.txt";

Manager::Manager(void) {
	log.clear();

	GUIfeedbackBox = MESSAGE_WELCOME;
	GUIfeedbackBox += "What would you like to do today?\r\n";
}


Manager::~Manager(void) {
}

void Manager::receiveInput(string input) {
	assert(input.size() > 0);
	string logInput = "User input: " + input;
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
	log.log("Manager: Pass userInput to parser");
	parsedInput  = parser.completeParse (userInput);

	try {
	log.log("Manager: Pass parsedInput to worker");
	feedback = worker.takeparsedCommand(parsedInput);
	} catch(int number) {
		 throw 0;
	 }
		
	// set GUITaskList;
	GUIfeedbackBox = feedback;
	GUIfeedbackBox += "What else would you like to do? \r\n";

	GUIInputField = "";

	log.endLog();
	
}