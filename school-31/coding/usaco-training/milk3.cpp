/*
ID: ugnthes1
PROG: milk3
LANG: C++11
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
using namespace std;

set<int> ans;
map<tuple<int, int, int>, bool> used;
queue<tuple<int, int, int>> q;
vector<tuple<int, int, int>> to(6);

void bfs(int x, int y, int z, int a, int b, int c) {
	auto cur = make_tuple(x, y, z);
	used[cur] = true;
	q.push(cur);
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		x = get<0>(cur);
		y = get<1>(cur);
		z = get<2>(cur);
		if (x == 0) {
			ans.insert(z);
		}
		to[0] = make_tuple(max(0, x + y - b), min(x + y, b), z);
		to[1] = make_tuple(max(0, x + z - c), y, min(x + z, c));
		to[2] = make_tuple(min(x + y, a), max(0, x + y - a), z);
		to[3] = make_tuple(x, max(0, y + z - c), min(y + z, c));
		to[4] = make_tuple(min(x + z, a), y, max(0, x + z - a));
		to[5] = make_tuple(x, min(y + z, b), max(0, y + z - b));
		for (int i = 0; i < 6; ++i) {
			if (used.find(to[i]) == used.end()) {
				q.push(to[i]);
				used[to[i]] = true;
			}
		}
	}
}

int main() {
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);

	int a, b, c;

    cin >> a >> b >> c;

    bfs(0, 0, c, a, b, c);

    auto it = ans.begin();
    cout << (*it);
    ++it;
    for (; it != ans.end(); ++it) {
		cout << " " << (*it);
    }
    cout << "\n";

	return 0;
}
