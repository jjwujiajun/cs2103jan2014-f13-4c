#include "Headers.h"
#include "Parser.h"


//These are messages that will be used by the programme




Parser::Parser (void) {
}

Parser::~Parser() {
}

vector<string> Parser::storeInformation(string userInput) {

	 unsigned int tStart = 0, tEnd = 0;
	 string newUserInput;
     string token;
	 tEnd = newUserInput.find_first_of(" ");

        while (tEnd != string::npos) {
			//if (newUserInput.find (keyWord_1)) {
			//tEnd = userInput.find (keyWord_1); // pos not provided. Default value of 0 is used 
			token = newUserInput.substr (tStart, tEnd - tStart);  
			storeUserInfo.push_back(token);
            tStart = tEnd + 1;  // start from pos 0 to the difference between start and end. this means after each iterration, the gap decreases
			tEnd = newUserInput.find_first_of (" ", tStart); // looks from tStart position
			}
			
			if (tStart < newUserInput.size()) {
				token = newUserInput.substr (tStart); // print the last token
                storeUserInfo.push_back (token);
        }

			return storeUserInfo;
}

Parser::Choice Parser::userCommand (string input) {
	if (input.substr(0,3) == MESSAGE_ADD) {
		log.log("Parser: Command is ADD");
		return ADD;
    }
    else if (input.substr (0,7) == "display") {
		log.log("Parser: Command is READ");
        return READ;
    }
    else if (input.substr (0,6) == "update") {
		log.log("Parser: Command is UPDATE");
        return UPDATE;
    }
    else if (input.substr (0,6) == MESSAGE_DELETE) {
		log.log("Parser: Command is DELETE");
        return DELETE;
    }
    else if (input.substr (0,6) == MESSAGE_SEARCH) {
		log.log("Parser: Command is SEARCH");
        return SEARCH;
    }
    else if (input.substr (0,5) == MESSAGE_CHECK) {
		log.log("Parser: Command is CHECK");
        return CHECK;
    }
    else {
        return ERROR;
    }
}


// parseCommand to process usercommand and sieve out first word which is the command. Eg. add, delete etc
// it will return a vector string storing all the commands

vector<string> Parser::parseCommand (string userInput) {
    Choice enumCommand;
    enumCommand = userCommand (userInput);
    /*
    	for (int i =0; i < userInput.length(); ++i)
      {
        userInput.at(i);
      }
    */
    switch (enumCommand) {
        case ADD:
			userInformation.push_back(MESSAGE_ADD);
            break;
        case READ:
			userInformation.push_back("display");
            break;
        case UPDATE:
            userInformation.push_back("update");
            break;
        case DELETE:
			userInformation.push_back(MESSAGE_DELETE);
            break;
        case SEARCH:
            userInformation.push_back("search");;
            break;
        case CHECK:
            userInformation[0] = MESSAGE_CHECK;
            break;
        case ERROR:
            cout << MESSAGE_INVALID << endl;
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
    enumCommand = userCommand (userInput);
    //int index;
    
    unsigned int tStart = 0, tEnd = 0;
	string newUserInput;
    string token;
    string keyWord_1 ("on");
    string keyWord_2 ("from");
    string keyWord_3 ("at");
	string keyWord_4 ("to");
	// find_first_of -> will treat the string as a set of characters served as delimters
	// it will also find the first occurrence of a member of string within the string to which it is applied
	
	//string.find will find the whole set of characters and not only one character. This differs from find first of which finds the character only
   
    switch (enumCommand) {

        case ADD:
			//  arun birthday on 20140703 1330 (floating task)
			//  project meeting from 20140705 at 1330 to 20140705 at 1530 (timed task)
			
            newUserInput = userInput.substr (4, userInput.size());
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


			 for (int i =0; i < 2; ++i)
			 {
				 assert(userInformation[i] != "");
			 }
/*
			 if (userInformation.size() != 0)
			{
				 cout << "Details successfully Parsed" << endl;
				 
			} else { 
				 cout << "Details NOT Parsed ERROR!!!" << endl;
			}
	*/		   
		
            /*
			
				
				if (newUserInput.find (keyWord_2)) {
					tEnd = userInput.find (keyWord_2);
					token = newUserInput.substr (tStart, tEnd - tStart);  
				    userInformation[2] = token;
					tStart = tEnd + 1;
				}

					}

					if(newUserInput.find (keyWord_3)) {
						newUserInput.find (keyWord_3);
						tEnd = userInput.find (keyWord_3);
						token = newUserInput.substr (tStart, tEnd - tStart);  
						userInformation[3] = token;
					}
            // print last token
            if (tStart < newUserInput.size()) {
                userInformation.push_back (newUserInput.substr (tStart));
                cout << "push " << token << endl;
            }
			
			
			*/
            break;

        case READ:
			
			 newUserInput =userInput.substr (7, userInput.size());
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
			
            newUserInput = userInput.substr (7, userInput.size());
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

			newUserInput = userInput.substr (6, userInput.size());
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
            newUserInput = userInput.substr (7, userInput.size());
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
            newUserInput = userInput.substr (6, userInput.size());
            break;
    }



	return 1;
}

/*
string token, mystring("scott>=tiger");
while(token != mystring){
  token = mystring.substr(0,mystring.find_first_of(">="));
  mystring = mystring.substr(mystring.find_first_of(">=") + 1);
  printf("%s ",token.c_str());
}
*/


vector<string> Parser::completeParse(string userInput) {
	parserEmpty();

	log.log("Parser: parseCommand(userInput)");
	parseCommand(userInput);
	parseDetails(userInput);
	//cout<<"hello"<<userInformation[0]<<userInformation[1]<<endl;
    for(int i=0; i<9; i++) {
			userInformation.push_back("0"); // initialise rest of vector
	}
			
	
	return userInformation; //returns details of task inputted by user in the form of a vector<string>
}

void Parser::parserEmpty() {
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
