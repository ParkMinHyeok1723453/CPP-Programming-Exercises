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

	cout << "�ϳ� 1������»��� 2���̳ʽ����»��� 3�ſ�ī����� 4�������� 5�Ա� 6��� 7�ܰ�" << endl;
	cout << "���� q������»��� w���̳ʽ����»��� e�ſ�ī����� r�������� t�Ա� y��� u�ܰ�" << endl;
	cout << "�Ϲ� a���¼�Ȯ�� s�����ѱ� d������� f����" << endl;

	fflush( stdin );
	switch( getchar() ){
		case '1':
		{
			string number;

			cout << "���¹�ȣ�Է�: ";
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

			cout << "���¹�ȣ�Է�: ";
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

			cout << "���¹�ȣ�Է�: ";
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

			cout << "���¹�ȣ�Է�: ";
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

			cout << "���¹�ȣ�Է�: ";
			cin >> number;

			cout << "�Աݾ��Է�: ";
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

			cout << "���¹�ȣ�Է�: ";
			cin >> number;

			cout << "��ݾ��Է�: ";
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

			cout << "���¹�ȣ�Է�: ";
			cin >> number;

			try{

				int		balance		= TBankHana::getInstance()->getBalance( number );
				string	lastTime	= TBankHana::getInstance()->getLastTime( number );

				cout << "�ܰ�: " << balance << " ��, ������ �ŷ���: " << lastTime << endl;
			}
			catch( const TException & ex ){
			
				cout << ex.what() << endl;
			}
		}
		break;

		case 'q':
		{
			string number;

			cout << "���¹�ȣ�Է�: ";
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

			cout << "���¹�ȣ�Է�: ";
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

			cout << "���¹�ȣ�Է�: ";
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

			cout << "���¹�ȣ�Է�: ";
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

			cout << "���¹�ȣ�Է�: ";
			cin >> number;

			cout << "�Աݾ��Է�: ";
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

			cout << "���¹�ȣ�Է�: ";
			cin >> number;

			cout << "��ݾ��Է�: ";
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

			cout << "���¹�ȣ�Է�: ";
			cin >> number;

			try{

				int		balance		= TBankKukmin::getInstance()->getBalance( number );
				string	lastTime	= TBankKukmin::getInstance()->getLastTime( number );

				cout << "�ܰ�: " << balance << " ��, ������ �ŷ���: " << lastTime << endl;
			}
			catch( const TException & ex ){
			
				cout << ex.what() << endl;
			}
		}
		break;
		
		case 'a':
		{
			cout << "�� ���� ����: " << TAccount< int >::getCount() << endl;
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
