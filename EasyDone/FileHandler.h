//@author A0100705Y
// FileHandler.h
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Headers.h"

using namespace std;

class FileHandler {

private:
	ofstream writeFile;
	ifstream readFile;

public:
	void createHelpHeadingInVector(vector<string>&);
	void createHelpInstructionsInVector(vector<string>&);
	vector<Task> getTaskList();
	void saveTaskList(const vector<Task>&);
	bool getPresetSetting(const string&);
	themeColor getPresetTheme();
	void saveSettingForFile(const bool&, const string&);
	void saveTheme(const themeColor&);
};

#endif