#include <fstream>
#include <string>
using namespace std;
#pragma once
const string LOG_FILE = "log.txt";
const string LOG_SEQUENCE_START = "Log sequence: \n";

class Log
{
private:
	ofstream file;

public:
	Log(void);
	~Log(void);

	void clear();
	void log(string);
	void endLog();
};

