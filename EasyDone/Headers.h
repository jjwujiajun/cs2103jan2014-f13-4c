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
#include <stack>
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
const string STRING_QUOTE = "\"";
const string NULL_STRING = "";
const string STRING_SPACE = " ";
const string STRING_TRUE = "true";
const string STRING_FALSE = "false";
const string KEYWORD_ADD = "add";
const string KEYWORD_NEW = "new";
const string KEYWORD_CREATE = "create";
const string KEYWORD_DELETE = "delete";
const string KEYWORD_REMOVE = "remove";
const string KEYWORD_DISPLAY = "display";
const string KEYWORD_VIEW = "view";
const string KEYWORD_UPDATE = "update";
const string KEYWORD_EDIT = "edit";
const string KEYWORD_CHANGE = "change";
const string KEYWORD_SEARCH = "search";
const string KEYWORD_DONE = "done";
const string KEYWORD_UNDO = "undo";
const string KEYWORD_TASK = "task";
const string KEYWORD_STARTDATE = "sd";
const string KEYWORD_STARTTIME = "st";
const string KEYWORD_ENDDATE = "ed";
const string KEYWORD_ENDTIME = "et";
const string KEYWORD_ON = "on";
const string KEYWORD_TODAY = "today";
const string KEYWORD_TOMORROW_1 = "tmr";
const string KEYWORD_TOMORROW_2 = "tmo";

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
const string FEEDBACK_PROMPT_START = "What would you like to do? \r\nChoose a command\r\n add • update • display • search • delete • done • undo • exit";
const string FEEDBACK_PROMPT_OTHERS = "What else would you like to do? \r\nChoose a command\r\n add • update • display • search • delete • done • undo • exit";
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
const string FILE_STRING_WHITETHEME = "white";
const string FILE_STRING_BLUETHEME = "blue";
const string FILE_STRING_METALTHEME = "metal";
const int TASKLIST_INDEX_LENGTH = 2;
const int TASKLIST_NAME_LENGTH = 25;

// PSR
// Command "add" keywords
const string keyWord_1 ("on");
const string keyWord_ON_ ("on ");
const string keyWord_2 ("by");
const string keyWord_BY_ ("by ");
const string keyWord_3 ("from");
const string keyWord_FROM_ ("from ");
const string keyWord_4 ("to");
const string keyWord_5 ("today");
const string keyWord_6 ("tmo");
const string keyWord_7 ("tmr");
// Command "edit" keywords
const string task ("task");
const string sd ("sd");
const string st ("st");
const string ed ("ed");
const string et ("et");
// Year
const string YEAR_14 ("14");
// Months
const string MONTH_1 ("jan");
const string MONTH_2 ("feb");
const string MONTH_3 ("mar");
const string MONTH_4 ("apr");
const string MONTH_5 ("may");
const string MONTH_6 ("jun");
const string MONTH_7 ("jul");
const string MONTH_8 ("aug");
const string MONTH_9 ("sep");
const string MONTH_10 ("oct");
const string MONTH_11 ("nov");
const string MONTH_12 ("dec");
const string FORMAT_MONTH_1 (" Jan");
const string FORMAT_MONTH_2 (" Feb");
const string FORMAT_MONTH_3 (" Mar");
const string FORMAT_MONTH_4 (" Apr");
const string FORMAT_MONTH_5 (" May");
const string FORMAT_MONTH_6 (" Jun");
const string FORMAT_MONTH_7 (" Jul");
const string FORMAT_MONTH_8 (" Aug");
const string FORMAT_MONTH_9 (" Sep");
const string FORMAT_MONTH_10 (" Oct");
const string FORMAT_MONTH_11 (" Nov");
const string FORMAT_MONTH_12 (" Dec");
// Day
const string DAY_0 ("0");
const string DAY_1 ("1");
const string DAY_2 ("2");
const string DAY_3 ("3");
const string DAY_4 ("4");
const string DAY_5 ("5");
const string DAY_6 ("6");
const string DAY_7 ("7");
const string DAY_8 ("8");
const string DAY_9 ("9");
const string DAY_10 ("10");
const string DAY_11 ("11");
const string DAY_12 ("12");
const string DAY_13 ("13");
const string DAY_14 ("14");
const string DAY_15 ("15");
const string DAY_16 ("16");
const string DAY_17 ("17");
const string DAY_18 ("18");
const string DAY_19 ("19");
const string DAY_20 ("20");
const string DAY_21 ("21");
const string DAY_22 ("22");
const string DAY_23 ("23");
const string DAY_24 ("24");
const string DAY_25 ("25");
const string DAY_26 ("26");
const string DAY_27 ("27");
const string DAY_28 ("28");
const string DAY_29 ("29");
const string DAY_30 ("30");
const string DAY_31 ("31");
const string DAY_123 ("123");
// Time
const string TIME_0 ("0");

// WKR
const string MESSAGE_ADDED_SUCCESSFULLY = "has been added successfully! :) \r\n";
const string MESSAGE_ADDED_FAILED_TASK_IN_LIST = "task is already inside the list!\r\n";
const string MESSAGE_ADDED_FAILED = "Task has not been added successfully! ): ";
const string MESSAGE_ADDED_FAILED_INVALID_DATE = "Invalid date! Is it a 30th or 31st?? Ensure time format is correct too! =) \r\n";
const string MESSAGE_ADDED_FAILED_INVALID_YEAR = "Invalid year! Year valid till 2099! Ensure time format is correct too! =) \r\n";
const string MESSAGE_ADDED_FAILED_INVALID_DATE_MONTH = "Invalid date & Month! Month is from 1 to 12! Ensure time format is correct too! =) \r\n";
const string MESSAGE_ADDED_FAILED_INVALID_DATE_YEAR = "Invalid date & Year! Is it a leap Year?? Ensure time format is correct too! =) \r\n";
const string MESSAGE_ADDED_FAILED_INVALID_DATE_MONTH_YEAR = "Invalid Date & Month & Year! Type Carefully! Ensure time format is correct too! ";
const string MESSAGE_ADDED_FAILED_INVALID_TIME = "Invalid Time! Remember hour is from 00 to 23, Minute is from 00 to 59 ";
const string MESSAGE_ADDED_FAILED_CHRONO_ORDER = "Start date cannot be after end date. Similarly if the start date and end date are same, start time cannot be after end time.\r\n";
const string MESSAGE_DELETED_SUCCESSFULLY = "has been deleted successfully! :) \r\n";
const string MESSAGE_UPDATED_SUCCESSFULLY = "has been updated successfully! :) \r\n";
const string MESSAGE_UPDATED_FAILED = "Task has not been edited successfully! ):";
const string MESSAGE_UPDATED_FAILED_DUPLICATE = "updated task already exists in the list. Therefore, it has been removed from the list. You may undo to get the unupdated task back.\r\n";
const string MESSAGE_UPDATED_FAILED_INVALID_DATE = "Invalid date! Is it a 30th or 31st?? Ensure time format is correct too! =) \r\n";
const string MESSAGE_UPDATED_FAILED_INVALID_YEAR = "Invalid Year! Year valid till 2099! Ensure time format is correct too! =) \r\n";
const string MESSAGE_UPDATED_FAILED_INVALID_DATE_MONTH = "Invalid date & Month! Month is from 1 to 12! Ensure time format is correct too! =) \r\n";
const string MESSAGE_UPDATED_FAILED_INVALID_DATE_YEAR = "Invalid date & Year! Is it a leap Year?? Ensure time format is correct too! =) \r\n";
const string MESSAGE_UPDATED_FAILED_INVALID_DATE_MONTH_YEAR = "Invalid Date & Month & Year! Type Carefully! Ensure time format is correct too! =) \r\n";
const string MESSAGE_UPDATED_FAILED_INVALID_TIME = "Invalid Time! Remember hour is from 00 to 23, Minute is from 00 to 59  \r\n";
const string MESSAGE_UPDATED_FAILED_OUT_OF_RANGE = "Either invalid field input or taskID is out of range! Please check again.\r\n";
const string MESSAGE_UPDATED_FAILED_CHRONO_DATE = "The task can't end before it starts. Please check again.\r\n";
const string MESSAGE_UPDATED_FAILED_CHRONO_TIME = "The task can't end before it starts. Please check again.\r\n";
const string MESSAGE_CHECKED_SUCCESSFULLY = "has been checked off your EasyDone task list! :) \r\n";
const string MESSAGE_DONE_SUCCESSFUL = "Task marked done.\r\n";
const string MESSAGE_DONE_FAILED = "Task not found.\r\n";
const string MESSAGE_SEARCH_SUCCESSFUL = "These tasks found.";
const string MESSAGE_SEARCH_FAILED = "Task not found.\r\n";
const string MESSAGE_DISPLAY_START = "Starts: ";
const string MESSAGE_DISPLAY_SPACE_FORMATTING = "   ";
const string MESSAGE_DISPLAY_END = "Ends: ";
const string MESSAGE_UNDO_SUCCESSFUL = "The most recent change has been removed.\r\n";
const string MESSAGE_UNDO_FAILED = "Nothing is undone.\r\n";
const string MESSAGE_WRONG_INDEX = "Please enter a valid index! \r\n";
const string MESSAGE_OUT_OF_RANGE_INDEX = "TaskID is out of range. Please check again.\r\n";
const string MESSAGE_ENTER_VALID_COMMAND = "Please enter a valid command! \r\n";
const string TASK_INDEX_FORMATTING = "0";
const string TASK_TIME_FORMATTING = ":";
const string TASK_EMPTY_TIME = "   -- ";
const string KEYWORD_startDate = "startDate";
const string KEYWORD_startTime = "startTime";

// Store
const string WORD_STARTDATE = "startDate";
const string WORD_STARTTIME = "startTime";

// File Handler
const string FILE_TASKLIST = "taskList.txt";
const string HELP_ADD_HEADING = "EasyAdd";
const string HELP_ADD = "Examples: \r\n• new Birthday party on 12/12/14 12.00\r\nFormat:\r\n• add <task> on <sd> <st>\r\n• add <task> by <ed> <et>\r\n• add <task> from <sd> <st> to <ed> <et>\r\n   Date Format: DD/MM/YY\r\n   Time Format: HH.MM\r\n";
const string HELP_DELETE_HEADING = "EasyDelete";
const string HELP_DELETE = "Example: • delete 10      Format: • delete <ID>\r\n";
const string HELP_UPDATE_HEADING = "EasyUpdate";
const string HELP_UPDATE = "Example: • update 2 sd 13/12/14\r\nFormat:\r\n• update <ID> <field name> <updated info>\r\n";
const string HELP_DISPLAY_HEADING = "EasyDisplay";
const string HELP_DISPLAY = "Example: • display 1           Format:• display <ID>\r\n";
const string HELP_UNDO_HEADING = "EasyUndo";
const string HELP_UNDO = "Format: • undo                 That's it.\r\n";
const string HELP_SEARCH_HEADING = "EasySearch";
const string HELP_SEARCH  = "Example: • search task party\r\nFormat: • search <field name> <query>";

#pragma once

class Headers
{
public:
	Headers(void);
	~Headers(void);
};
#endif
