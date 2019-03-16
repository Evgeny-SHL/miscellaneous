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

vector<int> z;

int main() {
	freopen("search2.in", "r", stdin);
	freopen("search2.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	string p, t, s;
	int n, m, k, l, r;

	cin >> p >> t;
	m = (int)p.length();
	s = p + "#" + t;
	n = (int)s.length();
	z.assign(n, 0);
	k = 0;
	l = 0;
	r = 0;
	z[0] = n;
	for (int i = 1; i < n; ++i) {
		if (i <= r) {
			z[i] = min(z[i - l], r - i + 1);
		}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			++z[i];
		}
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
		if (z[i] == m) {
			++k;
		}
	}
	cout << k << "\n";
	for (int i = m + 1; i < n; ++i) {
		if (z[i] == m) {
			cout << i - m << " ";
		}
	}
	cout << "\n";

	return 0;
}
