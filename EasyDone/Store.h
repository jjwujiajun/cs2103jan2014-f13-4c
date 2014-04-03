#include "Headers.h"
#include "FileHandler.h"


using namespace std;

#pragma once

/*typedef struct DateFormat {
	string day;
	string month;
	string year;
};*/


class Store {
	
	private:
		FileHandler file;
		vector<Task> taskList;
		vector<Task> searchTask;
		vector< vector<Task> > undoList;

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
		int getSize();
		Task accessSlot(int slot); 
		string getTaskID(int slotNumber);
		vector<Task>::iterator getIteratorBegin();
		vector<Task>::iterator getIteratorEnd();
		void saveToFile();

		bool MarkDone(Task taskID);
		Task accesswithTaskID(int indexEntered);
		void switchTask(int slot1, int slot2);
		void changeTask(int slot, Task slotTask);
		bool eraser(string taskIndex);
		void pushback(Task newTask);
		Task getTask(int slot);
		bool changeTask(int taskID, Task userTask, string updateField);
		bool SearchItem(int Index, string searchField, string searchItem);
		//int findSlot(string taskIndex);
		void dueToday();
		vector<Task> getTaskList();
		bool stackToList();
		void listToStack();
		void updateTaskID();
	
};
