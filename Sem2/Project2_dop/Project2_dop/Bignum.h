#pragma once
#include "Header.h"
#include "Array.h"

class Bignum {
private:
	Array vect;
	bool negative;


public:
	Bignum() {
		vect = Array();
		negative = false;
	}

	Bignum(int x) {
		negative = (x < 0);
		x = abs(x);
		int siz = size(to_string(x));
		int *di = new int[siz];

		for (int i = 0; i < siz; ++i) {
			di[i] = x % 10;
			x /= 10;
		}
		vect = Array(di, siz);
	}

	Bignum(const string S) {
		string s = S;
		int siz;
		if (S[0] == '-') {
			siz = size(S) - 1;
			negative = true;
			string s = S.substr(1);
		}
		else {
			siz = size(S);
			negative = false;
		}

		int* di = new int[siz];
		int x = abs(stoi(s));
		for (int i = 0; i < siz; ++i) {
			di[siz-i-1] = x % 10;
			x /= 10;
		}
		
		vect = Array(di, siz);
		delete[] di;
	}

	Bignum(const Bignum& n) {
		int siz = (n.vect).get_s();
		int* di_a = (n.vect).get_d();
		int* di = new int[siz];

		for (int i = 0; i < siz; i++){
			di[i] = di_a[i];
		}
		delete[] di_a;

		negative = n.negative;

		vect = Array(di, siz);
	}

	Bignum& operator=(const Bignum& v) {
		if (this != &v) {
			cout << 0;
			int siz = (v.vect).get_s();
			int* di_a = (v.vect).get_d();
			delete[] di_a;

			int* di = new int[siz];
			for (int i = 0; i < siz; i++)
				di[i] = di_a[i];
			negative = v.negative;
			vect = Array(di, siz);
			delete[] di;
		}
		return *this;
	}


	bool get_sign() {
		return negative;
	}

	int Size() {
		return vect.get_s();
	}

	int* get_d() {
		double* mas_arr = vect.get_v();
		int s = vect.get_s();
		int* m = new int[s];
		for (int i = 0; i < s; ++i) {
			m[i] = mas_arr[i];
		}
		return m;
	}




	long long int to_int(int*& v, int n, bool negative);

	bool operator>(const Bignum& v);
	bool operator<(const Bignum& v);
	bool operator>=(const Bignum& v);
	bool operator<=(const Bignum& v);
	bool operator==(const Bignum& v);
	bool operator!=(const Bignum& v);

	unsigned int HOD(Bignum& v1, Bignum& v2);


	Bignum operator+(const Bignum& arr);
	Bignum& operator+=(const Bignum& arr);
	Bignum& operator+(const int x);
	Bignum& operator+=(const int x);

	Bignum operator++();
	Bignum operator--();

	Bignum operator-(const Bignum& arr);
	Bignum& operator-=(const Bignum& arr);
	Bignum& operator-(const int x);
	Bignum& operator-=(const int x);
	Bignum& operator*(const int x);
	Bignum& operator*=(const int x);

	int& operator [] (int i);
	int operator [] (int i) const;

	~Bignum() {
	}

	friend ostream& operator << (ostream& os, const Bignum& fr);
	friend istream& operator >> (istream& os, Bignum&);
	
};