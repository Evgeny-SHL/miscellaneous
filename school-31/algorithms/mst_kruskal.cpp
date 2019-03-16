#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
	int s, f, w;
	edge(int a = 0, int b = 0, int c = 0) {
		s = a;
		f = b;
		w = c;
	}
};

vector<edge> g;
vector<int> parent;
vector<int> rank_set;
const int NIL = -1;

void make_set(int x) {
	parent[x] = x;
	rank_set[x] = 0;
}

int find_set(int x) {
	if (x != parent[x])
		parent[x] = find_set(parent[x]);
	return parent[x];
}

void link(int x, int y) {
	if (rank_set[x] > rank_set[y])
		parent[y] = x;
	else {
		parent[x] = y;
		if (rank_set[x] == rank_set[y])
			++rank_set[y];
	}
}

void union_sets(int x, int y) {
	link(find_set(x), find_set(y));
}

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

int mst_kruskal(int n) {
	int w_mst = 0;
	for (int i = 0; i < n; ++i)
		make_set(i);
	sort(g.begin(), g.end(), cmp);
	for (int j = 0; j < g.size(); ++j) {
		int v = g[j].s;
		int u = g[j].f;
		if (find_set(v) != find_set(u)) {
			w_mst += g[j].w;
			union_sets(v, u);
		}
	}
	return w_mst;
}

int main() {
	int n, m, v, u, w;

	cin >> n >> m;
	parent.resize(n + 1, NIL);
	rank_set.resize(n + 1, NIL);
	for (int j = 0; j < m; ++j) {
		cin >> v >> u >> w;
		g.push_back(edge(v - 1, u - 1, w));
		g.push_back(edge(u - 1, v - 1, w));
	}

	cout << mst_kruskal(n);

	return 0;
}