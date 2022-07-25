#include <string>
#include <iostream>

#include "digits.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	float Distance_to_point;	
	float Spase;
	float dist_to_line;

	int a = 2, b = 3, c = 4, d = 5, e = 6, f = 2;

	Distance_to_point = Distance(a, b, c, e);
	Spase = Square(a, b, c, d, e, f);
	dist_to_line = Distance_to_line(a, b, c, d, e, f);

	cout << "Расстояние между точками: " << Distance_to_point << endl;
	cout << "Площадь треугольника: " << Spase << endl;
	cout << "Расстояние между точкой и прямой " << dist_to_line << endl;

	//====================================================================

	Point a = { 0, 0 };
	Point b = { 5, 0 };
	Point c = { 0, 4 };

	COS ALF = { 0, 0, 0 };

	cos_triangle(& a, & b, & c, & ALF);

	cout << ALF.a << endl;

	return 0;
}