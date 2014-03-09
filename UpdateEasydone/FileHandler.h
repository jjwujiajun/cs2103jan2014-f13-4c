
#pragma once
#ifndef _STORE_H_
#define _STORE_H_

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
	bool fileReady(string fileName);
	bool diskcopy(string fileName);

};

#endif 