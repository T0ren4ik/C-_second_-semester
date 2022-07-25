#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Circle {
protected:
	string type; //название типа в иерархии наследования
	double radius;
public:
	virtual void setR(double r);

	virtual double getR() const;

	Circle() : radius(0), type("Circle") {
		cout << "Circle no parametrs create" << endl;
	};

	Circle(double r) : radius(r), type("Circle") {
		cout << "Circle create" << endl;
	};

	Circle(const Circle& C): radius(C.radius), type("Circle") {
		cout << "Circle copy" << endl;
		//this->radius = C.radius;
	}

	Circle& operator=(const Circle& C) {
		cout << "Circle operator=" << endl;
		if (this != &C) 
			this->radius = C.radius;
		
		return *this;
	}

	~Circle() {
		cout << "Circle deleted!" << endl;
	};

	virtual void shou_inform() const{
		cout << "Type: " << type << "\nRadius: " << radius << endl;
	}
	
	friend ostream& operator<< (ostream& os, const Circle& C) {
		C.shou_inform();
		return os;
	}

};

// Конус
class Cone : public Circle {
protected:
	double height;
public:
	virtual void setH(double h);

	virtual double getH() const;

	Cone() : Circle(), height(0){
		type = "Cone";
		cout << "Cone no parametrs create" << endl;
	};

	Cone(double r, double h) :Circle(r),  height(h) {
		type = "Cone";
		cout << "Cone create" << endl;
	};

	Cone(const Cone& C): Circle(C), height(C.height) {  // upcast
		type = "Cone";
		cout << "Cone copy" << endl;
	}

	Cone& operator=(const Cone& C) {
		cout << "Cone operator=" << endl;
		Circle::operator = (C);			  // upcast
		if (this != &C)
			this->height = C.height;
		return *this;
	}

	~Cone() {
		cout << "Cone deleted!" << endl;
	};

	virtual void shou_inform() const {
		this->Circle::shou_inform();
		cout << "Height: " << height << endl;
	}

	friend ostream& operator<< (ostream& os, const Cone& C) {
		C.shou_inform();
		return os;
	}
};

// сфера
class Sphere : public Circle {
public:

	Sphere() : Circle() {
		type = "Sphere";
		cout << "Sphere no parametrs create" << endl;
	};

	Sphere(double r) :Circle(r) {
		type = "Sphere";
		cout << "Sphere create" << endl;
	};

	Sphere(const Sphere& C) : Circle(C) {  // upcast
		type = "Sphere";
		cout << "Sphere copy" << endl;
	}

	Sphere& operator=(const Sphere& C) {
		cout << "Sphere operator=" << endl;
		Circle::operator = (C);			  // upcast
		return *this;
	}

	~Sphere() {
		cout << "Sphere deleted!" << endl;
	};


	friend ostream& operator<< (ostream& os, const Sphere& C) {
		C.Circle::shou_inform();
		return os;
	}
};

// цилиндр 
class Cylinder : public Cone {
public:
	Cylinder() : Cone() {
		type = "Cylinder";
		cout << "Cylinder no parametrs create" << endl;
	};

	Cylinder(double r, double h) :Cone(r, h) {
		type = "Cylinder";
		cout << "Cylinder create" << endl;
	};

	Cylinder(const Cylinder& C) : Cone(C) {  // upcast
		type = "Cylinder";
		cout << "Cylinder copy" << endl;
	}

	Cylinder& operator=(const Cylinder& C) {
		cout << "Cylinder operator=" << endl;
				 
		if (this != &C)
			Cone::operator = (C);  // upcast
		return *this;
	}

	~Cylinder() {
		cout << "Cylinder deleted!" << endl;
	};


	friend ostream& operator<< (ostream& os, const Cylinder& C) {
		C.Cone::shou_inform();
		return os;
	}
};

struct obj {
	Circle* p;
	int n;
	obj(Circle* object, int count) : p(object), n(count) {};
};

//Circle* create_obj_file(Circle* p, string filename);
void create_obj_file(string filename);

