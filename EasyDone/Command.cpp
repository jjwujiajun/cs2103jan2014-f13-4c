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
	
	bool erased = todoList.eraser(userTask.taskID);
	
	sort();
	todoList.saveToFile();
	log.log("Command: Task Deleted");

	return erased;
	
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

bool Command::Search(string searchField, string searchItem) {
	log.log("Searching: Updating task");
	bool found = false;
	int counter = 0;
	found = todoList.SearchItem(counter, searchField, searchItem);
	log.log("Command: Finished searching");

	return found;
}

Task Command::getTask(int Index) {
	return todoList.getTask(Index);
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

bool Command::markDone(Task task) {
	bool done = false;
	done = todoList.MarkDone(task);
	return done;
}

void Command::undo() {
	log.log("Command: undo");
	todoList.stackToList();
	todoList.saveToFile();
}

vector<Task> Command::getSearchedList() {
	return todoList.getSearchedList();
}

void Command::sort() {
	
	log.log("Command: sorting List");
	Task next;
	int Date, nextDate;
	for(int i = 1; i < todoList.getSize(); i++) {
		next = todoList.accessSlot(i);
		if(!next.startDate.empty()) {
			Date = stoi(next.startDate);
		} else {
			Date = 0;
		}
		int j = i-1;
		if(!todoList.accessSlot(j).startDate.empty()) {
			nextDate = stoi(todoList.accessSlot(j).startDate);
		} else {
			nextDate = 0;
		}
		for(j = i-1; j >= 0 && nextDate > Date; --j) {
			todoList.changeTask(j+1, todoList.accessSlot(j));
			if(!todoList.accessSlot(j).startDate.empty()) {
				nextDate = stoi(todoList.accessSlot(j).startDate);
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
				next = todoList.accessSlot(i);
				if(!next.startTime.empty()) {
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
				for(j = i-1; j >= prevsameDate && nextTime > Time; --j) {
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
	todoList.updateTaskID();
	log.log("Command: List sorted");
	
}