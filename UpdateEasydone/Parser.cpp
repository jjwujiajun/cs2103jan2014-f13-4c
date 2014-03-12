#include "Parser.h"

//These are messages that will be used by the programme
const string Parser::MESSAGE_ADD =  "add";
const string Parser::MESSAGE_NEW = "new";
const string Parser::MESSAGE_READ = "display";
const string Parser::MESSAGE_UPDATE = "update";
const string Parser::MESSAGE_DELETE = "delete";
const string Parser::MESSAGE_SEARCH = "search";
const string Parser::MESSAGE_CHECK = "check";
const string Parser::MESSAGE_INVALID  = "Wrong command! Please enter command again ";
const string Parser::MESSAGE_SUCCESSFUL = "Details successfully Parsed";
const string Parser::MESSAGE_ERROR = "Details NOT Parsed ERROR!!!";



Parser::Parser (void) {
}

Parser::~Parser() {
}


Parser::Choice Parser::userCommand (string input) {
    if (input.substr (0,2) == MESSAGE_ADD) {
        return ADD;
    }
    else if (input.substr (0,7) == MESSAGE_READ) {
        return READ;
    }
    else if (input.substr (0,6) == MESSAGE_UPDATE) {
        return UPDATE;
    }
    else if (input.substr (0,6) == MESSAGE_DELETE) {
        return DELETE;
    }
    else if (input.substr (0,6) == MESSAGE_SEARCH) {
        return SEARCH;
    }
    else if (input.substr (0,5) == MESSAGE_CHECK) {
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
            command[0] = MESSAGE_ADD;
            break;
        case READ:
            command[1] = MESSAGE_READ;
            break;
        case UPDATE:
            command[2] = MESSAGE_UPDATE;
            break;
        case DELETE:
            command[3] = MESSAGE_DELETE;
            break;
        case SEARCH:
            command[4] = MESSAGE_SEARCH;
            break;
        case CHECK:
            command[5] = MESSAGE_CHECK;
            break;
        case ERROR:
            cout << MESSAGE_INVALID << endl;
            break;
    }
    return command;
}


bool Parser::parseDetails (string userInput) {
    /*
    //Breaks the entire user input string into words and stores it into the vector concatedUserInformation
    istringstream iss(userInput);
    copy(istream_iterator<string>(iss), istream_iterator<string>(),  back_inserter<vector<string> >(userInformation));
    */
    Choice enumCommand;
    enumCommand = userCommand (userInput);
    int counter = 1;
    int index;
    vector<string>::iterator iter = userInformation.begin();
    unsigned int tStart = 0, tEnd = 0;
    string newUserInput;
    string token;
    string keyWord_1 ("on");
    string keyWord_2 ("from");
    string keyWord_3 ("to");
	// find_first_of -> will treat the string as a set of characters served as delimters
	// it will also find the first occurrence of a member of string within the string to which it is applied

	//srting.find will find the whole set of characters and not only one character. This differs from find first of which finds the character only
   
    switch (enumCommand) {

        case ADD:
			//  arun birthday on 2014/07/03 1330 (floating task)
			//  project meeting from 2014/07/05 1330 to 2014/07/05 1530 (timed task)

			
            newUserInput = userInput.substr (4, userInput.size());
            while (tEnd != string::npos) {
				if (newUserInput.find (keyWord_1)) {
				tEnd = userInput.find (keyWord_1); // pos not provided. Default value of 0 is used
                // start from pos 0 to the difference between start and end. this means after each iterration, the gap decreases
				token = newUserInput.substr (tStart, tEnd - tStart);  
                userInformation.push_back (token);
                cout << "push " << token << endl;
                tStart = tEnd + 1;
				}// start of a new word
               // tEnd = newUserInput.find_first_of (" ", tStart); // looks from tStart position
            
				if (newUserInput.find (keyWord_2)) {
					tEnd = userInput.find (keyWord_2);
					token = newUserInput.substr (tStart, tEnd - tStart);  
				    userInformation.push_back (token);
					tStart = tEnd + 1;

					if(newUserInput.find (keyWord_3)) {
						newUserInput.find (keyWord_3);
						tEnd = userInput.find (keyWord_3);
						token = newUserInput.substr (tStart, tEnd - tStart);  
						userInformation.push_back (token);
					}
				}
            }
            // print last token
            if (tStart < newUserInput.size()) {
                userInformation.push_back (newUserInput.substr (tStart));
                cout << "push " << token << endl;
            }
            for (iter = userInformation.begin()+1; iter != userInformation.end(); ++iter) {
                cout << endl << counter << ". " << *iter;
                counter++;
            }

            break;

        case READ:
            newUserInput =userInput.substr (7, userInput.size());
            // no details to be parsed since is just displaying
            break;

        case UPDATE:
			tEnd = userInput.find_first_of (" <>");
            newUserInput = userInput.substr (7, userInput.size());
		    while (tEnd != string::npos) {
			    token = newUserInput.substr (tStart, tEnd - tStart);
                userInformation.push_back (token);
                cout << "push " << token << endl;
                tStart = tEnd + 1;
                tEnd = newUserInput.find_first_of (" <>", tStart); // looks from tStart position
				//example update index<field>things to be updated
				
			}

                if (tStart < newUserInput.size()) {
                    userInformation.push_back (newUserInput.substr (tStart));
                    cout << "push " << token << endl;
                }
           
            break;

        case DELETE:
            newUserInput = userInput.substr (7, userInput.size());
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
   

            break;

        case SEARCH:
            newUserInput = userInput.substr (7, userInput.size());
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

            break;

        case CHECK:
            newUserInput = userInput.substr (6, userInput.size());
            break;
    }

	// check if vector is filled with information
	if (userInformation.size != 0)
			{
				MESSAGE_SUCCESSFUL;
			} else { 
				MESSAGE_ERROR;
			}
  
}

/*
string token, mystring("scott>=tiger");
while(token != mystring){
  token = mystring.substr(0,mystring.find_first_of(">="));
  mystring = mystring.substr(mystring.find_first_of(">=") + 1);
  printf("%s ",token.c_str());
}
*/


vector<string> Parser::completeParse (string userInput) {
	
	// juhi helppppppppppppppppppppp
	// what to input here?? thanks!
    command = parseCommand(userInput); //returns details of task inputted by user in the form of a vector<string>
    return command;
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
