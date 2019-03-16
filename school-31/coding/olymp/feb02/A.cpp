#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> st, fn, st1, fn1;
vector<int> a, b;
vector< vector<int> > G;
vector<int> T;
vector<bool> used;
int num;
int len, lq;

void funDFS(int v) {
	st[v] = ++num;
	used[v] = true;
	for (int i = 0; i < (int)G[v].size(); ++i) {
		int u = G[v][i];
		if (!used[u]) {
			T[u] = v;
			funDFS(u);
		}
	}
	fn[v] = num;
}

void sadDFS(int v) {
	st1[v] = ++num;
	used[v] = true;
	if (v != 1 && used[v]) {
		sadDFS[T[v]];
	}
	fn1[v] = num;
}

void _Init(int n) {
	a.assign(n + 1, 0);
	len = (int)sqrt(n);
	b.assign(n / len + 1, -1);
}

void _Inc(int l, int r, int d, int n) {
	int left = l / len;
	int right = r / len;
	if (left == right) {
		if (b[left] != -1) {
			for (int i = left * len; i <= min(n, (left + 1) * len - 1); ++i) {
				a[i] = b[left];
			}
			b[left] = -1;
		}
		for (int i = l; i <= r; ++i) {
			a[i] = d;
		}
	} else {
		_Inc(l, min(n, (left + 1) * len - 1), d, n);
		_Inc(right * len, r, d, n);
		for (int i = left + 1; i <= right - 1; ++i) {
			b[i] = d;
		}
	}
}

int main() {
	int n, q, c, k;
	int u, v;

	fin >> n;
	G.resize(n + 1);
	T.resize(n + 1);
	for (int i = 1; i <= n - 1; ++i) {
		fin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	num = 0;
	used.assign(n + 1, false);
	st.resize(n + 1);
	fn.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			funDFS(i);
		}
	}

	fin >> q;
	lq = (int)sqrt(q);

	_Init(n);
	num = 0;

	used.assign(n + 1, false);
	k = 0;
	for (int i = 1; i <= q; ++i) {
		fin >> c >> v;
		if (c == 1) {
			_Inc(st[v], fn[v], 1, n);
		} else if (c == 2) {
			_Dec(st[v], 0, n);
		} else {
			if (b[st[v] / len] == -1) {
				cout << a[st[v]] << "\n";
			} else {
				cout << b[st[v] / len] << "\n";
			}
		}
	}

	return 0;
}
