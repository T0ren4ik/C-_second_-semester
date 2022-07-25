#include "Header.h"


int main() {
	setlocale(LC_ALL, "ru");
	/*cout << "\n===============Ex1.1=================" << endl ;
	string s4 = "123 123 123";
	vector<char> v5;
	v5 = string2vector(s4);
	for (char x : s4)
		cout << x << ' ';

	cout << "\n===============Ex1.2=================" << endl ;
	vector<char> v4 = {'1', '2', '3'};
	char value_ch{};
	count_char_str(s4, v4);

	cout << "\n===============Ex1.3=================" << endl;
	string str3 = "Hello World";
	str2STR(str3);
	cout << str3 << endl;
	*/
	//cout << "\n===============Ex1.4=================" << endl;
	//string str2 = "Hello World";
	//vector<string> v2 = create_v_s(str2);
	//for (string s2 : v2)
	//	cout << s2 << endl;
	//cout << endl;

	//cout << "\n===============Ex2.1=================" << endl ;

	//code_v_string(v2);

	//cout << "\n===============Ex2.2=================" << endl ;
	string str1 = "Hello World Hello", s1 = "Hello";
	vector<string> v1 = create_v_s(str1);
	count_word(s1, v1);

	//cout << "\n===============Ex2.3=================" << endl ;
	//vector<string> v9{"12", "12", "34", "55"};
	//vector<string> v10{"12", "12", "24", "55"};
	//ferst_different(v9, v10);

	//cout << "\n===============Ex3.1=================" << endl;
	//permutation("1234", "4123");

	//cout << "\n===============Ex3.2=================" << endl ;
	//string ss= "Hello Wo";
	//findPermutations(ss);

	//cout << "\n===============Ex4.1=================" << endl;
	//vector<int> v6(6);
	//vect_gener_NM(v6, 0, 5);

	//cout << "\n===============Ex4.2=================" << endl;
	//arithmetic_mean(v6);
	//
	//cout << "\n===============Ex4.3=================" << endl;
	//MIN_V(v6);

	//cout << "\n===============Ex4.4=================" << endl;
	//count_min_mean(v6);

	//cout << "\n===============Ex4.5=================" << endl;
	//vector<int> v7(6);
	//copy_v_more_mean(v6, v7);

	//cout << "\n===============Ex4.6=================" << endl;
	//degree(v6);


	/*cout << "\n===============Ex5.1=================" << endl;
	int n = 3, m = 3;
	vector <vector<int>> mat(n, vector <int>(m));
	push_el_matrix(mat, n, m); cout << "...";

	cout << "\n===============Ex5.2=================" << endl;
	print_matrix(mat);

	cout << "\n===============Ex5.3=================" << endl;
	min_row_matrix(mat);

	cout << "\n===============Ex5.4=================" << endl;*/
	//mat[1][0] = 0; mat[1][1] = 0; mat[1][2] = 0;
	//vector<vector<int>>::iterator mat1 = remove_zero_row_matrix(mat);
	//for (auto row : mat)
	//{
	//	for(int el: row)
	//		cout << el << " ";
	//	cout << endl;
	//}

	/*cout << "\n===============Ex5.5=================" << endl;
	min_el_matrix_wVect(mat);

	cout << "\n===============Ex5.6=================" << endl;
	mat[0][0] = 1; mat[0][1] = 2; mat[0][2] = 3;
	mat[1][0] = 4; mat[1][1] = 5; mat[1][2] = 6;
	mat[2][0] = 7; mat[2][1] = 8; mat[2][2] = 9;
	print_matrix(mat);


	composition_matrix(mat, mat);*/

	return 0;
}