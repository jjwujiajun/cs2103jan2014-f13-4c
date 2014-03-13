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
	string command; //vector index 0
	string taskName; //vector index 1
	string startDate; //vector index 2
	string startTime; //vector index 3
	string endDate; //vector index 4
	string endTime; //vector index 5
	string index; //vector index 6
	string fieldtoUupdate; //vector index 7
	string updateContent; //vector index 8

	string successful;
	int newIndex;
	int size_todoList;
	string returnStringtomain;

		

	static const string MESSAGE_ADDED_SUCCESSFULLY;
	static const string MESSAGE_DELETED_SUCCESSFULLY;
	static const string MESSAGE_UPDATED_SUCCESSFULLY;
	static const string MESSAGE_CHECKED_SUCCESSFULLY;
	static const string NULL_STRING;


public:

	Worker();
	~Worker();

	// todoList function
	string addTask();
	string removeTaskWithIndex(int index);
	string updateTaskWithIndex(int index, string update, string fieldUpdate);
	//vector<string> displayTaskWithIndex(int index);

	// support functions
	string takeparsedCommand(vector<string> fromManager);
	string actonCommand(string command);
	int issueNewIndex();
	int searchTasks(string keyword);
};

#endif

