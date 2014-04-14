

// Purpose: Parse.cpp will focus on parsing userInput, splitting up into single strings for easier manupliation
// Parser will return a vector of strings to manager who will then give it to worker to handle whatever is necessary
// Parser is like a stand-alone class, has low coupling since it does not really depend on other classes.
// Rather, other classes depend on parser to parse the inputs

#include "Headers.h"

#define MAX_SIZE 255
using namespace std; 

const string MESSAGE_ADD = "add";
const string MESSAGE_NEW = "new";
const string MESSAGE_CREATE = "create";
const string MESSAGE_DISPLAY = "display";
const string MESSAGE_VIEW = "view";
const string MESSAGE_UPDATE = "update";
const string MESSAGE_EDIT = "edit";
const string MESSAGE_CHANGE = "change";
const string MESSAGE_DELETE = "delete";
const string MESSAGE_REMOVE = "remove";
const string MESSAGE_SEARCH = "search";
const string MESSAGE_DONE = "done";
const string MESSAGE_CLEAR = "clear";
const string MESSAGE_UNDO = "undo";
const string CHECK_DATE = "0123456789 ";
const string GUARD_DATE = "01234567890123456789";
const string MESSAGE_INVALID  = "Wrong command! Please enter command again ";
const string MESSAGE_SUCCESSFUL = "Details successfully Parsed";
const string MESSAGE_ERROR = "Details NOT Parsed ERROR!!!";

const string DATE_jan = "jan";
const string DATE_Jan = "Jan";
const string DATE_JAN = "Jan";

const string DATE_feb = "feb";
const string DATE_Feb = "Feb";
const string DATE_FEB = "FEB";

const string DATE_mar = "mar";
const string DATE_Mar = "Mar";
const string DATE_MAR = "MAR";
const string DATE_march = "march";
const string DATE_March = "March";

const string DATE_apr = "apr";
const string DATE_Apr = "Apr";
const string DATE_APR = "APR";
const string DATE_april = "april";
const string DATE_April = "April";

const string DATE_may = "may";
const string DATE_May = "May";
const string DATE_MAY = "MAY";

const string DATE_jun = "jun";
const string DATE_Jun = "Jun";
const string DATE_JUN = "JUN";
const string DATE_june = "june";
const string DATE_June = "June";

const string DATE_jul = "jul";
const string DATE_Jul = "Jul";
const string DATE_JUL = "JUL";
const string DATE_july = "july";
const string DATE_July = "July";

const string DATE_aug = "aug";
const string DATE_Aug = "Aug";
const string DATE_AUG = "AUG";

const string DATE_sep = "sep";
const string DATE_Sep = "Sep";
const string DATE_SEP = "SEP";

const string DATE_oct = "oct";
const string DATE_Oct = "Oct";
const string DATE_OCT = "OCT";

const string DATE_nov = "nov";
const string DATE_Nov = "Nov";
const string DATE_NOV = "NOV";

const string DATE_dec = "dec";
const string DATE_Dec = "Dec";
const string DATE_DEC = "DEC";






class Parser {

	vector<string> storeUserInfo;
	vector<string> storeOther;
	vector<string> userInformation;
	string output;
	string intCheck;
	string successful;
	
	Log log;																
	
public:
	Parser(void);
	~Parser(void);

	enum Choice{
		ADD, READ, UPDATE, DELETE, SEARCH, CHECK, CLEAR, UNDO, OTHER
	};

	Choice userCommand(vector<string> storeUserInfo);

	// Purpose: This function convert an index string format 0000001 to 1 for guarding purposes
	// Application: functions that requires an index input => edit, delete, display
	// Pre-req: takes in a string index 
	// Post-req: returns a string of index which has no zeros in front
	string convert_From_String_To_String (string index);

	
	// Purpose: This function takes 3 string variables-> date, month and year in NLP format. it then converts to numerical format
	// Application: 14 jan 14 -> 14/1/14. Allows user to key in more variable NLP format but converts it to numerical
	// for worker to process
	// Pre-req: 3 string variables of date, month and eyar
	// Post-req: returns one string in DD/MM/YY format
	string naturalParseInput (string date, string month, string year);

	// Purpose: This function will check if the user input after the keywords (on, by, from, to) is a word or date/time
	// Application: used as a checker and guarder to determine if user is inputing a date/time after the keyword or not.
	// Allows more flexible command and not restricted by the keyword for the user.
	// Pre-req: takes in a string word
	// Post-req: returns a string output (either a date/time or a description word)
	string checkKeyWord (string word);


	// *** getter functions to get date, month, year ***

	// Purpose: This function get the day(numbers) from the date format DD/MM/YY or DD/M/YY
	// Application: Example-> 28/05/14  or 28/05/14 will get 28
	// Pre-req: takes in a string date
	// Post-req: returns an int day(numbers)
	int getDate(string date);

	// Purpose: This function get the month from the date format DD/MM/YY or DD/M/YY
	// Application: Example-> 28/5/14 or 28/05/14 will get 5
	// Pre-req: takes in a string date
	// Post-req: returns an int month
	int getMonth(string date);

	// Purpose: This function get the year from the date format DD/MM/YY or DD/M/YY
	// Application: Example-> 28/05/14  or 28/05/14 will get 14
	// Pre-req: takes in a string date
	// Post-req: returns an int year
	int getYear(string date);


	// *** guards against wrong date and time ***



	// Purpose: This function is to check if each month corresponds to the correct dates in the month
	// inclusive of leap year guard
	// Application: always use to check the dates inputed by the user. (no matter in 14/4/14 format or 14 apr 14 format)
	// Pre-req: takes in a string date format DD/MM/YY or DD/M/YY
	// Post-req: returns an a string number-> "0" if its fail and "1" if its success
	// 
	string checkDate(string date);

	// Purpose: This function checks the date from the date format DD/MM/YY or DD/M/YY
	// Application: Example-> 28/05/14  or 28/05/14 will get 1,  30/2/14 will get 0
	// Pre-req: takes in a string date
	// Post-req: returns a string number to check if day is correct in which "0" means fails and "1" means success
	string checkParseDate(string date);


	// Purpose: This function checks the date from the date format DD/MM/YY or DD/M/YY
	// Application: Example-> 28/05/14  or 28/05/14 will get 1,  30/22/14 will get 0
	// Pre-req: takes in a string date
	// Post-req: returns a string number to check if month is correct in which "0" means fails and "1" means success
	string checkParseMonth(string date);


	// Purpose: This function checks the date from the date format DD/MM/YY or DD/M/YY
	// Application: Example-> 28/05/14  or 28/05/14 will get 1,  30/2/140 will get 0
	// Pre-req: takes in a string date
	// Post-req: returns a string number to check if year is correct in which "0" means fails and "1" means success
	// Note: year is limited to 2100
	string checkParseYear(string date);


	// Purpose: This function checks the time from the time format HH.MM
	// Application: Example-> 10.35 will get 1,  25.21 will get 0
	// Pre-req: takes in a string time
	// Post-req: returns a string number to check if time is correct in which "0" means fails and "1" means success
	string checkParseTime(string time);

	
	
	// *** convert date & time to proper format for worker to take in ***


	// Purpose: This function converts the date format from DD/MM/YY or DD/M/YY to YYYYMMDD
	// Application: Example-> convert 12/12/14 to 20141212, convert 12/5/14 to 20140512
	// Pre-req: takes in a string time
	// Post-req: returns a string date in the format of YYYYMMDD
	string convertDate(string date);


	// Purpose: This function checks converts the time from the time format HH.MM to HHMM
	// Application: Example-> 10.35 will get 1035, 
	// Pre-req: takes in a string time
	// Post-req: returns a string time in the format of HHMM
	string convertTime(string time);

	// Purpose: This function checks converts string to int
	// Application: for guards and checkers to check if the string date, month or year exceeds the limit
	// Pre-req: takes in a string input of date or time
	// Post-req: returns an int

	int convertStringToInt(string input); 


	//*** main securtiy function to run all the guards & conversion ***


	// Purpose: This function will check all the "0" and "1" as mentioned earlier and output a string number to represent to error.
	// else will return the date
	// This will be interpreted by the worker.cpp via the manager
	// Application: Example: wrong day will be "1", wrong year "3" etc
	// Pre-req: takes in the main date and takes in 3 more strings of "0" or "1" which represents 
	// if date/month/year is successful or fail
	// Post-req: returns the date string if its correct or an string number if wrong
	string guardConvertParserDate(string verifyDate, string verifyMonth, string verifyYear, string date);



	// Purpose: This function will check all the "0" and "1" as mentioned earlier and output a string number to represent to error.
	// else will return the time
	// This will be interpreted by the worker.cpp via the manager
	// Application: Example: wrong time will be "0" and correct time will be "1"
	// Pre-req: takes in the main time and takes in 1 more string of "0" or "1" which represents 
	// if time is successful or fail
	// Post-req: returns the time string if its correct or an string number if wrong
	string guardConvertParserTime(string verifyTime, string time);




	// ***** Main functions of Parser *****

	// Purpose: Foundation of the Parser-> splits up user input into a vector of strings for easier manipulation of parsing
	// Pre-req: Takes in the string of input from the user
	// Post-req: stores the string of inputs into a vector of stings and outputs
	vector<string> storeInformation(string userInput);

	// Purpose: this function is to store the commands and pass it back to manager which will pass to worker
	// Pre-req: takes in a vector of stirng of the broken down storeUserInfo
	// Post-req: outputs a vector string that consists of the command as the first element. Subsequent details will be added later
	vector<string> parseCommand(vector<string> storeUserInfo);

	// Purpose: parseDetails will interpret the command of the userInput and execure various functions depending on the command
	// Does the main work of the whole parser-> parsing of all the other details. 
	// Also inclusive of checking and guarding against some wrong user inputs
	// Pre-req: takes in a vector of the broken userInput
	// Post-req: outputs 1 when parse is executed
	bool parseDetails(vector<string> storeUserInfo);


	// Purpose: Most important function for manager to call parser. Provides the completed parsed format to worker via manager
	// Also is the main parser function which calls the other 3 parser function
	// Pre-req: takes in a string of the userinput
	// Post-req: outputs out a vector of strings of userInput in the proper format (especially for dates and time)
	vector<string> completeParse(string userInput); 

	
	// Purpose: resets the parser to take in new commands
	// Pre-req: none
	// Post-req: nil
	void parserEmpty();

};
