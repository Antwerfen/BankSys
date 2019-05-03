#ifndef __ERROR_CLUSTER_H__
#define ___ERROR_CLUSTER_H__

#include "MiniBankingCommonDecl.h"
#include "ACCOUNT.H"
#include "AccountHandler.h"

class Input_error //: public Account
{
private:
	int input_money;
public:
	Input_error(int in_money) :input_money(in_money)
	{}

	void Show_reason(void);
};

class Output_error //: public Account
{
private:
	int output_money;
public:
	Output_error(int out_money) : output_money(out_money)
	{}

	void Show_reason(void);
};

class Space_error //: public AccountHandler
{
private:
	int acc_space;

public:
	Space_error(int is_there_any_sapce) : acc_space(is_there_any_sapce)
	{}

	void Show_reason(void);

};


#endif // !__ERROR_CLUSTER_H__
