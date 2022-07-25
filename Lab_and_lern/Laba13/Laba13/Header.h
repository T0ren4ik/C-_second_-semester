#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct n_A {
	int n;
	string* A;
	int* I;
};
n_A split(string s);

template<typename T>
void print_arr(T* arr, int n) {
	//int n = sizeof(arr) / sizeof(T);
	if (arr != nullptr) {
		for (int i = 0; i < n; ++i)
			cout << setw(4) << arr[i] << " ";
		cout << "\n";
	}
}
int count_vorgs(string s);

string str_of_file(string name);
int count_lines(string name);

float min_abs_f(string name);

void create_f1_min_max_f(string name);

struct point{
	double x, y;
};

struct d_point {
	point a, b;
};

d_point max_len_point(string name);

double distance(float x1, float y1, float x2, float y2);


void create_f2_table_from_f(string name);