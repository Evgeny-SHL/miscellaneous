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

vector<long long> h, deg;

int main() {
	freopen("substr.in", "r", stdin);
	freopen("substr.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	string s;
	int n, m, a, b;
	long long t, r, sh;

	cin >> t >> r;
	cin >> s;
	n = (int)s.length();
	h.assign(n, 0);
	deg.assign(n, 0);
	h[0] = s[0] % r;
	deg[0] = 1;
	for (int i = 1; i < n; ++i) {
		h[i] = (s[i] + (h[i - 1] * t) % r) % r;
		deg[i] = (t * deg[i - 1]) % r;
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		if (a != 0) {
			sh = (r + h[b] - (h[a - 1] * deg[b - a + 1]) % r) % r;
		} else {
			sh = h[b];
		}
		cout << sh << "\n";
	}

	return 0;
}
