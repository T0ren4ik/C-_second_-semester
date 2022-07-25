#include "Matr.h"

int main() {
	setlocale(LC_ALL, "Rus");
	// Конструктор 
	Matr<int> M(3);
	Matr<int> M1(3);
	Matr<int> M2(2);
	Matr<int> M3;

	//Оперыции и методы
	cout <<"symmetry: " << M.symmetry() << endl;
	cout << "M*3: " << M * 3;
	cout << "operator[]: " << M[0][0] << endl;
	cout << "1.operator==: " << (M== M1*3) << endl;
	cout << "2.operator==: " << (M == M2) << endl;
	cout << "operator+: " << (M + M2) << endl;

	// ввод с клавиатуры
	//cout << "Input: (1 2 3 4 5 6 7 8 9): \n";
	//cin >> M3;
	//cout << M3;
	//
	
	cout << "================================\n";
	//№2
	//Массив указателей
	room* Ptr[4];

	Ptr[0] = new room(1, 100);
	Ptr[1] = new auditorium(2, 0, 18);
	Ptr[2] = new laboratory(3, 18, 1, "FIO");
	Ptr[3] = new room(3, 1000);

	//Вывод на экран
	cout << *(static_cast<laboratory*>(Ptr[2])) << endl;
	
	// В программе организовать массив помещений института. Выдать номер помещения с максимальной площадью. 
	int res = -1;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			res = lessSqr(*Ptr[i], *Ptr[j]);
		}
	}
	cout << res;

	return 0;
}
