#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "MiniBankingCommonDecl.h"
#include"ACCOUNT.h"
#include "error_cluster.h"

typedef Account* Account_ptr;

class AccountHandler
{
private:
	Account_ptr* accList;
	int accNum;

	
	AccountHandler(const AccountHandler& arrPtr) {}
		
	AccountHandler& operator=(const AccountHandler& arrPtr) {}
	

public:
	//������
	AccountHandler();

	
	//AccountHandler(int accNum);
	
	Account_ptr& operator[](int idx);

	Account_ptr& operator[](int idx) const;

	//�Ҹ���?
	~AccountHandler();


	//���� �����
	void make_account(int num);

	

	//�Ա��ϱ�
	void deposit_money();

	//accid�� ��ġã�� �� �ְ� ��ġ ��ȯ
	int accID_idx(int input_accID,int input_money);

	//����ϱ�
	void withdraw_money();
	
	//���������� ����ϴ� �Լ�
	int real_withdraw_money(int output_accID, int output_money);

	//�� ���� ��ȸ
	void inquire_account();

	//��ü ���� ��ȸ
	void show_all();


	//���¸���⿡�� �ߺ�üũ, �ٸ����� �ֳ� ���� üũ�ϴ� ��
	bool search_accID(int input_accID);

	
	//���Ͷ� ����(���� ������)
	void screenout(int cheker);
	

	//���Ͷ� ����(�� ���� ������)
	int inqire_screenout(int input_accid);

	//��� �Աݿ� ���Ͷ� ����
	void other_screenout(int idx);

	//��ü ������ȸ�� ���Ͷ� ����
	void show_all_screenout()const;

	//������³� �ſ���³�
	void select_accCreate(void);

	//����
	void AddAccount(Account_ptr *emp);

	//��� ����
	int accNum_return();

	Account* accList_return(int idx);


	

};
#endif // !__ACCOUNT_H__

