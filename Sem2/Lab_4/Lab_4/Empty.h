#pragma once
#include <string>
#include <iostream>

using namespace std;

class Empty {
	//класс для демонстрации срабатывания конструкторов, деструкторов и операторов=
private:
	std::string name;
// конструкторы
public:
	Empty();
	Empty(std::string s);
	Empty(const Empty& other);
	Empty(const Empty&& other)noexcept;
// деструктор
	~Empty();
//оператор =
	Empty operator-();
	Empty& operator=(const Empty& other);
	Empty& operator=(const Empty&& other)noexcept;
};

void f1(Empty a);
Empty f3(Empty& a);
Empty f2();