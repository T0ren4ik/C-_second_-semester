#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Student{
private:
	string full_name;
	string specialization;
	int* marks;

public:
	//Construction w
	Student();
	Student(string FN, string SP, int* M);
	Student(const Student& S);
	Student(Student&& S)noexcept;

	//operator= w
	Student& operator=(const Student& S);
	Student& operator=(Student&& S)noexcept;

	//geters\seters w
	string get_FN() const;
	string get_SP() const;
	int* get_M() const;

	void set_FN(string FN);
	void set_SP(string SP);
	void set_M(int* M);

	//metods w
	// и возможности выдать диплом с отличием(средний балл в каждый год обучения должен быть не ниже 85)
	bool permission_diplome();
	// средний балл
	int midle_ball() const;

	//comparison w
	bool operator>(const Student& S);
	bool operator>=(const Student& S);
	bool operator<(const Student& S);
	bool operator<=(const Student& S);
	bool operator==(const Student& S);
	bool operator!= (const Student& S);

	//destructor w
	~Student();

	//flow w
	friend ostream& operator<<(ostream& os, const Student S);
	friend istream& operator>>(istream& os, Student& S);

	//friend metod
	friend void Sort(Student** S, int n);
	// список студентов, упорядоченный по убыванию итогового среднего балла
	// список студентов, претендующих на диплом с отличием. W
	friend void show_list_diploms(Student** S, int n);
	// Матрица средних баллов W
	friend int** array_midle_bal(Student** S, int n);
};


void QSort(int** A, int low, int high);

