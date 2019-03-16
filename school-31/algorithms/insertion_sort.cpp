#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

void insertion_sort() {
	for (int j = 1; j < a.size(); ++j) {
		int key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > key) {
			a[i + 1] = a[i];
			--i;
		}
		a[i + 1] = key;
	}
}

int main() {
	int n;

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	insertion_sort();

	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << '\n';

	return 0;
}