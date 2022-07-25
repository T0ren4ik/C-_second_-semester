#include <iostream>

using namespace std;

template <class T>
T* create_array(T* a, int n);

template<class T>
int num_loc_min(T* a, int n);


int main() {
	setlocale(LC_ALL, "RU");

	//int* a = create_array(a, 10);
	cout << "=====test #1=====" << endl;// test 1
	int n = 5;
	int* arr = new int[n] { 99, 74, 57, 34, 13 };
	cout << "ќжидание: 4" << ", результат: " << num_loc_min(arr, n) << endl;
	delete[] arr; arr = nullptr;

	cout << "=====test #2=====" << endl;// test 2
	n = 1;
	arr = new int[n] { -5 };
	cout << "ќжидание: 0" << ", результат: " << num_loc_min(arr, n) << endl;
	delete[] arr; arr = nullptr;

	cout << "=====test #3=====" << endl;// test 3
	n = 2;
	arr = new int[n] { -2, -2 };
	try {
		cout << "ќжидание: ERROR" << ", результат: " << num_loc_min(arr, n) << endl;
	}
	catch (int x) {
		cout << "Error - GOOD, code:" << x << endl;
	}
	delete[] arr; arr = nullptr;

	cout << "=====test #4=====" << endl;// test 4
	n = 2;
	arr = new int[n] { -121, 121 };
	cout << "ќжидание: 0" << ", результат: " << num_loc_min(arr, n) << endl;
	delete[] arr; arr = nullptr;

	cout << "=====test #5=====" << endl; // test 5
	n = 2;
	arr = new int[n] { 101, -101 };
	cout << "ќжидание: 1" << ", результат: " << num_loc_min(arr, n) << endl;
	delete[] arr; arr = nullptr;

	cout << "=====test #6=====" << endl; // test 6
	n = 4;
	arr = new int[n] { 1, 1, 1, 1 };
	try {
		cout << "ќжидание: ERROR" << ", результат: " << num_loc_min(arr, n) << endl;
	}
	catch (int x) {
		cout << "Error - GOOD, code:" << x << endl;
	}
	delete[] arr; arr = nullptr;

	cout << "=====test #7=====" << endl; // test 7
	n = 7;
	arr = new int[n] { 9, 8, 7, 6, 7, 8, 9 };
	cout << "ќжидание: 3" << ", результат: " << num_loc_min(arr, n) << endl;
	delete[] arr; arr = nullptr;
}

template<class T>
T* create_array(T* a, int n){
    if (a == nullptr) {
        int* a = new int[n];
        for (int i = 0; i < n; ++i) {
            cout << "Enter digit: ";
            cin >> a[i];
        }
        return a;
    }
    else throw 1;
}

template<class T>
int num_loc_min(T * a, int n) {
    if (n == 1 || a[0] < a[1]) return 0;// если 1 элемент или 2

    for (int i = 1; i < n - 1; i++) {
        if ((a[i] < a[i - 1]) && (a[i] < a[i + 1]))	return i;
    }

    if (a[n - 1] < a[n - 2]) return n - 1;

    throw - 1;
}

