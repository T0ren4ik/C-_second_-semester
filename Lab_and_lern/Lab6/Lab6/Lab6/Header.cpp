#include "Header.h"

void read(int*& a, int& n){
	cout << "Size mass: ";
	cin >> (n);
	a = new int[n];

	for (int i = 0; i < n; ++i) {
		cout << "EL mass #" << i << ": ";
		cin >> a[i];
	}
}

int* random_array(int n){
	int* b = new int[n];

	for (int i = 0; i < n; ++i){
		b[i] = std::rand();
	}

	return b;
}

// add to centre
int* new_array(int* a, int n, int el) {
	int* b = new int[n + 1];

	int k = round(n / 2.);
	for (int i = 0; i < k; ++i)
		b[i] = a[i];

	b[k] = el;

	for (int i = k + 1; i < n + 1; ++i)
		b[i] = a[i-1];


	return b;
}

// удаление дубликатов
void del_double(int*& a, int& n) {
	int k = 0;
	int j = 0;

	// количество дубликатов
	for (int i = 0; i < n - 1; ++i) {   
		if (a[i] == a[i + 1]) {
			j = i + 2;
			k++;
			while (j < n && a[i] == a[j]) {
				j++;
				k++;
			}
			i = j;
		}
	}  

	n -= k;
	int* b = new int[n];
	j = 0;

	// присваиваю последний элемент a b, если это не дубликат (тк в цикле иду не до конца)
	if (a[n + k - 1] != a[n + k - 2]) 
		b[n - 1] = a[n + k - 1];

	for (int i = 0; i < n + k - 1; ++i) {		
		if (a[i] != a[i + 1]) {		
			b[j] = a[i];
			j++;
		}
		else {
			b[j] = a[i];
			j++;
			
			k = i + 2;
			while (a[i] == a[k] && (k < n + k - 1))
				k++;

			i += k - i - 1;
		}		
	}
	delete[] a; // очищаю память
	a = b;
}

// сортировка
void selectionSort(int* a, int n) {
	int min;
	for (int i = 0; i < n - 1; ++i) {
		min = i;
		for (int j = i + 1; j < n; ++j)
			if (a[j] < a[min]) min = j;
		swap(a[i], a[min]);
	}
}

// печать масива
void print(const int *arr, int n) {
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// бинарный поиск
void bin_find(int* a, int n, int key){
	selectionSort(a, n);

	bool flag = false;
	int l = 0; 
	int r = n - 1;
	int mid;

	while ((l <= r) && (flag != true)) {
		mid = (l + r) / 2; 

		if (a[mid] == key) flag = true; 
		if (a[mid] > key) r = mid - 1; 
		else l = mid + 1;
	}

	if (flag) cout << "Индекс элемента " << key << " в массиве равен: " << mid << endl;
	else cout << "Извините, но такого элемента в массиве нет" << endl;

}



bool isSimple(int x) {
	bool f = true;
	for (int i = 2; i < sqrt((double)abs(x)) && f; ++i)
		f = x % i != 0;
	return f;
}

bool pos(int a) {
	return a > 0;
}

bool zero(int a) {
	return a==0 ? 1 : 0;
}

bool chet(int a) {
	return (a % 2) == 0 ? 1 : 0;
}

bool F(int* a, int n, pred1 f){
	bool flag = true;
	int i = 0;
	while (i < n && flag) {
		cout << i << " | " << a[i] << endl;
		flag = f(a[i]);
		i++;
	}

	if (flag)
		cout << "Условие выполнено" << endl;
	else
		cout << "Условие не выполнено" << endl;
	return flag;
}

int T_F(int* a, int n, pred2 f){
	bool flag = true;
	int i = 0;
	while (i < (n - 1) && flag) {
		flag = f(a[i], a[i + 1]);
		i++;
	}

	
	return i < n ? i : -1;
}

bool vozr(int a, int b) {
	return (a <= b) ? 1 : 0;
}

bool el_equivalent(int a, int b){
	return (a == b) ? 0 : 1;
}
