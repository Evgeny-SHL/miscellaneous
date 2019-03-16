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

const int Max = 2e4 + 1;
const int Inf = 1e9 + 7;
vector<int> dp;

int main() {
#ifdef DEBUG
//	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	dp.assign(Max, Inf);
	dp[n] = 0;
	for (int j = 0; j <= max(n, m); ++j) {
		for (int i = 0; i <= Max / 2; i += 2) {
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
		for (int i = 0; i <= Max; ++i) {
			dp[i] = min(dp[i + 1] + 1, dp[i]);
		}
	}
/*	for (int i = 0; i <= 20; ++i) {
		cout << i << " " << dp[i] << "\n";
	}
*/	cout << dp[m] << "\n";
	return 0;
}