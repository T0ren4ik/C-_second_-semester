#include "Header.h"

int main() {
	setlocale(LC_ALL, "rus");
	//list* pn = nullptr;
	//cout << "===================== ������� 0 ==========================\n";
	//pn = sp_create_to_tail();
	//print_sp(pn);

	//cout << "===================== ������� 1 ==========================\n";
	//cout << len_list(pn) << endl;

	//cout << "===================== ������� 2 ==========================\n";
	//cout << count_elemennt_equivalent_x(pn, 2) << endl;

	//cout << "===================== ������� 3 ==========================\n";
	//print_sp(pn);

	//cout << no_elemen_equivalent_x(pn, 5) << endl;
	//cout << no_elemen_equivalent_x(pn, 1) << endl;
	//print_sp(pn);

	//cout << "===================== ������� 4 ==========================\n";
	//print_sp(pn);
	//reversePrintSp(pn);

	//erase(pn);

	cout << "===================== ������� 4 ==========================\n";
	elem* T, *T1;
	T = createT(10);
	printTREE(T, 0);

	cout << "===================== ������� 1 ==========================\n";
	cout << count_zero_el(T) << endl;

	cout << "===================== ������� 2 ==========================\n";
	cout << max_el_tree(T) << endl;

	cout << "===================== ������� 3 ==========================\n";
	cout << maxDepth(T) << endl;

	cout << "===================== ������� 5 ==========================\n";
	insert_el_in_tree(T, 9);
	printTREE(T, 0);

	cout << "===================== ������� 6 ==========================\n";
	elem* copy;
	dublicate(T, copy);
	printTREE(copy, 0);

	cout << "===================== ������� 7 ==========================\n";
	T1 = createT(3);
	printTREE(T1, 0);
	cout << equivalent_tree(T, copy) << endl;
	cout << equivalent_tree(T1, copy) << endl;

	return 0;
}