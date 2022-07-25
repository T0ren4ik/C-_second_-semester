#pragma once
#include <iostream>
#include <string>
#include <typeinfo>
#define GD() ((double)rand() / (RAND_MAX))

using namespace std;

class Animal
{
protected:
	string name;
	double health;
public:
	Animal(string n = "Animal") : name(n), health(GD() * 100) {}
	virtual ~Animal() {}

	void print_Animal();

	virtual void Interact(Animal& a) = 0;
	virtual void action(double power, double y) = 0;

	inline double get_health()
	{
		return health;
	}
	inline const string& get_name() {
		return name;
	}
};

class Herbivore :
	public Animal
{
protected:
	double luckiness;
public:
	Herbivore(string n = "Herbivore") : Animal(n), luckiness(GD()) {}
	virtual ~Herbivore() {}
	virtual void action(double power, double y) = 0;
	virtual void Interact(Animal& a) = 0;

};

class Rabbit :
	public Herbivore
{
private:
	double speed;
public:
	Rabbit() : Herbivore("Rabbit"), speed(GD()) {}
	virtual ~Rabbit() {}
	virtual void Interact(Animal& a);
	virtual void action(double power, double y);
};

class Elk :
	public Herbivore
{
private:
	double age;
public:
	Elk() : Herbivore("Elk"), age(GD()) {}
	virtual ~Elk() {}

	virtual void Interact(Animal& a);
	virtual void action(double power, double y);
};

class Carnivore:
	public Animal
{
protected:
	double power;
public:
	Carnivore(string n = "Carnivore") : Animal(n), power(GD()) {};
	virtual ~Carnivore() {}

	virtual void Interact(Animal& a) = 0;
	virtual void action(double, double ) = 0;
};

class Wolf :
	public Carnivore
{
protected:
	double rank;
public:
	Wolf() : Carnivore("Wolf"), rank(GD()) {};
	virtual ~Wolf() {}

	virtual void Interact(Animal& a);
	virtual void action(double, double);

};

class Fox :
	public Carnivore
{
protected:
	double trick;
public:
	Fox() : Carnivore("Fox"), trick(GD()) {};
	~Fox() {}

	virtual void Interact(Animal& a);
	virtual void action(double, double );
};

// functions
Animal** create_random_animal_array(int n);

void animal_game(Animal**, int&, int);

