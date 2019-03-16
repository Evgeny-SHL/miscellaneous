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
	unsigned long long val;
	int left, right;
	int v_min;
	node(unsigned long long a = 0, int b = 0, int c = 0, int d = 0) {
		val = a;
		left = b;
		right = c;
		v_min = d;
	}
};

vector<vector<edge> > G;
vector<unsigned long long> dist;
vector<node> data;
const unsigned long long INF = 2009000999LL;

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

void dijkstra(int s, int N) {

	data.clear();
	dist.clear();
	data.resize(4 * N + 10);
	dist.resize(N);
	for (int v = 0; v < N; ++v)
		dist[v] = INF;
	dist[s] = 0;
	build(0, N - 1, 1);

	for (int i = 0; i < N; ++i) {

		int v_min = data[1].v_min;
		int w_min = data[1].val;
		if (w_min == INF) break;

		for (int j = 0; j < G[v_min].size(); ++j) {
			if (dist[G[v_min][j].u] > dist[v_min] + G[v_min][j].w) {
				dist[G[v_min][j].u] = dist[v_min] + G[v_min][j].w;
				update(0, N - 1, 1, G[v_min][j].u, dist[G[v_min][j].u]);
			}
		}
		update(0, N - 1, 1, v_min, INF);
	}

	for (int v = 0; v < N; ++v)
		cout << dist[v] << " ";
	cout << '\n';
}

int main() {
	int K;
	int N, M;
	int v, u, w;
	int s;

	cin >> K;
	for (int k = 0; k < K; ++k) {

		cin >> N >> M;
		G.clear();
		G.resize(N);
		for (int i = 0; i < M; ++i) {
			cin >> v >> u >> w;
			G[v].push_back(edge(u, w));
			G[u].push_back(edge(v, w));
		}
		cin >> s;

		dijkstra(s, N);
	}

	return 0;
}
