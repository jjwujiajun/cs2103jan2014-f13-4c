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
			int day;
			int month;
			int year;
		};
		
		vector<Task> taskList;
	
	public:
		

		int getIndex(vector<Task> taskList);
		string getTaskname(vector<Task> taskList,int index);
		string getTaskvenue(vector<Task> taskList, int index);
		int getStarttime(vector<Task> taskList, int index);
		int getEndtime(vector<Task> taskList, int index);
		int getDay(vector<Task> taskList, int index);
		int getMonth(vector<Task> taskList, int index);
		int getYear(vector<Task> tasklist, int index);

	
};


#endif