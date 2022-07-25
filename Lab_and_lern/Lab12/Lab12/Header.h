#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

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

//сколько раз в файле встречается каждая буква латинского алфавита.
//int* count_letter(string name);
void count_letter(string name);

void max_len_str_f(string name);

void count_vord_f(string name);

void erase_str(string& s, const string sub);
void del_vord_f(string name, string del);

void numbered_str(string name);

void replese_sub_vord_count_f(string name, string sub);