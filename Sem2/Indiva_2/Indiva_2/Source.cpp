#include "Animal.h"

int main() {
	setlocale(LC_ALL, "ru");
	int n = 10;
	srand(time(NULL));

	Animal** A = create_random_animal_array(n);
	for(int i = 0; i < n; ++i)
		A[i]->print_Animal();
	cout << endl;

	animal_game(A, n, 50);

	for (int i = 0; i < n; ++i)
		A[i]->print_Animal();
	cout << endl;

	return 0;
}