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
	
	//������?
	NormalAccount(int acc_id,const String cusName);
	
	//~NormalAccount();
	//�������� ����
	void level_return();

	//�������� ����
	double level_ratio_return();

	//����������� �˷��ִ� �Լ�
	int normal_acc_return();

	//�����Ա����� �ƴ��� üũ�ϴ� �Լ�
	int check_normal_cnt();

	//�����Ա� ������ �Ǵ��ϴ� cnt_input�� �ø��� �Լ�
	void plus_normal_cnt();

};



#endif // !__BANK_H__
