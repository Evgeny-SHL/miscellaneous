#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int> > a;

int main() {
	int n;

	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		a[i].resize(i + 1, 0);
		a[i][1] = 1;
		a[i][i] = 1;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 2; j <= i - 1; ++j)
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j)
			cout << a[i][j] << " ";
		cout << '\n';
	}

	return 0;
}