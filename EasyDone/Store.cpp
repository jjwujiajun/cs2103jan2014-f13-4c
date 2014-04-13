#include "Store.h"


Store::Store() {
	taskList.clear();
	taskList = file.getTaskList();
	undoList.clear();
}

Store::~Store() {
	undoList.clear();
	file.saveTaskList(taskList);
}

string Store::getTaskName(int index) {

	int size = taskList.size();
	// Asserts that the index is within the task list range.
	assert(index <= size);
	
	string taskName1 = taskList[index-1].taskName;

	return taskName1;
}

string Store::getStartTime(int index) {

	int size = taskList.size();
	// Asserts that the index is within the task list range.
	assert(index <= size);

	string startTime1=  taskList[index-1].startTime;
	
	return startTime1;
}

string Store::getEndTime(int index) {

	int size = taskList.size();
	// Asserts that the index is within the task list range.
	assert(index <= size);

	string endTime1=  taskList[index-1].startTime;
	
	return endTime1;
}

string Store::getStartDate(int index) {

	int size = taskList.size();
	// Asserts that the index is within the task list range.
	assert(index <= size);

	string startDate1 = taskList[index-1].startDate;
	
	return startDate1;
}

string Store::getEndDate(int index) {

	int size = taskList.size();
	// Asserts that the index is within the task list range.
	assert(index <= size);

	string getEndDate1 = taskList[index-1].endDate;
	
	return getEndDate1;
}

int Store::getSize() {

	int sizeoftaskList = taskList.size();

	return sizeoftaskList;
}

string Store::getTaskID(int slotNumber) {

	int size = taskList.size();
	// Asserts that the slotNumber is within the task list range.
	assert(slotNumber <= size);

	string taskID = taskList[slotNumber].taskID;

	return taskID;
}

Task Store::accessSlot(int slot) {

	int size = taskList.size();
	// Asserts that the slot is within the task list range.
	assert(slot <= size);

	Task toReturn = taskList[slot];
	return toReturn;
}


vector<Task>::iterator Store::getIteratorBegin() {
	
	vector<Task>::iterator iter;
	iter = taskList.begin(); 

	return iter;
}

vector<Task>::iterator Store::getIteratorEnd() {
	
	vector<Task>::iterator iter;
	iter = taskList.end();

	return iter;
}

void Store::saveToFile() {
	log.log("Store: saving to file");
	file.saveTaskList(taskList);
}

void Store::switchTask(int slot1, int slot2) {

	int size = taskList.size();
	// Asserts that slot1 and slot2 are within the task list range.
	assert(slot1 < size);
	assert(slot2 < size);

	log.log("Store: switching task");
	Task tempTask = taskList[slot1];
	taskList[slot1] = taskList[slot2];
	taskList[slot2] = tempTask;
}

void Store::changeTask(int slot, Task slotTask) {
	
	int size = taskList.size();
	// Asserts that slot and slotTask's task ID are within the task list range.
	assert(slot < size);
	assert(stoi(slotTask.taskID) <= size);

	log.log("Store: changing task");
	taskList[slot] = slotTask;
}

bool Store::eraser(string taskIndex) {

	int size = taskList.size();
	// Asserts that the taskIndex is within the task list range.
	assert(stoi(taskIndex) <= size);

	log.log("Store: erasing task");
	bool erased = false;
	int slot=0;

	for(int i = 0; i < (int) taskList.size(); i++) {
		if(taskList[i].taskID == taskIndex) {
			slot = i;
			erased = true;
			break;
		}
	}
	for(slot; slot < (int) taskList.size()-1; slot++){
		taskList[slot+1].taskID = to_string(slot+1);
		taskList[slot] = taskList[slot+1];
	}
	taskList.pop_back();
	log.log("Store: task erased");

	return erased;
}

Task Store::accesswithTaskID(int indexEntered) {
	
	int size = taskList.size();
	// Asserts that the indexEntered is within the task list range.
	assert(indexEntered <= size);

	string convertedIndex = to_string(indexEntered);

	for(int i=0; i < (int) taskList.size(); i++) {

		if(taskList[i].taskID == convertedIndex) {

			return taskList[i];
		}

		//need an else case but idk how to do that LOL cause I am returning a Task data type ahem ok wtv or like if list is empty

	}

}

void Store::pushback(Task newTask) {

	int size = taskList.size() + 1;
	// Asserts that the task ID is within the task list range.
	assert(stoi(newTask.taskID) <= size);

	newTask.isDone = false;
	taskList.push_back(newTask);

}

Task Store::getTask(int slot) {

	// Asserts that the slot is within the task list range.
	assert(slot < taskList.size());

	return taskList.at(slot);
}

bool Store::MarkDone(Task task) {

	int size = taskList.size();
	// Asserts that the task ID is within the task list range.
	assert(stoi(task.taskID) <= size);

	bool done = false;
	int counter = 0;
	while(counter <getSize()) {
		if(taskList[counter].taskID == task.taskID) {
			taskList[counter].isDone = true;
			done = true;
			counter++;
		}
	}
	return done;
}
	
string Store::changeTask(int Index, Task userTask, string updateField) {
	log.log("Store: updating a task field");

	int size = taskList.size();
	// Asserts that the Index and userTask's task ID are within the task list range.
	assert(stoi(userTask.taskID) <= size);
	assert(Index <= size);

	if(updateField == "task") {
		taskList[Index].taskName = userTask.taskName;
	} else if(updateField == "sd") {
		taskList[Index].startDate = userTask.startDate;
	} else if(updateField == "st") {
		taskList[Index].startTime = userTask.startTime;
	} else if(updateField == "ed") {
		//Exception handler for start date and end date. Throws exception if start date comes after end date.
		if(!taskList[Index].startDate.empty()) {
			if(stoi(taskList[Index].startDate) > stoi(userTask.endDate)) {
				return "startDate";
			}
		} else {
			taskList[Index].endDate = userTask.endDate;
		}
	} else if(updateField == "et") {
		//Exception handler for start time and end time. Throws exception
		if(!taskList[Index].startDate.empty() && !taskList[Index].endDate.empty()) {
			if(taskList[Index].startDate == taskList[Index].endDate) {
				if(taskList[Index].startTime > userTask.endTime) {
					return "startTime";
				} else {
					taskList[Index].endTime = userTask.endTime;
				}
			} else {
				taskList[Index].endTime = userTask.endTime;
			}
		}
	}
	log.log("Store: field updated");
	return "true";
}

bool Store::SearchItem(int Index, string searchField, string searchItem) {

	int size = taskList.size();
	// Asserts that the Index is within the task list range.
	assert(Index <= size);

	log.log("Store: searching the task");
	bool found = false;
	
	searchTask.clear();

	while(Index < getSize()) {
		if(searchField == "task") {
			if(taskList[Index].taskName.find(searchItem) != string::npos) {
				searchTask.push_back(taskList[Index]);
				found = true;
			}
		} else if(searchField == "sd") {
			if(taskList[Index].startDate.find(searchItem) != string::npos)
				searchTask.push_back(taskList[Index]);
				found = true;
		} else if(searchField == "st") {
			if(taskList[Index].startTime.find(searchItem) != string::npos)
				searchTask.push_back(taskList[Index]);
				found = true;
		} else if(searchField == "ed") {
			if(taskList[Index].endDate.find(searchItem) != string::npos)
				searchTask.push_back(taskList[Index]);
				found = true;
		} else if(searchField == "et") {
			if(taskList[Index].endTime.find(searchItem) != string::npos)
				searchTask.push_back(taskList[Index]);
				found = true;
		}
		Index++;
	}
	log.log("Store: finished searching");
	
	return found;
}

vector<Task> Store::getTaskList() {

	vector<Task> duplicated;
	duplicated = taskList;

	return duplicated;
}

vector<Task> Store::getSearchedList() {
	return searchTask;
}

void Store::undoUndoList() {
	undoList.pop_back();
}

bool Store::stackToList() {
	log.log("Store: undoing the change in list");
	bool undo = false;
	if(undoList.size()!=0) {
		vector<Task> temp = undoList.back();
		taskList.clear();
		while(!temp.empty()) {
			taskList.push_back(temp.back());
			temp.pop_back();
		}
		undoList.pop_back();
		undo = true;
	}
	return undo;
}

void Store::listToStack() {
	log.log("Store: saving the change in list");
	vector<Task> temp;
	Task tempTask;
	vector<Task> copyList = taskList;
	int i = copyList.size();
	while(!copyList.empty()) {
		i--;
		tempTask = copyList[i];
		copyList.pop_back();
		temp.push_back(tempTask);
	}
	undoList.push_back(temp);
}

void Store::updateTaskID() {
	for(int i = 0; i < (int) taskList.size(); i++) {
		taskList[i].taskID = to_string(i+1);
	}
}

string Store::currentDay() {

	time_t rawtime;
	time(&rawtime);

	tm now;
	localtime_s(&now, &rawtime);

	int nowDay = (&now)->tm_mday; 
	
	ostringstream convert;   // stream used for the conversion

	convert << nowDay; 

	string nowDaystr = convert.str();

	if (nowDaystr.length() == 1)
        nowDaystr.insert(0, "0");

	//return nowDaystr;

	return nowDaystr;

}

string Store::currentMonth() {

	time_t rawtime;
	time(&rawtime);

	tm now;
	localtime_s(&now, &rawtime);

	int nowMonth = (&now)->tm_mon; 
	nowMonth =  nowMonth + 1;
	
	ostringstream convert;   // stream used for the conversion

	convert << nowMonth; 

	string nowMonthstr = convert.str();

	if (nowMonthstr.length() == 1)
        nowMonthstr.insert(0, "0");

	return nowMonthstr;
}

string Store::currentYear() {

	time_t rawtime;
	time(&rawtime);

	tm now;
	localtime_s(&now, &rawtime);

	int nowYear = 1900 + (&now)->tm_year;  
	
	ostringstream convert;   // stream used for the conversion

	convert << "2014"; 

	string nowYearstr = convert.str();

	return nowYearstr;

}

string Store::getDay(int index) {   
	//only meant for startDate

	int size = taskList.size();
	// Asserts that the index is within the task list range.
	assert(index <= size);

	string dateSize = taskList[index].startDate;

	int lenDate = (dateSize).size();

	//Exception handling for empty start date. Throws "0" when no start date is available for the task.
	if(lenDate == 8) {
	string date = taskList[index].startDate;
	string day = date.substr(6,2);

	return day;
	}

	else return "0";

}

string Store::getMonth(int index) {

	int size = taskList.size();
	// Asserts that the index is within the task list range.
	assert(index <= size);
	
	string dateSize = taskList[index].startDate;

	int lenDate = (dateSize).size();

	//Exception handling for empty start date. Throws "0" when no start date is available for the task.
	if(lenDate == 8) {
	string date = taskList[index].startDate;
	string month = date.substr(4,2);

	return month;
	}

	else return "0";
	
}

string Store::getYear(int index) {

	int size = taskList.size();
	// Asserts that the index is within the task list range.
	assert(index <= size);

	string dateSize = taskList[index].startDate;

	int lenDate = (dateSize).size();

	//Exception handling for empty start date. Throws "0" when no start date is available for the task.
	if(lenDate == 8) {
	string date = taskList[index].startDate;
	string year =  date.substr(0,4);

	return year;
	}
          
	else return "0";
}

void Store::markTasksDueToday() {
	log.log("Store: changing due status");

	string todayDay = currentDay();
	string todayMonth = currentMonth();
	string todayYear = currentYear();


	for(int i = 0; i <  taskList.size(); i++) {

		if(getDay(i) == todayDay  && getMonth(i) == todayMonth && getYear(i) == todayYear) {
			taskList[i].isBold = true;
		}
		else {
			taskList[i].isBold = false;
		}
	}
}

vector<string> Store::getDateTomorrow() {

	string todayDay = currentDay();
	string todayMonth = currentMonth();
	string todayYear = currentYear();

	if (todayDay[0] == 0)
        todayDay = todayDay[1];
	if (todayMonth[0] == 0)
        todayMonth = todayMonth[1];

	int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	int valueDay = atoi(todayDay.c_str());
	int valueMonth = atoi(todayMonth.c_str());
	int valueYear = atoi(todayYear.c_str());

	valueDay++;

	if ( valueDay > days[valueMonth-1]){
		
		valueDay = 1;
		valueMonth++;

		if ( valueMonth > 12 ) {

			valueYear++; 
			valueMonth=1;
		}
	 }

	// stream used for the conversion
	ostringstream convert1;   

	convert1 << valueDay;

	string tomorrowDay = convert1.str();

	if(tomorrowDay.length() == 1)
		tomorrowDay.insert(0, "0");
	
	ostringstream convert2;

	convert2 << valueMonth;

	string tomorrowMonth = convert2.str();

	if (tomorrowMonth.length() == 1)
        tomorrowMonth.insert(0, "0");

	ostringstream convert3;

	convert3 << valueYear;

	string tomorrowYear = convert3.str();

	vector<string> returnedVector;

	returnedVector.push_back(tomorrowDay);
	returnedVector.push_back(tomorrowMonth);
	returnedVector.push_back(tomorrowYear);

	return returnedVector;
} 

//implemented for non-leap years
void Store::markTasksDueTomorrow() { 

	vector<string> returnedVector = getDateTomorrow();
	
	string tomorrowDay = returnedVector[0];
	string tomorrowMonth = returnedVector[1];
	string tomorrowYear = returnedVector[2];


	for(int i =0; i < taskList.size(); i++) {

		if(getDay(i) ==  tomorrowDay && getMonth(i) == tomorrowMonth && getYear(i) == tomorrowYear) {

			taskList[i].isTomorrow = true;
		}
		else
			taskList[i].isTomorrow = false;
	}
		
		//taskList[1].isTomorrow = true;

	
} //this returns the tasks marked with tomorrow! now check if tomorrow really works!


void Store::markTasksOverdue() {

	string todayDay = currentDay();
	string todayMonth = currentMonth();
	string todayYear = currentYear();


	for(int i = 0; i < taskList.size(); i++) {

		string conjoint = todayYear + todayMonth + todayDay; 
		string taskDate = taskList[i].endDate;

		if(taskDate.size() == 8 && taskDate < conjoint && taskList[i].isDone ==  false) {
			taskList[i].isRed = true; 
		}

		else
			taskList[i].isRed = false;
	}


	/*for(int i = 0;i < taskList.size(); i++)
	{
		Task task = taskList[i];

		//task.isRed = false;

		string taskDay =  getDay(i);
		string taskMonth = getMonth(i);
		string taskYear = getYear(i);

		if(todayYear > taskYear) {

			task.isRed = true;
		}

		else if (todayYear == taskYear) {

			if(todayMonth > taskMonth) {

				task.isRed = true;
			}

		}

		else if (todayYear == taskYear) { 

			if(todayMonth ==  taskMonth) {
				 
				if(todayDay > taskDay) {

					task.isRed = true;
				}
			}
		}

		else if (todayYear == taskYear) { 

			if(todayMonth ==  taskMonth) {
				 
				if(todayDay == taskDay) {

					task.isRed = false;
				}
			}
		}

	}*/

//	Task task = taskList[1];
//	task.isRed = true;

}