#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.h"
#include "NormalAccount.h"
#include "String.h"



class HighCreditAccount : public Account
{
private:
	char high_level_name[LEVEL_LEN];
	double high_level_def_ratio; //기본 이자
	double High_ratio;	//추가 이자
	int high_cnt_input;
	int high_state_high;

public:

	//생성자?
	HighCreditAccount(int acc_id, const String cusName, const char* level_rank );

	
	void High_level_name_return();
	

	double High_level_ratio_return();
	

	double High_plus_ratio_return();

	int high_acc_return();


	//최초입금인지 아닌지 알려주는 함수
	int check_high_cnt();

	//cnt를 증가시키는 함수
	void plus_high_cnt();


	


};



#endif // !__BANK_H__
