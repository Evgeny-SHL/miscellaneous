#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
using namespace std;

const int Inf = (int)(1e9 + 7);
const pair<int, int> None = make_pair(-1, -1);

struct point {
	int x, y, ind, fuel;
	point(int p1 = 0, int p2 = 0, int p3 = 0, int p4 = 0) {
		x = p1;
		y = p2;
		ind = p3;
		fuel = p4;
	}
};

bool cmpx(point a, point b) {
	return (a.x < b.x);
}

bool cmpy(point a, point b) {
	return (a.y < b.y);
}

bool cmpi(point a, point b) {
	return (a.ind < b.ind);
}

vector<point> p;
vector<int> ans;
vector< vector<int> > mp, dp;
map<pair<int, int>, int > ind;
map<pair<int, int>,  pair<int, int> > anc;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int n, k;
	int prv;

	cin >> n >> k;

	p.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i].x >> p[i].y >> p[i].fuel;
		p[i].ind = i + 1;
	}

	sort(p.begin(), p.end(), cmpx);
	prv = p[0].x;
	p[0].x = 0;
	for (int i = 1; i < n; ++i) {
		if (p[i].x == prv) {
			p[i].x = p[i - 1].x;
		} else {
			prv = p[i].x;
			p[i].x = p[i - 1].x + 1;
		}
	}
	int l = p[n - 1].x + 1;

	sort(p.begin(), p.end(), cmpy);
	prv = p[0].y;
	p[0].y = 0;
	for (int i = 1; i < n; ++i) {
		if (p[i].y == prv) {
			p[i].y = p[i - 1].y;
		} else {
			prv = p[i].y;
			p[i].y = p[i - 1].y + 1;
		}
	}
	int m = p[n - 1].y + 1;

	sort(p.begin(), p.end(), cmpi);

//	for (int i = 0; i < n; ++i) {
//		cout << p[i].x << " " << p[i].y << "\n";
//	}

//	for (int i = 0; i < n; ++i) {
//		cout << p[i].x << " " << p[i].y << "\n";
//	}

	mp.resize(l);
	dp.resize(l);
	for (int i = 0; i < l; ++i) {
		dp[i].assign(m, -Inf);
		mp[i].assign(m, -1);
	}

	for (int i = 0; i < n; ++i) {
		mp[p[i].x][p[i].y] = p[i].fuel;
		ind[make_pair(p[i].x, p[i].y)] = p[i].ind;
	}

//	for (int i = 0; i < l; ++i) {
//		for (int j = 0; j < m; ++j) {
//			cout << mp[i][j] << " \n"[j == m - 1];
//		}
//	}

	int r, c;
	r = p[0].x;
	c = p[0].y;
	dp[r][c] = mp[r][c];
	pair<int, int> root = make_pair(r, c);
	anc[root] = None;
	for (int i = r; i < l; ++i) {
		for (int j = c; j < m; ++j) {
			for (int u = i + 1; u < l; ++u) {
				if (mp[i][j] >= 0 && mp[u][j] >= 0 && dp[i][j] >= k) {
					if (dp[i][j] - k + mp[u][j] > dp[u][j]) {
						dp[u][j] = dp[i][j] - k + mp[u][j];
						anc[make_pair(u, j)] = make_pair(i, j);
					}
				}
			}
			for (int v = j + 1; v < m; ++v) {
				if (mp[i][j] >= 0 && mp[i][v] >= 0 && dp[i][j] >= k) {
					if (dp[i][j] - k + mp[i][v] > dp[i][v]) {
						dp[i][v] = dp[i][j] - k + mp[i][v];
						anc[make_pair(i, v)] = make_pair(i, j);
					}
				}
			}
		}
	}

//	for (int i = 0; i < l; ++i) {
//		for (int j = 0; j < m; ++j) {
//			cout << dp[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	cout << "\n";

//	cout << r << " " << c << "\n";
//	cout << p[n - 1].x << " " << p[n - 1].y << "\n";

//	cout << dp[p[n - 1].x][p[n - 1].y] << "\n";

	pair<int, int> cur = make_pair(p[n - 1].x, p[n - 1].y);

//	cout << dp[p[n - 1].x][p[n - 1].y] << "\n";


	while (anc.find(cur) != anc.end()) {
		ans.push_back(ind[cur]);
		cur = anc[cur];
	}

	if (cur.first >= 0 && ind[cur] == 1) {
		ans.push_back(1);
	}

	if (ans.size() > 0) {
		cout << dp[p[n - 1].x][p[n - 1].y] << "\n";
		cout << ans.size() << "\n";
		for (int i = (int)ans.size() - 1; i >= 0; --i) {
			cout << ans[i] << "\n";
		}
	} else {
		cout << "-1\n";
	}

	return 0;
}