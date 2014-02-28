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

typedef struct Details{
    string taskName;
	string additionalDetails;
	string reminder;
	string duplciate;
	int startDate;
	int endData;
	int startTime;
	int endTime;
    bool timeSlotStatus; //true if timeslot is available, false if timeslot is occupied
    bool taskStatus; // true is task is completed
};


class Worker {

public:
	Details add(); // To add a task
	Details del(); // To delete a task
	void update(); // To update a task
	void display(); // To display a task
	Details markDone(); // To mark a task done
};

#endif

