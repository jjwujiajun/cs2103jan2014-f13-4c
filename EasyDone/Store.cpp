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

	return taskList[slot];
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
			if(taskList[Index].taskName == searchItem)
				searchTask.push_back(taskList[Index]);
				found = true;
		} else if(searchField == "st") {
			if(taskList[Index].taskName == searchItem)
				searchTask.push_back(taskList[Index]);
				found = true;
		} else if(searchField == "ed") {
			if(taskList[Index].taskName == searchItem)
				searchTask.push_back(taskList[Index]);
				found = true;
		} else if(searchField == "et") {
			if(taskList[Index].taskName == searchItem)
				searchTask.push_back(taskList[Index]);
				found = true;
		}
		Index++;
	}
	log.log("Store: finished searching");
	
	return found;
}

void Store::dueToday() {
	log.log("Store: changing due status");
	for(int i = 0; i < (int) taskList.size(); i++) {
		if(taskList[i].startDate == "20140403") {
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




