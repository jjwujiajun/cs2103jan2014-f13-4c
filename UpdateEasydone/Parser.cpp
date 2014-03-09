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


}




// parseCommand to process usercommand and sieve out first word which is the command. Eg. add, delete etc
// it will return an interger value to the manager
string Parser::parseCommand(string userInput) {

	

}


vector<string> Parser::parseDetails(string userInput) {

	
}




vector<string> Parser::completeParse(string userInput) {

	string command = parseCommand(userInput);  //returns corresponding command index eg add: 1 update 2 etc.
	vector<string> parsedDetails = parseDetails(userInput); //returns details of task inputted by user in the form of a vector<string>

	return ;

}

