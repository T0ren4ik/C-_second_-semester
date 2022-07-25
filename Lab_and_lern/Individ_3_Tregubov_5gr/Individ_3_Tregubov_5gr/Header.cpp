#include "Header.h"

//��������, ���  ������ ���������� ������� �������������� ������ ����� � ���������� ������� ���������.
bool good_plus_des_total_number(const char* str){
	if (!*str) 
		return	false;

	while (*str == ' ' && *str) str++; //������ ��������� �������

	while (*str) { // ��� �� ������ � ���������, ��� ������ �����
		if (('0' <= *str) && (*str <= '9'))
			str++;
		else // ���� ������� ���������� ������ �� �������
			return false;
	}

	return	true;
}

/*
��� ��������� ����. ��� ������ ������ � ����� ����������
���������� ����� � ���� ������. �������� ���� ���, ����� ����������
����� ���� �������� � ������ ������ ������.
*/
void add_start_str_f_count_nubber(string name){
	string str = "", out = "";

	const int M = 256;
	int A[M];
	
	int i, p, flag;

	ifstream file;
	file.open(name);

	if (!file) {
		file.clear();
		throw "���� ������� �� �������!";
	}
	//�������� ����� � ����������� 
	else {
		p = 0;
		while (!file.eof()) {
			A[p] = 0;
			getline(file, str); //������� ������
			i = 0;
			

			while (str[i]) { // ���� �� �����
				flag = 0;
				if (isdigit(str[i]) || str[i] == '-') { //���� �������� �����, �� ����������++
					i++;
					while ((isdigit(str[i]) || str[i] == '.' || str[i] == '-') && str[i]) {
						if (str[i] == '.' || str[i] == '-')
							flag++;
						i++;
					}
					//��������, ��� ������������ �����
					if (flag <= 1)
						A[p] ++;
				}

				// ��������, ��� ����� �������������� �� ����� �� �����
				if (str[i])
					i++;
			}
			// ����������� �������� ������
			out += "(" + to_string(A[p]) + ") " + str + "\n";

			//���������
			str = "";
			p++;
		}

		// �������� ������� � ������
		for (i = 0; i < p; ++i)
			cout << A[i] << " ";
		cout << endl;
		cout << out;
	}

	//�������
	file.clear();
	file.close();

	// ��������� �����
	ofstream f;

	f.open(name);

	f << out;

	//�������
	f.clear();
	f.close();
}
