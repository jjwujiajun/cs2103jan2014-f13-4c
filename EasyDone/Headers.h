#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <ctime>
#include <time.h>
#include <cctype>
#include <iterator>
#include "Log.h"
#include "Task.h"
#include <assert.h>

const string GUI_LABEL_TODAY = "Today \n";
const string GUI_LABEL_ALLTASKS = "All Tasks \n";
const string GUI_FONT_LABEL = "Broadway";

// ALL
const string SYSTEM_ENDL = "\r\n";
const string NULL_STRING = "";

// GUI
const int TASKLIST_RETRACT_ROW = 19;
const int TASKLIST_EXTENT_ROW = 24;
const int TASKLIST_X = 351;
const int TASKLIST_Y_RETRACT = 376;
const int TASKLIST_Y_EXTENT = 482;
const int RADIO_X_SUMMARY = 165;
const int RADIO_X_ALL = 180;
const int RADIO_X_DONE = 194;
const int RADIO_Y_RETRACT = 433;
const int RADIO_Y_EXTENT = 537;
const int FORM_X_RETRACT = 375;
const int FORM_X_EXTENT = 674;
const int FORM_Y = 587;
const int TAB_X_RETRACT = 355;
const int TAB_X_EXTENT = 655;
const int TAB_Y_HELP = 327;
const int TAB_Y_SETTING = 417;
const float HELP_SIZE_HEADING = 12;
const float HELP_SIZE_INSTRUCTION = 10;
const float TASKLIST_SIZE_INDEX = 8;
const float TASKLIST_SIZE_TASKINFO = 11;
const float TASKLIST_SIZE_HEADING = 12;

const int THEME_NUMBER = 3;
enum themeColor {WHITE, BLUE, METAL};


// MGR
const string FEEDBACK_MESSAGE_WELCOME = "Hi! Welcome to EasyDone!\r\n \r\n";
const string FEEDBACK_PROMPT_START = "What would you like to do?\r\n add • update • display • search • delete";
const string FEEDBACK_PROMPT_OTHERS = "What else would you like to do? \r\n";
const string LOG_MANAGER_TO_PARSER = "Manager: Pass userInput to parser";
const string LOG_MANAGER_TO_WORKER = "Manager: Pass parsedInput to worker";
const string LOG_STRING_USERINPUT = "User input: ";
const int HELP_NUMBER_OF_SECTIONS = 6;
const string FILE_HELP_HEADINGS = "helpHeadings";
const string FILE_HELP_INSTRUCTIONS = "helpInstruction";
const string TYPE_TEXTFILE = ".txt";
const string FILE_SETTINGS_THEME = "theme.txt";
const string FILE_SETTING_FEEDBACK = "feedbackSetting.txt";
const string FILE_SETTING_HELPTAB = "helpTabSetting.txt";
const string FILE_SETTING_SETTINGSTAB = "settingsTabSetting.txt";
const string FILE_STRING_TRUE = "true";
const string FILE_STRING_FALSE = "false";
const string FILE_STRING_WHITETHEME = "white";
const string FILE_STRING_BLUETHEME = "blue";
const string FILE_STRING_METALTHEME = "metal";

// WKR
const int TASKLIST_INDEX_LENGTH = 2;
const int TASKLIST_NAME_LENGTH = 25;

#pragma once

class Headers
{
public:
	Headers(void);
	~Headers(void);
};
#endif
