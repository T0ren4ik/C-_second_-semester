#pragma once 

float Distance(int x_1, int y_1, int x_2, int y_2);
float Square(int x_a, int y_a, int x_b, int y_b, int x_c, int y_c);
float Distance_to_line(int x_a, int y_a, int x_1, int y_1, int x_2, int y_2);
void cos_triangle(const Point& a, const Point& b, const Point& c, COS& ALF);
void Check_triangle_type(int x_a, int y_a, int x_b, int y_b, int x_c, int y_c);

inline double D(int x, int y) {
	(sqrt(x * x + y * y));
}

struct Point {
	int x, y;
};

struct COS {
	double a, b, c;
};