// Worker.h
// Worker does all the command functions like add, delete etc


#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include "Store.h" 

using namespace std;

class Worker {
private:

	
	Store todoList;

	//variables to store the various components from parsedCommandstring
	string command;
	string taskName;
	string day;
	string month;
	string year;
	string venue;

	int taskIndexIssuer;

	static const string MESSAGE_ADDED_SUCCESSFULLY;
	static const string MESSAGE_DELETED_SUCCESSFULLY;
	static const string MESSAGE_UPDATED_SUCCESSFULLY;
	static const string MESSAGE_CHECKED_SUCCESSFULLY;
	static const string NULL_STRING;


public:

	Worker();
	~Worker();

	// todoList functions
	string takeparsedCommand(vector<string> fromManager);
	string actonCommand(string command);
	string addTask(string taskName, string day, string month, string year, string venue);
	string removeTaskWithIndex(int index);
	string updateTaskWithIndex(int index, string update, string fieldUpdate);
	string markDoneTaskWithIndex(int index);
	//vector<string> displayTaskWithIndex(int index);

	// support functions
	int issueNewIndex();
	int searchTasks(string keyword);
	bool checkListForSlotFor(Task newTask);
};

#endif

