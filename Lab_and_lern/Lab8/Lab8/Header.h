#pragma once
#include <iostream>
#include <iomanip> 


using namespace std;

const int MAX_COLS = 5;
const int MAX_ROWS = 5;
typedef int matrix[MAX_ROWS][MAX_COLS];

	
void printMatrix(matrix matr, int rows, int cols);
int count_rows_cont_zero(matrix matr, int rows, int cols);
void transposition(matrix matr, int rows, int cols);
bool symmetry_on_main(matrix matr, int rows, int cols);
void delete_n_Row(matrix matr, int& rows, int cols, int n);
void add_p_rows(matrix matr, int rows, int cols, int p, int* a);
void delete_n_Row_m_col(matrix matr, int& rows, int &cols, int n, int m);
int determinate(matrix matr, int n);
