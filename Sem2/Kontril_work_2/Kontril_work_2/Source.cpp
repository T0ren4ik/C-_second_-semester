#include "tList.h"
#include "Tree.h"



int main() {
	setlocale(LC_ALL, "ru");
	//Tree t(5);
	//Tree t1(5);
	//t.printTree();
	//t.addLLeaves(0);
	//t.printTree();
	//cout << "Проверка ==: " << (t == t1) << endl;
	//cout << "Добавление и печать с помошбю cout" << endl;
	//t1.addNode(0);
	//cout << t1;
	//cout << "\n\n\n\n";

	List l(1);
	List k;
	k = l;
	//cout << k << endl;
	cout << "Дублирование: ";
	l.duplication();
	cout << l << endl;
	cout << "Проверка на пустоту: " << l.isEmpty() << endl;
	l.push_back(0);
	cout << "Добавление в конец " << l << endl;	
	l.push_front(0);
	cout << "Добавление в начало " << l << endl;
	cout << "Размер " << l.size() << endl;

	cout << "Вывод 2 элемента: " << l[2] << endl;
	

	return 0;
}