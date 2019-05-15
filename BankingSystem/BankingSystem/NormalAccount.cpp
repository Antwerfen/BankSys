#include "MiniBankingCommonDecl.h"
#include "NormalAccount.h"
#include "ACCOUNT.h"
#include "String.h"


char Normal_Level[LEVEL_LEN] = { "보통예금계좌" };


//기본적인 생성자
NormalAccount::NormalAccount(int acc_id, const String in_cusName)
	:Account(acc_id,in_cusName), normal_level_ratio(Level_ratio),
	normal_cnt_input(0),normal_state_normal(1)
{
	int len = strlen(Normal_Level) + 1;
	strcpy_s(normal_level_name, len, Normal_Level);
	//normal_level_ratio = Level_ratio;
	//돈은 bank만들 때 이미 0으로 해주니까 필요가 없으려나?
	//normal_cnt_input = 0;
	//normal_state_normal = 1;
}

//복구를 위한 생성자
NormalAccount::NormalAccount(int level_sepa, int acc_num, int acc_ID, 
	int r_balance, const char* cus_name, const char* normal_name, double normal_ratio, int cnt)
	:Account(acc_ID, cus_name, r_balance), normal_level_ratio(normal_ratio),
	normal_cnt_input(cnt),normal_state_normal(level_sepa)
{
	int len = strlen(normal_name) + 1;
	strcpy_s(normal_level_name, len, normal_name);
}

//보통계좌라는 글을 리턴
String NormalAccount::level_return()
{
	return normal_level_name;
}

//보통계좌이율을 리턴
double NormalAccount::level_ratio_return()
{
	return normal_level_ratio;
}

//보통계좌임을 나타내는 숫자 리턴
int NormalAccount::normal_acc_return()
{
	return normal_state_normal;
}

//최초입금여부 확인을 위한 cnt 리턴
int NormalAccount::check_normal_cnt()
{
	return normal_cnt_input;
}

//cnt를 증가시키는 함수
void NormalAccount::plus_normal_cnt()
{
	normal_cnt_input++;
}



