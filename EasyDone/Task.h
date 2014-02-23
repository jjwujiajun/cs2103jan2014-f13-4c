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
	//date_class _startDate;	// probabaly can be found online
	//time_class _startTime;
	//date_class _endDate;
	//time_class _endTime;
	//date_class or time_class period _recurrence;
	//Reminder_class reminder;	// we have to create ourselve
};

