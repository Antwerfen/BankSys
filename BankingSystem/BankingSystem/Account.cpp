#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.h"
#include "NormalAccount.h"
#include "String.h"
#include "ErrorCluster.h"

//취업면접비법
//돈 불러오는 걸로 초기화 시키는거 만들어야겠다.
Account::Account(int input_accID, const String input_cusName)
	:accID(input_accID), balance(0)
{
	cusName = input_cusName;
}

Account::Account(int input_accID, const String input_cusName, int input_balance)
	:accID(input_accID),cusName(input_cusName), balance(input_balance)
{
	//^ ㅇ^/
}



//복사
Account::Account(Account& copy)
{
	accID = copy.accID;
	balance = copy.balance;
	cusName = copy.cusName;
}


//계좌번호 검색
int Account::Search_accID()const
{
	return accID;
}

//계좌번호 송출
int Account::accID_return() const
{
	
	return accID;
}

//잔액 송출
int Account::balance_return() const
{
	return balance;
}

//최초잔액 설정용
int Account::def_balance()const
{
	return 0;
}

//이름 송출
String Account::name_return() const
{
	return cusName;
}

//돈 넣기
void Account::input_money(int input_money)
{

	balance = balance + input_money;
}

//돈 빼기
int Account::output_money(int output_money)
{
	int t;
	if (balance < output_money)
	{
		t = 1;
		Output_error expn(output_money);
		throw expn;

		//cout << "잔액보다 출금하려는 액수가 더 큽니다." << endl<<endl;
		//return -1;
	}
	else
	{
		balance = balance - output_money;
		cout << "계좌에서 " << output_money << "원을 출금하였습니다." << endl<<endl;
		return 1;
	}
}


//--------------------보통예금이라는 이름을 리턴
String Account::level_return()
{
	return 0;
}


//-------------------보통예금의 이자 리턴
double Account::level_ratio_return()
{
	return 0.0;
}


//-------------------신용예금이라는 이름을 리턴
String Account::High_level_name_return()
{
	return 0;
}

//------------------신용예금의 기초 이자 리턴
double Account::High_level_ratio_return()
{
	return 0.0;
}


//-------------------신용예금의 추가 이자 리턴
double Account::High_plus_ratio_return()
{
	return 0.0;
}


//-----------------------------보통계좌라는 것을 알리는 함수
int Account::normal_acc_return()
{
	return 0;
}


//---------------------------------신용계좌라는 것을 알리는 함수
int  Account::high_acc_return()
{
	return 0;
}

//-----------------보통 계좌가 최초입금인지 아닌지
int Account::check_normal_cnt()
{
	return 0;
}


//-----------------------------------신용계좌가 최초입금인지 아닌지
int Account::check_high_cnt()
{
	return 0;
}


//----------------------------------보통 계좌를 최초입금에서 벗어나게하는 함수
void Account::plus_normal_cnt()
{
	
}


//---------------------------------신용계좌를 최초입금에서 벗어나게하는 함수
void Account::plus_high_cnt()
{
	
}






