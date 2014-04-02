#include "Headers.h"
#include "Parser.h"

//using namespace std;

//These are messages that will be used by the programme




Parser::Parser (void) {
}

Parser::~Parser() {
}
// breaks up the userUnput via spaces and stores them into a vector string
vector<string> Parser::storeInformation(string userInput) {

// find_first_of -> will treat the string as a set of characters served as delimters
// it will also find the first occurrence of a member of string within the string to which it is applied
	
	 
	 unsigned int tStart = 0, tEnd = 0;
	 string token;
	 tEnd = userInput.find_first_of(" ");

        while (tEnd != string::npos) {
			//if (newUserInput.find (keyWord_1)) {
			//tEnd = userInput.find (keyWord_1); // pos not provided. Default value of 0 is used 
			token = userInput.substr (tStart, tEnd - tStart);
			storeUserInfo.push_back(token);
			
            tStart = tEnd + 1;  // start from pos 0 to the difference between start and end. this means after each iterration, the gap decreases
			tEnd = userInput.find_first_of (" ", tStart); // looks from tStart position
			}
			
			if (tStart < userInput.size()) {
				token = userInput.substr (tStart); // print the last token
                storeUserInfo.push_back (token);
				
			}
        
			
			return storeUserInfo;
}




Parser::Choice Parser::userCommand (vector<string>storeUserInfo) {

	if (storeUserInfo[0] == MESSAGE_ADD || storeUserInfo[0] == MESSAGE_CREATE || storeUserInfo[0] == MESSAGE_NEW  ) {
		log.log("Parser: Command is ADD");
		return ADD;
    }
    else if (storeUserInfo[0] == "display") {
		log.log("Parser: Command is READ");
        return READ;
    }
    else if (storeUserInfo[0] == "update" || storeUserInfo[0] == "change" || storeUserInfo[0] == "edit") {
		log.log("Parser: Command is UPDATE");
        return UPDATE;
    }
    else if (storeUserInfo[0] == "delete" || storeUserInfo[0] == "remove") {
		log.log("Parser: Command is DELETE");
        return DELETE;
    }
    else if (storeUserInfo[0] == "search") {
		log.log("Parser: Command is SEARCH");
        return SEARCH;
    }
    else if (storeUserInfo[0] == MESSAGE_CHECK) {
		log.log("Parser: Command is CHECK");
        return CHECK;
    }
	else if (storeUserInfo[0] == "undo") {
		log.log("Parser: Command is UNDO");
        return UNDO;
	}
    else { 
		storeOther.push_back("add");
        return OTHER;
    }
}


// parseCommand to process usercommand and sieve out first word which is the command. Eg. add, delete etc
// it will return a vector string storing all the commands

vector<string> Parser::parseCommand (vector<string> storeUserInfo) {
	
    Choice enumCommand;
    enumCommand = userCommand(storeUserInfo);
	
    switch (enumCommand) {
        case ADD:
			userInformation.push_back(storeUserInfo[0]);
            break;
        case READ:
			userInformation.push_back(storeUserInfo[0]);
            break;
        case UPDATE:
            userInformation.push_back(storeUserInfo[0]);
            break;
        case DELETE:
			userInformation.push_back(storeUserInfo[0]);
            break;
        case SEARCH:
            userInformation.push_back(storeUserInfo[0]);
            break;
        case CHECK:
            userInformation.push_back(storeUserInfo[0]);
            break;
		case UNDO:
			userInformation.push_back(storeUserInfo[0]);
			break;
        case OTHER:
            userInformation.push_back(storeOther[0]);
            break;
    }
    return userInformation;
}



bool Parser::parseDetails (vector<string> storeUserInfo) {
	
    /*
    //Breaks the entire user input string into words and stores it into the vector concatedUserInformation
    istringstream iss(userInput);
    copy(istream_iterator<string>(iss), istream_iterator<string>(),  back_inserter<vector<string> >(userInformation));
    */

    Choice enumCommand;
    enumCommand = userCommand(storeUserInfo);

	string checkDate;
	string checkDate2;
	string checkTime;


	int i = 1; // note i start from 1 because command already pushed in. change to 0 if above pushing is removed in future.
	
	string taskName;
	string startDate;
	string startTime;
	string endDate;
	string endTime;
	
    const string keyWord_1 ("on");
    const string keyWord_2 ("by");
    const string keyWord_3 ("from");
	const string keyWord_4 ("to");

	const string task ("task");
	const string sd ("sd");
	const string st ("st");
	const string ed ("ed");
	const string et ("et");
	

   
    switch (enumCommand) {
		
        case ADD:

		while (i < (int) storeUserInfo.size()) {
			
				// keyword is "on"
				// Purpose is for showcasing tasks to be done on that day
				if (storeUserInfo[i] == keyWord_1) {  
					++i;
					if (i < (int) storeUserInfo.size() && 
							 storeUserInfo[i] != keyWord_2 &&
							 storeUserInfo[i] != keyWord_3 &&
							 storeUserInfo[i] != keyWord_4) {
					
					startDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"
					++i;			
				}

					if(i < (int) storeUserInfo.size()) 
						startTime += storeUserInfo[i];
					++i;
				}	

				// keyword is "by"
				// Purpose is for deadline tasks to be done by that day & time or day/time
				else if(storeUserInfo[i] == keyWord_2)
				{
					++i;
					
					if (i < (int) storeUserInfo.size() && 
							 storeUserInfo[i] != keyWord_1 &&
							 storeUserInfo[i] != keyWord_3 &&
							 storeUserInfo[i] != keyWord_4) {
					
					endDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"
					++i;
					}
					if(i < (int) storeUserInfo.size()) 
						endTime += storeUserInfo[i];
					++i;



				}
				
				// keyword is "from"
				// Works in tandem with keyword "to"
				// Purpose is for timed tasks from a {date} {time} to {date} {time} 
				// from {date} {time} to {date} 
				// from {time} to {time}
				  else if (storeUserInfo[i] == keyWord_3) { // start date "from"
					++i;
					if (i < (int) storeUserInfo.size() && 
							 storeUserInfo[i] != keyWord_1 &&
							 storeUserInfo[i] != keyWord_2 &&
							 storeUserInfo[i] != keyWord_4) {

					checkDate += storeUserInfo[i];
					if (checkDate.size() > 5) {

						startDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"
						++i;
						if(storeUserInfo[i] == keyWord_4) {
						++i;
				
						endDate += storeUserInfo[i];
						++i;
						if (i < (int) storeUserInfo.size()){
						endTime += storeUserInfo[i];
						++i;
						}
									
						} else {
							
						startTime += storeUserInfo[i];
						++i;
						}

					} else {
						startTime += storeUserInfo[i];
						i++;
					}

					//startDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"
					//++i;
					}
				 }

				
				// keyword is "to"
				// Works in tandem with keyword "from"
				// Purpose is for timed tasks from a {date} {time} to {date} {time} 
				// from {date} {time} to {date} 
				// from {time} to {time}				 
				else if (storeUserInfo[i] == keyWord_4) { // end date "to"
						++i;
						if (i < (int) storeUserInfo.size() && 
							 storeUserInfo[i] != keyWord_1 &&
							 storeUserInfo[i] != keyWord_2 &&
							 storeUserInfo[i] != keyWord_3 ) {

					checkDate2 += storeUserInfo[i];
					if ((int) checkDate2.size() > 5) {
					endDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing
					++i;
					//if (i < (int) storeUserInfo.size()) {
					endTime += storeUserInfo[i];
					++i;
					//}
				  } else {
						endTime += storeUserInfo[i];
						i++;
					}
						
				}

				} else {
					taskName += storeUserInfo[i] + " ";
					++i;
					}
					
		}
				
			userInformation.push_back(taskName);
			userInformation.push_back(startDate);
			userInformation.push_back(startTime);
			userInformation.push_back(endDate);
			userInformation.push_back(endTime);
		
            break;
			
        case READ:

			// only detail to parse is the Index on the GUI
			userInformation.push_back(storeUserInfo[1]);
            
            break;

        case UPDATE:
			// update {index} {field to be updated} {what to be updated}
			// {field to be updated} includes 5 keywords. They are as follows
			// 1) task -> taskName
			// 2) sd -> startDate
			// 3) st -> startTime
			// 4) ed -> endDate
			// 5) et -> endTime
			while (i < (int) storeUserInfo.size()) {
				if(storeUserInfo[i] == sd || storeUserInfo[i] == st || storeUserInfo[i] == ed || storeUserInfo[i] == et ) {		
					startDate += storeUserInfo[i];
					++i;
					while(i < (int) storeUserInfo.size()){

						startTime += storeUserInfo[i];
					++i;
				}
					
				} else if (storeUserInfo[i] == task) {
					startDate += storeUserInfo[i];
					++i;
					while(i<storeUserInfo.size()){
						startTime += storeUserInfo[i] + " ";
					++i;
				}	

			} else {
					taskName += storeUserInfo[i] ; // remember to add " " spacing next time for parsing stuff like "21 Dec"
					++i;
					}

					 
	}
			userInformation.push_back(taskName);
			userInformation.push_back(startDate);
			userInformation.push_back(startTime);
			userInformation.push_back(endDate);
			userInformation.push_back(endTime);

            break;

        case DELETE:
			// only detail to parse is the Index on the GUI

			if(i < (int) storeUserInfo.size()) {
			userInformation.push_back(storeUserInfo[1]);
			}
		
            break;

        case SEARCH:
            
			if(i < (int) storeUserInfo.size()) {
			userInformation.push_back(storeUserInfo[1]);
			}
			//stringSize = storeUserInfo[0];
			//x = stringSize.size() + 1;
			
          //  newUserInput = userInput.substr (x, userInput.size());
			/*
            while (tEnd != string::npos) {
                token = newUserInput.substr (tStart, tEnd - tStart);
                userInformation.push_back (token);
                cout << "push " << token << endl;
                tStart = tEnd + 1;
                tEnd = newUserInput.find_first_of (" ", tStart); // looks from tStart position
			}

                if (tStart < newUserInput.size()) {
                    userInformation.push_back (newUserInput.substr (tStart));
                    cout << "push " << token << endl;
                }
				*/
            break;

        case CHECK:
            
			if(i < (int) storeUserInfo.size()) {
			userInformation.push_back(storeUserInfo[1]);
			}

            break;

		case UNDO:

			// User types: undo
			// Purpose to revert back to the previous change
			userInformation.push_back(taskName);
			userInformation.push_back(startDate);
			userInformation.push_back(startTime);
			userInformation.push_back(endDate);
			userInformation.push_back(endTime);
            break;

		case OTHER:
					int i = 0;
					while (i < (int) storeUserInfo.size()) {
			
				// keyword is "on"
				// Purpose is for showcasing tasks to be done on that day
				if (storeUserInfo[i] == keyWord_1) {  
					++i;
					if (i < (int) storeUserInfo.size() && 
							 storeUserInfo[i] != keyWord_2 &&
							 storeUserInfo[i] != keyWord_3 &&
							 storeUserInfo[i] != keyWord_4) {
					
					startDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"
					++i;
					}
					if(i < (int) storeUserInfo.size()) 
						startTime += storeUserInfo[i];
					++i;
				}	

				// keyword is "by"
				// Purpose is for deadline tasks to be done by that day & time or day/time
				else if(storeUserInfo[i] == keyWord_2)
				{
					++i;
					
					if (i < (int) storeUserInfo.size() && 
							 storeUserInfo[i] != keyWord_2 &&
							 storeUserInfo[i] != keyWord_3 &&
							 storeUserInfo[i] != keyWord_4) {
					
					endDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"
					++i;
					}
					if(i < (int) storeUserInfo.size()) 
						endTime += storeUserInfo[i];
					++i;



				}
				
				// keyword is "from"
				// Works in tandem with keyword "to"
				// Purpose is for timed tasks from a {date} {time} to {date} {time} 
				// from {date} {time} to {date} 
				// from {time} to {time}
				 else if (storeUserInfo[i] == keyWord_3) { // start date "from"
					++i;
					if (i < (int) storeUserInfo.size() && 
							 storeUserInfo[i] != keyWord_2 &&
							 storeUserInfo[i] != keyWord_3 &&
							 storeUserInfo[i] != keyWord_4) {

					checkDate += storeUserInfo[i];
					if (checkDate.size() > 5) {

						startDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"
						++i;
						if(storeUserInfo[i] == keyWord_3) {
						++i;
						endDate += storeUserInfo[i];
						++i;
						} else {
						startTime += storeUserInfo[i];
						++i;
						}

					} else {
						startTime += storeUserInfo[i];
						i++;
					}

					//startDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"
					//++i;
					}
				 }

				// keyword is "to"
				// Works in tandem with keyword "from"
				// Purpose is for timed tasks from a {date} {time} to {date} {time} 
				// from {date} {time} to {date} 
				// from {time} to {time}				 
				else if (storeUserInfo[i] == keyWord_4) { // end date "to"
						++i;
						if (i < storeUserInfo.size() && 
							 storeUserInfo[i] != keyWord_1 &&
							 storeUserInfo[i] != keyWord_2 &&
							 storeUserInfo[i] != keyWord_4 ) {

					checkDate2 += storeUserInfo[i];
					if (checkDate.size() > 5) {
					endDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing
					++i;
					endTime += storeUserInfo[i];
					++i;
					} else {
						endTime += storeUserInfo[i];
						i++;
					}
						
				}

				} else {
					taskName += storeUserInfo[i] + " ";
					++i;
					}
					
		}
				
			userInformation.push_back(taskName);
			userInformation.push_back(startDate);
			userInformation.push_back(startTime);
			userInformation.push_back(endDate);
			userInformation.push_back(endTime);
		
            break;
    }

	return 1;
}


// *** date input format is DD/MM/YY ***
string Parser::parseDate(string date)
{
    int start = 0;
    int keystroke = date.find("/", 0);
	
    start = atoi(date.substr(0, keystroke).c_str());
	cout << start << endl;

    //exception handling for the date input
    if (start < 1 || start > 31){		
		successful =  "wrong date inputed";
		cout << successful << endl;
				
    } else {
		successful =  "date inputed";		
		cout << successful << endl;;		
	}

	return successful;
     
}

string Parser::parseMonth(string date) {
	
	// 12/12/2014
    int start = 0;
    int keystroke = date.find("/", 0); // finds first /12/2014

    int startOfMonth = keystroke + 1; // 2
    int startOfKeystroke = date.find("/", startOfMonth); 
    start = atoi(date.substr(startOfMonth, startOfKeystroke).c_str()); // converts string to int
	cout << start << endl;

    //exception handling for the month input
    if (start < 1 || start > 12)
    {
       successful =  "wrong month inputed";
    } else {
	   successful =  "month inputed";
	}

	return successful;
}

string Parser:: parseYear(string date) {
	// 12/09/14
	int start = 0;

	int firstKeyStroke = date.find("/", 0);
	int startOfMonth = firstKeyStroke + 1;
	int secondKeyStroke = date.find("/",startOfMonth); 
	int startOfYear = secondKeyStroke + 1;

	start = atoi(date.substr(startOfYear).c_str()); // converts string to int
	cout << start << endl;

	//exception handling for the Year input
	if (start < 0 || start > 99)
    {
       successful =  "wrong Year inputed";
    } else {
	   successful =  "Year inputed";
	}

	return successful;

}
// *** Time input format is HH:MM ***
string Parser:: parseTime(string time) {

	int keyStroke = time.find(".", 0);
	int startOfMinute = keyStroke + 1;

	int hour = atoi(time.substr(0,keyStroke).c_str());
    int min = atoi(time.substr(startOfMinute).c_str());

	cout << hour << endl;
	cout << min << endl;
	
	if (hour < 0 || hour > 24 || min < 0 || min > 60) {
	   successful =  "wrong time inputed";
    } else {
	   successful =  "Time inputed";
	}

	return successful;

}

vector<string> Parser::completeParse(string userInput) {
	
	parserEmpty();
	
	log.log("Parser: parseCommand(userInput)");
	
	storeInformation(userInput);
	
	parseCommand(storeUserInfo);
	parseDetails(storeUserInfo);

   // for(int i=0; i<9; i++) {
//			userInformation.push_back("0"); // initialise rest of vector
//	}
	
			
	
	return userInformation; //returns details of task inputted by user in the form of a vector<string>
}

void Parser::parserEmpty() {
	storeUserInfo.clear();
	userInformation.clear();
	
}

