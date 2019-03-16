#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cassert>
using namespace std;

vector<int> a;

void shift(int l, int r) {
	int v = a[l];
	for (int i = l; i < r; ++i) {
		a[i] = a[i + 1];
	}
	a[r] = v;
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int n;

	cin >> n;
//	assert(n <= 10000);

	a.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		a[i] = i;
	}

	for (int k = 2; k <= n; ++k) {
		for (int i = 1; i <= n; i += k) {
			shift(i, min(n, i + k - 1));
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << a[i] << " \n"[i == n];
	}

	return 0;
}

