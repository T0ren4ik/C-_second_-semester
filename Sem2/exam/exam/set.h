#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <stack>


using namespace std;

template<typename type>
class Tree {
private:
	struct TNode;
	typedef TNode* node_ptr;
	struct TNode {
		type data;
		node_ptr lt, rt;
		TNode(type val = 0, node_ptr l = nullptr, node_ptr r = nullptr) : data(val), lt(l), rt(r) {}
	};
	node_ptr root;
	int t_size = 0;

	void copy_(node_ptr t, node_ptr& newT) const {
		if (t) {
			newT = new TNode(t->data);
			copy_(t->lt, newT->lt);
			copy_(t->rt, newT->rt);
		}
		else
			newT = nullptr;
	}

	void delTree(node_ptr t){
		if (t) {
			delTree(t->lt);
			delTree(t->rt);
			delete t;
			t = nullptr;
			t_size = 0;
		}
	}

	void printT(const node_ptr t, ostream& os) const {

		if (t != nullptr) {
			printT(t->lt, os);
			os << t->data << " ";
			printT(t->rt, os);
		}
	}

	void add(node_ptr& t, type key) {
		node_ptr curr = t;
		if (!t) { 
			t = new TNode(key); 
			t_size++;
			return; 
		}

		while (curr && curr->data != key)
		{

			if (curr->data > key && curr->lt == nullptr)
			{
				curr->lt = new TNode(key);
				t_size++;

				return;
			}
			if (curr->data < key && curr->rt == nullptr)
			{
				curr->rt = new TNode(key);
				t_size++;

				return;
			}
			if (curr->data > key)
				curr = curr->lt;
			else
				curr = curr->rt;
		}
	}
	void addT(node_ptr& t, node_ptr t1) {
		if (t1) {
			add(t, t1->data);
			addT(t, t1->lt);
			addT(t, t1->rt);
		}
		
	}
	void intersection(node_ptr t, node_ptr t1, node_ptr& res) {
		if (t && search(t1, t->data)) {
			add(res, t->data);
			intersection(t->lt, t1, res);
			intersection(t->rt, t1, res);
		}
	}
	
	void printRKL(node_ptr t, int skip = 0) {
		if (t->rt) printRKL(t->rt, skip + 2);
		for (int i = 0; i < skip; ++i) std::cout << " ";
		std::cout << t->data << "\n ";
		if (t->lt) printRKL(t->lt, skip + 2);
	}
	// функция нерекурсивного обхода
	void SymmetricOrder_BinaryTree_Loop(node_ptr Node)
	{
		stack<node_ptr> stack;

		while (Node != nullptr || !stack.empty())
		{
			while (Node != nullptr)
			{
				stack.push(Node);
				Node = Node->lt;
			}

			cout << stack.top()->data << ' ';
			Node = stack.top()->rt;
			stack.pop();
		}
		cout <<'\n';
	}
	bool equal(node_ptr t, node_ptr t2) {
		if (t) {
			if (t2) {
				if (t->data == t2->data) {
					return equal(t->lt, t2->lt) && equal(t->rt, t2->rt);
				}
				else return false;
			}
			else return false;
		}
		else if (!t2) return true;
		return false;
	}
	bool equal_AllEl(node_ptr t, node_ptr t2) {
		if (t) {
			if (search(t2, t->data))
				return equal_AllEl(t->lt, t2) && equal_AllEl(t->rt, t2);
			else return false;
		}
		return true;
		
	}

	node_ptr search(const node_ptr t, type key) {
		if (!t) return 0;
		else if (t->data == key) return t;
		else if (t->data > key)
			search(t->lt, key);
		else
			search(t->rt, key);
	}
	node_ptr createBalTree(int n) {

		if (n > 0) {
			type x;
			int d = n / 2;

			cin >> x;
			t_size++;

			node_ptr res = new TNode(x, createBalTree(d), createBalTree(n - d - 1));
			return res;
		}
		else return nullptr;
	}
	void createBinTree() {	// сделать проще
		vector<type> vec;
		string token;
		string str;
		getline(cin, str);
		istringstream iss(str);
		while (getline(iss, token, ' '))
			vec.push_back(stoi(token));

		for (type x : vec) {
			add(root, x);
		}
	}
	//Удаление
	void deleteEl(node_ptr& t, type a) {
		if (t != 0)
			if (a == t->data) {
				deleteNode(t); // узел найден - удаляем
			}
			else if (a < t->data)
				deleteEl(t->lt, a); // рекурсия
			else
				deleteEl(t->rt, a); // рекурсия
	}
	void deleteNode(node_ptr & t) {
		// 1. корень является листом
		// 2. у корня нет левого поддерева
		// 3. у корня нет правого поддерева
		// 4. корень имеет два поддерева
		node_ptr delNode;
		int repl;
		if ((t->lt == 0) && (t->rt == 0)) {// 1
			delete t;
			t = 0;
		}
		else if (t->lt == 0) {// 2
			delNode = t;
			t = t->rt;
			delete delNode;
		}
		else if (t->rt == 0) {// 3
			delNode = t;
			t = t->lt;
			delete delNode;
		}
		else {// 4
			delLeftLeaf(t->rt, repl);
			t->data = repl;
		}
		t->t_size--;

	}
	void delLeftLeaf(node_ptr& t, type& repl) {
		if (t->lt == 0) {// у самого левого нет левых потомков
			repl = t->data;
			node_ptr delNode = t;
			t = t->rt;
			delete delNode;
		}
		else
			delLeftLeaf(t->lt, repl);
	}
public:
	Tree() : root(nullptr) {}
	Tree(const Tree<type>& t) {
		t_size = t.t_size;
		copy_(t.root, root);
	}
	Tree(int n, int f = 1) {
		cout << "Введите " << n << " элементов через пробел: ";
		if (!f) {
			root = createBalTree(n);
		}
		else {
			createBinTree();
		}
	}
	~Tree() {
		delTree(root);
	}
	void addNode(type a) {
		add(root, a);
	}
	Tree<type> addTree(Tree& t) {
		Tree<type> t2;
		copy_(t.root, t2.root);
		addT(t2.root, root);
		return t2;
	}
	Tree<type> intersectionTree(Tree& t) {
		Tree<type> t2;
		intersection(t.root, root, t2.root);
		return t2;
	}
	node_ptr find(type x){
		return search(root, x);
	}
	Tree<type>& operator=(const Tree& t) {
		if (this != &t) {
			delTree(root);
			copy_(t.root, root);
		}
		return *this;
	}
	bool operator==(const Tree& t) {
		return equal(root, t.root);
	}
	bool euqal_data(const Tree& t) {
		return equal_AllEl(root, t.root);
	}
	int size() {
		return t_size;
	}
	void printTree() { // печать дерева
		printRKL(root);
		cout << "===================================\n";
	}
	void printTS() {
		SymmetricOrder_BinaryTree_Loop(root);
		cout << "===================================\n";
	}
	void delEl(type x) {
		deleteEl(root, x);
	}
	friend ostream& operator<<(ostream& os, const Tree<type>& t) {
		t.printT(t.root, os);
		os << endl;
		return os;
	}

};


template<typename type>
class set
{
private:
	Tree<type> T;
public: 
	set() {
		T = Tree<type>();
	}
	set(int n) {
		T = Tree<type>(n);
	}
	set<type>* operator+=(type x) {
		T.addNode(x);
		return this;
	}
	set<type>* operator-=(type x) {
		T.delEl(x);
		return this;
	}	
	set<type> operator+(set s) {
		set<type>* temp = T.addTree(s.T);
		return temp;
	}
	set<type> operator*(set s) {
		set<type>* temp = T.intersectionTree(s.T);
		return temp;
	}
	bool operator==(set s) {
		return T.euqal_data(s.T);
	}
	friend ostream& operator<<(ostream& os, const set<type>& s) {
		os << s.T;
		return os;
	}

};
