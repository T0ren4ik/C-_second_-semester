#include "Lab6.h"
#include "Header.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	//Student s("Student", 18, "ЮФУ", 3);
	//s.setMark(0, 5);
	//s.setMark(1, 4);
	//cout << s;
	//Student s1(s);
	//cout << s1;
	//Student s2;
	//cout << s2;
	//s2 = s1;
	//cout << s2;
	//для проверки совместимости типов
	//Person p("Иванов", 20);
	//Student sp("Петров", 19, "ЮФУ", 3);
	//p = sp;
	//cout << p;
	//// sp = p; будет ошибка компиляции
	//Person* pp = &p;
	//Student* ss = &sp;
	//pp = ss;
	//cout << *pp;
	//cout << *(Student*)pp; //downcast
	////ss = pp; // ошибка компиляции
	//Person& rp = sp;
	////Student& rs = p; // ошибка компиляции
	
	//Shape* S[4];

	//S[0] = new Poligon(2, 4, 2, 4);
	//S[1] = new Square(5);
	//S[2] = new Triangle(4, 5, 3);
	//S[3] = new Poligon(3, 5, 3, 5);

	//for (auto x : S)
	//	x->print();
	//cout << "\n\n\n\n";
	//sort_Shape(S, 4, lessPerimetr);
	Shape** SF = create_obj_file("Shape.txt");
	for (int i = 0; i < 6; ++i) {
		SF[i]->print();
	}
	//cout << fig_maxsq_num(S, 4);

	////cout << "!!!!!!!!!!!!!!!!!!!!!!!!\n";
	//for (auto x : S)
	//	x->print();

	return 0;
}