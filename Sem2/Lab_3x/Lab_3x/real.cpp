#include <iostream>
#include "real.h"

//  ������������ ����� - ������������ ������ ����� � ��������, � ������� �� � ����������
void real::normalize() {
	while (mantissa != 0 && mantissa % 10 == 0) {
		mantissa /= 10;
		exponent++;
	}
	if (mantissa == 0)
		exponent = 0;
}

//  ���������� � ������ ���������� - ���������� ��� �������� �����
void alignExponents(real& num1, real& num2) {
	//  ����������� �������� ��� �������, ���������� �� ������, ��� ��� ������ �� � ����� ������
	
	//  ��� ����� ������� � ����� � ������� ����������� �������� ��������� �� 10, � ���������� ��������� �� 1
	//  � ����� ���������� � ����� � ������� ����������� ������ �������� �� 10, ���������� ����������, ���� 
	//  ��� �� ����������. ���� ��������: � ��������, ������� ������������ ����� ������, ����������� ������ �� 
	//  ��������� �������� � ������� ����� ��������� �������� �������� �� 10, ���� �� ����� �� ������������� �����,
	//  �������� �� 10 (��� �������� ���� �� �� ������ �������� � ��������� �� ����� ����������).

	if (num1.exponent < num2.exponent) {
		//  ��������� ���� - ��� ����, ����� num1 ����� ������� ����������, �� swap ������ ������ - ��� ������
		//  ������� ���� ��������, �� ������ ���������� ��������� ������� � ����������� ��������, � ����� �����
		alignExponents(num2, num1);
		return;
	}
	//  � ����� ����� � num1 ���������� ������, ����� ����� �� ������

	//  ��������� ������ - ����� num1 == 0 (�������� ����� 0)
	if (num1.mantissa == 0) {
		if (num2.mantissa == 0)
			num1.exponent = num2.exponent = 0;
		else
			num1.exponent = num2.exponent;
		return;
	}

	//  ��������� ���������� num1 ���������, ��������� ������
	constexpr real::value_type maxInt = std::numeric_limits<real::value_type>::max() / 10;
	while (num1.exponent > num2.exponent && abs(num1.mantissa) < maxInt) {
		num1.mantissa *= 10;
		num1.exponent--;
	}

	//  ������ ��������� �������� ����������� ���������� ������� �����
	while (num2.exponent < num1.exponent && num2.mantissa != 0) {
		num2.mantissa /= 10;
		num2.exponent++;
	}
	if (num2.mantissa == 0)
		num2.exponent = num1.exponent;

	//  � ����� ��, ��� ���� ����� �� ��������� ����������
}
//����������� ��������� ������� ����� < ����� ���� � ������ ��������� ����� �������, � <=> ����� ����������� � !
bool real::operator<(const real& otherNum) const {
	//  �������� ��������� �� ����� ����� ������ ������������ ����� - ��������� ������
	//  ������� �� ������ �������� ��� ��������� �������, ��������� ��� ��� ����������, � ������� ��������
	real num1(*this), num2(otherNum);
	alignExponents(num1, num2);      //  ��� ������ ����� �� ��������� - �� � ��� ������ 
	return num1.mantissa < num2.mantissa;
}

bool real::operator<=(const real& otherNum) const{
	real num1(*this), num2(otherNum);
	alignExponents(num1, num2);      //  ��� ������ ����� �� ��������� - �� � ��� ������ 
	return num1.mantissa <= num2.mantissa;
}

bool real::operator>=(const real& otherNum) const{
	real num1(*this), num2(otherNum);
	alignExponents(num1, num2);      //  ��� ������ ����� �� ��������� - �� � ��� ������ 
	return num1.mantissa >= num2.mantissa;
}

bool real::operator>(const real& otherNum) const{
	real num1(*this), num2(otherNum);
	alignExponents(num1, num2);      //  ��� ������ ����� �� ��������� - �� � ��� ������ 
	return num1.mantissa > num2.mantissa;
}
// ����� �� ����������� ����� ����� ������?
bool operator<(const real& num1, const int& num2){
	real num3 = from_double(static_cast<double>(num2));
	return num1 < num3;
}

bool operator<=(const real& num1, const int& num2){
	real num3 = from_double(static_cast<double>(num2));
	return num1 <= num3;
}

bool operator>=(const real& num1, const int& num2){
	real num3 = from_double(static_cast<double>(num2));
	return num1 >= num3;
}

bool operator>(const real& num1, const int& num2){
	real num3 = from_double(static_cast<double>(num2));
	return num1 > num3;
}
//========
bool operator<(const int& num2, const real& num1) {
	real num3 = from_double(static_cast<double>(num2));
	return num1 > num3;
}

bool operator<=(const int& num2, const real& num1) {
	real num3 = from_double(static_cast<double>(num2));
	return num1 >= num3;
}

bool operator>=(const int& num2, const real& num1) {
	real num3 = from_double(static_cast<double>(num2));
	return num1 <= num3;
}

bool operator>(const int& num2, const real& num1) {
	real num3 = from_double(static_cast<double>(num2));
	return num1 < num3;
}
//==================


real operator+(real num1, real num2) {
	//  �������� �������� �� ������ ������ ���� ���������, �� ������ num1 � num2 - ��� ��������� �����, �.�.
	//  ������� ��������� ��������� �� ��������. ������, ����� ������ � num1 � num2 ��� ������
	
	//  ����������� ����������
	alignExponents(num1, num2);
	//  �������� ��������� � ����� ������ ���������, ��� �� � ����������
	num1.mantissa += num2.mantissa;
	num1.normalize();
	return num1;
}

real operator-(real num1, real num2){
	num2.mantissa = -num2.mantissa;
	return num1 + num2;
}

real operator/(real num1, real num2) {
	//  �������� 4/3 ������ - ��������� 1, � ��� 4 000 000/3 = 1�333�333
	//  �� ���� ������� ��������� �������� ����� � ���������, ����� ����� ������, � ����� ��� �� ���������� �������� 
	//  ������ �����
	//constexpr real::value_type maxMantissa = std::numeric_limits<real::value_type>::max();
	//cout << maxMantissa;
	//while (num1.mantissa * 10 < maxMantissa) {
	//	num1.mantissa *= 10;
	//	num1.exponent--;
	//	cout << num1.mantissa << endl;
	//}
	//cout << "ok\n";
	//while (num2.exponent > 0) {
	//	num2.mantissa *= 10;
	//	num2.exponent--;
	//}
	//cout << num1.mantissa;
	//num1.mantissa = (num1.mantissa / num2.mantissa);
	//num1.normalize();
	//return num1;
	return from_double(num1.to_double() / num2.to_double());
}

real operator*(real num1, real num2) {
	return from_double(num1.to_double() * num2.to_double());
}


real operator+(real num1, int num2){
	num1.mantissa + num2;
	num1.normalize();
	return num1;
}

real operator-(real num1, int num2){
	num1.mantissa - num2;
	num1.normalize();
	return num1;
}

real operator/(real num1, int num2){
	return from_double(num1.to_double() / num2);
}

real operator*(real num1, int num2){
	return from_double(num1.to_double() * num2);
}

//================================
real operator+(int num1, real num2){
	num2.mantissa + num1;
	num2.normalize();
	return num2;
}

real operator-(int num1, real num2){
num2.mantissa - num2;
num2.normalize();
return num2;
}

real operator/(int num1, real num2){
	return from_double(num1 / num2.to_double());
}

real operator*(int num1, real num2){
	return from_double(num1 * num2.to_double());
}

std::ostream& operator<<(std::ostream & out, const real& num) {
	out << num.to_double();
	return out;
}

//  �������� ��������� ������������ ����� � ������ ������ ������
real from_double(double x) {
	//  ���������� ����
	int sign{ 1 };
	if (x < 0) {
		sign = -1;
		x = -x;
	}

	//  ���� x > ������������� ���������� �������� �������� ��� ������ ���� ������ (�� ��������� int)
	int exponent{ 0 };
	constexpr real::value_type maxMantissa = std::numeric_limits<real::value_type>::max();
	while (x > maxMantissa) {
		exponent++;
		x /= 10;
	}
	//  ������ ����� ������ � ��� ��� ������, � ���������� �������
	//  �� ���� �������� - ��� ����� ���� ���������� ������ 1, 
	//  �� ���� ������ double, ���� "��������" ����� �� ������������ �����
	double intPart{ 0 };
	while (x*10 < maxMantissa && modf(x, &intPart) != 0) {
		x *= 10;
		exponent--;
	}
	
	//  �������� �������� � ������ ������ ���� (���� ��� ����� � ���������� �������), � ���� ���������
	real::value_type mantissa = static_cast<real::value_type>(x) * sign;
	//  ���������� ���������
	return real(mantissa, exponent);
}

//  ����� � ���� ������������� �������� - double
double real::to_double() const {
	//  �������� � ������������� ����� (double) � �������
	return mantissa * pow(10, exponent);
}



//real from_double(int x) {
//	real num3 = from_double(static_cast<double>(x));
//	return num3;
//}

//  ��������� ������������� �����
std::string real::to_string() const {
	//  ��� ����� ��������������� ����������� ������� to_string(), �� ��� ����� ������ "�����" ���, 
	//  ������� ���� ��������� ������������ ��� std
	return std::to_string(mantissa) + "e" + std::to_string(exponent);
}

real operator/(real num1, double num2) { return num1 / from_double(num2); }
