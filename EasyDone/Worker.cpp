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
	//Task temp; 
	 command =  parsedCommandstring[0];
	 taskID = parsedCommandstring[1];
	 taskName = parsedCommandstring[2];
	 startDate = parsedCommandstring[3];
	 startTime = parsedCommandstring[4];
	 endDate = parsedCommandstring[5];
	 endTime = parsedCommandstring[6];
	 index = parsedCommandstring[7];
	 fieldtoUpdate = parsedCommandstring[8];
	 updateContent = parsedCommandstring[9]; 
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
	 stringToMain += actonCommand(command);
	 return stringToMain;
}

string Worker::actonCommand(string command)
{
	if(command == "add") {
		successful = addTask(taskName, startDate, startTime, endDate, endTime);
	}

	else if(command == "delete" ) {
		successful = removeTaskWithIndex(taskID);
	}


	else if(command == "update" ) {
		successful = updateTaskWithIndex(index, updateContent, fieldtoUpdate);
	}

	else if(command ==  "read") {
		//successful = display();
	}
		

	return successful;

}
	

string Worker::addTask(string taskName1,string  startDate1,string  startTime1,string  endDate1,string  endTime1) {


	int vectindexofNexttask = todoList.getSize();
	
	Task newTask;
	newTask.taskName = taskName1;
	newTask.startDate = startDate1;
	newTask.startTime = startTime1;
	newTask.endDate = endDate1;
	newTask.endTime = endTime1;
	/*todoList.accessSlot(vectindexofNexttask).taskName = taskName1;
	todoList.accessSlot(vectindexofNexttask).startDate = startDate1;
	todoList.accessSlot(vectindexofNexttask).startTime = startTime1;
	todoList.accessSlot(vectindexofNexttask).endDate = endDate1;
	todoList.accessSlot(vectindexofNexttask).endTime = endTime1;
	*/
	
	//JJ edited:
	int newTaskID = issueNewTaskID();
	newTask.taskID = to_string(newTaskID);
	todoList.insert(newTask);

	return "has been added successfully! :) \r\n";
}

string Worker::removeTaskWithIndex(string taskIndex) {
	
	bool erased = todoList.eraser(taskIndex);
	/*vector<Task>::iterator iter;

	for(iter = todoList.getIteratorBegin(); iter < todoList.getIteratorEnd(); iter++) {

		if((*iter).taskID == taskIndex)
		{

			erased = todoList.eraser(iter);
		}


	}
	*/

	if( erased == true) {

	//string nameofTask = todoList.getTaskName(indexString); //for output

	return  "has been deleted successfully! :)";

	}

	else {

		return "Please enter a valid index!";
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

// display
/*
string Worker::display() {

	for(int i = 0; i<todoList.getSize(); i++) {
		Task printTask = todoList.getTask(i);
		cout<<"TaskID: "<<printTask.taskID<<"	";
		if(printTask.taskName != "0"){
			cout<<"TaskName: "<<printTask.taskName<<"	";
		}
		if(printTask.startDate != "0"){
			cout<<"StartDate: "<<printTask.startDate<<"	";
		}
		if(printTask.startTime != "0"){
			cout<<"Starttime: "<<printTask.startTime<<"	";
		}
		cout<<endl;
	}
	return "End of file.\n";
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



