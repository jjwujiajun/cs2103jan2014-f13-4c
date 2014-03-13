#pragma once

#ifndef _STORE_H_
#define _STORE_H_

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

/*typedef struct DateFormat {
	string day;
	string month;
	string year;
};*/


typedef struct Task {
	string taskName;
	string index;	
	string startDate;
	string startTime;
	string endDate;
	string endTime;
	string date;
	string month;
	string year;
};

vector<Task>::iterator iter;

class Store {
	
	private:
		
		vector<Task> taskList;
	
	
	public:
		
		//string getIndex(int index);
		string getTaskName(int slotNumber);
		string getStartDate(int slotNumber);
		string getStartTime(int slotNumber);
		string getEndDate(int slotNumber);
		string getEndTime(int slotNumber);
		int getSize();
		Task accessSlot(int slot); 
		vector<Task>::iterator getIteratorBegin();
		vector<Task>::iterator getIteratorEnd();
		bool eraser(vector<Task>::iterator iterPassed);

	
};


#endif