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
	 taskName = parsedCommandstring[1];
	 startDate = parsedCommandstring[2];
	 startTime = parsedCommandstring[3];
	 endDate = parsedCommandstring[4];
	 endTime = parsedCommandstring[5];
	 index = parsedCommandstring[6];
	 fieldtoUpdate = parsedCommandstring[7];
	 updateContent = parsedCommandstring[8]; 

	 return stringToMain = actonCommand(command);

	 


}

string Worker::actonCommand(string command)
{


	if(command == "add" || "create" ) {
		successful = addTask(taskName, startDate, startTime, endDate, endTime);
		
	}

	else if(command == "delete" || "remove") {
		successful = removeTaskWithIndex(index);
	}


	else if(command == "update" || "modify") {
		successful = updateTaskWithIndex(index, updateContent, fieldtoUpdate);
	}

	else if(command ==  "display" || "show") {
		//successful = display();
	}
		

	return successful;

}
	

string Worker::addTask(string taskName1,string  startDate1,string  startTime1,string  endDate1,string  endTime1) {


	int vectindexofNexttask = todoList.getSize() - 1;

	todoList.accessSlot(vectindexofNexttask).taskName = taskName1;
	todoList.accessSlot(vectindexofNexttask).startDate = startDate1;
	todoList.accessSlot(vectindexofNexttask).startTime = startTime1;
	todoList.accessSlot(vectindexofNexttask).endDate = endDate1;
	todoList.accessSlot(vectindexofNexttask).endTime = endTime1;
	ostringstream issuedIndex; 
	issuedIndex << issueNewTaskID();
    string strIssuedIndex = issuedIndex.str();
	todoList.accessSlot(vectindexofNexttask).taskID = strIssuedIndex;
		
	return MESSAGE_ADDED_SUCCESSFULLY;

}

string Worker::removeTaskWithIndex(string indexString) {

	bool erased;
	vector<Task>::iterator iter;

	for(iter = todoList.getIteratorBegin(); iter < todoList.getIteratorEnd(); iter++) {

		if((*iter).taskID == indexString)
		{

			erased = todoList.eraser(iter);
		}


	}

	if( erased == 1) {

	//string nameofTask = todoList.getTaskName(indexString); //for output

	return  MESSAGE_DELETED_SUCCESSFULLY;

	}

	else {

		return MESSAGE_WRONG_INDEX;
	}

}

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



int Worker::issueNewTaskID(){
	
	size_todoList =  todoList.getSize();
	newIndex = size_todoList++;

	return newIndex;

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



