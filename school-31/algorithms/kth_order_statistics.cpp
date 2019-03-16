#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> a;

int part(int l, int r) {
	int x = a[l];
	int i = l - 1;
	int j = r + 1;
	while (true) {
		do {
			--j;
		} while (a[j] > x);
		do {
			++i;
		} while (a[i] < x);
		if (i < j) {
			int y = a[i];
			a[i] = a[j];
			a[j] = y;
		} else return j;
	}
}

int randomized_partition(int l, int r) {
	int i = l + rand() % (r - l + 1);
	int v = a[l];
	a[l] = a[i];
	a[i] = v;
	return part(l, r);
}

int randomized_select(int l, int r, int k) {
	if (l == r)
		return a[l];
	int m = randomized_partition(l, r);
	int len = m - l + 1;
	if (k == len)
		return a[m];
	else if (k < len)
		return randomized_select(l, m - 1, k);
	else
		return randomized_select(m + 1, r, k - len);
}

int main() {
	int n, k, t;

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cin >> k;

	cout << randomized_select(0, n - 1, k) << '\n' << '\n';

	return 0;
}