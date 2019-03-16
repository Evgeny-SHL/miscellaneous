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
const int White = 0;
const int Gray = 1;
const int Black = 2;
vector< vector<int> > g, gt;
vector<bool> used;
vector<int> sorted;
vector<int> scc;

void top_sort(int u) {
	used[u] = true;
	for (int v: g[u]) {
		if (!used[v]) {
			top_sort(v);
		}
	}
	sorted.push_back(u);
}

void find_scc(int k, int u) {
	scc[u] = k;
	used[u] = true;
	for (int v: gt[u]) {
		if (!used[v]) {
			find_scc(k, v);
		}
	}
}

int main() {
	freopen("cond.in", "r", stdin);
	freopen("cond.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, m, u, v;

	cin >> n >> m;
	g.resize(n + 1);
	gt.resize(n + 1);
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		gt[v].push_back(u);
	}
	used.assign(n + 1, false);
	for (int u = 1; u <= n; ++u) {
		if (!used[u]) {
			top_sort(u);
		}
	}
	used.assign(n + 1, false);
	scc.assign(n + 1, None);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		int u = sorted[n - i];
		if (!used[u]) {
			++cnt;
			find_scc(cnt, u);
		}
	}
	cout << cnt << "\n";
	for (int u = 1; u <= n; ++u) {
		cout << scc[u] << " ";
	}
	cout << "\n";

	return 0;
}
