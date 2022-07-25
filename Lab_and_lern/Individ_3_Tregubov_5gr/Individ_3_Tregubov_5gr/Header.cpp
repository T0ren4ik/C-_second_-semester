#include "Header.h"

//Проверка, что  строка правильной записью положительного целого числа в десятичной системе счисления.
bool good_plus_des_total_number(const char* str){
	if (!*str) 
		return	false;

	while (*str == ' ' && *str) str++; //Убераю начальные пробелы

	while (*str) { // иду по строке и проверяюю, что символ число
		if (('0' <= *str) && (*str <= '9'))
			str++;
		else // если условие нарушается выхожу из функции
			return false;
	}

	return	true;
}

/*
Дан текстовый файл. Для каждой строки в файле определить
количество чисел в этой строке. Изменить файл так, чтобы количество
чисел было записано в начале каждой строки.
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
		throw "Фаил открыть не удалось!";
	}
	//Считываю линию и обрабатываю 
	else {
		p = 0;
		while (!file.eof()) {
			A[p] = 0;
			getline(file, str); //Получаю строку
			i = 0;
			

			while (str[i]) { // пока не конец
				flag = 0;
				if (isdigit(str[i]) || str[i] == '-') { //если встретил число, то количество++
					i++;
					while ((isdigit(str[i]) || str[i] == '.' || str[i] == '-') && str[i]) {
						if (str[i] == '.' || str[i] == '-')
							flag++;
						i++;
					}
					//проверка, что вещественное число
					if (flag <= 1)
						A[p] ++;
				}

				// проверка, что после преобразований не выйду за конец
				if (str[i])
					i++;
			}
			// составление итоговой строки
			out += "(" + to_string(A[p]) + ") " + str + "\n";

			//обнуление
			str = "";
			p++;
		}

		// проверка массива и строки
		for (i = 0; i < p; ++i)
			cout << A[i] << " ";
		cout << endl;
		cout << out;
	}

	//Очистка
	file.clear();
	file.close();

	// Изменение файла
	ofstream f;

	f.open(name);

	f << out;

	//Очистка
	f.clear();
	f.close();
}
