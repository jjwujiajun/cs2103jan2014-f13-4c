#include "Manager.h"
using namespace std;

string WELCOME_MESSAGE = "Hi! Welcome to EasyDone!\r\n";
string USER_PROMPT = "What would you like to do today?\r\n";
string EXIT = "exit";
string FILE_NAME = "storageFile.txt";

Manager::Manager(void) {
	log.clear();

	GUIfeedbackBox = "Hi! Welcome to EasyDone!\r\n";
	GUIfeedbackBox += "What would you like to do today?\r\n";
}


Manager::~Manager(void) {
}

void Manager::receiveInput(string input) {
	string logInput = "User input: " + input;
	log.log(logInput);

	userInput = input;
	init();
}

string Manager::getTaskList() {
	return GUITaskList;
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

	/* FileHandler to be Deleted!
	 * **********************************
	 * bool isReady = false;
	 * isReady = fileHandler.fileReady(FILE_NAME);
	 *
	 * add: do assert isReady here!
	 * if(isReady) {
	 * **********************************/

		// improve: return by pointer
		log.log("Manager: Pass userInput to parser");
		parsedInput  = parser.completeParse (userInput);

		log.log("Manager: Pass parsedInput to worker");
		feedback = worker.takeparsedCommand(parsedInput);
		
		// set GUITaskList;

		GUIfeedbackBox = feedback;
		GUIfeedbackBox += "What else would you like to do? \r\n";

		GUIInputField = "";
	//}
}