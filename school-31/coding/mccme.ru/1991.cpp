#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector< vector<int> > G, Gt;
vector<bool> used;
vector<int> scc, sorted;

void G_dfs_visit(int s) {
	used[s] = true;
	for (int i = 0; i < (int)G[s].size(); ++i) {
		int v = G[s][i];
		if (!used[v]) {
			G_dfs_visit(v);
		}
	}
	sorted.push_back(s);
}

void tSort(int N) {
	used.assign(N, false);
	for (int s = 0; s < N; ++s) {
		if (!used[s]) {
			G_dfs_visit(s);
		}
	}
	used.clear();
}

void Gt_dfs_visit(int s, int k) {
	used[s] = true;
	scc[s] = k;
	for (int i = 0; i < (int)Gt[s].size(); ++i) {
		int v = Gt[s][i];
		if (!used[v]) {
			Gt_dfs_visit(v, k);
		}
	}
}

int Gt_dfs(int N) {
	int k = 0;
	scc.resize(N);
	used.assign(N, false);
	for (int i = 1; i <= N; ++i) {
		int s = sorted[N - i];
		if (!used[s]) {
			++k;
			Gt_dfs_visit(s, k);
		}
	}
	return k;
}

int main() {
	int N, M, K;
	int u, v;

	fin >> N >> M;

	G.resize(N);
	Gt.resize(N);
	for (int i = 0; i < M; ++i) {
		fin >> u >> v;
		--u;
		--v;
		G[u].push_back(v);
		Gt[v].push_back(u);
	}

	tSort(N);
	K = Gt_dfs(N);

	fout << K << "\n";
	for (int i = 0; i < N; ++i) {
		fout << scc[i] << " \n"[i == N - 1];
	}

	return 0;
}