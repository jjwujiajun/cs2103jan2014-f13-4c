#include "Parser.h"

//These are messages that will be used by the programme
const string Parser::MESSAGE_ADD =  "add";
const string Parser::MESSAGE_NEW = "new";
const string Parser::MESSAGE_READ = "display";
const string Parser::MESSAGE_UPDATE = "update";
const string Parser::MESSAGE_DELETE = "delete";
const string Parser::MESSAGE_SEARCH = "search";
const string Parser::MESSAGE_CHECK = "check";




Parser::Parser(void) {


}

Parser::~Parser() {

}


Parser::Choice Parser::userCommand(string input) { 

	if (input == MESSAGE_ADD) {
		return ADD;
	} else if (input == MESSAGE_READ) {
		return READ;
	} else if (input == MESSAGE_UPDATE) {
		return UPDATE;
	} else if (input == MESSAGE_DELETE) {
		return DELETE;
	} else if (input == MESSAGE_SEARCH) {
		return SEARCH;
	} else if (input == MESSAGE_CHECK) {
		return CHECK;
	}

}


/*
enumLine = changeEnum(line);

switch (enumLine) {

case ADD:
add();
updateFile();
break;

case DEL:
int delLine;
writeFile->close();
cin >> delLine;
del(delLine);
break;
*/
//returns 1 if userInput has been parsed successfully


// parseCommand to process usercommand and sieve out first word which is the command. Eg. add, delete etc
// it will return an interger value to the manager
int Parser::parseCommand(string userInput) {

	Choice enumCommand;
	enumCommand = userCommand(userInput);

	switch(enumCommand) {

	case ADD:
		return 1;
		break;

	case READ:
		return 2;
		break;

	case UPDATE:
		return 3;
		break;

	case DELETE:
		return 4;
		break;

	case SEARCH:
		return 5;
		break;

	case CHECK:
		return 6;
		break;
	}

}


vector<string> Parser::parseDetails(string userInput) {

	/*
	//Breaks the entire user input string into words and stores it into the vector concatedUserInformation
    istringstream iss(userInput);
    copy(istream_iterator<string>(iss), istream_iterator<string>(),  back_inserter<vector<string> >(userInformation));
	*/

	int counter = 1;
	vector<string>::iterator iter = userInformation.begin();
	unsigned int tStart = 0, tEnd = 0;
	string token;
	
	tEnd = userInput.find_first_of("/."); // pos not provided. Default value of 0 is used
	

	while(tEnd != string::npos) {
		token = userInput.substr(tStart, tEnd - tStart);
		userInformation.push_back(token);
		cout << "push " << token << endl;
		tStart = tEnd + 1;
		tEnd = userInput.find_first_of("/.", tStart); // looks from tStart position
	}
	// print last token
	if (tStart <userInput.size()) {
		userInformation.push_back(userInput.substr(tStart));
		cout << "push " << token << endl;
	}

	for (iter = userInformation.begin()+1; iter != userInformation.end(); ++iter) { 
		cout << endl << counter << ". " << *iter; 
		counter++;
	}

	return userInformation;
}


/*
string token, mystring("scott>=tiger");
while(token != mystring){
  token = mystring.substr(0,mystring.find_first_of(">="));
  mystring = mystring.substr(mystring.find_first_of(">=") + 1);
  printf("%s ",token.c_str());
}
*/


vector<string> Parser::completeParse(string userInput) {

	actionIndex = parseCommand(userInput);  //returns corresponding command index eg add: 1 update 2 etc.
	parsedDetails = parseDetails(userInput); //returns details of task inputted by user in the form of a vector<string>

	return 1;

}

/*
void Parser:: getInput() {

string line;
Choice enumLine;

cin >> line;
enumLine = userCommand(line);

getchar(); // for enter

cin >> line;

}
*/




/*
#include "stdafx.h"
#include "parser.h"

parser::parser(void) {
}


parser::~parser(void) {
}

void parser::receiveUserInput() {
string input;

cin >> input;
//conversion method
parseCommand(input);

getchar();

cin >> input;
//conversion method
if (input[0] == '\"') {
//parseDueDate(input);
} else if (input[0] == '\\') {
parseDueTime(input);
} else if (input[0] == '/') {
parseDueDate(input);
}
}


void parser::parseInput(string input) {
int index = 0;
int &i = index;
int inputLength = input.length();

parseCommandz(input, i);
/*
while (i != inputlength) {
if (input[i] == '\"') {
parseTodoDescription(input, i)
}
if (input[i] == '/') {
parseDueDate(input, i);
}
}

}

void parser::parseCommandz(string input, int &i) {
char inputCommand[250];
while (input[i] != ' ') {
inputCommand[i] = input[i];
++i;
}

string stringCommand = (string)inputCommand;
if (stringCommand == "a" || stringCommand == "add" || stringCommand == "Add") {
command = ADD;
}
if (stringCommand == "d" || stringCommand == "del" || stringCommand == "delete" || stringCommand == "Delete") {
command = DELETE;
}

++i;
}
*/
