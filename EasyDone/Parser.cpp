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
	string taskInfo;
	string taskInfo_2;
	string taskInfo_3;
	string afterOnInput;
	string afterFromInput;
	string afterToInput;
	size_t found_1;
	size_t found_2;
	size_t found_3;
	
    string keyWord_1 ("on");
    string keyWord_2 ("from");
    string keyWord_3 ("to");
	string keyWord_4 ("at");
	// find_first_of -> will treat the string as a set of characters served as delimters
	// it will also find the first occurrence of a member of string within the string to which it is applied
	
	//string.find will find the whole set of characters and not only one character. This differs from find first of which finds the character only
   
    switch (enumCommand) {

        case ADD:
			//  arun birthday on 20140703 1330 (floating task)
			//  project meeting from 20140705 1330 to 20140705 1530 (timed task)
			
			stringSize = storeUserInfo[0];
			x = stringSize.size() + 1;
			// substr is (pos, lenth of word)
            newUserInput = userInput.substr(x, userInput.size()); // takes away command
		
			found_1 = newUserInput.find(keyWord_1);
			found_2 = newUserInput.find(keyWord_2);
			found_3 = newUserInput.find(keyWord_3);
		

			if(found_1 != string::npos) {
			taskInfo = newUserInput.substr(0, found_1-1); // stores everything before "on" excludes the spacing
			userInformation.push_back(taskInfo);
			
			afterOnInput = newUserInput.substr(found_1+3, userInput.size());

			tEnd = afterOnInput.find_first_of(" ");
            while (tEnd != string::npos) {
				
				//tEnd = userInput.find (keyWord_1); // pos not provided. Default value of 0 is used 
				//cout<< "1)tend is " << tEnd << endl;
				token = afterOnInput.substr(tStart, tEnd-tStart); 
				//cout << "1)token is " << token << endl;
				userInformation.push_back(token);
                tStart= tEnd + 1;  // start from pos 0 to the difference between start and end. this means after each iterration, the gap decreases
				tEnd = afterOnInput.find_first_of (" ", tStart); // looks from tStart position
				}
			
			 if (tStart <  afterOnInput.size()) {
				 token =  afterOnInput.substr (tStart); // print the last token
				// cout << "1)last token is " << token << endl;
                 userInformation.push_back (token);
            }

			 
		}

			else if(found_2 != string::npos) {
			
			taskInfo_2 = newUserInput.substr(0, found_2-1); // stores everything before "from" excludes the spacing
			userInformation.push_back(taskInfo_2);

			afterFromInput = newUserInput.substr(found_2+5, userInput.size());
			afterToInput = newUserInput.substr(found_3+3, userInput.size());
			tEnd = afterFromInput.find_first_of(" ");
            while (tEnd != string::npos) {

				//tEnd = userInput.find (keyWord_1); // pos not provided. Default value of 0 is used 
				//cout<< "2)tend is " << tEnd << endl;
				token = afterFromInput.substr(tStart, tEnd-tStart); 
				//cout << "token is " << token << endl;
				userInformation.push_back(token);
				//cout<< "2)token is " << token<< endl;
                tStart= tEnd + 1;  // start from pos 0 to the difference between start and end. this means after each iterration, the gap decreases
				tEnd = afterFromInput.find_first_of (" ", tStart); // looks from tStart position
				

				if(found_3 != string::npos) {
					
					taskInfo_3 = newUserInput.substr(found_3-5, 4);
					
					userInformation.push_back(taskInfo_3);

					tStart=0, tEnd = 0;
					tEnd = afterToInput.find_first_of(" ");
					
					token = afterToInput.substr(tStart, tEnd-tStart); 
					//cout << "token is " << token << endl;
					userInformation.push_back(token);
				//	cout<< "3)token is " << token<< endl;
					tStart= tEnd + 1;  // start from pos 0 to the difference between start and end. this means after each iterration, the gap decreases
					tEnd = afterToInput.find_first_of (" ", tStart); // looks from tStart position				

					
					 if (tStart < afterToInput.size()) {
					 token =  afterToInput.substr(tStart); // print the last token
					 userInformation.push_back (token);
			 
					 }
					 
					return 1;
					
			}
								
		}
			 
			 if (tStart < afterFromInput.size()) {
				 token =  afterFromInput.substr (tStart); // print the last token
                 userInformation.push_back (token);
            }
			 
		}
		
	
			 
			// for (int i =0; i < 2; ++i)
			// {
				// assert(userInformation[i] != "");
			// }

            break;

        case READ:
			 stringSize = storeUserInfo[0];
			 x = stringSize.size() + 1;
			
             newUserInput = userInput.substr (x, userInput.size());
			 token = "0";
			 userInformation.push_back(token);	
            // no details to be parsed since is just displaying
/*
			 if (userInformation.size() != 0)
			{
				 cout << "Command successfully Parsed" << endl;
				 
			} else { 
				 cout << "Command NOT Parsed ERROR!!!" << endl;
			}
          */
            break;

        case UPDATE:
			
			stringSize = storeUserInfo[0];
			x = stringSize.size() + 1;
			
            newUserInput = userInput.substr (x, userInput.size());
		    tEnd = newUserInput.find_first_of(" ");
            while (tEnd != string::npos) {
				//if (newUserInput.find (keyWord_1)) {
				//tEnd = userInput.find (keyWord_1); // pos not provided. Default value of 0 is used 
				token = newUserInput.substr (tStart, tEnd - tStart);  
				userInformation.push_back(token);
                tStart = tEnd + 1;  // start from pos 0 to the difference between start and end. this means after each iterration, the gap decreases
				tEnd = newUserInput.find_first_of (" ", tStart); // looks from tStart position
				}
			
			 if (tStart < newUserInput.size()) {
				 token = newUserInput.substr (tStart); // print the last token
                 userInformation.push_back (token);
            }
/*
			 if (userInformation.size() != 0)
			{
				 cout << "Details successfully Parsed" << endl;
				 
			} else { 
				 cout << "Details NOT Parsed ERROR!!!" << endl;
			}
			*/


            break;

        case DELETE:

			stringSize = storeUserInfo[0];
			x = stringSize.size() + 1;
			
            newUserInput = userInput.substr (x, userInput.size());
			//userInput.erase(0, 7);
			
			tEnd = newUserInput.find_first_of(" ");
            while (tEnd != string::npos) {
				//if (newUserInput.find (keyWord_1)) {
				//tEnd = userInput.find (keyWord_1); // pos not provided. Default value of 0 is used 
				token = newUserInput.substr (tStart, tEnd - tStart);  
				userInformation.push_back(token);
                tStart = tEnd + 1;  // start from pos 0 to the difference between start and end. this means after each iterration, the gap decreases
				tEnd = newUserInput.find_first_of (" ", tStart); // looks from tStart position
				}
			
			 if (tStart < newUserInput.size()) {
				 token = newUserInput.substr (tStart); // print the last token
                 userInformation.push_back (token);
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
    }



	return 1;
}




vector<string> Parser::completeParse(string userInput) {
	
	parserEmpty();
	
	log.log("Parser: parseCommand(userInput)");
	
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


/*
#include "stdafx.h"
#include "parser.h"

parser::parser(void) {
}


parser::~parser(void) {
}

void parser::receiveUserInput() {
string input;

cin >> input;
//conversion method
parseCommand(input);

getchar();

cin >> input;
//conversion method
if (input[0] == '\"') {
//parseDueDate(input);
} else if (input[0] == '\\') {
parseDueTime(input);
} else if (input[0] == '/') {
parseDueDate(input);
}
}


void parser::parseInput(string input) {
int index = 0;
int &i = index;
int inputLength = input.length();

parseCommandz(input, i);
/*
while (i != inputlength) {
if (input[i] == '\"') {
parseTodoDescription(input, i)
}
if (input[i] == '/') {
parseDueDate(input, i);
}
}

}

void parser::parseCommandz(string input, int &i) {
char inputCommand[250];
while (input[i] != ' ') {
inputCommand[i] = input[i];
++i;
}

string stringCommand = (string)inputCommand;
if (stringCommand == "a" || stringCommand == "add" || stringCommand == "Add") {
command = ADD;
}
if (stringCommand == "d" || stringCommand == "del" || stringCommand == "delete" || stringCommand == "Delete") {
command = DELETE;
}

++i;
}
*/
