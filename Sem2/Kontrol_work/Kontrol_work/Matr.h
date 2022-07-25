#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class Matr {
private:
	T m[3][3];
public:
	Matr<T>(int t = 0) {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				m[i][j] = t;
	}

	Matr<T>(const Matr<T>& M) {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				m[i][j] = M.m[i][j];
	}

	bool symmetry() {
		for (int i = 0; i < 3; ++i) {
			for (int j = i + 1; j < 3; ++j) {
				cout << i << j << endl;
				if (m[i][j] != m[j][i]) return false;
			}
		}
		return true;
	}

	T* operator [] (int i) { return m[i]; }

	T operator[](int i) const {
		return m[i];
	}

	bool operator==(const Matr<T>& M) {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (m[i][j] != M.m[i][j]) return 0;
		return 1;
	}

	Matr<T>& operator*(double x) {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				m[i][j] *= x;
		return *this;
	}

	Matr<T> operator+(const Matr<T>& M) {
		Matr<T> Temp;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				Temp.m[i][j] = m[i][j] + M.m[i][j];
		return Temp;
	}

	friend ostream& operator<<(ostream& os, const Matr<T>& M) {
		cout << "================" << endl;
		for (int i = 0; i < 3; ++i) {
			cout << "|";
			for (int j = 0; j < 3; ++j)
				cout << setw(4) << M.m[i][j] << "|";
			cout << "\n================" << endl;
		}
		return os;
	}

	// 
	friend istream& operator>>(istream& os, Matr<T>& M) {
		cout << "Введите 9 элементов через пробел: " << endl;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j)
				cin >> M.m[i][j];
		}
		return os;
	}
};


class room {
	int num; // номер комнаты
	double sqr; // площадь
public:
	room(int number, double square = 10) : num(number), sqr(square) {}
	int get_num() const { return num; }
	double get_sqr() const { return sqr; }
	void set_num(int n) { num = n; }
	void set_sqr(double s) { sqr = s; }

	friend ostream& operator<<(ostream& os, const room& R) {
		os << "комната - " << R.num << " площадью- " << R.sqr << endl;
		return os;
	}
};


class auditorium : public room {
	int places; // количество мест
	bool projector; // проектор 
public:
	auditorium(int number, bool proj, int pl = 22) : room(number), places(pl), projector(proj){}
	int get_places() { return places; }
	bool get_projector() { return projector; }
	void set_places(int n) { places = n; }
	void set_projector(bool s) { projector = s; }

	friend ostream& operator<<(ostream& os, const auditorium& R) {
		os << (room)R;
		os << "количество мест - " << R.places << " проектор - " << R.projector << endl;
		return os;
	}

};


class laboratory : public auditorium {
	int pc_count; // количество компьюторов
	string name; // ФИО лаборанта  
public:
	laboratory(int number, int pc, bool p, string n) : auditorium(number, p), pc_count(pc), name(n){}
	int get_pc_count() { return pc_count; }
	string get_name() { return name; }
	void set_pc_count(int n) { pc_count = n; }
	void set_name(string s) { name = s; }

	friend ostream& operator<<(ostream& os, const laboratory& R) {
		os << (auditorium)R;
		os << "количество компьюторов - " << R.pc_count << " ФИО лаборанта - " << R.name << endl;
		return os;
	}
};

//Описать полиморфную функцию (не член класса) сравнения двух комнат по площади, возвращает - номер комнаты.
int lessSqr(const room& P1, const room& P2);
