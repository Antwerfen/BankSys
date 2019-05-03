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
	double high_level_def_ratio; //�⺻ ����
	double High_ratio;	//�߰� ����
	int high_cnt_input;
	int high_state_high;

public:

	//������?
	HighCreditAccount(int acc_id, const String cusName, const char* level_rank );

	
	void High_level_name_return();
	

	double High_level_ratio_return();
	

	double High_plus_ratio_return();

	int high_acc_return();


	//�����Ա����� �ƴ��� �˷��ִ� �Լ�
	int check_high_cnt();

	//cnt�� ������Ű�� �Լ�
	void plus_high_cnt();


	


};



#endif // !__BANK_H__
