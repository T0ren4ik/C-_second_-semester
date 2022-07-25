#pragma once
#include <cmath>
#include <iostream>
constexpr auto M_PI = 3.14159265358979323846;

using namespace std;

int check_ib(int x, int i);
void print_bin(int number);
int one_add_i(int numder, int i);
int zero_add_i(int numder, int i);

double e_x(double x, double eps = 1e-5);
double sin_x(double x, double eps = 1e-5);