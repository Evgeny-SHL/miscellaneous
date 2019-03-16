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
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

vector< vector<int> > dp;
vector< vector<string> > pr;
string s;

int main() {
	freopen("palindrome.in", "r", stdin);
	freopen("palindrome.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, lst;

	cin >> s;
	n = (int)s.size();
	s = "*" + s;

	dp.resize(3);
	pr.resize(3);
	for (int i = 0; i < 3; ++i) {
		dp[i].resize(n + 1);
		pr[i].resize(n + 1);
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = 0;
			pr[i][j] = "";
		}
	}
	for (int i = 1; i <= n; ++i) {
		dp[1][i] = 1;
		pr[1][i] = s[i];
	}
	for (int len = 2; len <= n; ++len) {
		for (int frs = 1; frs <= n - len + 1; ++frs) {
			lst = frs + len - 1;
			if (s[frs] == s[lst]) {
				dp[2][frs] = 2 + dp[0][frs + 1];
				pr[2][frs] = s[frs] + pr[0][frs + 1];
			} else if (dp[1][frs + 1] > dp[1][frs]) {
				dp[2][frs] = dp[1][frs + 1];
				pr[2][frs] = pr[1][frs + 1];
			} else {
				dp[2][frs] = dp[1][frs];
				pr[2][frs] = pr[1][frs];
			}
		}
		dp[0] = dp[1];
		dp[1] = dp[2];
		pr[0] = pr[1];
		pr[1] = pr[2];
	}
	cout << dp[1][1] << "\n";
	cout << pr[1][1];
	s = pr[1][1];
	n = dp[1][1];
	for (int i = n / 2 - 1; i >= 0; --i) {
		cout << s[i];
	}
	cout << "\n";

	return 0;
}
