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

int ts;
vector<long long> tree;

long long sum(int l, int r) {
	long long res = 0;
	l += ts;
	r += ts;
	while (l <= r) {
		if (l % 2 == 1) {
			res += tree[l];
			++l;
		}
		if (r % 2 == 0) {
			res += tree[r];
			--r;
		}
		l /= 2;
		r /= 2;
	}
	return res;
}

int main() {
	freopen("sum2.in", "r", stdin);
	freopen("sum2.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, m, l, r;

	cin >> n;
	ts = 1;
	while (ts < n) {
		ts *= 2;
	}
	tree.assign(ts * 2, 0);
	for (int i = ts; i < n + ts; ++i) {
		cin >> tree[i];
	}
	for (int i = ts - 1; i >= 1; --i) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> l >> r;
		cout << sum(l - 1, r - 1) << "\n";
	}

	return 0;
}
