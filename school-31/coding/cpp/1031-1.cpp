#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > g;
vector<vector<bool> > colored;

void dfs_visit(int i, int j, int n, int m) {
	colored[i][j] = true;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if ((i + di >= 0 && i + di < n && j + dj >= 0 && j + dj < m) && (abs(di) + abs(dj) != 2) && (!colored[i + di][j + dj]) && g[i + di][j + dj] == 1)
				dfs_visit(i + di, j + dj, n, m);
		}
	}
}

int dfs(int n, int m) {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			if (!colored[i][j] && g[i][j] == 1) {
				dfs_visit(i, j, n, m);
				++cnt;
			}
	}
	return cnt;
}

int main() {
	int n, m;
	char c;

	cin >> n >> m;
	g.resize(n);
	colored.resize(n);
	for (int i = 0; i < n; ++i) {
		g[i].resize(m, 0);
		colored[i].resize(m, false);
		for (int j = 0; j < m; ++j) {
			cin >> c;
			if (c == '*')
				g[i][j] = 1;
		}
	}

	cout << dfs(n, m);

	return 0;
}