#include "Student.h"

//Construction
Student::Student(): full_name("NoName E.E."), specialization("NoSpecialization") {
	marks = new int[4];
	for (int i = 0; i < 4; ++i)
		marks[i] = 0;
}

Student::Student(string FN, string SP, int* M): full_name(FN), specialization(SP), marks(M){}

Student::Student(const Student& S): full_name(S.full_name), specialization(S.specialization){
	int* M = nullptr;
	if (S.marks != nullptr) {
		M = new int[4];
		for (int i = 0; i < 4; ++i)
			M[i] = S.marks[i];
	}
	marks = M;
}

Student::Student(Student&& S) noexcept: full_name(S.full_name), specialization(S.specialization) {
	marks = S.marks;
	S.marks = nullptr;
}

//operator=
Student& Student::operator=(const Student& S){
	if (this != &S) {
		delete[] marks;
		marks = new int[4];
		for (int i = 0; i < 4; i++)
			marks[i] = S.marks[i];
	}
	return *this;
}

Student& Student::operator=(Student&& S) noexcept {
	if (marks != nullptr)
		delete[] marks;
	marks = S.marks;
	full_name = S.full_name;
	specialization = S.specialization;
	S.marks = nullptr;
	return *this;
}

//geters\seters
string Student::get_FN() const {
	return full_name;
}

string Student::get_SP() const {
	return specialization;
}

int* Student::get_M() const {
	return marks;
}

void Student::set_FN(string FN){
	full_name = FN;
}

void Student::set_SP(string SP){
	specialization = SP;
}

void Student::set_M(int* M){
	if (M == nullptr) {
		if (marks == nullptr) {
			marks = M;
			return;
		}
		else {
			delete[] marks;
			marks = M;
			return;
		}
	}
	if (marks == nullptr) {
		marks = new int[4];
		for (int i = 0; i < 4; i++){
			marks[i] = M[i];
		}
	}
	else {
		for (int i = 0; i < 4; i++){
			marks[i] = M[i];
		}
	}
}

//metods
bool Student::permission_diplome(){
	for (int i = 0; i < 4; i++) {
		if (marks[i] < 85) return false;
	}
	return 1;
}

int Student::midle_ball() const{
	int res = 0;
	for (int i = 0; i < 4; i++)	{
		res += marks[i];
	}

	res /= 4;
	return res;
}


//comparison
bool Student::operator>(const Student& S) { return this->midle_ball() > S.midle_ball() ? 1 : 0; }

bool Student::operator>=(const Student& S){ return this->midle_ball() >= S.midle_ball() ? 1 : 0; }

bool Student::operator<(const Student& S){ return !(*this > S); }

bool Student::operator<=(const Student& S){ return !(*this >= S); }

bool Student::operator==(const Student& S){ return this->midle_ball() == S.midle_ball() ? 1 : 0; }

bool Student::operator!=(const Student& S){	return !(*this == S); }

//destructor
Student::~Student(){
	if (marks != nullptr) {
		delete[] marks;
	}
}


//flow
ostream& operator<<(ostream& os, const Student S) {
	os << "Full name: " << S.full_name << "\nSpecialization: " << S.specialization << "\nMarks: ";
	if (S.marks != nullptr)
		for (int i = 0; i < 4; ++i) {
			os << S.marks[i] << " ";
		}
	else os << "Empty";

	os << "\n=========================\n" << endl;
	return os;
}

istream& operator>>(istream& os, Student& S) {
	cout << "Enter full name(Уйльям Г.Г.), specialization and marks separated by a space: ";
	string temp1 = "", temp2 = "", SP, FN;
	int* m = new int[4];
	
	os >> temp1 >> temp2 >> SP >> m[0] >> m[1] >> m[2] >> m[3];

	FN = temp1 + " " + temp2;

	if (S.marks == nullptr) {
		S = Student(FN, SP, m);
	}
	else {
		delete[] S.marks;
		S.full_name = FN;
		S.specialization = SP;
		S.marks = m;

	}

	return os;
}

int** array_midle_bal(Student** S, int n) {
	cout << "array_midle_bal \n";
	int** a = new int* [n];

	for (int i = 0; i < n; ++i)
		a[i] = new int[2];
	for (int i = 0; i < n; i++) {
		a[i][0] = i;
	}
	for (int i = 0; i < n; i++) {
		//cout << S[i] << endl;
		a[i][1] = S[i]->midle_ball();
	}
	return a;
}

void Sort(Student** S, int n) {
	int** a = array_midle_bal(S, n);

	QSort(a, 0, n-1);

	for (int i = 0; i < n; ++i) {
		cout << *S[a[i][0]] << endl;
	}
}


void QSort(int** A, int low, int high) {

	int i = low, j = high;
	int x = A[(low + high) / 2][1]; // x - опорный
	do {
		while (A[i][1] < x) ++i; // поиск элемента для переноса
		while (A[j][1] > x) --j; // поиск элемента для переноса
		if (i <= j) { // обмен элементов местами:
			swap(A[i], A[j]);
			++i; --j; // переход к следующим элементам:
		}
	} while (i < j);
	if (low < j) QSort(A, low, j);
	if (i < high) QSort(A, i, high);
}


void show_list_diploms(Student** S, int n) {
	

	int temp;
	for (int i = 0; i < n; i++)	{
		temp = 0;

		for (int j = 0; j < 4; ++j) {
			if (S[i]->marks[j] >= 85)
				temp++;
		}

		if (temp == 4) cout << *S[i];
	}
}





