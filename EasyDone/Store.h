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
		string currentDay();
		string currentMonth();
		string currentYear();
		string tomorrowDay;
		string tomorrowMonth;
		string tomorrowYear;

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
		Task accessSlot(int slot); 
		string getTaskID(int slotNumber);
		void getDateTomorrow();
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
		void dueTomorrow();
		vector<Task> getTaskList();
		vector<Task> getSearchedList();
		bool stackToList();
		void listToStack();
		void updateTaskID();
	
};
