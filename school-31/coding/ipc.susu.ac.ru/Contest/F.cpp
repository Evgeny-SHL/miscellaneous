#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:16777216")

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

vector<vector<string>> dp;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	int n = (int)s1.length();
	int m = (int)s2.length();
	dp.assign(n + 1, vector<string>(m + 1, ""));
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = dp[i - 1][0] + s1[i - 1];
	}
	for (int j = 1; j <= m; ++j) {
		dp[0][j] = dp[0][j - 1] + s2[j - 1];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = max({dp[i][j], dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]});
		}
	}
	cout << dp[n][m] << "\n";

	return 0;
}