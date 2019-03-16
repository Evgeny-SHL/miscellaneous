#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct edge {
	int f;
	bool del;
	edge(int param1, int param2 = false) {
		f = param1;
		del = param2;
	}
};

vector< vector<edge> > G;
vector<bool> used;

const int NIL = -1;

void DFS_visit(int u, int p) {
	used[u] = true;
	for (int i = 0; i < (int)G[u].size(); ++i) {
		int v = G[u][i].f;
		if (!used[v]) {
			DFS_visit(v, u);
		} else if (v != p) {
			G[u][i].del = true;
		}
	}
}

void DFS(int N) {
	used.assign(N, false);
	for (int u = 0; u < N; ++u) {
		if (!used[u]) {
			DFS_visit(u, NIL);
		}
	}
}

int main() {
	int N, M;
	int u, v;

	fin >> N >> M;

	G.resize(N);
	for (int i = 0; i < M; ++i) {
		fin >> u >> v;
		--u;
		--v;
		G[u].push_back(edge(v));
		G[v].push_back(edge(u));
	}

	DFS(N);

	for (int u = 0; u < N; ++u) {
		for (int i = 0; i < (int)G[u].size(); ++i) {
			if (!G[u][i].del) {
				int v = G[u][i].f;
				if (u <= v) {
					fout << u + 1 << " " << v + 1 << "\n";
				}
			}
		}
	}

	return 0;
}