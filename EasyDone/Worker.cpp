/*  Worker cpp

Implementation for the worker class in which based on the
command entered by the user, the appropriate function is called to carry
out the desired operation.

*/
#include "Worker.h"

const string Worker::NULL_STRING = "";
const string Worker::MESSAGE_ADDED_SUCCESSFULLY = "has been added successfully! :) ";
const string Worker::MESSAGE_DELETED_SUCCESSFULLY = "has been deleted successfully! :)";
const string Worker::MESSAGE_UPDATED_SUCCESSFULLY = "has been updated successfully! :) "; 
const string Worker::MESSAGE_CHECKED_SUCCESSFULLY = "has been checked off your EasyDone task list! :)";
const string Worker::MESSAGE_WRONG_INDEX = "Please enter a valid index!";
const string  Worker:: MESSAGE_ENTER_VALID_COMMAND = "Please enter a valid command!";
//const int NULL_DATE = -1;



// const string Parser::MESSAGE_DELETE = "delete";

Worker::Worker() {


}

Worker::~Worker() {
	//taskIndexIssuer;	// save the state of issuer pls
}


string Worker::takeparsedCommand(vector<string> parsedCommandstring) {

	command =  parsedCommandstring[0];
	if(command == "add"){
		userTask.taskName = parsedCommandstring[1];
		userTask.startDate = parsedCommandstring[2];
		userTask.startTime = parsedCommandstring[3];
		userTask.endDate = parsedCommandstring[4];
		userTask.endTime = parsedCommandstring[5];
	} else if(command == "update"){
		userTask.taskID = parsedCommandstring[1];
		updateField = parsedCommandstring[2];

		if(updateField == "taskName") {
			userTask.taskName = parsedCommandstring[3];
		} else if(updateField == "startDate") {
			userTask.startDate = parsedCommandstring[3];
		} else if(updateField == "startTime") {
			userTask.startTime = parsedCommandstring[3];
		} else if(updateField == "endDate") {
			userTask.endDate = parsedCommandstring[3];
		} else if(updateField == "endTime") {
			userTask.endTime = parsedCommandstring[3];
		}
	} else if(command == "delete") {
		userTask.taskID = parsedCommandstring[1];
	}

	//stringToMain = command;
	 stringToMain += actonCommand(command);
	 return stringToMain;
}

string Worker::actonCommand(string command)
{
	if(command == "add" || command == "new" || command == "create") {
		if(userCommand.Add(userTask)) {
			successful = "has been added successfully! :) \n";
		} else{
			successful = "has not been added successfully! ): \n";
		}
	}

	else if(command == "delete" ) {
		if(userCommand.Delete(userTask)) {
			successful = "has been deleted successfully! :)\n";
		}
		else {
			successful = "Please enter a valid index!\n";
		}
	}


	else if(command == "update" ) {
		if(userCommand.Update(userTask, updateField)) {
			successful = "has been updated successfully! :)\n";
		}
		else {
			successful = "Please enter a valid index!\n";
		}
	}

	else if(command ==  "undo") {
		userCommand.undo();
	}
		

	return successful;

}

vector<Task> Worker::getTaskList() {
	vector<Task> displayedTaskList = userCommand.getTaskList();

	convertTaskDataToDisplayFormat(displayedTaskList);

	return displayedTaskList;
}


void Worker::convertTaskDataToDisplayFormat(vector<Task> &taskList) {
	for (int i = 0; i < taskList.size(); ++i) {
		string taskIndex = taskList[i].taskID;
		string time = taskList[i].startTime;
		string sDate = taskList[i].startDate;
		string sMonth;
		string sDay;
		int date;
		int month;
		int day;
		bool isKnownDateFormat = true;
		bool isKnownTimeFormat = time.size() == 4;


		// 4 digit index display
		while (taskIndex.size() < 4) {
			taskIndex = "0" + taskIndex;
		}
		taskList[i].taskID = taskIndex;
		
		// Worded date display
		if (!sDate.empty() && sDate != "0") {
			date = stoi(sDate);
			date %= 10000;

			month = date/100;
			//assert(1 <= month && month <= 12);
			switch (month) {
			case 1:
				sMonth = " Jan";
				break;
			case 2:
				sMonth = " Feb";
				break;
			case 3:
				sMonth = " Mar";
				break;
			case 4:
				sMonth = " Apr";
				break;
			case 5:
				sMonth = " May";
				break;
			case 6:
				sMonth = " Jun";
				break;
			case 7:
				sMonth = " Jul";
				break;
			case 8:
				sMonth = " Aug";
				break;
			case 9:
				sMonth = " Sep";
				break;
			case 10:
				sMonth = " Oct";
				break;
			case 11:
				sMonth = " Nov";
				break;
			case 12:
				sMonth = " Dec";
				break;
			default:
				isKnownDateFormat = false;
				break;
			}

			day = date%100;
			//assert(1 <= day && day <= 31);
			if (day < 10) {
				sDay = " " + to_string(day);
			} else {
				sDay = to_string(day);
			}

			if (isKnownDateFormat) {
				taskList[i].startDate = sDay + sMonth;
			}
		} else {
			taskList[i].startDate = ""; //6 spaces
		}

		if (!time.empty() && time != "0") {
			// Digital clock display
			//assert(time.size() <= 4);
			if (isKnownTimeFormat) {
				time.insert(2, ":");
				taskList[i].startTime = time;
			}
		} else {
			taskList[i].startTime = "";
		}
	}
}































/*bool Worker::checkListForSlotFor(Task newTask){
for (iter = todoList.begin(); iter != todoList.end(); ++iter) {
if (iter->startDate < newTask.startDate && newTask.startDate < iter->endDate) {
return false;
}
if (iter->startTime < newTask.startTime && newTask.startTime < iter->endTime) {
return false;
}
if (iter->startDate < newTask.endDate && newTask.endDate < iter->endDate) {
return false;
}
if (iter->startTime < newTask.endTime && newTask.endTime < iter->endTime) {
return false;
}
}
return true;
}*/



