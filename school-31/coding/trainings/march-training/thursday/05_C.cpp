#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;

const double Eps = (double)1e-9;
const long long bInf = (long long)(1e18 + 3);
const long long sInf = (long long)(1e9 + 7);
const int None = -1;
const double Pi = acos(-1.0);
const double eu = exp(1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

vector< vector<int> > t, g;
vector<bool> used, die;
vector<int> deg;
set< pair<int, int> > vrt;

void dfs(int u, int p, int k) {
	used[u] = true;
	if (k >= 0) {
		g[p].push_back(u);
	}
	if (k > 0) {
		for (int v: t[u]) {
			if (!used[v]) {
				dfs(v, p, k - 1);
			}
		}
	}
}

int main() {
    freopen("cockroach.in", "r", stdin);
    freopen("cockroach.out", "w", stdout);
    cout << fixed;
    cout.precision(9);
    ios_base::sync_with_stdio(0);

	int n, k, u, v, best, ans;

	cin >> n >> k;
	t.resize(n + 1);
	for (int i = 1; i <= n - 1; ++i) {
		cin >> u >> v;
		t[v].push_back(u);
		t[u].push_back(v);
	}
	g.resize(n + 1);
	for (int u = 1; u <= n; ++u) {
		used.assign(n + 1, false);
		dfs(u, u, k);
	}
	for (int u = 1; u <= n; ++u) {
	//	cout << u << ": ";
		for (int v: g[u]) {
		//	cout << v << " ";
		}
	//	cout << "\n";
	}
	deg.assign(n + 1, 0);
	die.assign(n + 1, false);
	used.assign(n + 1, false);
	for (int u = 1; u <= n; ++u) {
		deg[u] = (int)g[u].size();
	}
	for (int i = 1; i <= n; ++i) {
//	while (true) {
		best = 0;
		for (int u = 1; u <= n; ++u) {
		//	cerr << deg[u] << " ";
			if (deg[u] > deg[best]) {
				best = u;
			}
		}
	//	cerr << "\n";
		if (deg[best] <= 0) {
			break;
		}
	//	cerr << best << " " << deg[best] << "\n";
		cerr << best << " " << deg[best] << "\n";
		die[best] = true;
		deg[best] = 0;
	//	cerr << best << " " << deg[best] << "\n";
		for (int u: g[best]) {
		//	cerr << u << " " << deg[u] << "\n";
		//	deg[u] = -sInf;
		//	cerr << u << " " << deg[u] << "\n";
			for (int v: g[u]) {
				if (deg[v] > 0) {
					--deg[v];
				}
			}
		}
	//	cerr << "\n";
	}
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (die[i]) {
			++ans;
		}
	}
	cout << ans << "\n";

    return 0;
}
