
#include "MiniBankingCommonDecl.h"
#include <iostream>
#include <cstdlib>

#include "Account_template.h"


using namespace std;


//생성자
template <typename T>

Account_template<T>::Account_template()
	:arrlen(0)
{
	arr = new T[MAX_ACC];
}

/*
template <typename T>
Account_template<T>::Account_template(int len)
	:arrlen(len)
{
	arr = new T[len];
}
*/

//[]연산자 오버로딩
template <typename T>
T& Account_template<T>::operator[](int idx)
{
	if (idx < 0 || idx >= 100)
	{
		cout << "배열의 범위를 벗어났습니다." << endl;
		exit(1);
	}
	return arr[idx];
}

//const []연산자 오버로딩
template <typename T>
T Account_template<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= 100)
	{
		cout << "배열의 범위를 벗어났습니다." << endl;
		exit(1);
	}
	return arr[idx];
}

//GetArrLen()
template <typename T>
int Account_template<T>::getArrLen()const
{
	return arrlen;
}

//소멸자
template <typename T>
Account_template<T>::~Account_template()
{
	delete[]arr;
}