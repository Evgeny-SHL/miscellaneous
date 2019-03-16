#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <ctime>
using namespace std;

const long long bInf = (long long)(1e18 + 3);
const int sInf = (int)(1e9 + 7);
const double Eps = (double)(1e-9);
const int None = -1;
const double Eur = exp(1.0);
const double Pi = acos(-1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

int tsz = 1;
vector<long long> t1, t2;

void update(int i, long long v) {
	i += tsz;
	t1[i] = v;
	t2[i] = v;
	i /= 2;
	while (i > 0) {
		t1[i] = min(t1[i * 2], t1[i * 2 + 1]);
		t2[i] = max(t2[i * 2], t2[i * 2 + 1]);
		i /= 2;
	}
}

long long get_min(int l, int r) {
	long long res = sInf;
	l += tsz;
	r += tsz;
	while (l <= r) {
		if (l % 2 == 1) {
			res = min(res, t1[l]);
			++l;
		}
		if (r % 2 == 0) {
			res = min(res, t1[r]);
			--r;
		}
		l /= 2;
		r /= 2;
	}
	return res;
}

long long get_max(int l, int r) {
	long long res = -sInf;
	l += tsz;
	r += tsz;
	while (l <= r) {
		if (l % 2 == 1) {
			res = max(res, t2[l]);
			++l;
		}
		if (r % 2 == 0) {
			res = max(res, t2[r]);
			--r;
		}
		l /= 2;
		r /= 2;
	}
	return res;
}

int main() {
	freopen("rvq.in", "r", stdin);
	freopen("rvq.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, m;
	long long x, y;

	n = 100000;
	while (tsz < n) {
		tsz *= 2;
	}
	t1.assign(tsz * 2, sInf);
	t2.assign(tsz * 2, -sInf);
	for (long long i = 1; i <= n; ++i) {
		t1[i + tsz - 1] = t2[i + tsz - 1] = (i * i) % 12345 + (i * i * i) % 23456;
	}
	for (int i = tsz - 1; i >= 1; --i) {
        t1[i] = min(t1[i * 2], t1[i * 2 + 1]);
        t2[i] = max(t2[i * 2], t2[i * 2 + 1]);
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		if (x > 0) {
			cout << get_max(x - 1, y - 1) - get_min(x - 1, y - 1) << "\n";
		} else if (x < 0) {
			update(-x - 1, y);
		}
	}

	return 0;
}
