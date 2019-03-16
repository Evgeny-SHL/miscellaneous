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

const int Inf = (int)(1e9 + 7);

vector<int> h;
vector< vector<int> > dp;
set< pair<int, int> > arch;

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int n, k;
	cin >> n >> k;
	h.resize(n);
	dp.resize(n);
	for (int i = 0; i < n; ++i) {
		dp[i].assign(k + 1, Inf);
		cin >> h[i];
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			auto best = arch.lower_bound(h[i] - dp[i][k - 1] - 1)++;
		}
	}
	return 0;
}