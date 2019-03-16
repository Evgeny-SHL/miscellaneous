#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct edge {
	int u;
	long long w;
	edge(int p1 = 0, long long p2 = 0) {
		u = p1;
		w = p2;
	}
};

struct vertex {
	int v;
	long long d;
	vertex(int p1 = 0, long long p2 = 0) {
		v = p1;
		d = p2;
	}
};

const long long INF = 2009000999;
vector< vector<edge> > g;
vector<long long> dist;

bool operator<(vertex a, vertex b) {
	return (a.v != b.v && a.d < b.d);
}

set<vertex> vrt;
set<vertex>::iterator it;

void dijkstra(int s, int n, int m) {
	dist.assign(n, INF);
	dist[s] = 0;
	/*vrt.insert(vertex(s, dist[s]));
	while (!vrt.empty()) {
		it = vrt.begin();
		int v = (*it).v;
		vrt.erase(it);
		for (int i = 0; i < g[v].size(); ++i) {
			int u = g[v][i].u;
			long long w = g[v][i].w;
			if (dist[u] > dist[v] + w) {
				vrt.erase(vertex(u, dist[u]));
				dist[u] = dist[v] + w;
				vrt.insert(vertex(u, dist[u]));
			}
		}
	}*/
	set < pair<int, long long> > q;
	q.insert (make_pair(dist[s], s));
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase (q.begin());
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].u,
				len = g[v][j].w;
			if (dist[v] + len < dist[to]) {
				q.erase (make_pair (dist[to], to));
				dist[to] = dist[v] + len;
				q.insert (make_pair (dist[to], to));
			}
		}
	}
	return;
}

int main() {
	int NUM;
	int N, M;
	int u, v, s;
	long long w;

	fin >> NUM;

	for (int t = 0; t < NUM; ++t) {
		fin >> N >> M;
		g.resize(N);
		for (int i = 0; i < M; ++i) {
			fin >> u >> v >> w;
			g[u].push_back(edge(v, w));
			g[v].push_back(edge(u, w));
		}
		fin >> s;
		dijkstra(s, N, M);
		for (int i = 0; i < N; ++i) {
			fout << dist[i] << " \n"[i == N - 1];
		}
		g.clear();
		dist.clear();
		vrt.clear();
	}

	return 0;
}