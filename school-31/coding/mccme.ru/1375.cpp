#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> rank_set;

void make_set(int x) {
	parent[x] = x;
	rank_set[x] = 0;
}
int find_set(int x) {
	if (x != parent[x]) {
		parent[x] = find_set(parent[x]);
	}
	return parent[x];
}

void link(int x, int y) {
	if (rank_set[x] > rank_set[y]) {
		parent[y] = x;
	} else {
		parent[x] = y;
		if (rank_set[x] == rank_set[y]) {
			++rank_set[y];
		}
	}
}

void union_sets(int x, int y) {
	link(find_set(x), find_set(y));
}

int main() {
	int n, m, v, u, k;
	bool f;
	cin >> n >> m;
	parent.resize(n + 1);
	rank_set.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		make_set(i);
	}
	k = n;
	for (int i = 1; i <= m; ++i) {
		cin >> v >> u;
		if (find_set(v) != find_set(u)) {
			--k;
			union_sets(v, u);
		}
		if (k == 1) {
			cout << i << '\n';
			break;
		}
	}
	return 0;
}