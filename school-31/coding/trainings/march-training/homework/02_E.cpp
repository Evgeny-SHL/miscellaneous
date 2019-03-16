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
const int Root = 1;
const int White = 0;
const int Gray = 1;
const int Black = 2;

bool cycled;
vector< vector<int> > g;
vector<int> color;
vector<int> sorted;

void top_sort(int u) {
	color[u] = Gray;
	for (int v: g[u]) {
		if (color[v] == Gray) {
			cycled = true;
		} else if (color[v] == White) {
			top_sort(v);
		}
	}
	color[u] = Black;
	sorted.push_back(u);
}

void print_sorted() {
	while (sorted.size() > 0) {
		cout << sorted.back() << " ";
		sorted.pop_back();
	}
	cout << "\n";
}

int main() {
	freopen("topsort.in", "r", stdin);
	freopen("topsort.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, m, u, v;

	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
	}
	cycled = false;
	color.assign(n + 1, White);
	for (int u = 1; u <= n; ++u) {
		if (color[u] == White) {
			top_sort(u);
		}
	}
	if (!cycled) {
		print_sorted();
	} else {
		cout << "-1\n";
	}

	return 0;
}
