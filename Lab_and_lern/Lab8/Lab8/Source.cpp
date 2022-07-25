#include "Header.h"

int main() {
	const int MAX_ROWS = 3;
	const int MAX_COLS = 3;
	matrix matr = {
	 {1, 2, 3},
	 {4, 0, 6},
	 {7, 8, 0}
	};
	cout << "============== 1 ===============\n";

	cout << count_rows_cont_zero(matr, MAX_ROWS, MAX_COLS) << endl;

	cout << "============== 2 ===============\n";

	transposition(matr, 3, 3);
	printMatrix(matr, 3, 3);

	cout << "============== 3 ===============\n";

	matrix matr1 = {
	 {1, 2, 3},
	 {2, 5, 6},
	 {3, 6, 9}
	};

	cout << symmetry_on_main(matr, 3, 3) << endl;
	cout << symmetry_on_main(matr1, 3, 3) << endl;

	cout << "============== 4 ===============\n";
	int ROWS = 3, COLS = 3;

	delete_n_Row(matr, ROWS, COLS, 1);
	printMatrix(matr, ROWS, COLS);

	cout << "============== 5 ===============\n";

	cout << "ERROR\n";

	cout << "============== 6 ===============\n";

	int ROWS2 = 3, COLS2 = 3;
	matrix matr2 = {
	 {1, 2, 3},
	 {4, 5, 6},
	 {7, 6, 9}
	};
	delete_n_Row_m_col(matr2, ROWS2, COLS2, 0, 2);
	printMatrix(matr2, ROWS2, COLS2);

	cout << "============== 7 ===============\n";
	const int m_col = 4;
	const int m_row = 3;

	matrix M = {
	 {1, 2, 3},
	 {4, 6, 6},
	 {10, 8, 9}
	};
	int a[] = { 3, 5, 7 };

	add_p_rows(M, m_col, m_row, 2 ,a);

	printMatrix(M, m_col, m_row);

	cout << "============== 8 ===============\n";

	matrix val =
	{ {1, 2, 3},
	  {4, 4, 6},
	  {7, 8, 9}
	};

	cout << determinate(val, 3);



	return 0;
}