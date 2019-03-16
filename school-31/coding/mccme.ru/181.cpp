#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector< vector<int> > G;
vector<bool> used;

void DFS_visit(int v) {
	used[v] = true;
	for (int i = 0; i < (int)G[v].size(); ++i) {
		int u = G[v][i];
		if (!used[u]) {
			DFS_visit(u);
		}
	}
}

int DFS(int N) {
	int k = 0;
	used.assign(N, false);
	for (int v = 0; v < N; ++v) {
		if (!used[v]) {
			++k;
			if (k > 1) {
				return k;
			}
			DFS_visit(v);
		}
	}
	return k;
}

int main() {
	int N, M, K;
	int t;

	fin >> N;

	G.resize(N);
	M = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			fin >> t;
			if (t == 1) {
				G[i].push_back(j);
				++M;
			}
		}
	}
	M /= 2;

	K = DFS(N);

	if (K == 1 && M == N - 1) {
		fout << "YES\n";
	} else {
		fout << "NO\n";
	}

	return 0;
}