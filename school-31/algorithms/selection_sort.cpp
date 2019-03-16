#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

void selection_sort() {
	int n = a.size();
	for (int j = 0; j < n - 1; ++j) {
		int smallest = j;
		for (int i = j + 1; i < n; ++i)
			if (a[i] < a[smallest])
				smallest = i;
		int v = a[j];
		a[j] = a[smallest];
		a[smallest] = v;
	}
}

int main() {
	int n;

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	selection_sort();

	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << '\n';

	return 0;
}