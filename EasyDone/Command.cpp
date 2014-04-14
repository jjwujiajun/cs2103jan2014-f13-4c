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
	if(todoList.getSize() != 0) {
		while(counter < todoList.getSize()) {
			temp = todoList.accessSlot(counter);

			// Exception handling for same task. Throws exception if task already exists.
			if(temp.taskName == userTask.taskName && temp.startDate == userTask.startDate && temp.startTime == userTask.startTime && temp.endDate == userTask.endDate && temp.endTime == userTask.endTime) {
				added = false;
				break;
			}
			counter++;
		}
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

	int size = todoList.getSize();
	// Asserts that the task ID is within the task list range.
	assert(stoi(userTask.taskID) <= size);

	todoList.listToStack();
	log.log("Command: Deleting task");
	
	bool erased = todoList.eraser(userTask.taskID);
	
	sort();
	todoList.saveToFile();
	log.log("Command: Task Deleted");

	return erased;
	
}

bool Command::Update(Task userTask, string updateField) {

	int size = todoList.getSize();
	// Asserts that the task ID is within the task list range.
	assert(stoi(userTask.taskID) <= size);

	todoList.listToStack();
	log.log("Command: Updating task");
	bool updated = false;
	int Index = 0;
	while(userTask.taskID != todoList.getTask(Index).taskID) {
		Index++;
	}
	try {
		updated = todoList.changeTaskPos(Index, userTask, updateField);
	} catch (string error) {
		throw error;
	}
	
	int counter = 0, sameTaskNum = 0;
	Task temp, copyUserTask;
	copyUserTask = todoList.getTask(Index);

	// Exeption Handling for updating to same task. Throws exception if task is updated to a task inside the list.
	if(updated) {
		while(counter < todoList.getSize()) {
			temp = todoList.accessSlot(counter);
			if(temp.taskName == copyUserTask.taskName && temp.startDate == copyUserTask.startDate && temp.startTime == copyUserTask.startTime && temp.endDate == copyUserTask.endDate && temp.endTime == copyUserTask.endTime) {
				sameTaskNum++;
			}
			counter++;
		}

		if(sameTaskNum > 1) {
			updated = false;
			undo();
			Delete(todoList.getTask(Index));
		}
	}

	sort();
	todoList.saveToFile();
	log.log("Command: Task updated");

	return updated;
}

bool Command::Search(string searchField, string searchItem) {
	log.log("Searching: Updating task");
	bool found = false;
	int counter = 0;
	found = todoList.searchItem(counter, searchField, searchItem);
	log.log("Command: Finished searching");

	return found;
}

Task Command::getTask(int Index) {

	int size = todoList.getSize();
	// Asserts that the Index is within the task list range.
	assert(Index < size);

	return todoList.getTask(Index);
}

int Command::issueNewTaskID(){
	
	int newIndex =  todoList.getSize();
	newIndex++;

	return newIndex;
}
 
vector<Task>* Command::getTaskList() { 
	todoList.markTasksDueToday();
	vector<Task>* list = new vector<Task>;
	*list = todoList.getTaskList();
	return list;
}

bool Command::markDone(Task task) {
	
	int size = todoList.getSize();
	// Asserts that the task ID is within the task list range.
	assert(stoi(task.taskID) <= size);
	
	todoList.listToStack();

	log.log("Command: task is being marked done");
	bool done = false;
	Task temp;
	int counter = 0;
	while(counter < todoList.getSize()) {
		temp = todoList.getTask(counter);
		if(temp.taskID == task.taskID) {
			temp.isDone = true;
			todoList.changeTaskPos(counter,temp);
			done = true;
			break;
		}
		counter++;
	}
	sort();
	todoList.saveToFile();
	return done;
}

bool Command::undo() {

	log.log("Command: undo");

	bool undone = true;
	todoList.stackToList();
	todoList.saveToFile();
	return undone;
}

vector<Task>* Command::getSearchedList() {
	vector<Task>* list = new vector<Task>;
	*list = todoList.getSearchedList();
	return list;
}

void Command::sort() {
	sortdone();
	int counter = 0;
	int size = todoList.getSize();
	if(size > 1) {
		while(counter < size) {
			if(!todoList.accessSlot(counter).isDone) {
				counter++;
			} else {
				break;
			}
		}
		sortDateandTime(0, counter);
		sortDateandTime(counter, todoList.getSize());

		todoList.updateTaskID();
	}

}

void Command::sortDateandTime(int start, int end) {
	
	log.log("Command: sorting List");
	Task next;
	int Date, nextDate, j, i = start+1;
	while(i < end) {
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
		
		while(j >= start && nextDate > Date) {
			todoList.changeTaskPos(j+1, todoList.accessSlot(j));
			j--;
			if(j>=0) {
				if(!todoList.accessSlot(j).startDate.empty()) {
					nextDate = stoi(todoList.accessSlot(j).startDate);
				} else {
					nextDate = 0;
				}
			}
		}
		todoList.changeTaskPos(j+1, next);
		i++;
	}
	
	int Time, nextTime, prevsameDate, sameDate = 0, counter = start, countNum;
	
	while(sameDate < end) {
		prevsameDate = sameDate;
		next = todoList.getTask(sameDate);

		while((sameDate+1)<end) {
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
					todoList.changeTaskPos(j+1, todoList.accessSlot(j));
					if(!todoList.accessSlot(j).startTime.empty()) {
						nextTime = stoi(todoList.accessSlot(j).startTime);
					} else {
						nextTime = 0;
					}
				}
				todoList.changeTaskPos(j+1, next);
			}
		}
		sameDate++;
	} 
	log.log("Command: List sorted");
}

void Command::sortdone() {
	int counter = 0;
	Task temp;
	stack<Task> doneTasks;
	vector<int> doneTasksIndex;

	while(counter < todoList.getSize()) {
		temp = todoList.accessSlot(counter);
		if(temp.isDone) {
			doneTasks.push(temp);
			doneTasksIndex.push_back(counter);
		}
		counter++;
	}
	while(!doneTasksIndex.empty()) {
		todoList.eraser(to_string(doneTasksIndex.back() + 1));
		doneTasksIndex.pop_back();
	}
	while(!doneTasks.empty()) {
		todoList.pushbackDoneTask(doneTasks.top());
		doneTasks.pop();
	}
}

vector<Task>* Command::getTodayTask() {
	
	int i;
	todoList.markTasksDueToday();
	int sizeofList = todoList.getSize();
	vector<Task>* tasksReturned = new vector<Task>;

	for( i = 0; i < todoList.getSize(); i++)
	{
		Task task = todoList.getTask(i);
		
		if(task.isBold == true && tasksReturned->size() < sizeofList )
		{
			tasksReturned->push_back(task);
		}

	}

	return tasksReturned;
}

vector<Task>* Command::getTomorrowTask() {
	
	int i;
	todoList.markTasksDueTomorrow();
	vector<Task>* tasksReturned = new vector<Task>;

	for( i = 0 ; i < todoList.getSize(); i++) {

		Task task = todoList.getTask(i);

		if(task.isTomorrow == true)
		{
			tasksReturned->push_back(task);
		}
	}

	return tasksReturned;
}

vector<Task>* Command::getOverdueTasks() {
	
	int i;
	todoList.markTasksOverdue();
	vector<Task>* tasksReturned = new vector<Task>;

	for( i = 0 ; i < todoList.getSize(); i++) {

		Task task = todoList.getTask(i);

		if(task.isRed == true)
		{
			tasksReturned->push_back(task);
		}
	}

	return tasksReturned;
}

vector<Task>* Command::getMarkedTasks() {

	vector<Task>* tasksReturned = new vector<Task>;

	for(int i = 0; i < todoList.getSize(); i++)
	{
		Task task = todoList.getTask(i);
		
		if(task.isDone ==  true) {

			tasksReturned->push_back(task);
		}
	}

	return tasksReturned;
}

vector<Task>* Command::getUnmarkedTasks() { 

	vector<Task>* tasksReturned = new vector<Task>;

	for(int i = 0; i < todoList.getSize(); i++)
	{
		Task task = todoList.getTask(i);
		
		if(task.isDone == false) {

			tasksReturned->push_back(task);
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

vector<string> Command::getTomorrowDate() {

	vector<string> toReturn  = todoList.getDateTomorrow();

	return toReturn;
}