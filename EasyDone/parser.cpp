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
		parseDueDate(input);
	} else if (input[0] == '\\') {
		parseDueTime(input);
	} else if (input[0] == '/') {
		parseDueDate(input);
	}
}

void parser::parseCommand(string input) {
	if (input == "a" || input == "add" || input == "Add") {
		command = ADD;
	}
	if (input == "d" || input == "delete" || input == "Delete") {
		command = DELETE;
	}
}