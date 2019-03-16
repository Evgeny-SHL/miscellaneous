#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

#define place pair<int, int>

deque< pair<place, int> > q;
vector< vector<int> > dist;
vector< vector<bool> > used;
const int Max = 1e3 + 1;
const place King = make_pair(Max, Max);
const int Inf = 1e9 + 7;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
long long good, bad;
int s;

bool ok(int x, int y) {
	return ((abs(x) + abs(y)) % 2 == 0);
}

void bfs(place start) {
	int d;
	dist.resize(2 * Max + 1);
	for (int i = 0; i <= 2 * Max; ++i) {
		dist[i].assign(2 * Max + 1, Inf);
	}
	place cur, next;
	cur = start;
	good = 0;
	bad = 0;
	used[start.first][start.second] = true;
	q.push_back(make_pair(start, 0));
	while (!q.empty()) {
		cur = q.front().first;
		d = q.front().second;
		dist[cur.first][cur.second] = d;
		q.pop_front();
		if (d <= s) {
			if (ok(cur.first, cur.second)) {
				good += 1;
			} else {
				bad += 1;
			}
		}
		for (int i = 0; i < 4; ++i) {
			next = cur;
			next.first += dx[i];
			next.second += dy[i];
			if (next.first <= 2 * Max && next.second <= 2 * Max &&
				next.first >= 0 && next.second >= 0 &&
				!used[next.first][next.second] && d < s) {
				q.push_back(make_pair(next, d + 1));
				used[next.first][next.second] = true;
			}
		}
	}
}

void c_top() {
	int r = 0;
	for (int c = 0; c <= 2 * Max; ++c) {
		if (dist[r][c] < s) {
			int d = s - dist[r][c];
			good += d / 2;
			bad += d / 2;
			if (ok(r, c) && !ok(r - d, c)) {
				bad += 1;
			} else if (!ok(r, c) && ok(r - d, c)) {
				good += 1;
			}
		}
	}
}

void c_bottom() {
	int r = 2 * Max;
	for (int c = 0; c <= 2 * Max; ++c) {
		if (dist[r][c] < s) {
			int d = s - dist[r][c];
			good += d / 2;
			bad += d / 2;
			if (ok(r, c) && !ok(r + d, c)) {
				bad += 1;
			} else if (!ok(r, c) && ok(r + d, c)) {
				good += 1;
			}
		}
	}
}

void c_left() {
	int c = 0;
	for (int r = 0; r <= 2 * Max; ++r) {
		if (dist[r][c] < s) {
			int d = s - dist[r][c];
			good += d / 2;
			bad += d / 2;
			if (ok(r, c) && !ok(r, c - d)) {
				bad += 1;
			} else if (!ok(r, c) && ok(r, c + d)) {
				good += 1;
			}
		}
	}
}

void c_right() {
	int c = 2 * Max;
	for (int r = 0; r <= 2 * Max; ++r) {
		if (dist[r][c] < s) {
			int d = s - dist[r][c];
			good += d / 2;
			bad += d / 2;
			if (ok(r, c) && !ok(r, c + d)) {
				bad += 1;
			} else if (!ok(r, c) && ok(r, c + d)) {
				good += 1;
			}
		}
	}
}

void c_angle(int r, int c) {
	if (dist[r][c] < s) {
		int d = s - dist[r][c];
		if (!ok(r, c)) {
			for (int i = 1; i < d; i += 2) {
				bad += i;
			}
			for (int i = 2; i < d; i += 2) {
				good += i;
			}
		} else {
			for (int i = 1; i < d; i += 2) {
				good += i;
			}
			for (int i = 2; i < d; i += 2) {
				bad += i;
			}
		}
	}
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	used.resize(2 * Max + 1);
	for (int i = 0; i <= 2 * Max; ++i) {
		used[i].assign(2 * Max + 1, false);
	}
	int n;
	int x, y;
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		used[x + Max][y + Max] = true;
	}
	bfs(King);
	c_top();
	c_bottom();
	c_left();
	c_right();
	c_angle(0, 0);
	c_angle(0, 2 * Max);
	c_angle(2 * Max, 0);
	c_angle(2 * Max, 2 * Max);
	cout << good << " " << bad << "\n";
	return 0;
}