#include "Header.h"


int main() {
	setlocale(LC_ALL, "rus");

	int** m = nullptr;
	int rows, columns;

	try {
		read_new(m, rows, columns);
		printMatrix(m, rows, columns);
	}
	catch (const char* S) {
		cout << S << endl;
	}

	try {
		cout << "product_sum_row: " << product_sum_row(m, rows, columns) << endl;
		}
	catch (const char* S) {
		cout << S << endl;
	}
	//cout << "min_sum_cols: " << Min_sum_col(m, rows, columns) << endl;
	//==================================================================

	int* A = nullptr;
	int na;
	try {
		read(A, na);
		print_arr(A, na);
	}
	catch (const char* S) {
		cout << S << endl;
	}
	del_between_pozitive(A, na);
	//del_between_max_min(A, na);
	print_arr(A, na);
	//==================================================================

	int* A1 = nullptr;
	int n;
	try {
		read(A1, n);
		print_arr(A1, n);
	}
	catch (const char* S) {
		cout << S << endl;
	}

	try {
		cout << product_last_zero(A1, n) << endl;
	}
	catch (const char* S) {
		cout << S << endl;
	}
	
}