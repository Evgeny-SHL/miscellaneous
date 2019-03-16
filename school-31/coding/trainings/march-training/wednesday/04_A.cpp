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

const double Eps = 1e-9;
const long long bInf = (long long)(1e18 + 3);
const long long sInf = (long long)(1e9 + 7);
const int None = -1;
const double Pi = acos(-1.0);
const double eu = exp(1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;
const int Wh = 0;
const int Bl = 1;

vector< vector<int> > g;
vector<bool> used;
vector<int> color;
int cnt[2];

void dfs(int v, int clr) {
	used[v] = true;
	color[v] = clr;
	++cnt[clr];
	for (int u: g[v]) {
 		if (!used[u]) {
			dfs(u, 1 - clr);
		}
	}
}

int main() {
	freopen("tournament.in", "r", stdin);
	freopen("tournament.out", "w", stdout);
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, k, v, u;

	cin >> n;
	g.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	cin >> k;
	used.assign(n + 1, false);
	color.assign(n + 1, None);
	cnt[Wh] = cnt[Bl] = 0;
	for (int v = 1; v <= n; ++v) {
		if (!used[v]) {
			dfs(v, Bl);
		}
	}
	if (cnt[Wh] >= k) {
		for (int v = 1; (k > 0) && (v <= n); ++v) {
			if (color[v] == Wh) {
				--k;
				cout << v << " ";
			}
		}
		cout << "\n";
	} else {
		cout << 0 << "\n";
	}

	return 0;
}
