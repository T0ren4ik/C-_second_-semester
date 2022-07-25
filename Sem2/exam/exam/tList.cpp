#include "tList.h"

ostream& operator<<(ostream& os, const Node& n)
{
	os << n.data;
	return os;
}

ostream& operator<<(ostream& os, const List& l)
{
	Node* p = l.first;
	while (p) {
		os << *p << " ";
		p = p->next;
	}
	return os;
}

int List::index(int i) const
{
	if (first) {
		Node* cur = first;
		while (i > 0 && cur != last)
		{
			cur = first->next;
			i--;
		}
		if (i == 0) return cur->data;
		else throw err;
	}
	else throw err;
}


void List::create(int n, List& l)
{
	Node* p;
	int x;
	cout << "Введите " << n << " элементов через пробел.\n";
	cin >> x;
	l.first = l.last = new Node(x, 0);
	for (int i = 1; i < n; ++i) {
		cin >> x;
		l.push_back(x);
	}
}

List::List(int n)
{
	if (!n) {
		first = nullptr;
		last = nullptr;
	}
	else {
		create(n, *this);
	}
}

List::List(Node* f, Node* l): first(f), last(l){}

List::~List()
{
	while (first) {
		Node* cur = first;
		first = first->next;
		delete cur;
	}
	last = first = nullptr;
}

bool List::isEmpty() const
{
	return (!first && !last);
}

void List::push_back(int a)
{
	if (first) {
		last->next = new Node(a, nullptr);
		last = last->next;
	}
	else {
		first = last = new Node(a, nullptr);
	}
}

void List::push_front(int a)
{
	first = new Node(a, first);
	if (!last)
		last = first;
}


int List::size()
{
	int count = 0;
	if (first) {
		Node* t = first;
		while (t != nullptr) {
			count++;
			t = t->next;
		}
	}
	return count;
}

void List::duplication()
{
	if(int n = size()){
		Node* t = first;
		Node* temp;
		if (n == 1) return;
		while(t->next){
			if (t->data != t->next->data) {
				t->next = new Node(t->data, t->next);
				t = t->next;
			}
			t = t->next;
		}
	}
}

int List::operator[](int i) const
{
	try {
		return index(i);
	}
	catch (Error& E) {
		E.what();
	}
}

List& List::operator=(const List& l)
{
	if (this->first != l.first) {
		Node* cur = l.first;
		List* temp = this;
		delete temp;

		this->first = this->last = l.first;
		if (l.isEmpty()) {
			cur = cur->next;
			while (cur)
			{
				push_back(cur->data);
			}
		}
	}
	return *this;
}

