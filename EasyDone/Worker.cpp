//@author A0099326U
/*  Worker cpp

Implementation for the worker class in which based on the
command entered by the user, the appropriate function is called to carry
out the desired operation.

*/
#include "Worker.h"
//const int NULL_DATE = -1;



// const string Parser::MESSAGE_DELETE = KEYWORD_DELETE;

Worker::Worker() {


}

Worker::~Worker() {
	//taskIndexIssuer;	// save the state of issuer pls
}


string Worker::takeparsedCommand(vector<string> parsedCommandstring) {

	continueNext = true;
	command =  parsedCommandstring[0];
	if(command == KEYWORD_ADD || command == KEYWORD_NEW || command == KEYWORD_CREATE ){

		if (parsedCommandstring[2] == KEYWORD_TODAY) {

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

		} else if (parsedCommandstring[2] == KEYWORD_TOMORROW_1 || parsedCommandstring[2] == KEYWORD_TOMORROW_2 || parsedCommandstring[4] == KEYWORD_TOMORROW_1 || parsedCommandstring[4] == KEYWORD_TOMORROW_2) {

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
			} else if(stoi(userTask.startDate) == stoi(userTask.endDate)) {
				if(!userTask.startTime.empty() && !userTask.endTime.empty() && stoi(userTask.startTime) > stoi(userTask.endTime)) {
					continueNext = false;
				}
			}
		} 


	} else if(command == KEYWORD_UPDATE || command == KEYWORD_EDIT || command == KEYWORD_CHANGE){
		//Exception Handler for taskID inserted. Throws exception is the taskID is outside the list range.
		if(!parsedCommandstring[1].empty()) {
			if(stoi(userCommand.getSize()) >= stoi(parsedCommandstring[1]) && stoi(parsedCommandstring[1]) > 0) {
				userTask.taskID = to_string(stoi(parsedCommandstring[1]));
			} else {
				continueNext = false;
			}
		} else {
			continueNext = false;
		}
		updateField = parsedCommandstring[2];

		//Exception handler for updateField. Throws exception if the field provided is unidentified.
		if(updateField == KEYWORD_TASK) {
			userTask.taskName = parsedCommandstring[3];

		} else if(updateField == KEYWORD_STARTDATE) {

			if (parsedCommandstring[3] == KEYWORD_TODAY) {

			date = userCommand.getTodayDay();
			month = userCommand.getTodayMonth();
			year = userCommand.getTodayYear();
			combine = year + month + date;
			parsedCommandstring[3] = combine;

			userTask.startDate = parsedCommandstring[3];
			

		} else if (parsedCommandstring[3] == KEYWORD_TOMORROW_1 || parsedCommandstring[3] == KEYWORD_TOMORROW_2) {

			tomorrowDate = userCommand.getTomorrowDate();

			for (int i = tomorrowDate.size()-1; i >= 0 ; --i) {
				combine += tomorrowDate[i];

			}

			parsedCommandstring[3] = combine;
			userTask.startDate = parsedCommandstring[3];
			


		} else {
		
			userTask.startDate = parsedCommandstring[3];
	
			}
		} else if(updateField == KEYWORD_STARTTIME) {
			userTask.startTime = parsedCommandstring[3];
		} else if(updateField == KEYWORD_ENDDATE) {

			if (parsedCommandstring[3] == KEYWORD_TODAY) {

			date = userCommand.getTodayDay();
			month = userCommand.getTodayMonth();
			year = userCommand.getTodayYear();
			combine = year + month + date;
			parsedCommandstring[3] = combine;

			userTask.endDate = parsedCommandstring[3];
			

		} else if (parsedCommandstring[3] == KEYWORD_TOMORROW_1 || parsedCommandstring[3] == KEYWORD_TOMORROW_2) {

			tomorrowDate = userCommand.getTomorrowDate();

			for (int i = tomorrowDate.size()-1; i >= 0 ; --i) {
				combine += tomorrowDate[i];

			}

			parsedCommandstring[3] = combine;
			userTask.endDate = parsedCommandstring[3];
			


		} else {
		
			userTask.endDate = parsedCommandstring[3];
	
			}

		} else if(updateField == KEYWORD_ENDTIME) {
			userTask.endTime = parsedCommandstring[3];
		} else {
			continueNext = false;
		}
	} else if(command == KEYWORD_DELETE || command == KEYWORD_DELETE) {
		//Exception Handler for taskID inserted. Throws exception is the taskID is outside the list range.
		if(stoi(userCommand.getSize()) >= stoi(parsedCommandstring[1]) && stoi(parsedCommandstring[1]) > 0) {
			userTask.taskID = parsedCommandstring[1];
		} else {
			continueNext = false;
		}
	} else if(command == KEYWORD_DONE || command == KEYWORD_DISPLAY || command == KEYWORD_VIEW) {
		//Exception Handler for taskID inserted. Throws exception is the taskID is outside the list range.
		if(stoi(userCommand.getSize()) >= stoi(parsedCommandstring[1]) && stoi(parsedCommandstring[1]) > 0) {
			userTask.taskID = to_string(stoi(parsedCommandstring[1]));
		} else {
			continueNext = false;
		}
	} else if(command == KEYWORD_SEARCH) {
		
		searchField = parsedCommandstring[1];
		searchItem = parsedCommandstring[2];
	}

	stringToMain.clear();

	if(command == KEYWORD_ADD) {
		stringToMain = STRING_QUOTE + userTask.taskName + STRING_QUOTE + SYSTEM_ENDL;
	} else if(continueNext) {
		if (!userTask.taskID.empty() && command != KEYWORD_UNDO) {
			int taskID = atoi(userTask.taskID.c_str()) - 1;
			Task task = userCommand.getTask(taskID); 
			stringToMain = STRING_QUOTE + task.taskName + STRING_QUOTE + SYSTEM_ENDL;
		}
	}
	try {
		stringToMain += actonCommand(command);
	} catch (string error) {
		throw error;
	}

	return stringToMain;
}

string Worker::actonCommand(string command)
{
	string startDate = userTask.startDate;
	string endDate = userTask.endDate;
	string startTime = userTask.startTime;
	string endTime = userTask.endTime;

	if(command == KEYWORD_ADD || command == KEYWORD_NEW || command == KEYWORD_CREATE) {
		if(continueNext == true && startDate != DAY_1 && endDate != DAY_1 && startDate != DAY_3 && endDate != DAY_3 && startDate != DAY_12 && endDate != DAY_12 && startDate != DAY_13 && endDate != DAY_13 && startDate != DAY_123 && endDate != DAY_123 && startTime != "0" && endTime != "0" )  {
			if(userCommand.Add(userTask)) {
				successful = MESSAGE_ADDED_SUCCESSFULLY;
			} else {
				successful = MESSAGE_ADDED_FAILED_TASK_IN_LIST;
			}
		
	//	} else if (startDate == DAY_1 || endDate == DAY_1 || startDate == DAY_3 || endDate == DAY_3 || startDate == DAY_12 || endDate == DAY_12 || startDate == DAY_13 || endDate == DAY_13 || startDate == DAY_123 || endDate == DAY_123 && (startTime == "0" || endTime == "0")) {
		//	successful = "Invalid Time and date!!! Task has not been added successfully! ): Type Carefully! \r\n";
		
		} else if (startDate == DAY_1 || endDate == DAY_1 ) {
			successful = MESSAGE_ADDED_FAILED_INVALID_DATE + MESSAGE_ADDED_FAILED;

		} else if (startDate == DAY_3 || endDate == DAY_3) {
			successful = MESSAGE_ADDED_FAILED_INVALID_YEAR + MESSAGE_ADDED_FAILED;
		
		} else if (startDate == DAY_12 || endDate == DAY_12) {
			successful = MESSAGE_ADDED_FAILED_INVALID_DATE_MONTH + MESSAGE_ADDED_FAILED;

		} else if (startDate == DAY_13 || endDate == DAY_13) {
			successful = MESSAGE_ADDED_FAILED_INVALID_DATE_YEAR + MESSAGE_ADDED_FAILED;

		} else if (startDate == DAY_123 || endDate == DAY_123) {
			successful = MESSAGE_ADDED_FAILED_INVALID_DATE_MONTH_YEAR + MESSAGE_ADDED_FAILED;

		} else if (startTime == TIME_0 || endTime == TIME_0) {
			successful = MESSAGE_ADDED_FAILED_INVALID_TIME + MESSAGE_ADDED_FAILED;
		} else {
			successful = MESSAGE_ADDED_FAILED_CHRONO_ORDER;
		}
	}

	else if(command == KEYWORD_DELETE || command == KEYWORD_DELETE) {
		if(continueNext == true) {
			if(userCommand.Delete(userTask) ) {
				successful = MESSAGE_DELETED_SUCCESSFULLY;
			}
			else {
				successful = MESSAGE_WRONG_INDEX;
			}
		} else {
			successful = MESSAGE_OUT_OF_RANGE_INDEX;
		}
	}


	else if(command == KEYWORD_UPDATE || command == KEYWORD_EDIT|| command == KEYWORD_CHANGE ) {
		if(continueNext == true) {
			if(startDate != DAY_1 && endDate != DAY_1 && startDate != DAY_3 && endDate != DAY_3 && startDate != DAY_12 && endDate != DAY_12 && startDate != DAY_13 && endDate != DAY_13 && startDate != DAY_123 && endDate != DAY_123 && startTime != TIME_0 && endTime != TIME_0 ) {
				bool updated;
				try {
					updated = userCommand.Update(userTask, updateField);
				} catch (string error) {
					throw error;
				}
				if(updated) {
					successful = MESSAGE_UPDATED_SUCCESSFULLY;
				} else {
					successful = MESSAGE_UPDATED_FAILED_DUPLICATE;
				}
		
			} else if (startDate == DAY_1 || endDate == DAY_1 ) {
				successful = MESSAGE_UPDATED_FAILED_INVALID_DATE + MESSAGE_UPDATED_FAILED;

			} else if (startDate == DAY_3 || endDate == DAY_3) {
				successful = MESSAGE_UPDATED_FAILED_INVALID_YEAR + MESSAGE_UPDATED_FAILED;
		
			} else if (startDate == DAY_12 || endDate == DAY_12) {
				successful = MESSAGE_UPDATED_FAILED_INVALID_DATE_MONTH + MESSAGE_UPDATED_FAILED;

			} else if (startDate == DAY_13 || endDate == DAY_13) {
				successful = MESSAGE_UPDATED_FAILED_INVALID_DATE_YEAR + MESSAGE_UPDATED_FAILED;

			} else if (startDate == DAY_123 || endDate == DAY_123) {
				successful = MESSAGE_UPDATED_FAILED_INVALID_DATE_MONTH_YEAR + MESSAGE_UPDATED_FAILED;

			} else if (startTime == TIME_0 || endTime == TIME_0) {
				successful = MESSAGE_UPDATED_FAILED_INVALID_TIME + MESSAGE_UPDATED_FAILED;
			} 
		} else {
			successful = MESSAGE_UPDATED_FAILED_OUT_OF_RANGE;
		}
		
	}

	else if(command == KEYWORD_SEARCH ) {
		bool found = userCommand.Search(searchField, searchItem);
		if(found) {
			successful = MESSAGE_SEARCH_SUCCESSFUL;
		}
		else {
			successful = MESSAGE_SEARCH_FAILED;
		}
	}

	else if(command == KEYWORD_DONE ) {
		if(continueNext == true) {
			bool found = userCommand.markDone(userTask);
			if(found) {
				successful = MESSAGE_DONE_SUCCESSFUL;
			}
			else {
				successful = MESSAGE_DONE_FAILED;
			}
		} else {
			successful = MESSAGE_OUT_OF_RANGE_INDEX;
		}
	}

	else if(command == KEYWORD_DISPLAY) {
		if(continueNext == true) {
			vector<Task>* taskList = new vector<Task>;
			taskList = userCommand.getTaskList();
			int intID = stoi(userTask.taskID) - 1;
			Task task = taskList->at(intID);
			bool shouldShowYear = true;
			bool shouldBeDetailed = false;

			successful = MESSAGE_DISPLAY_START + formatDate(task.startDate, shouldShowYear, shouldBeDetailed) + MESSAGE_DISPLAY_SPACE_FORMATTING + formatTime(task.startTime, shouldBeDetailed) + SYSTEM_ENDL +
						 MESSAGE_DISPLAY_END + formatDate(task.endDate, shouldShowYear, shouldBeDetailed) + MESSAGE_DISPLAY_SPACE_FORMATTING + formatTime(task.endTime, shouldBeDetailed) + SYSTEM_ENDL;
			delete taskList;
		} else {
			successful = MESSAGE_OUT_OF_RANGE_INDEX;
		}
	}

	else if(command ==  KEYWORD_UNDO) {
		if(userCommand.undo()) {
			successful = MESSAGE_UNDO_SUCCESSFUL;
		} else {
			successful = MESSAGE_UNDO_FAILED;
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

vector<Task>* Worker::getSearchedList() {
	vector<Task>* displayedTaskList = userCommand.getSearchedList();

	bool shouldShowEndTime = false;
	convertTaskDataToDisplayFormat(*displayedTaskList, shouldShowEndTime);

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
			taskIndex = TASK_INDEX_FORMATTING + taskIndex;
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

	if (!sDate.empty() && sDate != DAY_0) {
			date = stoi(sDate);
			
			year = date/10000;
			sYear = " " + to_string(year);

			date %= 10000;
			month = date/100;
			//assert(1 <= month && month <= 12);
			switch (month) {
			case 1:
				sMonth = FORMAT_MONTH_1;
				break;
			case 2:
				sMonth = FORMAT_MONTH_2;
				break;
			case 3:
				sMonth = FORMAT_MONTH_3;
				break;
			case 4:
				sMonth = FORMAT_MONTH_4;
				break;
			case 5:
				sMonth = FORMAT_MONTH_5;
				break;
			case 6:
				sMonth = FORMAT_MONTH_6;
				break;
			case 7:
				sMonth = FORMAT_MONTH_7;
				break;
			case 8:
				sMonth = FORMAT_MONTH_8;
				break;
			case 9:
				sMonth = FORMAT_MONTH_9;
				break;
			case 10:
				sMonth = FORMAT_MONTH_10;
				break;
			case 11:
				sMonth = FORMAT_MONTH_11;
				break;
			case 12:
				sMonth = FORMAT_MONTH_12;
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
				resultDate = NULL_STRING;
			}
		} else {
			if (shouldBeDetailed) {
				resultDate = TASK_EMPTY_TIME;
			}
		}
	return resultDate;
}

string Worker::formatTime(string sTime, bool shouldBeDetailed) {
	string time = sTime;
	string resultTime;
	bool isKnownTimeFormat = time.size() == 4;

	if (!time.empty() && time != TIME_0) {
		// Digital clock display
		//assert(time.size() <= 4);
		if (isKnownTimeFormat) {
			time.insert(2, TASK_TIME_FORMATTING);
			resultTime = time;
		} else {
			resultTime = NULL_STRING;
		}
	} else {
		if (shouldBeDetailed) {
			resultTime = TASK_EMPTY_TIME;
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



