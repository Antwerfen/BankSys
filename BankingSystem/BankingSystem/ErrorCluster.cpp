#include "MiniBankingCommonDecl.h"
#include "ErrorCluster.h"


Input_error::Input_error(int in_money)
	:insult_money(in_money)
{
}

void Input_error::Show_reason(void)
{
	cout << "잘못된 입력입니다. 다시 시도하여 주시기 바랍니다." << endl << endl;
}



Output_error::Output_error(int out_money)
	:output_money(out_money)
{
}



void Output_error::Show_reason(void)
{
	cout << "통장에 잔고가 없거나 잘못된 입력입니다." << endl;
	cout << "다시 시도하여 주시기 바랍니다."<< endl;

}



Space_error::Space_error(int is_there_any_sapce)
	:acc_space(is_there_any_sapce)
{
}

void Space_error::Show_reason(void)
{
	cout << "더 이상의 공간이 없습니다. 관리자에게 문의해주십시오." << endl << endl;
}


