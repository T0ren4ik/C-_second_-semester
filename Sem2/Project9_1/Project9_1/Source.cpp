#include "List.h"
// ������ ������� ��� �������� ������ 
//int kol(bool(*f) (int));


bool odd(int x)
{
	return x % 2 != 0;
}

// ������ ������� ��� �������� ������ 
//	void for_each(void(*action)(int &));

void mult2(int& x) {
	x *= 2;
}

int main() {
	//�������� ������������� �������� pn1
	node* pn1 = new node(5, nullptr);
	//���������� �������� ����� pn1
	node* pn2 = new node(5, pn1);
	//���������� �������� �� pn1
	pn1->next = new node(7, nullptr);

	list l1;
	l1.addFirst(3);
	l1.addLast(4);
	l1.addLast(99);
	cout << l1 << endl;
	cout << l1.kol(odd) << endl;
	l1.for_each(mult2);
	cout << l1 << endl;
	cout << l1.kol(odd) << endl;

	cout << l1 << endl;
	cout << l1 << endl;
	cout << l1.delFirst() << endl;
	cout << l1 << endl;
	cout << l1.delLast() << endl;
	cout << l1 << endl;

	



	return 0;
}