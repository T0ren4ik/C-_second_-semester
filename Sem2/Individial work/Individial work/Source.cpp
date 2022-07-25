#include "Student.h"

int main() {
	setlocale(LC_ALL, "Russian");
	Student* S[5];

	int* M = new int[4]{ 80, 84, 98, 74 };
	S[0] = new Student("Попов0 И.М", "ПМИ", M);

	//S[1] = new Student();
	int* t = new int[4]{ 60, 85, 95, 70 };
	Student* CC1 = new Student("Попов1 И.М", "ПМИ", t);
	S[1] = CC1;

	int* K = new int[4]{ 60, 85, 95, 70 };
	Student* CC = new Student("Попов2 И.М", "ПМИ", K);
	S[2] = CC;

	int* C = new int[4]{ 85, 87, 98, 89 };
	S[3] = new Student("Попов3 И.М", "ПМИ", C);

	for (int i = 0; i < 4; i++)	{
		cout << *S[i];
	}

	// 0 | 1
	cout << (*S[0]).permission_diplome() << " | " << (*S[3]).permission_diplome() << endl;

	// 84
	cout << (*S[0]).midle_ball() << endl;

	// 1
	cout << (*S[0] < *S[3]) << endl;

	//flow (Uliman G.G. PMI 66 66 66 66)
	Student* PP = new Student();
	cout << "hi" << endl;
	cin >> *PP;
	S[4] = PP;
	cout << *PP;

	// Sort
	Sort(S, 5);

	cout << "show_list_diploms\n" << endl;
	show_list_diploms(S, 5);


	delete[] M; delete[] K; delete[] C;

	return 0;
}