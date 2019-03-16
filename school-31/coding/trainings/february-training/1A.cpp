#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<long long> a, l, r, q, b, c;
const long long MAX = (long long)(1 << 30) - 1;
int LEN;

void _Init(int n) {
	a.assign(n + 1, 0);
	LEN = (int)sqrt(n);
	b.assign(n / LEN + 1, 0);
}

void _Or(int l, int r, long long v, int n) {
	int left = l / LEN;
	int right = r / LEN;
	if (left == right) {
		for (int i = l; i <= r; ++i) {
			a[i] = a[i] | v;
		}
	} else {
		for (int i = l; i <= min(n, (left + 1) * LEN - 1); ++i) {
			a[i] = a[i] | v;
		}
		for (int i = left + 1; i <= right - 1; ++i) {
			b[i] = b[i] | v;
		}
		for (int i = right * LEN; i <= r; ++i) {
			a[i] = a[i] | v;
		}
	}
}

void _Upd(int n) {
	for (int i = 1; i <= n; ++i) {
		a[i] = a[i] | b[i / LEN];
	}
}

void _aInit(int n) {
	c.assign(n / LEN + 1, MAX);
	for (int i = 1; i <= n; ++i) {
		c[i / LEN] = c[i / LEN] & a[i];
	}
}

long long _And(int l, int r, int n) {
	long long res = MAX;
	int left = l / LEN;
	int right = r / LEN;
	if (left == right) {
		for (int i = l; i <= r; ++i) {
			res = res & a[i];
		}
	} else {
		for (int i = l; i <= min(n, (left + 1) * LEN - 1); ++i) {
			res = res & a[i];
		}
		for (int i = left + 1; i <= right - 1; ++i) {
			res = res & c[i];
		}
		for (int i = right * LEN; i <= r; ++i) {
			res = res & a[i];
		}
	}
	return res;
}

int main() {
	int n, m;

	cin >> n >> m;

	_Init(n);
	l.resize(m + 1);
	r.resize(m + 1);
	q.resize(m + 1);
	for (int i = 1; i <= m; ++i) {
		cin >> l[i] >> r[i] >> q[i];
		_Or(l[i], r[i], q[i], n);
	}
	_Upd(n);

	_aInit(n);
	for (int i = 1; i <= m; ++i) {
		if (_And(l[i], r[i], n) != q[i]) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << " ";
	}
	cout << "\n";

	return 0;
}