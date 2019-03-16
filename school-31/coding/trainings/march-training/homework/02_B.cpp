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
	int to, wgh;
	edge(int param1 = 0, int param2 = 0) {
		to = param1;
		wgh = param2;
	}
};

set<int> path;
vector< vector<edge> > g;
vector<int> dp;
vector<int> pr;
vector<int> road;
vector<int> cycle;
vector<bool> used;

int main() {
	freopen("negcycle.in", "r", stdin);
	freopen("negcycle.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, to, last_vr, cur, len, u, v, w;

	cin >> n;
	g.resize(n + 1);
	for (int u = 1; u <= n; ++u) {
		for (int v = 1; v <= n; ++v) {
			cin >> w;
			if (w != 1e9) {
				g[u].push_back(edge(v, w));
			}
		}
	}
	used.assign(n + 1, false);
	for (int s = 1; s <= n; ++s) {
		if (used[s]) {
			continue;
		}
		dp.clear();
		pr.clear();
		dp.assign(n + 1, sInf);
		pr.assign(n + 1, None);
		dp[s] = 0;
		used[s] = true;
		for (int k = 1; k <= n; ++k) {
			last_vr = None;
			for (int u = 1; u <= n; ++u) {
				if (dp[u] != sInf) {
					for (edge e: g[u]) {
						v = e.to;
						w = e.wgh;
						if (dp[v] > dp[u] + w) {
							dp[v] = dp[u] + w;
							used[v] = true;
							last_vr = v;
							pr[v] = u;
						}
					}
				}
			}
		}
		if (last_vr != None) {
			cout << "YES\n";
			cur = last_vr;
			do {
				road.push_back(cur);
				path.insert(cur);
				cur = pr[cur];
			} while (path.find(cur) == path.end());
			cycle.push_back(cur);
			for (int i = (int)(road.size()) - 1; i >= 0; --i) {
				cycle.push_back(road[i]);
				if (road[i] == cur) {
					break;
				}
			}
			len = cycle.size();
			cout << len << "\n";
			for (int i = 0; i < len; ++i) {
				cout << cycle[i] << " ";
			}
			cout << "\n";
			return 0;
		}
	}
	cout << "NO\n";

	return 0;
}
