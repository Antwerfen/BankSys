#include "MiniBankingCommonDecl.h"
#include "error_cluster.h"
#include "Account.h"
#include "AccountHandler.h"

void Output_error::Show_reason(void)
{
	cout << " ���忡 �ܰ� ���ų� �߸��� �Է��Դϴ�. ����" << endl << endl;
}

void Space_error::Show_reason(void)
{
	cout << "�� �̻��� ������ �����ϴ�. ����" << endl << endl;
}


void Input_error::Show_reason(void)
{
	cout << "�߸��� �Է��Դϴ�. ����" << endl << endl;
}
