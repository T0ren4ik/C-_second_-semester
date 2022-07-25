#include <string>
#include <iostream>


using namespace std;

int count_digit(int numder);
int sum_digit(int numder);
void print(int el);
void print(string el);
inline int max(int a, int b);
inline float max(float a, float b);
inline int max(int a, int b, int c);
inline float max(float a, float b, float c);
void sort_digit(int *a, int *b);
void sort_digit(float *a, float *b);
int remake_digit(int a);
int len_digit(int a);
void count_zero_one(int a, int* c_1, int* c_0);
float degree(float a, int b);
int factorial(int a);



int main() {
	setlocale(LC_ALL, "Rus");
	print("============= Ex №1 ====================");
	//============= Задание №1 ====================
	int arr[6] = { 123, 22345, -56, 7, 0, -1 };

	cout << "Element: ";
	for (int i = 0; i < 6; i++) {
		cout << arr[i] << ' ';

	}
	cout << ' ' << endl;

	//=============================================
	cout << "Count: ";
	for (int i = 0; i < 6; i++) {
		cout << count_digit(arr[i]) << ' ';

	}
	cout << ' ' << endl;

	//=============================================
	cout << "Sum: ";

	for (int i = 0; i < 6; i++) {
		cout << sum_digit(arr[i]) << ' ';
	}
	cout << ' ' << endl;

	//============= Задание №2 ====================
	print("============= Ex №2 ====================");
	int a = 10, b = 100, c = -1;
	cout << "Max element: " << max(a, b, c) << endl;
	
	//============= Задание №3 ====================
	print("============= Ex №3 ====================");
	sort_digit(&a, &b);
	cout << "Sort: " << a <<' ' << b << endl;

	//============ Задание №4 ====================
	print("============= Ex №4 ====================");
	print(factorial(2));
	
	//============ Задание №5 =====================
	print("============= Ex №5 ====================");
	cout << remake_digit(1234) << endl;

	//============ Задание №6 =====================
	print("============= Ex №6 ====================");
	int c_0 = 0;
	int c_1 = 0;
	int a_d = 100001;

	count_zero_one(a_d, &c_1, &c_0);

	cout << "Count 0: " << c_0 << ' ' << "Count 1: " << c_1 << endl;
	

	//============ Задание №7 ===================== 
	print("============= Ex №7 ====================");
	int osn = 407, st = -1;
	int sp_osn = osn;
	int sum_degree = 0;

	while (sp_osn > 0) {

		sum_degree += degree((sp_osn % 10), st);
		sp_osn /= 10;
	}
	print(osn == sum_degree ? "True" : "False");

	return 0;
}


int count_digit(int numder) {
	int count = 0;
	while (numder != 0) {
		count++;
		numder /= 10;

	}
	return count;
}


int sum_digit(int numder) {
	int sum = 0;
	while (numder != 0) {
		sum += abs(numder % 10);
		numder /= 10;
	}
	return sum;
}


void print(int el) {
	cout << el << endl;
}


void print(string el) {
	cout << el << endl;
}


inline int max(int a, int b) {
	return a > b ? a : b;
}


inline float max(float a, float b) {
	return a > b ? a : b;
}


inline int max(int a, int b, int c) {
	int f =  a > b ? a : b;
	return c > f ? c : f;
}


inline float max(float a, float b, float c) {
	float f = a > b ? a : b;
	return c > f ? c : f;
}


void sort_digit(int *a, int *b) {
	int c = *a;
	if (*a > *b) {
		*a = *b;
		*b = c;
	}
}


void sort_digit(float *a, float *b) {
	float c = *a;
	if (*a > *b) {
		*a = *b;
		*b = c;
	}
}


int len_digit(int a) {
	int count = 0;
	while (a != 0) {
		count++;
		a /= 10;
	}
	return count;
}


int remake_digit(int a) {
	int res;
	int sp = len_digit(a);
	int y = degree(10, sp);
	if (a / y == a % 10) {
		res = (a % y) / 10;
	}
	else
		res = (a % 10) * y + ((a % y) / 10) * 10 + a / y;

	return res;
}


void count_zero_one(int a, int *c_1, int *c_0) {
	while (a > 0) {
		if (a % 10 == 0)
			*c_0 = *c_0 + 1;
		else
			*c_1 = *c_1 + 1;

		a /= 10;
	}
} 


float degree(float a, int b) {
	float res = a;
	if (b > 1) {
		while (b > 1) {
			res *= a;
			b--;
		}
	}
	else if(b == 1){
		res = a;
	}
	else if (b == 0) {
		res = 1;
	}
	else {
		if (a != 0) {
			
			res = 1. / a;
			while (b < -1) {
				res /= a;
				b++;
			}
		}
		else 
			res = 0;
	}
	return res;
}


int factorial(int a) {
	int res = 1;
	for (int i = 2; i <= a; i++) {
		res *= i;
	}
	return res;
}

/*
 почему не работало а++ выше
как работать в нескольких файлах
пересмотреть\узнать о сслыках и копиях
узнать о ошибках
прочить остальное и посмотреть видеокурс
почему выдает ошибку setlocale(LC_ALL, "Rus"); 
почему если не закрыть консоль при след. запуски она пуста
прочитать фаил
узнать почему не работает заголовок и ресурсы
как в одном проекте делать несколько лаб
*/	