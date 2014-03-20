#include "Headers.h"
#include "FileHandler.h"
#include "Parser.h"
#include "Worker.h"

using namespace std;

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
	string GUIfeedbackBox;
	string GUIInputField;

	void init();

public:

	Manager(void);
	~Manager(void);

	void receiveInput(string input);
	string getFeedback();
	string getInputField();
	vector<Task> getTaskList();
};
