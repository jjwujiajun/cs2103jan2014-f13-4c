#include <string>
using namespace std;

#pragma once
class Manager {
private:
	string _userInput;

public:
	Manager(void);
	~Manager(void);

	void receiveInput(string);
	string getUserInput();
};

