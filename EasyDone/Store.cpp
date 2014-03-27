#include "Store.h"


Store::Store() {
	
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

void Store::switchTask(int slot1, int slot2) {
	Task tempTask = taskList[slot1];
	taskList[slot1] = taskList[slot2];
	taskList[slot2] = tempTask;
}

void Store::changeTask(int slot, Task slotTask) {
	taskList[slot] = slotTask;
}

bool Store::eraser(string taskIndex) {
	bool erased = false;
	int slot=0;

	for(int i = 0; i<taskList.size(); i++) {
		if(taskList[i].taskID == taskIndex) {
			slot = i;
			erased = true;
			break;
		}
	}
	for(slot; slot<taskList.size()-1; slot++){
		taskList[slot+1].taskID = to_string(slot+1);
		taskList[slot] = taskList[slot+1];
	}
	taskList.pop_back();
	
	return erased;
}

Task Store::accesswithTaskID(int indexEntered) {
	
	string convertedIndex = to_string(indexEntered);

	for(int i=0; i < taskList.size(); i++) {

		if(taskList[i].taskID == convertedIndex) {

			return taskList[i];
		}

		//need an else case but idk how to do that LOL cause I am returning a Task data type ahem ok wtv or like if list is empty

	}

}

void Store::pushback(Task newTask) {

	taskList.push_back(newTask);

}

Task Store::getTask(int slot) {

	return taskList[slot];
}
	
bool Store::changeTask(int Index, Task userTask, string updateField) {
	if(updateField == "taskName") {
		taskList[Index].taskName = userTask.taskName;
	} else if(updateField == "startDate") {
		taskList[Index].startDate = userTask.startDate;
	} else if(updateField == "startTime") {
		taskList[Index].startTime = userTask.startTime;
	} else if(updateField == "endDate") {
		taskList[Index].endDate = userTask.endDate;
	} else if(updateField == "endTime") {
		taskList[Index].endTime = userTask.endTime;
	}
	return true;
}

void Store::dueToday() {
	
	for(int i = 0; i < taskList.size(); i++) {
		if(taskList[i].startDate == "20140321") {
			taskList[i].isBold = true;
		}
		else {
			taskList[i].isBold = false;
		}
	}
}

vector<Task> Store::getTaskList() {

	vector<Task> duplicated;
	duplicated = taskList;

	return duplicated;
}

bool Store::stackToList() {
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





