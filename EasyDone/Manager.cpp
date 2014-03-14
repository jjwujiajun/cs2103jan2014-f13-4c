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

string Manager::getFeedback() {
	return GUIfeedbackBox;
}

void Manager::init() {

	vector<string> parsedInput;
	string feedback;

	//bool isReady = false;
	//isReady = fileHandler.fileReady(FILE_NAME);

	// add: do assert isReady here!
	//if(isReady) {
		// improve: return by pointer
		

		parsedInput  = parser.completeParse (userInput);
		
		for(int i=0; i<9; i++)
			parsedInput.push_back("0");
		//cout<<"hereeee"<<parsedInput[0]<< "	"<<parsedInput[1]<<endl;
		feedback = worker.takeparsedCommand(parsedInput);
		
		//GUIfeedbackBox = feedback;
		//GUIfeedbackBox += "What would you like to do today?\r\n";
		cout<<feedback<<endl;
		parser.parserEmpty();
	//}
}
