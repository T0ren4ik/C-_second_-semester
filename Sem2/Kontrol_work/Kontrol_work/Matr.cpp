#include "Matr.h"

int lessSqr(const room& P1, const room& P2) {
	return P1.get_sqr() > P2.get_sqr() ? P1.get_num() : P2.get_num();
}