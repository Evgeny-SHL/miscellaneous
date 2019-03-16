#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
vector<int> b;
vector<int> c;

void counting_sort(int k) {
	c.resize(k + 1, 0);
	b.resize(a.size(), 0);
	for (int j = 0; j < a.size(); ++j)
		++c[a[j]];
	for (int i = 1; i <= k; ++i)
		c[i] += c[i - 1];
	for (int j = a.size() - 1; j >= 0; --j) {
		b[c[a[j]] - 1] = a[j];
		--c[a[j]];
	}
}

int main() {
	int n, k;

	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	counting_sort(k);

	for (int i = 0; i < n; ++i)
		cout << b[i] << " ";
	cout << '\n';

	return 0;
}