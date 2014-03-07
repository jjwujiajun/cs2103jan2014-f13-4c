#include "History.h"

Jobs::Jobs() {
	ifstream storageFile;
	storageFile.open("Storage.txt");
	string temp;

	if(storageFile.is_open()){
		while(!storageFile.eof()){
			storageFile >> temp;
			_details.push_back(temp);
		}
	}
	storageFile.close();
}

int Jobs::storageSize() {
	return _details.size();
}

string Jobs::taskname() {
	string task = _details[0];
	string taskName = task.substr(0, task.find_first_of("."));
	task.erase(task.begin(), task.begin()+task.find_first_of("."));
	return taskName;
}

string Jobs::additionalDetails() {
	string task = _details[0];
	string additionaldetails = task.substr(0, task.find_first_of("."));
	task.erase(task.begin(), task.begin()+task.find_first_of("."));
	return additionaldetails;
}

string Jobs::reminder() {
	string task = _details[0];
	string Reminder = task.substr(0, task.find_first_of("."));
	task.erase(task.begin(), task.begin()+task.find_first_of("."));
	return Reminder;
}

string Jobs::duplciate() {
	string task = _details[0];
	string Duplicate = task.substr(0, task.find_first_of("."));
	task.erase(task.begin(), task.begin()+task.find_first_of("."));
	return Duplicate;
}

int Jobs::startDate() {
	string task = _details[0];
	string startdate = task.substr(0, task.find_first_of("."));
	task.erase(task.begin(), task.begin()+task.find_first_of("."));
	return atoi(startdate.c_str());
}

int Jobs::startTime() {
	string task = _details[0];
	string starttime = task.substr(0, task.find_first_of("."));
	task.erase(task.begin(), task.begin()+task.find_first_of("."));
	return atoi(starttime.c_str());
}

int Jobs::endDate() {
	string task = _details[0];
	string enddate = task.substr(0, task.find_first_of("."));
	task.erase(task.begin(), task.begin()+task.find_first_of("."));
	return atoi(enddate.c_str());
}

int Jobs::endTime() {
	string task = _details[0];
	string endtime = task.substr(0, task.find_first_of("."));
	task.erase(task.begin(), task.begin()+task.find_first_of("."));
	return atoi(endtime.c_str());
}

bool Jobs::isCompleted() {
	string task = _details[0];
	string iscompleted = task.substr(0, task.find_first_of("."));
	task.erase(task.begin(), task.begin()+task.find_first_of("."));
	
	if(atoi(iscompleted.c_str()) == 1){
		return true;
	}
		
	return false;
}

bool Jobs::hasAvailableSlot() {
	string task = _details[0];
	string hasavailableSlot = task.substr(0, task.find_first_of("."));
	task.erase(task.begin(), task.begin()+task.find_first_of("."));
	_details.erase(_details.begin());
	
	if(atoi(hasavailableSlot.c_str()) == 1){
		return true;
	}
		
	return false;
}