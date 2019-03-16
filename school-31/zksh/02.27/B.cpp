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

vector<long long> dp, deg;
vector< vector<long long> > c;
const long long Inf = (long long)(1e9 + 7);
long long Max;

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	dp.resize(n + 1);
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 1;
	if (n <= 2) {
		cout << dp[n] << "\n";
		return 0;
	}
	Max = n * (n - 1) / 2;
	deg.resize(Max + 1);;
	deg[0] = 1;
	for (int i = 1; i <= Max; ++i) {
		deg[i] = (2 * deg[i - 1]) % Inf;
	}
	c.resize(n + 1);
	for (int i = 0; i <= n; ++i) {
		c[i].resize(i + 1);
	}
	c[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		c[i][0] = 1;
		c[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % Inf;
		}
	}
	for (int i = 3; i <= n; ++i) {
		dp[i] = deg[i * (i - 1) / 2];
		cout << dp[i] << ": ";
		for (int j = 1; j <= i; ++j) {
			dp[i] = (dp[i] + Inf - (c[i][j] * dp[i - j]) % Inf) % Inf;
			cout << c[i]
			[j] << " " << dp[i - j] << ", ";
		}
		dp[i] %= Inf;
		cout << "\n";
		cout << i << " " << dp[i] << "\n";
	}
	cout << dp[n] << "\n";
	return 0;
}