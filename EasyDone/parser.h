// parser.h
// parses the input string to return understandable todo item fields.
// Responsibility of: JJ

#include "stdafx.h"
using namespace std;

#pragma once

class parser
{
public:
	parser(void);
	~parser(void);

	void receiveUserInput();
	void parseCommand(string input);
	void parseText(string input);
	void parseDueTime(string input);
	void parseDueDate(string input);

	enum Command {ADD, DELETE};

	Command command;
	string _taskName;
	int _startDate; //YYYYMMDD
	int _startTime;	//HHMM
	int _endDate;	//YYYYMMDD
	int _endTime;	//HHMM
	string _recurrence;
	string _reminderInfo;
};

