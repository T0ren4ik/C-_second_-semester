#include "Header.h"

Poligon::Poligon(double A, double B, double C, double D) :type("Poligon"), a(A), b(B), c(C), d(D) {};


Poligon::Poligon(const Poligon& P) : type(P.type), a(P.a), b(P.b), c(P.c), d(P.d) {};

Poligon::~Poligon(){}

void Poligon::print()
{
	cout << "==================================================\n";
	cout << "Type: " << type << "\nSide lengths: " << a << "|" << b << "|" << c << "|" << d << endl;
	cout << "Square: " << this->getarea() << "\nPerimeter: " << this->getperimetr() << endl;
	cout << "InnerR: " << this->getInnerR() << "\nOuterR: " << this->getOuterR() << endl;
	cout << "==================================================\n";
}

double Poligon::getarea() const {	return a*b*c*d; }

double Poligon::getperimetr() const {	return a + b + c + d; }

double Poligon::getInnerR()
{
	if (a + c == b + d) {
		return this->getarea() / this->getperimetr() / 2;
	}	
	else return 0.0;
}

double Poligon::getOuterR() const
{
	double p = this->getperimetr() / 2;
	return 0.25 * sqrt((a * b + c * d) * (a * d + b * c) * (a * c + d * b) / (p - a) / (p - b) / (p - c));
}

//===================================================================


Triangle::Triangle(double T1, double T2, double T3) : a(T1), b(T2), c(T3), type("Triangle") {};

Triangle::Triangle(const Triangle& T): a(T.a), b(T.b), c(T.c), type(T.type) {};

Triangle::~Triangle(){}

string Triangle::type_triangle()
{
	if (a >= b + c || b >= a + c || c >= b + a)
	{
		return "Ne treugol";
	}
	else
		if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == b * b + a * a)
			return ("pryamougol");
		else
			if (a * a > b * b + c * c || b * b > a * a + c * c || c * c > b * b + a * a)
				return("tupoygol");
			else
				return("ostrougol");

}


void Triangle::print()
{
	cout << "==================================================\n";
	cout << "Type: " << type << "\nSide lengths: " << a << "|" << b << "|" << c << endl;
	cout << "Square: " << this->getarea() << "\nPerimeter: " << this->getperimetr() << endl;
	cout << "InnerR: " << this->getInnerR() << "\nOuterR: " << this->getOuterR() << endl;
	cout << "type_triangle: " << this->type_triangle() << endl;
	cout << "==================================================\n";

}


double Triangle::getarea() const
{
	double p = this->getperimetr() / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::getperimetr() const
{
	return (a + b + c);
}

double Triangle::getInnerR()
{
	double p = this->getperimetr() / 2;
	double s = this->getarea();
	return s / p;
}

double Triangle::getOuterR() const
{
	return a*b*c/4/this->getarea();
}


//======================================================================

Square::Square() : a(0), type("Square") {};

Square::Square(double S1): a(S1), type("Square") {};

Square::Square(const Square& S) : a(S.a), type(S.type) {};

Square::~Square(){}

void Square::print()
{
	cout << "==================================================\n";
	cout << "Type: " << type << "\nSide lengths: " << a << endl;
	cout << "Square: " << this->getarea() << "\nPerimeter: " << this->getperimetr() << endl;
	cout << "InnerR: " << this->getInnerR() << "\nOuterR: " << this->getOuterR() << endl;
	cout << "==================================================\n";
}

double Square::getarea() const
{
	return a*a;
}

double Square::getperimetr()const
{
	return 4*a;
}

double Square::getInnerR()
{
	return a/2;
}

double Square::getOuterR()const
{
	return a/sqrt(2);
}

Shape** create_obj_file(string filename) {

	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "Error!" << endl;
		throw - 1;
	}

	int count;
	string type, name_meaning;
	double a = 0, b = 0, c = 0, d = 0;
	fin >> count;

	Shape** ptr = new Shape * [count];

	for (int i = 0; i < count; ++i) {
		fin >> type;
		if (type == "Poligon") {
			for (int i = 0; i < 4; ++i) {
				fin >> name_meaning;
				if (name_meaning[0] == 'a') {
					a = stod(name_meaning.substr(1));
				}
				else if (name_meaning[0] == 'b') {
					b = stod(name_meaning.substr(1));
				}
				else if (name_meaning[0] == 'c') {
					c = stod(name_meaning.substr(1));
				}
				else if (name_meaning[0] == 'd') {
					d = stod(name_meaning.substr(1));
				}
				else throw - 1;
			}
			 
			ptr[i] = new Poligon(a, b, c, d);

		}
		
		else if (type == "Triangle") {
			for (int i = 0; i < 3; ++i) {
				fin >> name_meaning;
				if (name_meaning[0] == 'a') {
					a = stod(name_meaning.substr(1));
				}
				else if (name_meaning[0] == 'b') {
					b = stod(name_meaning.substr(1));
				}
				else if (name_meaning[0] == 'c') {
					c = stod(name_meaning.substr(1));
				}
				else throw - 1;
			}
			ptr[i] = new Triangle(a, b, c);

		}
		else if (type == "Square") {

			fin >> name_meaning;
			if (name_meaning[0] == 'a') {
				a = stod(name_meaning.substr(1));
			}
			else throw - 1;
			ptr[i] = new Square(a);

		}
		else throw 0;
	}
	fin.close();
	return ptr;
}

void sort_Shape(Shape** Ss, int n, compare F)
{	
	bool f = true;
	int i = n - 1;
	int j;
	while (f) {
		f = false;
		for (j = 0; j < i; ++j) {
			if (F(*Ss[j], *Ss[j + 1])) {
				swap(Ss[j], Ss[j + 1]);
				f = true;
			}
		}
		i = j;		
	}
}

bool lessArea(const Shape& P1, const Shape& P2)
{
	return P1.getarea() > P2.getarea() ? 1 : 0;
}

bool lessPerimetr(const Shape& P1, const Shape& P2)
{
	return P1.getperimetr() > P2.getperimetr() ? 1 : 0;
}

bool lessRout(const Shape& P1, const Shape& P2)
{
	return P1.getOuterR() > P2.getOuterR() ? 1 : 0;
}

double fig_maxsq_num(Shape** Ss, int n){
	double fig_maxsq_num = 0;
	for (int i = 0; i < n - 1; i++) // цикл по фигурам из массива
		if (lessArea(*Ss[i], *Ss[i + 1])) { // площадь i-й фигуры меньше i+1-й
			fig_maxsq_num = i; // зафиксировали номер
		}
	return fig_maxsq_num;
}
