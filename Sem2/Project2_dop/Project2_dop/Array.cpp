#include "Array.h"
// Спросить про тип ().

//void Array::Swap(Array& other) {
//	swap(sizev, other.sizev);
//	swap(vect, other.vect);
//}
//
//Array& Array::operator=(Array other) {//вызов конструктора копии
//	this->Swap(other);
//	return *this;
//}


Array Array::operator+(const Array& v) {
	int sMIN = sizev < v.sizev ? sizev : v.sizev;
	int sMAX = sizev > v.sizev ? sizev : v.sizev;

	Array v1(sMAX);
	for (int i = 0; i <= sMIN; ++i)
		v1.vect[i] = v.vect[i] + vect[i];

	if (sMIN == sizev)
		for (int i = sMIN; i <= sMAX; ++i)
			v1.vect[i] = v.vect[i];
	else
		for (int i = sMIN; i <= sMAX; ++i)
			v1.vect[i] = vect[i];

	return v1;
}

Array& Array::operator+=(const Array& v) {
	*this = (*this) + v;
	return *this;
}

Array& Array::operator+=(const int x) {
	return (*this) + x;
}

Array Array::operator+(const int x) {
	for (int i = 0; i < sizev; ++i)
		vect[i] += x;
	return *this;
}

	

bool Array::operator>(const Array& v){
	if (sizev != v.sizev)
			return sizev > v.sizev ? 1 : 0;

	int i = 0;
	while (vect[i] > v.vect[i++]);

	if (i == sizev) return true;
	else return false;
}


bool Array::operator>=(const Array& v) {
	if (sizev != v.sizev)
		return sizev >= v.sizev ? 1 : 0;

	int i = 0;
	while (vect[i] >= v.vect[i++]);

	if (i == sizev) return true;
	else return false;


}


bool Array::operator==(const Array& v) {
	if (sizev != v.sizev)
		return 0;

	int i = 0;
	while (vect[i] == v.vect[i++]);

	if (i == sizev) return true;
	else return false;
}


double& Array::operator[](int i) {
	return vect[i];
}	

double Array::operator[](int i) const {
	return vect[i];
}

void Array::resize(int nsize) {
	double* ndata = new double[nsize];

	double sz = (sizev < nsize) ? sizev : nsize;
	for (int i = 0; i < sz; ++i) 
		ndata[i] = vect[i];
	
	delete[] vect;
	vect = ndata;
	sizev = nsize;
}

int Array::find_el(double el){
	for (int i = 0; i < sizev; ++i) 
		if (vect[i] == el) return i;
	
	return -1;
}

void Array::add_el_last(double el){
	resize(sizev + 1);
	vect[sizev-1] = el;
}

void Array::add_el_ind(double el, int k){
	resize(sizev + 1);

	// сдвигаем элементы вперед
	for (int i = sizev-1; i > k; --i)
		vect[i] = vect[i - 1];
	// вставить х в поз
	vect[k] = el;
}

void Array::del_el(int k){
	for (int i = k; i < sizev ; ++i)
		vect[i] = vect[i+1];
	resize(sizev - 1);
}

ostream& operator<<(ostream& os, const Array& v){
	//os << "Size: " << v.sizev << endl;
	for (int i = 0; i < v.sizev; ++i) {
		os << v.vect[i];
	}
	os << endl;
	return os;
}

istream& operator>>(istream& os, Array& v){
	int n;
	cout << "Enter size array: ";
	os >> n;
	if (n == 0)
		return os;
	
	v.sizev = n;
	for (int i = 0; i < v.sizev; ++i) {
		cout << "Enter el: ";
		os >> v.vect[i];
	}
	return os;
}

//======================================================================