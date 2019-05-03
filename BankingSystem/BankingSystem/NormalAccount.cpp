#include "MiniBankingCommonDecl.h"
#include "NormalAccount.h"
#include "ACCOUNT.h"
#include "String.h"


char Normal_Level[LEVEL_LEN] = { "보통예금계좌" };



NormalAccount::NormalAccount(int acc_id, const String in_cusName)
	:Account(acc_id,in_cusName), normal_level_ratio(0.0),normal_state_normal(0)
{
	int len = strlen(Normal_Level) + 1;
	strcpy_s(normal_level_name, len, Normal_Level);
	normal_level_ratio = Level_ratio;
	//돈은 bank만들 때 이미 0으로 해주니까 필요가 없으려나?
	normal_cnt_input = 0;
	normal_state_normal = 1;
}

void NormalAccount::level_return()
{
	cout << normal_level_name;
}

double NormalAccount::level_ratio_return()
{
	return normal_level_ratio;
}

int NormalAccount::normal_acc_return()
{
	return normal_state_normal;
}

int NormalAccount::check_normal_cnt()
{
	return normal_cnt_input;
}

void NormalAccount::plus_normal_cnt()
{
	normal_cnt_input++;
}



