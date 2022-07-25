#pragma once
#pragma once
#include <iostream>
using namespace std;



class Tree {
private:
	struct TNode; // ����

	typedef TNode* node_ptr; // ��������� �� ����
	struct TNode { // �������� � ����������� ����
		int data;
		node_ptr lt, rt;
		TNode(int val, node_ptr l = nullptr, node_ptr r = nullptr) : data(val), lt(l), rt(r) {};
	};
	typedef TNode* node_ptr; // ��������� �� ����
	// �������, ������� ��������� � ����������� �� ���� ������ (node_ptr),
	// ������ ���� ��������� ��� private
	node_ptr root; // ��������� �� ������

	void delTree(node_ptr t) const;
	void add(node_ptr& t, int a);
	void printLKR(node_ptr t, ostream& os) const;
	void copy(node_ptr t, node_ptr& newT) const;
	void printRKL(node_ptr t, int skip = 0); // ������ � ���� ������ (����� �� TreeRec)
	int nodes(node_ptr t); // ���������� ����� (��� 15, ������� �������)
	int leaves(node_ptr t); // ���������� ������� (��� 15, ������� �������)
	int depth(node_ptr t); // ������� ������ (��� 15, ������� �������)
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
	// ��� ������� � �������� ��������, ������������ node_ptr,
	// ������������ �������� ������� ������, ������� �������� ����������� �������, 	��������� ��������� �� ������
	Tree() : root(nullptr) {} // ����������� �� ���������
	Tree(const Tree& t) { // ���������� �����������
		copy(t.root, root);
	}
	Tree(int n , int flag=1) {
		if (flag)
			root = createT(n);
		else {
			node_ptr t;
			int* a = new int[n];
			cout << "������� n ����� ����� ������: ";
			for (int i = 0; i < n; i++)
			{
				cin >> a[i];
			}
			width_balance(t, n, a, 0);
			root = t;
		}
	};
	~Tree() { // ����������
		delTree(root);
	}
	void addNode(int a) { // ���������� ����
		add(root, a);
	}
	friend ostream& operator<<(ostream& os, const Tree& t) {
		t.printLKR(t.root, os);
		return os;
	} // ����� � �����
	void printTree() { // ������ ������
		printRKL(root);
	}
	int depth_tree() { // ������� ������
		return depth(root);
	}
	bool eq_tree(const Tree& t2) { // ��������� ������ t2
		return equal(root, t2.root);
	}
	int leaves_count() { // ���������� ������� � ������
		return leaves(root);
	}
	int nodes_count() { // ���������� ����� � ������
		return nodes(root);
	}
	// ���������� ��������� ������������ 
	Tree& operator=(const Tree& other) {
		if (this != &other) { // ������� �� �����, ����� ���� ����� ���-�� ������ ������
			copy(other.root, root); // �������� ����������� ����������� ������ � ������ other � ������ � ������ root
		}
		return *this; // ���������� ���� (������ � ������ root)
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