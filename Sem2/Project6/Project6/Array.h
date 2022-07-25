#pragma once
#include <iostream>
using namespace std;

class Array {
private:
	int n;
	
		int* A;
public:
	Array(); //����������� �� ���������
	Array(int _n, int x = 0);
	//����������� � ���������� �� ���������
	Array(const Array& B); //����������� �����
	int length() const; //������� ��� ���������� ������� �������
	void resize(int nsize); //��������� ������� �������
	Array operator + (const Array& B);
	Array& operator += (const Array& B);
	Array operator + (const int x);
	Array& operator = (const Array& B);
	int& operator [] (int i);
	int operator [] (int i) const;

	~Array();
	friend ostream& operator << (ostream& out, const Array& B);
};

