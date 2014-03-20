#include "Manager.h"

using namespace std;

int main() {
	Manager manager;
	string userInput;
	
	while(userInput != "exit") {
		cout << manager.getFeedback();
		getline(cin, userInput);

		manager.receiveInput(userInput);
	/*	cout << manager.getFeedback();
	*/
	}

	return 0;
}