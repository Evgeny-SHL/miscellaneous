#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cmath>
using namespace std;

vector< vector<int> > a;
vector< vector<bool> > used;
deque< pair<int, int> > q;

bool bfs(int n, int m, int x, int y, int z) {
	used.clear();
	used.resize(n);
	for (int i = 0; i < n; ++i) {
		used[i].assign(m, false);
	}
	for (int s = 0; s < m; ++s) {
		if (a[0][s] == x || a[0][s] == y || a[0][s] == z) {
			used[0][s] = true;
			q.push_back(make_pair(0, s));
		}
	}
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop_front();
		int r = cur.first;
		int c = cur.second;
		used[r][c] = true;
		if (r == n - 1) {
			return true;
		}
		for (int dr = -1; dr <= 1; ++dr) {
			for (int dc = -1; dc <= 1; ++dc) {
				if (r + dr < 0 || r + dr >= n || c + dc < 0 || c + dc >= m ||
					abs(dc) + abs(dr) != 1) {
					continue;
				}
				if (a[r + dr][c + dc] != x && a[r + dr][c + dc] != y && a[r + dr][c + dc] != z) {
					continue;
				}
				if (used[r + dr][c + dc]) {
					continue;
				}
				if (r + dr == n - 1) {
					return true;
				}
				q.push_back(make_pair(r + dr, c + dc));
				used[r + dr][c + dc] = true;
			}
		}
	}
	return false;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> m >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		a[i].resize(m);
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int x = 0; x < 10; ++x) {
		for (int y = x; y < 10; ++y) {
			for (int z = y; z < 10; ++z) {
				if (bfs(n, m, x, y, z)) {
					cout << x << " " << y << " " << z << "\n";
					return 0;
				}
			}
		}
	}
	cout << "-1 -1 -1\n";
	return 0;
}