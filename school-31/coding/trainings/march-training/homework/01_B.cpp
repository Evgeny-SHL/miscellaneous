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

vector<int> a;
vector<int> dp;

int main() {
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, ans, len;

	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	dp.resize(n + 1);
	dp[0] = -(int)sInf;
	for (int i = 1; i <= n; ++i) {
		dp[i] = (int)sInf;
	}
	for (int i = 1; i <= n; ++i) {
		int j = (int)(upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin());
		if (dp[j - 1] <= a[i] && a[i] <= dp[j]) {
			dp[j] = a[i];
		}
		if (i == n) {
			len = j;
		}
	}
	cout << n - len << "\n";
	return 0;
}
