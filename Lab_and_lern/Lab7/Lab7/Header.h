#pragma once
#include <iostream>

using namespace std;

int rec_sum(int* a, int i);

typedef bool (*pred)(int);
bool chet(int a);
bool isSimple(int x);
bool pos(int a);
int F_count(int* a, int i, pred f);

int rec_max_el_seg(int* begin, int* end);

bool rec_zero_not(int* a, int i);

double ratio_mud_sum(int* a, int n);

void read(int*& a, int& n);
void print_arr(const int* arr, int n);
