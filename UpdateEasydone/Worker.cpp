/*  Worker cpp

Implementation for the worker class in which based on the
command entered by the user, the appropriate function is called to carry
out the desired operation.

*/
#include "Worker.h"
#include "Store.h"

const string Worker::NULL_STRING = "";
const string Worker::MESSAGE_ADDED_SUCCESSFULLY = "has been added successfully! :) ";
const string Worker::MESSAGE_DELETED_SUCCESSFULLY = "has been deleted successfully! :)";
const string Worker::MESSAGE_UPDATED_SUCCESSFULLY = "has been updated successfully! :) "; 
const string Worker::MESSAGE_CHECKED_SUCCESSFULLY = "has been checked off your EasyDone task list! :)";
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
	 startDate = parsedCommandstring[2];
	 startTime = parsedCommandstring[3];
	 endDate = parsedCommandstring[4];
	 endTime = parsedCommandstring[5];
	 index = parsedCommandstring[6];
	 fieldtoUupdate = parsedCommandstring[7];
	 updateContent = parsedCommandstring[8]; 

	string returnStringtomain = actonCommand(command);

	return returnStringtomain;
}

string Worker::actonCommand(string command)
{
	/*

	if(command == "add" || "create" ) {
		successful = addTask();
		
	}

	else if(command == "delete" || "remove") {
		successful = removeTaskWithIndex();
	}


	else if(command == "update" || "modify") {
		successful = updateTaskWithIndex();
	}

	else if(command ==  "display" || "show") {
		//successful = display();
	}
		

	return successful;
	*/

	return "abc";
}
	



string Worker::addTask() {
	/*

	int vectindexofNexttask = todoList.getSize() - 1;

	todoList.accessSlot(vectindexofNexttask).taskName = taskName;
	todoList.accessSlot(vectindexofNexttask).startDate = startDate;
	todoList.accessSlot(vectindexofNexttask).startTime = startTime;
	todoList.accessSlot(vectindexofNexttask).endDate = endDate;
	todoList.accessSlot(vectindexofNexttask).endTime = endTime;
	ostringstream lala; 
	lala << issueNewIndex();
    string converting = lala.str();
	todoList.accessSlot(vectindexofNexttask).index = converting;
		
	



	*/

	
	return "abds";

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



int Worker::issueNewIndex(){
	/*
	int size_todoList =  todoList.getSize();
	int newindex = size_todoList++;
	*/
	return 1;
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



