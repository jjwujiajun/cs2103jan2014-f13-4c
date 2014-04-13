// This class does all the command functions like add, delete etc
#ifndef COMMAND_H
#define COMMAND_H

#include "Headers.h"
#include "Store.h" 

using namespace std;

class Command {
private:
	Store todoList;
	Log log;

	

public:
	Command();
	~Command();
	
	bool Add(Task userTask);
	bool Delete(Task userTask);
	bool Search(string searchField, string searchItem);
	bool markDone(Task task);
	bool undo();
	void sort();
	string Update(Task userTask, string updateField);
	
	//GUI functions + helper functions! 
	vector<Task> getSearchedList();
	vector<Task> getTodayTask();
	vector<Task> getTomorrowTask();
	vector<Task> getOverdueTasks();
	vector<Task> getMarkedTasks();
	vector<Task> getUnmarkedTasks();
	vector<Task> getTaskList();
	Task getTask(int Index);
	string getSize();
	int issueNewTaskID();
	string getTodayDay();
	string getTodayMonth();
	string getTodayYear();
	vector<string> getTomorrowDate();
};

#endif