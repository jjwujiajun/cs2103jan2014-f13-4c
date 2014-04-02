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
	
	
	Log log;
	
public:
	Parser(void);
	~Parser(void);

	enum Choice{
		ADD, READ, UPDATE, DELETE, SEARCH, CHECK, UNDO, OTHER
	};

	Choice userCommand(vector<string> storeUserInfo);

	vector<string> completeParse(string userInput); 
	vector<string> storeInformation(string userInput);

	// this vector of strings to store the commands and pass it back to manager
	vector<string> parseCommand(vector<string> storeUserInfo);

	// parseDetails will return if the parsing of details was successful or not
	bool parseDetails(vector<string> storeUserInfo);

	void parserEmpty();

};
