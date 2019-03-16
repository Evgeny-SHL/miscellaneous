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

struct node {
	int val;
	int left, right;
	int v_min;
	node(int a = 0, int b = 0, int c = 0, int d = 0) {
		val = a;
		left = b;
		right = c;
		v_min = d;
	}
};

vector<vector<edge> > g;
vector<int> dist;
vector<int> pi;
vector<node> data;
const int INF = 1e9 + 7;
const int NIL = -1;

void build(int l, int r, int p) {
	if (l == r)
		data[p] = node(dist[l], l, r, l);
	else {
		build(l, (l + r) / 2, 2 * p);
		build((l + r)/ 2 + 1, r, 2 * p + 1);

		if (data[2 * p].val < data[2 * p + 1].val)
			data[p] = node(data[2 * p].val, l, r, data[2 * p].v_min);
		else
			data[p] = node(data[2 * p + 1].val, l, r, data[2 * p + 1].v_min);
	}
}

void update(int l, int r, int p, int v, int d) {
	if (l == r)
		data[p].val = d;
	else {
		if (v <= (l + r)/ 2) update(l, data[2 * p].right, 2 * p, v, d);
		else update(data[2 * p + 1].left, r, 2 * p + 1, v, d);

		if (data[2 * p].val < data[2 * p + 1].val)
			data[p] = node(data[2 * p].val, l, r, data[2 * p].v_min);
		else
			data[p] = node(data[2 * p + 1].val, l, r, data[2 * p + 1].v_min);
	}
}

void init(int s, int n) {
	data.resize(4 * n + 1);
	dist.resize(n, INF);
	pi.resize(n, NIL);
	dist[s] = 0;
}

void relax(int v, int u, int w, int n) {
	if (dist[v] != INF && dist[u] > dist[v] + w) {
		dist[u] = dist[v] + w;
		pi[u] = v;
		update(0, n - 1, 1, u, dist[u]);
	}
}

void dijkstra(int s, int n) {
	init(s, n);
	build(0, n - 1, 1);
	for (int i = 0; i < n; ++i) {
		int v_min = data[1].v_min;
		int w_min = data[1].val;
		if (w_min == INF) break;
		for (int j = 0; j < g[v_min].size(); ++j) {
			relax(v_min, g[v_min][j].u, g[v_min][j].w, n);
		}
		update(0, n - 1, 1, v_min, INF);
	}
}

int main() {
	int n, m, v, u, w, s;

	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		cin >> v >> u >> w;
		g[v - 1].push_back(edge(u - 1, w));
	}
	cin >> s;

	dijkstra(s - 1, n);

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