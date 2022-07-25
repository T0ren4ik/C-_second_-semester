#pragma once
#include <iostream>

using namespace std;

struct list {
	int inf;
	list* next;

	list(int inf, list* next) {
		this->inf = inf;
		this->next = next;
	}
};

//{
// Функция создания списка заданной длины, элементы списка вводятся с консоли.
//Порядок следования элементов должен совпадать с порядком ввода.
list* sp_create_to_tail();

//Функция вывода списка на консоль
void print_sp(list* L);

//Функция удаления списка.
void erase(list*& L);
//}

//=========================================================================================================

//Функция определения длины списка.
int len_list(list* L);

//Посчитать количество элементов списка с заданным значением.
int count_elemennt_equivalent_x(list* L, int x);

//Проверить, что в списке нет элементов с заданным значением
bool no_elemen_equivalent_x(list* L, int x);

//Напечатать элементы списка в обратном порядке
void reversePrintSp(list* L);

//=========================================================================================================


struct elem {
	int inf;
	elem* lt, *rt;

	elem(int inf, elem* lt, elem* rt) {
		this->inf = inf;
		this->lt = lt;
		this->rt = rt;
	}
};

//4 Создать сбалансированное дерево из N вершин
elem* createT(int n);
void eraseT(elem* t);
void printLKR(elem* t);
void printTREE(elem* t, int n);

//1)Найти количество нулевых значений в вершинах дерева
int count_zero_el(elem* t);

//2) Найти максимальный элемент (значение) в дереве
int max_el_tree(elem* t);

//3) Определить глубину дерева
int maxDepth(elem* T);

//5) Добавить элемент в дерево поиска, сохраняя упорядоченность 
void insert_el_in_tree(elem*& t, int a);

//6) Создать копию дерева
elem* dublicate(elem* t, elem*& copy);

//7) Проверить два дерева на равенство(одинаковая структура и значения в узлах).
bool equivalent_tree(elem* t1, elem*& t2);

//8) Проверить дерево на упорядоченность значений в вершинах (по возрастанию)
bool rise_el_tree(elem* t);
