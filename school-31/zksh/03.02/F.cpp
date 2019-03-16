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
#include <cassert>
using namespace std;

vector<int> pi[3];
vector< vector<bool> > used;
vector< vector<int> > g;
vector<bool> colored;
vector<int> ans;
deque<int> q;

bool bfs(int u, int v, int n, int k) {
	q.clear();
	bool res = false;
	int w, cur;
	q.push_back(u);
	colored[u] = true;
	while (!q.empty()) {
		int w = q.front();
		q.pop_front();
		if (w == v) {
			res = true;
		}
		for (int to: g[w]) {
			if (!used[w][to] && !used[to][w] && !colored[to]) {
				q.push_back(to);
				colored[to] = true;
				pi[k][to] = w;
				used[w][to] = true;
				used[to][w] = true;
			}
		}
	}
	used.resize(n);
	for (int i = 0; i < n; ++i) {
		used[i].assign(n, false);
	}
	colored.assign(n, false);
	for (int i = 0; i < 3; ++i) {
		cur = v;
		while (pi[i][cur] != -1) {
			used[cur][pi[i][cur]] = true;
			used[pi[i][cur]][cur] = true;
			cur = pi[i][cur];
			colored[cur] = true;
		}
		colored[u] = false;
		colored[v] = false;
	}
	return res;
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	int u, v;
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}
	if (n <= 70) {
		for (int u = 0; u < n - 1; ++u) {
			for (int v = u + 1; v < n; ++v) {
				bool good = true;
				for (int k = 0; k < 3; ++k) {
					pi[k].assign(n, -1);
				}
				used.resize(n);
				colored.assign(n, false);
				for (int i = 0; i < n; ++i) {
					used[i].assign(n, false);
				}
				good = bfs(u, v, n, 0);
				if (!good) {
					continue;
				}
				good = bfs(u, v, n, 1);
				if (!good) {
					continue;
				}
				good = bfs(u, v, n, 2);
				if (!good) {
					continue;
				}
				cout << "YES\n";
				for (int k = 0; k < 3; ++k) {
					int s = v;
					ans.clear();
					ans.push_back(s);
					while (pi[k][s] != -1) {
						s = pi[k][s];
						ans.push_back(s);
					}
					cout << (int)ans.size() << " ";
					for (int i = 0; i < (int)ans.size(); ++i) {
						cout << ans[i] + 1 << " ";
					}
					cout << "\n";
				}
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}