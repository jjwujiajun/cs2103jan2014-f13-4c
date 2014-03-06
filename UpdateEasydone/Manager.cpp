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

	using namespace std;

	int index;
	string userInput;
    string taskName;
	string additionalDetails;
	string reminder;
	//string duplciate;		//whats a duplicate
	int startDate;
	int startTime;
	int endDate;
	int endTime;
	bool isCompleted;		// true is task is completed
    //bool hasTimeSlot;		//true if timeslot is available, false if timeslot is occupied

	const string WELCOME_MESSAGE = "Hi! Welcome to EasyDone!"; 
	const string USER_PROMPT = "What would you like to do today?"; 



int main(int argc, char *argv[]) {

		cout<< WELCOME_MESSAGE << endl;
		cout<< USER_PROMPT<< endl;

		cin >> userInput;
		
		Parser parseUserinput;

		parseUserinput.parseCommand(userInput);


		



		
		

		


	


  

	return 0;
}
