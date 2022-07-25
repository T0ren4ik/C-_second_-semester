#include "Bignum.h"

ostream& operator<<(ostream& os, const Bignum& v) {
	//os << "Size: " << v.sizev << endl;
	//if (v.negative) os << "-";
	//for (int i = v.sizev-1; i >= 0; --i)
	//	os << v.digit[i];
	//
	//os << endl;
	bool sign = v.negative;
	if (sign) os << "-";
	os << (v.vect);
	return os;
}

istream& operator>>(istream& os, Bignum& v) {
	string s;
	os >> s;

	Bignum temp(s);
	v = temp;
	return os;
}

//string Bignum::to_str(const Bignum& v) {
//	string s = "";
//	if (negative) s += "-";
//	for (int i = 0; i < sizev; i++)
//		s += to_string(digit[i]);
//	cout << s << endl;
//	return s;
//}

long long int  Bignum::to_int(int*& v, int n, bool negative) {
	long long int res = 0;
	if (n !=0) {
		res = v[0];

		for (int i = 1; i < n; ++i) {
			res += pow(10, i) * v[i];
		}
		if (negative) res = -res;
	}	

	return res;
}


bool Bignum::operator>(const Bignum& v) {
	if (negative != v.negative)
		return negative ? 0 : 1;

		if (negative)
			return vect>(v.vect) ? 0:1;
		else
			return vect > (v.vect) ? 1 : 0;
}

bool Bignum::operator<(const Bignum& v) {
	return !(*this > v);
}


bool Bignum::operator>=(const Bignum& v) {
	if (negative != v.negative)
		return negative ? 0 : 1;

	if (negative)
		return vect >= (v.vect) ? 0 : 1;
	else
		return vect >= (v.vect) ? 1 : 0;
}

bool Bignum::operator<=(const Bignum& v) {
	return !(*this >= v);
}

bool Bignum::operator==(const Bignum& v) {
	if (negative != v.negative)
		return negative ? 0 : 1;

	if (negative)
		return vect == (v.vect) ? 0 : 1;
	else
		return vect == (v.vect) ? 1 : 0;
}

bool Bignum::operator!=(const Bignum& v) {
	return !(*this == v);
}


Bignum Bignum::operator+(const Bignum& v) {
	int* v1 = (v.vect).get_d();
	int* v2 = vect.get_d();
	int x1 = to_int(v1, (v.vect).get_s(), v.negative),  x2 = to_int(v2, vect.get_s(), negative);
	//cout << x1 << " | " << x2 << endl;
	Bignum temp(x1 + x2);
	//cout << temp;
	return temp;
}

Bignum Bignum::operator++(){
	if(negative)
		vect.increment(-1);
	else
		vect.increment(1);
	return *this;
}


Bignum Bignum::operator--(){
	if (negative)
		vect.increment(1);
	else
		vect.increment(-1);
	return *this;
}

Bignum Bignum::operator-(const Bignum& v){
	int* v1 = (v.vect).get_d();
	int* v2 = vect.get_d();
	int x1 = to_int(v1, (v.vect).get_s(), v.negative), x2 = to_int(v2, vect.get_s(), negative);
	Bignum temp(x1 - x2);
	return temp;
}

Bignum& Bignum::operator-=(const Bignum& arr){
	*this = (*this - arr);
	return *this;
}

Bignum& Bignum::operator-(const int x){
	int* v1 = vect.get_d();
	int x1 = to_int(v1, (vect).get_s(), negative);
	Bignum temp(x1 - x);
	return temp;
}

Bignum& Bignum::operator-=(const int x){
	*this = Bignum(*this - x);
	return *this;
}

Bignum& Bignum::operator*(const int x){
	int* v1 = vect.get_d();
	int x1 = to_int(v1, (vect).get_s(), negative);
	Bignum temp(x1 * x);
	return temp;
}

Bignum& Bignum::operator*=(const int x){
	*this = Bignum(*this * x);
	return *this;
}

Bignum& Bignum::operator+=(const Bignum& v) {
	*this = (*this) + v;
	return *this;
}

Bignum& Bignum::operator+(const int x) {
	int* v1 = vect.get_d();
	int x1 = to_int(v1, (vect).get_s(), negative);
	Bignum temp(x1 + x);
	return temp;
}


Bignum& Bignum::operator+=(const int x) {
	*this = (*this) + Bignum(x);
	return *this;
}


unsigned int greatest_common_divisor(unsigned int a, unsigned int b) {
	if (a == b)
		return a;
	if (a > b)
		return greatest_common_divisor(a - b, b);
	return greatest_common_divisor(a, b - a);
}

unsigned int Bignum::HOD(Bignum& v1, Bignum& v2) {
	int* d1 = (v1.vect).get_d();
	int* d2 = (v2.vect).get_d();
	int x1 = to_int(d1, (v1.vect).get_s(), v1.negative), x2 = to_int(d2, v1.vect.get_s(), v2.negative);

	return greatest_common_divisor(x1, x2);;
}

int& Bignum::operator[](int i) {
	int k = int(vect[i]);
	return k;
}

int Bignum::operator[](int i) const {
	int k = int(vect[i]);
	return k;
}
