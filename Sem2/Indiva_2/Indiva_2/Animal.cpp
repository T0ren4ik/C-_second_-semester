#include "Animal.h"

void Animal::print_Animal()
{
	cout << "Name: " << name << " Health: " << health << endl;
}

void Rabbit::Interact(Animal& a)
{
	if (dynamic_cast<Rabbit*>(&a) != nullptr) {
		cout << "Встретились два " << name << " .Создалась новая особь, не участвует в этой игре." << endl;
		return;
	}
	else if (dynamic_cast<Elk*>(&a) != nullptr) {
		cout << "Встретились две однотипные особи" << name << endl;
		return;
	}
	else {
		a.Interact(*this);
		if (health > 0) {
			a.action(0., 0.);
		}
		return;
	}
	

}

void Elk::Interact(Animal& a)
{
	if (dynamic_cast<Elk*>(&a) != nullptr) {
		cout << "Встретились два " << name << ". Создалась новая особь, не участвует в этой игре" << endl;

		
	}
	else if (dynamic_cast<Rabbit*>(&a) != nullptr) {
		cout << "Встретились две однотипные особи" << name << endl;
		
	}
	else {
		a.Interact(*this);
		if (health > 0) {
			a.action(0., 0.);
		}
		return;

	}


}

void Wolf::Interact(Animal& a)
{
	if (dynamic_cast<Wolf*>(&a) != nullptr) {
		cout << "Встретились два " << name << ". Создалась новая особь, не участвует в этой игре" << endl;


	}
	else if (dynamic_cast<Fox*>(&a) != nullptr) {
		cout << "Встретились две однотипные особи" << name << endl;

	}
	else {
		cout << "Произошла встреча " << name << " и";
		if (dynamic_cast<Elk*>(&a) != nullptr) cout << " Elk" << endl;
		else cout << " Rabbit" << endl;
		a.action(power, rank);
	}


}

void Fox::Interact(Animal& a)
{
	if (dynamic_cast<Fox*>(&a) != nullptr) {
		cout << "Встретились два " << name << ". Создалась новая особь, не участвует в этой игре" << endl;
	}
	else if (dynamic_cast<Wolf*>(&a) != nullptr) {
		cout << "Встретились две однотипные особи" << name << endl;

	}
	else {
		cout << "Произошла встреча " << name << " и";
		if (dynamic_cast<Elk*>(&a) != nullptr) cout << " Elk" << endl;
		else cout << " Rabbit" << endl;
		a.action(power, trick);
	}

}


void Wolf::action(double, double )
{
	health -= 20 * power + 20;
	power -= 0.05;
}

void Fox::action(double, double)
{
	health -= 15 * power +20;
	power -= 0.05;
}

void Elk::action(double power, double y)
{
	if (luckiness < power) {
		double luck = luckiness > 0 ? luckiness : 1;
		health -= power * 100 * y * luck + 30;
	}
	else {
		luckiness = luckiness > 0.1 ? luckiness - 0.1 : 0;
	}
	if (health < 0)
		cout << "Вышел победителем хищник " << endl;
	else
		cout << "Вышел победителем травоядное " << endl;	
}

void Rabbit::action(double power, double y)
{
	if (luckiness < power) {
		double luck = luckiness > 0 ? luckiness : 1;
		health -= power * 100 * y * luck + 30;
	}
	else {
		luckiness = luckiness > 0.1 ? luckiness - 0.1 : 0;
	}
	if (health < 0)
		cout << "Вышел победителем хищник " << endl;
	else
		cout << "Вышел победителем травоядное " << endl;
}

Animal** create_random_animal_array(int n)
{
	if (n < 1)
		throw invalid_argument("Number of Animal should be grater than zero");
	Animal** Animal_set = new Animal * [n];
	int obj_id;
	for (int i = 0; i < n; ++i) {
		obj_id = rand() % 4;
		switch (obj_id)
		{
		case 0:
			Animal_set[i] = new Rabbit;
			break;
		case 1:
			Animal_set[i] = new Elk;
			break;
		case 2:
			Animal_set[i] = new Wolf;
			break;
		case 3:
			Animal_set[i] = new Fox;
			break;
		}
	}
	return Animal_set;
}


void animal_game(Animal** a, int& Animal_count, int era)
{
	
	int i1, i2;
	while (Animal_count > 1 && era > 0) {
		i1 = rand() % Animal_count;
		i2 = rand() % Animal_count;
		while (i2 == i1) i2 = rand() % Animal_count;
		cout << endl;
		
		a[i1]->Interact(*a[i2]);

		cout << endl;
		if (a[i2]->get_health() <= 0) {
			swap(a[i2], a[Animal_count - 1]);
			--Animal_count;
		}
		era--;
	}
}
