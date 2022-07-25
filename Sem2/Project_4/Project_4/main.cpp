#include <iostream>
#include "Empty.h"
#include "template.h"


using namespace std;

int main() {
	//cout << "test constructors" << endl;
	//Empty a;
	//Empty b("1");
	//Empty c(a);
	//cout << "test move-constructor" << endl;
	//Empty s(-b);
	//cout << "end test constructors" << endl;

	//// move конструктор срабатывает когда у нас rvalue выражение.
	//// обычный конструктор при передачи в функцию на значению, при возврате по значению и при €вном вызове

	//cout << endl;

	//cout << "test operator= and functions" << endl;
	//cout << "test =" << endl;
	//c = -b;
	//// ѕроисходит создание копии выражени€ (-b) в  функции оно возврощаетс€ из функции и создаетс€ move-copy т.к. rvalue
	//// 1 копи€ удал€етс€ потом происходит move= т.к. rvalue и удал€етс€ move-copy
	//// ѕо идее удал€тс€ ничего не должно, но так как в классе нет пол€ с динамической пам€тью
	//// и мы в диструктор не добавили проверку на nulltr, то удаление происходит срузу после выхода из функции

	//cout << endl;

	//cout << "test f1" << endl;
	//f1(b);
	//// создалась копи€ внутри функции и удалилась после	т.к. по значению

	//cout << endl;
	//cout << "test f2" << endl;
	//a = f2();
	//// в функции создалась переменна€ класса и вернулась в виде копии, после move= т.к. rvalue и удалилось

	//cout << endl;
	//cout << "test f3" << endl;
	//// с(copy noname)
	//a = f3(c);
	// //копи€ не создалась т.к. передаем по ссылке, при выходе создалась копи€, move= т.к. rvaleu 
	// //и пошло все удал€ть
	
	//===================================================

	cout << max_type_T(3, 2) << endl;
	cout << max_type_T(3.5, -10.6) << endl;
	string s1 = "hello";
	string s2 = "world";
	cout << max_type_T(s1, s2) << endl;
	Persone p1{ "aaa",1980 }, p2{ "BBb",2000 };
	cout << max_type_T(p1, p2) << endl;

	char s3[] = "String";
	char s4[] = "world";
	cout << max_type_T(s3, s4) << endl;
	


	return 0;
}