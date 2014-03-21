#ifndef HEADERS_H
#define HEADER_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cctype>
#include <iterator>
#include "Log.h"
#include "Task.h"
#include <assert.h>

const string GUI_LABEL_TODAY = "Today \n";
const string GUI_LABEL_ALLTASKS = "All Tasks \n";
const string GUI_FONT_LABEL = "Broadway";

#pragma once

class Headers
{
public:
	Headers(void);
	~Headers(void);
};
#endif
