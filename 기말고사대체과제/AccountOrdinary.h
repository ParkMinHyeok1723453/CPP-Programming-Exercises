#pragma once

#include "Account.h"
#include "ExceptionNotEnoughMoney.h"

template< typename T >
class TAccountOrdinary : public TAccount< T >{

public:

	

protected:

	

public:

	TAccountOrdinary( int number ) : TAccount( number ){
	
	}

	TAccountOrdinary( const string & number ) : TAccount( number ){

	}

	void	withdraw( T money ){

		if( money > this->money ){
			throw TExceptionNotEnoughMoney( "Not enough money." );
		}


		withdrawMoney( this->money, money );
		updateLastTime();
	}
};

