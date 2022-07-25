#include <limits>
#include <string>
#pragma once
using namespace std;

/// <summary>
///  ласс дл€ представлени€ вещественных чисел
/// </summary>
class real {
	//  ¬ещественные числа представл€ем двум€ целыми - собственно числом (мантисса),
	//  и экспонентой - степенью числа 10
	//  ¬ итоге число 3.141569 =   3141569 * 10^-6, 
	//  то есть число Pi можно представить парой mantissa = 3141569, exponent = -6
	
	//  Ёто псевдоним дл€ целого типа, который будет использоватьс€ дл€ мантиссы. 
	//  ” int небольшой диапазон, а вообще можно до long long докрутить. »змен€ть нужно только в строчке ниже, 
	//  всЄ остальное будет работать и так. ƒолжен быть знаковым!
public:
	using value_type = int;

private:
	value_type mantissa;
	int exponent;
	//  Ќормализаци€ числа - отбрасывание правых нулей у мантиссы, и перевод их в экспоненту
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

	//  „исло в виде вещественного значени€ - double
	double to_double() const;

	//  —троковое представление числа
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

	//  ¬ывод в поток
	friend std::ostream& operator<<(std::ostream& out, const real& num);
	
	//  ѕриведение к единой экспоненте - необходимо дл€ сложени€/вычитани€ чисел 
	friend void alignExponents(real& num1, real& num2);

	//  ƒоступ на чтение дл€ закрытых полей класса
//  Ёти методы нужны в основном дл€ тестов, а так вообще их можно убрать
	value_type mnt() const { return mantissa; }
	int exp() const { return exponent; }
};

//  ѕреобразование вещественного числа в объект нашего класса
real from_double(double x);