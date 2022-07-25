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

struct header_teil {
	list* H;
	list* T;
};

// ������� �������� ������ �������� �����, �������� ������ �������� � �������.
//������� ���������� ��������� ������ ��������� � �������� �����.
list* sp_create_to_tail();

//������� ������ ������ �� �������
void print_sp(list* L);

//������� �������� ������.
void erase(list*& L);

//���������� ��������� ������
int count_element_list(list* L);

//������� ������ ��������
list* find_el(list* L, int x);

//�������� ������� �������� �����a
int first_el(const list* L);

//������� �������� � ������ ������
void add_first(list*& pn, int x);

//������� �������� � ����� ������.
void add_end(list*& L, int x);

//������� ������ �������� ����� ��������� ��������� ������.
list* add_el_i_position(list*& L, list* position, int x);

// �������� �������� ����� ���������� �������� ������
void remove_after(list*& L);

//�������� ����� ������� � ������ �� ������ ��������� � �������� ���������. ����
//�������� ����������, ������� ������ ����������� ����������.
void add_i_past_pos(list*& L, int pos, int x);

//������� �� ������ ��� �������� � �������� ���������.
void remove_after_el(list*& L, int el);

//�������� ������
void delTail(list*& L);

//��������, ��� ���� ���������� �� �����������
bool vozr_list(list* L);

//��������� ������ �� ���������� ������� ��� ��������� ������, ������� ��������
//�������� �����������.
bool pred_list(list* L, bool (*f)(int));

//�������� �� ����
bool all_zero(int x);

//16 ������������� ������, �� ��������� �������� ���������/������������
//������������ ������.
list* revers_list(list* &L);