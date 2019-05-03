#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "MiniBankingCommonDecl.h"
#include "String.h"
#include "error_cluster.h"




class Account
{
private:
	int accID;
	int balance;
	String cusName;

public:

	Account();
	
	//생성자
	Account(int input_accID, const String input_cusName);
	
	//복사
	Account(Account& copy);

	
	//계좌번호검색
	int Search_accID()const;

	//최초잔액 설정용
	int def_balance()const;
	
	//계좌번호 송출
	int accID_return()const;
	//잔액 송출
	int balance_return()const;
	//이름 송출
	void name_return()const;

	//돈 넣기
	void input_money(int input_money);

	//돈 빼기
	int output_money(int output_money);

	
	
	virtual void level_return() ;
	
	virtual double level_ratio_return();
	
	virtual void High_level_name_return();

	virtual double High_level_ratio_return();

	virtual double High_plus_ratio_return();

	virtual int high_acc_return();//신용게좌임을 알려주는 함수

	virtual int normal_acc_return();//보통계좌임을 알려주는 함수

	virtual int check_normal_cnt();//보통계좌의 최초입금 여부를 알려주는 함수

	virtual int check_high_cnt();//신용계좌의 최초입금 여부를 알려주는 함수
	
	virtual void plus_normal_cnt();//보통계좌의 cnt를 늘리는 함수

	virtual void plus_high_cnt();

	


	
};

#endif // !__BANK_H__

