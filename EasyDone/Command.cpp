#include "Command.h"

Command::Command() {

}

Command::~Command() {

}

bool Add::Addition(Task userTask)  {
	todoList.listToStack();
	log.log("Command: Adding new task");
	int vectindexofNexttask = todoList.getSize();
	
	int newTaskID = issueNewTaskID();
	userTask.taskID = to_string(newTaskID);
	todoList.pushback(userTask);
	
	Sort();
	todoList.saveToFile();
	log.log("Command: New task added");
	return true;
}

bool Delete::Deletion(Task userTask) {
	todoList.listToStack();
	log.log("Command: Deleting task");
	
	bool erased = todoList.eraser(userTask.taskID);
	
	Sort();
	todoList.saveToFile();
	log.log("Command: Task Deleted");

	return erased;
	
}
bool Update::Updating(Task userTask, string updateField) {
	todoList.listToStack();
	log.log("Command: Updating task");
	bool updated = false;
	int Index = 0;
	while(userTask.taskID != todoList.getTask(Index).taskID) {
		Index++;
	}
	updated = todoList.changeTask(Index, userTask, updateField);
	
	Sort();
	todoList.saveToFile();
	log.log("Command: Task updated");

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

vector<Task> Command::getTodayTask() {
	
	int i;
	todoList.dueToday();
	vector<Task> tasksReturned;

	for( i = 0; i < todoList.getSize(); i++)
	{
		Task task = todoList.getTask(i);
		
		if(task.isToday = true)
		{
			tasksReturned.push_back(task);
		}

	}

	return tasksReturned;
}

vector<Task> Command::getTomorrowTask() {
	
	int i;
	todoList.dueTomorrow();
	vector<Task> tasksReturned;

	for( i = 0 ; todoList.getSize(); i++) {

		Task task = todoList.getTask(i);

		if(task.isTomorrow == true)
		{
			tasksReturned.push_back(task);
		}
	}

	return tasksReturned;
}

void Command::Undo() {
	log.log("Command: undo");
	todoList.stackToList();
	todoList.saveToFile();
}

void Command::Sort() {
	
	log.log("Command: sorting List");
	Task next;
	int Date, nextDate;
	for(int i = 1; i < todoList.getSize(); i++) {
		next = todoList.getTask(i);
		if(!next.startDate.empty()) {
			Date = stoi(next.startDate);
		} else {
			Date = 0;
		}
		int j = i-1;
		if(!todoList.getTask(j).startDate.empty()) {
			nextDate = stoi(todoList.getTask(j).startDate);
		} else {
			nextDate = 0;
		}
		for(j = i-1; j >= 0 && nextDate > Date; --j) {
			todoList.changeTask(j+1, todoList.getTask(j));
			if(!todoList.getTask(j).startDate.empty()) {
				nextDate = stoi(todoList.getTask(j).startDate);
			} else {
				nextDate = 0;
			}
		}
		todoList.changeTask(j+1, next);
	}
	
	int Time, nextTime, prevsameDate, sameDate = 0, counter = 1, countNum;
	
	while(sameDate < todoList.getSize()) {
		prevsameDate = sameDate;
		next = todoList.getTask(sameDate);

		while((sameDate+1)<todoList.getSize()) {
			if(next.startDate == todoList.getTask(sameDate+1).startDate)
				sameDate++;
			else
				break;
		}

		counter = prevsameDate+1;
		countNum = sameDate - prevsameDate;

		if(countNum>0) {
			for(int i = counter; i <= sameDate; i++) {
				next = todoList.getTask(i);
				if(!next.startDate.empty()) {
					Time = stoi(next.startTime);
				} else {
					Time = 0;
				}
				int j=i-1;
				if(!todoList.getTask(j).startTime.empty()) {
					nextTime = stoi(todoList.getTask(j).startTime);
				} else {
					nextTime = 0;
				}
				for(j = i-1; j >= prevsameDate && nextTime > Time; --j) {
					todoList.changeTask(j+1, todoList.getTask(j));
					if(!todoList.getTask(j).startTime.empty()) {
						nextTime = stoi(todoList.getTask(j).startTime);
					} else {
						nextTime = 0;
					}
				}
				todoList.changeTask(j+1, next);
			}
		}
		sameDate++;
	}
	todoList.updateTaskID();
	log.log("Command: List sorted");
	
}