#include <iostream>
# include "Bignum.h"
# include "Array.h"

int main() {
	Array A0;
	Array A(6, 4);
	Array B(10, 5);

	Array F = B;  // оператор копии
	Array C = (A + B);   // move-copy, даже не отработало создание копии при передаче по значению

	Array K(A + B);    // move-copy  
	// Ќе открабатывает операци€ копии и присваивани€ даже без мув функций из-за RVO.
	// ’от€, конечно, при создании копии в rv используетс€ move-copy
	//cout << C;

	//C+=3;
	//cout << C;

	//C += A;
	//cout << C;

	//cout << C[7]<<endl;

	//cout << C.find_el(8) << endl;

	//C.add_el_last(16);
	//cout << C;

	//C.del_el(4);
	//cout << C;

	//C.add_el_ind(0, 6);
	//cout << "good" << endl;
	//cout << C;

	//=======================================================
	
	frac f = frac(2, 3);
	double d = f;
	cout << d;


	return 0;
}