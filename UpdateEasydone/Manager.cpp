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

	const string WELCOME_MESSAGE = "Hi! Welcome to EasyDone!"; 
	const string USER_PROMPT = "What would you like to do today?"; 



int main(int argc, char *argv[]) {

		cout<< WELCOME_MESSAGE << endl;
		cout<< USER_PROMPT<< endl;

		cin >> userInput;
		
		
		Parser parserJob;
		Worker workerJob;

		bool successful = parserJob.parseCommand(userInput);
		detailsFromParser = parserJob.parseDetails(userInput);
		taskName = detailsFromParser[0];
		startDate = detailsFromParser[1];
		startTime =  detailsFromParser[2];
		endDate = detailsFromParser[3];
		endTime = detailsFromParser[4];
		additionalDetails = detailsFromParser[5];
		isCompleted = detailsFromParser[6];
		KeyWord =  detailsFromParser [7];
		

		switch(parserJob.actionIndex) {
			case 1:
				outputMessage= workerJob.addTask(taskName, startDate, startTime, endDate, endTime, additionalDetails);
				break;

			case 2: 
				outputMessage = workerJob.removeTaskWithIndex(indexOfTask);
				break;

			case 3: 
				outputMessage =  workerJob.updateTaskWithIndex(indexOfTask, contentToBeUpdated);
				break;

			case 4:  
				outputMessage =  workerJob.markDoneTaskWithIndex(indexOfTask);
				break;

			case 5: 
				toBeDisplayed = workerJob.displayTaskWithIndex(indexOfTask);
				break;

			case 6: 
				int indexOfSeachedTask =  workerJob.searchTasks(KeyWord);
				break;

		}



				


		



		
		

		


	


  

	return 0;
}
