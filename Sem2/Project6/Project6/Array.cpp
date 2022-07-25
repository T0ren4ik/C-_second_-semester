#include "Array.h"

Array::Array() {
	n = 10;
	A = new int[n];
	for (int i = 0; i < n; i++)
		A[i] = 0;
}
Array::Array(int _n, int x) {
	n = _n;
	A = new int[n];
	for (int i = 0; i < n; i++)
		A[i] = x;
}
Array::Array(const Array& B) {
	n = B.n;
	A = new int[n];
	for (int i = 0; i < n; i++)
		A[i] = B.A[i];
}
int Array::length() const {
	return n;
}
void Array::resize(int nsize) {
	int* ndata = new int[nsize];
	int sz = (n < nsize) ? n : nsize;

	for (int i = 0; i < sz; ++i)
		ndata[i] = A[i];
	delete[] A;
	A = ndata;
	n = nsize;
}
Array Array::operator + (const Array& B) {
	if (n != B.n)
		throw (1);
	Array C(n); //можно: Array C(n,0);
	for (int i = 0; i < n; i++)
		C.A[i] = A[i] + B.A[i];
	return C;
}
Array& Array::operator += (const Array& B) {
	if (n != B.n)
		throw (1);
	for (int i = 0; i < n; i++)
		A[i] = A[i] + B.A[i];
	return *this;
}
Array Array::operator + (const int x) {
	Array C(n); //можно: Array C(n,0);
	for (int i = 0; i < n; i++)
		C.A[i] = A[i] + x;
	return C;
}
Array& Array::operator = (const Array& B) {
	if (this != &B) {
		delete[] A;
		n = B.n;
		A = new int[n];
		for (int i = 0; i < n; i++)
			A[i] = B.A[i];
	}
	return *this;
}
int& Array::operator [] (int i) {
	return A[i];
}

int Array::operator [] (int i) const {
	return A[i];
}

Array::~Array() {
	delete[] A;
}

ostream& operator << (ostream& out, const Array& B) {
	for (int i = 0; i < B.n; i++)
		out << B.A[i] << ' ';
	out << endl;
	return out;
}
