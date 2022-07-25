#include "Header.h"

//���������� ���������� ����� � ������
string str_of_file(string filename){
	string str = "", s;
	ifstream file;

	//�������� ����
	file.open(filename);

	if (!file) { // ���� �� �������� ����� ������
		file.clear();
		throw "���� ������� �� �������!";
	}
	else { // ���� ��������

		// ��� �� �����, �������� ������, ������������
		while (!file.eof()) {
			s = "";
			getline(file, s);

			if (s != "")
				str += s + "\n";
			else
				str += "\n";
		}
	}

	//�������� ����, ��������� ������
	file.clear();
	file.close();

	return str;

	
}

//������� ������� ���������� ���� � ������
int count_vorgs(string s) {
	int i = 0, count = 0;
	int Fs;

	//��������� ��������� �������
	while (s[i] == ' ' && s[i]) {
		i++;
	}

	//��� �� �����
	for (; i < s.length(); ++i) {
		// ���������� count(���-�� ����)
		count++;
		//���� ���� ���������� �����, �� ���������
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

//���������� ���� ��������� ���� � �����
void count_letter(string name) {
	//int* count_letter(string name){
	string str = "";
	char s;
	ifstream file;

	//������ ������ � �������� 0, ���-�� ��. 26 ������������ ���-�� ����
	int* count = new int[26];
	for (int i = 0; i < 26; ++i) count[i] = 0;

	file.open(name);

	if (!file) {
		file.clear();
		throw "���� ������� �� �������!";
	}
	else {
		//��� �����������, ���� ������ - �����, �� ��������� � ������
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


	//������ �����
	for (char i = 'a'; i <= 'z'; i = char(int(i) + 1)) 
		cout << setw(4) << std::left << i << " ";

	cout << "\n";
	print_arr(count, 26); //������ ������

	delete[] count;
	//return count;
}

//����� ������� ������ � �����
void max_len_str_f(string name){
	string str = "", max_str;
	ifstream file;
	int len_s;
	file.open(name);

	if (!file) {
		file.clear();
		throw "���� ������� �� �������!";
	}
	else {//��� ��������� � �������� ����� ������, ��������
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

//���������� ����
void count_vord_f(string name) {
	string str = "";
	ifstream file;
	int i = 1;

	file.open(name);

	if (!file) {
		file.clear();
		throw "���� ������� �� �������!";
	}
	else {//�������� ����� � ����������� 
		while (!file.eof()) {
			getline(file, str);

			cout << "� ������ " << i << ". ���������� ����: " << count_vorgs(str) << endl;		
			i++;
		}
	}

	file.clear();
	file.close();
}

// ������� ������ ��� ��������� ���� sub 
void erase_str(string& s, const string sub) {
	int i = 0, Fs;
	int len_sub = size(sub);
	Fs = s.find(sub);
	//���� ���� ������ ������ � �����
	while (Fs != -1) {
		s.erase(Fs, len_sub);
		Fs = s.find(sub);
	}
}

//������ �� ��������� ���� sub �� ����� (UP?)
void del_vord_f(string name, string del) {
	string str = str_of_file(name);

	ofstream file;

	file.open(name);

	if (!file) {
		file.clear();
		throw "���� ������� �� �������!";
	}
	else {
		erase_str(str, del);
		cout << str;
		file << str;
	}

	file.clear();
	file.close();
}

//������� ������ ����� (UP?)
void numbered_str(string name) {
	string str = "", s = "", numer = "1)";
	int i = 1;
	ifstream file;

	file.open(name);

	if (!file) {
		file.clear();
		throw "���� ������� �� �������!";
	}
	else {//�������� ����� � �����������
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

//�������� sub �� ins � ������
void isert_str(string& s, const string sub) {
	int count = 0;
	int Fs = s.find(sub);
	while (Fs != -1) {//���� ����� sub ������� �� ����� ���������
		count++;
		s.replace(Fs, size(sub), to_string(count));
		Fs = s.find(sub);
	}
	
}

//�������� sub �� ins � ����� (UP?)
void replese_sub_vord_count_f(string name, string sub) {
	string str = str_of_file(name);	
	ofstream file;

	file.open(name);

	if (!file) {
		file.clear();
		throw "���� ������� �� �������!";
	}
	else {
		isert_str(str, sub);
		cout << str;
		file << str;
	}

	file.clear();
	file.close();
}