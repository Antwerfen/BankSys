#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "MiniBankingCommonDecl.h"
#include"ACCOUNT.h"
#include "screenOutMenu.h"
#include "Account_template.h"
#include"Account_template.cpp"


typedef Account* Account_ptr;

class AccountHandler
{
private:
	Account_template<Account_ptr> accList;
	int accNum;


	AccountHandler(const AccountHandler& arrPtr) {}

	AccountHandler& operator=(const AccountHandler& arrPtr) {}


public:
	//생성자
	AccountHandler();


	//AccountHandler(int accNum);

	Account_ptr& operator[](int idx);

	Account_ptr operator[](int idx) const;

	//소멸자?
	~AccountHandler();


	//계좌 만들기
	void make_account(int num);



	//입금하기
	void deposit_money();

	//accid의 위치찾고 돈 넣고 위치 반환
	int accID_idx(int input_accID, int input_money);

	//출금하기
	void withdraw_money();

	//실질적으로 출금하는 함수
	int real_withdraw_money(int output_accID, int output_money);

	//한 계좌 조회
	void inquire_account();

	//전체 계좌 조회
	void show_all();


	//계좌만들기에선 중복체크, 다른데선 있나 없나 체크하는 것
	bool search_accID(int input_accID);


	//나와라 정보(계좌 생성용)
	void screenout(int cheker);


	//나와라 정보(한 계좌 생성용)
	int inqire_screenout(int input_accid);

	//출금 입금용 나와라 정보
	void other_screenout(int idx);

	//전체 계좌조회용 나와라 정보
	void show_all_screenout()const;

	//보통계좌냐 신용계좌냐
	void select_accCreate(void);

	//실험
	void AddAccount(Account_ptr* emp);

	//명수 리턴
	int accNum_return();

	Account* accList_return(int idx);

	//파일 읽는 함수
	void Read_data_file(void);

	//고객정보 다시 쓰는 함수
	void put_in_txt(void);

	//virtual int Show_create_result(Account *address, int checker,int acc);

};
#endif // !__ACCOUNT_H__

