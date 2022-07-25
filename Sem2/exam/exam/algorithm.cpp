#include "algorithm.h"

vector<char> string2vector(string s){
	vector<char> v;
	copy(s.begin(), s.end(), inserter(v, v.end()));
	return v;
}

void count_char_str(string s, vector<char> m)
{
	vector<char> v = string2vector(s);

	for (char x : m) {
		char value_ch = x;
		cout << "Количество " << value_ch << " ";
		cout << count_if(v.begin(), v.end(), [&value_ch](char value) {return value == value_ch; }) << endl;
	}
}

void str2STR(string& str) {
	transform(str.begin(), str.end(), str.begin(), toupper);
}

vector<string> create_v_s(string str)
{
	vector<string> line;
	string token;
	istringstream iss(str);

	while (getline(iss, token, ' '))
		line.push_back(token);

	return line;
}

void code_v_string(vector<string>& v) {
	vector<int> ind(v.size());
	for (auto i = 0; i < v.size(); i++)
	{
		ind[i] = i;
	}

	transform(v.begin(), v.end(), ind.begin(), v.begin(), [](string s1, int i) { rotate(s1.begin(), s1.begin() + i, s1.end()); return s1; });
	for (string s2 : v)
		cout << s2 << endl;
	cout << endl;
}


void count_word(string s, vector<string> v)
{
	cout << "Количество " << s << " ";
	string value_str = s;
	cout << count_if(v.begin(), v.end(), [&](string s) {return s == value_str; }) << endl;
}


void ferst_different(vector<string> v1, vector<string> v2) {
	auto s2 = mismatch(v1.begin(), v1.end(), v2.begin());
	std::cout << "First mismatching elements: " << *s2.first;
	std::cout << " and " << *s2.second << '\n';
}

void permutation(string s1, string s2)
{
	if (is_permutation(s1.begin(), s1.end(), s2.begin())) {
		cout << "string contain the same elements.\n";
		return;
	}
	cout << "string contains the not same elements.\n";
}

void findPermutations(string s)
{
	cout << "Possible permutations are:\n";

	do {

		cout << s;

	} while (next_permutation(s.begin(), s.end()));

}

void vect_gener_NM(vector<int>& v, int n, int m)
{
	cout << "start_vect: ";
	if (v.size() > 0)
		for (int x : v) {
			cout << x << " ";
		}
	else cout << "nulptr" << endl;
	
	cout << "\nnew_vect: ";
	generate(v.begin() + n, v.begin() + m, rand);

	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
}


double arithmetic_mean(vector<int>& v)
{
	int count_ = 0, sum_mean = 0;
	for_each(v.begin(), v.end(), [&](int x) {
		count_ ++; 
		sum_mean += x; 
	});

	double mean = double(sum_mean) / count_;
	cout << "Среднее вектора: " << mean << endl;
	return mean;
}


void MIN_V(vector<int>& v)
{
	int MIN = abs(v[0]);
	for_each(v.begin(), v.end(), [&](int x) {x = MIN < abs(x) ? x : MIN; });
	cout << "MIN ABS  вектора: " << MIN << endl;
}

void count_min_mean(vector<int>& v) {
	double mean = arithmetic_mean(v);
	cout << "count_min_mean  вектора: ";
	cout << count_if(v.begin(), v.end(), [&](int x) {return (x < mean); }) << endl;
}


void copy_v_more_mean(vector<int>& v1, vector<int>& v2)
{
	double mean = arithmetic_mean(v1);
	cout << "copy_v_more_mean: ";
	remove_copy_if(v1.begin(), v1.end(), v2.begin(), [&](int x) {return x > mean; });
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
}


void degree(vector<int>& v)
{
	transform(v.begin(), v.end(), v.begin(), [](int x) {return x * x; });
	cout << "degree: ";
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}


void print_matrix(vector<vector<int>>& m)
{
	cout << "========================\n";
	for_each(m.begin(), m.end(), [](vector<int> v) {
		for_each(v.begin(), v.end(), [](int x) {cout << setw(7) << x << "|"; });
		cout << "\n========================\n"; 
	});
}

void push_el_matrix(vector<vector<int>>& mat, int n, int m)
{
	for (int i = 0; i < n; ++i) {
		generate(mat[i].begin(), mat[i].end(), rand);
	}
}

void min_row_matrix(vector<vector<int>>& m)
{
	int SUM, sum_v = 0;
	for_each(m[0].begin(), m[0].end(), [&](int x) {sum_v += x; });
	SUM = sum_v; auto ind = m[0];

	for (vector<int> x : m) {
		for_each(x.begin(), x.end(), [&](int x) {sum_v += x; });
		if (SUM > sum_v) ind = x;
	}
	
	copy(ind.begin(), ind.end(), ostream_iterator<int>(cout, " "));
}

bool IsZero(vector<int> x) {
	cout << "1234\n";
	for (int el : x)
		if (el != 0) return 0;
	return 1;
}

vector<vector<int>>::iterator remove_zero_row_matrix(vector<vector<int>>& m)
{
	return remove_if(m.begin(), m.end(), IsZero);
}

void min_el_matrix_wVect(vector<vector<int>>& m)
{
	vector<int> v;
	transform(m.begin(), m.end(), back_inserter(v), [](vector<int> v1) { return  *min_element(v1.begin(), v1.end()); });
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

void composition_matrix(vector<vector<int>>& mat, vector<vector<int>>& mat1)
{
	int n = mat.size();
	vector <vector<int>> matT(n, vector <int>(n));
	vector <int> res;
	
	//Транспонирование
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			(matT[j][i] = mat1[i][j]);
		}
	}
	print_matrix(matT);

	for (vector<int> v1 : mat)
		for (vector<int> v2 : matT) {
			vector <int> pr(n);
			transform(v1.begin(), v1.end(), v2.begin(), back_inserter(pr),
				[](int x, int y) {
					return x * y;
				});
			res.push_back(accumulate(pr.begin(), pr.end(), 0));
		}

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			(matT[j][i] = res[i + j]);
		}
	}
	print_matrix(matT);
}

