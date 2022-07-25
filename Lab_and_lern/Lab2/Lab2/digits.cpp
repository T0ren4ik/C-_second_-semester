#include "digits.h"
#include <cmath>
#include <iostream>




/*
	int a_b[2] = { (x_b - x_a), (y_b - y_a) };
	int b_c[2] = { (x_c - x_b), (y_c - y_b) };
	int c_a[2] = { (x_a - x_c), (y_a - y_c) };

	ABC.a = abs(a_b[1] * c_a[1] + a_b[2] * a_b[2]) / (sqrt(a_b[1] * a_b[1] + a_b[2] * a_b[2]) + sqrt(c_a[1] * c_a[1] + c_a[2] * c_a[2]));
	ABC.b = abs(a_b[1] * b_c[1] + a_b[2] * b_c[2]) / (sqrt(a_b[1] * b_c[1] + a_b[2] * a_b[2]) + sqrt(c_a[1] * c_a[1] + c_a[2] * c_a[2]));
	ABC.c = abs(b_c[1] * c_a[1] + b_c[2] * a_b[2]) / (sqrt(a_b[1] * a_b[1] + a_b[2] * a_b[2]) + sqrt(c_a[1] * c_a[1] + c_a[2] * c_a[2]));
*/
/*

	float dis_ab = Distance(x_a, y_a, x_b, y_b);
	float dis_bc = Distance(x_b, y_b, x_c, y_c);
	float dis_ca = Distance(x_c, y_c, x_a, y_a);

	if (dis_ab == dis_bc == dis_ca)
		std::cout << "Равно сторонний треугольник";
	else if (dis_ab == dis_bc | dis_bc == dis_ca | dis_ab == dis_ca)
		std::cout << "Равнобедренный треугольник";
	else if (ABC.a == 90 or ABC.b == 90 or ABC.c == 90)
		std::cout << "Прямоугольный треугольник";
	else if ()
		std::cout << "Тупоугольный треугольник";
	else if ()
		std::cout << "остроугольный треугольник";
*/

float Distance(int x_1, int y_1, int x_2, int y_2){
	return sqrt((x_2 - x_1)*(x_2 - x_1) + (y_2 - y_1)*(y_2 - y_1));
}


float Square(int x_a, int y_a, int x_b, int y_b, int x_c, int y_c){
	return abs(0.5*(x_a*(y_b - y_c) + x_b*(y_c - y_a) + x_c*(y_a - y_b)));
}


float Distance_to_line(int x_a, int y_a, int x_1, int y_1, int x_2, int y_2){
	return abs((y_2 - y_1)*x_a - (x_2 - x_1)*y_a + x_2*y_1 - y_2*x_1)/sqrt((x_2 - x_1) * (x_2 - x_1) + (y_2 - y_1) * (y_2 - y_1));
}


void cos_triangle(const Point &a, const Point &b, const Point &c, COS &ALF){
	struct vector{
		int X, Y;
	};
	vector  AB = { b.x - a.x, b.y - a.y }, 
			BC = { c.x - b.x, c.y - b.y }, 
			CA = { c.x - a.x, c.y - a.y };

	COS ALF = { acos((AB.X * CA.X + AB.Y * CA.Y) / D(AB.X, AB.Y) / D(CA.X, CA.Y)),
				acos((AB.X * BC.X + AB.Y * BC.Y) / D(AB.X, AB.Y) / D(BC.X, BC.Y)),
				acos((BC.X * CA.X + BC.Y * CA.Y) / D(BC.X, BC.Y) / D(CA.X, CA.Y))};


}

void Sort(COS& ALF){
	double m[3] = { ALF.a, ALF.b, ALF.c };

	for (int j = 1; j < 3; j++)
		for (int i = 0; i < 2; i++)
			if (m[i] < m[i + 1]){
				double x = m[i];
				m[i] = x;
				m[i + 1] = x;
			}

	ALF.a = m[1];
	ALF.b = m[2];
	ALF.c = m[3];


}


void Check_triangle_type(COS &ALF){

}


// что за специальный тип для возвращяемого обьекта функции
// можно как-то укоротить имя чего-либо
