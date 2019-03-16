#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cmath>
using namespace std;

#define fright pair<char, vector<int> >

const fright None = make_pair('*', vector<int>(0));
vector< vector<int> > a, r, c;
vector<fright> ans;
int len;

void upd_row(int n, int m, int k) {
	while (true) {
		bool row = true;
		for (int i = 1; row && (i <= n); ++i) {
			for (int p = 1; row && (p <= k); ++p) {
				if (r[i][p] >= 2 && r[i][p] < m) {
					row = false;
					ans.push_back(None);
					ans[len].first = 'H';
					int cnt = 0;
					for (int j = 1; j <= m; ++j) {
						if (a[i][j] == p) {
							ans[len].second.push_back(i);
							ans[len].second.push_back(j);
							cnt += 1;
						}
						if (cnt == 2) {
							break;
						}
					}
					len += 1;
					for (int j = 1; j <= m; ++j) {
						c[j][a[i][j]] -= 1;
						c[j][p] += 1;
						a[i][j] = p;
					}
					for (int q = 1; q <= k; ++q) {
						r[i][q] = 0;
					}
					r[i][p] = m;
				}
			}
		}
		if (row) {
			break;
		}
	}
}

void upd_col(int n, int m, int k) {
	while (true) {
		bool col = true;
		for (int j = 1; col && (j <= m); ++j) {
			for (int p = 1; col && (p <= k); ++p) {
				if (c[j][p] >= 2 && c[j][p] < n) {
					col = false;
					ans.push_back(None);
					ans[len].first = 'V';
					int cnt = 0;
					for (int i = 1; i <= n; ++i) {
						if (a[i][j] == p) {
							ans[len].second.push_back(i);
							ans[len].second.push_back(j);
							cnt += 1;
						}
						if (cnt == 2) {
							break;
						}
					}
					len += 1;
					for (int i = 1; i <= n; ++i) {
						r[i][a[i][j]] -= 1;
						r[i][p] += 1;
						a[i][j] = p;
					}
					for (int q = 1; q <= k; ++q) {
						c[j][q] = 0;
					}
					c[j][p] = n;
					}
			}
		}
		if (col) {
			break;
		}
	}
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "r", stdout);
#endif
	int n, m, k;
	string s;
	cin >> n >> m;
	k = min(n, m) - 1;
	r.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		r[i].assign(k + 1, 0);
	}
	c.resize(m + 1);
	for (int j = 1; j <= m; ++j) {
		c[j].assign(k + 1, 0);
	}
	a.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		a[i].resize(m + 1);
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
			r[i][a[i][j]] += 1;
			c[j][a[i][j]] += 1;
		}
	}
//	cout < "OK\n";
	ans.push_back(None);
	len = 1;
	upd_row(n, m, k);
	upd_col(n, m, k);
	bool again = false;
	for (int i = 1; i <= n; ++i) {
		for (int q = 1; q <= k; ++q) {
			if (r[i][q] != m) {
				again = true;
			}
		}
	}
	if (again) {
		upd_row(n, m, k);
		upd_col(n, m, k);
	}
	cout << len - 1 << "\n";
	for (int i = 1; i < len; ++i) {
		cout << ans[i].first << " ";
		for (int j = 0; j < 4; ++j) {
			cout << ans[i].second[j] << " ";
		}
		cout << "\n";
	}
	return 0;
}