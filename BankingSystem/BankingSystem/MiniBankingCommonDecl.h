#ifndef __MINIBANKINGCOMMONDECL_H__
#define __MINIBANKINGCOMMONDECL_H__

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>


using namespace std;

#include "String.h"




#define NAME_LEN 20 //고객이름을 위한
#define LEVEL_LEN 15 //계좌종류를 위한
#define Level_ratio 0.25 //보통계좌 기본 이자율
#define PASS_WORD 9999
#define High_Level_ratio 0.25 // 신용계좌 기본 이자율
#define MAX_ACC 100


//메뉴용 열거자
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, SHOWALLACC, EXIT };



// 계좌의 종류
enum { NORMAL = 1, CREDIT = 2, GOBACK = 3 };

//신용계좌 추가이자 부분
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };







#endif
