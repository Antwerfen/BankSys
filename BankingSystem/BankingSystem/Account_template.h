#ifndef __ACCOUNT_TEMPLATE_H__
#define __ACCOUNT_TEMPLATE_H__

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class Account_template
{
private:
	T* arr;
	int arrlen;

	//복사생성자
	Account_template(const Account_template& arr) {}

	//대입연산자
	Account_template& operator=(const Account_template& arr) {}


public:
	Account_template();
	//Account_template(int len);

	//수정용
	T& operator[](int idx);
	//출력용
	T operator[](int idx) const;
	//저장된 요소 갯수 파악을 위해
	int getArrLen()const;
	//소멸자
	~Account_template();





};

//생성자
template <typename T>

Account_template<T>::Account_template();
//Account_template<T>::Account_template(int len);


//[]연산자 오버로딩
template <typename T>
T& Account_template<T>::operator[](int idx);


//const []연산자 오버로딩
template <typename T>
T Account_template<T>::operator[](int idx) const;


//GetArrLen()
template <typename T>
int Account_template<T>::getArrLen()const;


//소멸자
template <typename T>
Account_template<T>::~Account_template();


#endif // !__ACCOUNT_TEMPLATE_H__