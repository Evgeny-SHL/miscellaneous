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

const int Inf = (int)(1e9 + 7);
const int Max = 10000;
const pair<int, int> None = make_pair(-1, -1);

vector<int> a, b, first_zero, next_dig;
vector< vector<int> > dp;
vector< vector< pair<int, int> > > pi;
set<int> pluses;
int need;

int sum(int l, int r, int max) {
	int res = 0;
	for (int i = (a[l] == 0) ? next_dig[l] : l; i <= r; ++i) {
		res = res * 10 + a[i];
		if (res > max) {
			return -1;
		}
	}
	return res;
}

void relax(int i, int j, int k) {
	int d = sum(k, i, j);
	if (d >= 0) {
		int ip = k - 1;
	//	cout << i << " " << j << " " << k << "\n";
		int jp = j - d;
	//	cout << k << " " << i << "\n";
	//	cout << jp << "\n";
	//	cout << sum(ip, i) << " = " << ip << "..." << jp << "\n";
		//	cout << j << " " << sum(k, i) << " " << ip << "\n";
		//	cout << ip << " " << jp << " " << i << " " << j << "\n";
		int upd = dp[ip][jp];
	//	cout << upd << "\n";
	//	cout << "(" << i << ", " << j << ") " << " <- " << d << " <- " << "(" << ip << ", " << jp << ")\n";
	//	cout << upd << "\n";
		if (upd < Inf) {
		//	cout << "(" << i << ", " << j << ") " << " <- " << j << " <- " << "(" << ip << ", " << jp << ")\n";
			if (upd + 1 < dp[i][j]) {
			//	cout << "(" << i << ", " << j << ") " << " <- " << d << " <- " << "(" << ip << ", " << jp << ")\n";
				pi[i][j] = make_pair(ip, jp);
				dp[i][j] = upd + 1;
			}
		}
	}
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin >> s;
	{
		int i = 0;
		while (s[i] != '=') {
			a.push_back(s[i] - '0');
			i += 1;
		}
		i += 1;
		while (i < (int)s.length()) {
			b.push_back(s[i] - '0');
			i += 1;
		}
	}
	for (int i = 0; i < (int)b.size(); ++i) {
		need = need * 10 + b[i];
	}
	int n = (int)a.size();
	first_zero.assign(n, -1);
	{
		int first = -1;
		bool ret = true;
		for (int i = 0; i < n; ++i) {
			if (a[i] == 0 && ret) {
				first = i;
				ret = false;
			}
			if (a[i] != 0) {
				ret = true;
			}
			if (i + 3 < n) {
				first_zero[i + 3] = first;
			}
		}
	}
	next_dig.resize(n);
	{
		int last = n;
		for (int i = n - 1; i >= 0; --i) {
			if (a[i] != 0) {
				last = i;
			}
			next_dig[i] = last;
		}
	}
/*	for (int i = 0; i < n; ++i) {
		cout << first_zero[i] << " ";
	//	cout << next_dig[i] << " ";
	}
	cout << "\n";
*/	dp.resize(n);
	pi.resize(n);
	for (int i = 0; i < n; ++i) {
		dp[i].assign(Max, Inf);
		pi[i].assign(Max, None);
	}
/*	for (int l = 0; l < n; ++l) {
		for (int r = l; r <= min(n, l + 3); ++r) {
			cout << l << " " << r << " " << sum(l, r) << "\n";
		}
	}
*/	{
	int d = 0;
		for (int l = 0; l < min(4, n); ++l) {
			d = 10 * d + a[l];
			dp[l][d] = 0;
			pi[l][d] = None;
		}
	}
//dp[0][a[0]] = 0;
//	cout << "OK\n";
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= need; ++j) {
			if (first_zero[i] > -1) {
				for (int k = 0; k <= 3; ++k) {
					if (first_zero[i] + k < n) {
						relax(i, j, first_zero[i] + k);
					}
				}
			}
			for (int k = max(1, i - 3); k <= i; ++k) {
			//	cout << i << " " << j << " " << k << "...\n";
				relax(i, j, k);
			//	cout << "OK\n";
			}
		//	cout << i << " " << j << " " << nz[i] << "...\n";
		//	cout << "OK\n";
		//	relax(i, j, i);
		}
	}
//	cout << dp[n - 1][need] << "\n";
	pair<int, int> cur = pi[n - 1][need];
	while (cur != None) {
	//	cout << cur.first << " " << cur.second << "\n";
	//	cout << cur.first << " " << cur.second << "\n";
		pluses.insert(cur.first);
		cur = pi[cur.first][cur.second];
	};
/*	for (auto i = pluses.begin(); i != pluses.end(); ++i) {
		cout << *i << " ";
	}
	cout << "\n";
*/	for (int i = 0; i < n; ++i) {
		cout << a[i];
		if (pluses.find(i) != pluses.end()) {
			cout << "+";
		}
	}
	cout << "=" << need << "\n";
	return 0;
}