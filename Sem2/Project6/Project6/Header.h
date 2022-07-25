#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

class Shape {
public:
	virtual void print() = 0; //������ ���������� � ���� ������
	virtual double getarea() const = 0; //����� ������� ������
	virtual double getperimetr() const = 0; // ����� ��������
	virtual double getOuterR() const = 0; // ������ �������� ���
};


class Circled : public Shape {
public:
	virtual double getInnerR() = 0; //������ ��������� ����������
	virtual double getOuterR() const = 0; //������ ��������� ����������
};	


class Poligon : public Circled {
private:
	double a, b, c, d;
	string type;

public:
	Poligon(double A = 0, double B = 0, double C = 0, double � = 0);
	Poligon(const Poligon& P);
	virtual ~Poligon();

	virtual void print(); //������ ���������� � ���� ������
	virtual double getarea() const; //����� ������� ������
	virtual double getperimetr() const; // ����� ��������

	virtual double getInnerR(); //������ ��������� ����������
	virtual double getOuterR() const; //������ ��������� ����������
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

	virtual void print(); //������ ���������� � ���� ������
	virtual double getarea() const; //����� ������� ������
	virtual double getperimetr() const; // ����� ��������

	virtual double getInnerR(); //������ ��������� ����������
	virtual double getOuterR() const; //������ ��������� ����������
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

	virtual void print(); //������ ���������� � ���� ������
	virtual double getarea() const; //����� ������� ������
	virtual double getperimetr() const; // ����� ��������

	virtual double getInnerR(); //������ ��������� ����������
	virtual double getOuterR() const; //������ ��������� ����������

	//virtual bool lessArea(Shape& P1, Shape& P2); // ��������� �� ������� 
	//virtual bool lessPerimetr(Shape& P1, Shape& P2); // ��������� �� ��������� 
	//virtual bool lessRout(Shape& P1, Shape& P2); // ��������� �� ������� ���������

	//virtual bool lessArea(const Triangle& P1, const Triangle& P2); // ��������� �� ������� 
	//virtual bool lessPerimetr(const Triangle& P1, const Triangle& P2); // ��������� �� ��������� 
	//virtual bool lessRout(const Triangle& P1, const Triangle& P2); // ��������� �� ������� ���������

};

// ������ � ������
Shape** create_obj_file(string filename);
// ����������
typedef bool (*compare) (const Shape& f1, const Shape& f2);
void sort_Shape(Shape** Ss, int n, compare);

bool lessArea(const Shape& P1, const Shape& P2); // ��������� �� ������� 
bool lessPerimetr(const Shape& P1, const Shape& P2); // ��������� �� ��������� 
bool lessRout(const Shape& P1, const Shape& P2); // ��������� �� ������� ���������
double fig_maxsq_num (Shape** Ss, int n); // ����� ������ � ���� ��������
