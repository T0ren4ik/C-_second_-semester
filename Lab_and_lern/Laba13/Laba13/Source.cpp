#include "Header.h"

int main() {
	setlocale(LC_ALL, "rus");

	cout << min_abs_f("H.txt") << endl;

	cout << "===========================\n";

	create_f1_min_max_f("H.txt");

	cout << "===========================\n";


	d_point SS;
	SS = max_len_point("PI.txt");

	cout << "x1 = " << SS.a.x << " | y1 = " << SS.a.y << " | x2 = " << SS.b.x << " | y2 = " << SS.b.y << endl;

	cout << "===========================\n";


	create_f2_table_from_f("people.txt");


	return 0;
}
