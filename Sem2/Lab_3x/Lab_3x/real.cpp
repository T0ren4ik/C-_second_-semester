#include <iostream>
#include "real.h"

//  Нормализация числа - отбрасывание правых нулей у мантиссы, и перевод их в экспоненту
void real::normalize() {
	while (mantissa != 0 && mantissa % 10 == 0) {
		mantissa /= 10;
		exponent++;
	}
	if (mantissa == 0)
		exponent = 0;
}

//  Приведение к единой экспоненте - необходимо для сложения чисел
void alignExponents(real& num1, real& num2) {
	//  Аргументами являются два объекта, переданные по ссылке, так что просто их и будем менять
	
	//  Нам нужно сначала в числе с большей экспонентой мантиссу домножать на 10, а экспоненту уменьшать на 1
	//  а потом аналогично в числе с меньшей экспонентой делить мантиссу на 10, увеличивая экспоненту, пока 
	//  они не сравняются. Есть проблема: у мантиссы, которая представлена целым числом, ограничение сверху на 
	//  возможные значения – поэтому нужно аккуратно умножать мантиссу на 10, пока не дойдём до максимального числа,
	//  делённого на 10 (это позволит хотя бы по поводу сложения и вычитания не особо переживать).

	if (num1.exponent < num2.exponent) {
		//  Маленький трюк - нам надо, чтобы num1 имело большую экспоненту, но swap делать нельзя - это ссылки
		//  поэтому если наоборот, то просто рекурсивно запускаем функцию с параметрами наоборот, а потом выход
		alignExponents(num2, num1);
		return;
	}
	//  С этого места у num1 экспонента больше, иначе вышли бы раньше

	//  Отдельный случай - когда num1 == 0 (мантисса равна 0)
	if (num1.mantissa == 0) {
		if (num2.mantissa == 0)
			num1.exponent = num2.exponent = 0;
		else
			num1.exponent = num2.exponent;
		return;
	}

	//  Уменьшаем экспоненту num1 настолько, насколько сможем
	constexpr real::value_type maxInt = std::numeric_limits<real::value_type>::max() / 10;
	while (num1.exponent > num2.exponent && abs(num1.mantissa) < maxInt) {
		num1.mantissa *= 10;
		num1.exponent--;
	}

	//  Теперь насколько возможно увеличиваем экспоненту второго числа
	while (num2.exponent < num1.exponent && num2.mantissa != 0) {
		num2.mantissa /= 10;
		num2.exponent++;
	}
	if (num2.mantissa == 0)
		num2.exponent = num1.exponent;

	//  В целом всё, для двух чисел мы выровняли экспоненты
}
//Реализовать остальные опреции через < можно было с помошь изменение знака мантисы, а <=> через обьединение и !
bool real::operator<(const real& otherNum) const {
	//  Оператор сравнения не имеет права менять сравниваемые числа - семантика такова
	//  Поэтому мы просто создадим два временных объекта, выровняем для них экспоненты, и сравним мантиссы
	real num1(*this), num2(otherNum);
	alignExponents(num1, num2);      //  Имя класса можно не указывать - мы и так внутри 
	return num1.mantissa < num2.mantissa;
}

bool real::operator<=(const real& otherNum) const{
	real num1(*this), num2(otherNum);
	alignExponents(num1, num2);      //  Имя класса можно не указывать - мы и так внутри 
	return num1.mantissa <= num2.mantissa;
}

bool real::operator>=(const real& otherNum) const{
	real num1(*this), num2(otherNum);
	alignExponents(num1, num2);      //  Имя класса можно не указывать - мы и так внутри 
	return num1.mantissa >= num2.mantissa;
}

bool real::operator>(const real& otherNum) const{
	real num1(*this), num2(otherNum);
	alignExponents(num1, num2);      //  Имя класса можно не указывать - мы и так внутри 
	return num1.mantissa > num2.mantissa;
}
// Можно ли реализовать через смену класса?
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
	//  Операция сложения не должна менять свои аргументы, но сейчас num1 и num2 - это локальные копии, т.к.
	//  функция принимает аргументы по значению. Значит, можно делать с num1 и num2 что угодно
	
	//  Выравниваем экспоненты
	alignExponents(num1, num2);
	//  Сложение выполняем в одном первом агрументе, его же и возвращаем
	num1.mantissa += num2.mantissa;
	num1.normalize();
	return num1;
}

real operator-(real num1, real num2){
	num2.mantissa = -num2.mantissa;
	return num1 + num2;
}

real operator/(real num1, real num2) {
	//  например 4/3 делить - получится 1, а вот 4 000 000/3 = 1 333 333
	//  то есть сначала добавляем побольше нулей к числителю, потом делим нацело, а потом уже из результата собираем 
	//  заново число
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

//  Пытаемся перевести вещественное число в объект нашего класса
real from_double(double x) {
	//  Запоминаем знак
	int sign{ 1 };
	if (x < 0) {
		sign = -1;
		x = -x;
	}

	//  Пока x > максимального возможного значения мантиссы для нашего типа данных (по умолчанию int)
	int exponent{ 0 };
	constexpr real::value_type maxMantissa = std::numeric_limits<real::value_type>::max();
	while (x > maxMantissa) {
		exponent++;
		x /= 10;
	}
	//  Теперь число влезет в наш тип данных, а экспонента остаётся
	//  Но есть проблема - оно может быть изначально меньше 1, 
	//  то есть мелкое double, надо "выводить" знаки из вещественной части
	double intPart{ 0 };
	while (x*10 < maxMantissa && modf(x, &intPart) != 0) {
		x *= 10;
		exponent--;
	}
	
	//  Приводим мантиссу к нашему целому типу (хотя тут можно и округление сделать), и знак учитываем
	real::value_type mantissa = static_cast<real::value_type>(x) * sign;
	//  Возвращаем результат
	return real(mantissa, exponent);
}

//  Число в виде вещественного значения - double
double real::to_double() const {
	//  Приводим к вещественному числу (double) и выводим
	return mantissa * pow(10, exponent);
}



//real from_double(int x) {
//	real num3 = from_double(static_cast<double>(x));
//	return num3;
//}

//  Строковое представление числа
std::string real::to_string() const {
	//  Нам нужно воспользоваться стандартным методом to_string(), но наш метод класса "скрыл" его, 
	//  поэтому явно указываем пространство имён std
	return std::to_string(mantissa) + "e" + std::to_string(exponent);
}

real operator/(real num1, double num2) { return num1 / from_double(num2); }
