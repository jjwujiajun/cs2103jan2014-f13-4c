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

	typedef struct Task {
		int index;
		string taskName;
		string venue;	
		int date;
		int month;
		int year;
		int startTime;
		int endTime;
		string isCompleted;		
		//bool hasAvailableSlot;		
	};

	vector<Task> todoList;
	vector<Task>::iterator iter;
	vector<string> input;
	Store tasksStorage;
	int taskIndexIssuer;

	static const string MESSAGE_ADDED_SUCCESSFULLY;
	static const string MESSAGE_DELETED_SUCCESSFULLY;
	static const string MESSAGE_UPDATED_SUCCESSFULLY;
	static const string MESSAGE_CHECKED_SUCCESSFULLY;
	static const string NULL_STRING;
	static const string MESSAGE_ERROR;


public:

	Worker();
	~Worker();

	// todoList functions
	string takeparsedCommand(vector<string>);
	//string addTask(string taskName, string venue, int day, int month, int year, int startTime, int endTime);
	string addTask(vector <string> input);
	string removeTaskWithIndex(int index);
	string updateTaskWithIndex(int index, string update, string fieldUpdate);
	string markDoneTaskWithIndex(int index);
	void displayTaskWithIndex(int index);

	// support functions
	int issueNewIndex();
	int searchTasks(string keyword);
	bool checkListForSlotFor(Task newTask);

};

#endif

