// This class does all the command functions like add, delete etc
#ifndef COMMAND_H
#define COMMAND_H

#include "Headers.h"
#include "Store.h" 

using namespace std;
Store todoList;

class Command {

	public:
		Command();
		~Command();
		vector<Task> getTaskList();
		vector<Task> getTodayTask();
		vector<Task> getTomorrowTask();
		void Undo();

	protected:
		Log log;
		void Sort();
		int issueNewTaskID();

	private: 
		/*string currentDay();
		string currentMonth();
		string currentYear();*/
};


class Add: public Command {

	public:
		Add();
		~Add();
		bool Addition(Task userTask);

};

class Delete: public Command { 

	public:
		Delete();
		~Delete();
		bool Deletion(Task userTask);

};

class Update: public Command {

	public:
		Update();
		~Update();
		bool Updating(Task userTask, string updateField);

};

class Display: public Command {

	public:
		Display();
		~Display();
		bool Displaying(Task userTask);

};

class Search: public Command {

	public:
		Search();
		~Search();
		

};


#endif