#pragma once

#include "Account.h"
#include "CreditCard.h"

template< typename T >
class TAccountAdapter : public TAccount< T >{

public:

	

protected:

	TCreditCard *	card;

public:

	TAccountAdapter( TCreditCard * card ) : TAccount( card->getNumber() ){
	
		this->card = card;
	}

	~TAccountAdapter(){
	
		delete card;
	}

	string	getNumber(){
	
		return card->getNumber();
	}

	void	save( T money ){
	
		
	}

	void	withdraw( T money ){
	
		card->pay( money );
	}

	T	getBalance(){

		return card->getBalance();
	}
	
	string	getLastTime(){
	
		return card->getLastTime();
	}

	void	updateLastTime(){
	
		card->updateLastTime();
	}
};

