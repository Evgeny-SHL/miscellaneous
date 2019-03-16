#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;

const double Eps = 1e-9;
const long long bInf = (long long)(1e18 + 3);
const long long sInf = (long long)(1e9 + 7);
const double Pi = acos(-1.0);
const double eu = exp(1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

vector<int> p, z;

int main() {
	freopen("robot.in", "r", stdin);
	freopen("robot.out", "w", stdout);
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int k, n, l, r, m, p;
	string s;

	cin >> k;
	cin >> s;
	n = (int)s.length();
	int ans = 0;
	for (int t = 0; t < n - k; ++t) {
		z.clear();
		int m = n - t;
		z.resize(m);
		z[0] = m;
		l = 0;
		r = 0;
		for (int i = 1; i < m; ++i) {
			if (i <= r) {
				z[i] = min(r - i + 1, z[i - l]);
			}
			while (i + z[i] < m && s[z[i] + t] == s[i + z[i] + t]) {
				++z[i];
			}
			if (i + z[i] - 1 > r) {
				l = i;
				r = i + z[i] - 1;
			}
		}
		p = k;
		if (z[p] > 0) {
			l = p;
			r = p;
			while (p < m && z[p] >= k) {
				r = p + z[p] - 1;
				p += k;
			}
			ans += r - l + 1;
		//	cout << t << " " << t + l << " " << t + r << "\n";
		}
	}
	cout << ans << "\n";

	return 0;
}
