#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void create_b_f(string filename);
void read_b_f(string filename);
void change_first_last_b_f(string filename);
void BF_koord(string filename);

struct point
{
	double x, y;
	point(double x, double y) {
		this->x = x;
		this->y = y;
	}
};
point* find_point(string filename);
inline double dist(double x, double y) {
	return sqrt(x * x + y * y);
}






struct person // ƒанные о сотруднике:
{
	int number;            // number Ц внутренний номер;
	string fullname;    // fullname - фамили€;
	int year;            // year Ц год рождени€;
	char gender;        // gender - пол.

	//person(int n, string f, int y, char g) {
	//	number = n;
	//	fullname = f;
	//	year = y;
	//	gender = g;
	//}

	//person() {
	//	number = 0;
	//	fullname = "";
	//	year = 0000;
	//	gender = ' ';
	//}


};
void BF_worker(string filename);
void worker(ifstream& fin, ofstream& f);

void create_table_worker_t(string filename);

void change_gate(string filename, int n, int date);

void change_gate(string filename, int n, string name);