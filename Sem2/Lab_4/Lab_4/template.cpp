#include "template.h"
#include <iostream>
#include <string>

using namespace std;
struct Persone {
	string name;
	int year;
	
	bool operator>(const Persone& oth) const{
		return year > oth.year;
	}
	friend ostream & operator << (ostream & out, const Persone &B) {
		out << B.name << "  " << B.year;
		return out;
	}
};

int main() {
	cout << max_type_T(3, 2) << endl;
	cout << max_type_T(3.5, -10.6) << endl;
	string s1 = "hello";
	string s2 = "world";
	cout << max_type_T(s1, s2) << endl;
	Persone p1{ "aaa",1980 }, p2{ "BBb",2000 };
	cout << max_type_T(p1, p2) << endl;
	system("pause");
	return 0;
}