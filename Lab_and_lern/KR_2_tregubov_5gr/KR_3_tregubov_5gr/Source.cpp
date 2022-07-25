#include "Header.h"

int main() {
	setlocale(LC_ALL, "rus");

	cout << "=============== Задание 1 ====================\n";

	char str[256] = "Hello dear ddouble world";

	remove_last_s_chr(str);

	cout << str << endl;

	cout << "=============== Задание 3 ====================\n";

	string s = "Hello dear ddouble world";
	string s1 = "Hello delar ddouble world";
	string s2 = "   Hello delar ddouble world";


	remove_last_word_str(s, 'w');
	cout << s << endl;


	remove_last_word_str(s1, 'l');
	cout << s1 << endl;

	remove_last_word_str(s2, 'l');
	cout << s2 << endl;


	cout << "=============== Задание 2 ====================\n";

	cout << max_sum_digit_numder_f("H.txt");
	return 0;
}