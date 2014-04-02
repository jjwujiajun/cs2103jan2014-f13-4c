#include "Headers.h"
#include "FileHandler.h"


using namespace std;

#pragma once


class Store {
	
	private:
		FileHandler file;
		vector<Task> taskList;
		vector< vector<Task> > undoList;

		string currentDay();
		string currentMonth();
		string currentYear();

		Log log;
	
	
	public:
		Store();
		~Store();

		//string getIndex(int index);
		string getTaskName(int slotNumber);
		string getStartDate(int slotNumber);
		string getStartTime(int slotNumber);
		string getEndDate(int slotNumber);
		string getEndTime(int slotNumber);
		string getDay(int slotNumber);
		string getMonth(int slotNumber);
		string getYear(int slotNumber);



		int getSize();
		//Task accessSlot(int slot); 
		string getTaskID(int slotNumber);
		vector<Task>::iterator getIteratorBegin();
		vector<Task>::iterator getIteratorEnd();
		void saveToFile();
		Task accesswithTaskID(int indexEntered);
		void switchTask(int slot1, int slot2);
		void changeTask(int slot, Task slotTask);
		bool eraser(string taskIndex);
		void pushback(Task newTask);
		Task getTask(int slot);
		bool changeTask(int taskID, Task userTask, string updateField);
		//int findSlot(string taskIndex);
		vector<Task> getTaskList();
		bool stackToList();
		void listToStack();
		void updateTaskID();
		void dueToday();
		void dueTomorrow();
};
