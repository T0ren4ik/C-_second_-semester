#include "List.h"

list::~list() {
	while (first) {
		node* cur = first;
		first = first->next;
		delete cur;
	}
	last = first = nullptr;
}

bool list::isEmpty() const {
	return (first == nullptr);
}

ostream& operator << (ostream& out, const list& y) {
	node* p = y.first;
	while (p) {
		out << *p << " ";
		p = p->next;
	}
	return out;
}

void list::addFirst(int x) {
	first = new node(x, first);
	if (!last)
		last = first;
}

void list::addLast(int x) {
	if (first) {
		last->next = new node(x, nullptr);
		last = last->next;
	}
	else
		first = last = new node(x, nullptr);
}

int list::getFirst() const {
	if (first)
		return first->data;
	else
		throw err;
}

int list::getLast()const {
	if (first)
		return last->data;
	else
		throw err;
}


int list::delFirst() {
	int x;
	if (first) {
		x = first->data;
		node* t = first;
		first = first->next;
		delete t;
		return x;
	}
	else
		throw err;
}

int list::delLast() {
	if (first) {
		int x;
		x = last->data;
		node* t = first;
		while (t->next != last)
			t = t->next;
		delete last;
		last = t;
		last->next = nullptr;
		return x;
	}
	else
		throw err;
}

int list::kol(bool(*f)(int)) {
	int k = 0;
	for (node* p = first; p; p = p->next)
		if (f(p->data))
			k++;
	return k;
}

void list::for_each(void(*action)(int&)) {
	node* p = first;
	while (p) {
		action(p->data);
		p = p->next;
	}
}




list_iter list::begin() const {
	return list_iter(this, first);
}

list_iter list::end() const {
	list_iter iter(this, nullptr);
	return iter;
}

void remove_after(node*& L) {
	if (L != nullptr && L->next != nullptr) {
		node* p = L->next;
		L->next = L->next->next;
		delete p;
	}
	else throw "Ёлемент отсуттствует";
}


void list_iter::delete_el()
{
	//if (*this == this->collection->begin()) 
	//	const_cast<list*>(this->collection)->delFirst();
	//else if (*this == this->collection->end()) 
	//	const_cast<list*>(this->collection)->delLast();
	//else {
	//	list_iter temp = this->collection->begin();
	//	list_iter temp_1 = this->collection->begin(); temp_1++;
	//	while (temp_1 != *this && (temp_1 != this->collection->end())) {
	//		temp_1++;
	//		temp++;
	//	}
	//	if(temp_1 != this->collection->end())
	//		remove_after(temp_1.cur);
	//}	
}


