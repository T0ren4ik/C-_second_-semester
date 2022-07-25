#pragma once
#include <iostream>

using namespace std;

struct node
{
	int data;
	node* next;

	node(int data, node* next) {
		this->data = data;
		this->next = next;
	}

	friend ostream& operator << (ostream& out, const node& x) {
		out << x.data;
		return out;
	}
};


class Error {
public:
	void what() {
		cout << "Iterator error" << endl;
	}
};

class list_iter;

class list {
private:
	node* first;
	node* last;
	Error err;
public:
	list() : first(nullptr), last(nullptr) {	}
	~list();
	bool isEmpty() const;
	void addFirst(int x);
	void addLast(int val);
	int getFirst()const;
	int getLast()const;
	int delFirst();
	int delLast();
	//обработка с предикатом
	int kol(bool(*f) (int));
	void for_each(void(*action)(int&));
	//в полной реализации могут быть еще функции
	list_iter begin()const;

	list_iter end()const;
	friend ostream& operator << (ostream& out, const list& y);
};



class list_iter {
private:
	const list* collection;
	node* cur;
public:
	list_iter(const list* s,  node* e) : collection(s), cur(e) {}
	int& operator *() {
		if (cur)      return cur->data;
		else         throw Error();
	}
	list_iter operator++() { //префиксный ++
		if (cur) {
			cur = cur->next;
			return *this;
		}
		else throw Error();
	}
	bool operator == (const list_iter& ri) const {
		return ((collection == ri.collection) && (cur == ri.cur));
	}
	bool operator != (const list_iter& ri) const {
		return !(*this == ri);
	}

	void delete_el();

};
