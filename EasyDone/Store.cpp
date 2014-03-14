#include "Store.h"



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

bool Store::eraser(string taskIndex) {
	vector<Task>::iterator iter;
	int i = 0;
	bool erased = false;
	//JJ commented this. Will not be shown by GUIFeedback. Find a way to "cout" to GUITaskListBox.
	//cout<<iter->taskID<<taskIndex<<endl;
	int j;
	cin>>j;
	for(iter = taskList.begin(); iter < taskList.end(); iter++){
		//cout<<iter->taskID<<taskIndex<<endl;
		if(iter->taskID == taskIndex)
		{
			taskList.erase(iter);
			erased = true;
			break;
		}
	}
	/*
	int slot;
	bool erased = false;
	for(int i = 0; i<taskList.size(); i++) {
		if(taskList[i].taskID == taskIndex) {

	*/
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

void Store::insert(Task newTask) {

	taskList.push_back(newTask);

}

Task Store::getTask(int slot) {

	return taskList[slot];
}
	
