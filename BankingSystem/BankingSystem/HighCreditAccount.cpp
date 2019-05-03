#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.h"
#include "HighCreditAccount.h"
#include "String.h"


char A[8] = { "A���" };
char B[8] = { "B���" };
char C[8] = { "C���" };


char High_Level[LEVEL_LEN] = { "�ſ�ŷڰ���" };



HighCreditAccount::HighCreditAccount(int acc_id, const String cusName, const char* level_rank)
	:Account(acc_id, cusName), High_ratio(0.0), high_state_high(0)
{
	int len = strlen(High_Level) + 1;
	strcpy_s(high_level_name, len, High_Level);

	high_level_def_ratio = High_Level_ratio;

	high_cnt_input = 0;
	high_state_high = 2;

	if (strcmp(level_rank, A) == 0)
	{
		High_ratio = LEVEL_A * 0.01;
		return;
	}

	else if (strcmp(level_rank, B) == 0)
	{
		High_ratio = LEVEL_B * 0.01;
		return;
	}

	else if (strcmp(level_rank, C) == 0)
	{
		High_ratio = LEVEL_C * 0.01;
		return;
	}

}

	void HighCreditAccount::High_level_name_return() //�������� ����
	{
		cout << high_level_name;
	}

	double HighCreditAccount::High_level_ratio_return() //�⺻ ����
	{
		return high_level_def_ratio;
	}

	double HighCreditAccount::High_plus_ratio_return() //�߰� ����
	{
		return High_ratio;
	}

	int HighCreditAccount::high_acc_return()
	{
		
		return high_state_high; // �ſ���� = 2 ��ȯ
	}

	int HighCreditAccount::check_high_cnt()
	{
		return high_cnt_input;
	}

	void HighCreditAccount::plus_high_cnt()
	{
		high_cnt_input++;
	}



	

	


	
