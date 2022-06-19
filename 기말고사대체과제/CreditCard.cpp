#include "CreditCard.h"

TCreditCard::TCreditCard( const string & number ){
	
	this->number = number;

	money		= 0;
	lastTime	= 0;
}

TCreditCard::~TCreditCard(){

	if( lastTime ){
		delete lastTime;
	}
}

string TCreditCard::getNumber(){

	return number;
}

void TCreditCard::pay( int money ){

	this->money -= money;
	updateLastTime();
}

int TCreditCard::getBalance(){

	return money;
}

string TCreditCard::getLastTime(){

	if( lastTime ){
		return lastTime->getTime();
	}
	
	return "";
}

void TCreditCard::updateLastTime(){

	if( lastTime ){
		delete lastTime;
	}

	lastTime = new TNowTime();
}

