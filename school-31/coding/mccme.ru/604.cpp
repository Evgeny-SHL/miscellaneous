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
vector<int> parent, rate;

bool comp(edge a, edge b) {
	return a.w < b.w;
}

void make_set(int x) {
	parent[x] = x;
	rate[x] = 0;
}

void init(int N) {
	parent.resize(N);
	rate.resize(N);
	for (int s = 0; s < N; ++s) {
		make_set(s);
	}
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
	if (rate[X] < rate[Y]) {
		parent[X] = Y;
	} else {
		parent[Y] = X;
		if (rate[X] == rate[Y]) {
			++rate[X];
		}
	}
}

int MST_Kruskal(int N, int M) {
	int MST_w = 0;
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
	int c;

	fin >> N;

	for (int u = 0; u < N; ++u) {
		for (int v = 0; v < N; ++v) {
			fin >> w;
			G.push_back(edge(u, v, w));
			G.push_back(edge(v, u, w));
		}
	}
	M = (int)G.size();

	init(N);
	for (int u = 0; u < N; ++u) {
		for (int v = 0; v < N; ++v) {
			fin >> c;
			if (c == 1) {
				union_sets(u, v);
			}
		}
	}

	fout << MST_Kruskal(N, M) << "\n";

	return 0;
}