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

const string WELCOME_MESSAGE = "Hi! Welcome to EasyDone!";
const string USER_PROMPT = "What would you like to do today?";



int main (void) {
    //string filname = argv[0];
    cout<< WELCOME_MESSAGE << endl;
    cout<< USER_PROMPT<< endl;

	getline(cin, userInput);
   

    Parser parserJob;
    Worker workerJob;

    // Checks if input has passed successfully
    bool successful = parserJob.completeParse (userInput);

    //details from parser spilt into the individual components
    detailsFromParser = parserJob.parseDetails (userInput);
    taskName = detailsFromParser[0];
    startDate = detailsFromParser[1];
    startTime =  detailsFromParser[2];
    endDate = detailsFromParser[3];
    endTime = detailsFromParser[4];
    additionalDetails = detailsFromParser[5];
    isCompleted = detailsFromParser[6];
    KeyWord =  detailsFromParser [7];
    // different cases for the different task. Manager calls worker to do the task
    switch (parserJob.actionIndex) {
        case 1:
            outputMessage= workerJob.addTask (taskName, startDate, startTime, endDate, endTime, additionalDetails);
            cout<<outputMessage;
            break;
        case 2:
            outputMessage = workerJob.removeTaskWithIndex (indexOfTask);
            cout<<outputMessage;
            break;
        case 3:
            outputMessage =  workerJob.updateTaskWithIndex (indexOfTask, contentToBeUpdated, fieldToBeUpdated);
            cout<<outputMessage;
            break;
        case 4:
            outputMessage =  workerJob.markDoneTaskWithIndex (indexOfTask);
            cout<<outputMessage;
            break;
        //case 5:
        //toBeDisplayed = workerJob.displayTaskWithIndex(indexOfTask);
        //break;
        case 5:
            int indexOfSeachedTask =  workerJob.searchTasks (KeyWord);
            break;
    }
    cout<<"bye!";
    return 0;
}
