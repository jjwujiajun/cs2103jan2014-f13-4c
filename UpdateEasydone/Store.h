#pragma once

#ifndef _STORE_H_
#define _STORE_H_

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;


typedef struct Task{
	string taskName;
	int index;	
	int startDate;
	int startTime;
	int endDate;
	int endTime;
	int date;
	int month;
	int year;
};

class Store {
	
	private:
		
		vector<Task> taskList;
	
	
	public:
		
		int getIndex(vector<Task> taskList);
		string getTaskName(int index);
		string getStartDate(int index);
		string getStartTime(int index);
		string getEndDate(int index);
		string getEndTime(int index);
		string getSize();
		Task accessSlot(int slot); 
	
};


#endif