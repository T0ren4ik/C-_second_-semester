#include "Header.h"

//���������� ���������� ����� � ������
string str_of_file(string filename) {
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
				str += s + " ";
			else
				str += " ";
		}
	}

	//�������� ����, ��������� ������
	file.clear();
	file.close();

	return str;


}

int count_lines(string name){
	ifstream in(name);
	string s;
	int i = 0;

	while (in.peek() != EOF) {
		getline(in, s);
		i++;
	}

	in.clear();
	in.close();

	return i;
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
	for (; i < s.length() + 1; ++i) {
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

n_A split(string s) {
	int len_s = size(s);
	string* AS; // ��������� �� ��� string
	int* I;
	int n = count_vorgs(s);
	//cout << "N:" << n << endl;

	if (n > 0) {
		// ������������ ��������� ������ ��� ������� AS
		AS = new string[n];
		I = new int[n];
		n = 0;
	}
	else
		throw "� ������ ��� ����!";

	//cout << "Len string:" << len_s << endl;
	int i = 0, i_start, i_end;
	while (i < len_s) {
		while (s[i] == ' ' && s[i]) {
			i++;
		}
		i_start = i;
		while (s[i] != ' ' && s[i]) {
			i++;
		}
		i_end = i - 1;

		//cout << s.substr(i_start, i_end - i_start + 1) << endl;
	
		if (i_end <= len_s - 1 && s[i_end] != ' ') {
			I[n] = i_start;
			AS[n] = s.substr(i_start, i_end - i_start + 1);
			n++;
		}

	}

	//print_arr(AS, n);
	n_A P{ n, AS, I };
	return P;
}

//========================================
/*
��� ��������� ����, ���������� ������������������ ������������ �����.
���������� ����� � ����� ������� �� ��������. ����� ����������� �� ������
�������� � �����.
*/
float min_abs_f(string name){
	float min_ = NULL;

	//���� ��������� �������
	try{
		string str = str_of_file(name);
		n_A P = split(str);
		// ��������, ��� �������� ����
		if (P.n > 0) {
			min_ = stof(P.A[0]);
			for (int i = 1; i < P.n; ++i) { // ��� ���������� �� ������
				if (abs(stof(P.A[i])) < min_)
					min_ = stof(P.A[i]);
			}
		}
		else
			throw "���� ����";

		delete[] P.A;
		delete[] P.I;

		return min_;
	}
	catch(const char * s){
		cout << s << endl;		
	}
}

/*
��� ��������� ����, ���������� ������ ������������ �����. ���������� ����� �
������ ������ ����� ���� ���������. ��������� ������� � �������� � ������
������. ��������� �������� � ����� ����. ������ ������ � ����� ������ ���������
�����, ����������� �������� � ������, ������������ �������� � ������.

*/
void create_f1_min_max_f(string name) {
	ifstream file;
	string str = "";
	float min_, max_;
	file.open(name);
	int c = count_lines(name); // ���������� �����
	float* B = new float[c * 2]; // ������ ��� �������� � ���������
	n_A P;
	int i;

	if (!file) {
		file.clear();
		throw "���� ������� �� �������!";
	}
	else { // ���� ��������
		for (i = 0; i < c; ++i) { // ��� ��������� 
			getline(file, str);
			//cout << str << endl;
			P = split(str);

			//print_arr(P.A, P.n);

			if (P.n > 0) { // ��� ������� � �������� � ������
				min_ = stof(P.A[0]);
				max_ = stof(P.A[0]);

				for (int i = 1; i < P.n; ++i) {
					//cout << P.A[i] << endl;
					if (stof(P.A[i]) < min_) 
						min_ = stof(P.A[i]);					

					if (stof(P.A[i]) > max_)
						max_ = stof(P.A[i]);
				}

				// ��������� � ������
				B[2 * i] = min_; 
				B[2* i + 1] = max_;
			}
			else {
				B[2 * i] = NULL;
				B[2* i + 1] = NULL;
			}

			delete[] P.A;
			delete[] P.I;
		}

	}
	//print_arr(B, c * 2);
	file.clear();
	file.close();

	ofstream f;

	// �������� ����� ����
	f.open("f1.txt");

	// ��������� ��� ��������
	for (int j = 0; j < i; ++j) {
		f << to_string(j + 1) + ")" + "Min: " + to_string(B[2 * j]) + " | Max: " + to_string(B[2 * j + 1]) + "\n";
		cout << to_string(j + 1) + ")" + "Min: " + to_string(B[2 * j]) + " | Max: " + to_string(B[2 * j + 1]) + "\n";
	}

	f.clear();
	f.close();


	delete[] B;
}

//��������� ����� �������
double distance(float x1, float y1, float x2, float y2){
	return sqrt(pow((double)abs(x1 - x2), 2) + pow((double)abs(y1 - y2), 2));
}

/*
� ��������� ����� � ������ ������ �������� ���������� ����� �� ���������, ����� �
������ ������ - ���������� ��������� �����. ����� ��� �����, �������� ��������� ����
�� ����� (����� ����, ���� ����� ���������).
*/
d_point max_len_point(string name){
	ifstream file;
	string str = "";
	n_A P;
	file.open(name);
	int count, i, j;

	if (!file) {
		file.clear();
		throw "���� ������� �� �������!";
	}
	else { // ���� ��������
		string str = str_of_file(name);
		n_A P = split(str);
		count = stoi(P.A[0]);
		float* K = new float[P.n];
		//cout << P.n << endl;
		//print_arr(P.A, P.n);
		//cout << count << endl;
		for (i = 1; i < P.n; ++i) { // ������ ������ �������� ��������� �����
			K[i - 1] = stof(P.A[i]);
		}
		print_arr(K, P.n - 1);

		double max_dist = 0.00;
		int max_i = 0, max_j = max_i;
		for (i = 0; i < P.n - 1; i = i + 2) // ��� ���������� ��������� � ��������� �����
			for (j = i + 2; j < P.n - 1; j = j + 2){
				double d = distance(K[i], K[i + 1], K[j], K[j + 1]); // ���������
				//cout << d << endl;
				if (d > max_dist || max_dist == 0.00){ // ���������
					max_dist = d;
					max_i = i; max_j = j;
				}
			}		
		//print_arr(K, P.n);
		// ��������������� ��������� � ����� �����
		point A{ K[max_i], K[max_i + 1] };
		point B{ K[max_j], K[max_j + 1] };

		d_point S{ A, B };

		delete[] K;
		delete[] P.A;
		delete[] P.I;
		return S;
	}
}

/*
� ��������� ����� � ������ ������ �������� ���������� �����������. ����� � � ������
������ ������ ������ ����������.
������ � ����������� �������� � ������.
�������� �������, ���������� ������ ��� ���� ����������� � ��������� ���� � ����
�������.
*/
void create_f2_table_from_f(string name) {
	ifstream file;
	string str = "";
	n_A P;
	file.open(name);

	int count, i, j;

	if (!file) {
		file.clear();
		throw "���� ������� �� �������!";
	}
	else { // ���� �������� ��������� ����������

		string str = str_of_file(name);
		//cout << str << endl;

		n_A P = split(str);
		count = stoi(P.A[0]);
		//cout << P.n << endl;

		string* K = new string[P.n - 1];

		for (i = 1; i < P.n; ++i) {
			K[i - 1] = P.A[i];
		}

		ofstream f;

		// ������ � �������� ����
		f.open("f2.txt");

		f << "|-----------------------------------------------------|" << endl;
		f << "|" << setw(30) << left << "���";
		f << "|" << setw(16)   << "���� ��������" << left;
		f << "|" << setw(5) << "���" << left << "|" << endl;

		for (i = 0; i < P.n - 1; i = i + 5) {
			f << "|-----------------------------------------------------|" << endl;
			f << "|" << setw(30) << left << K[i] + " " + K[i + 1] + " " + K[i + 2];
			f << "|" << setw(16) << K[i + 3] << left;
			f << "|" << setw(5) << K[i + 4] << left << "|" << endl;
		}

		f << "|-----------------------------------------------------|" << endl;


		f.clear();
		f.close();


		delete[] K;
		delete[] P.A;
		delete[] P.I;
	}

}