#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> rank_set;
vector<int> weight;

void make_set(int x) {
	parent[x] = x;
	rank_set[x] = 0;
}

int find_set(int x) {
	if (parent[x] != x) {
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
	int n, m, v, u, w, x, k;
	cin >> n >> m;
	parent.resize(n + 1);
	rank_set.resize(n + 1);
	weight.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		make_set(i);
		weight[i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> k;
		if (k == 1) {
			cin >> v >> u >> w;
			union_sets(v, u);
			weight[find_set(v)] += w;
		} else {
			cin >> x;
			cout << weight[find_set(x)] << '\n';
		}
	}
	return 0;
}