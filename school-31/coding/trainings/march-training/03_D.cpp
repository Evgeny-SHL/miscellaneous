#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;

const double Eps = 1e-9;
const long long bInf = (long long)(1e18 + 3);
const long long sInf = (long long)(1e9 + 7);
const double Pi = acos(-1.0);
const double eu = exp(1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

vector<int> sqns;
vector<int> line;
vector<int> dp;

int gcs(int n) {
	int res;
	dp.clear();
	dp.resize(n);
	dp[0] = 1;
	res = 1;
	for (int i = 1; i < n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (line[j] < line[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
				res = max(res, dp[i]);
			}
		}
	}
	return res;
}

bool good(int n, int k) {
	int s = 0;
	for (int i = 0; i < k; ++i) {
		bool ok = false;
		for (int j = s; j < n; ++j) {
			if (line[j] == sqns[i]) {
				s = j + 1;
				ok = true;
				break;
			}
		}
		if (!ok) {
			return false;
		}
	}
	return true;
}

int main() {
	freopen("army.in", "r", stdin);
	freopen("army.out", "w", stdout);
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, k;
	long long ans;

	cin >> n;
	cin >> k;
	sqns.resize(k);
	for (int i = 0; i < k; ++i) {
		cin >> sqns[i];
	}
	line.resize(n);
	for (int i = 0; i < n; ++i) {
		line[i] = i + 1;
	}
	ans = 0;
	do {
		if (gcs(n) == k && good(n, k)) {
			++ans;
		}
	} while(next_permutation(line.begin(), line.end()));
	cout << ans << "\n";

	return 0;
}
