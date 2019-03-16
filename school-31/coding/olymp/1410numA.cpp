#include <iostream>
#include <vector>
#include <stdio.h>
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
	if (data[p].left == data[p].right)
	{
	    data[p].val = d;
	    //return;
	}
	else {
 //   cout << "from " << l << " " << r << " " << p << " " << v << " " << d << '\n';
 //   char c;
	//	c=getchar();
		if ((v >= data[2 * p].left) && (v <= data[2 * p].right)) {
     //       cout << "in   " << data[2 * p].left << " " << data[2 * p].right << " " << 2 * p << " " << v << " " << d << '\n';
		    update(data[2 * p].left, data[2 * p].right, 2 * p, v, d);
		}
		else {
	//	    cout << "in   " << data[2 * p + 1].left << " " << data[2 * p + 1].right << " " << 2 * p + 1 << " " << v << " " << d << '\n';
		    update(data[2 * p + 1].left, data[2 * p + 1].right, 2 * p + 1, v, d);
		}

		if (data[2 * p].val < data[2 * p + 1].val)
			data[p].v_min = data[2 * p].v_min;// = node(data[2 * p].val, l, r, data[2 * p].v_min);
		else
			data[p].v_min = data[2 * p + 1].v_min;// = node(data[2 * p + 1].val, l, r, data[2 * p + 1].v_min);
	}
}

void dijkstra(int s, int N) {

	data.resize(4 * N + 10);
	dist.resize(N);
	for (int v = 0; v < N; ++v)
		dist[v] = INF;
	dist[s] = 0;

	build(0, N - 1, 1);
	for (int i = 1; i < data.size() / 2; ++i)
        cout << data[i].val << " " << data[i].left << " " << data[i].right << " " << data[i].v_min << '\n';

	for (int i = 0; i < N; ++i) {

		int v_min = data[1].v_min;
		int w_min = data[1].val;
		if (w_min == INF) break;

		for (int j = 0; j < G[v_min].size(); ++j) {
			if (dist[G[v_min][j].u] > dist[v_min] + G[v_min][j].w) {
				dist[G[v_min][j].u] = dist[v_min] + G[v_min][j].w;
		//		cout << "update" << '\n';
				update(0, N - 1, 1, G[v_min][j].u, dist[G[v_min][j].u]);
			}
		}
	//	cout << "coloring" << '\n';
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
