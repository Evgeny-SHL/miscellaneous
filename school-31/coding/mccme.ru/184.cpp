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

bool comp(edge a, edge b) {
	return (a.w < b.w);
}

vector<edge> E;
vector<bool> color;

int main() {
	int N, M;
	int w, c;

	fin >> N;

	M = N * (N - 1);
	for (int u = 0; u < N; ++u) {
		for (int v = 0; v < N; ++v) {
			fin >> w;
			if (w > 0) {
				E.push_back(edge(u, v, w));
			}
		}
	}

	color.assign(N, false);
	for (int u = 0; u < N; ++u) {
		fin >> c;
		if (c == 1) {
			color[u] = true;
		}
	}

	sort(E.begin(), E.end(), comp);

	for (int i = 0; i < M; ++i) {
		if (color[E[i].u] == false &&
			color[E[i].v] == true) {
			fout << E[i].u + 1 << " " << E[i].v + 1 << "\n";
			break;
		}
	}

	return 0;
}