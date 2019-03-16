#include <iostream>
#include <vector>
using namespace std;

struct edge {
	int f;
	edge(int a = 0) {
		f = a;
	}
};

const int WHITE = 0;
const int BLACK = 1;
const int GRAY = 2;
vector<vector<edge> > g;
vector<vector<edge> > g_t;
vector<int> order;
vector<int> scc;
vector<int> color;
int time;

void dfs_visit(int v) {
	color[v] = GRAY;
	for (int i = 0; i < g[v].size(); ++i) {
		int u = g[v][i].f;
		if (color[u] == WHITE)
			dfs_visit(u);
	}
	color[v] = BLACK;
	order.push_back(v);
}

void dfs() {
	color.resize(g.size(), WHITE);
	for (int v = 0; v < g.size(); ++v)
		if (color[v] == WHITE)
			dfs_visit(v);
}

void dfs_visit_t(int v) {
	color[v] = GRAY;
	scc.push_back(v);
	for (int i = 0; i < g_t[v].size(); ++i) {
		int u = g_t[v][i].f;
		if (color[u] == WHITE)
			dfs_visit_t(u);
	}
	color[v] = BLACK;
}

void dfs_t() {
	color.clear();
	color.resize(g.size(), WHITE);
	for (int i = 0; i < g.size(); ++i) {
		int v = order[g.size() - 1 - i];
		if (color[v] == WHITE) {
			dfs_visit_t(v);
			for (int u = 0; u < scc.size(); ++u)
				cout << scc[u] << " ";
			cout << '\n';
			scc.clear();
		}
	}
}

int main() {
	int n, m, v, u;

	cin >> n;
	g.resize(n);
	g_t.resize(n);
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> v >> u;
		g[v - 1].push_back(edge(u - 1));
		g_t[u - 1].push_back(edge(v - 1));
	}

	dfs();
	dfs_t();

	return 0;
}