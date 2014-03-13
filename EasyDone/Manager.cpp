#include "Manager.h"
using namespace std;

const string EMPTY = "";
const string WELCOME_MESSAGE = "Hi! Welcome to EasyDone!\n";
const string USER_PROMPT = "What would you like to do today?\n";
const string KEYED_EXIT = "exit";
const string FILE_NAME = "storageFile.txt";

Manager::Manager(void) {
	fileName = FILE_NAME;
	GUIfeedback = EMPTY;
}


Manager::~Manager(void) {
}

void Manager::receiveInput(string input) {
	userInput = input;
}

string Manager::getUserInput() {
	return userInput;
}

void Manager::init() {

	bool isReady = false;
	bool continue_running = true;

	while(continue_running) {
		isReady = fileHandler.fileReady(fileName);

		if(isReady) {
			while (1) {
				GUIfeedback += WELCOME_MESSAGE;
				GUIfeedback += USER_PROMPT;
				
				//switch(userCommand)
				if (userInput == KEYED_EXIT){

					continue_running = false;
					break;

					vector<string> parsedInput  = parser.completeParse (userInput);
					string jobReturn = worker.takeparsedCommand(parsedInput);

					cout << jobReturn;
				}
			}
		}
	}
}
