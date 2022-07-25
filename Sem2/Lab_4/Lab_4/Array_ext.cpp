#pragma once
#include <iostream>

using namespace std;

class Array {
private:
	double* vect;
	int sizev;

	void resize(int nsize);
public:
	//конструктор по умолчанию
	Array() {
		sizev = 1;
		vect = new double[sizev];
		vect[0] = 0;
	}

	//конструктор с параметрами
	Array(int _n, double x = 0) {
		sizev = _n;
		vect = new double[sizev];

		for (int i = 0; i < sizev; i++)
			vect[i] = x;
	}

	//Конструктор 
	Array(int*& v, int _n) {
		sizev = _n;
		vect = new double[sizev];

		for (int i = 0; i < sizev; i++)
			vect[i] = v[i];
	}

	//move- конструктор
	Array(Array&& other) {
		sizev = other.sizev;
		vect = other.vect;
		other.vect = nullptr;	// Не позволит сразу деструктору удалить массив, перемещенный в другой объект
	}

	Array& operator= (Array&& arr) {
		//if (this != &arr) { - здесь не бывает самоприсваивания
		if (vect != nullptr)
			delete[] vect;
		sizev = arr.sizev;
		vect = arr.vect;
		arr.vect = nullptr;	// Не позволит сразу деструктору удалить массив, перемещенный в другой объект
		return *this;
	}


	// Изменение деструктора
		//Деструктор
	~Array() {
		if (vect != nullptr) {
			delete[] vect;
			cout << "Array deleted!" << endl;
		}
	}

	// методы
	int size() const {
		return sizeof(vect) / sizeof(double);
	}

	int get_s() const {
		return sizev;
	}

	double* get_v() const {

		return vect;
	}

	int* get_d() const {
		int* m = new int[sizev];
		for (int i = 0; i < sizev; ++i) {
			m[i] = vect[i];
		}
		return m;
	}

	void increment(int i) {
		vect[sizev - 1] += i;
	}

	Array operator + (const Array& arr);
	Array& operator += (const Array& arr);
	Array& operator + (const int x);
	Array& operator+=(const int x);


	bool operator>(const Array& v);
	bool operator>=(const Array& v);
	bool operator==(const Array& v);


	double& operator [] (int i);
	double operator [] (int i) const;



	int find_el(double el);
	void add_el_last(double el);
	void add_el_ind(double el, int k);
	void del_el(int k);


	// дружественные функции
	friend ostream& operator << (ostream& out, const Array& arr);
	friend istream& operator >> (istream& in, Array& arr);

};


