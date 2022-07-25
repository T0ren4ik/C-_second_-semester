#include "Header.h"


void Tree::delTree(node_ptr t) const{
	// int c;
	if (t != nullptr) {
		delTree(t->lt); // ������� ����� ���������
		delTree(t->rt); // ������� ������ ���������
		delete t; // ������� ������
		t = nullptr; // �������� ���������
	}
}
void Tree::add(node_ptr& t, int a) {
	if (t == nullptr) t = new TNode(a); // ���� ������ ������ ��� ������ => ������� ������
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
// ������ � ���� ������ (����� �� TreeRec)
void Tree::printRKL(node_ptr t, int skip) {
	if (t->rt) printRKL(t->rt, skip + 2);
	for (int i = 0; i < skip; ++i) std::cout << " ";
	std::cout << t->data << "\n ";
	if (t->lt) printRKL(t->lt, skip + 2);
}
// ������� ������ (��� 15, ������� �������)
int Tree::depth(node_ptr t) {
	if ((t == nullptr) || ((t->rt == nullptr) && (t->lt == nullptr))) return 0;
	return 1 + max(depth(t->lt), depth(t->rt)); // ����� � �������
}
// ��������� �������� (��� 15, ������� �������)

bool Tree::equal(node_ptr t, node_ptr t2) {
	if (t) { // ������ ������ ��������
		if (t2) { // � ������ ������ ��������
			if (t->data != t2->data) return false; // ��������� �������� ��������
			return equal(t->lt, t2->lt) && equal(t->rt, t2->rt);
		}
		else return false; // ������ - ��������, � ������ - ������
	}
	else if (t2) return false; // ������ - ������, � ������ - ��������
	return true; // ���� �� ����� � false
}



// ���������� ������� (��� 15, ������� �������)
int Tree::leaves(node_ptr t) {
	if (t == nullptr) return 0; // ������ ������
	if (t->lt == nullptr && t->rt == nullptr) return 1; // ����� ���� ��� ��������

	return leaves(t->lt) + leaves(t->rt); // ����������� ����� � �����������
}

// ���������� ����� (��� 15, ������� �������)
int Tree::nodes(node_ptr t) {
	if (t) {
		return 1 + nodes(t->lt) + nodes(t->rt); // ������� ����� � ������ ����� + 1
	}
	else return 0; // ������ ������
}

