#pragma once

#include <string>
using namespace std;

class TException{

public:



protected:

	string	message;

public:

	TException();
	TException( const string & message );
	const string & what() const;
};

