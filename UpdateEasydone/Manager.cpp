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

string fileName;

string outputMessage;
string KeyWord;
vector<string> toBeDisplayed;
string fieldToBeUpdated;

const string WELCOME_MESSAGE = "Hi! Welcome to EasyDone!";
const string USER_PROMPT = "What would you like to do today?";
const string KEYED_EXIT = "exit";



int main (int argc, char* argv[]) {
    
	bool ready = 0;
	FileHandler Loader;
	Parser ParserJob;
	Worker WorkerJob;
	bool continue_running;

	fileName = argv[1];

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

    return 0;
}
