#pragma once
#include <iostream>

using namespace std;
// Основы ООП (1-9)
class error {
private:
	string str;
public:
	error(string s): str(s) {}
	string what() {
		return str;
	}
};

class Vector
{
private:
	int* v;
	int sizev;
	void resize(int n) {
		if (v != nullptr) {
			sizev = n;
			int siz = n > sizev ? sizev : n;
			int* temp = new int[n];
			for (int i = 0; i < siz; ++i) {
				temp[i] = v[i];
			}
			delete v;
			v = temp;
		}
		else
			if (n > 0) {
				sizev = n;
				v = new int[n];
			}
			else throw error("невыерны размер");
	
	}
public:
	explicit Vector(int n = 10) : sizev(n) {
		cout << "Vector" << endl;

		if (n > 0) {
			v = new int[sizev];
			for (int i = 0; i < sizev; ++i) {
				v[i] = 0;
			}
		}
		else {
			v = nullptr;
			sizev = 0;
			throw error("Не верный размер");
		}
	}
	Vector(int* a, int n) {
		if (n > 0) {
			sizev = n;
			v = new int[sizev];
			for (int i = 0; i < sizev; ++i) {
				v[i] = a[i];
			}
		}
		else {
			v = nullptr;
			sizev = 0;
			throw error("Не верный размер");
		}
	}
	~Vector() {
		cout << "~Vector\n";
		if (v != nullptr) {
			delete[] v;
			v = nullptr;
		}
	}
	bool operator==(const Vector& other) {
		if (sizev != other.sizev) return false;
		for (int i = 0; i < sizev; ++i) 
			if (v[i] != other.v[i]) return false;
		return true;
	}
	bool operator!=(const Vector& other) {
		return !(*this == other);
	}
	Vector& operator=(const Vector& other) {
		cout << "operator=" << endl;
		if (*this == other) {
			delete[] v;
			sizev = other.sizev;
			if (sizev > 0) {
				v = new int[sizev];
				for (int i = 0; i < sizev; ++i) {
					v[i] = other.v[i];
				}
			}
		}
		return *this;
	}
	//Vector(const Vector& other) {
	//	cout << "copy" << endl;
	//	sizev = other.sizev;
	//	v = new int[sizev];
	//	for (int i = 0; i < sizev; ++i) {
	//		v[i] = other.v[i]; 
	//	}
	//}
	Vector(Vector&& other) noexcept {
		cout << "move-copy" << endl;
		sizev = other.sizev;
		v = other.v;
		other.v = nullptr;
	}
	Vector& operator=(Vector&& other) noexcept {
		cout << "move-construct" << endl;
		
		delete[] v;
		sizev = other.sizev;
		v = other.v;
		other.v = nullptr;
		return *this;
	}
	Vector operator+(const Vector& other) {
		int n = sizev > other.sizev ? other.sizev : sizev;
		for (int i = 0; i < n; ++i) {
			v[i] += other.v[i];
		}
		return *this;
	}
	Vector& operator+=(const Vector& other) {
		*this = (*this + other);
		return *this;
	}
	Vector operator+(const int x) {
		for (int i = 0; i < sizev; ++i) {
			v[i] += x;
		}
		return *this;
	}

	int& operator[](int i) {
		if (i < sizev)
			return v[i];
		else
			throw error("выход за границу массива");
	}
	int operator[](int i)const {
		if (i < sizev)
			return v[i];
		else
			throw error("выход за границу массива");
	}
	Vector& operator++() {
		for (int i = 0; i < sizev; ++i) {
			v[i]++;
		}
		return* this;
	}
	Vector operator++(int) {
		Vector temp(*this);
		for (int i = 0; i < sizev; ++i) {
			v[i]++;
		}
		return temp;
	}
	int find(int x){
		for (int i = 0; i < sizev; ++i) {
			if (v[i] == x) return i;
		}
		return -1;
	
	}
	void add_el(int x, int i_) {
		if (i_ <= sizev + 1) {
			resize(sizev + 1);
			v[sizev] = x;

			for (int i = sizev; i > i_-1; --i) {
				swap(v[i], v[i - 1]);
			}
		}
		else throw error("выход за пределы массива");

	}
	int size() {
		return sizev;
	}
	void swap_(Vector& other) {
		swap(other.sizev, sizev);
		swap(other.v, v);
	}
	Vector(Vector& other) {
		this->swap_(other);
	}
	friend ostream& operator<<(ostream& os, const Vector& other) {
		for (int i = 0; i < other.sizev; ++i) {
			os << other.v[i] << " ";
		}
		os << "\n";
		return os;
	}
};

class frac {
private:
	int a, b;
public:
	frac(int a_, int b_) : a(a_), b(b_) {};
	operator double() {
		return a / (double)b;
	}

};
