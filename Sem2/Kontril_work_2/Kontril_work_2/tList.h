#pragma once
#include <iostream>

using namespace std;

// Элемент списка
struct Node
{
public:
	int data;
	Node* next;

	Node(int data, Node* next) {
		this->data = data;
		this->next = next;
	}
	
	// Вывод одного элемента списка
	friend 	ostream & operator<< (ostream & os, const Node & n);
};

class Error { 
public:
	void what() {
		cout << "Out of range.\n";
	}
};

class List {
private:
	//Структура
	Node* first;
	Node* last;
	Error err;

	// Индексация и создание списка
	int index(int i) const;
	void create(int n, List& l);
	void del();
public:
	// Основные функции
	List(int n = 0);
	List(Node* f, Node* l);
	~List();

	bool isEmpty() const; // Проверка на пустоту
	void push_back(int a); // Добавление в конец
	void push_front(int a); // В началро
	int size(); // Размер

	//Продублировать все элементы списка  не равные своему следующему соседу.
	void duplication(); 

	// Индексация
	int operator[] (int i)const;
	List& operator=(const List& l) ; // Опретор присваивания
	
	friend ostream & operator << (ostream & os, const List & l); // вывод в консоль
};



