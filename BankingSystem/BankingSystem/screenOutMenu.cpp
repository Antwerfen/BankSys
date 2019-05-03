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


void Show_create_acc_result(int checker)
{
	AccountHandler test;
	int idx = test.accNum_return() -1 ;
	
	switch (checker)
	{
	case 1:
		cout << " 입력하신 정보를 확인하시기 바랍니다." << endl;
		cout << "====================================" << endl;
		cout << "	계좌번호 : " << test.accList_return(idx)->accID_return() << endl;
		cout << "	계좌종류 : ";
		test.accList_return(idx)->level_return(); cout << endl;
		cout << "	예금이자 : " << test.accList_return(idx)->level_ratio_return() << "%" << endl;
		cout << "	잔    액 : " << test.accList_return(idx)->balance_return() << "원" << endl;
		cout << "	고객성명 : ";
		test.accList_return(idx)->name_return(); cout << "님" << endl;
		cout << "====================================" << endl;
		break;

	case 2:
		cout << " 입력하신 정보를 확인하시기 바랍니다." << endl;
		cout << "====================================" << endl;
		cout << "	계좌번호 : " << test.accList_return(idx)->accID_return() << endl;
		cout << "	계좌종류 : ";
		test.accList_return(idx)->High_level_name_return(); cout << ' ' << endl;
		cout << "	예금이자 : " << test.accList_return(idx)->High_level_ratio_return() << endl;
		cout << "	추가이자 : " << test.accList_return(idx)->High_plus_ratio_return() << endl;
		cout << "	잔    액 : " << test.accList_return(idx)->balance_return() << "원" << endl;
		cout << "	고객성명 : ";
		test.accList_return(idx)->name_return(); cout << "님" << endl;
		cout << "====================================" << endl;
		break;

	default:
		cout << "언제나 함께하는 xx은행" << endl;
		break;
	}

}


