#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int N = 100000;
const int LEN = (int) sqrt(N);
vector<int> a;
vector<int> b;

void _init() {
	b.resize((N - 1) / LEN + 1, 0);
}

void _update(int ind, int v) {
	b[ind / LEN] += v - a[ind];
	a[ind] = v;
}

int _sum(int i, int j) {
	int ans = 0;
	int l = i / LEN;
	int r = j / LEN;
	if (l == r) {
		for (int k = i; k <= j; ++k) {
			ans += a[k];
		}
		return ans;
	}
	for (int k = l + 1; k <= r - 1; ++k) {
		ans += b[k];
	}
	for (int k = i; k < min(N, LEN * (l + 1)); ++k) {
		ans += a[k];
	}
	for (int k = LEN * r; k <= j; ++k) {
		ans += a[k];
	}
	return ans;
}

int main() {
	int k, i, l, r, v;
	char key;
	a.resize(N, 0);
	_init();
	cin >> k;
	for (int t = 1; t <= k; ++t) {
		cin >> key;
		if (key == 'S') {
			cin >> i >> v;
			_update(i - 1, v);
		} else {
			cin >> l >> r;
			cout << _sum(l - 1, r - 1) << '\n';
		}
	}
	return 0;
}