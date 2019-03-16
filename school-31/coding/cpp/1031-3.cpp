#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<bool> > g;
vector<vector<bool> > colored;
const int N = 8;

void dfs_visit(int i, int j) {
	colored[i][j] = true;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (i + di >= 0 && i + di < N && j + dj >= 0 && j + dj < N && !colored[i + di][j + dj] && g[i][j] == !g[i + di][j + dj] && abs(di) + abs(dj) != 2)
				dfs_visit(i + di, j + dj);
		}
	}
}

int dfs() {
	int cnt = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (!colored[i][j]) {
				++cnt;
				dfs_visit(i, j);
			}
	return cnt;
}

int main() {
	char c;

	g.resize(N);
	colored.resize(N);
	for (int i = 0; i < N; ++i) {
		g[i].resize(N, false);
		colored[i].resize(N, false);
		for (int j = 0; j < N; ++j) {
			cin >> c;
			if (c == 'B')
				g[i][j] = true;
		}
	}

	cout << dfs();

	return 0;
}