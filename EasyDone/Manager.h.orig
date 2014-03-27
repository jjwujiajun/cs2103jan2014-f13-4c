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

	// GUI displays
	string GUITaskList;
	string GUIfeedbackBox;
	string GUIInputField;

	void init();

public:

	Manager(void);
	~Manager(void);

	void receiveInput(string input);
	string getTaskList();
	string getFeedback();
	string getInputField();
};
