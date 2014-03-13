

#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>


using namespace std;

class FileHandler {

private:
	string line;
	vector<string> sentencesVector;
	static const string MESSAGE_OUTPUT_WELCOME;
	static const string MESSAGE_READY_FOR_USE;

public:
	void load(string inputText);
	void remove();
	bool fileReady(string fileName);
	bool diskcopy(string fileName);
	void copyfile();

};

#endif 