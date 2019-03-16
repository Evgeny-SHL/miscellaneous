#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int None = -1;
const int Max = 1000000;

struct node {
	int chd[26];
	int ind, len, pred;
	bool leaf;
	node() {
		for (int i = 0; i < 26; ++i) {
			chd[i] = None;
		}
		ind = 0;
		leaf = false;
		len = 0;
		pred = None;
	}
};

int vertex;
int to_node[Max + 1];
long long cost[Max + 1];
node tree[Max + 1];
char p[Max + 1];

void put(int ind, string p) {
	int v = 0;
	int n = (int)p.length();
	for (int i = 0; i < n; ++i) {
		int j = (int)(p[i] - 'a');
		if (tree[v].chd[j] == None) {
			++vertex;
			tree[v].chd[j] = vertex;
		}
		v = tree[v].chd[j];
	}
	tree[v].leaf = true;
	tree[v].ind = ind;
	tree[v].len = n;
	to_node[ind] = v;
}

long long sum(int v, int k) {
	long long res = 0;
	while (v != None && tree[v].len >= k) {
		res += cost[tree[v].ind];
		v = tree[v].pred;
	};
	return res;
}

void find_preds(int v, int p) {
	if (tree[v].leaf) {
		tree[v].pred = p;
		p = v;
	}
	for (int u = 0; u < 26; ++u) {
		if (tree[v].chd[u] != None) {
			find_preds(tree[v].chd[u], p);
		}
	}
}

int main() {
	freopen("pizza.in", "r", stdin);
	freopen("pizza.out", "w", stdout);

	for (int i = 0; i <= Max; ++i) {
		to_node[i] = 0;
		cost[i] = 0;
		tree[i] = node();
	}

	int n, m, l, i, k;
	char c;
	long long j;

	scanf("%d %d", &n, &m);
	vertex = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%s %I64d", &p, &cost[i]);
		put(i, p);
	}
	find_preds(0, 0);
	for (int q = 1; q <= m; ++q) {
		scanf("%s", &c);
		if (c == '!') {
			scanf("%d %I64d", &i, &j);
			cost[i] += j;
		} else {
			scanf("%d %d", &i, &k);
			printf("%I64d\n", sum(to_node[i], k));
		}
	}

	return 0;
}
