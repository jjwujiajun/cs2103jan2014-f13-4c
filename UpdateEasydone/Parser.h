#ifndef PARSER_H
#define PARSER_H

// parser will pass string of commands without the details

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm> 
#include <queue>

#define MAX_SIZE 255
using namespace std; 

class Parser {

private:

	vector<string> userInformation;
	static const string MESSAGE_ADD;
	static const string MESSAGE_UPDATE;
	static const string MESSAGE_DELETE;
	static const string MESSAGE_SEARCH;
	static const string MESSAGE_CHECK;

public:


	Parser(void);
	~Parser(void);
	vector<string> completeParse(string userInput); 
	int parseCommand(string userInput);
	vector<string> parseDetails(string userInput);

};

#endif
