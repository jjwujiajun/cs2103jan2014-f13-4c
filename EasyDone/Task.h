//@author A0101681R
#ifndef TASK_H
#define TASK_H
#include <string>

using namespace std;

class Task {
public:
	string taskName;
	string taskID;	
	string startDate;
	string startTime;
	string endDate;
	string endTime;
	string date;
	string month;
	string year;
	bool isBold;
	bool isRed;
	bool isDone;
	bool isTomorrow;
};

#endif