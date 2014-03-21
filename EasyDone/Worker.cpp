/*  Worker cpp

Implementation for the worker class in which based on the
command entered by the user, the appropriate function is called to carry
out the desired operation.

*/
#include "Worker.h"

const string Worker::NULL_STRING = "";
const string Worker::MESSAGE_ADDED_SUCCESSFULLY = "has been added successfully! :) ";
const string Worker::MESSAGE_DELETED_SUCCESSFULLY = "has been deleted successfully! :)";
const string Worker::MESSAGE_UPDATED_SUCCESSFULLY = "has been updated successfully! :) "; 
const string Worker::MESSAGE_CHECKED_SUCCESSFULLY = "has been checked off your EasyDone task list! :)";
const string Worker::MESSAGE_WRONG_INDEX = "Please enter a valid index!";
const string  Worker:: MESSAGE_ENTER_VALID_COMMAND = "Please enter a valid command!";
//const int NULL_DATE = -1;



// const string Parser::MESSAGE_DELETE = "delete";

Worker::Worker() {


}

Worker::~Worker() {
	//taskIndexIssuer;	// save the state of issuer pls
}


string Worker::takeparsedCommand(vector<string> parsedCommandstring) {

	command =  parsedCommandstring[0];
	if(command == "add"){
		
		userTask.taskName = parsedCommandstring[1];
		userTask.startDate = parsedCommandstring[2];
		userTask.startTime = parsedCommandstring[3];
		userTask.endDate = parsedCommandstring[4];
		userTask.endTime = parsedCommandstring[5];
	} else {
		userTask.taskID = parsedCommandstring[1];
		userTask.taskName = parsedCommandstring[2];
		userTask.startDate = parsedCommandstring[3];
		userTask.startTime = parsedCommandstring[4];
		userTask.endDate = parsedCommandstring[5];
		userTask.endTime = parsedCommandstring[6];
	}

	 //stringToMain = parsedCommandstring[10];

	 stringToMain += actonCommand(command);
	 return stringToMain;
}

string Worker::actonCommand(string command)
{
	if(command == "add") {
		if(userCommand.Add(userTask)) {
			successful = "has been added successfully! :) \n";
		} else{
			successful = "has not been added successfully! ): \n";
		}
	}

	else if(command == "delete" ) {
		if(userCommand.Delete(userTask)) {
			successful = "has been deleted successfully! :)\n";
		}
		else {
			successful = "Please enter a valid index!\n";
		}
	}


	else if(command == "update" ) {
		if(userCommand.Update(userTask)) {
			successful = "has been updated successfully! :)\n";
		}
		else {
			successful = "Please enter a valid index!\n";
		}
	}

	else if(command ==  "read") {
		if(userCommand.Display()) {
			successful = "End of file.\n";
		}
	}
		

	return successful;

}

vector<Task> Worker::getTaskList() {
	return userCommand.getTaskList();
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



