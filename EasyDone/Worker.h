// Worker.h


#include "Headers.h"
#include "Command.h"

using namespace std;

class Worker {
private:

	
	//Store todoList;
	Command userCommand;
	Task userTask; 
	string command;

	//variables to store the various components from parsedCommandstring
	/*string taskID;
	string command; //vector index 0
	string taskName; //vector index 1
	string startDate; //vector index 2
	string startTime; //vector index 3
	string endDate; //vector index 4
	string endTime; //vector index 5
	string index; //vector index 6
	string fieldtoUpdate; //vector index 7
	string updateContent; //vector index 8*/

	string successful;
	//int newIndex;
	//int size_todoList;
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
};


