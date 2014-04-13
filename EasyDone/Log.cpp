//@author A0100705Y
// Log.cpp
#include "Log.h"
using namespace std;

Log::Log(void) {
}


Log::~Log(void) {
}

void Log::clear() {
	ofstream file;
	file.open(LOG_FILE, ios::trunc);
	file << LOG_SEQUENCE_START;
	file.close();
}

void Log::log(string input) {
	file.open(LOG_FILE, ios::app);

	file << input << endl;

	file.close();
}

void Log::endLog() {
	file.open(LOG_FILE, ios::app);

	file << endl;

	file.close();
}