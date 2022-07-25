#include "Header.h"

int check_ib(int x, int i){
	return (x >> (i - 1)) % 2;
}


void print_bin(int number) {
	do {	
		cout << (number & 1);
		number = number >> 1;
	} while (number);
}

int one_add_i(int number, int i){
	return number | (1 << (i - 1));
}

int zero_add_i(int number, int i){
	return number & ~(1 << (i-1));
}

double e_x(double x, double eps){
	double res = 1.0;
	double i = 2;
	double pr_zn = x;
	while (pr_zn > eps){
		res += pr_zn;
		pr_zn *= (x / i);
		i++;

	} 
	return res;
}

double sin_x(double x, double eps){
	while (abs(x) > 2 * M_PI) x = (x > 0) ? x - M_PI : x + M_PI;
	double res = x;
	double i = 1;
	double pr_zn = -(x * x * x) / (2*i + 1) / 2;
	while (abs(pr_zn) > eps) {
		res += pr_zn;
		i++;
		pr_zn *= (-(x * x) / (2*i + 1) / (2*i));
	}
	return res;
}
