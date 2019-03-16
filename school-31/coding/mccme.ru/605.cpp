#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct point {
	int x, y;
	point(int param1, int param2) {
		x = param1;
		y = param2;
	}
};

double len(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

vector<point> pt;

struct edge {
	int u, v;
	double w;
	edge(int param1, int param2) {
		u = param1;
		v = param2;
		w = len(pt[u], pt[v]);
	}
};

const double EPS = 1e-9;

bool comp(edge a, edge b) {
	return (a.w < b.w + EPS);
}

vector<edge> G;
vector<int> parent, rate;

void make_set(int x) {
	parent[x] = x;
	rate[x] = 0;
}

void init(int N) {
	parent.resize(N);
	rate.resize(N);
	for (int u = 0; u < N; ++u) {
		for (int v = 0; v < N; ++v) {
			G.push_back(edge(u, v));
		}
	}
	for (int x = 0; x < N; ++x) {
		make_set(x);
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

double MST_Kruskal(int N, int M) {
	double MST_w = 0.0;
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
	int N, K, M;
	int x, y;
	int u, v;

	fin >> N;

	for (int i = 0; i < N; ++i) {
		fin >> x >> y;
		pt.push_back(point(x, y));
	}

	fin >> K;

	init(N);
	for (int i = 0; i < K; ++i) {
		fin >> u >> v;
		--u;
		--v;
		union_sets(u, v);
	}

	M = (int)G.size();

	fout << fixed;
	fout.precision(5);

	fout << MST_Kruskal(N, M) << "\n";

	return 0;
}