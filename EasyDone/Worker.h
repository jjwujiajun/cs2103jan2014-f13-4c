//@author A0099326U
// Worker.h
/* Worker receives the parsed command from the Parser through the Manager.
 * It excutes the commands from the user and returns the result to be displayed on the GUI.
 * 
 * Functions include:
 * 1. Identifying the parsed command and using the date provided by user accordingly.
 * 2. Executing the the commands by linking to store through Command class.
 * 3. Analysing the execution and returning the feedback to the GUI to be displayed.
 * Coded by Arun Kumar
*/


#include "Headers.h"
#include "Command.h"

using namespace std;

class Worker {
private:
	// Member Classes
	Command userCommand;
	Task userTask; 

	void convertTaskDataToDisplayFormat(vector<Task> &, bool shouldBeDetailed);
	 
	// Local variables used for functions
	string command;
	string updateField;
	string date;
	string month;
	string year;
	string store;
	string combine;

	string successful;
	string returnStringtomain;
	string stringToMain;
	string searchField;
	string searchItem;

	// Used to ensure data provided is correct
	bool continueNext;

public:

	Worker();
	~Worker();

	// Support functions

	// Takes the Parsed command, organizes the user data accordingly and returns
	// The feedback to be displayed on the GUI
	string takeparsedCommand(vector<string> fromManager);
	// Acts on the user command and executes the function
	string actonCommand(string command);

	// Display helper functions

	// Returns a pointer to the complete task list to GUI
	vector<Task>* getTaskList();
	// Returns a pointer to the searched list to GUI
	vector<Task>* getSearchedList();
	// Returns a pointer to the tasks due today to GUI
	vector<Task>* getTasksDueTodayList();
	// Returns a pointer to the tasks due tomorrow to GUI
	vector<Task>* getTasksDueTomorrowList();
	// Returns a pointer to the overdue tasks to GUI
	vector<Task>* getTasksOverdueList();
	// Returns a pointer to the done tasks to GUI
	vector<Task>* getTasksDoneList();
	// Returns a pointer to undone tasks to GUI
	vector<Task>* getTasksUndoneList();

	vector<string> tomorrowDate;

	// Formatting functions

	// Formats the date to be displayed on GUI
	string formatDate(string, bool shouldShowYear, bool shouldBeDetailed);
	// Formats the time to be displayed on GUI
	string formatTime(string, bool shouldBeDetailed);
};


