#include "MiniBankingCommonDecl.h"
#include "error_cluster.h"
#include "Account.h"
#include "AccountHandler.h"

void Output_error::Show_reason(void)
{
	cout << " 통장에 잔고가 없거나 잘못된 입력입니다. 센세" << endl << endl;
}

void Space_error::Show_reason(void)
{
	cout << "더 이상의 공간이 없습니다. 센세" << endl << endl;
}


void Input_error::Show_reason(void)
{
	cout << "잘못된 입력입니다. 센세" << endl << endl;
}
