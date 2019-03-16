#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <set>
using namespace std;

vector< vector< set< pair<int, int> > > > child;
set< pair<int, int> > cur;
vector< vector<bool> > G, used;
int n, m;


set< pair<int, int> > DFS(int r, int c) {
//	cout << r << " " << c << "\n";
	set<pair<int, int> > res;
	res.insert(make_pair(r, c));
	used[r][c] = true;
	if (r < n && !used[r + 1][c] && G[r + 1][c]) {
	//	res.insert(make_pair(r + 1, c));
		cur = DFS(r + 1, c);
	//	child[r + 1][c].insert(cur.begin(), cur.end());
		res.insert(cur.begin(), cur.end());
	} else if (r < n && used[r + 1][c] && G[r + 1][c]) {
		res.insert(child[r + 1][c].begin(), child[r + 1][c].end());
	}
	if (c < m && !used[r][c + 1] && G[r][c + 1]) {
	//	res.insert(make_pair(r, c + 1));
		cur = DFS(r, c + 1);
	//	child[r][c + 1].insert(cur.begin(), cur.end());
		res.insert(cur.begin(), cur.end());
	} else if (c < m && used[r][c + 1] && G[r][c + 1]) {
		res.insert(child[r][c + 1].begin(), child[r][c + 1].end());
	}
//	cout << r << " " << c << " " << "OK\n";

	child[r][c].insert(res.begin(), res.end());
	return res;
}

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
	used.resize(n + 1);

	G[0].assign(m + 1, false);
	used[0].assign(m + 1, false);
	child.resize(n + 1);

//	cout << "OK\n";

	for (int i = 1; i <= n; ++i) {
		G[i].assign(m + 1, true);
		used[i].assign(m + 1, 0);
		child[i].resize(m + 1);
		for (int j = 1; j <= m; ++j) {
			cin >> t;
			if (t == '#') {
				G[i][j] = false;
			}
		}
	}

//	cout << "OK\n";
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (G[i][j] && !used[i][j]) {
				cur = DFS(i, j);
			//	cout << "out\n";
			//	child[i][j].insert(cur.begin(), cur.end());
			}
		}
	}
	cin >> q;
//	cout << "query\n";
	for (int k = 1; k <= q; ++k) {
		cin >> i >> j >> r >> c;
		if (child[i][j].find(make_pair(r, c)) != child[i][j].end()) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	/*for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << "(" << i << "," << j << "): ";
			for (set< pair<int, int> >::iterator it = child[i][j].begin(); it != child[i][j].end(); ++it) {
				cout << "(" << it->first << "," << it->second << ") ";
			}
			cout << "\n";
		}
	}*/

	return 0;
}

