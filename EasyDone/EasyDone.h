// EasyDone.h
// manages the all the rest of the operations.
// Responsibility of: Juhi

#include "stdafx.h"
#include "Task.h"
using namespace std;

#pragma once

// I named it EasyDone to sound nicer in the main function later. If you wanna change the name feel free to do so. :)
class EasyDone
{
public:
	EasyDone(void);
	~EasyDone(void);

	void init();

private:
	vector<Task> todoList;	// JJ: I'm thinking we may need to make this a class by itself next time, if it has to support some functions.
};

