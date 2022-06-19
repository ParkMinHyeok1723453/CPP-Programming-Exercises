#pragma once

#include "Bank.h"

class TBankHana : public TBank{

public:

	

protected:

	static TBankHana * bankHana;

private:

	TBankHana();

public:

	static void fin();

	static TBankHana *	getInstance();
	
	void	withdraw( const string & number, int money );
};

