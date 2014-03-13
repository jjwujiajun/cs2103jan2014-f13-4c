#include "Manager.h"
using namespace std;

const string WELCOME_MESSAGE = "Hi! Welcome to EasyDone!";
const string USER_PROMPT = "What would you like to do today?";
const string KEYED_EXIT = "exit";
const string FILE_FORMAT = ".txt";

Manager::Manager(void) {
}


Manager::~Manager(void) {
}

void Manager::receiveInput(string input) {
	_userInput = input;
}

string Manager::getUserInput() {
	return _userInput;
}

void Manager::init() {
 
	bool ready = 0;
	FileHandler Loader;
	Parser ParserJob;
	Worker WorkerJob;
	bool continue_running = true;

	fileName = "storageFile.txt";

//This condition checks if the filename input name contains the correct extension. 
//If not, it by default appends the extension.

	if (fileName.size() > 4 && fileName.substr(fileName.size()-4, fileName.size()) != FILE_FORMAT){
		fileName = fileName + FILE_FORMAT;
	}
	else if (fileName.size() < 4){
		fileName = fileName + FILE_FORMAT;
	}


	while(continue_running)
	{
		ready = Loader.fileReady(fileName);

		if(ready != 0){
	
			while (1)
			{
				cout << WELCOME_MESSAGE;
				cout<< USER_PROMPT<< endl;

				getline(cin, userInput);

				//switch(userCommand)
				if (userInput == KEYED_EXIT){

					continue_running = false;
					break;

				Parser parserJob;
				Worker workerJob;

				vector<string> parsedInput  = parserJob.completeParse (userInput);
				string jobReturn = workerJob.takeparsedCommand(parsedInput);

				cout << jobReturn;
				}
			}
		}
	}
}
