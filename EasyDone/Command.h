//@author A0099326U
// Command.h
/* Command contains all the functions to be executed on store (The task list).
 * It allows the manager to make changes to store through its functions.
 * 
 * Functions include:
 * 1. Editing the stored task list to execute user commands.
 * 2. Manage the task list and keep it organized.
 * 3. Getter functions to return pointers to the GUI.
 * Coded by Arun Kumar
*/
#ifndef COMMAND_H
#define COMMAND_H

#include "Headers.h"
#include "Store.h" 

using namespace std;

class Command {
private:
	//Member classes
	Store todoList;
	Log log;

	

public:
	Command();
	~Command();
	
	// Command functions

	// Adds the task to the task list
	bool Add(Task userTask);
	// Deletes the task from the task list
	bool Delete(Task userTask);
	// Searches for the item in the task list
	bool Search(string searchField, string searchItem);
	// Updates the task in the updatefield
	bool Update(Task userTask, string updateField);
	// Marks the task done in the task list
	bool markDone(Task task);
	// Removes the most recent change to the task list
	bool undo();
	// Sorts the task list according to the done tasks, start date and start time
	void sort();
	// Sorts the task list according to the start date and start time
	void sortDateandTime(int start, int end);
	// Sorts the task list according to the done tasks
	void sortdone();
	
	// Display helper functions

	// Returns a pointer to the complete task list to GUI 
	vector<Task>* getTaskList();
	// Returns a pointer to the searched list to GUI
	vector<Task>* getSearchedList();
	// Returns a pointer to the tasks due today to GUI
	vector<Task>* getTodayTask();
	// Returns a pointer to the tasks due tomorrow to GUI
	vector<Task>* getTomorrowTask();
	// Returns a pointer to the overdue tasks to GUI
	vector<Task>* getOverdueTasks();
	// Returns a pointer to the done tasks to GUI
	vector<Task>* getMarkedTasks();
	// Returns a pointer to undone tasks to GUI
	vector<Task>* getUnmarkedTasks();
	
	// Getter functions

	// Returns the task to the function
	Task getTask(int Index);
	// Returns the size of the vector
	string getSize();
	// Issues a new task ID to the task
	int issueNewTaskID();
	// Returns the date of today
	string getTodayDay();
	// Returns the month of today
	string getTodayMonth();
	// Returns the year for today
	string getTodayYear();
	// Returns the date for tomorrow
	vector<string> getTomorrowDate();
};

#endif