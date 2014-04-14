//@author A0094588J
// Purpose: Log.cpp will store all userInput into a .txt fil
// inclusive of all the loggings

#include "Log.h"
using namespace std;

Log::Log(void) {
}


Log::~Log(void) {
}

// Purpose: This function clears the log
// Pre-req: nil
// Post-req: nil
void Log::clear() {
	ofstream file;
	file.open(LOG_FILE, ios::trunc);
	file << LOG_SEQUENCE_START;
	file.close();
}

// Purpose: This function inputs the logging
// Pre-req: string of input
// Post-req: nil
void Log::log(string input) {
	file.open(LOG_FILE, ios::app);

	file << input << endl;

	file.close();
}

// Purpose: This function ends the log
// Pre-req: nil
// Post-req: nil
void Log::endLog() {
	file.open(LOG_FILE, ios::app);

	file << endl;

	file.close();
}