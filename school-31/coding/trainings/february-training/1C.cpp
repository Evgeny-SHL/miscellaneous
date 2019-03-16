#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<long long> a, l, r, d;
vector<long long> c;
vector<long long> b1, b2;
int LEN1, LEN2;

void qInit(int m) {
	c.assign(m + 1, 0);
	LEN1 = (int)sqrt(m);
	b1.assign(m / LEN1 + 1, 0);
}

void qInc(int l, int r, int m) {
	int left = l / LEN1;
	int right = r / LEN1;
	if (left == right) {
		for (int i = l; i <= r; ++i) {
			++c[i];
		}
	} else {
		for (int i = l; i <= min(m, (left + 1) * LEN1 - 1); ++i) {
			++c[i];
		}
		for (int i = left + 1; i <= right - 1; ++i) {
			++b1[i];
		}
		for (int i = right * LEN1; i <= r; ++i) {
			++c[i];
		}
	}
}

void qUpd(int m) {
	for (int i = 1; i <= m; ++i) {
		d[i] *= (c[i] + b1[i / LEN1]);
	}
}

void aInit(int n) {
	LEN2 = (int)sqrt(n);
	b2.assign(n / LEN2 + 1, 0);
}

void aInc(int l, int r, long long v, int n) {
	int left = l / LEN2;
	int right = r / LEN2;
	if (left == right) {
		for (int i = l; i <= r; ++i) {
			a[i] += v;
		}
	} else {
		for (int i = l; i <= min(n, (left + 1) * LEN2 - 1); ++i) {
			a[i] += v;
		}
		for (int i = left + 1; i <= right - 1; ++i) {
			b2[i] += v;
		}
		for (int i = right * LEN2; i <= r; ++i) {
			a[i] += v;
		}
	}
}

void aUpd(int n) {
	for (int i = 1; i <= n; ++i) {
		a[i] += b2[i / LEN2];
	}
}

int main() {
	int n, m, k;
	int x, y;

	cin >> n >> m >> k;

	a.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	l.resize(m + 1);
	r.resize(m + 1);
	d.resize(m + 1);
	for (int i = 1; i <= m; ++i) {
		cin >> l[i] >> r[i] >> d[i];
	}

	qInit(m);

	for (int i = 1; i <= k; ++i) {
		cin >> x >> y;
		qInc(x, y, m);
	}
	qUpd(m);

	aInit(n);
	for (int i = 1; i <= m; ++i) {
		aInc(l[i], r[i], d[i], n);
	}
	aUpd(n);

	for (int i = 1; i <= n; ++i) {
		cout << a[i] << " ";
	}
	cout << "\n";

	return 0;
}