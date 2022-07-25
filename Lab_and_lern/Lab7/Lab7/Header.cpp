#include <D:\C++\Lab_and_lern\Lab7\Lab7\Header.h>

int rec_sum(int* a, int i){
	i--;
	if (i == 0) {
		return a[i];
	}
	return a[i] + rec_sum(a, i);
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

int F_count(int* a, int i, pred f) {
	i--;
	if (i == 0) {
		return f(a[i]) ? 1 : 0;
	}
	return (f(a[i]) ? 1 : 0) + F_count(a, i, f);
}

bool chet(int a) {
	return (a % 2) == 0 ? 1 : 0;
}


int rec_max_el_seg(int* begin, int* end) {
	if (begin == end) {
		return *begin;
	}
	return max(*begin, rec_max_el_seg(begin + 1, end));
}

bool rec_zero_not(int* a, int i){
	i--;

	if ((a[i] == 0)) {
		return false;
	}
	else if (i == 0) {
		return true;
	}
	return rec_zero_not(a, i);
}

double ratio_mud_sum(int* a, int n){
	int* zero = a;

	while (*zero != 0 && ++zero < a + n - 1);
	

	if (a == zero ) {
		throw 1;
	}
	else if ((a + n - 1) == zero) {
		throw 2;
	}
	else {
		float sum_past_zero = rec_sum(a, zero - a);
		float sum_futer_zero = rec_sum(zero, n - (zero - a));
		if (sum_futer_zero)
			return sum_past_zero / sum_futer_zero;
		else
			throw 0;
	}
}

void read(int*& a, int& n) {
	if (a == NULL) {
		cout << "Size mass: ";
		cin >> (n);
		a = new int[n];

		for (int i = 0; i < n; ++i) {
			cout << "EL mass #" << i << ": ";
			cin >> a[i];
		}
	}
	else
		throw "Память занята";
}


void print_arr(const int* arr, int n) {
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}