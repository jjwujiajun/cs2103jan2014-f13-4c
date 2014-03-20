// Task.h
// The individual to-do task item object.

#ifndef FILEOPERATION_H
#define FILEOPERATION_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;



// JJ: I made a Task class instead of a struct because it's more encapsulated.
class Task {
public:
	Task(void);
	~Task(void);

private:
	string _taskName;
	//date_class _startDate;	// probabaly can be found online
	//time_class _startTime;
	//date_class _endDate;
	//time_class _endTime;
	//date_class or time_class period _recurrence;
	//Reminder_class reminder;	// we have to create ourselve
};

#endif