#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "MiniBankingCommonDecl.h"
#include "String.h"





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
	
	//불러오기용 생성자
	Account(int input_accID, const String input_cusName, int input_balance);

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
	String name_return()const;

	//돈 넣기
	void input_money(int input_money);

	//돈 빼기
	int output_money(int output_money);

	
	
	virtual String level_return() ; //보통예금을 나타내는 숫자 리턴
	
	virtual double level_ratio_return();	//보통예금의 이자 리턴
	
	virtual String High_level_name_return();	//보통예금이라는 이름을 리턴

	virtual double High_level_ratio_return();	//신용계좌 기본 이자 리턴

	virtual double High_plus_ratio_return();	//신용계좌 추가 이자 리턴

	virtual int high_acc_return();//신용계좌임을 알려주는 함수

	virtual int normal_acc_return();//보통계좌임을 알려주는 함수

	virtual int check_normal_cnt();//보통계좌의 최초입금 여부를 알려주는 함수

	virtual int check_high_cnt();//신용계좌의 최초입금 여부를 알려주는 함수
	
	virtual void plus_normal_cnt();//보통계좌의 cnt를 늘리는 함수

	virtual void plus_high_cnt();	//신용계좌의 cnt를 늘리는 함수

	


	
};

#endif // !__BANK_H__

