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

	continueNext = true;
	command =  parsedCommandstring[0];
	if(command == "add" || command == "new" || command == "create" ){

		if (parsedCommandstring[2] == "today") {

			date = userCommand.getTodayDay();
			month = userCommand.getTodayMonth();
			year = userCommand.getTodayYear();
			combine = year + month + date;
			parsedCommandstring[2] = combine;

			userTask.taskName = parsedCommandstring[1];
			userTask.startDate = parsedCommandstring[2];
			userTask.startTime = parsedCommandstring[3];
			userTask.endDate = parsedCommandstring[4];
			userTask.endTime = parsedCommandstring[5];

		} else if (parsedCommandstring[2] == "tmr" || parsedCommandstring[2] == "tmo" || parsedCommandstring[4] == "tmr" || parsedCommandstring[4] == "tmo") {

			tomorrowDate = userCommand.getTomorrowDate();

			for (int i = tomorrowDate.size()-1; i >= 0 ; --i) {
				combine += tomorrowDate[i];

			}

			parsedCommandstring[2] = combine;
			parsedCommandstring[4] = combine;

			userTask.taskName = parsedCommandstring[1];
			userTask.startDate = parsedCommandstring[2];
			userTask.startTime = parsedCommandstring[3];
			userTask.endDate = parsedCommandstring[4];
			userTask.endTime = parsedCommandstring[5];

		} else {
		userTask.taskName = parsedCommandstring[1];
		userTask.startDate = parsedCommandstring[2];
		userTask.startTime = parsedCommandstring[3];
		userTask.endDate = parsedCommandstring[4];
		userTask.endTime = parsedCommandstring[5];

		}

		//Exception handler for start date and end date. Throws exception if end date is before the start date.
		if(!userTask.startDate.empty() && !userTask.endDate.empty()) {
			if(stoi(userTask.startDate) > stoi(userTask.endDate)) {
				continueNext = false;
			} else if(!userTask.startTime.empty() && !userTask.endTime.empty()) {
				if(stoi(userTask.startTime) > stoi(userTask.endTime)) {
					continueNext = false;
				}
			}
		} 


	} else if(command == "update" || command == "edit" || command == "change"){
		//Exception Handler for taskID inserted. Throws exception is the taskID is outside the list range.
		if(!parsedCommandstring[1].empty()) {
			if(stoi(userCommand.getSize()) >= stoi(parsedCommandstring[1]) && stoi(parsedCommandstring[1]) > 0) {
				userTask.taskID = parsedCommandstring[1];
			} else {
				continueNext = false;
			}
		} else {
			continueNext = false;
		}
		updateField = parsedCommandstring[2];

		//Exception handler for updateField. Throws exception if the field provided is unidentified.
		if(updateField == "task") {
			userTask.taskName = parsedCommandstring[3];

		} else if(updateField == "sd") {

			if (parsedCommandstring[3] == "today") {

			date = userCommand.getTodayDay();
			month = userCommand.getTodayMonth();
			year = userCommand.getTodayYear();
			combine = year + month + date;
			parsedCommandstring[3] = combine;

			userTask.startDate = parsedCommandstring[3];
			

		} else if (parsedCommandstring[3] == "tmr" || parsedCommandstring[3] == "tmo") {

			tomorrowDate = userCommand.getTomorrowDate();

			for (int i = tomorrowDate.size()-1; i >= 0 ; --i) {
				combine += tomorrowDate[i];

			}

			parsedCommandstring[3] = combine;
			userTask.startDate = parsedCommandstring[3];
			


		} else {
		
			userTask.startDate = parsedCommandstring[3];
	
			}
		} else if(updateField == "st") {
			userTask.startTime = parsedCommandstring[3];
		} else if(updateField == "ed") {

			if (parsedCommandstring[3] == "today") {

			date = userCommand.getTodayDay();
			month = userCommand.getTodayMonth();
			year = userCommand.getTodayYear();
			combine = year + month + date;
			parsedCommandstring[3] = combine;

			userTask.endDate = parsedCommandstring[3];
			

		} else if (parsedCommandstring[3] == "tmr" || parsedCommandstring[3] == "tmo") {

			tomorrowDate = userCommand.getTomorrowDate();

			for (int i = tomorrowDate.size()-1; i >= 0 ; --i) {
				combine += tomorrowDate[i];

			}

			parsedCommandstring[3] = combine;
			userTask.endDate = parsedCommandstring[3];
			


		} else {
		
			userTask.endDate = parsedCommandstring[3];
	
			}

		} else if(updateField == "et") {
			userTask.endTime = parsedCommandstring[3];
		} else {
			continueNext = false;
		}
	} else if(command == "delete" || command == "remove") {
		//Exception Handler for taskID inserted. Throws exception is the taskID is outside the list range.
		if(stoi(userCommand.getSize()) >= stoi(parsedCommandstring[1]) && stoi(parsedCommandstring[1]) > 0) {
			userTask.taskID = parsedCommandstring[1];
		} else {
			continueNext = false;
		}
	} else if(command == "done" || command == "display" || command == "view") {
		//Exception Handler for taskID inserted. Throws exception is the taskID is outside the list range.
		if(stoi(userCommand.getSize()) >= stoi(parsedCommandstring[1]) && stoi(parsedCommandstring[1]) > 0) {
			userTask.taskID = parsedCommandstring[1];
		} else {
			continueNext = false;
		}
	} else if(command == "search") {
		
		searchField = parsedCommandstring[1];
		searchItem = parsedCommandstring[2];
	}

	stringToMain.clear();

	if(command == "add") {
		stringToMain = "\"" + userTask.taskName + "\" \r\n";
	} else if(continueNext) {
		if (!userTask.taskID.empty() && command != "undo") {
			int taskID = atoi(userTask.taskID.c_str()) - 1;
			Task task = userCommand.getTask(taskID); 
			stringToMain = "\"" + task.taskName + "\" \r\n";
		}
	}

	stringToMain += actonCommand(command);
	return stringToMain;
}

string Worker::actonCommand(string command)
{
	string startDate = userTask.startDate;
	string endDate = userTask.endDate;
	string startTime = userTask.startTime;
	string endTime = userTask.endTime;

	if(command == "add" || command == "new" || command == "create") {
		if(continueNext == true && startDate != "1" && endDate != "1" && startDate != "3" && endDate != "3" && startDate != "12" && endDate != "12" && startDate != "13" && endDate != "13" && startDate != "123" && endDate != "123" && startTime != "0" && endTime != "0" )  {
			if(userCommand.Add(userTask)) {
				successful = "has been added successfully! :) \r\n";
			} else {
				successful = "task is already inside the list!\r\n";
			}
		
	//	} else if (startDate == "1" || endDate == "1" || startDate == "3" || endDate == "3" || startDate == "12" || endDate == "12" || startDate == "13" || endDate == "13" || startDate == "123" || endDate == "123" && (startTime == "0" || endTime == "0")) {
		//	successful = "Invalid Time and date!!! Task has not been added successfully! ): Type Carefully! \r\n";
		
		} else if (startDate == "1" || endDate == "1" ) {
			successful = "Invalid date!!!! Task has not been added successfully! ): Is it a 30th or 31st?? Ensure time format is correct too! =) \r\n";

		} else if (startDate == "3" || endDate == "3") {
			successful = "Invalid Year!!! Task has not been added successfully! ): Year valid till 2099! Ensure time format is correct too! =) \r\n";
		
		} else if (startDate == "12" || endDate == "12") {
			successful = "Invalid date & Month!!! Task has not been added successfully! ): Month is from 1 to 12! Ensure time format is correct too! =) \r\n";

		} else if (startDate == "13" || endDate == "13") {
			successful = "Invalid date & Year!!! Task has not been added successfully! ): Is it a leap Year?? Ensure time format is correct too! =) \r\n";

		} else if (startDate == "123" || endDate == "123") {
			successful = "Invalid Date & Month & Year!!! Task has not been added successfully! ): Type Carefully! Ensure time format is correct too! =) \r\n";

		} else if (startTime == "0" || endTime == "0") {
			successful = "Invalid Time!!! Task has not been added successfully! ): Remember hour is from 00 to 23, Minute is from 00 to 59  \r\n";
		} else {
			successful = "Start date cannot be after end date. Similarly if the start date and end date are same, start time cannot be after end time.\r\n";
		}
	}

	else if(command == "delete" || command == "remove") {
		if(continueNext == true) {
			if(userCommand.Delete(userTask) ) {
				successful = "has been deleted successfully! :) \r\n";
			}
			else {
				successful = "Please enter a valid index!\r\n";
			}
		} else {
			successful = "TaskID is out of range. Please check again.\r\n";
		}
	}


	else if(command == "update" || command == "edit" || command == "change" ) {
		if(continueNext == true) {
			if(startDate != "1" && endDate != "1" && startDate != "3" && endDate != "3" && startDate != "12" && endDate != "12" && startDate != "13" && endDate != "13" && startDate != "123" && endDate != "123" && startTime != "0" && endTime != "0" ) {
				string updated = userCommand.Update(userTask, updateField);
				if(updated == "true") {
					successful = "has been updated successfully! :)\r\n";
				} else {
					if(updated == "false") {
						successful = "updated task already exists in the list. Therefore, it has been removed from the list. You may undo to get the unupdated task back.\r\n";
					} else if(updated == "startDate") {
						successful = "End date cannot be before the start date. Please check again.\r\n";
					} else if(updated == "startTime") {
						successful = "End time cannot be before start Time if the task starts and ends on the same day. Please check again.\r\n";
					}
				}
		
			} else if (startDate == "1" || endDate == "1" ) {
				successful = "Invalid date!!!! Task has not been edited successfully! ): Is it a 30th or 31st?? Ensure time format is correct too! =) \r\n";

			} else if (startDate == "3" || endDate == "3") {
				successful = "Invalid Year!!! Task has not been edited successfully! ): Year valid till 2099! Ensure time format is correct too! =) \r\n";
		
			} else if (startDate == "12" || endDate == "12") {
				successful = "Invalid date & Month!!! Task has not been edited successfully! ): Month is from 1 to 12! Ensure time format is correct too! =) \r\n";

			} else if (startDate == "13" || endDate == "13") {
				successful = "Invalid date & Year!!! Task has not been edited successfully! ): Is it a leap Year?? Ensure time format is correct too! =) \r\n";

			} else if (startDate == "123" || endDate == "123") {
				successful = "Invalid Date & Month & Year!!! Task has not been edited successfully! ): Type Carefully! Ensure time format is correct too! =) \r\n";

			} else if (startTime == "0" || endTime == "0") {
				successful = "Invalid Time!!! Task has not been edited successfully! ): Remember hour is from 00 to 23, Minute is from 00 to 59  \r\n";
			} 
		} else {
			successful = "Either invalid field input or taskID is out of range! Please check again.\r\n";
		}
		
	}

	else if(command == "search" ) {
		bool found = userCommand.Search(searchField, searchItem);
		if(found) {
			successful = "These tasks found.";
		}
		else {
			successful = "Task not found.\r\n";
		}
	}

	else if(command == "done" ) {
		if(continueNext == true) {
			bool found = userCommand.markDone(userTask);
			if(found) {
				successful = "Task marked done.\r\n";
			}
			else {
				successful = "Task not found.\r\n";
			}
		} else {
			successful = "TaskID is out of range. Please check again.\r\n";
		}
	}

	else if(command == "display") {
		if(continueNext == true) {
			vector<Task>* taskList = new vector<Task>;
			taskList = userCommand.getTaskList();
			int intID = stoi(userTask.taskID) - 1;
			Task task = taskList->at(intID);
			bool shouldShowYear = true;
			bool shouldBeDetailed = false;

			successful = "Starts: " + formatDate(task.startDate, shouldShowYear, shouldBeDetailed) + "   " + formatTime(task.startTime, shouldBeDetailed) + "\r\n" +
						 "Ends: " + formatDate(task.endDate, shouldShowYear, shouldBeDetailed) + "   " + formatTime(task.endTime, shouldBeDetailed) + "\r\n\r\n";
			delete taskList;
		} else {
			successful = "TaskID is out of range. Please check again.\r\n";
		}
	}

	else if(command ==  "undo") {
		if(userCommand.undo()) {
			successful = "The most recent change has been removed.\r\n";
		} else {
			successful = "Nothing is undo.\r\n";
		}
	}
		

	return successful;

}

vector<Task>* Worker::getTaskList() {
	vector<Task>* displayedTaskList = userCommand.getTaskList();

	bool shouldShowEndTime = false;
	convertTaskDataToDisplayFormat(*displayedTaskList, shouldShowEndTime);

	return displayedTaskList;
}

vector<Task> Worker::getSearchedList() {
	vector<Task> displayedTaskList = userCommand.getSearchedList();

	bool shouldShowEndTime = false;
	convertTaskDataToDisplayFormat(displayedTaskList, shouldShowEndTime);

	return displayedTaskList;
}

vector<Task>* Worker::getTasksDueTodayList() {

	vector<Task>* displayedTaskList =  userCommand.getTodayTask();
	
	bool shouldShowEndTime = true;
	convertTaskDataToDisplayFormat(*displayedTaskList, shouldShowEndTime);

	return displayedTaskList;
}

vector<Task>* Worker::getTasksDueTomorrowList() {

	vector<Task>* displayedTaskList = userCommand.getTomorrowTask();

	bool shouldShowEndTime = true;
	convertTaskDataToDisplayFormat(*displayedTaskList, shouldShowEndTime);

	return displayedTaskList;
}

vector<Task>* Worker::getTasksOverdueList() {

	vector<Task>* displayedTaskList =  userCommand.getOverdueTasks();

	bool shouldShowEndTime = false;
	convertTaskDataToDisplayFormat(*displayedTaskList, shouldShowEndTime);

	return displayedTaskList;

}

vector<Task>* Worker::getTasksDoneList() {

	vector<Task>* displayedTaskList =  userCommand.getMarkedTasks();

	bool shouldShowEndTime = false;
	convertTaskDataToDisplayFormat(*displayedTaskList, shouldShowEndTime);

	return displayedTaskList;
}

vector<Task>* Worker::getTasksUndoneList() {

	vector<Task>* displayedTaskList =  userCommand.getUnmarkedTasks();

	bool shouldShowEndTime = false;
	convertTaskDataToDisplayFormat(*displayedTaskList, shouldShowEndTime);

	return displayedTaskList;
}


void Worker::convertTaskDataToDisplayFormat(vector<Task> &taskList, bool shouldBeDetailed) { //, const bool& isExpanded) {
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
		bool shouldShowYear = false;
		taskList[i].startDate = formatDate(taskList[i].startDate, shouldShowYear, shouldBeDetailed);
		taskList[i].startTime = formatTime(taskList[i].startTime, shouldBeDetailed);
		taskList[i].endDate = formatDate(taskList[i].endDate, shouldShowYear, shouldBeDetailed);
		taskList[i].endTime = formatTime(taskList[i].endTime, shouldBeDetailed);
	}
}

string Worker::formatDate(string dataDate, bool shouldShowYear, bool shouldBeDetailed) {
	string sDate = dataDate;
	string sYear;
	string sMonth;
	string sDay;
	string resultDate;
	int date;
	int year;
	int month;
	int day;
	bool isKnownDateFormat = true;

	if (!sDate.empty() && sDate != "0") {
			date = stoi(sDate);
			
			year = date/10000;
			sYear = " " + to_string(year);

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
				if (shouldShowYear) {
					resultDate += sYear;
				}
			} else {
				resultDate = "";
			}
		} else {
			if (shouldBeDetailed) {
				resultDate = "   -- ";
			}
		}
	return resultDate;
}

string Worker::formatTime(string sTime, bool shouldBeDetailed) {
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
		if (shouldBeDetailed) {
			resultTime = "   -- ";
		}
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



