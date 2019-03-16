#include <iostream>
#include <vector>
using namespace std;

vector<bool> d;

int main() {
	int n, m, k;

	cin >> n >> m;
	d.resize(n + 1, false);
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			if (j % (i + 1) == 0)
				d[j] = !d[j];

	k = 0;
	for (int i = 1; i <= n; ++i)
		if (d[i])
			++k;

	cout << k;

	return 0;
}