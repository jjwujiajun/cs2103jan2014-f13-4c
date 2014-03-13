#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include "Parser.h"
#include "Worker.h"
#include "FileHandler.h"

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

	int indexOfTask;
	string contentToBeUpdated;
	string userInput;
	string taskName;
	string additionalDetails;
	//string reminder;
	//string duplciate;		//whats a duplicate
	string startDate;
	string startTime;
	string endDate;
	string endTime;
	string isCompleted;		// '1': task completed '0':not completed
	vector<string> detailsFromParser;
	//bool hasTimeSlot;		//true if timeslot is available, false if timeslot is occupied

	string outputMessage;
	string KeyWord;
	vector<string> toBeDisplayed;
	string fieldToBeUpdated;

public:

	Manager(void);
	~Manager(void);

	void init();
	void receiveInput(string);
	string getFeedback();
};

/*







*/