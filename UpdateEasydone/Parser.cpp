#include "Parser.h"

//These are messages that will be used by the programme
const string Parser::MESSAGE_ADD =  "add";
const string Parser::MESSAGE_READ = "display";
const string Parser::MESSAGE_UPDATE = "update";
const string Parser::MESSAGE_DELETE = "delete";

Parser::Parser(void){


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
	}

}

//returns 1 if userInput has been parsed successfully
bool Parser::completeParse(string userInput) {

	actionIndex = parseCommand(userInput);  //returns corresponding command index eg add: 1 delet: 2 etc.
	parsedDetails = parseDetails(userInput); //returns details of task inputted by user in the form of a vector<string>

}




void Parser:: getInput() {
	
	string line;
	Choice enumLine;

	cin >> line;
	enumLine = Command(line);

	getchar(); // for enter

	cin >> line;
	
}

	



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
