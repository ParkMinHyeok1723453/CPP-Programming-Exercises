#include <iostream>
#include <exception>
using namespace std;
#include <windows.h>

#include "BankHana.h"
#include "BankKukmin.h"
#include "Exception.h"

STARTUPINFO			startUpInfo;
PROCESS_INFORMATION	processInfo;

void init(){

	memset( &startUpInfo, 0, sizeof( STARTUPINFO ) );
	memset( &processInfo, 0, sizeof( PROCESS_INFORMATION ) );
}

void fin(){

	TBankHana::fin();
	TBankKukmin::fin();
}

void runCalculator(){

	if( ! processInfo.hProcess ){
		TCHAR command[] = TEXT( "calc" );
		CreateProcess( 0, command, 0, 0, 0, 0, 0, 0, &startUpInfo, &processInfo );
	}
}

void exitCalculator(){

	if( processInfo.hProcess ){
		TerminateProcess( processInfo.hProcess, 0 );
		processInfo.hProcess = 0;
	}
}

bool loop(){

	cout << "하나 1보통계좌생성 2마이너스계좌생성 3신용카드생성 4계좌제거 5입금 6출금 7잔고" << endl;
	cout << "국민 q보통계좌생성 w마이너스계좌생성 e신용카드생성 r계좌제거 t입금 y출금 u잔고" << endl;
	cout << "일반 a계좌수확인 s계산기켜기 d계산기끄기 f종료" << endl;

	fflush( stdin );
	switch( getchar() ){
		case '1':
		{
			string number;

			cout << "계좌번호입력: ";
			cin >> number;

			try{

				TBankHana::getInstance()->addAccountOrdinary( number );
			}
			catch( const TException & ex ){
			
				cout << ex.what() << endl;
			}
		}
		break;

		case '2':
		{
			string number;

			cout << "계좌번호입력: ";
			cin >> number;

			try{

				TBankHana::getInstance()->addAccountMinus( number );
			}
			catch( const TException & ex ){
			
				cout << ex.what() << endl;
			}
		}
		break;

		case '3':
		{
			string number;

			cout << "계좌번호입력: ";
			cin >> number;

			try{

				TBankHana::getInstance()->addCreditCard( number );
			}
			catch( const TException & ex ){
			
				cout << ex.what() << endl;
			}
		}
		break;

		case '4':
		{
			string number;

			cout << "계좌번호입력: ";
			cin >> number;

			try{

				TBankHana::getInstance()->removeAccount( number );
			}
			catch( const TException & ex ){
			
				cout << ex.what() << endl;
			}
		}
		break;

		case '5':
		{
			string	number;
			int		money;

			cout << "계좌번호입력: ";
			cin >> number;

			cout << "입금액입력: ";
			cin >> money;

			try{

				TBankHana::getInstance()->save( number, money );
			}
			catch( const TException & ex ){
			
				cout << ex.what() << endl;
			}
		}
		break;

		case '6':
		{
			string	number;
			int		money;

			cout << "계좌번호입력: ";
			cin >> number;

			cout << "출금액입력: ";
			cin >> money;

			try{

				TBankHana::getInstance()->withdraw( number, money );
			}
			catch( const TException & ex ){
			
				cout << ex.what() << endl;
			}
		}
		break;

		case '7':
		{
			string number;

			cout << "계좌번호입력: ";
			cin >> number;

			try{

				int		balance		= TBankHana::getInstance()->getBalance( number );
				string	lastTime	= TBankHana::getInstance()->getLastTime( number );

				cout << "잔고: " << balance << " 원, 마지막 거래일: " << lastTime << endl;
			}
			catch( const TException & ex ){
			
				cout << ex.what() << endl;
			}
		}
		break;

		case 'q':
		{
			string number;

			cout << "계좌번호입력: ";
			cin >> number;

			try{

				TBankKukmin::getInstance()->addAccountOrdinary( number );
			}
			catch( const TException & ex ){
			
				cout << ex.what() << endl;
			}
		}
		break;

		case 'w':
		{
			string number;

			cout << "계좌번호입력: ";
			cin >> number;

			try{

				TBankKukmin::getInstance()->addAccountMinus( number );
			}
			catch( const TException & ex ){
			
				cout << ex.what() << endl;
			}
		}
		break;

		case 'e':
		{
			string number;

			cout << "계좌번호입력: ";
			cin >> number;

			try{

				TBankKukmin::getInstance()->addCreditCard( number );
			}
			catch( const TException & ex ){
			
				cout << ex.what() << endl;
			}
		}
		break;

		case 'r':
		{
			string number;

			cout << "계좌번호입력: ";
			cin >> number;

			try{

				TBankKukmin::getInstance()->removeAccount( number );
			}
			catch( const TException & ex ){
			
				cout << ex.what() << endl;
			}
		}
		break;

		case 't':
		{
			string	number;
			int		money;

			cout << "계좌번호입력: ";
			cin >> number;

			cout << "입금액입력: ";
			cin >> money;

			try{

				TBankKukmin::getInstance()->save( number, money );
			}
			catch( const TException & ex ){
			
				cout << ex.what() << endl;
			}
		}
		break;

		case 'y':
		{
			string	number;
			int		money;

			cout << "계좌번호입력: ";
			cin >> number;

			cout << "출금액입력: ";
			cin >> money;

			try{

				TBankKukmin::getInstance()->withdraw( number, money );
			}
			catch( const TException & ex ){
			
				cout << ex.what() << endl;
			}
		}
		break;

		case 'u':
		{
			string number;

			cout << "계좌번호입력: ";
			cin >> number;

			try{

				int		balance		= TBankKukmin::getInstance()->getBalance( number );
				string	lastTime	= TBankKukmin::getInstance()->getLastTime( number );

				cout << "잔고: " << balance << " 원, 마지막 거래일: " << lastTime << endl;
			}
			catch( const TException & ex ){
			
				cout << ex.what() << endl;
			}
		}
		break;
		
		case 'a':
		{
			cout << "내 계좌 개수: " << TAccount< int >::getCount() << endl;
		}
		break;

		case 's':
		{
			runCalculator();
		}
		break;

		case 'd':
		{
			exitCalculator();
		}
		break;

		case 'f':
		{
			return false;
		}
		break;
	}

	cout << endl;
	
	return true;
}

int main(){

	init();
	while( loop() );
	fin();

	return 0;
}
