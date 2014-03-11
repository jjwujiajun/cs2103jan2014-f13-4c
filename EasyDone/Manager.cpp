#include "Manager.h"


Manager::Manager(void) {
}


Manager::~Manager(void) {
}

void Manager::receiveInput(string input) {
	_userInput = input;
}

string Manager::getUserInput() {
	return _userInput;
}