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
vector<long long> tree;

long long sum(int l, int r) {
	long long res = sInf;
	l += ts;
	r += ts;
	while (l <= r) {
		if (l % 2 == 1) {
			res = min(res, tree[l]);
			++l;
		}
		if (r % 2 == 0) {
			res = min(res, tree[r]);
			--r;
		}
		l /= 2;
		r /= 2;
	}
	return res;
}

int main() {
	freopen("sparse.in", "r", stdin);
	freopen("sparse.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, m, u, v, l, r;
	long long a, ans;

	cin >> n >> m >> a;
	while (ts < n) {
		ts *= 2;
	}
	tree.assign(ts * 2, 0);
	tree[ts] = a;
	for (int i = ts + 1; i < ts + n; ++i) {
		tree[i] = (23 * tree[i - 1] + 21563) % 16714589;
	}
	for (int i = ts - 1; i >= 1; --i) {
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
	}
	cin >> u >> v;
	l = min(u, v) - 1;
	r = max(u, v) - 1;
	ans = sum(l, r);
	for (int i = 1; i < m; ++i) {
		u = ((17 * u + 751 + ans + 2 * i) % n) + 1;
		v = ((13 * v + 593 + ans + 5 * i) % n) + 1;
		l = min(u, v) - 1;
		r = max(u, v) - 1;
		ans = sum(l, r);
	}
	cout << u << " " << v << " " << ans << "\n";

	return 0;
}
