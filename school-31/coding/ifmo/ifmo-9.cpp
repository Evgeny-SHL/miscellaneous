#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > g;
vector<pair<int, int> > pth;

int dfs(int s, int k, int len) {
	if (k < 6) {
		return min(dfs(pth[k + 1].first, k + 1, len + g[s][pth[k + 1].first]),
				   dfs(pth[k + 1].second, k + 1, len + g[s][pth[k + 1].second]));
	} else if (k == 6) {
		return len;
	}
}

int main() {

	g.resize(5);
	for (int i = 1; i <= 4; ++i) {
		g[i].resize(5, 0);
	}
	g[1][2] = 3;
	g[1][3] = 1;
	g[1][4] = 3;
	g[2][3] = 2;
	g[2][4] = 1;
	g[3][4] = 3;
	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= i; ++j) {
			g[i][j] = g[j][i];
		}
	}

	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= 4; ++j) {
			cout << g[i][j];
		}
		cout << '\n';
	}

	pth.resize(7);
	pth[1] = make_pair(1, 3);
	pth[2] = make_pair(2, 3);
	pth[3] = make_pair(2, 4);
	pth[4] = make_pair(3, 4);
	pth[5] = make_pair(1, 2);
	pth[6] = make_pair(1, 4);

	int ans = 6 + min(dfs(1, 2, 0), dfs(3, 2, 0));

	cout << ans << '\n';

	return 0;
}