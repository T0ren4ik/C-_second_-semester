#include <ctime>
#include "Header.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	Tree t(5);
	t.printTree();
	cout << "\n";
	Tree t1(5, 0);
	t1.printTree();
	return 0;
}