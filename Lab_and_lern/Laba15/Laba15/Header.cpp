#include "Header.h"


//Функция создания списка заданной длины, элементы списка вводятся с консоли.
//Порядок следования элементов должен совпадать с порядком ввода.
list* sp_create_to_tail() {
	list* head, * p, * tail;
	int n, el;
	cout << "size list->";
	cin >> n; head = tail = nullptr;
	if (n > 0) {
		cout << "list item -> ";
		cin >> el;
		head = tail = new list(el, nullptr);
	}
	for (int i = 1; i < n; ++i) {
		cout << "list item -> ";
		cin >> el;
		p = new list(el, nullptr);
		tail->next = p;
		tail = p;
	}
	return head;
}

//4 Функция удаления списка. (Можно ли без создания нового списка, поидее L адресс не должен менятся)
void erase(list*& L) {
	list* t;
	t = L;
	while (t != NULL) {
		L = t->next;
		delete t;
		t = L;
	}
}


//3 Функция вывода списка на консоль
void print_sp(list* L) {
	if (L) {
		list* p;
		p = L;
		for (; p; p = p->next) {
			cout << p->inf << " ";
		}
		cout << "\n";
	}
	else throw "Список пуст!";
}


//=========================================================================================================
//Функция определения длины списка.
int len_list(list* L) {
	if (L) {
		return 1 + len_list(L->next);
	}
	else
		return 0;
}


//Посчитать количество элементов списка с заданным значением.
int count_elemennt_equivalent_x(list* L, int x){
	if (L) {	
		//if (L->inf == x)
		//	return 1 + count_elemennt_equivalent_x(L->next, x);
		//else 
		//	return 0 + count_elemennt_equivalent_x(L->next, x);
		return (L->inf == x) ? 1 + count_elemennt_equivalent_x(L->next, x) : 0 + count_elemennt_equivalent_x(L->next, x);
	}
	else
		return 0;
}


//Проверить, что в списке нет элементов с заданным значением
bool no_elemen_equivalent_x(list* L, int x){
	if (L) {
		if (L->inf == x) return false;			
		else return no_elemen_equivalent_x(L->next, x);
	}
	else
		return true;
}


//Напечатать элементы списка в обратном порядке
void reversePrintSp(list* L) {
	if (L) {
		reversePrintSp(L->next);
		cout << L->inf << " ";
	}
	else
		cout << "Reverse print" << endl;
}

//=========================================================================================================
//Печать узла
void printTREE(elem* t, int n) {
	if (t != NULL) {
		printTREE(t->rt, n + 1);
		for (int i = 0; i < n; ++i)
			cout << " ";
		cout << t->inf << endl;
		printTREE(t->lt, n + 1);
	}
}

//4 Создать сбалансированное дерево из N вершин
elem* createT(int n) {
	elem* p;
	int d, inf;
	if (n > 0) {
		cout << "Another element?";
		cin >> inf;
		d = n / 2;
		p = new elem(inf, createT(d), createT(n - 1 - d));
		return p;
	}
	else
		return nullptr;
}

//инфиксная печать
void printLKR(elem* t) {
	if (t != NULL) {
		printLKR(t->lt);
		cout << t->inf << " ";
		printLKR(t->rt);
	}
}

//Удаление
void eraseT(elem* t) {
	if (t != NULL) {
		eraseT(t->lt);
		eraseT(t->rt);
		delete(t);
	}
}

//Найти количество нулевых значений в вершинах дерева
int count_zero_el(elem* t) {
	if (t) {
		if (t->inf != 0)
			return count_zero_el(t->lt) + count_zero_el(t->rt);
		else
			return 1 + count_zero_el(t->lt) + count_zero_el(t->rt);
	}
	else return 0;
}

//2) Найти максимальный элемент (значение) в дереве
int max_el_tree(elem* t) {
	int max1 = t->inf;
	int max2;
	if (t->lt) {
		max2 = max_el_tree(t->lt);
		if (max2 > max1) max1 = max2;
	}
	if (t->rt) {
		max2 = max_el_tree(t->rt);
		if (max2 > max1) max1 = max2;
	}
	return max1;
}

//3) Определить глубину дерева
int maxDepth(elem* T){
	if (T == nullptr) return 0;
	return max(maxDepth(T->lt), maxDepth(T->rt));
}

//5) Добавить элемент в дерево поиска, сохраняя упорядоченность 
void insert_el_in_tree(elem*& t, int a) {
	if (!t) {
		t = new elem(a, nullptr, nullptr);
	}
	else {
		if (a < t->inf) insert_el_in_tree(t->lt, a);
		else insert_el_in_tree(t->rt, a);
	}
}

//6) Создать копию дерева
elem* dublicate(elem* t, elem* &copy){
	if (t == nullptr)	{
		return nullptr;
	}	
	copy = new elem(t->inf, dublicate(t->lt, copy), dublicate(t->rt, copy));

	return copy;
}

//7) Проверить два дерева на равенство(одинаковая структура и значения в узлах).
bool equivalent_tree(elem* t1, elem*& t2) {
	if (t1) {
		if (t2) {
			if (t1->inf != t2->inf) return false;
			equivalent_tree(t1->lt, t2->lt);
			equivalent_tree(t1->rt, t2->rt);
		}
		else return false;
	}
	else if (t2) return false;

	return true;
}


//8) Проверить дерево на упорядоченность значений в вершинах (по возрастанию)
bool rise_el_tree(elem* t){
	if (t) {

	}

	return false;
}
