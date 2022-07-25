#pragma once  // не подключаем заголовочный файл несколько раз
#include <iostream>
#include<math.h>    // библиотеки
#define _USE_MATH_DEFINES 
# define M_PI          3.141592653589793238462643383279502884L /* pi */


using namespace std;

int LEN(int a);
int count_square63(int a);
int sun_extreme(int a, int b);
int square(int n);
long double decomposition(float x, float eps = 1e-6);