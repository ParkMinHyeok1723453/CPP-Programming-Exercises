#include "NowTime.h"

TNowTime::TNowTime(){

	time_t	nowTime		= time( 0 );
	tm *	localTime	= localtime( &nowTime );

	sprintf( timeText, "%04d-%02d-%02d %02d:%02d:%02d",
		localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
		localTime->tm_hour, localTime->tm_min, localTime->tm_sec );
}

string TNowTime::getTime(){

	return timeText;
}