#include <iostream>
#include "Empty.h"
#include "template.h"


using namespace std;

int main() {
	//cout << "test constructors" << endl;
	//Empty a;
	//Empty b("1");
	//Empty c(a);
	//cout << "test move-constructor" << endl;
	//Empty s(-b);
	//cout << "end test constructors" << endl;

	//// move ����������� ����������� ����� � ��� rvalue ���������.
	//// ������� ����������� ��� �������� � ������� �� ��������, ��� �������� �� �������� � ��� ����� ������

	//cout << endl;

	//cout << "test operator= and functions" << endl;
	//cout << "test =" << endl;
	//c = -b;
	//// ���������� �������� ����� ��������� (-b) �  ������� ��� ������������ �� ������� � ��������� move-copy �.�. rvalue
	//// 1 ����� ��������� ����� ���������� move= �.�. rvalue � ��������� move-copy
	//// �� ���� �������� ������ �� ������, �� ��� ��� � ������ ��� ���� � ������������ �������
	//// � �� � ���������� �� �������� �������� �� nulltr, �� �������� ���������� ����� ����� ������ �� �������

	//cout << endl;

	//cout << "test f1" << endl;
	//f1(b);
	//// ��������� ����� ������ ������� � ��������� �����	�.�. �� ��������

	//cout << endl;
	//cout << "test f2" << endl;
	//a = f2();
	//// � ������� ��������� ���������� ������ � ��������� � ���� �����, ����� move= �.�. rvalue � ���������

	//cout << endl;
	//cout << "test f3" << endl;
	//// �(copy noname)
	//a = f3(c);
	// //����� �� ��������� �.�. �������� �� ������, ��� ������ ��������� �����, move= �.�. rvaleu 
	// //� ����� ��� �������
	
	//===================================================

	cout << max_type_T(3, 2) << endl;
	cout << max_type_T(3.5, -10.6) << endl;
	string s1 = "hello";
	string s2 = "world";
	cout << max_type_T(s1, s2) << endl;
	Persone p1{ "aaa",1980 }, p2{ "BBb",2000 };
	cout << max_type_T(p1, p2) << endl;

	char s3[] = "String";
	char s4[] = "world";
	cout << max_type_T(s3, s4) << endl;
	


	return 0;
}