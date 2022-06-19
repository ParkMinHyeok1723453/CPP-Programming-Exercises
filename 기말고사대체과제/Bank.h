#pragma once

#include <sstream>
#include <string>
#include <map>
#include <ctime>
using namespace std;

#include "Account.h"

class TBank{

public:

	

private:

	static int	count;

protected:

	map< string, TAccount< int > * >	accounts;
	TNowTime *							lastTime;

public:

	TBank();
	virtual ~TBank();
	
	void	checkAccount( int number );
	void	checkAccount( const string & number );
	
	inline TAccount< int > *	getAccount( const string & number ){

		return accounts.find( number )->second;
	}

	void	addAccountOrdinary( const string & number );
	void	addAccountMinus( const string & number );
	void	addCreditCard( const string & number );

	void	removeAccount( const string & number );

	void			save( const string & number, int money );
	virtual void	withdraw( const string & number, int money ) = 0;
	int				getBalance( const string & number );
	string			getLastTime( const string & number );
	
	string	getLastTime();
	void	updateLastTime();

	static int	getCount();
};

