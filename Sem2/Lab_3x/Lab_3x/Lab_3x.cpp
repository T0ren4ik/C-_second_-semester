//  Проект, иллюстрирующий работу с классом вещественных чисел

#include <iostream>
#include <locale>
#include <cmath>
#include <limits>
#include "real.h"

using namespace std;


//  Эталонная функция вычисления синуса с помощью ряда
double check_sin(double x) {
    double slag{ x }, x2{ x * x }, summ{ slag };
    int sign = 1;
    for (int i = 1; i < 25; i++) {
        slag = slag * x2 / (2*i) / (2*i + 1);
        sign = -sign;
        summ = summ + slag * sign;
    }
    return summ;
}

real calc_sin(double x) {   
    return  from_double(check_sin(x));
}

//  Эталонная функция вычисления косинуса с помощью ряда
double check_cos(double x) {
    double slag{ 1 }, x2{ x * x }, summ{ slag };
    int sign = 1;
    for (int i = 1; i < 25; i++) {
        slag = slag * x2 / (2 * i) / (2 * i - 1);
        sign = -sign;
        summ = summ + slag * sign;
    }
    return summ;
}

real calc_cos(double x) {
    return  from_double(check_cos(x));
}

int main(){
    setlocale(LC_ALL, "Russian");
    // //№1 количество значащих цифр типа double: 15-18
    //cout << "ВНИМАНИЕ! Проверьте, какой тип указан в классе real в качестве базового для мантиссы!\n";
    //cout << "Сейчас вы используете " << typeid(real::value_type).name() << endl;
    //cout << "Проблемы с точностью вещественных чисел :\n\n";
    double x1{ 10000000000 }, x2{ 0.0000000001 }, x3{ x1 + x2 };
    auto oldPrecision = cout.precision();
    cout.precision(20);
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x1 + x2 = " << x3 << endl;
    cout << "Проверяем, что x1 + x2 == x1 : " << (x1 == x3) << endl;
    real y1{ 1, 1 }, y2{ 2, 1 };
    cout << (y1 + y2) << " | " << (y1 - y2) << endl;

    int n = 3, k = 40;
    cout << k - y1 << endl;
    cout << y1 - k << endl;



    //cout << (y1 < k) << endl;
    //cout << (k > y1) << endl;
    //cout << "=======  Преобразование вещественного числа  ======\n\n";
    //auto elem = from_double(0.21315677e-100);
    //cout << "Elem = " << elem << endl;
   /* cout << "Elem = " << elem.to_string() << endl; */ //  тут округления нет при выводе в консоль
    //cout << "=======  Деление проверяем  ======\n\n";

    //elem = real(4, 0) / real(3, 0);
    //elem = real(1, 0) / 3;
    //cout << "Результат деления : \n\n";
    //cout << "Elem = " << elem << endl;
    //cout << "Elem = " << elem.to_string() << endl;  //  тут округления нет при выводе в консоль
    //cout << "=======  Sin проверяем  ======\n\n";

    //double arg = 1.223344;
    //cout << "Sin(1.223344) = 0.9402432548956731888953856219343700787144169073051291245493\n";
    //cout << sin(arg) << endl;
    //cout << check_sin(arg) << endl;
    //elem = calc_sin(arg);
    //cout << elem << endl;
    //cout << elem.to_string() << endl;
    //cout << "===========  Работа с классом real  ===========\n\n";

    //cout.precision(oldPrecision);
    //real n1(512, -2), n2(3141569, -6);
    //cout << n1 << "  " << n2 << endl;
    //real sum = n1 + n2;
    //cout << sum << endl;

    //cout << "Сравнение чисел : " << n1 << "<" << n2 << " = " << (n1 < n2) << endl;
    //cout << "Сравнение чисел : " << n2 << "<" << n1 << " = " << (n2 < n1) << endl;
    //system("pause");
}