#pragma once
#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int data, Node* next) {
		this->data = data;
		this->next = next;
	}

	friend 	ostream & operator<< (ostream & out, const Node & x);
};


class Error { //����� ������� ���������� ��� ����������� �� exception
};

class List_iter;

class List {
private:
	Node* first;
	Node* last;
	Error err;
public:
	List() : first(nullptr), last(nullptr) {	}
	~List();
	bool isEmpty() const;
	void addFirst(int x);
	void addLast(int val);
	int getFirst()const;
	int getLast()const;
	int delFirst();
	int delLast();
	//��������� � ����������
	int kol(bool(*f) (int));
	void for_each(void(*action)(int &));
	//� ������ ���������� ����� ���� ��� �������
	List_iter begin()const; 

	List_iter end()const; 

	friend ostream & operator << (ostream & out, const List & y);

};
//���������� ������� ��������� ���������
/*
List_iter List:: begin()const {
return List_iter(this, first);
}

List_iter List::end()const {
return List_iter(this, nullptr);
}
*/

// ������ ������� ��� �������� ������ 
//	int kol(bool(*f) (int));

/*
bool odd(int x)
{
	return x % 2 != 0;
}*/
// ������ ������� ��� �������� ������ 
//	void for_each(void(*action)(int &));
/*
void mult2(int & x) {
	x *= 2;
}*/


class List_iter {
private:
	const List *collection;
	Node *cur;
public:
	List_iter(const List *s, Node *e) : collection(s), cur(e) {}
	 int& operator *() {
		if (cur)      return cur->data;
		else         throw Error();
	}
	List_iter operator++() { //���������� ++
		if (cur) {
			cur = cur->next;
			return *this;
		}
		else throw Error();
	}
	bool operator == (const List_iter &ri) const {
		return ((collection == ri.collection) && (cur == ri.cur));
	}
	bool operator != (const List_iter &ri) const {
		return !(*this == ri);
	}

};



