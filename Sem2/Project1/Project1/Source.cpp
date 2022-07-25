#define _CRTDBG_MAP_ALLOC // ƒл€ вы€влени€ утечек пам€ти
#include <stdlib.h>      //
#include <crtdbg.h>     //

#include "Header.h"


int main(){
	setlocale(LC_ALL, "Russian");
	List<int> L; // 443144318995
	
	L.inTail(4);
	L.inTail(4);
	L.inTail(3);
	L.inTail(1);
	L.inTail(4);
	L.inTail(4);
	L.inTail(3);
	L.inTail(1);
	L.inTail(8);
	L.inTail(9);
	L.inTail(9);
	L.inTail(5);

	cout << L;

	L.Sort();
	cout << L;
	

	L.delDubl();
	cout << L;

	return 0;
	_CrtDumpMemoryLeaks();  // ƒл€ вы€влени€ утечек пам€ти
}


