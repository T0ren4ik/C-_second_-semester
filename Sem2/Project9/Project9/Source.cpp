#include "List.h"


int main() {
	//создание единственного элемента pn1
	node* pn1 = new node(5, nullptr);
	//добавление элемента перед pn1
	node* pn2 = new node(5, pn1);
	//добавление элемента за pn1
	pn1->next = new node(7, nullptr);



	return 0;
}