#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <cmath>
#include <random>
#include <ctime>
#include <cassert>
using namespace std;

const double Eps = (double)(1e-9);
const long long Inf = (long long)(1e18);
const int None = -1;
const double Pi = acos(-1.0);
const double Eu = exp(1.0);

vector< vector<long long> > dp;
vector<long long> s;

int value(int cnt, int k, int c) {
	return (cnt % k == 0) ? c : 0;
}

bool comp(int a, int b) {
	return a > b;
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	srand(time(0));
	ios_base::sync_with_stdio(0);
	cout << fixed;
	cout.precision(9);

	long long n, k, c, d, a, b, bprev;
	long long ans = 0;
	cin >> n >> k >> c >> d;
	cin >> a >> b;
	ans += d * (b - a);
	bprev = b;
	s.resize(n);
	for (int i = 1; i < n; ++i) {
		cin >> a >> b;
		ans += d * (b - a);
		s[i] = d * (a - bprev);
		bprev = b;
	}
	dp.resize(n);
	for (int i = 0; i < n; ++i) {
		dp[i].resize(i + 1, Inf);
	}
	dp[0][0] = 0;
	for (int pref = 0; pref < n - 1; ++pref) {
		for (int free = 0; free <= pref; ++free) {
			dp[pref + 1][free + 1] = min(dp[pref + 1][free + 1], dp[pref][free] + value(free + 1, k, c));
			dp[pref + 1][free] = min(dp[pref + 1][free], dp[pref][free] + s[pref + 1]);
		}
	}
	long long delt = Inf;
	for (int free = 0; free <= n - 1; ++free) {
		delt = min(delt, dp[n - 1][free]);
	}
	ans += delt;
	cout << ans << "\n";
	return 0;
}
