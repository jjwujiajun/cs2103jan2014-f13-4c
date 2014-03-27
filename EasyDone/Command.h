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
	bool Update(Task userTask, string updateField);
	bool Search();
	int issueNewTaskID();
	vector<Task> getTaskList();
	void undo();
	void sort();

};

#endif