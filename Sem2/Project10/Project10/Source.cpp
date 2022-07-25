#include "Header.h"

int main() {
	setlocale(LC_ALL, "ru");
	vector<int> p;
	p = work_with_file("el.txt");
	copy(p.begin(), p.end(), ostream_iterator<int>(cout, " ")); cout << endl << endl;


	string s = "1 23 456 7 44 8910 55";
	//ex_2_vect(s, '4');
	//ex_2_deque(s, '4');
	//ex_2_list(s, '4');


	ex_3_set("name.txt");

	return 0;
}