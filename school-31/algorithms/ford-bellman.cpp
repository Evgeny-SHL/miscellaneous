#include <iostream>
#include <vector>
using namespace std;

struct edge {
	int u, w;
	edge(int a = 0, int b = 0) {
		u = a;
		w = b;
	}
};

vector<vector<edge> > g;
vector<int> dist;
vector<int> pi;
const int INF = 1e9 + 7;
const int NIL = -1;

void init(int s, int n) {
	dist.resize(n, INF);
	pi.resize(n, NIL);
	dist[s] = 0;
}

void relax(int v, int u, int w) {
	if (dist[v] != INF && dist[u] > dist[v] + w) {
		dist[u] = dist[v] + w;
		pi[u] = v;
	}
}

bool ford_bellman(int s, int n) {
	init(s, n);
	for (int i = 0; i < n - 1; ++i)
		for (int v = 0; v < n; ++v)
			for (int j = 0; j < g[v].size(); ++j)
				relax(v, g[v][j].u, g[v][j].w);
	for (int v = 0; v < n; ++v)
		for (int j = 0; j < g[v].size(); ++j) {
			int u = g[v][j].u;
			int w = g[v][j].w;
			if (dist[u] > dist[v] + w)
				return false;
		}
	return true;
}

int main() {
	int n, m, v, u, w, s;
	bool neg_cycle;

	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		cin >> v >> u >> w;
		g[v - 1].push_back(edge(u - 1, w));
	}
	cin >> s;

	neg_cycle = ford_bellman(s - 1, n);

	cout << neg_cycle << '\n';
	for (int v = 0; v < n; ++v)
		if (dist[v] != INF)
			cout << dist[v] << " ";
		else cout << "INF ";
	cout << '\n';
	for (int v = 0; v < n; ++v)
		if (pi[v] != NIL)
			cout << pi[v] + 1 << " ";
		else cout << "NIL ";
	cout << '\n';

	return 0;
}