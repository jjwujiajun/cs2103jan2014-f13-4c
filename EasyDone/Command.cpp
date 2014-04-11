#include "Command.h"

Command::Command() {

}

Command::~Command() {

}

bool Command::Add(Task userTask) {
	todoList.listToStack();
	log.log("Command: Adding new task");

	bool added = true;
	int counter = 0;
	Task temp;

	while(counter < todoList.getSize()) {
		temp = todoList.accessSlot(counter);
		if(temp.taskName == userTask.taskName) {
			added = false;
			break;
		}
		counter++;
	}
	if(added) {
		int vectindexofNexttask = todoList.getSize();
	
		int newTaskID = issueNewTaskID();
		userTask.taskID = to_string(newTaskID);
		todoList.pushback(userTask);
	} else {
		todoList.undoUndoList();
	}
	sort();
	todoList.saveToFile();
	log.log("Command: New task added");
	return added; 
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
 
vector<Task> Command::getTaskList() { //must change this!!!!!!!
	todoList.markTasksDueToday();
	return todoList.getTaskList();
}

bool Command::markDone(Task task) {
	todoList.listToStack();
	log.log("Command: task is being marked done");
	bool done = false;
	Task temp;
	int counter = 0;
	while(counter < todoList.getSize()) {
		temp = todoList.getTask(counter);
		if(temp.taskID == task.taskID) {
			temp.isDone = true;
			todoList.changeTask(counter,temp);
			done = true;
			break;
		}
		counter++;
	}
	sort();
	todoList.saveToFile();
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
	int Date, nextDate, j, i = 1;
	while(i < todoList.getSize()) {
		next = todoList.accessSlot(i);
		if(!next.startDate.empty()) {
			Date = stoi(next.startDate);
		} else {
			Date = 0;
		}
		j = i-1;
		
		if(!todoList.accessSlot(j).startDate.empty()) {
			nextDate = stoi(todoList.accessSlot(j).startDate);
		} else {
			nextDate = 0;
		}
		
		while(j >= 0 && nextDate > Date) {
			todoList.changeTask(j+1, todoList.accessSlot(j));
			j--;
			if(j>=0) {
				if(!todoList.accessSlot(j).startDate.empty()) {
					nextDate = stoi(todoList.accessSlot(j).startDate);
				} else {
					nextDate = 0;
				}
			}
		}
		todoList.changeTask(j+1, next);
		i++;
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

vector<Task> Command::getTodayTask() {
	
	int i;
	todoList.markTasksDueToday();
	int sizeofList = todoList.getSize();
	vector<Task> tasksReturned;

	for( i = 0; i < todoList.getSize(); i++)
	{
		Task task = todoList.getTask(i);
		
		if(task.isBold == true && tasksReturned.size() < sizeofList )
		{
			tasksReturned.push_back(task);
		}

	}

	return tasksReturned;
}

vector<Task> Command::getTomorrowTask() {
	
	int i;
	todoList.markTasksDueTomorrow();
	vector<Task> tasksReturned;

	for( i = 0 ; i < todoList.getSize(); i++) {

		Task task = todoList.getTask(i);

		if(task.isTomorrow == true)
		{
			tasksReturned.push_back(task);
		}
	}

	return tasksReturned;
}

vector<Task> Command::getOverdueTasks() {
	
	int i;
	todoList.markTasksOverdue();
	vector<Task> tasksReturned;

	for( i = 0 ; i < todoList.getSize(); i++) {

		Task task = todoList.getTask(i);

		if(task.isRed == true)
		{
			tasksReturned.push_back(task);
		}
	}

	return tasksReturned;
}

vector<Task> Command::getMarkedTasks() {

	vector<Task> tasksReturned;

	for(int i = 0; i < todoList.getSize(); i++)
	{
		Task task = todoList.getTask(i);
		
		if(task.isDone ==  true) {

			tasksReturned.push_back(task);
		}
	}

	return tasksReturned;
}

vector<Task> Command::getUnmarkedTasks() { 

	vector<Task> tasksReturned;

	for(int i = 0; i < todoList.getSize(); i++)
	{
		Task task = todoList.getTask(i);
		
		if(task.isDone == false) {

			tasksReturned.push_back(task);
		}
	}

	return tasksReturned;

}

string Command::getSize() {
	string size = to_string(todoList.getSize());
	return size;
}

string Command::getTodayDay() {

	string toReturn =  todoList.currentDay();

	return toReturn;
}

string Command::getTodayMonth() {

	string toReturn =  todoList.currentMonth();

	return toReturn;
}

string Command::getTodayYear() {

	string toReturn =  todoList.currentYear();

	return toReturn;
}

