#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 7;
vector<int> a;
vector<int> a_left;
vector<int> a_right;

void mrg(int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	a_left.resize(n1 + 2);
	a_right.resize(n2 + 2);
	for (int i = 1; i <= n1; ++i)
		a_left[i] = a[l + i - 1];
	for (int j = 1; j <= n2; ++j)
		a_right[j] = a[m + j];
	a_left[n1 + 1] = INF;
	a_right[n2 + 1] = INF;
	int i = 1;
	int j = 1;
	for (int k = l; k <= r; ++k)
		if (a_left[i] <= a_right[j]) {
			a[k] = a_left[i];
			++i;
		} else {
			a[k] = a_right[j];
			++j;
		}
}

void merge_sort(int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		merge_sort(l, m);
		merge_sort(m + 1, r);
		mrg(l, m, r);
	}
}

int main() {
	int n;

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	merge_sort(0, n - 1);

	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << '\n';

	return 0;
}