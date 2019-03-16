#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector< vector<int> > G;
vector<int> ch, up, d;
vector<bool> used, important;

// ch[v] = количество сыновей в поддереве с корнем v
// d[v] = время захода в вершину v
// up[v] = минимальное время обнаружения среди всех вершины,
// достижимых из поддерева с корнем v и при прохождении
// ровно по одному обратному ребру

void DFS_visit(int s, int N, int time) {
	used[s] = true;
	++time;
	d[s] = time;
	up[s] = N + 1;
	for (int i = 0; i < (int)G[s].size(); ++i) {
		int v = G[s][i];
		if (!used[v]) {
			++ch[s];
			DFS_visit(v, N, time);
			up[s] = min(up[s], up[v]);
			if (up[v] >= d[s]) {
				important[s] = true;
			}
		} else { // проход по обратному ребру
			up[s] = min(up[s], d[v]);
		}
	}
}

void DFS(int N) {
	used.assign(N, false);
	important.assign(N, false);
	ch.assign(N, 0);
	up.assign(N, 0);
	d.assign(N, 0);
	int time = 0;
	for (int s = 0; s < N; ++s) {
		if (!used[s]) {
			DFS_visit(s, N, time);
			if (ch[s] > 1) {
				important[s] = true;
			} else {
				important[s] = false;
			}
		}
	}
}

int main() {
	int N;
	int u, v;
	int ans;

	fin >> N;

	G.resize(N);
	for (int i = 0; i < N - 1; ++i) {
		fin >> u >> v;
		--u;
		--v;
		G[u].push_back(v);
	}

	DFS(N);

	ans = 0;
	for (int s = 0; s < N; ++s) {
		if (important[s]) {
			++ans;
		}
	}

	fout << ans << "\n";

	return 0;
}