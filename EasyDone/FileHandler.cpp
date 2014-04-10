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
		assert(isReadable);
		task.taskName = line;
		
		isReadable = getline(readFile, line);
		assert(isReadable);
		task.startDate = line;
		
		isReadable = getline(readFile, line);
		assert(isReadable);
		task.startTime = line;
		
		isReadable = getline(readFile, line);
		assert(isReadable);
		task.endDate = line;
		
		isReadable = getline(readFile, line);
		assert(isReadable);
		task.endTime = line;

		isReadable = getline(readFile, line);
		assert(isReadable);
		if (line == FILE_STRING_TRUE) {
			task.isDone = true;
		} else {
			assert(line == FILE_STRING_FALSE);
			task.isDone = false;
		}

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
		if (taskList[i].isDone) {
			writeFile << FILE_STRING_TRUE << endl;
		} else {
			writeFile << FILE_STRING_FALSE << endl;
		}
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

themeColor FileHandler::getPresetTheme() {
	ifstream presetTheme;
	string fileStoredTheme;
	themeColor theme;

	presetTheme.open(FILE_SETTINGS_THEME);
	getline(presetTheme, fileStoredTheme);

	if (fileStoredTheme == FILE_STRING_BLUETHEME) {
		theme = BLUE;
	} else if (fileStoredTheme == FILE_STRING_METALTHEME) {
		theme = METAL;
	} else {
		theme = WHITE;
	}
	presetTheme.close();
	return theme;
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

void FileHandler::saveTheme(const themeColor& theme) {
	ofstream presetTheme;
	string fileStoredTheme;
	presetTheme.open(FILE_SETTINGS_THEME, ios::trunc);

	if (theme == WHITE) {
		presetTheme << FILE_STRING_WHITETHEME << endl;
	} else if (theme == BLUE) {
		presetTheme << FILE_STRING_BLUETHEME << endl;
	} else if (theme == METAL) {
		presetTheme << FILE_STRING_METALTHEME << endl;
	}
}