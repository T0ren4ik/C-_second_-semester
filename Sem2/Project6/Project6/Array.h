#pragma once
#include <iostream>
using namespace std;

class Array {
private:
	int n;
	
		int* A;
public:
	Array(); //конструктор по умолчанию
	Array(int _n, int x = 0);
	//конструктор с параметром по умолчанию
	Array(const Array& B); //конструктор копии
	int length() const; //функция для нахождения размера массива
	void resize(int nsize); //изменение размера массива
	Array operator + (const Array& B);
	Array& operator += (const Array& B);
	Array operator + (const int x);
	Array& operator = (const Array& B);
	int& operator [] (int i);
	int operator [] (int i) const;

	~Array();
	friend ostream& operator << (ostream& out, const Array& B);
};

