#include "List.h"


int main() {
	//�������� ������������� �������� pn1
	node* pn1 = new node(5, nullptr);
	//���������� �������� ����� pn1
	node* pn2 = new node(5, pn1);
	//���������� �������� �� pn1
	pn1->next = new node(7, nullptr);



	return 0;
}