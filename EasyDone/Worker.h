// Worker.h


#include "Headers.h"
#include "Command.h"

using namespace std;

class Worker {


	//Store todoList;
	Command userCommand;
	Task userTask; 
	string command;
	string updateField;

	void convertTaskDataToDisplayFormat(vector<Task> &);

	

	string successful;
	string returnStringtomain;
	string stringToMain;
		

	static const string MESSAGE_ADDED_SUCCESSFULLY;
	static const string MESSAGE_DELETED_SUCCESSFULLY;
	static const string MESSAGE_UPDATED_SUCCESSFULLY;
	static const string MESSAGE_CHECKED_SUCCESSFULLY;
	static const string MESSAGE_WRONG_INDEX;
	static const string MESSAGE_ENTER_VALID_COMMAND;
	static const string NULL_STRING;


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


