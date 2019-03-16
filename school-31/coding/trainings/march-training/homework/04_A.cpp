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

int ts = 1;
vector<long long> tree[2];

void upd(int k, int i, long long v) {
	int j;
	j = i + ts;
	tree[k][j] = v;
	j /= 2;
	while (j > 0) {
		tree[k][j] = tree[k][j * 2] + tree[k][j * 2 + 1];
		j /= 2;
	}
}

long long sum(int k, int l, int r) {
	long long res = 0;
	l += ts;
	r += ts;
	while (l <= r) {
		if (l % 2 == 1) {
			res += tree[k][l];
			++l;
		}
		if (r % 2 == 0) {
			res += tree[k][r];
			--r;
		}
		l /= 2;
		r /= 2;
	}
	return res;
}

int main() {
	freopen("signchange.in", "r", stdin);
	freopen("signchange.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, m, k, l, r, j;
	long long x;

	cin >> n;
	while (ts < n) {
		ts *= 2;
	}
	tree[0].assign(ts * 2, 0);
	tree[1].assign(ts * 2, 0);
	for (int i = 0; i < n; ++i) {
		cin >> tree[i % 2][i + ts];
	}
	for (int i = ts - 1; i >= 1; --i) {
		tree[0][i] = tree[0][i * 2] + tree[0][i * 2 + 1];
		tree[1][i] = tree[1][i * 2] + tree[1][i * 2 + 1];
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> k;
		if (k == 1) {
			cin >> l >> r;
			--l;
			--r;
			cout << sum(l % 2, l, r) - sum(1 - l % 2, l, r) << "\n";
		} else {
			cin >> j >> x;
			--j;
			upd(j % 2, j, x);
		}
	}

	return 0;
}
