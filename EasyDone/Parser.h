// parser will pass string of commands without the details

#include "Headers.h"

#define MAX_SIZE 255
using namespace std; 

const string MESSAGE_ADD = "add";
const string MESSAGE_NEW = "new";
const string MESSAGE_READ = "display";
const string MESSAGE_UPDATE = "update";
const string MESSAGE_DELETE = "delete";
const string MESSAGE_SEARCH = "search";
const string MESSAGE_CHECK = "check";
const string MESSAGE_INVALID  = "Wrong command! Please enter command again ";
const string MESSAGE_SUCCESSFUL = "Details successfully Parsed";
const string MESSAGE_ERROR = "Details NOT Parsed ERROR!!!";

class Parser {

private:

	
	vector<string> userInformation;
	vector<string> storeUserInfo;
	Log log;
	
	//vector<string> userInformationDelete;




public:
	Parser(void);
	~Parser(void);
	int actionIndex;
	

	enum Choice{
		ADD, READ, UPDATE, DELETE, SEARCH, CHECK, ERROR
	};

	Choice userCommand(string);

	
	vector<string> completeParse(string userInput); 
	vector<string> storeInformation(string userInput);

	// this vector of strings to store the commands and pass it back to manager
	vector<string> parseCommand(string userInput);

	// parseDetails will return if the parsing of details was successful or not
	bool parseDetails(string userInput);

	void parserEmpty();


};

/*
public:
	parser(void);
	~parser(void);

	void parseInput(string input);
	void parseCommandz(string input, int &i);
	void receiveUserInput();
	void parseCommand(string input);
	void parseText(string input);
	void parseDueTime(string input);
	void parseDueDate(string input);

	enum Command {ADD, DELETE};

	Command command;
	string _taskName;
	int _startDate; //YYYYMMDD
	int _startTime;	//HHMM
	int _endDate;	//YYYYMMDD
	int _endTime;	//HHMM
	string _recurrence;
	string _reminderInfo;
};
*/