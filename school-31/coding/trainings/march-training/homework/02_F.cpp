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
vector<long long> dist;
multiset< pair<long long, int> > q;

void dijkstra(int s, int n) {
    int u, to;
    long long wg;
    dist.assign(n + 1, bInf);
    dist[s] = 0;
    q.clear();
    q.insert(make_pair(dist[s], s));
    while (!q.empty()) {
        u = q.begin()->second;
        q.erase (q.begin());
        for (edge e: g[u]) {
            to = e.to;
            wg = e.wg;
            if (dist[u] + wg < dist[to]) {
                q.erase(make_pair(dist[to], to));
                dist[to] = dist[u] + wg;
                q.insert(make_pair(dist[to], to));
            }
        }
    }
    return;
}

int main() {
    freopen("pathbgep.in", "r", stdin);
    freopen("pathbgep.out", "w", stdout);
    srand(time(0));
    cout << fixed;
    cout.precision(9);
    ios_base::sync_with_stdio(0);

    int n, m, u, v;
    long long w;

    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v >> w;
        g[u].push_back(edge(v, w));
        g[v].push_back(edge(u, w));
    }
    dijkstra(Root, n);
    for (int u = 1; u <= n; ++u) {
        cout << dist[u] << " ";
    }
    cout << "\n";

    return 0;
}