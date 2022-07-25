#pragma once
#include <iostream>

using namespace std;

struct Node
{
public:
	int data;
	Node* next;

	Node(int data, Node* next) {
		this->data = data;
		this->next = next;
	}
	
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
	Node* first;
	Node* last;
	Error err;
	int index(int i) const;
	void create(int n, List& l);
public:
	List(int n = 0);
	List(Node* f, Node* l);
	~List();
	bool isEmpty() const;
	void push_back(int a);
	void push_front(int a);
	int size();

	void duplication();

	int operator[] (int i)const;
	List& operator=(const List& l);
	
	friend ostream & operator << (ostream & os, const List & l);
};



