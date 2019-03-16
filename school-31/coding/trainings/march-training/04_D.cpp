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
const int sInf = (int)(1e9 + 7);
const int None = -1;
const double Pi = acos(-1.0);
const double eu = exp(1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

vector<int> y;
vector< vector<int> > dp, pr, lm, lk;

int main() {
	freopen("dynasties.in", "r", stdin);
	freopen("dynasties.out", "w", stdout);
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, s;
	int kl, kr, ml, mr;

	cin >> n;
	y.resize(n + 1);
	y[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> y[i];
	}
	cin >> s;
	int ind = 0;
	int ans = sInf;
	string seq = "";
	for (int t = 1; t <= s; ++t) {
		cin >> kl >> kr >> ml >> mr;
		dp.clear();
		dp.assign(n + 1, vector<int>(2, sInf));
		pr.clear();
		pr.assign(n + 1, vector<int>(2, None));
		lk.clear();
		lk.assign(n + 1, vector<int>(2, None));
		lm.clear();
		lm.assign(n + 1, vector<int>(2, None));
		dp[1][0] = 0;
		dp[1][1] = 0;
		lk[1][0] = y[1];
		lm[1][1] = y[1];
		for (int i = 1; i <= n - 1; ++i) {
		//	cerr << dp[2][0] << " " << dp[2][1] << "\n";
		//	cerr << lk[2][0] << " " << lk[2][1] << "\n";
		//	cerr << lm[2][0] << " " << lm[2][1] << "\n";
		//	cerr << "...\n";
		//	cerr << y[i + 1] << " " << lk[i][0] << "\n";
			if (kl <= y[i + 1] - lk[i][0] && y[i + 1] - lk[i][0] <= kr || lk[i][0] == None) {
				if (dp[i][0] != sInf && dp[i][0] + 1 < dp[i + 1][0]) {
					dp[i + 1][0] = dp[i][0] + 1;
					pr[i + 1][0] = 0;
					lm[i + 1][0] = lm[i][0];
					lk[i + 1][0] = y[i + 1];
				//	cerr << "1\n";
				}
			}
		//	cerr << y[i + 1] << " " << lk[i][1] << "\n";
			if (kl <= y[i + 1] - lk[i][1] && y[i + 1] - lk[i][1] <= kr || lk[i][1] == None) {
				if (dp[i][1] != sInf && dp[i][1] + 0 < dp[i + 1][0]) {
					dp[i + 1][0] = dp[i][1] + 0;
					pr[i + 1][0] = 1;
					lm[i + 1][0] = lm[i][1];
					lk[i + 1][0] = y[i + 1];
				//	cerr << "2\n";
				}
			}
		//	cerr << y[i + 1] << " " << lm[i][0] << "\n";
			if (ml <= y[i + 1] - lm[i][0] && y[i + 1] - lm[i][0] <= mr || lm[i][0] == None) {
				if (dp[i][0] != sInf && dp[i][0] + 0 < dp[i + 1][1]) {
					dp[i + 1][1] = dp[i][0] + 0;
					pr[i + 1][1] = 0;
					lk[i + 1][1] = lk[i][0];
					lm[i + 1][1] = y[i + 1];
				//	cerr << "3\n";
				}
			}
		//	cerr << y[i + 1] << " " << lm[i][1] << "\n";
			if (ml <= y[i + 1] - lm[i][1] && y[i + 1] - lm[i][1] <= mr || lm[i][1] == None) {
			//	cerr << "? " << dp[i][1] << "\n";
				if (dp[i][1] != sInf && dp[i][1] + 1 < dp[i + 1][1]) {
					dp[i + 1][1] = dp[i][1] + 1;
					pr[i + 1][1] = 1;
					lk[i + 1][1] = lk[i][1];
					lm[i + 1][1] = y[i + 1];
				//	cerr << "4\n";
				}
			}
		}
		int ths = min(dp[n][0], dp[n][1]);
		if (ths == sInf) {
			continue;
		}
		if (ths < ans) {
			ind = t;
			ans = ths;
			int p;
			if (dp[n][0] == ths) {
				p = 0;
			} else {
				p = 1;
			}
			seq = "";
			for (int i = n; i >= 1; --i) {
				if (p == 0) {
					seq = "1" + seq;
				} else {
					seq = "2" + seq;
				}
				p = pr[i][p];
			}
		}
	}
	if (ans == sInf) {
		cout << 0 << "\n";
	} else {
		cout << ind << " " << ans << "\n";
		cout << seq << "\n";
	}

	return 0;
}
