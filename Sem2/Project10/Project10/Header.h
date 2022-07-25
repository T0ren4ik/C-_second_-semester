#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <numeric> // accumulate
#include <iomanip>

#include <deque>
#include <list>
#include <ctime>

#include <set>
#include <map>


using namespace std;


vector<int> work_with_file(string filename) {
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "Error!" << endl;
		throw - 1;
	}

	int count_line = 0, max_line = NULL, temp = 0, i = 0;
	vector<int> v;
	string s;
	vector<int> max_vect;

	getline(fin, s);
	count_line = stoi(s);
	while (!fin.eof() && count_line)
	{
		getline(fin, s);
		stringstream ss(s);
		copy(istream_iterator<int>(ss), {}, back_inserter(v));

		temp = accumulate(v.begin(), v.end(), 0);

		if (max_line == NULL || max_line < temp) { 
			max_line = temp; 
			max_vect.clear();
			copy(v.begin(), v.end(), inserter(max_vect, max_vect.begin()));
		}

		cout << i++ << "| Max: " << setw(5) << *max_element(v.begin(), v.end()) << "| Min: " <<
			setw(5) << *min_element(v.begin(), v.end()) << endl;
		temp = 0; v.clear(); 
		count_line--;
	} 
	//copy(max_vect.begin(), max_vect.end(), ostream_iterator<int>(cout, " "));
	return max_vect;
}

void ex_2_vect(string s, char f) {
	vector<string> line;
	string token;
	istringstream iss(s);
	unsigned int start_time, end_time, search_time;

	while (getline(iss, token, ' '))
		line.push_back(token);
	
	//№1
	cout << "Последнее слово в строке, начинающееся с " << f << ": ";

	start_time = clock();
	for (int i = line.size() - 1; i >= 0; i--)
	{
		if (line[i][0] == f) {
			cout << line[i] << endl;
			break;
		}
	}
	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время
	cout << "Время выполнения поиска: " << search_time << endl;

	//№2

	int si;
	cout << "\nHечётные слова строки в обратном порядке" << endl;

	start_time = clock();
	if (((si = line.size()) % 2) == 0) si -= 2;
	else si--;
	for (int i = si; i >= 0; i -= 2)
	{
		cout << line[i] << " ";
	}
	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время
	cout << "\nВремя вывода в обратном порядке:" << search_time << endl;

	//№3

	cout << "\nCортировка контейнера" << endl;

	start_time = clock();
	sort(line.begin(), line.end());

	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время

	for (string s : line)
		cout << s << ' ';
	cout << "Время сортировки:" << search_time << endl;
}


void ex_2_deque(string s, char f) {
	deque<string> line;
	string token;
	istringstream iss(s);
	unsigned int start_time, end_time, search_time;

	while (std::getline(iss, token, ' '))
		line.push_back(token);

	//№1
	cout << "Последнее слово в строке, начинающееся с " << f << ": ";

	start_time = clock();
	for (int i = line.size() - 1; i >= 0; i--)
	{
		if (line[i][0] == f) {
			cout << line[i] << endl;
			break;
		}
	}
	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время
	cout << "Время выполнения поиска: " << search_time << endl;

	//№2

	int si;
	cout << "\nHечётные слова строки в обратном порядке" << endl;

	start_time = clock();
	if (((si = line.size()) % 2) == 0) si -= 2;
	else si--;
	for (int i = si; i >= 0; i -= 2)
	{
		cout << line[i] << " ";
	}
	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время
	cout << "\nВремя вывода в обратном порядке:" << search_time << endl;

	//№3

	cout << "\nCортировка контейнера" << endl;

	start_time = clock();
	sort(line.begin(), line.end());

	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время

	for (string s : line)
		cout << s << ' ';
	cout << "Время сортировки:" << search_time << endl;
}


void ex_2_list(string s, char f) {
	list<string> line;
	string token;
	istringstream iss(s);
	unsigned int start_time, end_time, search_time;

	while (std::getline(iss, token, ' '))
		line.push_back(token);

	//№1
	cout << "Последнее слово в строке, начинающееся с " << f << ": ";

	start_time = clock();
	string el;
	for (int i = line.size() - 1; i >= 0; i--)
	{
		if ((el = (*next(line.begin(), i)))[0] == f) {
			cout << el << endl;
			break;
		}
	}
	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время
	cout << "Время выполнения поиска: " << search_time << endl;

	//№2

	int si;
	cout << "\nHечётные слова строки в обратном порядке" << endl;

	start_time = clock();
	if (((si = line.size()) % 2) == 0) si -= 2;
	else si--;
	for (int i = si; i >= 0; i -= 2)
	{
		cout << (*next(line.begin(), i)) << " ";
	}
	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время
	cout << "\nВремя вывода в обратном порядке:" << search_time << endl;

	//№3

	cout << "\nCортировка контейнера" << endl;

	start_time = clock();
	line.sort();

	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время

	for (string s : line)
		cout << s << ' ';

	cout << "\nВремя сортировки:" << search_time << endl;
}


void ex_3_set(string filename) {
	ifstream fin(filename);
	if (!fin.is_open()) {
		cout << "Error!" << endl;
		throw - 1;
	}

	set<string> name;
	set<string> secondName;
	set<string> surname;
	string s, token;
	stringstream iss(s);
	map<string, int> dictionary;

	while (!fin.eof())
	{
		getline(fin, s);
		stringstream iss(s);

		getline(iss, token, ';');
		name.insert(token);
		++dictionary[token];

		getline(iss, token, ';');
		secondName.insert(token);

		getline(iss, token, ' ');
		surname.insert(token);
	}
	
	for (string s : name)
		cout << s << ' ';

	cout << endl << endl;
	for (auto s : dictionary) {
		cout << s.first << " - " << s.second << endl;
	}
}