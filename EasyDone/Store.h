#include "Headers.h"

using namespace std;

#pragma once

/*typedef struct DateFormat {
	string day;
	string month;
	string year;
};*/


 struct Task {
	string taskName;
	string taskID;	
	string startDate;
	string startTime;
	string endDate;
	string endTime;
	string date;
	string month;
	string year;
};




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
		string getTaskID(int slotNumber);
		vector<Task>::iterator getIteratorBegin();
		vector<Task>::iterator getIteratorEnd();
		Task accesswithTaskID(int indexEntered);
		bool eraser(vector<Task>::iterator iterPassed);
		
	
};
