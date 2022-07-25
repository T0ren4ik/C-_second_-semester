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

// Функция создания списка заданной длины, элементы списка вводятся с консоли.
//Порядок следования элементов должен совпадать с порядком ввода.
list* sp_create_to_tail();

//Функция вывода списка на консоль
void print_sp(list* L);

//Функция удаления списка.
void erase(list*& L);

//Количество элементов списка
int count_element_list(list* L);

//Функция поиска элемента
list* find_el(list* L, int x);

//Значение первого элемента спискa
int first_el(const list* L);

//Вставка элемента в начало списка
void add_first(list*& pn, int x);

//Вставка элемента в конец списка.
void add_end(list*& L, int x);

//Вставка нового значения перед указанным элементом списка.
list* add_el_i_position(list*& L, list* position, int x);

// Удаление элемента после указанного элемента списка
void remove_after(list*& L);

//Вставить новый элемент в список за первым элементом с заданным значением. Если
//вставить невозможно, функция должна выбрасывать исключение.
void add_i_past_pos(list*& L, int pos, int x);

//Удалить из списка все элементы с заданным значением.
void remove_after_el(list*& L, int el);

//Удаление хваста
void delTail(list*& L);

//Проверка, что лист упорядочен по возростанию
bool vozr_list(list* L);

//Проверить список на выполнение условия для элементов списка, условие задается
//функцией –параметром.
bool pred_list(list* L, bool (*f)(int));

//проверка на ноль
bool all_zero(int x);

//16 «Перевернуть» список, не используя операций выделения/освобождения
//динамической памяти.
list* revers_list(list* &L);