#include "Headers.h"
#include "FileHandler.h"
#include "Parser.h"
#include "Worker.h"

using namespace std;

const string FEEDBACK_MESSAGE_WELCOME = "Hi! Welcome to EasyDone!\r\n";
const string FEEDBACK_PROMPT_START = "What would you like to do today?\r\n";
const string FEEDBACK_PROMPT_OTHERS = "What else would you like to do? \r\n";
const string LOG_MANAGER_TO_PARSER = "Manager: Pass userInput to parser";
const string LOG_MANAGER_TO_WORKER = "Manager: Pass parsedInput to worker";
const string LOG_STRING_USERINPUT = "User input: ";
const int HELP_NUMBER_OF_SECTIONS = 4;
const string HELP_FILE_HEADINGS = "helpHeadings";
const string HELP_FILE_INSTRUCTIONS = "helpInstruction";
const string TYPE_TEXTFILE = ".txt";
const string SYSTEM_ENDL = "\r\n";
const string NULL_STRING = "";

#pragma once
class Manager {
private:
	
	// member classes
	FileHandler fileHandler;
	Parser parser;
	Worker worker;
	string userInput;
	Log log;

	// GUI displays
	vector<Task> GUITaskList;
	string GUIfeedbackBox;
	string GUIInputField;
	vector<string> GUIHelpHeadings;
	vector<string> GUIHelpInstructions;

	void init();
	void loadHelpPage();

public:

	Manager(void);
	~Manager(void);

	void receiveInput(string input);
	string& getFeedback();
	string& getInputField();
	vector<Task>& getTaskList();
	vector<string>& getHelpHeadings();
	vector<string>& getHelpInstructions();
};
