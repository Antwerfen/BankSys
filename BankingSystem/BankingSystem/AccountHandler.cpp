#include "MiniBankingCommonDecl.h"
#include "AccountHandler.h"
#include "etc.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"
#include "screenOutMenu.h"



//생성자?
//AccountHandler::AccountHandler()
//	:accNum(0)
//{}

AccountHandler::AccountHandler()
	:accNum(0)
{
	accList = new Account_ptr[MAX_ACC];
}

//소멸자
AccountHandler::~AccountHandler()
{
	//for (int i = 0; i < accNum; i++)
	//{
		delete []accList;
	//}
}

Account_ptr& AccountHandler::operator[](int idx)
{
	if (idx < 0 || idx >= MAX_ACC)
	{
		cout << "배열의 범위를 벗어났습니다." << endl;
		exit(1);
	}

	return accList[idx];
}

Account_ptr& AccountHandler::operator[](int idx) const
{
	if (idx < 0 || idx >= MAX_ACC)
	{
		cout << "배열의 범위를 벗어났습니까?" << endl;
		exit(1);
	}

	return accList[idx];
}




//계좌 만들기
void AccountHandler::make_account(int num)
{
	
	int def_id;
	String cus_name;
	int account_cheker = -1;

	switch (accNum)
	{
	case 100:
		cout << "더 이상의 계좌는 만들 수 없습니다." << endl;
		break;

	default:

		cout << "1.계좌개설" << endl;
		cout << "계좌 입력 : ";
		cin >> def_id;

		//있는거냐 없는거냐 검색
		if(search_accID(def_id))
		{
			cout << "이미 존재하는 계좌입니다." << endl;
			return;
		}
		
		
		cout << "성명 입력 : ";
		cin >> cus_name;
		

		//실질적으로 계좌를 만드는 부분
		switch (num)
		{
		case 1://노말
			
			cout << "1.보통예금계좌생성" << endl;
			//NormalAccount* normal;
			//normal = new NormalAccount(def_id, cus_name);
			
			accList[accNum] = new NormalAccount(def_id, cus_name);
			//AddAccount(normal);
			cout << ' ' << endl << endl;
			account_cheker = 1;
			accNum++;
			break;

			
		
		case 2://신용
			char level_rank[10];

			cout << ' ' << endl;
			cout << "2.신용신뢰계좌생성" << endl;

			cout << "안내받은 고객님의 신용등급을 입력해주세요." << endl;
			cout << "예) A등급, B등급, C등급 등등" << endl << endl;
			cout << "주의 : 고객님의 부주의로 인해 잘못된 신용등급을 입력하여"
				<< "발생하는 불이익의 경우 책임지지 않습니다." << endl;
			

			cin >> level_rank;


			//HighCreditAccount* high;
			//high = new HighCreditAccount(def_id, cus_name, level_rank);
			
			accList[accNum] = new HighCreditAccount(def_id, cus_name, level_rank);
			//AddAccount(high);
			//accList[accNum++] = new HighCreditAccount(def_id,cus_name,level_rank);
			cout << ' ' << endl << endl;
			account_cheker = 2;
			accNum++;
			break;
		
		default://뷁
			cout << "알 수 없는 오류가 발생했습니다." << endl << endl;
			break;
		}
		//정보출력하는부분
		screenout(account_cheker);
		//Show_create_acc_result(accNum);
		
		break;
	}

	return;
}


/*===================입금 ===========================*/
//입금하기
void AccountHandler::deposit_money()
{
	switch (accNum)
	{
	case 0:
		cout << "현재 입력된 정보 0" << endl;
		break;

	default:

		int input_accID;
		int input_money;
		int idx;

		cout << "2.입금" << endl;
		cout << "입금하려는 계좌번호를 입력하세요 ";
		cin >> input_accID;

		if (!search_accID(input_accID))
		{
			cout << "해당 계좌번호는 없습니다." << endl;
			return;
		}

		cout << "얼마를 입금하시겠습니까? ";
		cin >> input_money;
		cout << ' ' << endl << endl;
		
		if (input_money <= 0)
		{
			cout << "잘못된 입력입니다." << endl;
			return;
		}

		//실제로 돈 넣는 함수
		idx = accID_idx(input_accID, input_money);

		//정보출력
		other_screenout(idx);
		break;
	}

}


//accid 위치 찾고 돈 넣기
int AccountHandler::accID_idx(int input_accid, int input_money)
{

	for (int i = 0; i < accNum; i++)
	{
		if (input_accid == accList[i]->Search_accID())
		{
			if (accList[i]->normal_acc_return() == 1) //보통계좌
			{
				double plus_ratio;

				if (accList[i]->check_normal_cnt() > 0)
				{
					plus_ratio = (1.0 + Level_ratio) * input_money;
					accList[i]->input_money(plus_ratio * 1);
					accList[i]->plus_normal_cnt();
					return i;
				}

				else
				{
					accList[i]->input_money(input_money);
					accList[i]->plus_normal_cnt();
					return i;
				}
			}

			else if (accList[i]->high_acc_return() == 2)//신용계좌
			{
				double plus_plus_ratio;

				if (accList[i]->check_high_cnt() > 0)
				{
					plus_plus_ratio = (input_money * (1.0 + Level_ratio) * (1.0 + accList[i]->High_plus_ratio_return()));
					accList[i]->input_money(plus_plus_ratio * 1);
					accList[i]->plus_high_cnt();
					return i;
				}

				else
				{
					accList[i]->input_money(input_money);
					accList[i]->plus_high_cnt();
					return i;
				}

			}


		}

	}
	return -1;
}


/*===================출금 ===========================*/
//출금하기
void AccountHandler::withdraw_money()
{
	switch (accNum)
	{
	case 0:
		cout << "현재 입력된 정보 0" << endl;
		break;

	default:

		int output_accID;
		int output_money;
		int idx;

		cout << "3.출금" << endl;
		cout << "출금하려는 계좌번호를 입력하세요 ";
		cin >> output_accID;

		if (!search_accID(output_accID))
		{
			cout << "해당 계좌번호는 없습니다." << endl;
			return;
		}

		cout << "얼마를 출금하시겠습니까? ";
		cin >> output_money;
		cout << ' ' << endl << endl;

		if (output_money <= 0)
		{
			cout << "잘못된 입력입니다." << endl;
			return;
		}

		//실제로 돈 넣는 함수
		idx = real_withdraw_money(output_accID, output_money);

		
		//정보출력
		other_screenout(idx);
		break;
	}

}

//accid 위치 찾고 돈 빼고 위치 반환
int AccountHandler::real_withdraw_money(int output_accid, int output_money)
{
	for (int i = 0; i < accNum; i++)
	{
		if (output_accid == accList[i]->Search_accID())
		{
			if (accList[i]->output_money(output_money)>=0)
				return i;

			else
				return -1;
		}
	}
	return -1;
}

/*=============================  yes or no ===========================*/

//계좌 존재 유무검색
bool AccountHandler::search_accID(int input_accID)
{

	for (int i = 0; i < accNum; i++)
	{
		if (input_accID == accList[i]->Search_accID())
		{
			
			return true;
		}
	}
	return false;
}

//보통 계좌냐 신용계좌냐
void AccountHandler::select_accCreate(void)
{
	int antwerpen;

	switch (antwerpen = input_choice())
	{
	case NORMAL:
		cout << "1.보통예금계좌생성" << endl;
		make_account(antwerpen);
		break;

	case CREDIT:
		cout << "2.신용신뢰계좌생성" << endl;
		make_account(antwerpen);
		break;

	case GOBACK:
		cout << "처음 화면으로 돌아갑니다." << endl;
		break;

	default:
		cout << "잘못된 입력입니다." << endl;
		break;
	}

}




/*===========================================계좌 조회 구역 ===========================================*/

//한 계좌 정보검색
void AccountHandler::inquire_account()
{
	switch (accNum)
	{
	case 0:
		cout << "현재 입력된 정보 0" << endl;
		break;

	default:

		int input_accID;
		//int input_money;
		//int idx;

		cout << "4.계좌조회" << endl;
		cout << "조회하려는 계좌번호를 입력하세요 ";
		cin >> input_accID;
		cout << ' ' << endl;

		if (!search_accID(input_accID))
		{
			cout << "해당 계좌번호는 없습니다." << endl;
			return;
		}

		//search_accID를 int형으로 고치면 더 나을 것 같다.
		//idx = 
		inqire_screenout(input_accID);

		//정보출력
		
		break;
	}
}

//전체 계좌 조회 메뉴
void AccountHandler::show_all()
{
	int input_pass;

cout << "비밀번호를 입력하십시오. ";
cin >> input_pass;
cout << ' ' << endl << endl;

switch (input_pass)
{
case PASS_WORD:
{
	switch (accNum)
	{
	case 0:
		cout << "조회할 정보가 없습니다." << endl;
		break;

	default:
		show_all_screenout();

		break;
	}
	break;
}
default:
	cout << "권한이 없는 사람은 조회할 수 없습니다." << endl;
	break;
}
}

//나와라 정보(계좌생성용)
void AccountHandler::screenout(int cheker)
{
	int idx = accNum - 1;

	switch (cheker)
	{
	case 1:
		cout << " 입력하신 정보를 확인하시기 바랍니다." << endl;
		cout << "====================================" << endl;
		cout << "	계좌번호 : " << accList[idx]->accID_return() << endl;
		cout << "	계좌종류 : ";
		accList[idx]->level_return(); cout << endl;
		cout << "	예금이자 : " << accList[idx]->level_ratio_return() << "%" << endl;
		cout << "	잔    액 : " << accList[idx]->balance_return() << "원" << endl;
		cout << "	고객성명 : ";
		accList[idx]->name_return(); cout << "님" << endl;
		cout << "====================================" << endl;
		break;

	case 2:
		cout << " 입력하신 정보를 확인하시기 바랍니다." << endl;
		cout << "====================================" << endl;
		cout << "	계좌번호 : " << accList[idx]->accID_return() << endl;
		cout << "	계좌종류 : ";
		accList[idx]->High_level_name_return(); cout << ' ' << endl;
		cout << "	예금이자 : " << accList[idx]->High_level_ratio_return() << endl;
		cout << "	추가이자 : " << accList[idx]->High_plus_ratio_return() << endl;
		cout << "	잔    액 : " << accList[idx]->balance_return() << "원" << endl;
		cout << "	고객성명 : ";
		accList[idx]->name_return(); cout << "님" << endl;
		cout << "====================================" << endl;
		break;

	default:
		cout << "언제나 함께하는 xx은행" << endl;
		break;
	}
}

//나와라 정보(한 계좌 정보검색용)
int AccountHandler::inqire_screenout(int input_accid)
{
	
	for (int idx = 0; idx < accNum; idx++)
	{
		if (input_accid == accList[idx]->Search_accID())
		{
			if (accList[idx]->normal_acc_return() == 1)
			{
				cout << " 입력하신 정보를 확인하시기 바랍니다." << endl;
				cout << "====================================" << endl;
				cout << "	계좌번호 : " << accList[idx]->accID_return() << endl;
				cout << "	계좌종류 : ";
				accList[idx]->level_return(); cout << endl;
				cout << "	예금이자 : " << accList[idx]->level_ratio_return() << "%" << endl;
				cout << "	잔    액 : " << accList[idx]->balance_return() << "원" << endl;
				cout << "	고객성명 : ";
				accList[idx]->name_return(); cout << "님" << endl;
				cout << "====================================" << endl;
				return 1;
			}


			else if (accList[idx]->high_acc_return() == 2)
			{
				cout << " 입력하신 정보를 확인하시기 바랍니다." << endl;
				cout << "====================================" << endl;
				cout << "	계좌번호 : " << accList[idx]->accID_return() << endl;
				cout << "	계좌종류 : ";
				accList[idx]->High_level_name_return(); cout << ' ' << endl;
				cout << "	예금이자 : " << accList[idx]->High_level_ratio_return() << endl;
				cout << "	추가이자 : " << accList[idx]->High_plus_ratio_return() << endl;
				cout << "	잔    액 : " << accList[idx]->balance_return() << "원" << endl;
				cout << "	고객성명 : ";
				accList[idx]->name_return(); cout << "님" << endl;
				cout << "====================================" << endl;
				return 2;
			}

			else
			{
				cout << "언제나 함께하는 xx은행" << endl;
				return -1;
			}
		}
	}
}


//다른 부분 정보출력(입금,출금)
void AccountHandler::other_screenout(int idx)
{
	switch (idx)
	{
	case -1:
		cout << "언제나 함께하는 xx은행" << endl;
		break;

	default:
		
		if (accList[idx]->normal_acc_return() == 1)
		{
			cout << " 입력하신 정보를 확인하시기 바랍니다." << endl;
			cout << "====================================" << endl;
			cout << "	계좌번호 : " << accList[idx]->accID_return() << endl;
			cout << "	계좌종류 : ";
			accList[idx]->level_return(); cout << endl;
			cout << "	예금이자 : " << accList[idx]->level_ratio_return() << "%" << endl;
			cout << "	잔    액 : " << accList[idx]->balance_return() << "원" << endl;
			cout << "	고객성명 : ";
			accList[idx]->name_return(); cout << "님" << endl;
			cout << "====================================" << endl;
			return;
		}


		else if (accList[idx]->high_acc_return() == 2)
		{
			cout << " 입력하신 정보를 확인하시기 바랍니다." << endl;
			cout << "====================================" << endl;
			cout << "	계좌번호 : " << accList[idx]->accID_return() << endl;
			cout << "	계좌종류 : ";
			accList[idx]->High_level_name_return(); cout << ' ' << endl;
			cout << "	예금이자 : " << accList[idx]->High_level_ratio_return() << endl;
			cout << "	추가이자 : " << accList[idx]->High_plus_ratio_return() << endl;
			cout << "	잔    액 : " << accList[idx]->balance_return() << "원" << endl;
			cout << "	고객성명 : ";
			accList[idx]->name_return(); cout << "님" << endl;
			cout << "====================================" << endl;
			return;
		}
		break;
	}
	
}

//전체 계좌조회용 나와라 정보
void AccountHandler::show_all_screenout()const
{
	for (int idx = 0; idx < accNum; idx++)
	{
		if (accList[idx]->normal_acc_return() == 1)
		{
			cout <<idx+1<< "번째 정보" << endl;
			cout << "====================================" << endl;
			cout << "	계좌번호 : " << accList[idx]->accID_return() << endl;
			cout << "	계좌종류 : ";
			accList[idx]->level_return(); cout << endl;
			cout << "	예금이자 : " << accList[idx]->level_ratio_return() << "%" << endl;
			cout << "	잔    액 : " << accList[idx]->balance_return() << "원" << endl;
			cout << "	고객성명 : ";
			accList[idx]->name_return(); cout << "님" << endl;
			cout << "====================================" << endl << endl;
		}

		if (accList[idx]->high_acc_return() == 2)
		{
			cout << idx + 1 << "번째 정보" << endl;
			cout << "====================================" << endl;
			cout << "	계좌번호 : " << accList[idx]->accID_return() << endl;
			cout << "	계좌종류 : ";
			accList[idx]->High_level_name_return(); cout << ' ' << endl;
			cout << "	예금이자 : " << accList[idx]->High_level_ratio_return() << endl;
			cout << "	추가이자 : " << accList[idx]->High_plus_ratio_return() << endl;
			cout << "	잔    액 : " << accList[idx]->balance_return() << "원" << endl;
			cout << "	고객성명 : ";
			accList[idx]->name_return(); cout << "님" << endl;
			cout << "====================================" << endl << endl;

		}

	}
	return;
}



//실험

/*
void AccountHandler::AddAccount(Account_ptr *emp)
{
	accList[accNum++] = emp;

}
*/

int AccountHandler::accNum_return()
{
	return accNum;
}

Account* AccountHandler::accList_return(int idx)
{
	return accList[idx];
}


