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

using namespace std;

typedef struct Details {
	int index;
    string taskName;
	string additionalDetails;
	string reminder;
	string duplciate;		//whats a duplicate
	int startDate;
	int startTime;
	int endDate;
	int endTime;
	bool isCompleted;		// true is task is completed
    bool hasTimeSlot;		//true if timeslot is available, false if timeslot is occupied
};



class Worker {
private:

	typedef struct Task {
		int index;
		string taskName;
		string additionalDetails;
		string reminder;
		string duplciate;		//whats a duplicate
		int startDate;
		int startTime;
		int endDate;
		int endTime;
		bool isCompleted;		// true is task is completed
		bool hasAvailableSlot;		//true if timeslot is available, false if timeslot is occupied
	};

	vector<Task> todoList;
	vector<Task>::iterator iter;
	int taskIndexIssuer;

public:

	Worker();
	~Worker();

	// todoList functions
	void addTask(string taskName, string additionalDetails, string reminder, string duplicate, int startDate, int endDate, int startTime, int endTime);
	void removeTaskWithIndex(int index);
	void updateTaskWithIndex(int index, string taskName, string additionalDetails, string reminder, string duplicate, int startDate, int startTime, int endDate, int endTime);
	void markDoneTaskWithIndex(int index);
	void display();

	// support functions
	int issueNewIndex();
	int searchForTaskWithIndex(int index);
	bool checkListForSlotFor(Task newTask);
};

#endif

