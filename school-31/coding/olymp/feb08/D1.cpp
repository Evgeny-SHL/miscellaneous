#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <set>
#include <cassert>
using namespace std;

vector< vector<int> > G;
int n, m;

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int q;
	int num;
	char t;
	int i, j, r, c;

	cin >> n >> m;

	G.resize(n + 1);
	G[0].assign(m + 1, -1);
	for (int i = 1; i <= n; ++i) {
		G[i].assign(m + 1, 0);
		for (int j = 1; j <= m; ++j) {
			cin >> t;
			if (t == '#') {
				G[i][j] = -1;
			}
		}
	}

	assert(n * m <= 100 * 100);

	cin >> q;
	for (int k = 1; k <= q; ++k) {
		cin >> i >> j >> r >> c;

		G[i][j] = k;
		for (int x = i; x <= r; ++x) {
			for (int y = j; y <= c; ++y) {
				if (G[x][y] >= 0) {
					G[x][y] = max(G[x][y], max(G[x][y - 1], G[x - 1][y]));
				}
			}
		}
		if (G[i][j] == G[r][c]) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}

