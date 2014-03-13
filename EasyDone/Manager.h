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

	// GUI displays
	string GUIfeedbackBox;

	//others
	string userInput;

public:

	Manager(void);
	~Manager(void);

	void init();
	void receiveInput(string input);
	string getFeedback();
};
