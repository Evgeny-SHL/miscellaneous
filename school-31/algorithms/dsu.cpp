#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> rank_set;
const int NIL = -1;

void make_set(int x) {
	parent[x] = x;
	rank_set[x] = 0;
}

int find_set(int x) {
	if (x != parent[x])
		parent[x] = find_set(parent[x]);
	return parent[x];
}

void link(int x, int y) {
	if (rank_set[x] > rank_set[y])
		parent[y] = x;
	else {
		parent[x] = y;
		if (rank_set[x] == rank_set[y])
			++rank_set[y];
	}
}

void union_sets(int x, int y) {
	link(find_set(x), find_set(y));
}

int main() {
	int n, m, x, y, l;

	cin >> n >> m;
	parent.resize(n + 1, NIL);
	rank_set.resize(n + 1, NIL);
	for (int i = 0; i < n; ++i) {
		cin >> x;
		make_set(x);
	}

	for (int i = 0; i < m; ++i) {
		cin >> l >> x;
		if (l == 1)
			cout << find_set(x) << '\n';
		else {
			cin >> y;
			union_sets(x, y);
		}
	}

	return 0;
}