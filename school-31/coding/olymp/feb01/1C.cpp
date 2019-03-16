#include <iostream>
//#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<long long> a, l, r, d, b, cnt, bCnt;
int LEN, LENq;

//ifstream cin("input.txt");
//ofstream cout("output.txt");

void qInit(int m) {
	LENq = (int)sqrt(m);
	bCnt.assign((m - 1) / LENq + 1, 0);
	cnt.assign(m, 0);
}

void qInc(int l, int r, int m) {
	int left = l / LENq;
	int right = r / LENq;
	if (left == right) {
		for (int i = l; i <= r; ++i) {
			++cnt[i];
		}
		return;
	}
	for (int i = l; i < min(m, LENq * (left + 1)); ++i) {
		++cnt[i];
	}
	for (int i = left + 1; i < right; ++i) {
		++bCnt[i];
	}
	for (int i = LENq * right; i <= r; ++i) {
		++cnt[i];
	}
	return;
}

void qFin(int m) {
	for (int i = 0; i < m; ++i) {
		d[i] = d[i] * (cnt[i] + bCnt[i / LENq]);
	}
	return;
}

void aInit(int n) {
	LEN = (int)sqrt(n);
	b.assign((n - 1) / LEN + 1, 0);
}

void aInc(int l, int r, int d, int n) {
	int left = l / LEN;
	int right = r / LEN;
	if (left == right) {
		for (int i = l; i <= r; ++i) {
			a[i] += d;
		}
		return;
	}
	for (int i = l; i < min(n, LEN * (left + 1)); ++i) {
		a[i] += d;
	}
	for (int i = left + 1; i < right; ++i) {
		b[i] += d;
	}
	for (int i = LEN * right; i <= r; ++i) {
		a[i] += d;
	}
	return;
}

void aFin(int n) {
	for (int i = 0; i < n; ++i) {
		a[i] += b[i / LEN];
	}
}

int main() {
	int n, m, k;
	int x, y;

	cin >> n >> m >> k;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	l.resize(m);
	r.resize(m);
	d.resize(m);
	for (int i = 0; i < m; ++i) {
		cin >> l[i] >> r[i] >> d[i];
		--l[i];
		--r[i];
	}

	qInit(m);
	for (int i = 0; i < k; ++i) {
		cin >> x >> y;
		qInc(x - 1, y - 1, m);
	}
	qFin(m);

	aInit(k);
	for (int i = 0; i < m; ++i) {
	//	if (d[i] > 0) {
			aInc(l[i], r[i], d[i], n);
	//	}
	}
	aFin(n);

	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << "\n";

	return 0;
}
