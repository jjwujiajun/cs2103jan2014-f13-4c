/*@author A0101681R
* Written by: Ramireddi Juhi Simanthika
* Name: STORE.H
* Store.h defines a private vector of type Task called taskList. 
* This vector is used to store tasks and their information temporarily before they are copied to a file.  
* The vector is then copied to a file in Hard disk before the program exits. 
* Store contains an instance of FileHandler so as to store the user's task permanently in hard disk.
* Store contains several helper functions required by Command Class. The function served by these methods are explained in Store.cpp
*/


#include "Headers.h"
#include "FileHandler.h"


using namespace std;

#pragma once

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

		string getDay(int slotNumber);
		string getMonth(int slotNumber);
		string getYear(int slotNumber);
		string currentDay();
		string currentMonth();
		string currentYear();
		vector<string> getDateTomorrow();
		void markTasksDueToday();
		void markTasksDueTomorrow();
		void markTasksOverdue();
		string getTaskID(int slotNumber);
		int getSize();
		Task getTask(int slot);
		vector<Task> getTaskList();
		vector<Task> getSearchedList();
		Task accesswithTaskID(int indexEntered);
		void switchTask(int slot1, int slot2);
		void changeTask(int slot, Task slotTask);
		Task accessSlot(int slot); 
		vector<Task>::iterator getIteratorBegin();
		vector<Task>::iterator getIteratorEnd();
		void undoUndoList();
		bool eraser(string taskIndex);
		void pushback(Task newTask);
		void pushbackDoneTask(Task newTask);
		bool changeTask(int taskID, Task userTask, string updateField);
		bool searchItem(int Index, string searchField, string searchItem);
		bool stackToList();
		void listToStack();
		void updateTaskID();
		void saveToFile();
	
};
