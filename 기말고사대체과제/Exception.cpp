#include "Exception.h"

TException::TException(){

}

TException::TException( const string & message ){
	
	this->message = message;
}

const string & TException::what() const{
	
	return message;
}
