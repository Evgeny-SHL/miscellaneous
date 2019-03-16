#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cmath>
using namespace std;

const int Inf = (int)(1e9 + 7);
vector<int> x, y;
vector< vector<int> > dp;

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "r", stdout);
#endif
	int n, t;
	cin >> n >> t;
	dp.resize(n + 1);
	dp[0].assign(t + 1, Inf);
	x.resize(n + 1);
	y.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
		dp[i].assign(t + 1, Inf);
	}
	dp[0][0] = 0;
	for (int pref = 0; pref <= n - 1; ++pref) {
		for (int times = 0; times <= t; ++times) {
			dp[pref + 1][times] = min(dp[pref + 1][times], dp[pref][times] + x[pref + 1]);
			int delta = min(t - times, y[pref + 1]);
			dp[pref + 1][times + delta] = min(dp[pref + 1][times + delta], dp[pref][times] + y[pref + 1] - delta);
		}
	}
	int ans = Inf;
	for (int times = 0; times <= t; ++times) {
		ans = min(ans, dp[n][times]);
	}
	cout << ans << "\n";
	return 0;
}