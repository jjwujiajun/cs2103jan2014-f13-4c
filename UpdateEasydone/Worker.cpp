/*  Worker cpp

Implementation for the worker class in which based on the
command entered by the user, the appropriate function is called to carry
out the desired operation.

*/
#include "Worker.h"
#include "store.h"

const string Worker::NULL_STRING = "";
const string Worker::MESSAGE_ADDED_SUCCESSFULLY = "has been added successfully";
const string Worker::MESSAGE_DELETED_SUCCESSFULLY = "has been deleted successfully";
const string Worker::MESSAGE_UPDATED_SUCCESSFULLY = "has been updated successfully"; 
const string Worker::MESSAGE_CHECKED_SUCCESSFULLY = "has been checked off your EasyDone task list";
const string Worker::MESSAGE_ERROR = "Error: Task cannot be found";
const int NULL_DATE = -1;

// const string Parser::MESSAGE_DELETE = "delete";

Worker::Worker() {
	//Jobs Task;
	taskIndexIssuer = Task.storageSize();

	for(int i=0; i<taskIndexIssuer; i++) {
		todoList[i].index = i+1;
		todoList[i].taskName = Task.taskname();
		todoList[i].venue = Task.venue();
		todoList[i].date = Task.date();
		todoList[i].month = Task.month();
		todoList[i].year = Task.year();
		todoList[i].startTime = Task.startTime();
		todoList[i].endTime = Task.endTime();
		todoList[i].isCompleted = Task.isCompleted();
	//	todoList[i].hasAvailableSlot = Task.hasAvailableSlot();
	}
}

Worker::~Worker() {
	taskIndexIssuer;	// save the state of issuer pls
}



// todoList functions
string Worker::addTask(vector<string> input) {

	Task newTask;

	newTask.index = 
	newTask.taskName = taskName;
	newTask.venue = venue;
	newTask.date = date;
	newTask.month = month;
	newTask.year = year;
	newTask.startTime = startTime;
	newTask.endTime = endTime;
	
	/* Put conversion in parser
	newTask.startTime =  atoi(startTime.c_str()); // convert string to integer
	newTask.startDate = atoi(startDate.c_str());
	newTask.endTime = atoi(endTime.c_str());
	newTask.endDate = atoi(endDate.c_str());
	*/

	todoList.push_back(newTask);

	return MESSAGE_ADDED_SUCCESSFULLY;



}

string Worker::removeTaskWithIndex(int index) {
	for (iter = todoList.begin(); iter != todoList.end(); ++iter) {

	if (iter->index == index) {
	todoList.erase(iter);			
	//highly inefficient accord to c++ lib. vector efficient for accessing vector[]. List efficient for insertion/deletion
	} else {
	cout << MESSAGE_ERROR << endl;
	}
	
	}
	return MESSAGE_DELETED_SUCCESSFULLY;
	
}


string Worker::updateTaskWithIndex(int index, string update, string updateField) {
	/*int item = searchForTaskWithIndex(index);

	if (taskName != NULL_STRING) {
	todoList[item].taskName = taskName;
	}
	if (reminder != NULL_STRING) {
	todoList[item].reminder = reminder;
	}
	if (duplicate != NULL_STRING) {
	todoList[item].duplciate = duplicate;
	}
	if (startDate != NULL_DATE) {
	todoList[item].startDate = startDate;
	}
	if (startTime != NULL_DATE) {
	todoList[item].startTime = startTime;
	}
	if (endDate != NULL_DATE) {
	todoList[item].endDate = endDate;
	}
	if (endTime != NULL_DATE) {
	todoList[item].endTime = endTime;
	}*/

	return MESSAGE_UPDATED_SUCCESSFULLY;
}

void Worker::displayTaskWithIndex(int index) {

	
	for (iter = todoList.begin(); iter != todoList.end(); ++iter) {
		cout << index;
	}
}

string Worker::markDoneTaskWithIndex(int index) {
	/*int item = searchForTaskWithIndex(index);

	if (todoList[item].isCompleted == false) {
	todoList[item].isCompleted = true;
	}*/

	return MESSAGE_CHECKED_SUCCESSFULLY;
}

int Worker::searchTasks(string keyWord){
	/*int i = 0;
	for (iter = todoList.begin(); iter != todoList.end(); ++iter, ++i) {
	if (iter->index == index) {
	return i;
	}
	}
	return -1;*/

	return 6;
}

// support functions
int Worker::issueNewIndex(){
	

	taskIndexIssuer++;

	return taskIndexIssuer;
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



