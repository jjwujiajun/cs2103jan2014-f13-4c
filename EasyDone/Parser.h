// parser will pass string of commands without the details

#include "Headers.h"

#define MAX_SIZE 255
using namespace std; 

const string MESSAGE_ADD = "add";
const string MESSAGE_NEW = "new";
const string MESSAGE_CREATE = "create";
const string MESSAGE_READ = "display";
const string MESSAGE_UPDATE = "update";
const string MESSAGE_EDIT = "edit";
const string MESSAGE_CHANGE = "change";
const string MESSAGE_DELETE = "delete";
const string MESSAGE_REMOVE = "remove";
const string MESSAGE_SEARCH = "search";
const string MESSAGE_CHECK = "check";
const string MESSAGE_INVALID  = "Wrong command! Please enter command again ";
const string MESSAGE_SUCCESSFUL = "Details successfully Parsed";
const string MESSAGE_ERROR = "Details NOT Parsed ERROR!!!";

class Parser {

	vector<string> storeUserInfo;
	vector<string> storeOther;
	vector<string> userInformation;
	
	string successful;
	
	Log log;
	
public:
	Parser(void);
	~Parser(void);

	enum Choice{
		ADD, READ, UPDATE, DELETE, SEARCH, CHECK, UNDO, OTHER
	};

	Choice userCommand(vector<string> storeUserInfo);

	// guards against wrong date and time
	// parse to manager as a string which will bring to worker to output error
	string checkParseDate(string date);
	string checkParseMonth(string date);
	string checkParseYear(string date);
	string checkParseTime(string time);

	// convert date & time to proper format for worker to take in

	string convertDate(string date);
	string convertTime(string time);

	// convert function from string to int

	int convertStringToInt(string input); 

	// guard to check if startTime/startDate is more than endTime/endDate

	bool compare(int start, int end);



	// ***** Main functions of Parser *****

	// Most important function for manager to call parser
	vector<string> completeParse(string userInput); 

	// Foundation of the Parser: splits up user input into a vector of strings
	vector<string> storeInformation(string userInput);

	// parseDetails will parse the relevant details of different commands to worker
	bool parseDetails(vector<string> storeUserInfo);
	// this vector of strings to store the commands and pass it back to manager
	vector<string> parseCommand(vector<string> storeUserInfo);

	// resets the parser to take in new commands
	void parserEmpty();

};
