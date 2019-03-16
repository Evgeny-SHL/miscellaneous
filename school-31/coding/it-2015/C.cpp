#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

struct edge {
	int u;
	double w;
	edge(int param1 = 0, double param2 = 0.0) {
		u = param1;
		w = param2;
	}
};

vector< vector<double> > field;
vector< vector<edge> > G;
vector<double> ro;
multiset< pair<double, int> > dist;

const double INF = (double)1e18;
const double EPS = (double)1e-12;

// Расстояние между двумя высотами.
double len(int u, int v, int M) {
	int r1, c1, r2, c2;
	c1 = u % M;
	r1 = u / M;
	c2 = v % M;
	r2 = v / M;
	return max(field[r1][c1] - field[r2][c2], 0.0);
}

// Алгоритм Дейкстры за O(ElogV) на set.
double dijkstra(int s, int f, int K) {
	int v, u;
	double w;
	ro.assign(K, INF);
	ro[s] = 0.0;
	dist.insert(make_pair(ro[s], s));
	while (!dist.empty()) {
		v = (*dist.begin()).second;
		if (v == f) {
			return ro[f];
		}
		dist.erase(dist.begin());
		for (int i = 0; i < (int)G[v].size(); ++i) {
			u = G[v][i].u;
			w = G[v][i].w;
			if (ro[u] > ro[v] + w + EPS) {
				dist.erase(make_pair(ro[u], u));
				ro[u] = ro[v] + w;
				dist.insert(make_pair(ro[u], u));
			}
		}
	}
	return ro[f];
}

int main() {
	int N, M;
	int sr, sc, fr, fc;
	int s, f;
	int v, u;

	cin >> N >> M;
	cin >> sr >> sc;
	cin >> fr >> fc;
	s = M * sr + sc;
	f = M * fr + fc;

	field.resize(N);
	for (int i = 0; i < N; ++i) {
		field[i].resize(M);
		for (int j = 0; j < M; ++j) {
			cin >> field[i][j];
		}
	}

	// Генерируем граф по карте высот.
	// Вес ребра - высота подъема.
	G.resize(M * N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			v = M * i + j;
			if (i < N - 1) {
				u = M * (i + 1) + j;
				G[v].push_back(edge(u, len(u, v, M)));
			}
			if (i > 0) {
				u = M * (i - 1) + j;
				G[v].push_back(edge(u, len(u, v, M)));
			}
			if (j < M - 1) {
				u = M * i + (j + 1);
				G[v].push_back(edge(u, len(u, v, M)));
			}
			if (j > 0) {
				u = M * i + (j - 1);
				G[v].push_back(edge(u, len(u, v, M)));
			}
		}
	}

	/*for (int i = 0; i < N * M; ++i) {
		cout << i << ": ";
		for (int j = 0; j < (int)G[i].size(); ++j) {
			cout << "(" << G[i][j].u << "," << G[i][j].w << ")\t";
		}
		cout << "\n";
	}*/

	cout << fixed;
	cout.precision(11);

	// Выводим найденный кратчайший путь.
	cout << dijkstra(s, f, N * M) << "\n";

	return 0;
}

/*
2 3
0 0
1 2
2.3 3.4 4.5
5.6 6.7 7.89

6 3
0 1
5 2
1.1 0.0 0.0
1.21 100.0 1.12
1.31 100.0 1.62
1.41 100.0 1.32
1.51 100.0 1.42
1.81 1.63 1.73

2 4
0 0
1 2
3 2 1 0
7 10 2 10

3 2 1
0 7 10
*/