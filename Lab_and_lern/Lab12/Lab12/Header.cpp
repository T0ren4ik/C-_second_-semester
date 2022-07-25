#include "Header.h"

//Записывает содержимое файла в строку
string str_of_file(string filename){
	string str = "", s;
	ifstream file;

	//Открываю фаил
	file.open(filename);

	if (!file) { // Если не открылся выдаю ошибку
		file.clear();
		throw "Фаил открыть не удалось!";
	}
	else { // если открылся

		// иду до конца, считываю строки, конкатенирую
		while (!file.eof()) {
			s = "";
			getline(file, s);

			if (s != "")
				str += s + "\n";
			else
				str += "\n";
		}
	}

	//ЗАкрываю фаил, возврашаю строку
	file.clear();
	file.close();

	return str;

	
}

//Функция считает количество слов в строке
int count_vorgs(string s) {
	int i = 0, count = 0;
	int Fs;

	//пропуская начальные пробелы
	while (s[i] == ' ' && s[i]) {
		i++;
	}

	//иду по слову
	for (; i < s.length(); ++i) {
		// увеличиваю count(кол-во слов)
		count++;
		//если есть пробельные далее, то пропускаю
		Fs = s.find(' ', i);
		if (Fs != -1) {
			i += Fs - i;

			while (s[i] == ' ' && s[i]) {
				i++;
			}
		}
		else
			break;
	}

	return count;
}

//Количество всех латинских букв в файле
void count_letter(string name) {
	//int* count_letter(string name){
	string str = "";
	char s;
	ifstream file;

	//Создаю массив и заполняю 0, Кол-во эл. 26 эквивалентно кол-ву букв
	int* count = new int[26];
	for (int i = 0; i < 26; ++i) count[i] = 0;

	file.open(name);

	if (!file) {
		file.clear();
		throw "Фаил открыть не удалось!";
	}
	else {
		//Иду посимвольно, если символ - буква, то записываю в массив
		while (file.get(s)) {
			if ('a' <= s && s <= 'z') 
				count[s-'a'] ++;
			
			if ('A' <= s && s <= 'Z')
				count[s - 'A'] ++;

			s = ' ';
		}
	}
	file.clear();
	file.close();


	//Вывожу буквы
	for (char i = 'a'; i <= 'z'; i = char(int(i) + 1)) 
		cout << setw(4) << std::left << i << " ";

	cout << "\n";
	print_arr(count, 26); //Вывожу массив

	delete[] count;
	//return count;
}

//самая длинная строка в файле
void max_len_str_f(string name){
	string str = "", max_str;
	ifstream file;
	int len_s;
	file.open(name);

	if (!file) {
		file.clear();
		throw "Фаил открыть не удалось!";
	}
	else {//Иду построчно и считываю длину строки, оцениваю
		if (!file.eof()) {
			getline(file, max_str);
			len_s = size(str);
		}
		while(!file.eof()){
			getline(file, str);
			
			if (len_s < size(str)) {
				len_s = size(str);
				max_str = str;
			}
		}
	}
	file.clear();
	file.close();
	cout << max_str + "\n";
}

//Количество слов
void count_vord_f(string name) {
	string str = "";
	ifstream file;
	int i = 1;

	file.open(name);

	if (!file) {
		file.clear();
		throw "Фаил открыть не удалось!";
	}
	else {//Считываю линию и обрабатываю 
		while (!file.eof()) {
			getline(file, str);

			cout << "В строке " << i << ". Количество слов: " << count_vorgs(str) << endl;		
			i++;
		}
	}

	file.clear();
	file.close();
}

// Функция удалят все подстроки вида sub 
void erase_str(string& s, const string sub) {
	int i = 0, Fs;
	int len_sub = size(sub);
	Fs = s.find(sub);
	//если есть строка удаляю и далее
	while (Fs != -1) {
		s.erase(Fs, len_sub);
		Fs = s.find(sub);
	}
}

//Удаляю се подстроки вида sub из файла (UP?)
void del_vord_f(string name, string del) {
	string str = str_of_file(name);

	ofstream file;

	file.open(name);

	if (!file) {
		file.clear();
		throw "Фаил открыть не удалось!";
	}
	else {
		erase_str(str, del);
		cout << str;
		file << str;
	}

	file.clear();
	file.close();
}

//Нумирую строки файла (UP?)
void numbered_str(string name) {
	string str = "", s = "", numer = "1)";
	int i = 1;
	ifstream file;

	file.open(name);

	if (!file) {
		file.clear();
		throw "Фаил открыть не удалось!";
	}
	else {//Считываю линию и обрабатываю
		while (!file.eof()) {	
			getline(file, s);
			str += numer + s + "\n";
			i++;
			s = "";
			numer = to_string(i) + ")";
		}
	}
	file.clear();
	file.close();

	cout << str << endl;
	ofstream f;

	f.open(name);

	f << str;

	f.clear();
	f.close();
}

//заменяет sub на ins в строке
void isert_str(string& s, const string sub) {
	int count = 0;
	int Fs = s.find(sub);
	while (Fs != -1) {//Если нашел sub заменяю на номер вхождения
		count++;
		s.replace(Fs, size(sub), to_string(count));
		Fs = s.find(sub);
	}
	
}

//заменяет sub на ins в файле (UP?)
void replese_sub_vord_count_f(string name, string sub) {
	string str = str_of_file(name);	
	ofstream file;

	file.open(name);

	if (!file) {
		file.clear();
		throw "Фаил открыть не удалось!";
	}
	else {
		isert_str(str, sub);
		cout << str;
		file << str;
	}

	file.clear();
	file.close();
}