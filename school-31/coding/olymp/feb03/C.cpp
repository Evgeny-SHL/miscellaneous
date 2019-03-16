#include <iostream>
using namespace std;

int main() {
	int t, n, p, k;
	bool flag;
	cin >> t;
	for (int r = 1; r <= t; ++r) {
		cin >> n >> p;
		k = 0;
		flag = true;
		for (int i = 1; flag && (i < n); ++i) {
			for (int j = i + 1; flag && (j <= n); ++j) {
				cout << i << " " << j << "\n";
				++k;
				if (k == 2 * n + p) {
					flag = false;
				}
			}
		}
	}

	return 0;
}
