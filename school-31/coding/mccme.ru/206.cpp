#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int> > a;

int main() {
	int n, m;

	cin >> n >> m;
	a.resize(n + 1);
	a[1].resize(m + 1, 1);
	for (int i = 2; i <= n; ++i) {
		a[i].resize(m + 1, 0);
		a[i][1] = 1;
	}

	for (int i = 2; i <= n; ++i)
		for (int j = 2; j <= m; ++j)
			a[i][j] = a[i - 1][j] + a[i][j - 1];

	cout << a[n][m];

	return 0;
}