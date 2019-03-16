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
const long long sInf = (long long)(1e9 + 7);
const double Eps = (double)(1e-9);
const int None = -1;
const double Eur = exp(1.0);
const double Pi = acos(-1.0);

const int Max = 5 * 5;

vector<int> color;
vector< vector<int> > am;
bitset<Max> b;

bool dfs(int v, int n) {
	color[v] = 1;
	bool good = true;
	for (int u = 0; good && (u < n); ++u) {
		if (am[v][u] && color[u] == 1) {
			good = false;
		} else if (am[v][u] && color[u] == 0) {
			good = good && dfs(u, n);
		}
	}
	color[v] = 2;
	return good;
}

int main() {
	freopen("baskerville.in", "r", stdin);
	freopen("baskerville.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, ans, k;
	bool good;

	cin >> n;
	am.resize(n);
	for (int i = 0; i < n; ++i) {
		am[i].resize(n);
	}
	ans = 0;
	assert(n <= 5);
	for (int mask = 0; mask < (1 << n * n); ++mask) {
		good = true;
		b = bitset<Max>(mask);
	//	for (int i = 0; i < n * n; ++i) {
	//		cout << b[i] << " ";
	//	}
	//	cout << "\n";
		k = 0;
		for (int i = 0; good && (i < n); ++i) {
			for (int j = 0; good && (j < n); ++j) {
				am[i][j] = (bool)b[k];
				++k;
				if (am[i][j] == 1 && am[j][i] == 1) {
					good = false;
				}
			}
		}
		if (!good) {
			continue;
		}
	//	cerr << mask << "\n";
		color.clear();
		color.assign(n, 0);
		for (int v = 0; good && (v < n); ++v) {
			if (color[v] == 0) {
			//	cerr << "..." << v << "\n";
			//	cout << "start in " << v << "\n";
				good = good && dfs(v, n);
			}
		}
	/*	if (good) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					cout << am[i][j];
				}
				cout << "\n";
			}
			cout << good << "\n";
		}
	*/	ans = (ans + (int)good) % sInf;
	}
	cout << ans << "\n";

	return 0;
}
