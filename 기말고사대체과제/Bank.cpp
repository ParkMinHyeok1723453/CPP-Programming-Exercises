#include "Bank.h"

#include "AccountOrdinary.h"
#include "AccountMinus.h"
#include "AccountAdapter.h"
#include "CreditCard.h"
#include "ExceptionAlreadyAccount.h"
#include "ExceptionNoAccount.h"

int TBank::count = 0;

TBank::TBank(){

	lastTime = 0;

	++count;
}

TBank::~TBank(){

	map< string, TAccount< int > * >::iterator it, itEnd;

	it		= accounts.begin();
	itEnd	= accounts.end();

	for( ; it != itEnd ; ++it ){
		delete it->second;
	}


	if( lastTime ){
		delete lastTime;
	}

	--count;
}

void TBank::checkAccount( int number ){

	stringstream ss;
	ss << number;
	checkAccount( ss.str() );
}

void TBank::checkAccount( const string & number ){

	if( accounts.find( number ) != accounts.end() ){
		
		throw TExceptionAlreadyAccount( "Already account." );
	}
	else{

		throw TExceptionNoAccount( "No account." );
	}
}

void TBank::addAccountOrdinary( const string & number ){

	try{
		
		checkAccount( number );
	}
	catch( const TExceptionAlreadyAccount & ex ){
	
		throw ex;
	}
	catch( const TException & ex ){
	
	}

	accounts[ number ] = new TAccountOrdinary< int >( number );
	updateLastTime();
}

void TBank::addAccountMinus( const string & number ){

	try{
		
		checkAccount( number );
	}
	catch( const TExceptionAlreadyAccount & ex ){
	
		throw ex;
	}
	catch( const TException & ex ){
	
	}

	accounts[ number ] = new TAccountMinus< int >( number );
	updateLastTime();
}

void TBank::addCreditCard( const string & number ){

	try{
		
		checkAccount( number );
	}
	catch( const TExceptionAlreadyAccount & ex ){
	
		throw ex;
	}
	catch( const TException & ex ){
	
	}

	accounts[ number ] = new TAccountAdapter< int >( new TCreditCard( number ) );
	updateLastTime();
}

void TBank::removeAccount( const string & number ){

	try{
		
		checkAccount( number );
	}
	catch( const TExceptionNoAccount & ex ){
	
		throw ex;
	}
	catch( const TException & ex ){
	
	}

	delete getAccount( number );
	accounts.erase( accounts.find( number ) );
	updateLastTime();
}

void TBank::save( const string & number, int money ){

	try{
		
		checkAccount( number );
	}
	catch( const TExceptionNoAccount & ex ){
	
		throw ex;
	}
	catch( const TException & ex ){
	
	}

	getAccount( number )->save( money );
	updateLastTime();
}

int TBank::getBalance( const string & number ){

	try{
		
		checkAccount( number );
	}
	catch( const TExceptionNoAccount & ex ){
	
		throw ex;
	}
	catch( const TException & ex ){
	
	}

	return getAccount( number )->getBalance();
}

string TBank::getLastTime( const string & number ){

	try{
		
		checkAccount( number );
	}
	catch( const TExceptionNoAccount & ex ){
	
		throw ex;
	}
	catch( const TException & ex ){
	
	}

	return getAccount( number )->getLastTime();
}

string TBank::getLastTime(){

	if( lastTime ){
		return lastTime->getTime();
	}
	
	return "";
}

void TBank::updateLastTime(){

	if( lastTime ){
		delete lastTime;
	}

	lastTime = new TNowTime();
}

int TBank::getCount(){

	return count;
}
