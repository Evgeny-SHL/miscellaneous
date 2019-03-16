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

vector<long long> h[3], deg[3];
long long t[3] = { 0, 19, 23 };
long long p[3] = { 0, 1000000007, 1000000009 };

long long hsub(int k, int l, int r) {
	return (p[k] + h[k][r] - (h[k][l - 1] * deg[k][r - l + 1]) % p[k]) % p[k];
}

bool cp(int a, int b, int l) {
	bool res = true;
	for (int k = 1; k <= 2; ++k) {
		if (hsub(k, a, a + l - 1) != hsub(k, b, b + l - 1)) {
			res = false;
			break;
		}
	}
	return res;
}

int main() {
	freopen("lcp.in", "r", stdin);
	freopen("lcp.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	string s;
	int n, m, a, b;

	cin >> s;
	n = (int)s.length();
	s = "*" + s;
	for (int k = 1; k <= 2; ++k) {
		h[k].resize(n + 1);
		deg[k].resize(n + 1);
		h[k][0] = 0;
		deg[k][0] = 1;
		for (int i = 1; i <= n; ++i) {
			h[k][i] = (s[i] + (h[k][i - 1] * t[k]) % p[k]) % p[k];
			deg[k][i] = (t[k] * deg[k][i - 1]) % p[k];
		}
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b;
		int lmin = 0;
		int lmax = n - max(a, b) + 1;
		++a;
		++b;
		while (lmin < lmax - 1) {
			int lmid = (lmin + lmax) / 2;
			if (cp(a, b, lmid)) {
				lmin = lmid;
			} else {
				lmax = lmid;
			}
		}
		cout << lmin << "\n";
	}

	return 0;
}
