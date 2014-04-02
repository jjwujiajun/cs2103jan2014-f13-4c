// Worker.h


#include "Headers.h"
#include "Command.h"

using namespace std;


//const string NULL_STRING = "";
const string MESSAGE_ADDED_SUCCESSFULLY = "has been added successfully! :) \r\n";
const string MESSAGE_DELETED_SUCCESSFULLY = "has been deleted successfully! :) \r\n";
const string MESSAGE_UPDATED_SUCCESSFULLY = "has been updated successfully! :) \r\n"; 
const string MESSAGE_CHECKED_SUCCESSFULLY = "has been checked off your EasyDone task list! :) \r\n";
const string MESSAGE_WRONG_INDEX = "Please enter a valid index! \r\n";
const string MESSAGE_ENTER_VALID_COMMAND = "Please enter a valid command! \r\n";


class Worker {

private:
	Command userCommand;
	Add usercommandAdd;
	Delete usercommandDelete;
	Update usercommandUpdate;
	Display usercommandDisplay;
	Task userTask; 
	string command;
	string updateField;

	void convertTaskDataToDisplayFormat(vector<Task> &); //should this be here???
	
	string successful;
	string returnStringtomain;
	string stringToMain;
		

public:

	Worker();
	~Worker();

	// todoList function
	string addTask(string taskName1, string startDate1, string startTime1, string endDate1, string endTime1);
	string removeTaskWithIndex(string taskIndex);
	string updateTaskWithIndex(string index, string update, string fieldUpdate);
	//vector<string> displayTaskWithIndex(int index);

	// support functions
	string takeparsedCommand(vector<string> fromManager);
	string actonCommand(string command);
	//string display();

	vector<Task> getTaskList();
};


