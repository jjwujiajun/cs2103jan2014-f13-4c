/*  Worker cpp

Implementation for the worker class in which based on the
command entered by the user, the appropriate function is called to carry
out the desired operation.

*/
#include "Worker.h"

const string Worker::NULL_STRING = "";
const string Worker::MESSAGE_ADDED_SUCCESSFULLY = "has been added successfully! :) \r\n";
const string Worker::MESSAGE_DELETED_SUCCESSFULLY = "has been deleted successfully! :) \r\n";
const string Worker::MESSAGE_UPDATED_SUCCESSFULLY = "has been updated successfully! :) \r\n"; 
const string Worker::MESSAGE_CHECKED_SUCCESSFULLY = "has been checked off your EasyDone task list! :) \r\n";
const string Worker::MESSAGE_WRONG_INDEX = "Please enter a valid index! \r\n";
const string Worker:: MESSAGE_ENTER_VALID_COMMAND = "Please enter a valid command! \r\n";
//const int NULL_DATE = -1;



// const string Parser::MESSAGE_DELETE = "delete";

Worker::Worker() {


}

Worker::~Worker() {
	//taskIndexIssuer;	// save the state of issuer pls
}


string Worker::takeparsedCommand(vector<string> parsedCommandstring) {

	command =  parsedCommandstring[0];
	if(command == "add" || command == "new" || command == "create" ){
		userTask.taskName = parsedCommandstring[1];
		userTask.startDate = parsedCommandstring[2];
		userTask.startTime = parsedCommandstring[3];
		userTask.endDate = parsedCommandstring[4];
		userTask.endTime = parsedCommandstring[5];
	} else if(command == "update"){
		userTask.taskID = parsedCommandstring[1];
		updateField = parsedCommandstring[2];

		if(updateField == "task") {
			userTask.taskName = parsedCommandstring[3];
		} else if(updateField == "sd") {
			userTask.startDate = parsedCommandstring[3];
		} else if(updateField == "st") {
			userTask.startTime = parsedCommandstring[3];
		} else if(updateField == "ed") {
			userTask.endDate = parsedCommandstring[3];
		} else if(updateField == "et") {
			userTask.endTime = parsedCommandstring[3];
		}
	} else if(command == "delete") {
		userTask.taskID = parsedCommandstring[1];
	} else if(command == "display") {
		userTask.taskID = parsedCommandstring[1];
	} else if(command == "done") {
		userTask.taskID = parsedCommandstring[1];
	} else if(command == "search") {
		
		searchField = parsedCommandstring[1];
		searchItem = parsedCommandstring[2];
	}

	int taskID = atoi(userTask.taskID.c_str());
	Task task = userCommand.getTask(taskID);

	stringToMain.clear();
	stringToMain = "\"" + task.taskName + "\" ";
	stringToMain += actonCommand(command);
	return stringToMain;
}

string Worker::actonCommand(string command)
{
	if(command == "add" || command == "new" || command == "create") {
		if(userCommand.Add(userTask)) {
			successful = "has been added successfully! :) \r\n";
		} else{
			successful = "has not been added successfully! ): \r\n";
		}
	}

	else if(command == "delete" ) {
		if(userCommand.Delete(userTask)) {
			successful = "has been deleted successfully! :) \r\n";
		}
		else {
			successful = "Please enter a valid index!\r\n";
		}
	}


	else if(command == "update" ) {
		if(userCommand.Update(userTask, updateField)) {
			successful = "has been updated successfully! :)\r\n";
		}
		else {
			successful = "Please enter a valid index!\r\n";
		}
	}

	else if(command == "search" ) {
		bool found = userCommand.Search(searchField, searchItem);
		if(found) {
			successful = "These tasks found";
		}
		else {
			successful = "Task not found";
		}
	}

	else if(command == "done" ) {
		bool found = userCommand.markDone(userTask);
		if(found) {
			successful = "Task marked done";
		}
		else {
			successful = "Task not found";
		}
	}

	else if(command == "display") {
		vector<Task> taskList = userCommand.getTaskList();
		int intID = stoi(userTask.taskID) - 1;
		Task task = taskList.at(intID);

		successful = "\r\nTask: " + task.taskName + "\r\n" +
						"Starts: " + formatDate(task.startDate) + " " + formatTime(task.startTime) + "\r\n" +
						"Ends: " + formatDate(task.endDate) + " " + formatTime(task.endTime) + "\r\n";
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

vector<Task> Worker::getSearchedList() {
	vector<Task> displayedTaskList = userCommand.getSearchedList();

	convertTaskDataToDisplayFormat(displayedTaskList);

	return displayedTaskList;
}

void Worker::convertTaskDataToDisplayFormat(vector<Task> &taskList) {
	for (int i = 0; i < (int) taskList.size(); ++i) {
		string taskIndex = taskList[i].taskID;
		string taskName = taskList[i].taskName;

		//limit taskName length for display
		if (taskName.size() > TASKLIST_NAME_LENGTH) {
			taskName = taskName.substr(0,TASKLIST_NAME_LENGTH-1);
			taskName += "...";
			taskList[i].taskName = taskName;
		}

		// 4 digit index display
		while (taskIndex.size() < TASKLIST_INDEX_LENGTH) {
			taskIndex = "0" + taskIndex;
		}
		taskList[i].taskID = taskIndex;
		
		// Worded date/time display
		taskList[i].startDate = formatDate(taskList[i].startDate);
		taskList[i].startTime = formatTime(taskList[i].startTime);
	}
}

string Worker::formatDate(string dataDate) {
	string sDate = dataDate;
	string sMonth;
	string sDay;
	string resultDate;
	int date;
	int month;
	int day;
	bool isKnownDateFormat = true;

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
				resultDate = sDay + sMonth;
			} else {
				resultDate = "";
			}
		} else {
			resultDate = "";
		}
	return resultDate;
}

string Worker::formatTime(string sTime) {
	string time = sTime;
	string resultTime;
	bool isKnownTimeFormat = time.size() == 4;

	if (!time.empty() && time != "0") {
		// Digital clock display
		//assert(time.size() <= 4);
		if (isKnownTimeFormat) {
			time.insert(2, ":");
			resultTime = time;
		} else {
			resultTime = "";
		}
	} else {
		resultTime = "";
	}
	return resultTime;
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



