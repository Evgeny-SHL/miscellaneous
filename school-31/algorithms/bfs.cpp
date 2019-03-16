#include <iostream>
#include <deque>
#include <vector>
using namespace std;

struct edge {
	int f;
	int weight;
	edge(int a = 0, int b = 0) {
		f = a;
		weight = b;
	}
};

const int WHITE = 0;
const int BLACK = 1;
const int GRAY = 2;
const int NIL = -1;
const int INF = 1e9 + 7;
vector<vector<edge> > g;
vector<int> dist;
vector<int> pi;
vector<int> color;

void bfs(int s) {
	color[s] = GRAY;
	dist[s] = 0;
	deque<int> q;
	q.push_back(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop_front();
		for (int i = 0; i < g[v].size(); ++i) {
			int u = g[v][i].f;
			if (color[u] == WHITE) {
				color[u] = GRAY;
				dist[u] = dist[v] + 1;
				pi[u] = v + 1;
				q.push_back(u);
			}
		}
		color[v] = BLACK;
	}
}

int main() {
	int n, m, s, v, u;

	cin >> n;
	g.resize(n);
	dist.resize(n, INF);
	color.resize(n, WHITE);
	pi.resize(n, NIL);
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> v >> u;
		g[v - 1].push_back(edge(u - 1));
	}
	cin >> s;
	s--;

	bfs(s);

	for (int v = 0; v < n; ++v)
		if (dist[v] != INF)
			cout << dist[v] << " ";
		else cout << "INF ";
	cout << '\n';
	for (int v = 0; v < n; ++v)
		if (pi[v] != NIL)
			cout << pi[v] << " ";
		else cout << "NIL ";
	cout << '\n';

	return 0;
}