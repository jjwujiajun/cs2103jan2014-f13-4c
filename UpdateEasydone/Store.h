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
		int getStartDate(int index);
		int getStartTime(int index);
		int getEndDate(int index);
		int getEndTime(int index);
		int getSize();
		Task accessSlot(int slot); 
	
};


#endif