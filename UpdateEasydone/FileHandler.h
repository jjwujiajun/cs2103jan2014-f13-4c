
#pragma once
#ifndef _STORE_H_
#define _STORE_H_

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>


using namespace std;

class FileHandler {

public:
	bool fileReady(string fileName);
	bool discopy(string fileName);
};

#endif 