#include "Headers.h"
#include "Task.h"

using namespace std;

#pragma once

/*typedef struct DateFormat {
	string day;
	string month;
	string year;
};*/


class Store {
	
	private:
		
		vector<Task> taskList;
		vector< vector<Task> > undoList;
	
	
	public:
		Store();
		~Store();

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
		void switchTask(int slot1, int slot2);
		void changeTask(int slot, Task slotTask);
		bool eraser(string taskIndex);
		void pushback(Task newTask);
		Task getTask(int slot);
		bool changeTask(int taskID, Task userTask, string updateField);
		//int findSlot(string taskIndex);
		void dueToday();
		vector<Task> getTaskList();
		void stackToList();
		void listToStack();
	
};
