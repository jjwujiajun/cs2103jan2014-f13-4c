#include "Store.h"

string Store::getTaskname(vector<Task> taskList, int index)
{
	string taskName = taskList[index].taskName;

	return taskName;
}

int Store::getStarttime(vector<Task> taskList, int index)
{
	int startTime=  taskList[index].startTime;
	
	return startTime;
}

int Store::getEndtime(vector<Task> taskList, int index)
{
	int endTime=  taskList[index].startTime;
	
	return endTime;
}

int Store::getDay(vector<Task> taskList, int index)
{
	int day = taskList[index].day;
	
	return day;
}

int Store::getMonth(vector<Task> taskList, int index)
{
	int month = taskList[index].month;
	
	return month;
}

int Store::getYear(vector<Task> taskList, int index)
{
	int year = taskList[index].year;
	
	return year;
}