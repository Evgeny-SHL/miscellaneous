#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <ctime>
using namespace std;

const long long bInf = (long long)(1e18 + 3);
const int sInf = (int)(1e9 + 7);
const double Eps = (double)(1e-9);
const int None = -1;
const double Eur = exp(1.0);
const double Pi = acos(-1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

struct edg {
	int from, to;
	long long weight;
	edg(int param1 = 0, int param2 = 0, long long param3 = 0) {
		from = param1;
		to = param2;
		weight = param3;
	}
};

bool comp(edg a, edg b) {
	return (a.weight < b.weight);
}

vector<edg> edges;
vector<int> parent;
vector<int> range;

void dsu_init(int n) {
	parent.resize(n + 1);
	range.resize(n + 1);
	for (int x = 1; x <= n; ++x) {
		parent[x] = x;
		range[x] = 0;
	}
}

int find_set(int x) {
	if (x != parent[x]) {
		parent[x] = find_set(parent[x]);
	}
	return parent[x];
}

void union_sets(int x, int y) {
	int set_x = find_set(x);
	int set_y = find_set(y);
	if (range[set_x] < range[set_y]) {
		parent[set_x] = set_y;
	} else {
		parent[set_y] = set_x;
		if (range[set_x] == range[set_y]) {
			++range[set_x];
		}
	}
}

int main() {
	freopen("spantree2.in", "r", stdin);
	freopen("spantree2.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, m;
	long long sum_w;

	cin >> n >> m;
	edges.resize(m + 1);
	for (int i = 1; i <= m; ++i) {
		cin >> edges[i].from >> edges[i].to >> edges[i].weight;
	}
	sort(edges.begin() + 1, edges.end(), comp);
	dsu_init(n);
	sum_w = 0;
	for (int i = 1; i <= m; ++i) {
		int u = edges[i].from;
		int v = edges[i].to;
		int w = edges[i].weight;
		if (find_set(u) != find_set(v)) {
			sum_w += w;
			union_sets(u, v);
		}
	}
	cout << sum_w << "\n";

	return 0;
}
