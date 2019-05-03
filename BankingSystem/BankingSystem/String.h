#ifndef __STRING_H__
#define __STRING_H__

#include "MiniBankingCommonDecl.h"

class String
{
private:
	int strLen;
	char* str;

public:

	//처음
	String();

	//길이 확보
	String(int len);

	//복사?
	String(const char* text);

	//길이,글자 둘 다 입력?
	String(int len, const char *text);

	//복사 생성자?
	String(const String& copy);

	//뭐지?
	String(const char* text, int idx);

	//?
	String(char* text1, char* text2);

	//?
	virtual ~String()
	{
		delete[]str;
	}

	
	String& operator+=(const char* text);
	

	String& operator=(const char* text);
	

	String& operator=(const String& copy);
	

	char& operator[](int idx);
	

	String operator+(const String& copy);
	

	friend ostream& operator<<(ostream& out, const String& obj);

	friend istream& operator>>(istream& in, String& obj);


};
	
	

#endif