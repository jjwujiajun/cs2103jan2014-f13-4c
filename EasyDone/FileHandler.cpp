#include "FileHandler.h"

using namespace std;

vector<Task> FileHandler::getTaskList() {
	string line;
	bool isReadable;
	Task task;
	vector<Task> taskList;

	readFile.open(FILE_TASKLIST);

	while(getline(readFile, line)) {
		task.taskID = line;
		
		isReadable = getline(readFile, line);
		assert(isReadable == true);
		task.taskName = line;
		
		isReadable = getline(readFile, line);
		assert(isReadable == true);
		task.startDate = line;
		
		isReadable = getline(readFile, line);
		assert(isReadable == true);
		task.startTime = line;
		
		isReadable = getline(readFile, line);
		assert(isReadable == true);
		task.endDate = line;
		
		isReadable = getline(readFile, line);
		assert(isReadable == true);
		task.endTime = line;

		taskList.push_back(task);
		getline(readFile, line);
	}

	readFile.close();

	return taskList;
}

void FileHandler::saveTaskList(const vector<Task>& taskList) {
	writeFile.open(FILE_TASKLIST, ios::trunc);

	for (int i = 0; i < taskList.size(); ++i) {
		writeFile << taskList[i].taskID << endl;
		writeFile << taskList[i].taskName << endl;
		writeFile << taskList[i].startDate << endl;
		writeFile << taskList[i].startTime << endl;
		writeFile << taskList[i].endDate << endl;
		writeFile << taskList[i].endTime << endl;
		writeFile << endl;
	}

	writeFile.close();
}

