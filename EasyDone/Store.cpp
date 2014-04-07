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
	
	string taskName1 = taskList[index-1].taskName;

	return taskName1;
}

string Store::getStartTime(int index) {
	string startTime1=  taskList[index-1].startTime;
	
	return startTime1;
}

string Store::getEndTime(int index) {
	string endTime1=  taskList[index-1].startTime;
	
	return endTime1;
}

string Store::getStartDate(int index) {
	string startDate1 = taskList[index-1].startDate;
	
	return startDate1;
}

string Store::getEndDate(int index) {

	string getEndDate1 = taskList[index-1].endDate;
	
	return getEndDate1;
}

int Store::getSize() {

	int sizeoftaskList = taskList.size();

	return sizeoftaskList;
}

string Store::getTaskID(int slotNumber) {

	string taskID = taskList[slotNumber].taskID;

	return taskID;
}

Task Store::accessSlot(int slot) {

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
	log.log("Store: switching task");
	Task tempTask = taskList[slot1];
	taskList[slot1] = taskList[slot2];
	taskList[slot2] = tempTask;
}

void Store::changeTask(int slot, Task slotTask) {
	log.log("Store: changing task");
	taskList[slot] = slotTask;
}

bool Store::eraser(string taskIndex) {
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
	
	string convertedIndex = to_string(indexEntered);

	for(int i=0; i < (int) taskList.size(); i++) {

		if(taskList[i].taskID == convertedIndex) {

			return taskList[i];
		}

		//need an else case but idk how to do that LOL cause I am returning a Task data type ahem ok wtv or like if list is empty

	}

}

void Store::pushback(Task newTask) {
	newTask.isDone = false;
	taskList.push_back(newTask);

}

Task Store::getTask(int slot) {

	return taskList.at(slot);
}

bool Store::MarkDone(Task task) {
	bool done = false;
	int counter = 0;
	while(counter <getSize()) {
		if(taskList[counter].taskID == task.taskID) {
			taskList[counter].isDone = true;
			done = true;
		}
	}
	return done;
}
	
bool Store::changeTask(int Index, Task userTask, string updateField) {
	log.log("Store: updating a task field");
	if(updateField == "task") {
		taskList[Index].taskName = userTask.taskName;
	} else if(updateField == "sd") {
		taskList[Index].startDate = userTask.startDate;
	} else if(updateField == "st") {
		taskList[Index].startTime = userTask.startTime;
	} else if(updateField == "ed") {
		taskList[Index].endDate = userTask.endDate;
	} else if(updateField == "et") {
		taskList[Index].endTime = userTask.endTime;
	}
	log.log("Store: field updated");
	return true;
}

bool Store::SearchItem(int Index, string searchField, string searchItem) {
	log.log("Store: searching the task");
	bool found = false;
	
	//JJ add
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

/*void Store::markTasksDueToday() {
	log.log("Store: changing due status");
	for(int i = 0; i < (int) taskList.size(); i++) {
		if(taskList[i].startDate == "20140404") {
			taskList[i].isBold = true;
		}
		else {
			taskList[i].isBold = false;
		}
	}
}*/

vector<Task> Store::getTaskList() {

	vector<Task> duplicated;
	duplicated = taskList;

	return duplicated;
}

vector<Task> Store::getSearchedList() {
	return searchTask;
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
	//only works for startDate

	string dateSize = taskList[index].startDate;

	int lenDate = (dateSize).size();

	if(lenDate == 8) {
	string date = taskList[index].startDate;
	string day = date.substr(6,2);

	return day;
	}

	else return "0";

}

string Store::getMonth(int index) {
	
	string dateSize = taskList[index].startDate;

	int lenDate = (dateSize).size();

	if(lenDate == 8) {
	string date = taskList[index].startDate;
	string month = date.substr(4,2);

	return month;
	}

	else return "0";
	
}

string Store::getYear(int index) {

	string dateSize = taskList[index].startDate;

	int lenDate = (dateSize).size();

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

		/*if(taskList[i].startDate == "20140407")
		{
			taskList[i].isBold = true;
		}

		else 
			taskList[i].isBold = false;*/

	}
}

void Store::getDateTomorrow() {

	string todayDay = currentDay();
	string todayMonth = currentMonth();
	string todayYear = currentYear();

	int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	int valueDay = atoi(todayDay.c_str());
	int valueMonth = atoi(todayMonth.c_str());
	int valueYear = atoi(todayYear.c_str());

	valueDay++;

	if ( valueDay > days[valueMonth-1]){
		
		valueDay = 1;
		valueMonth++;

		if ( valueMonth > 12 ) {
			{ valueYear++; valueMonth=1; }
		}
	 }

	
	ostringstream convert;   // stream used for the conversion

	convert << valueDay;

	string tomorrowDay = convert.str();

	if(tomorrowDay.length() == 1)
		tomorrowDay.insert(0, "0");

	convert << valueMonth;

	string tomorrowMonth = convert.str();

	if (tomorrowMonth.length() == 1)
        tomorrowMonth.insert(0, "0");

	convert << valueYear;

	string tomorrowYear = convert.str();
}

void Store::markTasksDueTomorrow() { //implemented for non-leap years

	
	for(int i =0; i < taskList.size(); i++) {

		if(getDay(i) ==  tomorrowDay && getMonth(i) == tomorrowMonth && getYear(i) == tomorrowYear) {

			taskList.at(i).isTomorrow = true;
		}
		else
			taskList.at(i).isTomorrow = false;


	}
	
} 

void Store::markTasksOverdue() {

	string todayDay = currentDay();
	string todayMonth = currentMonth();
	string todayYear = currentYear();


	for(int i = 0;i < taskList.size(); i++)
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

	}

}