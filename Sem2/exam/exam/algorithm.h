#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <numeric> // accumulate
#include <iomanip>
#include <map>

using namespace std;

//Используя функцию copy, построить вектор символов из строки.
vector<char> string2vector(string s);

// Используя функцию count_if, посчитать количество заданных символов в строке.
void count_char_str(string s, vector<char> m);

//Используя функции transform и toupper, преобразовать символы строки к верхнему регистру.
void str2STR(string& str);

// Используя функцию copy и объект stringstream, заполнить вектор словами из строки.
vector<string> create_v_s(string str);


//С помощью функций transform и rotate, зашифровать каждое слово в
//строке смещением символов слова вправо на порядковый номер слова.
void code_v_string(vector<string>& v);

//Используя функцию count_if, посчитать количество заданных слов в строке.
void count_word(string s, vector<string> v);

//Используя функцию mismatch, найти первое различное слово в двух строках.
void ferst_different(vector<string> v1, vector<string> v2);


//Проверьте, является ли эта строка анаграммой другого слова, используя is_permutation().
void permutation(string s1, string s2);

//Напишите генератор анаграмм, который получает слово из командной
//строки и строит вектор всех возможных перестановок из букв. https://prog-cpp.ru/permutation/
void findPermutations(string s);


// Используя функцию generate, заполнить вектор случайными целыми
// числами в диапазоне N...M.
void vect_gener_NM(vector<int>& v, int n, int m);

//Используя функцию for_each, найти среднее арифметическое значений в векторе
double arithmetic_mean(vector<int>& v);

//Используя функцию for_each, найти минимальное по модулю значение в векторе
void MIN_V(vector<int>& v);

//Используя функцию count_if, найти количество значений меньших среднего.
void count_min_mean(vector<int>& v);

//Используя функцию remove_copy_if, создать копию вектора удалив все значения меньшие среднего.
void copy_v_more_mean(vector<int>& v1, vector<int>& v2);

//Используя функцию transform, возвести все значения в векторе в квадрат.
void degree(vector<int>& v);


// Используя функцию generate, заполнить матрицу случайными целыми
// числами в диапазоне N...M.
void push_el_matrix(vector<vector<int>>& mat, int n, int m);

// Используя функцию for_each, вывести матрицу на экран.
void print_matrix(vector<vector<int>>& m);

//Используя функцию for_each, найти строку матрицы с минимальной
// суммой элементов.
void min_row_matrix(vector<vector<int>>& m);

//Используя функцию remove_if, удалить из матрицы нулевые строки
vector<vector<int>>::iterator remove_zero_row_matrix(vector<vector<int>>& m);

//Используя функцию transform, получить вектор минимальных по
// модулю значений в каждой строке матрицы.
void min_el_matrix_wVect(vector<vector<int>>& m);

//Используя функцию transform, найти произведение двух квадратных
//матриц.
void composition_matrix(vector<vector<int>>& mat, vector<vector<int>>& mat1);
