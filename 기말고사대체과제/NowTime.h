#pragma once

#include <sstream>
#include <string>
#include <ctime>
using namespace std;

class TNowTime{

protected:

	char timeText[ 20 ];

public:

	TNowTime();

	string	getTime();
};