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
const int Root = 1;

struct edge {
	int to;
	long long wg;
	edge(int param1 = 0, long long param2 = 0) {
		to = param1;
		wg = param2;
	}
};

vector< vector<edge> > g;
vector<long long> dp;
vector<bool> used;

void dfs(int u) {
	int v;
	used[u] = true;
	dp[u] = -bInf;
	for (edge e: g[u]) {
		v = e.to;
		if (!used[v]) {
			dfs(v);
		}
	}
}

int main() {
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int s, n, m, u, v;
	long long w;
	bool cont;

	cin >> n >> m >> s;
	g.resize(n + 1);
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v >> w;
		g[u].push_back(edge(v, w));
	}
	dp.assign(n + 1, bInf);
	dp[s] = 0;
	for (int k = 1; k <= n - 1; ++k) {
		for (int u = 1; u <= n; ++u) {
			if (dp[u] == bInf) {
				continue;
			}
			for (edge e: g[u]) {
				v = e.to;
				w = e.wg;
				if (dp[v] > dp[u] + w) {
					dp[v] = dp[u] + w;
				}
			}
		}
	}
	used.assign(n + 1, false);
	for (int u = 1; u <= n; ++u) {
		if (dp[u] == bInf) {
			continue;
		}
		for (edge e: g[u]) {
			v = e.to;
			w = e.wg;
			if (dp[v] > dp[u] + w) {
				dfs(v);
			}
		}
	}
	for (int u = 1; u <= n; ++u) {
		if (dp[u] == -bInf) {
			cout << "-\n";
		} else if (dp[u] == bInf) {
			cout << "*\n";
		} else {
			cout << dp[u] << "\n";
		}
	}

	return 0;
}
