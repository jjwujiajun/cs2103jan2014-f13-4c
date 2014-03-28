#include "Headers.h"
#include "Parser.h"



//These are messages that will be used by the programme
const string MESSAGE_ADD = "add";
const string MESSAGE_NEW = "new";
const string MESSAGE_READ = "display";
const string MESSAGE_UPDATE = "update";
const string MESSAGE_DELETE = "delete";
const string MESSAGE_SEARCH = "search";
const string MESSAGE_CHECK = "check";
const string MESSAGE_INVALID  = "Wrong command! Please enter command again ";
const string MESSAGE_SUCCESSFUL = "Details successfully Parsed";
const string MESSAGE_ERROR = "Details NOT Parsed ERROR!!!";



Parser::Parser (void) {
}

Parser::~Parser() {
}
// breaks up the userUnput via spaces and stores them into a vector string
vector<string> Parser::storeInformation(string userInput) {
	 
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

	if (storeUserInfo[0] == "add" || storeUserInfo[0] == "create" || storeUserInfo[0] == "new"  ) {
		//log.log("Parser: Command is ADD");
		return ADD;
    }
    else if (storeUserInfo[0] == "display") {
		//log.log("Parser: Command is READ");
        return READ;
    }
    else if (storeUserInfo[0] == "update" || storeUserInfo[0] == "change" || storeUserInfo[0] == "edit") {
		//log.log("Parser: Command is UPDATE");
        return UPDATE;
    }
    else if (storeUserInfo[0] == "delete" || storeUserInfo[0] == "remove") {
		//log.log("Parser: Command is DELETE");
        return DELETE;
    }
    else if (storeUserInfo[0] == "search") {
		//log.log("Parser: Command is SEARCH");
        return SEARCH;
    }
    else if (storeUserInfo[0] == MESSAGE_CHECK) {
		//log.log("Parser: Command is CHECK");
        return CHECK;
    }
	else if (storeUserInfo[0] == "undo") {
		//log.log("Parser: Command is UNDO");
        return UNDO;
	}
    else {
        return ERROR;
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
        case ERROR:
            cout << MESSAGE_INVALID  << endl;
            break;
    }
    return userInformation;
}



bool Parser::parseDetails (string userInput) {
	
    /*
    //Breaks the entire user input string into words and stores it into the vector concatedUserInformation
    istringstream iss(userInput);
    copy(istream_iterator<string>(iss), istream_iterator<string>(),  back_inserter<vector<string> >(userInformation));
    */

	
    Choice enumCommand;
    enumCommand = userCommand(storeUserInfo);
    //int index;
	int x;
 
    unsigned int tStart=0, tEnd = 0;
	string newUserInput;
    string token;
	string stringSize;

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
    const string keyWord_2 ("from");
    const string keyWord_3 ("to");
	const string keyWord_4 ("start");
	const string keyWord_5 ("end");
	// find_first_of -> will treat the string as a set of characters served as delimters
	// it will also find the first occurrence of a member of string within the string to which it is applied
	
	//string.find will find the whole set of characters and not only one character. This differs from find first of which finds the character only
   
    switch (enumCommand) {
		
        case ADD:

			while (i < (int) storeUserInfo.size()) {
			
				
				if (storeUserInfo[i] == keyWord_1) {
					int a = find(storeUserInfo.begin(), storeUserInfo.end(), keyWord_2) - storeUserInfo.begin();
					//taskName += storeUserInfo[a-1] + " ";
					++i;
					if (i < (int) storeUserInfo.size() && 
							 storeUserInfo[i] != keyWord_2 &&
							 storeUserInfo[i] != keyWord_3) {
					
					startDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"
					++i;
					}
					if(i < (int) storeUserInfo.size()) 
						startTime += storeUserInfo[i];
					++i;
				}			
				 else if (storeUserInfo[i] == keyWord_2) { // start date "from"
					++i;
					if (i < (int) storeUserInfo.size() && 
							 storeUserInfo[i] != keyWord_2 &&
							 storeUserInfo[i] != keyWord_3 &&
							 storeUserInfo[i] != keyWord_4 &&
							 storeUserInfo[i] != keyWord_5) {

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
				 
				else if (storeUserInfo[i] == keyWord_3) { // end date "to"
						++i;
						if (i < storeUserInfo.size() && 
							 storeUserInfo[i] != keyWord_1 &&
							 storeUserInfo[i] != keyWord_2 &&
							 storeUserInfo[i] != keyWord_4 &&
							 storeUserInfo[i] != keyWord_5 ) {

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
				
			
				
			/*	else if (storeUserInfo[i] == keyWord_4) { // start time
					++i;
					while (i < storeUserInfo.size() && 
							 storeUserInfo[i] != keyWord_1 &&
							 storeUserInfo[i] != keyWord_2 &&
							 storeUserInfo[i] != keyWord_3 &&
							 storeUserInfo[i] != keyWord_5 ) {
					startTime += storeUserInfo[i]; // remember to add " " spacing next time for parsing
					++i;
					// then parse time;
					// then,
					// endTime = parsedStartTime + 100;  which means 1 hour right?
					}
								
					// then parse date		
				}
				else if (storeUserInfo[i] == keyWord_5) { // end time
					++i;
					while (i < storeUserInfo.size() && 
							 storeUserInfo[i] != keyWord_1 &&
							 storeUserInfo[i] != keyWord_2 &&
							 storeUserInfo[i] != keyWord_3 &&
							 storeUserInfo[i] != keyWord_4) {
					endTime = storeUserInfo[i]; // remember to add " " spacing next time for parsing
					++i;
					}
					*/
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
			/*
			 stringSize = storeUserInfo[0];
			 x = stringSize.size() + 1;
			
             newUserInput = userInput.substr (x, userInput.size());
			 token = "0";
			 userInformation.push_back(token);	
			 */
			userInformation.push_back(storeUserInfo[1]);
            // no details to be parsed since is just displaying

            break;

        case UPDATE:
			while (i < storeUserInfo.size()) {
					
				if(storeUserInfo[i] == "task" || storeUserInfo[i] == "sd" || storeUserInfo[i] == "st" || storeUserInfo[i] == "ed" || storeUserInfo[i] == "et" ) {
					
					startDate += storeUserInfo[i];
					++i;
					while(i<storeUserInfo.size()){
						startTime += storeUserInfo[i] + " ";
					++i;
				}		
					}else {
						taskName += storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"
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

			if(i<storeUserInfo.size()) {
			userInformation.push_back(storeUserInfo[1]);
			}
		
            break;

        case SEARCH:
            
			stringSize = storeUserInfo[0];
			x = stringSize.size() + 1;
			
            newUserInput = userInput.substr (x, userInput.size());
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
            
			stringSize = storeUserInfo[0];
			x = stringSize.size() + 1;
			
            newUserInput = userInput.substr (x, userInput.size());
            break;

		case UNDO:
			userInformation.push_back(taskName);
			userInformation.push_back(startDate);
			userInformation.push_back(startTime);
			userInformation.push_back(endDate);
			userInformation.push_back(endTime);
            break;

    }



	return 1;
}




vector<string> Parser::completeParse(string userInput) {
	
	parserEmpty();
	
	//log.log("Parser: parseCommand(userInput)");
	
	storeInformation(userInput);
	
	parseCommand(storeUserInfo);
	parseDetails(userInput);

    for(int i=0; i<9; i++) {
			userInformation.push_back("0"); // initialise rest of vector
	}
	
			
	
	return userInformation; //returns details of task inputted by user in the form of a vector<string>
}

void Parser::parserEmpty() {
	storeUserInfo.clear();
	userInformation.clear();
	
}

