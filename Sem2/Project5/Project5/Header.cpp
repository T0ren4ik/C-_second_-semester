#include "Header.h"
// circle

void Circle::setR(double r){
	radius = r;
}

double Circle::getR() const{
	return radius;
}

// cone

void Cone::setH(double h){
	height = h;
}

double Cone::getH() const{
	return height;
}

//Circle* create_obj_file(Circle* p, string filename)
void create_obj_file(string filename){
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "Error!" << endl;
		throw - 1;
	}
	
	int count;
	string type, name_meaning; 
	double r = 0, h = 0; 
	fin >> count;


	for (int i = 0; i < count; ++i) {
		fin >> type;
		if (type == "Circle") {
			fin >> name_meaning;
			if (name_meaning[0] == 'r') {
				r = stod(name_meaning.substr(1));
				cout << Circle(r) << endl;
	
			}
			else throw - 1;
		}
		else if (type == "Cone") {
			for (int i = 0; i < 2; i++) {
				fin >> name_meaning;
				if (name_meaning[0] == 'r') {
					r = stod(name_meaning.substr(1));
				}
				else if (name_meaning[0] == 'h') {
					h = stod(name_meaning.substr(1));
				}
				else throw - 2;
			}
			cout << Cone(r, h) << endl;
		}
		else if (type == "Sphere") {
			fin >> name_meaning;
			if (name_meaning[0] == 'r') {
				r = stod(name_meaning.substr(1));
				cout << Sphere(r) << endl;
			}
			else throw - 3;
		}
		else if (type == "Cylinder") {
			for (int i = 0; i < 2; i++) {
				fin >> name_meaning;
				if (name_meaning[0] == 'r') {
					r = stod(name_meaning.substr(1));
				}
				else if (name_meaning[0] == 'h') {
					h = stod(name_meaning.substr(1));
				}
				else throw - 2;
			}
			cout << Cylinder(r, h) << endl;
		}
		else throw 0;
	}
	fin.close();
}
