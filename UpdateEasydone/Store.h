#pragma once

#ifndef _STORE_H_
#define _STORE_H_

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Store {
	private:

		typedef struct Task{

			string taskName;
			string venue;
			int index;
			int startTime;
			int endTime;
			int date;
			int month;
			int year;
		};
		
		vector<Task> taskList;
	
	
	public:
		

		int getIndex(vector<Task> taskList);
		string getTaskName(vector<Task> taskList,int index);
		string getTaskVenue(vector<Task> taskList, int index);
		int getStartTime(vector<Task> taskList, int index);
		int getEndTime(vector<Task> taskList, int index);
		int getDate(vector<Task> taskList, int index);
		int getMonth(vector<Task> taskList, int index);
		int getYear(vector<Task> tasklist, int index);

	
};


#endif