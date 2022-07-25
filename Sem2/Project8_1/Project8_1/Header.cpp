#include "Header.h"


void Tree::delTree(node_ptr t) const{
	// int c;
	if (t != nullptr) {
		delTree(t->lt); // удалили левое поддерево
		delTree(t->rt); // удалили правое поддерево
		delete t; // удалили корень
		t = nullptr; // обнулили указатель
	}
}
void Tree::add(node_ptr& t, int a) {
	if (t == nullptr) t = new TNode(a); // если корень дерева был пустым => создаем голову
	else if (t->data > a) add(t->lt, a);
	else add(t->rt, a);
}
void Tree::printLKR(node_ptr t, ostream& os) const {
	if (t) {
		printLKR(t->lt, os);
		os << t->data << " ";
		printLKR(t->rt, os);
	}
}
void Tree::copy(node_ptr t, node_ptr& newT) const //KLR
{
	if (t != nullptr)
	{
		newT = new TNode(t->data, 0, 0);
		copy(t->lt, newT->lt);
		copy(t->rt, newT->rt);
	}
	else newT = nullptr;
}
// печать в виде дерева (взято из TreeRec)
void Tree::printRKL(node_ptr t, int skip) {
	if (t->rt) printRKL(t->rt, skip + 2);
	for (int i = 0; i < skip; ++i) std::cout << " ";
	std::cout << t->data << "\n ";
	if (t->lt) printRKL(t->lt, skip + 2);
}
// глубина дерева (Лаб 15, прошлый семестр)
int Tree::depth(node_ptr t) {
	if ((t == nullptr) || ((t->rt == nullptr) && (t->lt == nullptr))) return 0;
	return 1 + max(depth(t->lt), depth(t->rt)); // поиск в глубину
}
// равенство деревьев (Лаб 15, прошлый семестр)

bool Tree::equal(node_ptr t, node_ptr t2) {
	if (t) { // первое дерево непустое
		if (t2) { // и второе дерево непустое
			if (t->data != t2->data) return false; // встретили неравные элементы
			return equal(t->lt, t2->lt) && equal(t->rt, t2->rt);
		}
		else return false; // первое - непустое, а второе - пустое
	}
	else if (t2) return false; // первое - пустое, а второе - непустое
	return true; // если не вышли с false
}



// количество листьев (Лаб 15, прошлый семестр)
int Tree::leaves(node_ptr t) {
	if (t == nullptr) return 0; // пустое дерево
	if (t->lt == nullptr && t->rt == nullptr) return 1; // нашли узел без потомков

	return leaves(t->lt) + leaves(t->rt); // накапливаем листы с поддеревьев
}

// количество узлов (Лаб 15, прошлый семестр)
int Tree::nodes(node_ptr t) {
	if (t) {
		return 1 + nodes(t->lt) + nodes(t->rt); // обходим левую и правую часть + 1
	}
	else return 0; // пустое дерево
}

