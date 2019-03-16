#include <iostream>
#include <vector>
using namespace std;

struct edge {
	int f;
	edge(int a = 0) {
		f = a;
	}
};

const int WHITE = 0;
const int BLACK = 1;
const int GRAY = 2;
const int NIL = -1;
vector<vector<edge> > g;
vector<int> start;
vector<int> finish;
vector<int> pi;
vector<int> cc;
vector<int> color;
int time;

void dfs_visit(int v, int counter) {
	++time;
	cc[v] = counter;
	start[v] = time;
	color[v] = GRAY;
	for (int i = 0; i < g[v].size(); ++i) {
		int u = g[v][i].f;
		if (color[u] == WHITE) {
			pi[u] = v + 1;
			dfs_visit(u, counter);
		}
	}
	color[v] = BLACK;
	++time;
	finish[v] = time;
}

void dfs() {
	time = 0;
	int counter = 0;
	for (int v = 0; v < g.size(); ++v)
		if (color[v] == WHITE) {
			++counter;
			dfs_visit(v, counter);
		}
}

int main() {
	int n, m, s, v, u;

	cin >> n;
	g.resize(n);
	start.resize(n, 0);
	finish.resize(n, 0);
	color.resize(n, WHITE);
	pi.resize(n, NIL);
	cc.resize(n, 0);
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> v >> u;
		g[v - 1].push_back(edge(u - 1));
	}

	dfs();

	for (int v = 0; v < n; ++v)
		if (pi[v] != NIL)
			cout << pi[v] << " ";
		else cout << "NIL ";
	cout << '\n';
	for (int v = 0; v < n; ++v)
		cout << start[v] << " ";
	cout << '\n';
	for (int v = 0; v < n; ++v)
		cout << finish[v] << " ";
	cout << '\n';
	for (int v = 0; v < n; ++v)
		cout << cc[v] << " ";
	cout << '\n';

	return 0;
}