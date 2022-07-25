#include <iostream>

using namespace std;

void copy_char(char* s1, char* s2);

int main() {
	setlocale(LC_ALL, "RU");

	char s1[4] = "123";
	char s2[11] = "456";
	copy_char(s1, s2);

	cout <<"�������� <123> � <456>, ������� <456321123>. ���������: " << s2;
	cout << "\n";

	char* s3 = new char[2]{ '1' };
	char* s4 = new char[4]{ '2', '3', '4'};

	copy_char(s3, s4);
	cout << "�������� <1> � <234>, ������� <23411>. ���������: " << s4;
	cout << "\n";

	char* s5 = new char[4]{ '2', '3', '4' };
	char* s6 = new char[10]{'\0'};


	copy_char(s5, s6);
	cout << "�������� <234> � <>, ������� <432234>. ���������: " << s6;
	cout << "\n";

	return 0;
}

//������� ����������� ������ s1 � ������ s2 ������� � �������� �������, ����� � ��������. 
//��������������, ��� ������ � s2 ����������, ����� �������� �� ��������� ����� ������ � 
//���������� �� � ������� ��� ���������� ������� �� ������
void copy_char(char* s1, char* s2) {
	char* begin_s1 = s1;

	//��� �� ���������� ������� ������, ������� ���������� �����������
	while (*s1) s1++;
	s1--;

	//������ ��������� �� ������ ������ ������ � ��� �� �����
	char* p = s2;
	while (*p) p++;

	// ������� � �������� �������
	while (s1 != begin_s1) {
		*p++ = *s1--;
	}
	*p++ = *s1;

	// ������� � ����������� �������
	while (*begin_s1) {
		*p++ = *begin_s1++;
	}
	*p = '\0';//���������� ����� ������
}