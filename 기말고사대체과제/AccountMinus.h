#pragma once

#include "Account.h"

template< typename T >
class TAccountMinus : public TAccount< T >{

public:

	

protected:

	

public:

	TAccountMinus( int number ) : TAccount( number ){

	}

	TAccountMinus( const string & number ) : TAccount( number ){

	}

	void	withdraw( T money ){

		withdrawMoney( this->money, money );
		updateLastTime();
	}
};

