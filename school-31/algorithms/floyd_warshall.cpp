#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > dist;
const int INF = 1e9 + 7;

void floyd_warshall(int n) {
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (dist[i][k] != INF && dist[k][j] != INF)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
	int n, m, v, u, w;

	cin >> n;
	dist.resize(n);
	for (int i = 0; i < n; ++i) {
		dist[i].resize(n, INF);
		dist[i][i] = 0;
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> v >> u >> w;
		dist[v - 1][u - 1] = w;
	}

	floyd_warshall(n);

	for (int v = 0; v < n; ++v) {
		for (int u = 0; u < n; ++u)
			if (dist[v][u] != INF)
				cout << dist[v][u] << " ";
			else cout << "INF ";
		cout << '\n';
	}

	return 0;
}