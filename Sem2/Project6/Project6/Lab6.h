#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Array.h"
using namespace std;
class Person {
private: // обратите внимание!!! поля закрыты для потомков!
	string name;
	int age;
public:
	Person(const string& name = "noname", int age = 18) :
		name(name), age(age) {}
	friend ostream & operator<< (ostream & os, const Person & p) {
		os << p.name << " " << p.age << endl;
		return os;
	}
};



class Student : public Person {
private:
	string univ; // Университет
	Array marks; // Оценки
public:
	Student() : marks(3), univ("MGU") { }

	Student(const string& name, int age, const string& u, int m) :
		Person(name, age), univ(u), marks(m) { }

	Student(const Student& s) :
		Person(s), univ(s.univ), marks(s.marks) { }

	Student& operator=(const Student& s) {
		if (&s != this)
		{
			Person::operator=(s); //обратите внимание для закрытых полей предка вызываем метод предка!
			marks.Array::operator=(s.marks);
			univ = s.univ;

		}
		return *this;
	};


	void setMark(int i, int mark) {
		if (i < 0 || i >= marks.length())
			throw - 1;
		marks[i] = mark;
	}
	friend ostream& operator<< (ostream& os, const Student& s) {
		os << (Person)s;
		os << s.univ << endl;
		os << s.marks;
		return os;
	}
};

class ErrMark : public exception { //наследем от базового типа исключений
private:
	int mark;
public:
	ErrMark(int n) :mark(n) {};
	const char* what() const { return "Error in mark"; }
	int getmark() const{return mark;}
 };
