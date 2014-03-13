#include "Manager.h"
using namespace std;

const string WELCOME_MESSAGE = "Hi! Welcome to EasyDone!";
const string USER_PROMPT = "What would you like to do today?\n";
const string KEYED_EXIT = "exit";
const string FILE_NAME = "storageFile.txt";

Manager::Manager(void) {
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
 
	bool ready = 0;
	FileHandler Loader;
	Parser parserJob;
	Worker workerJob;
	bool continue_running = true;

	fileName = FILE_NAME;

	while(continue_running) {
		ready = Loader.fileReady(fileName);

		if(ready != 0) {
			while (1) {
				cout << WELCOME_MESSAGE;
				cout << USER_PROMPT;
				
				//switch(userCommand)
				if (userInput == KEYED_EXIT){

					continue_running = false;
					break;

					vector<string> parsedInput  = parserJob.completeParse (userInput);
					string jobReturn = workerJob.takeparsedCommand(parsedInput);

					cout << jobReturn;
				}
			}
		}
	}
}
