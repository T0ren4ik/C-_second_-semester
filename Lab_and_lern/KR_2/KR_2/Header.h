#pragma once
#include <iostream>
#include <iomanip> 

using namespace std;


template<typename T>
void read_new(T**& matr, int& rows, int& cols) {

	if (matr == nullptr) {
		cout << "������� ���-�� �����: ";
		cin >> rows;
		cout << "������� ���-�� ��������: ";
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
		throw "������ ��������";
}

template<typename T>
void printMatrix(T** matr, int rows, int cols) {
	// ��������������� ����� ��� ������������ ��������		
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
		throw "������� �������� ������������ ������";
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
		throw "������ ������";
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
//������� ������� ����������� ����� �������� � �������.
template<typename T>
T Min_sum_col(T** matr, int row, int col) {
	//�������� ��� ������������ >= 1
	T out = matr[0][0];
	int i, j;
	T pr_zn;

	//���������� �������� ���������� �������� ������� ��������
	for (j = 1; j < col; ++j) {
		out += matr[j][0];
	}

	//��������� � ���������� � ������ �������
	for (j = 0; j < col; j++) {
		pr_zn = 0;
		for (i = 0; i < row; i++) {
			pr_zn += matr[i][j];
		}
		out = (pr_zn < out) ? pr_zn : out;
	}

	return out;
}

//������� ������� ��� �������� ����� ������ ����������� � ��������� ������������ 
template<typename T>
void del_between_max_min(T*& a, int& n) {
	int i, between;
	int i_max = 0, i_min = 0, max = a[0], min = a[0];

	// ��� ������� � ��������
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

	// ����� ������� ���, ����� ������ ��� ����� ����������� ������
	if (i_min > i_max) {
		swap(i_min, i_max);
	}
	
	// ������ ���������� ������������� ��������� � � ������ != 0 ������ ������ � ������
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

//������� ��������� ������������ ��������� ����� ���������� �������� ��������.
template<typename T>
T product_last_zero(T* a, int n) {
	T out = 1;
	int i = n - 1;

	//������ ��������� ������� �������
	while (a[i] && --i > -1);

	// ���� �� �� ��������� � �� ����, �� ������� ����������� �� �����, ����� ��������� � ����� ������
	if (i < n - 1 && i >= 0) {
		// i++ �.�. a[i] ��� ����
		for (i++; i < n; ++i) {
			out *= a[i];
		}

		return out;
	}
	else if (i == n - 1)
		throw "���� �� ��������� �������, ������ �� �������� ��� ����������";
	else if (i == -1)
		throw "���� ��� � ������, ������ �� �������� ��� ����������";
	else
		throw "ERROR";

}
//------------------------------------------------------------------

//������� ������� ��� ������������� ��������
template<typename T>
void del_between_pozitive(T*& a, int& n) {
	int i, count_pol = 0, j;
	// ����������� ���������� ������� ���������
	for (i = 0; i < n; ++i) 
		count_pol = (a[i] > 0) ? count_pol + 1 : count_pol;

	//���� �� ���������� > ����
	if (count_pol != 0) {
		//��������, ��� �� ���� ������ �� ���. ��.,
		if (n - count_pol == 0) {
			delete[] a; a = nullptr;
		}
		// ������ ����� ������, ������ ������� � �������������� ���������
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

//��������� ������������ �� ������� ��������� �������� ���� ����� �������
template<typename T>
T product_sum_row(T** matr, int row, int col) {
	T out = 1;
	int i, j;
	T pr_zn;
	bool flag = false;

	// ��� �� ������
	for (i = 0; i < row; ++i) {
		pr_zn = 0;
		//������ ����� � ������
		for (j = 0; j < col; j++) {
			pr_zn += matr[i][j];
		}
		//���� �� ���� ������� � �����������, ��� �������� ���� ���� �������� ��������
		if (pr_zn != 0) {
			out *= pr_zn;
			flag = true;
		}
	}
	//��������, ��� ����������� ��������� ������������ �� ���� � ������
	if (flag)
		return out;
	else
		throw "� ������� ����������� ������, ����� ��������� ������� �� ����� ����.";
}