// This class does all the command functions like add, delete etc
#ifndef COMMAND_H
#define COMMAND_H

#include "Headers.h"
#include "Store.h" 

using namespace std;

class Command {
private:
	Store todoList;
	/*enum command {
		ADD, READ, UPDATE, DELETE, SEARCH, CHECK, ERROR
	};*/

public:
	Command();
	~Command();
	//bool userCommnad(string userInput);
	bool Add(Task userTask);
	bool Delete(Task userTask);
	bool Update(Task userTask, string updateField);
	bool Display();
	bool Search();
	int issueNewTaskID();
	vector<Task> getTaskList();
	void undo();

};

#endif