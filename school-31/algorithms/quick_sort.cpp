#include <iostream>
#include <vector>
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

void quick_sort(int l, int r) {
	if (l < r) {
		int q = part(l, r);
		quick_sort(l, q);
		quick_sort(q + 1, r);
	}
}

int main() {
	int n;

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	quick_sort(0, n - 1);

	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << '\n';

	return 0;
}