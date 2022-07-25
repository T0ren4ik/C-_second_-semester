#include "Header.h"

int main() {
	setlocale(LC_ALL, "rus");
/*
Gooood!

Gooood!
Gooood bye!

*/
	int* C_L = nullptr;

	/*for (char i = 'a'; i <= 'z'; i = char(int(i) + 1)) cout << i << " ";
	cout << "\n";
	C_L = count_letter("H.txt");
	print_arr(C_L, 26);*/
	count_letter("H.txt");
	cout << "===========================================================================\n";

	max_len_str_f("H.txt");

	cout << "===========================================================================\n";

	count_vord_f("H.txt");

	cout << "===========================================================================\n";

	del_vord_f("H.txt", "bye");

	cout << "===========================================================================\n";

	numbered_str("H.txt");

	cout << "===========================================================================\n";

	replese_sub_vord_count_f("H.txt", "Gooood");
	return 0;
}