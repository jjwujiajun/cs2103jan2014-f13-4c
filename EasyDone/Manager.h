#include "Headers.h"
#include "Parser.h"
#include "Worker.h"
#include "FileHandler.h"
using namespace std;

#pragma once

#define TESTMODE

class Manager {
#ifndef TESTMODE 
private: 
#else 
public: 
#endif
	
	// member classes
	FileHandler fileHandler;
	Parser parser;
	Worker worker;
	string userInput;
	Log log;

	// GUI displays
	vector<Task> GUITaskList;
	string GUIfeedbackBox;
	string GUIInputField;
	vector<string> GUIHelpHeadings;
	vector<string> GUIHelpInstructions;

	void init();
	void loadHelpPage();

public:

	Manager(void);
	~Manager(void);

	void receiveInput(string input);

	string getFeedback();
	string getInputField();
	vector<Task> getAllTaskList();
	vector<Task> getTodayTaskList();
	vector<Task> getTomorrowTaskList();
	vector<Task> getDueTaskList();
	vector<Task> getSearchedList();
	vector<Task> getDoneTaskList();

	vector<string> getHelpHeadings();
	vector<string> getHelpInstructions();
	themeColor getPresetTheme();
	void getPresetSettingFor(bool& feedback, bool& helpTab, bool& settingsTab);

	void saveTheme(themeColor);
	void saveFeedbackBoxSetting(bool);
	void saveHelpTabSetting(bool);
	void saveSettingTabSetting(bool);
};
