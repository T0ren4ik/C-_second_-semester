#include "PPN.h"

int main() {
	//Stack<int> intStack(5);
	//for (int i = 0; i < 5; i++)
	//	intStack.push(10 - i);
	//cout << intStack.isEmpty();
	//intStack.printStack();
	//for (int i = 0; i < 5; i++)
	//	intStack.pop();
	//cout << intStack.isEmpty();
	//=============================
	//test_balanced("");
	//test_balanced("a(b[c]d)e");
	//test_balanced("a(b[c)d]e");
	//test_balanced("a(b[c]d");
	//test_balanced("b[c]d)e");
	string P = "(a+b)*(c-d)/e";
	string P1 = "a+(b-c)*d";
	C2PPN s(P1);
	s.convert();
	string poli = s.get_str_out();
	cout << poli;
	string PP = "7 5 2 - 4 * +";
	cout << calculate(PP);

	return 0;
}