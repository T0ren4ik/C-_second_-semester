#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void read(int*& a, int& n);

void print(const int *arr, int n);

int* random_array(int n);

int* new_array(int* arr, int n, int el);

void del_double(int*& a, int& n);

void bin_find(int* a, int n, int key);

void selectionSort(int* a, int n);

typedef bool (*pred1)(int);
bool isSimple(int x);
bool pos(int a);
bool zero(int a);
bool chet(int a);
bool F(int* a, int n, pred1 f);

typedef bool (*pred2)(int, int);
int T_F(int* a, int n, pred2 f);
bool vozr(int a, int b);
bool el_equivalent(int a, int b);
