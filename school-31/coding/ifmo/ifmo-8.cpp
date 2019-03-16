#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool> > g;

void dfs(int x, int y) {
	cout << x << " " << y << '\n';
	g[x][y] = true;
	if (!g[x + 1][y]) {
		dfs(x + 1, y);
	}
	if (!g[x - 1][y]) {
		dfs(x - 1, y);
	}
	if (!g[x][y + 1]) {
		dfs(x, y + 1);
	}
	if (!g[x][y - 1]) {
		dfs(x, y - 1);
	}
}

int main() {

	g.resize(11);
	for (int i = 0; i <= 10; ++i) {
		g[i].resize(11, false);
	}

	g[1][5] = true;
	g[1][6] = true;
	g[2][4] = true;
	g[2][7] = true;
	g[3][4] = true;
	g[3][7] = true;

	g[4][2] = true;
	g[4][3] = true;
	g[4][8] = true;
	g[4][9] = true;

	g[5][1] = true;
	g[5][10] = true;
	g[6][1] = true;
	g[6][10] = true;

	g[7][2] = true;
	g[7][3] = true;
	g[7][8] = true;
	g[7][9] = true;

	g[10][5] = true;
	g[10][6] = true;
	g[9][4] = true;
	g[9][7] = true;
	g[8][4] = true;
	g[8][7] = true;

	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= 10; ++j) {
			cout << g[i][j];
		}
		cout << '\n';
	}

	dfs(4, 4);

	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= 10; ++j) {
			cout << g[i][j];
		}
		cout << '\n';
	}

	return 0;
}