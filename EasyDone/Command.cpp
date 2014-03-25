#include "Command.h"

Command::Command() {

}

Command::~Command() {

}

bool Command::Add(Task userTask) {
	int vectindexofNexttask = todoList.getSize();
	
	int newTaskID = issueNewTaskID();
	userTask.taskID = to_string(newTaskID);
	todoList.pushback(userTask);
	todoList.listToStack();
	return true;
}

bool Command::Delete(Task userTask) {
	try {
	bool erased = todoList.eraser(userTask.taskID);
	todoList.listToStack();
	return erased;
	} catch (int number) {
		throw 0;
	}
}

bool Command::Display() {

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
	return true;
}

bool Command::Update(Task userTask, string updateField) {
	bool updated = false;
	int Index = 0;
	while(userTask.taskID != todoList.getTask(Index).taskID) {
		Index++;
	}
	updated = todoList.changeTask(Index, userTask, updateField);
	todoList.listToStack();
	return updated;
}


int Command::issueNewTaskID(){
	
	int newIndex =  todoList.getSize();
	newIndex++;

	return newIndex;
}

vector<Task> Command::getTaskList() {
	todoList.dueToday();
	return todoList.getTaskList();
}

void Command::undo() {
	todoList.stackToList();
}