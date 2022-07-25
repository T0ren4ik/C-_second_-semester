#pragma once
#include <iostream>

using namespace std;


class Tree {
private:
	// Структура
	struct TNode;
	typedef TNode* node_ptr;
	struct TNode {
		int data;
		node_ptr lt, rt;
		TNode(int val = 0, node_ptr l = nullptr, node_ptr r = nullptr) : data(val), lt(l), rt(r) {}
	};
	// Элемент
	node_ptr root;

	void copy(node_ptr t, node_ptr& newT) const; // конструктор копии
	void delTree(node_ptr& t) const;            // удаление дерева
	// печать дерева
	void printT(const node_ptr& t, ostream& os) const;  
	void printRKL(node_ptr t, int skip = 0);

	void add(node_ptr& t, int a) const; // Добавление в дерево
	bool equal(node_ptr t, node_ptr t2); // проверка на равенство

	// Создание сбалансированного дерева (для тестов)
	node_ptr createTree(int n) {
		if (n > 0) {
			int x, d = n / 2;
			//cout << "Another element?";

			cin >> x;
			node_ptr res = new TNode(x, createTree(d), createTree(n - d - 1));
			return res;
		}
		else return nullptr;
	} 
	//Добавить новый узел с заданным значением слева от каждого листового узла.
	// По умолчанию считаем, что в пустое дерево не добавляем
	void addLL(node_ptr& t, int a); 
public: 
	//Основные функции класса
	Tree() : root(nullptr) {}
	Tree(const Tree& t);	
	Tree(int n) noexcept;
	~Tree(); 

	void addNode(int a); // узел добавляется по правилу дерева поиска
	//Tree& operator=(const Tree& t);
	bool operator==(const Tree& t); // equal // проверка на равенство
	void printTree() { // печать дерева
		printRKL(root);
		cout << "===================================\n";
	}

	void addLLeaves(int a); // Задание
	friend ostream& operator<<(ostream& os, const Tree &t) ; // Вывод на экран элементов
};