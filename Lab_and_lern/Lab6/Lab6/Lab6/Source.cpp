#include "Header.h"

int main() {
	setlocale(LC_ALL, "rus");

	int n;
	int* A = NULL;
	read(A, n);
	print(A, n);
	cout << "=========================" << endl;

	int k = n + 1;
	int *B = random_array(k);
	print(B, k);
	cout << "=========================" << endl;

	int* C = new_array(A, n, 10);
	int* C1 = new_array(B, k, 10);

	print(C, n+1);
	print(C1, k + 1);

	delete[] C;
	delete[] C1;
	delete[] A;
	cout << "=========== повторы ==============" << endl;

	int n1;
	int* A1 = NULL;
	read(A1, n1);
	print(A1, n1);

	del_double(A1, n1);
	print(A1, n1);


	del_double(B, k);
	print(B, k);

	delete[] A1;
	delete[] B;
	cout << "======== Поиск ===========" << endl;
	int* A2 = NULL;
	read(A2, n1);
	print(A2, n1);

	bin_find(A2, n1, 5);
	bin_find(A2, n1, 0);
	cout << "=========================" << endl;

	F(A2, n1, zero);

	cout << "=========================" << endl;
	cout << "Позиция: " << T_F(A2, n1, vozr);

	delete[] A2;

	return 0;
}
