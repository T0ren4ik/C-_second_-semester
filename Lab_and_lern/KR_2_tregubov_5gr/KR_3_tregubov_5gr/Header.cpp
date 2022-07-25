#include "Header.h"

/*
��������� ������ char* � ������ � ���������� ������ ����� ��������� �������� ������� ��� ������� ��������� ������:
������� ��� ��������� ���������� ������� ������.
*/
void remove_last_s_chr(char* str){
	char last;
	int i = 0, j, ind_last;

	while (str[i]) i++;
	ind_last = i - 1;
	last = str[ind_last];

	for (i = 0; str[i]; ++i) {
		if (str[i] == last) {
			j = i;
			for (; str[j + 1]; ++j) {
				swap(str[j], str[j + 1]);
			}
			str[j] = 0;
			i--;
		}
	}
}


//� ��������� ����� �������� ������������������ ����� �����. ����� ����� (������) � ������������ ������ ����.
int max_sum_digit_numder_f(string filename){
	ifstream f;
	f.open(filename);
	char c;
	int i, max = NULL, pr_zn;
	string el;
	
	while (f.get(c)) {
		cout << c << endl;

		//while (f.peek() == ' ') {
		//	//cout << "1" << endl;
		//	f.ignore(1);
		//}
		
		//while (f.get(c) && c != ' ') {
		//	//cout << "2" << endl;
		//	cout << c << endl;
		//	el += c;
		//	f.get(c);
		//}
		
		el = c;
		//cout << el << endl;


		if (max == NULL || max < stoi(el)) {
			max = stoi(el);		
		}
		el = "";
	}
		
	return max;
}


/*
������ �������� �����, ����������� ����� ��� ����������� ���������. ��������� ������ std::string,
������� ��������� �����, ������� �� �������� �������� �����.
*/
void remove_last_word_str(string& s, char b){
	int len_s = size(s);
	int i = len_s, Fs;
	string sub_s;

	while (s[i] == ' ' && i > 0) {
		i--;
	}

	for (; i > 0;) {
		Fs = s.rfind(' ', i);
		if (Fs != -1) {
			sub_s = s.substr(Fs, i - Fs + 1);
			//cout << Fs << " | " << sub_s << endl;
			

			if (sub_s.find(b) == -1) {
				s.erase(Fs, i - Fs + 1);
				break;
			}
		
			i = Fs - 1;

			while (s[i] == ' ' && i > 0) {
				i--;
			}

		}
		else {
			sub_s = s.substr(0, i + 1);

			if (sub_s.find(b) == -1) {
				s.erase(0, i + 1);
			}

			break;
		}

	}
}
