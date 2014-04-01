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

	for (int i = 0; i < (int) taskList.size(); ++i) {
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

bool FileHandler::getPresetSetting(const string& fileName) {
	string fileStoredSetting;
	ifstream file;
	bool setting;

	file.open(fileName);
	if (getline(file, fileStoredSetting)) {
		setting = fileStoredSetting == FILE_STRING_TRUE;
		return setting;
	}
	return true;
}

void FileHandler::saveSettingForFile(const bool& isOn, const string& fileName) {
	ofstream presetFile;
	
	presetFile.open(fileName, ios::trunc);
	if (isOn) {
		presetFile << FILE_STRING_TRUE;
	} else {
		presetFile << FILE_STRING_FALSE;
	}
}