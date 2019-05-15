#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.h"
#include "String.h"



class NormalAccount : public Account
{
private:
	char normal_level_name[LEVEL_LEN];
	double normal_level_ratio;
	int normal_cnt_input;
	int normal_state_normal;
public:
	
	//생성자?
	NormalAccount(int acc_id,const String cusName);
	
	//acc_num ,acc_ID, r_balance, cus_name, normal_name, normal_ratio, cnt
	NormalAccount(int level_sepa, int acc_num, int acc_ID, int r_balance, const char* cus_name,
		const char* normal_name, double normal_ratio, int cnt);

	//~NormalAccount();
	//계좌종류 리턴
	String level_return();

	//예금이자 리턴
	double level_ratio_return();

	//보통계좌임을 알려주는 함수
	int normal_acc_return();

	//최초입금인지 아닌지 체크하는 함수
	int check_normal_cnt();

	//최초입금 유무를 판단하는 cnt_input을 늘리는 함수
	void plus_normal_cnt();

};



#endif // !__BANK_H__
