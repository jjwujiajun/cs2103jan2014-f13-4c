#include "Manager.h"
using namespace std;

string WELCOME_MESSAGE = "Hi! Welcome to EasyDone!\r\n";
string USER_PROMPT = "What would you like to do today?\r\n";
string EXIT = "exit";
string FILE_NAME = "storageFile.txt";

Manager::Manager(void) {
	GUIfeedbackBox = "Hi! Welcome to EasyDone!\r\n";
	GUIfeedbackBox += "What would you like to do today?\r\n";			
}


Manager::~Manager(void) {
}

void Manager::receiveInput(string input) {
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

	/* FileHandler to be Deleted!
	 * **********************************
	 * bool isReady = false;
	 * isReady = fileHandler.fileReady(FILE_NAME);
	 *
	 * add: do assert isReady here!
	 * if(isReady) {
	 * **********************************/

		// improve: return by pointer
		parsedInput  = parser.completeParse (userInput);
		feedback = worker.takeparsedCommand(parsedInput);
		
		// set GUITaskList;

		GUIfeedbackBox = feedback;
		GUIfeedbackBox += "What would you like to do today?\r\n";

		GUIInputField = "";
	//}
}
