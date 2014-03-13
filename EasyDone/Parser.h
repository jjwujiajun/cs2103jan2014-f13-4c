// parser will pass string of commands without the details

#include "Headers.h"

#define MAX_SIZE 255
using namespace std; 

class Parser {

private:

	vector<string> userInformation;
	static const string MESSAGE_ADD;
	static const string MESSAGE_NEW;
	static const string MESSAGE_READ;
	static const string MESSAGE_UPDATE;
	static const string MESSAGE_DELETE;
	static const string MESSAGE_SEARCH;
	static const string MESSAGE_CHECK;
	static const string MESSAGE_INVALID;
	static const string MESSAGE_SUCCESSFUL;
	static const string MESSAGE_ERROR;



public:
	
	int actionIndex;
	vector<string> parsedDetails;

	enum Choice{
		ADD, READ, UPDATE, DELETE, SEARCH, CHECK, ERROR
	};

	Choice userCommand(string);

	Parser(void);
	~Parser(void);
	vector<string> completeParse(string userInput); 
	

	// this vector of strings to store the commands and pass it back to manager
	vector<string> parseCommand(string userInput);

	// parseDetails will return if the parsing of details was successful or not
	bool parseDetails(string userInput);


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