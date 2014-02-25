// Task.h
// The individual to-do task item object.
// Resposibility of: JJ

#include "stdafx.h"
using namespace std;

#pragma once

// JJ: I made a Task class instead of a struct because it's more encapsulated.
class Task
{
public:
	Task(void);
	~Task(void);

private:
	string _taskName;
	int _startDate;	//YYYYMMDD	
	int _startTime;	//HHMM
	int _endDate;	//YYYYMMDD
	int _endTime;	//HHMM
	//date_class or time_class period _recurrence;
	//Reminder_class reminder;	// we have to create ourselve
};

