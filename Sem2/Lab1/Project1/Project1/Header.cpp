#include "Header.h"

/*
1. Пользователем с клавиатуры вводится последовательность из N
целых/вещественных чисел. Сохранить вводимую пользователем
последовательность в двоичном файле. 
*/
void create_b_f(string filename){
	ofstream fout(filename, ios::out | ios::trunc | ios::binary);
	int N, el;

	if (!fout.is_open()) {
		cout << "Can't open " << filename << "\n";
		throw - 1;
	}

	cout << "Введите количество цифр: ";
	cin >> N;

	for (int i = 0; i < N; i++){
		cout << "El" << i << ": ";
		cin >> el;
		fout.write(reinterpret_cast <char*>(&el), sizeof el);
	}

	fout.close();
	fout.clear();
}


/*
2. Написать функцию, распечатывающую содержимое двоичного файла
целых/вещественных чисел. Параметр функции – имя файла.
*/
void read_b_f(string filename){
	ifstream fin(filename, ios::in | ios::binary);
	double el;
	if (fin.is_open()) {
		while (fin.read(reinterpret_cast <char*>(&el), sizeof el)) {
			cout << el << " ";
		}
		cout << endl;
		fin.close();
		fin.clear();
	}
	else throw - 1;
}


/*
3. Поменять в файле вещественных чисел первое и последнее число
местами. Не использовать при решении вспомогательный файл или
массив
*/
void change_first_last_b_f(string filename) {
	fstream f(filename, ios::in | ios::out |ios::binary);
	if (!f.is_open()) {
		cout << "Error!" << endl;
		throw - 1;
	}

	int first_el, last_el;
	int size_int = sizeof(int);
	f.seekg(0, ios::beg);
	f.read(reinterpret_cast <char*>(&first_el), sizeof size_int);
	f.seekg(-size_int, ios::end);
	f.read(reinterpret_cast <char*>(&last_el), sizeof size_int);

	//cout << first_el << " | " << last_el << endl;

	f.seekp(0, ios::beg);
	f.write(reinterpret_cast <char*>(&last_el), sizeof size_int);
	f.seekp(-size_int, ios::end);
	f.write(reinterpret_cast <char*>(&first_el), sizeof size_int);

	f.close();
}


/*
4. В текстовом файле в первой строке записано количество точек на плоскости,
далее в каждой строке - координаты очередной точки. Используя ввод
данных из текстового файла, создать новый файл, хранящий данных о
координатах точек в двоичном формате. Написать функцию, которая ищет в
файле точек на плоскости точку, максимально удаленную от начала
координат.
*/
void BF_koord(string filename){
	ifstream fin(filename);
	ofstream f("b_koord.dat", ios::out | ios::trunc | ios::binary);
	if (!fin.is_open() && !f.is_open()) {
		cout << "Error!" << endl;
		throw - 1;
	}

	int N, i;
	double x, y;
	int size_d = sizeof(double);
	fin >> N;

	for (i = 0; i < N; ++i) {
		fin >> x; fin >> y;
		//cout << x << " | " << y << endl;
		f.write(reinterpret_cast <char*>(&x), sizeof(x));
		f.write(reinterpret_cast <char*>(&y), sizeof(y));
	}
	fin.close();
	f.close();
}

point* find_point(string filename){
	point* p = nullptr;
	int int_size = sizeof(double);
	double x, y, len_p, len_pr;
	ifstream f(filename, ios::in | ios::binary);

	if (f.read(reinterpret_cast <char*>(&x), int_size) && f.read(reinterpret_cast <char*>(&y), int_size)) {	
		len_p = dist(x, y);
		//cout << x << " | " << y << " | " << len_p << endl;
		p = new point(x, y);
	}
	else throw - 2;

	while (f.read(reinterpret_cast <char*>(&x), int_size) && f.read(reinterpret_cast <char*>(&y), int_size)) {
		len_pr = dist(x, y);
		//cout << x << " | " << y << " | " << len_pr << endl;
		if (len_pr > len_p) { p->x = x; p->y = y; }
	}

	f.close();

	return p;
}


/*
5. Написать функцию, добавляющую в двоичный файл данные о новом
сотруднике. Используя эту функцию, создать файл сотрудников, считывая     
данные для N сотрудников из текстового файла.
*/
void worker(ifstream& fin, ofstream& f){
	string pr;
	person p;

	
	fin >> p.number; 
	for (int j = 0; j < 3; ++j) { 
		fin >> pr;
		p.fullname += pr;
		p.fullname += " ";
	}
	//cout << fullname << endl;
	//fin >> fullname;
	fin >> p.year; 
	fin >> p.gender;
	f.write(reinterpret_cast <char*>(&p), sizeof p);
}

void BF_worker(string filename) {
	ifstream fin(filename);
	ofstream f("b_people.dat", ios::out | ios::trunc | ios::binary);

	if (!fin.is_open() && !f.is_open()) {
		cout << "Error!" << endl;
		throw - 1;
	}
	int N, i;

	fin >> N;
	for (i = 0; i < N; ++i) {
		worker(fin, f);
	}

	fin.close();
	f.close();
}


/*
6. Написать функцию, печатающую данные обо всех сотрудниках из                    dont work 
двоичного файла в текстовый файл в виде таблицы.
*/
void create_table_worker_t(string filename){
	ifstream f(filename, ios::in | ios::binary);
	ofstream fout("t_people.txt");

	if (!fout.is_open() && !f.is_open()) {
		cout << "Error!" << endl;
		throw - 1;
	}

	int i;
	person p;
	fout << "|---------------------------------------------------------|" << endl;
	fout << "|" << setw(3) << left << '№';
	fout << "|" << setw(40) << left << "FIO";
	fout << "|" << setw(5) << "Year" << left;
	fout << "|" << setw(6) << "Gender" << left << "|" << endl;
	cout << "`w" << endl;
	while (f.read(reinterpret_cast <char*>(&p), sizeof p)) {
		fout << "|---------------------------------------------------------|" << endl;
		cout << p.fullname << endl;
		fout << "|" << setw(3) << left << p.number;
		fout << "|" << setw(40) << left << p.fullname;
		fout << "|" << setw(5) << p.year << left;
		fout << "|" << setw(6) << p.gender << left << "|" << endl;
	}
	cout << "w`" << endl;

	fout << "|---------------------------------------------------------|" << endl;


	fout.close();
	f.close();
	cout << 1;
}


/*
7. Написать функцию, изменяющую в двоичном файле год рождения у
сотрудника по заданному номеру сотрудника.
*/
void change_gate(string filename, int n, int date){
	fstream f(filename, ios::in | ios::out | ios::binary);
	if (!f.is_open()) {
		cout << "Error!" << endl;
		throw - 1;
	}
	person p;
	
	int size_p = sizeof(p);
	n = n - 1;
	f.seekg(n * size_p, ios::beg);
	f.read(reinterpret_cast <char*>(&p), size_p);
	cout << p.fullname << endl;

	p.year = date;
	f.seekp(n * size_p, ios::beg);
	f.write(reinterpret_cast <char*>(&p), size_p);


	f.close();
	cout << 1;
}


void change_gate(string filename, int n, string name) {
	fstream f(filename, ios::in | ios::out | ios::binary);
	if (!f.is_open()) {
		cout << "Error!" << endl;
		throw - 1;
	}
	person p;

	int size_p = sizeof(p);
	n = n - 1;
	f.seekg(n * size_p, ios::beg);
	f.read(reinterpret_cast <char*>(&p), size_p);
	cout << p.fullname << endl;

	p.fullname = name;
	f.seekp(n * size_p, ios::beg);
	f.write(reinterpret_cast <char*>(&p), size_p);


	f.close();
}