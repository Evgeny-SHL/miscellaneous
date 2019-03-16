#pragma comment(linker, "/STACK:268435456")
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;

const double Eps = (double)(1.0e-9);
const long long bInf = (long long)(1e18 + 3);
const long long sInf = (long long)(1e9 + 7);
const int None = -1;
const double Pi = acos(-1.0);
const double Eu = exp(1.0);

struct query {
	int l, r;
	long long x;
	query(int p1 = 0, int p2 = 0, long long p3 = 0) {
		l = p1;
		r = p2;
		x = p3;
	}
};

vector<long long> a;
vector<int> used;
vector<query> q;

int main() {
	freopen("lottery.in", "r", stdin);
	freopen("lottery.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, m, p;
	long long k, ans, dlt, mul1, mul2;
	bool good;
	cin >> n >> m >> k;
	a.resize(n + 1);
	used.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		a[i] = 0;
		used[i] = false;
	}
	q.resize(m + 1);
	q[0] = query(1, n, k);
	for (int i = 1; i <= m; ++i) {
		cin >> q[i].l >> q[i].r >> q[i].x;
		for (int j = q[i].l; j <= q[i].r; ++j) {
			if (q[i].x < q[a[j]].x) {
				a[j] = i;
			}
			used[j] = true;
		}
	}
	ans = 1;
	for (int i = 0; i <= m; ++i) {
		p = 0;
		for (int j = q[i].l; j <= q[i].r; ++j) {
			if (a[j] == i) {
				++p;
			}
		}
		if (p == 0) {
			good = false;
			for (int j = q[i].l; j <= q[i].r; ++j) {
				if (q[a[j]].x == q[i].x) {
					good = true;
					break;
				}
			}
			if (good) {
				continue;
			}
		}
		mul1 = 1;
		mul2 = 1;
		for (int j = 1; j <= p; ++j) {
			mul1 = (mul1 * q[i].x) % sInf;
			mul2 = (mul2 * (q[i].x - 1)) % sInf;
		}
		dlt = (mul1 - mul2 + sInf * sInf) % sInf;
		ans = (ans * dlt) % sInf;
	}
	cout << ans << "\n";
//	for (int i = 1; i <= n; ++i) {
//		if (!used[i]) {
//			ans = (ans * q[a[i]].x) % sInf;
//		}
//	}
//	cout << ans << "\n";

	return 0;
}