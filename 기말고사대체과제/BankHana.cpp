#include "BankHana.h"
#include "ExceptionNoAccount.h"

TBankHana *	TBankHana::bankHana = new TBankHana();

TBankHana::TBankHana() : TBank(){

}

void TBankHana::fin(){

	if( bankHana ){
		delete bankHana;
		bankHana = 0;
	}
}

TBankHana * TBankHana::getInstance(){

	return bankHana;
}

void TBankHana::withdraw( const string & number, int money ){

	try{
		
		checkAccount( number );
	}
	catch( const TExceptionNoAccount & ex ){
	
		throw ex;
	}
	catch( const TException & ex ){
	
	}

	accounts.find( number )->second->withdraw( money + 400 );	// 수수료 400원
	updateLastTime();
}
