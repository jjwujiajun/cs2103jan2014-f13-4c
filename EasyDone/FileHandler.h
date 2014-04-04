#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Headers.h"

using namespace std;

const string FILE_TASKLIST = "taskList.txt";

class FileHandler {

private:
	ofstream writeFile;
	ifstream readFile;

public:
	vector<Task> getTaskList();
	void saveTaskList(const vector<Task>&);
	bool getPresetSetting(const string&);
	themeColor getPresetTheme();
	void saveSettingForFile(const bool&, const string&);
	void saveTheme(const themeColor&);
};

#endif