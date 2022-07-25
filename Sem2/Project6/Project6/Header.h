#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

class Shape {
public:
	virtual void print() = 0; //выдать информацию о типе фигуры
	virtual double getarea() const = 0; //найти площадь фигуры
	virtual double getperimetr() const = 0; // найти периметр
	virtual double getOuterR() const = 0; // радиус описаной окр
};


class Circled : public Shape {
public:
	virtual double getInnerR() = 0; //радиус вписанной окружности
	virtual double getOuterR() const = 0; //радиус описанной окружности
};	


class Poligon : public Circled {
private:
	double a, b, c, d;
	string type;

public:
	Poligon(double A = 0, double B = 0, double C = 0, double в = 0);
	Poligon(const Poligon& P);
	virtual ~Poligon();

	virtual void print(); //выдать информацию о типе фигуры
	virtual double getarea() const; //найти площадь фигуры
	virtual double getperimetr() const; // найти периметр

	virtual double getInnerR(); //радиус вписанной окружности
	virtual double getOuterR() const; //радиус описанной окружности
};


class Square : public Poligon {
private:
	double a;
	string type;
public:
	Square();
	Square(double S1);
	Square(const Square& S);
	virtual ~Square();

	virtual void print(); //выдать информацию о типе фигуры
	virtual double getarea() const; //найти площадь фигуры
	virtual double getperimetr() const; // найти периметр

	virtual double getInnerR(); //радиус вписанной окружности
	virtual double getOuterR() const; //радиус описанной окружности
};


class Triangle : public Circled{
protected:
	double a, b, c;
	string type;

public:
	Triangle(double T1, double T2, double T3);
	Triangle(const Triangle& T);
	virtual ~Triangle();

	string type_triangle();

	virtual void print(); //выдать информацию о типе фигуры
	virtual double getarea() const; //найти площадь фигуры
	virtual double getperimetr() const; // найти периметр

	virtual double getInnerR(); //радиус вписанной окружности
	virtual double getOuterR() const; //радиус описанной окружности

	//virtual bool lessArea(Shape& P1, Shape& P2); // сравнение по площ€ди 
	//virtual bool lessPerimetr(Shape& P1, Shape& P2); // сравнение по периметру 
	//virtual bool lessRout(Shape& P1, Shape& P2); // сравнение по радиусу вписанной

	//virtual bool lessArea(const Triangle& P1, const Triangle& P2); // сравнение по площ€ди 
	//virtual bool lessPerimetr(const Triangle& P1, const Triangle& P2); // сравнение по периметру 
	//virtual bool lessRout(const Triangle& P1, const Triangle& P2); // сравнение по радиусу вписанной

};

// –абота с файлом
Shape** create_obj_file(string filename);
// —ортировка
typedef bool (*compare) (const Shape& f1, const Shape& f2);
void sort_Shape(Shape** Ss, int n, compare);

bool lessArea(const Shape& P1, const Shape& P2); // сравнение по площ€ди 
bool lessPerimetr(const Shape& P1, const Shape& P2); // сравнение по периметру 
bool lessRout(const Shape& P1, const Shape& P2); // сравнение по радиусу вписанной
double fig_maxsq_num (Shape** Ss, int n); // номер фигуры с макс площадью
