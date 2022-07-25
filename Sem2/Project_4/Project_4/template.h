#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Persone {
	string name;
	int year;

	bool operator>(const Persone& oth) const {
		return year > oth.year;
	}
	friend ostream& operator << (ostream& out, const Persone& B) {
		out << B.name << "  " << B.year;
		return out;
	}
};


template <typename T>
T max_type_T(const T a, const T b) {
	return a > b ? a : b;
}


template <>
const char* max_type_T(const char* a, const char* b) {
	if (strcmp(a, b) >= 0)
		return a;
	else
		return b;
}


