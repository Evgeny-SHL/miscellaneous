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
#include <cmath>
#include <algorithm>
#include <cassert>
#include <ctime>
using namespace std;

const long long Inf = 1e9 + 7;
const double Eps = (double)(1e-9);
const int None = -1;
const double Eur = exp(1.0);
const double Pi = acos(-1.0);

vector< vector<long long> > crd, dp;
vector<long long> val;

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif // DEBUG
	srand(time(0));
	cout << fixed;
	cout.precision(9);

	int m, k, n, p, q;
	long long lft, rgt, up, fll, dig, ans, mul;
	string c;
	cin >> m >> k;
	crd.resize(m + 1);
	val.assign(m + 1, 0);
	fll = 0;
	crd[0].assign(k + 1, 0);
	for (int i = 1; i <= m; ++i) {
		cin >> c;
		crd[i].assign(k + 1, 0);
		for (int j = 1; j <= k; ++j) {
			crd[i][j] = (int)(c[j - 1] - '0');
			val[i] += crd[i][j];
		}
		fll += val[i];
	}
	lft = 0;
	rgt = 0;
	ans = 0;
	up = 9 * k * m;
	n = m / 2;
	mul = 1;
	for (int i = 1; i <= n; ++i) {
		mul = (mul * (i * i)) % Inf;
	}
	p = ((m % 2 != 0) ? 1 : 0);
	q = ((m % 2 != 0) ? m : 0);
	for (int cnr = p; cnr <= q; ++cnr) {
		lft = 0;
		rgt = 0;
		dig = 0;
		for (int j = 1; j <= k / 2; ++j) {
			lft += crd[cnr][j];
			rgt += crd[cnr][k - j + 1];
		}
		dig = val[cnr] - (lft + rgt);
		dp.clear();
		dp.resize(up + 1);
		for (int i = 0; i <= up; ++i) {
			dp[i].assign(m + 1, 0);
		}
		dp[0][0] = 1;
		for (int i = 1; i <= m; ++i) {
			if (i == cnr) {
				continue;
			}
			for (int sum = fll - val[i]; sum >= 0; --sum) {
				for (int cnt = n - 1; cnt >= 0; --cnt) {
					dp[sum + val[i]][cnt + 1] = (dp[sum + val[i]][cnt + 1] + dp[sum][cnt]) % Inf;
				}
			}
		}
		for (int sum = 0; sum <= fll; ++sum) {
			if (sum + lft == rgt + ((fll - val[cnr]) - sum)) {
				ans = (ans + dp[sum][n]) % Inf;
			}
		}
	}
	ans = (mul * ans) % Inf;
	cout << ans << "\n";

	return 0;
}