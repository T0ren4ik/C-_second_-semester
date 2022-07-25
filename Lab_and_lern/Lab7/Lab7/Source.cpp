#include <D:\C++\Lab_and_lern\Lab7\Lab7\Header.h>

int main() {
	setlocale(LC_ALL, "rus");
	cout << "============ 1 ============" << endl;

	int a[] = { 1, -2, 0, 4 };
	int n = sizeof (a) / sizeof(int);
	cout << "a | sum: " << rec_sum(a, n) << endl;
	
	cout << "============ 2 ============" << endl;

	int b[] = { 12, 4, 6, 8 };
	int n1 = sizeof(b) / sizeof(int);
	cout << "b | chet: " << F_count(b, n1, chet) << endl;
	cout << "a | pos: " << F_count(a, n, pos) << endl;


	cout << "============ 3 ============" << endl;

	cout << "b | max: " << rec_max_el_seg(b + 1, b + 3) << endl;
	cout << "a | max: " << rec_max_el_seg(a, a + 3) << endl;

	cout << "============ 4 ============" << endl;

	cout << "b | no zero: " << rec_zero_not(b, n1) << endl;
	cout << "a | no zero: " << rec_zero_not(a, n) << endl;

	cout << "============ 5 ============" << endl;

	cout << "a | ratio: " << ratio_mud_sum(a, n) << endl;


	int c[] = { 1, 0 ,0 };
	int n2 = sizeof(c) / sizeof(int);
	try {
		cout << "c | ratio: " << ratio_mud_sum(c, n2) << endl;
	}
	catch (int k) {
		if (k == 0)
		cout << "Попытка деления на ноль, массив не подходит для обработки" << endl;
		else if	(k == 1)
			cout << "Первый элемент массива равен нулю, массив не подходит для обработки" << endl;
		else if(k == 2) 
			cout << "последний элемент массива равен нулю, массив не подходит для обработки" << endl;
	}



	try {
		cout << "b | ratio: " << ratio_mud_sum(b, n1) << endl;
	}
	catch (int k) {
		if (k == 0)
			cout << "Попытка деления на ноль, массив не подходит для обработки" << endl;
		else if (k == 1)
			cout << "Первый элемент массива равен нулю, массив не подходит для обработки" << endl;
		else if (k == 2)
			cout << "последний элемент массива равен нулю, массив не подходит для обработки" << endl;
	}


	int c1[] = { 0, 1 ,3, 0, 1, 2 };
	int n3 = sizeof(c1) / sizeof(int);
	try {
		cout << "c | ratio: " << ratio_mud_sum(c1, n3) << endl;
	}
	catch (int k) {
		if (k == 0)
			cout << "Попытка деления на ноль, массив не подходит для обработки" << endl;
		else if (k == 1)
			cout << "Первый элемент массива равен нулю, массив не подходит для обработки" << endl;
		else if (k == 2)
			cout << "последний элемент массива равен нулю, массив не подходит для обработки" << endl;
	}
	
	cout << "============ 6 ============" << endl;
	int* A = new int[3];
	int na;
	try {
		read(A, na);
		print_arr(A, na);
	}
	catch (const char* S) {
		cout << S << endl;
	}


	int* AA = NULL;
	try {
		read(AA, na);
		print_arr(AA, na);
	}
	catch (const char* S) {
		cout << S << endl;
	}

	return 0;
}