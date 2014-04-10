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
const int HELP_TOGGLE_LEFT_LABEL_X = 134;
const int HELP_TOGGLE_RIGHT_LABEL_X = 207;
const int HELP_TOGGLE_LABEL_RETRACT_Y = 437;
const int HELP_TOGGLE_LABEL_EXTENT_Y = 541;
const float HELP_SIZE_HEADING = 12;
const float HELP_SIZE_INSTRUCTION = 10;
const float TASKLIST_SIZE_INDEX = 8;
const float TASKLIST_SIZE_TASKINFO = 11;
const float TASKLIST_SIZE_HEADING = 12;

const int THEME_NUMBER = 3;
enum themeColor {WHITE, BLUE, METAL};


// MGR
const string FEEDBACK_MESSAGE_WELCOME = "Hi! Welcome to EasyDone!\r\n \r\n";
const string FEEDBACK_PROMPT_START = "What would you like to do?\r\n add • update • display • search • delete • done • exit";
const string FEEDBACK_PROMPT_OTHERS = "What else would you like to do? \r\n add • update • display • search • delete • done • exit";
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
const string LIVE_FEEDBACK_ADD = "You're adding a task... \r\n\r\n";
const string LIVE_FEEDBACK_ADD_HINTDATE = "Now put in the date DD/MM/YY \r\n\r\n";
const string LIVE_FEEDBACK_ADD_FORMAT = "Format: add <task name> on <date>";
const string LIVE_FEEDBACK_DELETE = "You're deleting a task \r\n\r\nType in the ID that's on the left of the task name\r\n";
const string LIVE_FEEDBACK_DISPLAY = "You're displaying a task \r\n\r\nType in the ID that's on the left of the task name\r\n";
const string LIVE_FEEDBACK_UPDATE = "You're updating a task \r\n\r\nFormat: update <ID> <field> <new info> \r\n\r\n";
const string LIVE_FEEDBACK_UPDATE_FIELD = "The ID is on the left of the task name\r\nFields: task • sd • st • ed • et \r\n\r\n";
const string LIVE_FEEDBACK_UPDATE_TASK = "Now type in your new task name \r\n";
const string LIVE_FEEDBACK_UPDATE_DATE = "Put in the new date DD/MM/YY \r\n";
const string LIVE_FEEDBACK_UPDATE_TIME = "Put in the new time HH.MM \r\n";
const string LIVE_FEEDBACK_SEARCH = "You are searching... \r\n\r\nTell me the field name before you search the query\r\n task • sd • st • ed • et ";
const string LIVE_FEEDBACK_DONE = "You're marking a task as done \r\n\r\nType in the ID that's on the left of the task name\r\n";
const string LIVE_SEARCH_ENTER = "Press Enter when you're done";
const string KEYWORD_ADD = "add";
const string KEYWORD_DELETE = "delete";
const string KEYWORD_DISPLAY = "display";
const string KEYWORD_UPDATE = "update";
const string KEYWORD_SEARCH = "search";
const string KEYWORD_DONE = "done";
const string KEYWORD_TASK = "task";
const string KEYWORD_STARTDATE = "sd";
const string KEYWORD_STARTTIME = "st";
const string KEYWORD_ENDDATE = "ed";
const string KEYWORD_ENDTIME = "et";
const string KEYWORD_ON = "on";

// File Handler
const string FILE_TASKLIST = "taskList.txt";

#pragma once

class Headers
{
public:
	Headers(void);
	~Headers(void);
};
#endif
