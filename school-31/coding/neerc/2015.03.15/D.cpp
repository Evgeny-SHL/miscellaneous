#pragma comment(linker, "/STACK:268435456")
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;

const double Eps = (double)(1.0e-9);
const long long bInf = (long long)(1e18 + 3);
const int sInf = (int)(1e9 + 7);
const int None = -1;
const double Pi = acos(-1.0);
const double Eu = exp(1.0);
const int Max = 10;

struct edge {
	int to, wgt, vsd;
	edge (int p1 = 0, int p2 = 0) {
		to = p1;
		wgt = p2;
		vsd = false;
	}
};

vector< vector<edge> > g;
vector<int> len, deg;
vector<bool> avl, used;
deque<int> pth;
bitset<Max> b;

void filling(int s) {
	used[s] = true;
	for (int j = 1; j <= len[s]; ++j) {
		int u = g[s][j].to;
		if (avl[u] && !used[u]) {
			filling(u);
		}
	}
}

bool check(int n) {
	int bads;
	deg.resize(n + 1);
	used.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		deg[i] = 0;
		used[i] = false;
	}
	for (int v = 1; v <= n; ++v) {
		if (avl[v]) {
			for (int j = 1; j <= len[v]; ++j) {
				int u = g[v][j].to;
				if (avl[u]) {
					++deg[v];
				}
			}
		}
	}
	bads = 0;
	for (int i = 1; i <= n; ++i) {
		if (deg[i] % 2 == 1) {
			return false;
		}
	}
	for (int v = 1; v <= n; ++v) {
		if (deg[v] > 0) {
			filling(v);
			break;
		}
	}
	for (int v = 1; v <= n; ++v) {
		if (avl[v] && !used[v] && deg[v] > 0) {
			return false;
		}
	}
	return true;
}

//vector<int> euler(int s, int n) {
void euler(int s) {
	int wmn, wmx, v, u;
	wmn = sInf;
	wmx = 0;
	pth.clear();
	pth.push_back(s);
	while (!pth.empty()) {
		v = pth.back();
		cerr << "\n";
		cerr << v << ": ";
		for (int j = 1; j <= len[v]; ++j) {
			u = g[v][j].to;
			if (avl[u]) {
				cerr << u << " ";
				if (!g[v][j].vsd) {
					pth.push_back(u);
					g[v][j].vsd = true;
				} else {
					pth.pop_back();
					cout << u << " ";
					break;
				}
			}
		}
	}
}

int main() {
	freopen("cycle.in", "r", stdin);
	freopen("cycle.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, m, v, u, w, s, ans;
	cin >> n >> m;
	g.resize(n + 1);
	len.resize(n + 1);
	avl.resize(n + 1);
	for (int i = 0; i <= n; ++i) {
		len[i] = 0;
		g[i].push_back(edge());
	}
	for (int i = 1; i <= m; ++i) {
		cin >> v >> u >> w;
		g[v].push_back(edge(u, w));
		g[u].push_back(edge(v, w));
		++len[v];
		++len[u];
	}
	ans = 0;
	for (int mask = 0; mask < (1 << n); ++mask) {
		mask = 7;																			/************************/
		for (int v = 1; v <= n; ++v) {
			for (int j = 1; j <= len[v]; ++j) {
				g[v][j].vsd = false;
			}
		}
		b = bitset<Max>(mask);
		if (b.count() < 3) {
			continue;
		}
		s = 0;
		for (int i = 1; i <= n; ++i) {
			avl[i] = (bool)b[i - 1];
			if (avl[i]) {
				s = i;
			}
		}
		if (!check(n)) {
			continue;
		}
	//	cycle = euler(s);
		euler(s);
		cout << "\n";
	//	cout << u << "\n";
	}
	cout << ans << "\n";

	return 0;
}