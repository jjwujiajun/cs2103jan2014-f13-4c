// parser will pass string of commands without the details

#include "Headers.h"

#define MAX_SIZE 255
using namespace std; 


class Parser {


	vector<string> storeUserInfo;
	vector<string> userInformation;
	
	Log log;
	





public:
	Parser(void);
	~Parser(void);

	
	
	
	

	enum Choice{
		ADD, READ, UPDATE, DELETE, SEARCH, CHECK, UNDO, ERROR
	};

	Choice userCommand(vector<string> storeUserInfo);

	
	vector<string> completeParse(string userInput); 
	vector<string> storeInformation(string userInput);

	// this vector of strings to store the commands and pass it back to manager
	vector<string> parseCommand(vector<string> storeUserInfo);

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