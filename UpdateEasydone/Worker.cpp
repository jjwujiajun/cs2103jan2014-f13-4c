/*  Worker cpp

 Implementation for the worker class in which based on the
 command entered by the user, the appropriate function is called to carry
 out the desired operation.

 */
#include "Worker.h"

Worker::Worker() {
	taskIndexIssuer = 0;
}

// todoList functions
void Worker::addTask(string taskName, string additionalDetails, string reminder, string duplicate, int startDate, int startTime, int endDate, int endTime) {
	
	Task newTask;
	newTask.index = issueNewIndex();
	newTask.taskName = taskName;
	newTask.additionalDetails = additionalDetails;
	newTask.reminder = reminder;
	newTask.duplciate = duplicate;
	newTask.startDate = startDate;
	newTask.startTime = startTime;
	newTask.endDate = endDate;
	newTask.endTime = endTime;
	newTask.isCompleted = false;
	newTask.hasAvailableSlot = checkListForSlotFor(newTask);

	todoList.push_back(newTask);
}

void Worker::removeTaskWithIndex(int index) {
	for (iter = todoList.begin(); iter != todoList.end(); ++iter) {
		if (iter->index == index) {
			todoList.erase(iter);			
			//highly inefficient accord to c++ lib. vector efficient for accessing vector[]. List efficient for insertion/deletion
			return;
		}
		//cout << Error: Task cannot be found.
	}
}

void Worker::updateTaskWithIndex(int index, string taskName, string additionalDetails, string reminder, string duplicate, int startDate, int startTime, int endDate, int endTime) {
	int item = searchForTaskWithIndex(index);

	if (taskName != "") {
		todoList[item].taskName = taskName;				// to be refactored to string nullString = "";
	}
	if (additionalDetails != "") {
		todoList[item].additionalDetails = additionalDetails;
	}
	if (reminder != "") {
		todoList[item].reminder = reminder;
	}
	if (duplicate != "") {
		todoList[item].duplciate = duplicate;
	}
	if (startDate != -1) {								// to be refactor to int nullDate = -1;
		todoList[item].startDate = startDate;
	}
	if (startTime != -1) {
		todoList[item].startTime = startTime;
	}
	if (endDate != -1) {
		todoList[item].endDate = endDate;
	}
	if (endTime != -1) {
		todoList[item].endTime = endTime;
	}
}

void Worker::markDoneTaskWithIndex(int index){
	int item = searchForTaskWithIndex(index);
	
	if (todoList[item].isCompleted == false) {
		todoList[item].isCompleted == true;
	}
}
	
// support functions
int Worker::issueNewIndex(){
	taskIndexIssuer++;

	return taskIndexIssuer;
}

int Worker::searchForTaskWithIndex(int index){
	int i = 0;
	for (iter = todoList.begin(); iter != todoList.end(); ++iter, ++i) {
		if (iter->index == index) {
			return i;
		}
	}
	return -1;
}

bool Worker::checkListForSlotFor(Task newTask){
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
}



