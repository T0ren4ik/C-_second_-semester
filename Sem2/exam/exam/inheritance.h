#pragma once
#include <iostream>

using namespace std;

class Shape {
public:
	virtual double getarea() const = 0;
};

class Circled :
	public Shape {
protected:
	int r;
public:
	Circled(int x = 0) : r{x} {}
	double getarea() const override  {
		return 3.14 * r * r;
	}
};

class Sphere :
	public Circled {
public:
	Sphere(int x = 0) : Circled(x) {}

	double getarea() const final  {
		return 3.14 * r * r * r;
	}

};

double getA(const Shape& s) {
	return s.getarea();
}