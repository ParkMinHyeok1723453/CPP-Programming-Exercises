#pragma once

#include "Bank.h"

class TBankKukmin : public TBank{

public:

	

protected:

	static TBankKukmin * bankKukmin;

private:

	TBankKukmin();

public:

	static void fin();

	static TBankKukmin *	getInstance();
	
	void	withdraw( const string & number, int money );
};

