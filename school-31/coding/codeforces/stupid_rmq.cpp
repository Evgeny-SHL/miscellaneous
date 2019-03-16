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
vector<int> tree;

int find_min(int l, int r) {
	int res = sInf;
	l += tsz;
	r += tsz;
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
	freopen("stupid_rmq.in", "r", stdin);
	freopen("stupid_rmq.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, m, l, r;

	cin >> n;
	while (tsz < n) {
		tsz *= 2;
	}
	tree.resize(2 * tsz, sInf);
	for (int i = 0; i < n; ++i) {
		cin >> tree[i + tsz];
	}
	for (int i = tsz - 1; i >= 1; --i) {
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> l >> r;
		--l;
		--r;
		cout << find_min(l, r) << "\n";
	}

	return 0;
}
