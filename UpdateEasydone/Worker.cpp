/*  Worker cpp

Implementation for the worker class in which based on the
command entered by the user, the appropriate function is called to carry
out the desired operation.

*/
#include "Worker.h"
#include "Store.h"

const string Worker::NULL_STRING = "";
const string Worker::MESSAGE_ADDED_SUCCESSFULLY = "has been added successfully";
const string Worker::MESSAGE_DELETED_SUCCESSFULLY = "has been deleted successfully";
const string Worker::MESSAGE_UPDATED_SUCCESSFULLY = "has been updated successfully"; 
const string Worker::MESSAGE_CHECKED_SUCCESSFULLY = "has been checked off your EasyDone task list";
const int NULL_DATE = -1;

// const string Parser::MESSAGE_DELETE = "delete";

Worker::Worker() {


}

Worker::~Worker() {
	taskIndexIssuer;	// save the state of issuer pls
}


string Worker::takeparsedCommand(vector<string> parsedCommandstring) {

	 command =  parsedCommandstring[0];
	 taskName = parsedCommandstring[1];
	 day = parsedCommandstring[2];
	 month = parsedCommandstring[3];
	 year = parsedCommandstring[4];
	 venue = parsedCommandstring[5];

	string returnStringtomain = actonCommand(command);


}

string Worker::actonCommand(string command)
{


	switch (command) {
	case "add" || "create":
		bool successful = addTask();
		string returnstring =  "add successful!" 
		break;
	case "delete" || "remove":
		bool successful = removeTaskWithIndex();
		break;
	case "display" || "show":
		break;
	case "update" || "change":
		break;
	default:
		return "Please enter a valid command!";






}


bool Worker::addTask(string taskName, string date, string month, string year, string venue){

	

}

string Worker::removeTaskWithIndex(int index) {
	/*for (iter = todoList.begin(); iter != todoList.end(); ++iter) {
	if (iter->index == index) {
	todoList.erase(iter);			
	//highly inefficient accord to c++ lib. vector efficient for accessing vector[]. List efficient for insertion/deletion
	return;
	}
	//cout << Error: Task cannot be found.
	}*/

	return MESSAGE_DELETED_SUCCESSFULLY;
}

string Worker::updateTaskWithIndex(int index, string update, string updateField) {
	/*int item = searchForTaskWithIndex(index);

	if (taskName != NULL_STRING) {
	todoList[item].taskName = taskName;
	}
	if (additionalDetails != NULL_STRING) {
	todoList[item].additionalDetails = additionalDetails;
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

string Worker::markDoneTaskWithIndex(int index) {
	/*int item = searchForTaskWithIndex(index);

	if (todoList[item].isCompleted == false) {
	todoList[item].isCompleted = true;
	}*/

	return MESSAGE_CHECKED_SUCCESSFULLY;
}


int Worker::issueNewIndex(){
	
	vector<string> duplicatedtodoList = todoList.getDuplicatevector(todoList);
	int size_todoList = duplicatedtodoList.size();

	int newindex = size_todoList++;

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



