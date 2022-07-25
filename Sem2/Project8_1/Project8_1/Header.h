#pragma once
#pragma once
#include <iostream>
using namespace std;



class Tree {
private:
	struct TNode; // узел

	typedef TNode* node_ptr; // указатель на узел
	struct TNode { // рекурсия в определении типа
		int data;
		node_ptr lt, rt;
		TNode(int val, node_ptr l = nullptr, node_ptr r = nullptr) : data(val), lt(l), rt(r) {};
	};
	typedef TNode* node_ptr; // указатель на узел
	// Функции, которые оперируют с указателями на узел дерева (node_ptr),
	// должны быть объявлены как private
	node_ptr root; // указатель на корень

	void delTree(node_ptr t) const;
	void add(node_ptr& t, int a);
	void printLKR(node_ptr t, ostream& os) const;
	void copy(node_ptr t, node_ptr& newT) const;
	void printRKL(node_ptr t, int skip = 0); // печать в виде дерева (взято из TreeRec)
	int nodes(node_ptr t); // количество узлов (Лаб 15, прошлый семестр)
	int leaves(node_ptr t); // количество листьев (Лаб 15, прошлый семестр)
	int depth(node_ptr t); // глубина дерева (Лаб 15, прошлый семестр)
	bool equal(node_ptr t, node_ptr t2);

	node_ptr createT(int n) {
		node_ptr p;
		int d, inf;
		if (n > 0) {
			cout << "Another element?";
			cin >> inf;
			d = n / 2;
			p = new TNode(inf, createT(d), createT(n - 1 - d));
			return p;
		}
		else
			return nullptr;
	}

	void width_balance(node_ptr& t, int n, int* a, int i) {
		if (i < n) {
			t = new TNode(a[i]);
			if (n >= 2 * i + 1)
				width_balance(t->lt, n, a, 2 * i + 1);
			if (n >= 2 * i + 2)
				width_balance(t->rt, n, a, 2 * i + 2);
		}
	}

public:
	// Для доступа к закрытым функциям, использующим node_ptr,
	// используются открытые функции класса, которые вызывают рекурсивные функции, 	передавая указатель на корень
	Tree() : root(nullptr) {} // конструктор по умолчанию
	Tree(const Tree& t) { // копирующий конструктор
		copy(t.root, root);
	}
	Tree(int n , int flag=1) {
		if (flag)
			root = createT(n);
		else {
			node_ptr t;
			int* a = new int[n];
			cout << "Введите n чисел через пробел: ";
			for (int i = 0; i < n; i++)
			{
				cin >> a[i];
			}
			width_balance(t, n, a, 0);
			root = t;
		}
	};
	~Tree() { // деструктор
		delTree(root);
	}
	void addNode(int a) { // добавление узла
		add(root, a);
	}
	friend ostream& operator<<(ostream& os, const Tree& t) {
		t.printLKR(t.root, os);
		return os;
	} // вывод в поток
	void printTree() { // печать дерева
		printRKL(root);
	}
	int depth_tree() { // глубина дерева
		return depth(root);
	}
	bool eq_tree(const Tree& t2) { // равенство дереву t2
		return equal(root, t2.root);
	}
	int leaves_count() { // количество листьев в дереве
		return leaves(root);
	}
	int nodes_count() { // количество узлов в дереве
		return nodes(root);
	}
	// Перегрузка оператора присваивания 
	Tree& operator=(const Tree& other) {
		if (this != &other) { // деревья не равны, тогда есть смысл что-то вообще делать
			copy(other.root, root); // вызываем копирование содержимого дерева с корнем other в дерево с корнем root
		}
		return *this; // возвращаем себя (дерево с корнем root)
	}
};


/*
Node* & List::indexS(int i)
{
	if (first) {
		Node* cur = first;
		while (i > 0 && cur != last)
		{
			cur = first->next;
			i--;
		}
		if (i == 0) return cur;
		else throw err;
	}
	else throw err;
}

int List::delFirst()
{
	if (first) {
		Node* cut = first;
		int x = cut->data;
		first = first->next;
		delete cut;
		return x;
	}
	else
		throw err;
}

int List::delLast()
{
	if (first) {
		Node* cur = first;
		while (cur->next != last)
			cur = cur->next;
		int x = last->data;
		delete last;
		last = cur;
		last->next = nullptr;
		return x;
	}
	else
		throw err;
}


*/