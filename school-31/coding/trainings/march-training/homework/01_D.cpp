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
const int Max = 20;
const int bMax = (1 << Max);

int a[Max];
int b[Max];
int c[Max];
int dp[bMax][Max];
pair<int, int> pr[bMax][Max];
vector<int> ans;

int main() {
	freopen("meetings.in", "r", stdin);
	freopen("meetings.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	for (int i = 0; i <= Max; ++i) {
		a[i] = b[i] = c[i] = 0;
	}
	for (int m = 0; m < bMax; ++m) {
		for (int i = 0; i <= Max; ++i) {
			dp[m][i] = (int)sInf;
			pr[m][i] = make_pair(-1, -1);
		}
	}
	int n, k;
	int best_mask, best_last, best_lent;

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
	}
	best_lent = 0;
	best_last = -1;
	best_mask = 0;
	for (int i = 0; i < n; ++i) {
		dp[0][i] = k;
	}
	for (int mask = 0; mask < (1 << n); ++mask) {
		for (int last = 0; last < n; ++last) {
			if (dp[mask][last] != (int)sInf) {
				for (int to_last = 0; to_last < n; ++to_last) {
					int to_mask = mask | (1 << to_last);
					if (to_mask != mask && a[to_last] <= dp[mask][last] && dp[mask][last] <= b[to_last]) {
						dp[to_mask][to_last] = dp[mask][last] + c[to_last];
					//	dp[to_mask][to_last] = c[to_last];
						pr[to_mask][to_last] = make_pair(mask, last);
					}
				}
				bitset<Max> t(mask);
				if (t.count() > best_lent) {
					best_mask = mask;
					best_last = last;
					best_lent = t.count();
				}
			}
		}
	}
	cout << best_lent << "\n";
	ans.resize(best_lent);
	for (int i = 0; i < best_lent; ++i) {
		ans[i] = best_last + 1;
		pair<int, int> next = pr[best_mask][best_last];
		best_mask = next.first;
		best_last = next.second;
	}
	for (int i = best_lent - 1; i >= 0; --i) {
		cout << ans[i] << " \n"[i == 0];
	}

	return 0;
}
