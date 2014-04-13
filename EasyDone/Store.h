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
		string getDay(int slotNumber);
		string getMonth(int slotNumber);
		string getYear(int slotNumber);
		vector<Task> getTaskList();
		vector<Task> getSearchedList();
		int getSize();
		string getTaskID(int slotNumber);


		
		Task accessSlot(int slot); 
		vector<Task>::iterator getIteratorBegin();
		vector<Task>::iterator getIteratorEnd();
		void saveToFile();
		void undoUndoList();

		bool MarkDone(Task taskID);  //arun pls make all helper functions private, only public functions are included in API!
		Task accesswithTaskID(int indexEntered);
		void switchTask(int slot1, int slot2);
		void changeTask(int slot, Task slotTask);
		vector<string> getDateTomorrow();
		bool eraser(string taskIndex);
		void pushback(Task newTask);
		Task getTask(int slot);
		string changeTask(int taskID, Task userTask, string updateField);
		bool SearchItem(int Index, string searchField, string searchItem);
		//int findSlot(string taskIndex);
		void markTasksOverdue(); //bring this down!
		bool stackToList();
		void listToStack();
		void updateTaskID();
		void markTasksDueToday();
		void markTasksDueTomorrow();

		string currentDay();
		string currentMonth();
		string currentYear();
	
};
