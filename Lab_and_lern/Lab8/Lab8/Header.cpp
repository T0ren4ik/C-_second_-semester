#include "Header.h"


void printMatrix(matrix matr, int rows, int cols) {
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

int count_rows_cont_zero(matrix matr, int rows, int cols){
	int count = 0;

	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++) {
			if (matr[i][j] == 0) {
				count++;
				break;
			}
			
		}
	}
	return count;
}

void transposition(matrix matr, int rows, int cols){
	for (int i = 0; i < rows - 1; i++) {
		
		for (int j = i + 1; j < cols; j++) {
			swap(matr[i][j], matr[j][i]);
		}
	}
}

bool symmetry_on_main(matrix matr, int rows, int cols){
	bool flag = true;
	int i = 0, j = 1;
	while (flag && i < rows - 1) {
		j = i + 1;
		while (flag && j < cols) {
			flag = (matr[i][j] == matr[j][i]);
			//cout << flag << " | " << matr[i][j] << " | " << matr[j][i] << endl;
			j++;
		}
		i++;
	}

	return flag;
}

void delete_n_Row(matrix matr, int& rows, int cols, int n){

	for (int i = n; i < rows - 1; ++i) {
		for (int j = 0; j < cols; ++j) {
			matr[i][j] = matr[i + 1][j];
		}
	}	
	rows--;
}

void delete_n_Row_m_col(matrix matr, int& rows, int& cols, int n, int m){

	for (int i = n; i < rows - 1; ++i) {
		swap(matr[i], matr[i + 1]);
	}
	rows--;


	for (int i = 0; i < rows; ++i) {
		for (int j = m; j < cols - 1; ++j) {
			swap(matr[i][j],matr[i][j + 1]);
		}
	}
	cols--;
}

void add_p_rows(matrix matr, int rows, int cols, int p, int* a) {
	for (int j = 0; j < cols; ++j) {
		matr[rows-1][j] = a[j];
	}

	for (int i = rows - 1; i > p; --i) {
		swap(matr[i], matr[i - 1]);
	}
}

int determinate(matrix matr, int n) {
	int out = 0;
	if (n == 1) {
		return matr[0][0];
	}
	else if (n == 2) {
		return matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
	}
	else {
		matrix M;
		for (int s = 0; s < n; ++s) {
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					M[i][j] = matr[i][j];

			int n1, n2;
			n1 = n2 = n;

			delete_n_Row_m_col(M, n1, n2, s, 0);
			out += matr[s][0] * pow(-1, s) * determinate(M, n - 1);
		}
	}
	return out;
}