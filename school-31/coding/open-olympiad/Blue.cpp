#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <cmath>
#include <random>
#include <ctime>
#include <cassert>
using namespace std;

const double Eps = (double)(1e-9);
const long long Inf = (long long)(1e18);
const int None = (int)(1e9 + 7);
const double Pi = acos(-1.0);
const double Eu = exp(1.0);

vector<bool> inside, dp;
vector<int> z;

long long Const[2] = {31, 19};
long long Mod[2] = {(long long)(1e9 + 7), (long long)(1e9 + 9)};
vector< vector<long long> > h, deg;

void compute_z_function(string s) {
	int n = (int)s.length();
	int l = 0;
	int r = 0;
	z.resize(n);
	z[0] = n;
	for (int i = 1; i < n; ++i) {
		if (i <= r) {
			z[i] = min(z[i - l], r - i + 1);
		}
		while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
			++z[i];
		}
		if (i + z[i] - 1 > r) {
			r = i + z[i] - 1;
			l = i;
		}
	}
}

int period(string s) {
	int n = (int)s.length();
	for (int i = 1; i < n; ++i) {
		if (i + z[i] == n && n % i == 0) {
			return i;
		}
	}
	return n;
}

void init(string s) {
	int n = (int)s.length();
	h.resize(2);
	deg.resize(2);
	for (int k = 0; k < 2; ++k) {
		h[k].resize(n);
		deg[k].resize(n);
		h[k][0] = (long long)(s[0] - 'a' + 1);
		deg[k][0] = 1;
		for (int i = 1; i < n; ++i) {
			deg[k][i] = (deg[k][i - 1] * Const[k]) % Mod[k];
			h[k][i] = (h[k][i - 1] + ((s[i] - 'a' + 1) * deg[k][i]) % Mod[k]) % Mod[k];
		}
	}
}

long long hash_substr(int k, int l, int r, int n) {
	if (l == 0) {
		return (h[k][r] * deg[k][n - 1]) % Mod[k];
	}
	return (((Mod[k] + h[k][r] - h[k][l - 1]) % Mod[k]) * deg[k][n - l - 1]) % Mod[k];
}

bool equiv(int l0, int r0, int l, int r, int n) {
	bool eq = true;
	for (int k = 0; k < 2; ++k) {
		eq = eq && (hash_substr(k, l0, r0, n) == hash_substr(k, l, r, n));
	}
	return eq;
}

int main() {
	srand(time(NULL));
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	cout << fixed;
	cout.precision(9);
	int n, l, cnt;
	string s;
	cin >> l;
	cin >> s;
	n = (int)s.length();
	inside.resize(3);
	for (int i = 0; i < n; ++i) {
		inside[s[i] - 'a'] = true;
	}
	cnt = 0;
	for (int i = 0; i < 3; ++i) {
		if (inside[i]) {
			cnt += 1;
		}
	}
	if (l >= n) {
		cout << 1 << "\n";
		cout << s << "\n";
	} else {
		if (cnt == 1) {
			cout << 1 << "\n";
			cout << s[0];
		} else if (cnt == 2) {
			compute_z_function(s);
			int t = period(s);
			if (t <= l) {
				cout << 1 << "\n";
				for (int i = 0; i < t; ++i) {
					cout << s[i];
				}
				cout << "\n";
			} else {
				cout << 2 << "\n";
				for (int i = 0; i < 3; ++i) {
					if (inside[i]) {
						cout << (char)('a' + i) << "\n";
					}
				}
			}
		} else {
			compute_z_function(s);
			int t = period(s);
			if (t <= l) {dp.assign(n, false);
				cout << 1 << "\n";
				for (int i = 0; i < t; ++i) {
					cout << s[i];
				}
				cout << "\n";
			} else {
				init(s);
				int l1, r1, l2, r2;
				for (int len1 = 1; len1 <= l; ++len1) {
					l1 = 0;
					r1 = len1 - 1;
					while (r1 + len1 < n && equiv(l1, r1, l1 + len1, r1 + len1, n)) {
						l1 += len1;
						r1 += len1;
					}
					l2 = r1 + 1;
					for (int len2 = 1; len2 <= l; ++len2) {
						dp.assign(n, false);
						r2 = l2 + len2 - 1;
						for (int i = r1; i >= 0; i -= len1) {
							dp[i] = true;
						}
						dp[r2] = true;
					//	cout << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
						for (int i = r2 + min(len1, len2); i < n; ++i) {
							dp[i] = dp[i - len1] && equiv(l1, r1, i - len1 + 1, i, n);
							dp[i] = dp[i] || dp[i - len2] && equiv(l2, r2, i - len2 + 1, i, n);
						}
					//	for (int i = 0; i < n; ++i) {
					//		cout << dp[i] << " ";
					//	}
					//	cout << "\n";
						if (dp[n - 1]) {
							cout << 2 << "\n";
							for (int i = l1; i <= r1; ++i) {
								cout << s[i];
							}dp.assign(n, false);
							cout << "\n";
							for (int i = l2; i <= r2; ++i) {
								cout << s[i];
							}
							cout << "\n";
							return 0;
						}
					}
				}
				cout << 3 << "\n";
				cout << "a\n";
				cout << "b\n";
				cout << "c\n";
			}
		}
	}
    return 0;
}
