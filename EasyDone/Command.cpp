#include "Command.h"

Command::Command() {

}

Command::~Command() {

}

bool Command::Add(Task userTask) {
	todoList.listToStack();
	log.log("Command: Adding new task");
	int vectindexofNexttask = todoList.getSize();
	
	int newTaskID = issueNewTaskID();
	userTask.taskID = to_string(newTaskID);
	todoList.pushback(userTask);
	
	sort();
	todoList.saveToFile();
	log.log("Command: New task added");
	return true;
}

bool Command::Delete(Task userTask) {
	todoList.listToStack();
	log.log("Command: Deleting task");
	try {
	bool erased = todoList.eraser(userTask.taskID);
	
	sort();
	todoList.saveToFile();
	log.log("Command: Task Deleted");

	return erased;
	} catch (int number) {
		throw 0;
	}
}

bool Command::Update(Task userTask, string updateField) {
	todoList.listToStack();
	log.log("Command: Updating task");
	bool updated = false;
	int Index = 0;
	while(userTask.taskID != todoList.getTask(Index).taskID) {
		Index++;
	}
	updated = todoList.changeTask(Index, userTask, updateField);
	
	sort();
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

void Command::undo() {
	log.log("Command: undo");
	todoList.stackToList();
	todoList.saveToFile();
}

void Command::sort() {
	log.log("Command: sorting List");
	Task next;
	int Date, nextDate;
	for(int i =1; i<todoList.getSize(); i++) {
		next = todoList.accessSlot(i);
		if(!next.startDate.empty()) {
			Date = stoi(next.startDate);
		} else {
			Date = 0;
		}
		int j=i-1;
		if(!todoList.accessSlot(j).startDate.empty()) {
			nextDate = stoi(todoList.accessSlot(j).startDate);
		} else {
			nextDate = 0;
		}
		for(j=i-1; j>=0 && nextDate>Date; --j) {
			todoList.changeTask(j+1, todoList.accessSlot(j));
			if(!todoList.accessSlot(j).startDate.empty()) {
				nextDate = stoi(todoList.accessSlot(j).startDate);
			} else {
				nextDate = 0;
			}
		}
		todoList.changeTask(j+1, next);
	}

	int Time, nextTime, prevsameDate, sameDate = 1, counter = 1;
	
	while(sameDate<todoList.getSize()) {
		prevsameDate = sameDate;
		next = todoList.getTask(sameDate);

		while(next.startDate == todoList.getTask(sameDate-1).startDate && sameDate<todoList.getSize()) {
			sameDate++;
		}

		counter = prevsameDate;;
		prevsameDate = sameDate - prevsameDate;

		if(counter>0 && prevsameDate>0) {
			for(int i = counter; i<sameDate; i++) {
				next = todoList.accessSlot(i);
				if(!next.startDate.empty()) {
					Time = stoi(next.startTime);
				} else {
					Time = 0;
				}
				int j=i-1;
				if(!todoList.accessSlot(j).startTime.empty()) {
					nextTime = stoi(todoList.accessSlot(j).startTime);
				} else {
					nextTime = 0;
				}
				for(j=i-1; j>=0 && nextTime>Time; --j) {
					todoList.changeTask(j+1, todoList.accessSlot(j));
					if(!todoList.accessSlot(j).startTime.empty()) {
						nextTime = stoi(todoList.accessSlot(j).startTime);
					} else {
						nextTime = 0;
					}
				}
				todoList.changeTask(j+1, next);
			}
		}
		sameDate++;
	}
	log.log("Command: List sorted");
}