#include "MiniBankingCommonDecl.h"
#include "AccountHandler.h"
#include "screenOutMenu.h"



//�ʱ� �޴�
void ShowMenu(void)
{
	cout << "======Menu======" << endl;
	cout << "  1. ���°���" << endl;
	cout << "  2. ��    ��" << endl;
	cout << "  3. ��    ��" << endl;
	cout << "  4. ������ȸ" << endl;
	cout << "  5. ��ü��ȸ" << endl;
	cout << "  6. ��    ��" << endl;
	cout << "================" << endl;

}
//���°��� �޴�
void ShowAccMakeMenu(void)
{
	cout << "======Menu======" << endl;
	cout << "  1. ���뿹�ݰ��� ����" << endl;
	cout << "  2. �ſ�ŷڰ��� ����" << endl;
	cout << "  3. ó������ ���ư���" << endl;
	cout << "================" << endl;
}


void Show_create_acc_result(int checker)
{
	AccountHandler test;
	int idx = test.accNum_return() -1 ;
	
	switch (checker)
	{
	case 1:
		cout << " �Է��Ͻ� ������ Ȯ���Ͻñ� �ٶ��ϴ�." << endl;
		cout << "====================================" << endl;
		cout << "	���¹�ȣ : " << test.accList_return(idx)->accID_return() << endl;
		cout << "	�������� : ";
		test.accList_return(idx)->level_return(); cout << endl;
		cout << "	�������� : " << test.accList_return(idx)->level_ratio_return() << "%" << endl;
		cout << "	��    �� : " << test.accList_return(idx)->balance_return() << "��" << endl;
		cout << "	������ : ";
		test.accList_return(idx)->name_return(); cout << "��" << endl;
		cout << "====================================" << endl;
		break;

	case 2:
		cout << " �Է��Ͻ� ������ Ȯ���Ͻñ� �ٶ��ϴ�." << endl;
		cout << "====================================" << endl;
		cout << "	���¹�ȣ : " << test.accList_return(idx)->accID_return() << endl;
		cout << "	�������� : ";
		test.accList_return(idx)->High_level_name_return(); cout << ' ' << endl;
		cout << "	�������� : " << test.accList_return(idx)->High_level_ratio_return() << endl;
		cout << "	�߰����� : " << test.accList_return(idx)->High_plus_ratio_return() << endl;
		cout << "	��    �� : " << test.accList_return(idx)->balance_return() << "��" << endl;
		cout << "	������ : ";
		test.accList_return(idx)->name_return(); cout << "��" << endl;
		cout << "====================================" << endl;
		break;

	default:
		cout << "������ �Բ��ϴ� xx����" << endl;
		break;
	}

}


