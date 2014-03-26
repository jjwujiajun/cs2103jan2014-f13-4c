#include "Command.h"

Command::Command() {

}

Command::~Command() {

}

bool Command::Add(Task userTask) {
	todoList.listToStack();

	int vectindexofNexttask = todoList.getSize();
	
	int newTaskID = issueNewTaskID();
	userTask.taskID = to_string(newTaskID);
	todoList.pushback(userTask);
	
	return true;
}

bool Command::Delete(Task userTask) {
	todoList.listToStack();
	
	bool erased = todoList.eraser(userTask.taskID);
	
	return erased;
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
	todoList.listToStack();
	
	bool updated = false;
	int Index = 0;
	while(userTask.taskID != todoList.getTask(Index).taskID) {
		Index++;
	}
	updated = todoList.changeTask(Index, userTask, updateField);
	
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

bool Command::undo() {
	bool Undo;
	Undo = todoList.stackToList();
	return Undo;
}