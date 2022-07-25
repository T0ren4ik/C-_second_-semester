#include "Header.h"

int main() {
	setlocale(LC_ALL, "rus");
	list* pn = nullptr;
	cout << "===================== Задание 2 ==========================\n";
	pn = sp_create_to_tail();

	cout << "===================== Задание 4 ==========================\n";
	print_sp(pn);

	/*cout << "===================== Задание 5 ==========================\n";
	cout << count_element_list(pn) << endl;

	cout << "===================== Задание 6 ==========================\n";
	try {
		list* p = find_el(pn, 3);
		cout << p << " | " << p->inf << endl;
	}
	catch (const char* s) {
		cout << s << endl;
	}

	cout << "===================== Задание 7 ==========================\n";
	try {
		cout << first_el(pn) << endl;
	}
	catch (const char* s) {
		cout << s << endl;
	}
	

	cout << "===================== Задание 8 ==========================\n";
	add_first(pn, 0);
	print_sp(pn);

	cout << "===================== Задание 9 ==========================\n";
	add_end(pn, 4);
	print_sp(pn);

	cout << "===================== Задание 10 ==========================\n";
	try {
		add_el_i_position(pn, pn->next, 10);
		print_sp(pn);
	}
	catch (const char* s) {
		cout << s << endl;
	}


	cout << "===================== Задание 11 ==========================\n";
	try {
		remove_after(pn);
		print_sp(pn);
	}
	catch (const char* s) {
		cout << s << endl;
	}
	

	cout << "===================== Задание 12 ==========================\n";
	try {
		add_i_past_pos(pn, 4, 5);
		print_sp(pn);
	}
	catch (const char* s) {
		cout << s << endl;
	}

	cout << "===================== Задание 13 ==========================\n";
	try {
		remove_after_el(pn, 4);
		print_sp(pn);
	}
	catch (const char* s) {
		cout << s << endl;
	}

	cout << "===================== Задание 14 ==========================\n";
	cout << vozr_list(pn) << endl;

	cout << "===================== Задание 15 ==========================\n";
	cout << pred_list(pn, all_zero) << endl;*/

	cout << "===================== Задание 16 ==========================\n";
	list* R = revers_list(pn);
	print_sp(R);

	cout << "===================== Задание 3 ==========================\n";

	erase(R);
	erase(pn);

	return 0;
}