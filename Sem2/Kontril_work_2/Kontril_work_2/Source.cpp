#include "tList.h"
#include "Tree.h"



int main() {
	setlocale(LC_ALL, "ru");
	//Tree t(5);
	//Tree t1(5);
	//t.printTree();
	//t.addLLeaves(0);
	//t.printTree();
	//cout << "�������� ==: " << (t == t1) << endl;
	//cout << "���������� � ������ � ������� cout" << endl;
	//t1.addNode(0);
	//cout << t1;
	//cout << "\n\n\n\n";

	List l(1);
	List k;
	k = l;
	//cout << k << endl;
	cout << "������������: ";
	l.duplication();
	cout << l << endl;
	cout << "�������� �� �������: " << l.isEmpty() << endl;
	l.push_back(0);
	cout << "���������� � ����� " << l << endl;	
	l.push_front(0);
	cout << "���������� � ������ " << l << endl;
	cout << "������ " << l.size() << endl;

	cout << "����� 2 ��������: " << l[2] << endl;
	

	return 0;
}