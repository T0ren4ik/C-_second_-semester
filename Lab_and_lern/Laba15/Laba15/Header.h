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
// ������� �������� ������ �������� �����, �������� ������ �������� � �������.
//������� ���������� ��������� ������ ��������� � �������� �����.
list* sp_create_to_tail();

//������� ������ ������ �� �������
void print_sp(list* L);

//������� �������� ������.
void erase(list*& L);
//}

//=========================================================================================================

//������� ����������� ����� ������.
int len_list(list* L);

//��������� ���������� ��������� ������ � �������� ���������.
int count_elemennt_equivalent_x(list* L, int x);

//���������, ��� � ������ ��� ��������� � �������� ���������
bool no_elemen_equivalent_x(list* L, int x);

//���������� �������� ������ � �������� �������
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

//4 ������� ���������������� ������ �� N ������
elem* createT(int n);
void eraseT(elem* t);
void printLKR(elem* t);
void printTREE(elem* t, int n);

//1)����� ���������� ������� �������� � �������� ������
int count_zero_el(elem* t);

//2) ����� ������������ ������� (��������) � ������
int max_el_tree(elem* t);

//3) ���������� ������� ������
int maxDepth(elem* T);

//5) �������� ������� � ������ ������, �������� ��������������� 
void insert_el_in_tree(elem*& t, int a);

//6) ������� ����� ������
elem* dublicate(elem* t, elem*& copy);

//7) ��������� ��� ������ �� ���������(���������� ��������� � �������� � �����).
bool equivalent_tree(elem* t1, elem*& t2);

//8) ��������� ������ �� ��������������� �������� � �������� (�� �����������)
bool rise_el_tree(elem* t);
