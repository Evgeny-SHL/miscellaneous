#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct edge {
	int u, v, w;
	edge(int param1, int param2, int param3) {
		u = param1;
		v = param2;
		w = param3;
	}
};

vector<edge> G;
vector<int> parent, range;

bool comp(edge a, edge b) {
	return (a.w < b.w);
}

void init(int N) {
	parent.resize(N);
	range.resize(N);
}

void make_set(int x) {
	parent[x] = x;
	range[x] = 0;
}

int find_set(int x) {
	if (parent[x] != x) {
		parent[x] = find_set(parent[x]);
	}
	return parent[x];
}

void union_sets(int x, int y) {
	int X = find_set(x);
	int Y = find_set(y);
	if (range[X] < range[Y]) {
		parent[X] = Y;
	} else {
		parent[Y] = X;
		if (range[X] == range[Y]) {
			++range[X];
		}
	}
}

int MST_Kruskal(int N, int M) {
	init(N);
	int MST_w = 0;
	for (int i = 0; i < N; ++i) {
		make_set(i);
	}
	sort(G.begin(), G.end(), comp);
	for (int i = 0; i < M; ++i) {
		int u = G[i].u;
		int v = G[i].v;
		if (find_set(u) != find_set(v)) {
			MST_w += G[i].w;
			union_sets(u, v);
		}
	}
	return MST_w;
}

int main() {
	int N, M;
	int u, v, w;

	fin >> N >> M;

    for (int i = 0; i < M; ++i) {
		fin >> u >> v >> w;
		--u;
		--v;
		G.push_back(edge(u, v, w));
		G.push_back(edge(v, u, w));
    }
    M *= 2;

    fout << MST_Kruskal(N, M);

	return 0;
}