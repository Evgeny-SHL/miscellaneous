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

	int k, n, l, r, m;
	string s;

	cin >> k;
	cin >> s;
	n = (int)s.length();

	/*cin >> s;
	n = (int)s.length();
	p.resize(n);
	p[0] = 0;
	for (int i = 1; i < n; ++i) {
		int j = p[i - 1];
		while (j > 0 && s[j] != s[i]) {
			j = p[j];
		}
		if (s[j] == s[i]) {
			++j;
		}
		p[i] = j;
	}
	for (int i = 0; i < n; ++i) {
		cout << p[i] << " ";
	}
	cout << "\n";*/

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
	//	for (int i = t; i < n; ++i) {
	//		cerr << s[i];
	//	}
	//	cerr << "\n";
	//	string mem = "";
	//	for (int i = t; i < t + k; ++i) {
	//		mem += s[i];
	//	}
	//	cerr << mem << "\n";
		int per = k;
		for (int i = 1; i < k; ++i) {
	//		cerr << min(z[i], k - i) << "\n";
			if (min(z[i], k - i) + i == k && (k % i == 0)) {
				per = i;
				break;
			}
		}
	//	cerr << "per = " << per << "\n";
	//	for (int i = 0; i < m; ++i) {
	//		cerr << z[i] << " ";
	//	}
	//	cerr << "\n";
		int p = 0;
	//	cerr << "!!! " << t << "\n";
	//	cerr << p << " " << p + k + 1 << "\n";
	//	cerr << z[p] << " >= " << k << " " << z[p + k] << "\n";
		while (p + per < m && z[p] >= k && z[p + per] > 0) {
		//	cerr << ". . . up!\n";
			++ans;
			p += per;
		}
	//	cerr << p << "\n";
		if (p == m - 1 && p > 0 && z[p] > 0) {
			++ans;
		//	cerr << ". . . up!\n";
		}
	//	cerr << "\n\n";
	}
	cout << ans << "\n";

	return 0;
}
