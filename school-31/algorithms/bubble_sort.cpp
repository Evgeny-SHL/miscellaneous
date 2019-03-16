#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

void bubble_sort() {
	for (int i = 0; i < a.size() - 1; ++i)
		for (int j = a.size() - 1; j >= i + 1; --j)
			if (a[j] < a[j - 1]) {
				int v = a[j];
				a[j] = a[j - 1];
				a[j - 1] = v;
			}
}

int main() {
	int n;

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	bubble_sort();

	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << '\n';

	return 0;
}