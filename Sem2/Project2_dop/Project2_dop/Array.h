#pragma once
#include "Header.h"
class Bignum;

class Array {
private:
	double* vect;
	int sizev;

	void resize(int nsize);
public:
	//����������� �� ���������
	Array(){
		sizev = 1;
		vect = new double[sizev];
		vect[0] = 0;
	} 

	//����������� � �����������
	Array(int _n, double x = 0) {
		sizev = _n;
		vect = new double[sizev];

		for (int i = 0; i < sizev; i++) 
			vect[i] = x;
	} 

	//����������� 
	Array(int* v, int _n) {
		sizev = _n;
		vect = new double[sizev];

		for (int i = 0; i < sizev; i++)
			vect[i] = v[i];
	}

	explicit Array(int n) {
		sizev = n;
		vect = new double[n];
		for (int i = 0; i < n; ++i) {
			vect[i] = 0;
		}
	}

	//����������� �����
	Array(const Array& B) {
		cout << "operator_copy" << endl;

		sizev = B.sizev;
		vect = new double[sizev];
		for (int i = 0; i < sizev; i++)
			vect[i] = B.vect[i];
	}

	//�������� ������������ 
	Array& operator=(const Array& v) {
		cout << "operator=" << endl;
		if (this != &v) {
			delete[] vect;
			sizev = v.sizev;
			vect = new double[sizev];
			for (int i = 0; i < sizev; i++)
				vect[i] = v.vect[i];
		}
		return *this;
	}

	// ��������� � ���������� � ������ Array ��� ���������� ��������� move
// ��������� � ���������� � ������ Array ��� ���������� ��������� move

//��������� �����������
//����������
	~Array() {
		if (vect != nullptr) {
			delete[] vect;
			cout << "Array deleted!" << endl;
		}
	}

	//move- �����������
	 Array(Array&& other) noexcept {
		cout << "move-copy" << endl;
		sizev = other.sizev;
		vect = other.vect;
		other.vect = nullptr;	// �� �������� ����� ����������� ������� ������, ������������ � ������ ������
	}
	// noexcept
	//move- �������� ������������
	Array& operator= (Array&& arr) noexcept {
		cout << "move=" << endl;
		//if (this != &arr) { - ����� �� ������ ����������������
		if (vect != nullptr)
			delete[] vect;
		sizev = arr.sizev;
		vect = arr.vect;
		arr.vect = nullptr;	// �� �������� ����� ����������� ������� ������, ������������ � ������ ������
		return *this;
	}

	// ������
	int size() const {
		return sizeof(vect)/sizeof(double);
	}

	int get_s() const {
		return sizev;
	}

	double* get_v() const{

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
	Array operator + (const int x);
	Array& operator+=(const int x);
	Array& operator++();
	Array& operator++(int);

	bool operator>(const Array& v);
	bool operator>=(const Array& v);
	bool operator==(const Array& v);

	
	double& operator [] (int i);
	double operator [] (int i) const;



	int find_el(double el);
	void add_el_last(double el);
	void add_el_ind(double el, int k);
	void del_el(int k);
		

	// ������������� �������
	friend ostream& operator << (ostream& out, const Array& arr);
	friend istream& operator >> (istream& in, Array& arr);

};

class frac {
	int m, n;
	
public:
	frac(int a, int b) {
		m = a;
		n = b;
	}
	operator double() {
		return m / (double)n;
	}




};
