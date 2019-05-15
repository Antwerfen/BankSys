#include "MiniBankingCommonDecl.h"
#include "AccountHandler.h"
#include "screenOutMenu.h"



//초기 메뉴
void ShowMenu(void)
{
	cout << "======Menu======" << endl;
	cout << "  1. 계좌개설" << endl;
	cout << "  2. 입    금" << endl;
	cout << "  3. 출    금" << endl;
	cout << "  4. 계좌조회" << endl;
	cout << "  5. 전체조회" << endl;
	cout << "  6. 종    료" << endl;
	cout << "================" << endl;

}
//계좌개설 메뉴
void ShowAccMakeMenu(void)
{
	cout << "======Menu======" << endl;
	cout << "  1. 보통예금계좌 개설" << endl;
	cout << "  2. 신용신뢰계좌 개설" << endl;
	cout << "  3. 처음으로 돌아가기" << endl;
	cout << "================" << endl;
}



/*
int Show_create_result(Account *address,int checker,int acc)
{
	//int idx = address->accNum_return() - 1;
	
	
}
*/


/*
int r_show::Show_create_result(Account* address, int checker, int acc)
{
	if (address->normal_acc_return() == 1)

	{
		cout << " 입력하신 정보를 확인하시기 바랍니다." << endl;
		cout << "====================================" << endl;
		cout << "	계좌번호 : " << address->accID_return() << endl;
		cout << "	계좌종류 : " << address->level_return(); cout << endl;
		cout << "	예금이자 : " << address->level_ratio_return() << "%" << endl;
		cout << "	잔    액 : " << address->balance_return() << "원" << endl;
		cout << "	고객성명 : " << address->name_return(); cout << "님" << endl;
		cout << "====================================" << endl;
		return 0;
	}


	else if (address->high_acc_return() == 2)
	{
		cout << " 입력하신 정보를 확인하시기 바랍니다." << endl;
		cout << "====================================" << endl;
		cout << "	계좌번호 : " << address->accID_return() << endl;
		cout << "	계좌종류 : " << address->High_level_name_return(); cout << ' ' << endl;
		cout << "	예금이자 : " << address->High_level_ratio_return() << "%" << endl;
		cout << "	추가이자 : " << address->High_plus_ratio_return() << "%" << endl;
		cout << "	잔    액 : " << address->balance_return() << "원" << endl;
		cout << "	고객성명 : " << address->name_return(); cout << "님" << endl;
		cout << "====================================" << endl;
		return 0;
	}

	return 0;
}
*/
