#include "Header.h"


double Sum_N(int N) {
	float sum = 0; //����� ����

	for (int i = 1; i <= N; i++) {
		sum += (1. / (i * i));
	}
	
	return sum;
}
