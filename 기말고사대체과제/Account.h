#pragma once

#include <sstream>
#include <string>
#include <ctime>
using namespace std;

#include "NowTime.h"

template< typename T >
class TAccount{

public:

	

private:

	static int	count;

protected:

	string	number;
	T		money;

	TNowTime *	lastTime;

public:
	
	TAccount( int number ){
	
		stringstream ss;
		ss << number;
		this->number = ss.str();

		money		= 0;
		lastTime	= 0;
		++count;
	}

	TAccount( const string & number ){
	
		this->number = number;

		money		= 0;
		lastTime	= 0;
		++count;
	}

	virtual ~TAccount(){
	
		if( lastTime ){
			delete lastTime;
		}

		--count;
	}

	virtual string	getNumber(){
	
		return number;
	}

	virtual void	save( T money ){
	
		this->money += money;

		updateLastTime();
	}

	virtual void	withdraw( T money ) = 0;

	virtual T	getBalance(){ return money; }
	
	virtual string	getLastTime(){
	
		if( lastTime ){
			return lastTime->getTime();
		}
		
		return "";
	}

	virtual void	updateLastTime(){
	
		if( lastTime ){
			delete lastTime;
		}

		lastTime = new TNowTime();
	}

	static int getCount(){
	
		return count;
	}
};

template< typename T >
int TAccount< T >::count = 0;

template< typename T >
void withdrawMoney( T & source, T & amount ){

	source -= amount;
}

