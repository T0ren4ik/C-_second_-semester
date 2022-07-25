#include "Tree.h"

// Копия 
void Tree::copy(node_ptr t, node_ptr& newT) const
{
	if (t) {
		newT = new TNode(t->data, 0, 0);
		copy(t->lt, newT->lt);
		copy(t->rt, newT->rt);
	}
	else
		newT = nullptr;
}

// Печать 
void Tree::printT(const node_ptr& t, ostream& os) const
{
	if (t) {
		printT(t->lt, os);
		os << t->data << " ";
		printT(t->rt, os);
	}
}
void Tree::printRKL(node_ptr t, int skip) {
	if (t->rt) printRKL(t->rt, skip + 2);
	for (int i = 0; i < skip; ++i) std::cout << " ";
	std::cout << t->data << "\n ";
	if (t->lt) printRKL(t->lt, skip + 2);
}

// Сравнение на равенство
bool Tree::equal(node_ptr t, node_ptr t2)
{
	if (t) {
		if (t2) {
			if (t->data == t2->data) {
				return equal(t->lt, t2->lt) && equal(t->rt, t2->rt);
			}
			else return false;
		}
		else return false;
	}
	else if (!t2) return false;
	return true;
}

// Добавление 
void Tree::add(node_ptr& t, int a) const
{
	if (!t) t = new TNode(a, 0, 0);
	else if (t->data < a) add(t->rt, a);
	else add(t->lt, a);
}

//Добавить новый узел с заданным значением слева от каждого листового узла.
void Tree::addLL(node_ptr& t, int a)
{
	if (!t);
	else if (t->lt == nullptr && t->rt == nullptr) t->lt = new TNode(a, 0);
	else {
		addLL(t->lt, a);
		addLL(t->rt, a);
	}
}

void Tree::delTree(node_ptr& t) const
{
	if (t) {
		delTree(t->lt);
		delTree(t->rt);
		delete t;
		t = nullptr;
	}
}
//=================
// Интерфейс
Tree::Tree(const Tree& t)
{
	copy(t.root, root);
}

Tree::Tree(int n) noexcept
{
	cout << "Введите " << n << " элементов через пробел\n";
	root = createTree(n);
}

Tree::~Tree()
{
	delTree(root);
}

void Tree::addNode(int a)
{
	add(root, a);
}

//Tree& Tree::operator=(const Tree& t)
//{
//	if (this != &t)
//		delTree(root);
//		copy(t.root, root);
//	return *this;
//}

bool Tree::operator==(const Tree& t)
{
	return equal(root, t.root);
}

void Tree::addLLeaves(int a)
{
	addLL(root, a);
}

ostream& operator<<(ostream& os, const Tree& t)
{
	t.printT(t.root, os);
	os << endl;
	return os;
}
