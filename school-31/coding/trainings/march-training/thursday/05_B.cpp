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

const int Max = 2000;

long long dist[Max + 1][Max + 1];
int color[Max + 1];

void floyd_warshall(int n) {
    for (int u = 1; u <= n; ++u) {
		for (int v = 1; v <= n; ++v) {
			for (int k = 1; k <= n; ++k) {
				if (dist[u][k] == bInf || dist[k][v] == bInf) {
					continue;
				}
 				dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
			}
		}
	}
}

void find_best(int n) {
	long long best, s1, s2;
	best = bInf;
	s1 = 0;
	s2 = 0;
	for (int u = 1; u <= n; ++u) {
		for (int v = 1; v <= n; ++v) {
			if (u != v && dist[u][v] < best && color[u] == color[v]) {
				best = dist[u][v];
				s1 = u;
				s2 = v;
			}
		}
	}
	cout << best << " " << s1 << " " << s2 << '\n';
}

int main() {
    freopen("parties.in", "r", stdin);
    freopen("parties.out", "w", stdout);
    cout << fixed;
    cout.precision(9);
    ios_base::sync_with_stdio(0);

    int n, m, k, u, v, w, i;
    string s;

    cin >> n >> m >> k;
    assert(n <= Max);
    for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dist[i][j] = bInf;
		}
    }
    cin >> s;
    for (int i = 0; i < n; ++i) {
		if (s[i] == 'R') {
			color[i + 1] = 1;
		}
    }
    for (int e = 1; e <= m; ++e) {
		cin >> u >> v >> w;
		dist[u][v] = w;
		dist[v][u] = w;
    }
	floyd_warshall(n);
	find_best(n);
	for (int i = 1; i <= k; ++i) {
		cin >> u;
		color[u] = 1 - color[u];
		find_best(n);
	}

    return 0;
}
