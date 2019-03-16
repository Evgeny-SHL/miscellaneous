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
vector<int> top_s;
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
	top_s.push_back(v);
}

void dfs() {
	for (int v = 0; v < g.size(); ++v)
		if (color[v] == WHITE)
			dfs_visit(v);
}

int main() {
	int n, m, v, u;

	cin >> n;
	g.resize(n);
	color.resize(n, WHITE);
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> v >> u;
		g[v - 1].push_back(edge(u - 1));
	}

	dfs();

	for (int i = top_s.size() - 1; i >= 0; --i)
		cout << top_s[i] + 1 << " ";
	cout << '\n';

	return 0;
}