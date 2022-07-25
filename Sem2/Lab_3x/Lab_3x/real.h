#include <limits>
#include <string>
#pragma once
using namespace std;

/// <summary>
/// ����� ��� ������������� ������������ �����
/// </summary>
class real {
	//  ������������ ����� ������������ ����� ������ - ���������� ������ (��������),
	//  � ����������� - �������� ����� 10
	//  � ����� ����� 3.141569 =   3141569 * 10^-6, 
	//  �� ���� ����� Pi ����� ����������� ����� mantissa = 3141569, exponent = -6
	
	//  ��� ��������� ��� ������ ����, ������� ����� �������������� ��� ��������. 
	//  � int ��������� ��������, � ������ ����� �� long long ���������. �������� ����� ������ � ������� ����, 
	//  �� ��������� ����� �������� � ���. ������ ���� ��������!
public:
	using value_type = int;

private:
	value_type mantissa;
	int exponent;
	//  ������������ ����� - ������������ ������ ����� � ��������, � ������� �� � ����������
	void normalize();

public:
	real() : mantissa(0), exponent(0) {};
	real(value_type Mantissa, int Exponent) : mantissa(Mantissa), exponent(Exponent) { normalize(); }

	bool operator<(const real& otherNum) const;
	bool operator<=(const real& otherNum) const;
	bool operator>=(const real& otherNum) const;
	bool operator>(const real& otherNum) const;

	friend bool operator<(const real& num1, const int& num2);
	friend bool operator<=(const real& num1, const int& num2);
	friend bool operator>=(const real& num1, const int& num2);
	friend bool operator>(const real& num1, const int& num2);

	friend bool operator<(const int& num2, const real& num1);
	friend bool operator<=(const int& num2, const real& num1);
	friend bool operator>=(const int& num2, const real& num1);
	friend bool operator>(const int& num2, const real& num1);

	//  ����� � ���� ������������� �������� - double
	double to_double() const;

	//  ��������� ������������� �����
	std::string to_string() const;

	friend real operator+(real num1, real num2);
	friend real operator-(real num1, real num2);
	friend real operator/(real num1, real num2);
	friend real operator/(real num1, double num2);
	friend real operator*(real num1, real num2);

	friend real operator+(real num1, int num2);
	friend real operator-(real num1, int num2);
	friend real operator/(real num1, int num2);
	friend real operator*(real num1, int num2);


	friend real operator+(int num1, real num2);
	friend real operator-(int num1, real num2);
	friend real operator/(int num1, real num2);
	friend real operator*(int num1, real num2);

	//  ����� � �����
	friend std::ostream& operator<<(std::ostream& out, const real& num);
	
	//  ���������� � ������ ���������� - ���������� ��� ��������/��������� ����� 
	friend void alignExponents(real& num1, real& num2);

	//  ������ �� ������ ��� �������� ����� ������
//  ��� ������ ����� � �������� ��� ������, � ��� ������ �� ����� ������
	value_type mnt() const { return mantissa; }
	int exp() const { return exponent; }
};

//  �������������� ������������� ����� � ������ ������ ������
real from_double(double x);