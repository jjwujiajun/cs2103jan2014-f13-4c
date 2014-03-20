#include "Headers.h"
#include "Manager.h"

using namespace std;

int main() {
	Manager manager;
	string userInput;
	vector<Task> taskList;
	int i = 0;
	
	while(userInput != "exit") {
		cout << manager.getFeedback();
		getline(cin, userInput);

		manager.receiveInput(userInput);

		taskList = manager.getTaskList();
		while (i < taskList.size()) {
			cout << taskList[i].taskID << " " 
				 << taskList[i].startTime << " "
				 << taskList[i].startDate << " "
				 << taskList[i].taskName << endl;
			++i;
		}

		cout << manager.getFeedback() << endl;
	}

	return 0;
}