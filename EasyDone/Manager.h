// Manager.h
/* The manager is the facade of the whole Logic unit.
 * It links the GUI seamlessly with all the logic components.
 *
 * Functions include:
 * 1. Parsing user input for understanding
 * 2. Performing the tasking requirements
 * 3. Manange the live feedback required for easy use for beginners.
 */

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

	bool inputIsSearchQuery;

	void init();
	void loadHelpPage();

public:

	Manager(void);
	~Manager(void);

	// Takes in an input string and perform it's command on the to-do list
	void receiveInput(string input);

	// Checks a string to see if the user is at a stage where he should be given prompt of help.
	bool hasFeedbackForGivenInput(const string &);
	// Checks if the user input is a search query, so live manipulation of task list can be performed
	bool checkInputIsSearchQuery();
	string getFeedback();
	string getInputField();

	vector<Task> getAllTaskList();
	vector<Task> getTodayTaskList();
	vector<Task> getTomorrowTaskList();
	vector<Task> getDueTaskList();
	vector<Task> getSearchedList();
	vector<Task> getDoneTaskList();

	// Get the headings that are necessary for display on help page
	vector<string> getHelpHeadings();
	// Get the instructions that are necessary for display on help page
	vector<string> getHelpInstructions();
	// Gets the preset theme saved by the user on previous use
	themeColor getPresetTheme();
	// Gets the various settings saved by the user on previous use. Include feedback, help tab, settings tab in that order.
	void getPresetSettingFor(bool& feedback, bool& helpTab, bool& settingsTab);

	// Save the current user theme color selection
	void saveTheme(themeColor);
	// Save the current user feedbackBox setting
	void saveFeedbackBoxSetting(bool);
	// Save the current user help tab setting
	void saveHelpTabSetting(bool);
	// Save the current user setting tab setting
	void saveSettingTabSetting(bool);
};
