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
	if (userInput.size() != 0) {

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

	} else {
		storeUserInfo.push_back ("");
	}

	return storeUserInfo;

}


Parser::Choice Parser::userCommand (vector<string>storeUserInfo) {

	if (storeUserInfo[0] == MESSAGE_ADD || storeUserInfo[0] == MESSAGE_CREATE || storeUserInfo[0] == MESSAGE_NEW  ) {
		log.log("Parser: Command is ADD");
		return ADD;
	}
	else if (storeUserInfo[0] == MESSAGE_DISPLAY) {
		log.log("Parser: Command is READ");
		return READ;
	}
	else if (storeUserInfo[0] == MESSAGE_UPDATE|| storeUserInfo[0] == MESSAGE_CHANGE || storeUserInfo[0] == MESSAGE_EDIT) {
		log.log("Parser: Command is UPDATE");
		return UPDATE;
	}
	else if (storeUserInfo[0] == MESSAGE_DELETE|| storeUserInfo[0] == MESSAGE_REMOVE) {
		log.log("Parser: Command is DELETE");
		return DELETE;
	}
	else if (storeUserInfo[0] == MESSAGE_SEARCH) {
		log.log("Parser: Command is SEARCH");
		return SEARCH;
	}
	else if (storeUserInfo[0] == MESSAGE_DONE) {
		log.log("Parser: Command is CHECK");
		return CHECK;
	}
	else if (storeUserInfo[0] == MESSAGE_UNDO) {
		log.log("Parser: Command is UNDO");
		return UNDO;
	}
	else { 
		storeOther.push_back(MESSAGE_ADD);
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

	// natural language
	string date;
	string month;
	string year;
	string final;


	// guard keyword variables
	string checkWord;
	string store;

	// guard variables
	string checkDate;
	string checkDate2;
	string checkTime;


	// pushing guard variables into vector
	string verifyDate;
	string verifyMonth;
	string verifyYear;
	string verifyTime;

	int i = 1; // note i start from 1 because command already pushed in. 

	// parsed variables
	string taskName;
	string startDate;
	string startTime;
	string endDate;
	string endTime;


	// Command "add" keywords
	const string keyWord_1 ("on");
	const string keyWord_2 ("by");
	const string keyWord_3 ("from");
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

	switch (enumCommand) {

	case ADD:

		while (i < (int) storeUserInfo.size()) {

			// keyword is "on"
			// Purpose is for showcasing tasks to be done on that day (startDate and/or startTime)
			if (storeUserInfo[i] == keyWord_1) {  
				++i;
				if (i < (int) storeUserInfo.size() && 
					storeUserInfo[i] != keyWord_2 &&
					storeUserInfo[i] != keyWord_3 &&
					storeUserInfo[i] != keyWord_4) {
					
					if ( i < (int) storeUserInfo.size() && (storeUserInfo[i] == "1" || storeUserInfo[i] == "2" || storeUserInfo[i] == "4" || storeUserInfo[i] == "5" || storeUserInfo[i] == "6" || storeUserInfo[i] == "7" || storeUserInfo[i] == "8" || storeUserInfo[i] == "9" || storeUserInfo[i] == "10" || storeUserInfo[i] == "11" || storeUserInfo[i] == "12" || storeUserInfo[i] == "13" || storeUserInfo[i] == "14") || storeUserInfo[i] == "15" || storeUserInfo[i] == "16" || storeUserInfo[i] == "17" || storeUserInfo[i] == "18" || storeUserInfo[i] == "19" || storeUserInfo[i] == "20" || storeUserInfo[i] == "21" || storeUserInfo[i] == "22" || storeUserInfo[i] == "23" || storeUserInfo[i] == "24" || storeUserInfo[i] == "25" || storeUserInfo[i] == "26" || storeUserInfo[i] == "27" || storeUserInfo[i] == "28" || storeUserInfo[i] == "29" || storeUserInfo[i] == "30" || storeUserInfo[i] == "31" ) {

						date = storeUserInfo[i];
						i++;
						
						while (i < (int) storeUserInfo.size()) {

						if (storeUserInfo[i] == "jan" || storeUserInfo[i] == "feb" || storeUserInfo[i] == "mar" || storeUserInfo[i] == "apr" || storeUserInfo[i] == "may" || storeUserInfo[i] == "jun" || storeUserInfo[i] == "jul" || storeUserInfo[i] == "aug" || storeUserInfo[i] == "sep" || storeUserInfo[i] == "oct" || storeUserInfo[i] == "nov" || storeUserInfo[i] == "dec") {
						
						month = storeUserInfo[i];
						++i;
						year = storeUserInfo[i];
						//++i;

						final = naturalParseInput(date, month, year);
						

						//store = final; // remember to add " " spacing next time for parsing stuff like "21 Dec"
						store = final;

						checkWord = checkKeyWord(store);

						if (checkWord.size() > 12) {
							taskName = taskName + "on ";
							taskName += storeUserInfo[i] + " ";
							++i;

						} else {
							storeUserInfo[i] = store;
							//startDate = store;
							startDate = storeUserInfo[i];


							// Guards
							verifyDate = checkParseDate(startDate);
							verifyMonth = checkParseMonth(startDate);
							verifyYear = checkParseYear(startDate);

							// push back guard output into vector
							// error is not = 1
							startDate = guardConvertParserDate(verifyDate, verifyMonth, verifyYear, startDate);

							++i;	

							if(i < (int) storeUserInfo.size()) { 
								startTime += storeUserInfo[i];

								// guards
								verifyTime = checkParseTime(startTime);

								// push back guard output into vector
								startTime = guardConvertParserTime(verifyTime, startTime);
								++i;
							}
						}
						


					} else {

						taskName = storeUserInfo[i];
						}

				}
							
							
					} else {				


					store = storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"

			
								
					if (storeUserInfo[i] == keyWord_5 || storeUserInfo[i] == keyWord_6 || storeUserInfo[i] == keyWord_7 ) {

					startDate = storeUserInfo[i];
				
					++i;	
	
					if(i < (int) storeUserInfo.size()) { 
					startTime = storeUserInfo[i];

					//guards
					verifyTime = checkParseTime(startTime);

					// push back guard output into vector
					startTime = guardConvertParserTime(verifyTime, startTime);
					++i;
					}

				} else { 

						checkWord = checkKeyWord(store); 
						
						if (checkWord.size() > 12) {
							taskName = taskName + "on ";
							taskName += storeUserInfo[i] + " ";
							++i;

						} else {

							startDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"

							// Guards
							verifyDate = checkParseDate(startDate);
							verifyMonth = checkParseMonth(startDate);
							verifyYear = checkParseYear(startDate);

							// push back guard output into vector
							// error is not = 1

							startDate = guardConvertParserDate(verifyDate, verifyMonth, verifyYear, startDate);
							++i;				


							if(i < (int) storeUserInfo.size()) { 
								startTime += storeUserInfo[i];

								// guards
								verifyTime = checkParseTime(startTime);

								// push back guard output into vector										
								startTime = guardConvertParserTime(verifyTime, startTime);
								++i;
							}
						}
					}
				}	
			}	
		}


			// keyword is "by"
			// Purpose is for deadline tasks to be done by that day & time or day/time
			else if(storeUserInfo[i] == keyWord_2) {
				++i;

				if (i < (int) storeUserInfo.size() && 
					storeUserInfo[i] != keyWord_1 &&
					storeUserInfo[i] != keyWord_3 &&
					storeUserInfo[i] != keyWord_4) {

					store = storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"
					if (storeUserInfo[i] == keyWord_5 || storeUserInfo[i] == keyWord_6 || storeUserInfo[i] == keyWord_7 ) {

					startDate = storeUserInfo[i];
					endDate = startDate;
				
					++i;	
	
					if(i < (int) storeUserInfo.size()) { 
					startTime = storeUserInfo[i];

					//guards
					verifyTime = checkParseTime(startTime);

					// push back guard output into vector
					startTime = guardConvertParserTime(verifyTime, startTime);
					endTime = startTime;
					++i;
					}


				} else {

						checkWord = checkKeyWord(store);

						if (checkWord.size() > 12) {
							taskName = taskName + "by ";
							taskName += storeUserInfo[i] + " ";
							++i;
						} else {

							startDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"

							// Guards
							verifyDate = checkParseDate(startDate);
							verifyMonth = checkParseMonth(startDate);
							verifyYear = checkParseYear(startDate);

							startDate = guardConvertParserDate(verifyDate, verifyMonth, verifyYear, startDate);

							endDate = startDate;
							++i;


							if(i < (int) storeUserInfo.size()) {

								startTime += storeUserInfo[i];
								// guards
								verifyTime = checkParseTime(startTime);

								// push back guard output into vector										
								startTime = guardConvertParserTime(verifyTime, startTime);
								endTime = startTime;
								++i;
							}
						}
					}
				}

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

						store = storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"

						checkWord = checkKeyWord(store);

						if (checkWord.size() > 12) {
							taskName = taskName + "from ";
							taskName += storeUserInfo[i] + " ";
							++i;

						} else {

							checkDate += storeUserInfo[i];
							if (checkDate.size() > 5) {

								startDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"

								// Guards
								verifyDate = checkParseDate(startDate);
								verifyMonth = checkParseMonth(startDate);
								verifyYear = checkParseYear(startDate);

								// push back guard output into vector										
								startDate = guardConvertParserDate(verifyDate, verifyMonth, verifyYear, startDate);

								++i;

								storeUserInfo.push_back("");

								if(storeUserInfo[i] == keyWord_4) {
									++i;

									storeUserInfo.erase(storeUserInfo.end()-1);

									endDate += storeUserInfo[i];

									// guards
									verifyDate = checkParseDate(endDate);
									verifyMonth = checkParseMonth(endDate);
									verifyYear = checkParseYear(endDate);

									// push back guard output into vector
									endDate = guardConvertParserDate(verifyDate, verifyMonth, verifyYear, endDate);

									++i;

									if (i < (int) storeUserInfo.size()){
										endTime += storeUserInfo[i];

										// guards
										verifyTime = checkParseTime(endTime);

										// push back guard output into vector										
										endTime = guardConvertParserTime(verifyTime, endTime);


										++i;
									}

								} else {

									startTime += storeUserInfo[i];

									// guards
									verifyTime = checkParseTime(startTime);

									// push back guard output into vector	
									startTime = guardConvertParserTime(verifyTime, startTime);

									++i;
								}

							} else {
								startTime += storeUserInfo[i];

								// guards
								verifyTime = checkParseTime(startTime);

								// push back guard output into vector	
								startTime = guardConvertParserTime(verifyTime, startTime);
								i++;
							}

						}
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


						store = storeUserInfo[i]; // store word after "to"

						checkWord = checkKeyWord(store);

						if (checkWord.size() > 12) {
							taskName = taskName + "to ";
							taskName += storeUserInfo[i] + " ";
							++i;

						} else {

							checkDate2 += storeUserInfo[i];
							if ((int) checkDate2.size() > 5) {
								endDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing

								// Guards
								verifyDate = checkParseDate(endDate);
								verifyMonth = checkParseMonth(endDate);
								verifyYear = checkParseYear(endDate);

								// push back guard output into vector
								endDate = guardConvertParserDate(verifyDate, verifyMonth, verifyYear, endDate);
								++i;

								storeUserInfo.push_back("");

								//if (i < (int) storeUserInfo.size()) {
								endTime += storeUserInfo[i];

								storeUserInfo.erase(storeUserInfo.end()-1);

								// Guards
								verifyTime = checkParseTime(endTime);

								// push back guard output into vector										
								endTime = guardConvertParserTime(verifyTime, endTime);

								++i;
								//}
							} else {
								endTime += storeUserInfo[i];

								// Guards
								verifyTime = checkParseTime(endTime);

								// push back guard output into vector										
								endTime = guardConvertParserTime(verifyTime, endTime);
								i++;
							}
						}
					}

				} else {
					taskName += storeUserInfo[i] + " ";
					++i;
				}
			}


			taskName = taskName.substr(0, taskName.size()-1);

			userInformation.push_back(taskName);
			userInformation.push_back(startDate);
			userInformation.push_back(startTime);
			userInformation.push_back(endDate);
			userInformation.push_back(endTime);

			break;

	case READ:

		// only detail to parse is the Index on the GUI
		if (i < (int) storeUserInfo.size()) {

			taskName = storeUserInfo[i];
			++i;		
		} else {
			taskName = "1";	
		}

		
		userInformation.push_back(taskName);
		userInformation.push_back(startDate);
		userInformation.push_back(startTime);
		userInformation.push_back(endDate);
		userInformation.push_back(endTime);

		break;

	case UPDATE:
		// update {index} {field to be updated} {what to be updated}
		// {field to be updated} includes 5 keywords. They are as follows
		// 1) task -> taskName
		// 2) sd -> startDate
		// 3) st -> startTime
		// 4) ed -> endDate
		// 5) et -> endTime

		if (i < (int) storeUserInfo.size()) {
			while (i < (int) storeUserInfo.size()) {



				if(storeUserInfo[i] == sd ) {	
					startDate += storeUserInfo[i];
					++i;
					while(i < (int) storeUserInfo.size()){

						startTime += storeUserInfo[i] + " ";

						// Guards
						verifyDate = checkParseDate(startTime);
						verifyMonth = checkParseMonth(startTime);
						verifyYear = checkParseYear(startTime);

						// push back guard output into vector										
						startTime = guardConvertParserDate(verifyDate, verifyMonth, verifyYear, startTime);
						++i;
					}

				} else if (storeUserInfo[i] == st) {

					startDate += storeUserInfo[i];
					++i;
					while(i < (int) storeUserInfo.size()){

						startTime += storeUserInfo[i] + " ";

						// Guards
						verifyTime = checkParseTime(startTime);

						// push back guard output into vector										
						startTime = guardConvertParserTime(verifyTime, startTime);

						++i;
					}

				} else if (storeUserInfo[i] == ed) {

					startDate += storeUserInfo[i];
					++i;
					while(i < (int) storeUserInfo.size()){

						startTime += storeUserInfo[i] + " ";

						// Guards
						verifyDate = checkParseDate(startTime);
						verifyMonth = checkParseMonth(startTime);
						verifyYear = checkParseYear(startTime);

						// push back guard output into vector										
						startTime = guardConvertParserDate(verifyDate, verifyMonth, verifyYear, startTime);
						++i;
					}

				} else if (storeUserInfo[i] == et) {
					startDate += storeUserInfo[i];
					++i;
					while(i < (int) storeUserInfo.size()){

						startTime += storeUserInfo[i] + " ";

						// Guards
						verifyTime = checkParseTime(startTime);

						// push back guard output into vector										
						startTime = guardConvertParserTime(verifyTime, startTime);

						++i;
					}

				} else if (storeUserInfo[i] == task) {
					startDate += storeUserInfo[i];

					++i;
					while(i<storeUserInfo.size()){
						startTime += storeUserInfo[i] + " ";
						++i;
					}	
					startTime = startTime.substr(0, startTime.size()-1);

				} else {

					taskName += storeUserInfo[i] ; // remember to add " " spacing next time for parsing stuff like "21 Dec"
					++i;
					
				}

			} 

		} else {
			taskName = "1";
		}

		userInformation.push_back(taskName);
		userInformation.push_back(startDate);
		userInformation.push_back(startTime);
		userInformation.push_back(endDate);
		userInformation.push_back(endTime);

		break;

	case DELETE:
		// only detail to parse is the Index on the GUI

		if (i < (int) storeUserInfo.size()) {

			taskName = storeUserInfo[i];
			++i;		
		} else {
			taskName = "1";	
		}

		userInformation.push_back(taskName);
		userInformation.push_back(startDate);
		userInformation.push_back(startTime);
		userInformation.push_back(endDate);
		userInformation.push_back(endTime);

		break;

	case SEARCH:

		if (i < (int) storeUserInfo.size()) {
			if(storeUserInfo[i] == sd ) {	
				taskName = storeUserInfo[i];
				++i;
				while(i < (int) storeUserInfo.size()){

					
					//startDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"		

					startDate = storeUserInfo[i] + " ";

					++i;
				}

			} else if (storeUserInfo[i] == st) {

				taskName = storeUserInfo[i];
				++i;
				while(i < (int) storeUserInfo.size()){

					startDate = storeUserInfo[i] + " ";

					++i;
				}

			} else if (storeUserInfo[i] == ed) {

				taskName = storeUserInfo[i];
				++i;
				while(i < (int) storeUserInfo.size()){

					startDate = storeUserInfo[i] + " ";

					++i;
				}

			} else if (storeUserInfo[i] == et) {
				taskName = storeUserInfo[i];
				++i;
				while(i < (int) storeUserInfo.size()){

					startDate = storeUserInfo[i] + " ";

					++i;
				}

			} else if (storeUserInfo[i] == task) {
				taskName = storeUserInfo[i];

				++i;
				while(i < storeUserInfo.size()){
					startDate = storeUserInfo[i] + " ";
					++i;

				}	

			} else {
				taskName += storeUserInfo[i] ; // remember to add " " spacing next time for parsing stuff like "21 Dec"
				++i;
			}

		} else {
			taskName = "1";
		}

		startDate = startDate.substr(0, startDate.size()-1);

		userInformation.push_back(taskName);
		userInformation.push_back(startDate);
		userInformation.push_back(startTime);
		userInformation.push_back(endDate);
		userInformation.push_back(endTime);


		break;

	case CHECK:

		if (i < (int) storeUserInfo.size()) {

			taskName = storeUserInfo[i];
			++i;		
		} else {
			taskName = "1";	
		}

		userInformation.push_back(taskName);
		userInformation.push_back(startDate);
		userInformation.push_back(startTime);
		userInformation.push_back(endDate);
		userInformation.push_back(endTime);

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
			// Purpose is for showcasing tasks to be done on that day (startDate and/or startTime)
			if (storeUserInfo[i] == keyWord_1) {  
				++i;
				if (i < (int) storeUserInfo.size() && 
					storeUserInfo[i] != keyWord_2 &&
					storeUserInfo[i] != keyWord_3 &&
					storeUserInfo[i] != keyWord_4 ) {

					store = storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"

					if (storeUserInfo[i] == keyWord_5 || storeUserInfo[i] == keyWord_6 || storeUserInfo[i] == keyWord_7 ) {

					startDate = storeUserInfo[i];
				
					++i;	
	
					if(i < (int) storeUserInfo.size()) { 
					startTime = storeUserInfo[i];

					//guards
					verifyTime = checkParseTime(startTime);

					// push back guard output into vector
					startTime = guardConvertParserTime(verifyTime, startTime);
					++i;
					}
						// check if keyword is repeated
					} else {
						checkWord = checkKeyWord(store);

						if (checkWord.size() > 12) {
							taskName = taskName + "on ";
							taskName += storeUserInfo[i] + " ";
							++i;

						} else {

							startDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"

							// Guards
							verifyDate = checkParseDate(startDate);
							verifyMonth = checkParseMonth(startDate);
							verifyYear = checkParseYear(startDate);

							// push back guard output into vector
							// error is not = 1

							startDate = guardConvertParserDate(verifyDate, verifyMonth, verifyYear, startDate);
							++i;				


							if(i < (int) storeUserInfo.size()) { 
								startTime += storeUserInfo[i];

								// guards
								verifyTime = checkParseTime(startTime);

								// push back guard output into vector										
								startTime = guardConvertParserTime(verifyTime, startTime);
								++i;
							}
						}
					}
				}	
			}			


			// keyword is "by"
			// Purpose is for deadline tasks to be done by that day & time or day/time
			else if(storeUserInfo[i] == keyWord_2) {
				++i;

				if (i < (int) storeUserInfo.size() && 
					storeUserInfo[i] != keyWord_1 &&
					storeUserInfo[i] != keyWord_3 &&
					storeUserInfo[i] != keyWord_4) {

					store = storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"

					if (storeUserInfo[i] == keyWord_5 || storeUserInfo[i] == keyWord_6 || storeUserInfo[i] == keyWord_7 ) {

					startDate = storeUserInfo[i];
					endDate = startDate;
					++i;	
	
					if(i < (int) storeUserInfo.size()) { 
					startTime = storeUserInfo[i];

					//guards
					verifyTime = checkParseTime(startTime);

					// push back guard output into vector
					startTime = guardConvertParserTime(verifyTime, startTime);
					//endTime = startTime;
					++i;
					}

						} else {
						checkWord = checkKeyWord(store);

						if (checkWord.size() > 12) {
							taskName = taskName + "by ";
							taskName += storeUserInfo[i] + " ";
							++i;
						} else {

							startDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"

							// Guards
							verifyDate = checkParseDate(startDate);
							verifyMonth = checkParseMonth(startDate);
							verifyYear = checkParseYear(startDate);

							startDate = guardConvertParserDate(verifyDate, verifyMonth, verifyYear, startDate);
							endDate = startDate;
							++i;


							if(i < (int) storeUserInfo.size()) {

								startTime += storeUserInfo[i];
								// guards
								verifyTime = checkParseTime(startTime);

								// push back guard output into vector										
								startTime = guardConvertParserTime(verifyTime, startTime);
								endTime = startTime;
								++i;
							}
						}
					}
				}
		
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

						store = storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"

						checkWord = checkKeyWord(store);

						if (checkWord.size() > 12) {
							taskName = taskName + "from ";
							taskName += storeUserInfo[i] + " ";
							++i;

						} else {

							checkDate += storeUserInfo[i];
							if (checkDate.size() > 5) {

								startDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing stuff like "21 Dec"

								// Guards
								verifyDate = checkParseDate(startDate);
								verifyMonth = checkParseMonth(startDate);
								verifyYear = checkParseYear(startDate);

								// push back guard output into vector										
								startDate = guardConvertParserDate(verifyDate, verifyMonth, verifyYear, startDate);

								++i;

								storeUserInfo.push_back("");

								if(storeUserInfo[i] == keyWord_4) {
									++i;

									endDate += storeUserInfo[i];

									// guards
									verifyDate = checkParseDate(endDate);
									verifyMonth = checkParseMonth(endDate);
									verifyYear = checkParseYear(endDate);

									// push back guard output into vector
									endDate = guardConvertParserDate(verifyDate, verifyMonth, verifyYear, endDate);

									++i;

									if (i < (int) storeUserInfo.size()){
										endTime += storeUserInfo[i];

										// guards
										verifyTime = checkParseTime(endTime);

										// push back guard output into vector										
										endTime = guardConvertParserTime(verifyTime, endTime);

										++i;
									}

								} else {

									startTime += storeUserInfo[i];

									// guards
									verifyTime = checkParseTime(startTime);

									// push back guard output into vector	
									startTime = guardConvertParserTime(verifyTime, startTime);

									++i;
								}

							} else {
								startTime += storeUserInfo[i];

								// guards
								verifyTime = checkParseTime(startTime);

								// push back guard output into vector	
								startTime = guardConvertParserTime(verifyTime, startTime);
								i++;
							}
						}
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

						
						store = storeUserInfo[i]; // store word after "to"

						checkWord = checkKeyWord(store);

						if (checkWord.size() > 12) {
							taskName = taskName + "to ";
							taskName += storeUserInfo[i] + " ";
							++i;

						} else {

						checkDate2 += storeUserInfo[i];
						if ((int) checkDate2.size() > 5) {
							endDate += storeUserInfo[i]; // remember to add " " spacing next time for parsing

							// Guards
							verifyDate = checkParseDate(endDate);
							verifyMonth = checkParseMonth(endDate);
							verifyYear = checkParseYear(endDate);

							// push back guard output into vector
							endDate = guardConvertParserDate(verifyDate, verifyMonth, verifyYear, endDate);
							++i;

							storeUserInfo.push_back("");
		
							endTime += storeUserInfo[i];

							// Guards
							verifyTime = checkParseTime(endTime);

							// push back guard output into vector										
							endTime = guardConvertParserTime(verifyTime, endTime);

							++i;
							
						} else {
							endTime += storeUserInfo[i];

							// Guards
							verifyTime = checkParseTime(endTime);

							// push back guard output into vector										
							endTime = guardConvertParserTime(verifyTime, endTime);
							i++;
						}
					}
				}

		
			} else {
				taskName += storeUserInfo[i] + " ";
				++i;
			}
		
				
		}
		taskName = taskName.substr(0, taskName.size()-1);

		userInformation.push_back(taskName);
		userInformation.push_back(startDate);
		userInformation.push_back(startTime);
		userInformation.push_back(endDate);
		userInformation.push_back(endTime);

		break;
	}

	return 1;
}

	// guard against keyWord (startdate will get date)
	string Parser:: checkKeyWord(string startDate) {

		string found;
		string check = CHECK_DATE;

		// Searches the string for the first character that does not match any of the characters (0123456789 ) specified in its arguments.
		if( startDate.size() < 2 ) {
		
		found = startDate + GUARD_DATE;
		
		} else {
			if ((startDate.find_first_not_of(check) && startDate.size() > 4) || startDate.substr(2,1) == "."  ) { // detects "/"
			found = startDate;

		} else {

			found = startDate + GUARD_DATE;
		}
			
		return found;

	}
	return found;
}


	// getter functions

	int Parser::getDate(string date) {
		int start = 0;
		int keystroke = date.find("/", 0);

		start = atoi(date.substr(0, keystroke).c_str());

		return start;
	}

	int Parser::getMonth(string date) {

		int start = 0;
		int keystroke = date.find("/", 0); // finds first /12/2014

		int startOfMonth = keystroke + 1; // 2
		int startOfKeystroke = date.find("/", startOfMonth); 
		start = atoi(date.substr(startOfMonth, startOfKeystroke).c_str()); // converts string to int

		return start;

	}


	int Parser::getYear(string date) {

		int start = 0;
		int combine;

		int firstKeyStroke = date.find("/", 0);
		int startOfMonth = firstKeyStroke + 1;
		int secondKeyStroke = date.find("/",startOfMonth); 
		int startOfYear = secondKeyStroke + 1;

		start = atoi(date.substr(startOfYear).c_str()); // converts string to int

		if (start < 100) {
			return start = start + 2000;
		} else {
			return start;
		}

	}


	// function to check if each month corresponds to the correct dates in the month
	string Parser::checkDate(string date) {

		int currentDate = getDate(date);
		int currentMonth = getMonth(date);
		int currentYear = getYear(date);



		// checks if the current year is a leap year
		if ((currentYear % 4 == 0 && currentYear % 100 != 0) || ( currentYear % 400 == 0)) {

			// checks if  month consists of 31 days (Jan, March, May, July, August, October, December)
			if (currentMonth == 1 || currentMonth == 3 || currentMonth == 5 || currentMonth == 7 || currentMonth == 8 || currentMonth == 10 || currentMonth == 12) {
				//checks if the date doesn't exceed 31, if it does, the month is incremented
				if (currentDate > 31 || currentDate < 1) {
					output =  "0";
				} else {

					output =  "1";
				}  
				// checks if month consists of 30 days (April, June, September, November)
			} else if (currentMonth == 4 || currentMonth == 6 || currentMonth == 9 || currentMonth == 11) {

				if (currentDate > 30 || currentDate < 1) {
					output =  "0";
				} else {
					output =  "1";
				}
				// checks if month consits of 29 days (Feburary and leap year)
			} else if (currentMonth == 2) {

				if (currentDate >29 || currentDate < 1) {

					output = "0";
				} else {
					output = "1";
				}
			} else if (currentMonth != 1 || currentMonth != 2 || currentMonth != 3 || currentMonth != 4 || currentMonth != 5 ||			currentMonth != 6 || currentMonth != 7 || currentMonth != 8 || currentMonth != 9 || currentMonth != 10 || currentMonth != 11 || currentMonth != 12 ) {

				output = "0";
			}

			//the current year is not a leap year

		} else {

			// checks if  month consists of 31 days (Jan, March, May, July, August, October, December)
			if (currentMonth == 1 || currentMonth == 3 || currentMonth == 5 || currentMonth == 7 || currentMonth == 8 || currentMonth == 10 || currentMonth == 12) {
				//checks if the date doesn't exceed 31, if it does, the month is incremented
				if (currentDate > 31 || currentDate < 1) {
					output =  "0";
				} else {

					output =  "1";
				}  
				// checks if month consists of 30 days (April, June, September, November)
			} else if (currentMonth == 4 || currentMonth == 6 || currentMonth == 9 || currentMonth == 11) {

				if (currentDate > 30 || currentDate < 1) {
					output =  "0";
				} else {
					output =  "1";
				}
				// checks if month consits of 28 days (Feburary and not leap year)
			} else if (currentMonth == 2) {

				if (currentDate > 28 || currentDate < 1) {
					output = "0";
				} else {
					output = "1";
				}

			} else if (currentMonth != 1 || currentMonth != 2 || currentMonth != 3 || currentMonth != 4 || currentMonth != 5 || currentMonth != 6 || currentMonth != 7 || currentMonth != 8 || currentMonth != 9 || currentMonth != 10 || currentMonth != 11 || currentMonth != 12 ) {

				output = "0";
			}
		}


		return output;
	}


	// *** date input format is DD/MM/YY ***
	string Parser::checkParseDate(string date)
	{

		string output = checkDate(date);

		return output;

	}

	string Parser::checkParseMonth(string date) {

		// 12/12/2014
		int start = 0;
		int keystroke = date.find("/", 0); // finds first /12/2014

		int startOfMonth = keystroke + 1; // 2
		int startOfKeystroke = date.find("/", startOfMonth); 
		start = atoi(date.substr(startOfMonth, startOfKeystroke).c_str()); // converts string to int

		//exception handling for the month input
		if (start < 1 || start > 12)
		{
			successful =  "0";
		} else {
			successful =  "1";
		}

		return successful;
	}

	string Parser::checkParseYear(string date) {
		// 12/09/14
		int start = 0;

		int firstKeyStroke = date.find("/", 0);
		int startOfMonth = firstKeyStroke + 1;
		int secondKeyStroke = date.find("/",startOfMonth); 
		int startOfYear = secondKeyStroke + 1;

		start = atoi(date.substr(startOfYear).c_str()); // converts string to int

		//exception handling for the Year input
		if (start < 0 || start > 99)
		{
			successful =  "0";
		} else {
			successful =  "1";
		}

		return successful;

	}

	// *** Time input format is HH:MM ***
	string Parser::checkParseTime(string time) {

		int keyStroke = time.find(".", 0);
		int startOfMinute = keyStroke + 1;

		int hour = atoi(time.substr(0,keyStroke).c_str());
		int min = atoi(time.substr(startOfMinute).c_str());


		if (hour < 0 || hour > 23 || min < 0 || min > 60) {
			successful =  "0";
		} else {
			successful =  "1";
		}

		return successful;

	}

	string Parser::convertDate(string date) {

		// input:12/12/14
		// output: 20141212
		string x;

		int digit = 0;
		int month = 0;
		int year = 0;
		int combine;

		int keystroke = date.find("/", 0);

		int startOfMonth = keystroke + 1; // 2
		int startOfKeystroke = date.find("/", startOfMonth); 

		int secondKeyStroke = date.find("/",startOfMonth); 
		int startOfYear = secondKeyStroke + 1;


		digit = atoi(date.substr(0, keystroke).c_str());
		month = atoi(date.substr(startOfMonth, startOfKeystroke).c_str());
		year =  atoi(date.substr(startOfYear).c_str());

		combine = digit + (month * 100) + ((year+2000) * 10000);

		string result;
		ostringstream convert; // stream used for the conversion
		convert << combine; 
		result = convert.str();

		return result;

	}

	string Parser::convertTime(string time) {

		int keyStroke = time.find(".", 0);
		int startOfMinute = keyStroke + 1;
		int combine;

		int hour = atoi(time.substr(0,keyStroke).c_str());
		int min = atoi(time.substr(startOfMinute).c_str());


		combine = (hour * 100) + min;


		string result;
		ostringstream convert; // stream used for the conversion
		convert << combine; 
		result = convert.str();


		if (result.size() == 1) {
			result = "000" + result;
		} else if (result.size() == 2) {
			result = "00" + result;	
		} else if (result.size() == 3) {
			result = "0" + result;

		} else {
			return result;
		}

		return result;

	}

	int Parser::convertStringToInt(string input) {

		int value = atoi(input.c_str());
		return value;

	}

	bool Parser::compare(int start, int end) {

		if (start > end) {
			return 1;
		} else {
			return 0;
		}
	}

	string Parser::guardConvertParserDate(string verifyDate, string verifyMonth, string verifyYear, string date) {

		string convertedDate_Start;
		string convertedDate_End;


		if (verifyDate == "1") {
			// Conversion of date
			convertedDate_Start = convertDate(date);
			date = convertedDate_Start;
		} else {
			date = "1";

		}

		if (verifyMonth == "1" && verifyDate == "1" ) {
			date = convertedDate_Start;

		} else if (verifyDate == "1" && verifyMonth != "1") {
			date = "2";

		} else if (verifyDate != "1" && verifyMonth != "1") {
			date = "12";
		}


		if (verifyDate == "1" && verifyMonth == "1" && verifyYear == "1") {
			date = convertedDate_Start;

		} else if (verifyDate == "1" && verifyMonth == "1" && verifyYear != "1") {
			date = "3";

		} else if (verifyDate != "1" && verifyMonth != "1" && verifyYear != "1") {
			date = "123";
		} else if (verifyDate == "1" && verifyMonth != "1" && verifyYear != "1") {
			date = "23";
		} else if (verifyDate != "1" && verifyMonth == "1" && verifyYear != "1") {
			date = "13";
		}

		return date;
	}

	string Parser::guardConvertParserTime(string verifyTime, string time) {


		string convertedTime_Start;
		string convertedTime_End;

		if (verifyTime == "1") {
			// Conversion of time
			convertedTime_Start = convertTime(time);
			time = convertedTime_Start;		
		} else {
			time = "0";

		}

		return time;

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

string Parser:: naturalParseInput (string date, string month, string year) {

	int intDate = atoi(date.c_str());

	string intMonth;
	string combine;
	string final;


	if (month == "jan" || month == "JAN" || month == "Jan") {
		intMonth = "1";

	} else if (month == "feb" || month == "FEB" || month == "feb") {
		intMonth = "2";

	} else if (month == "mar" || month == "MAR" || month == "Mar") {
		intMonth = "3";

	} else if (month == "apr" || month == "APR" || month == "Apr") {
		intMonth = "4";

	} else if (month == "may" || month == "MAY" || month == "May") {
		intMonth = "5";

	} else if (month == "jun" || month == "JUN" || month == "Jun") {
		intMonth = "6";

	} else if (month == "jul" || month == "JUL" || month == "Jul") {
		intMonth = "7";

	} else if (month == "aug" || month == "AUG" || month == "aug") {
		intMonth = "8";

	} else if (month == "sep" || month == "SEP" || month == "Sep") {
		intMonth = "9";

	} else if (month == "oct" || month == "OCT" || month == "Oct") {
		intMonth = "10";

	} else if (month == "nov" || month == "NOV" || month == "Nov") {
		intMonth = "11";

	} else if (month == "dec" || month == "DEC" || month == "Dec") {
		intMonth = "12";

	} else {
		intMonth = "0";
	}

	combine = date + "/" + intMonth + "/" + year;

	if (checkDate(combine) == "1") {
	return combine;
		
	} else {
		return 0;
	}
}



void Parser::parserEmpty() {
		storeUserInfo.clear();
		userInformation.clear();

}

