#pragma once

#include <iostream>
using namespace std;

#include "NowTime.h"

class TCreditCard{

public:



protected:

	string	number;
	int		money;

	TNowTime *	lastTime;

public:

	TCreditCard( const string & number );
	~TCreditCard();

	string	getNumber();
	void	pay( int money );
	int		getBalance();
	string	getLastTime();
	void	updateLastTime();
};
