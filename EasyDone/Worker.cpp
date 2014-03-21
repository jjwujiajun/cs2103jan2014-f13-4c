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
	//userTask.taskID = parsedCommandstring[1];
	userTask.taskName = parsedCommandstring[1];
	userTask.startDate = parsedCommandstring[2];
	userTask.startTime = parsedCommandstring[3];
	userTask.endDate = parsedCommandstring[4];
	userTask.endTime = parsedCommandstring[5];

	/*
	 command =  parsedCommandstring[0];
	 taskID = parsedCommandstring[1];
	 taskName = parsedCommandstring[2];
	 startDate = parsedCommandstring[3];
	 startTime = parsedCommandstring[4];
	 endDate = parsedCommandstring[5];
	 endTime = parsedCommandstring[6];
	 index = parsedCommandstring[7];
	 fieldtoUpdate = parsedCommandstring[8];
	 updateContent = parsedCommandstring[9]; */
	 //JJ added:
	 stringToMain = parsedCommandstring[10];

	// cout << taskID <<" hhere" << endl;
	 /*
	 cout << command <<" here" << endl;
	 cout << taskName << " retrieved" << endl;
	 cout << startDate << " date" << endl;
	 cout << startTime << " time" << endl;
	 cout << endDate << " endDate" << endl;
	 cout << endTime << " endTime" << endl;
	 cout << index << " index" << endl;
	 cout << fieldtoUpdate << " field" << endl;
	 cout << updateContent << " content" << endl;
	 */

	 //JJ added:
	 try {
	 stringToMain += actonCommand(command);
	 return stringToMain;
	 } catch(int number) {
		 throw 0;
	 }
}

string Worker::actonCommand(string command)
{
	try{
	if(command == "add") {
		if(userCommand.Add(userTask)) {
			successful = "has been added successfully! :) \n";
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
	}
	catch (int number) {
		throw 0;
	}

	return successful;

}

vector<Task> Worker::getTaskList() {
	return userCommand.getTaskList();
}

/*
string Worker::updateTaskWithIndex(string index, string update, string updateField) {
	
	int indexInt  = atoi(index.c_str());

	if(updateField == taskName && index == todoList.getTaskID(indexInt) ) {
		todoList.accesswithTaskID(indexInt).taskName =  update;
	}

	else if(updateField == startDate && index == todoList.getTaskID(indexInt)) {
		todoList.accesswithTaskID(indexInt).startDate =  update;
	}

	else if(updateField == startTime && index == todoList.getTaskID(indexInt)) {
		todoList.accesswithTaskID(indexInt).startTime =  update;
	}
	
	else if(updateField == endDate && index == todoList.getTaskID(indexInt)) { 
		todoList.accesswithTaskID(indexInt).endDate =  update;
	}
	
	else if(updateField == endTime && index == todoList.getTaskID(indexInt) ) {
		todoList.accesswithTaskID(indexInt).endTime =  update;
	}

	else
		return MESSAGE_ENTER_VALID_COMMAND;



	return MESSAGE_UPDATED_SUCCESSFULLY;
}
*/






























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



