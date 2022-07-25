#include "set.h"

bool work_with_file(string filename1, string filename2) {
	ifstream fin1(filename1);
	if (!fin1.is_open()) {
		cout << "Error!" << endl;
		throw - 1;
	}
	ifstream fin2(filename2);
	if (!fin2.is_open()) {
		cout << "Error!" << endl;
		throw - 1;
	}

	string x;
	set<string> S1;
	set<string> S2;

	while (!fin1.eof())
	{
		fin1 >> x;
		S1 += x;
	}

	while (!fin2.eof())
	{
		fin2 >> x;
		S2 += x;
	}

    cout << S1 << endl;
    cout << S2 << endl;

	return (S1 == S2);
}

void sort(int a[], int n)
{
    int mid, left, right, l, r;
    mid = left = right = l = r = 0;
    stack <int> st;

    st.push(n - 1);
    st.push(0);
    do {
        left = st.top();
        st.pop();
        right = st.top();
        st.pop();
        {
            mid = a[(left + right) / 2];
            l = left;
            r = right;
            while (l < r)
            {
                while (a[l] < mid) l++;
                while (mid < a[r]) r--;
                if (l <= r)
                {
                    swap(a[l], a[r]);
                    l++;
                    r--;
                }
            }
        }
        if (left < r)
        {
            st.push(r);
            st.push(left);
        }
        if (l < right)
        {
            st.push(right);
            st.push(l);
        }
    } while (st.size() != NULL);
}

int main() {
	setlocale(LC_ALL, "ru");
	//Tree<double> t(2);
	//Tree<double> t1(2, 1);
	//t.printTree();
	//t1.printTree();
 //   t.printTS();
	//Tree<double> t2 = t.intersectionTree(t1);
	//t2.printTree();

	cout << "\n ans: " << work_with_file("el1.txt", "el2.txt");



    //int n = 10;
    //int* a = new int[n];
    //for (int i = 0; i < n; i++)
    //{
    //    a[i] = rand() % 100;
    //}
    //sort(a, n);
    //for (int i = 0; i < n; i++)
    //{
    //    cout << a[i] << " ";
    //}

	return 0;
}

