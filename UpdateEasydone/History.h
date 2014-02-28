// History.h
// Purpose is to save the user actions into a .txt file


#ifndef HISTORY_H
#define HISTORY_H

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

typedef struct Details {
	string taskName;
	int startDate;
	int endData;
	int startTime;
	int endTime;
    bool timeSlotStatus; //true if timeslot is available, false if timeslot is occupied
    bool taskStatus; // true is task is completed
};

class Jobs {
private:
	Details _detail;
	int _startDate;
	int _endDate;
	int _startTime;
	int _endTime;

public:
	Jobs(void);
	~Jobs(void);
	Jobs(Details);


};
#endif

/*
#ifndef HISTORY_H
#define HISTORY_H

#include <vector>
#include <time.h>
#include <fstream>
#include <iostream>
#include "StorageVector.h"
#include "FileOperation.h"

using namespace std;

struct with_command_details
{
    std::string command;
    std::string taskname;
    int date;
    int month;
    int year;
    int start_time;
    int end_time;
    bool timeSlotStatus;
    bool taskStatus;
};

class Action{

private:
    with_command_details _detail;

    int action_id;
    int _time;
    int _date;
    int _month;
    int _year;

public:


    Action(void);
    Action(with_command_details);

    with_command_details getDetails();
    int getTime();
    int getDate();
    int getMonth();
    int getYear();

public:
    std::fstream file;
    void writeToFile(bool);
    void RecordActionToFile(with_command_details,bool);
};


#endif // HISTORY_H


*/
