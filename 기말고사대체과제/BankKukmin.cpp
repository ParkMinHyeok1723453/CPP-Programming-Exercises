#include "BankKukmin.h"
#include "ExceptionNoAccount.h"

TBankKukmin *	TBankKukmin::bankKukmin = new TBankKukmin();

TBankKukmin::TBankKukmin() : TBank(){

}

void TBankKukmin::fin(){

	if( bankKukmin ){
		delete bankKukmin;
		bankKukmin = 0;
	}
}

TBankKukmin * TBankKukmin::getInstance(){

	return bankKukmin;
}

void TBankKukmin::withdraw( const string & number, int money ){

	try{
		
		checkAccount( number );
	}
	catch( const TExceptionNoAccount & ex ){
	
		throw ex;
	}
	catch( const TException & ex ){
	
	}

	accounts.find( number )->second->withdraw( money + 500 );	// 수수료 500원
	updateLastTime();
}

