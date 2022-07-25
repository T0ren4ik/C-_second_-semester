#pragma once
#include <iostream>
#include <iomanip> 

using namespace std;


template<typename T>
void read_new(T**& matr, int& rows, int& cols) {

	if (matr == nullptr) {
		cout << "Введите кол-во строк: ";
		cin >> rows;
		cout << "Введите кол-во столбцов: ";
		cin >> cols;

		matr = new int* [rows];
		for (int i = 0; i < rows; ++i) matr[i] = new int[cols];

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << "EL mass #" << i << "|" << j << ": ";
				cin >> matr[i][j];
			}
		}
	}
	else
		throw "Память выделена";
}

template<typename T>
void printMatrix(T** matr, int rows, int cols) {
	// Форматированный вывод для выравнивания столбцов		
	cout.setf(ios::left);
	cout << setw(6);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matr[i][j] << "\t";
		}
		cout << endl;
	}
}

template<typename T>
void delete_matrix(T**& matr, int rows) {
	if (matr != nullptr) {
		for (int i = 0; i < rows; ++i) delete[] matr[i];
		delete[]matr;
	}
	else {
		throw "Попытка удаления невыделенной памяти";
	}
}

template<typename T>
void read(T*& a, int& n) {
	if (a == NULL) {
		cout << "Size mass: ";
		cin >> (n);
		a = new T[n];

		for (int i = 0; i < n; ++i) {
			cout << "EL mass #" << i << ": ";
			cin >> a[i];
		}
	}
	else
		throw "Память занята";
}

template<typename T>
void print_arr(const T* arr, int n) {
	if (arr != nullptr) {
		for (int i = 0; i < n; ++i)
			cout << arr[i] << " ";
		cout << "\n";
	}
}
//------------------------------------------------------------------
//Функция находит минимальную сумму значений в столбце.
template<typename T>
T Min_sum_col(T** matr, int row, int col) {
	//Работает для размерностей >= 1
	T out = matr[0][0];
	int i, j;
	T pr_zn;

	//присваиваю выходной переменной значение первого стольбца
	for (j = 1; j < col; ++j) {
		out += matr[j][0];
	}

	//Сравниваю с остальными и нахожу минимум
	for (j = 0; j < col; j++) {
		pr_zn = 0;
		for (i = 0; i < row; i++) {
			pr_zn += matr[i][j];
		}
		out = (pr_zn < out) ? pr_zn : out;
	}

	return out;
}

//Функция удаляет все элементы между первым минимальным и последний максимальным 
template<typename T>
void del_between_max_min(T*& a, int& n) {
	int i, between;
	int i_max = 0, i_min = 0, max = a[0], min = a[0];

	// Ищу минимум и максимум
	for (i = 1; i < n; ++i) {
		if (min > a[i]) {
			i_min = i;
			min = a[i];
		}
		if (max <= a[i]) {
			i_max = i;
			max = a[i];
		}
	}

	// Муняю индыксы так, чтобы первым шел самый минимальный индекс
	if (i_min > i_max) {
		swap(i_min, i_max);
	}
	
	// Нахожу количество промежуточных элементов и в случае != 0 создаю массив и удаляю
	between = i_max - i_min - 1;
	if (between) {
		int* A = new int[n - between];
		for (i = 0; i <= i_min; ++i) {
			A[i] = a[i];
		}

		for (int  j = i_max; j < n; ++j) {
			A[i] = a[j];
			i++;

		}
		delete[] a; a = A;
		n -= between;
	}
}

//Функция вычисляет произведение элементов после последнего нулевого элемента.
template<typename T>
T product_last_zero(T* a, int n) {
	T out = 1;
	int i = n - 1;

	//Нахожу последний нулевой элемент
	while (a[i] && --i > -1);

	// если он не последний и он есть, то начинаю перемножать до конца, иначе обработка и вывод ошибок
	if (i < n - 1 && i >= 0) {
		// i++ т.к. a[i] это ноль
		for (i++; i < n; ++i) {
			out *= a[i];
		}

		return out;
	}
	else if (i == n - 1)
		throw "Ноль на последней позиции, строка не подходит для вычисления";
	else if (i == -1)
		throw "Ноля нет в строке, строка не подходит для вычисления";
	else
		throw "ERROR";

}
//------------------------------------------------------------------

//Функция удаляет все положительные элементы
template<typename T>
void del_between_pozitive(T*& a, int& n) {
	int i, count_pol = 0, j;
	// Подсчитываю количество нулевых элементов
	for (i = 0; i < n; ++i) 
		count_pol = (a[i] > 0) ? count_pol + 1 : count_pol;

	//Если их количество > нуля
	if (count_pol != 0) {
		//проверяю, что не весь массив из пол. эл.,
		if (n - count_pol == 0) {
			delete[] a; a = nullptr;
		}
		// создаю новый массив, удаляю страрый и переприсваиваю указатели
		else {
			int* A = new int[n - count_pol];
			j = 0;
			for (i = 0; i < n; ++i) {
				if (a[i] <= 0) {
					A[j] = a[i];
					j++;
				}
			}
			n -= count_pol;
			delete[] a; a = A;
			//print_arr(A, n - count_pol);
		}
	}
}

//вычисляет произведение не нулевых элементов значений сумм строк матрицы
template<typename T>
T product_sum_row(T** matr, int row, int col) {
	T out = 1;
	int i, j;
	T pr_zn;
	bool flag = false;

	// иду по строка
	for (i = 0; i < row; ++i) {
		pr_zn = 0;
		//считаю сумму в строке
		for (j = 0; j < col; j++) {
			pr_zn += matr[i][j];
		}
		//если не ноль умножаю и подтверждаю, что проводил хоть одну этерацию уможения
		if (pr_zn != 0) {
			out *= pr_zn;
			flag = true;
		}
	}
	//проверяю, что колисчество элементов произведения не ноль и вывожу
	if (flag)
		return out;
	else
		throw "В матрице отстуствуют строки, сумма элементов которой не равны нулю.";
}