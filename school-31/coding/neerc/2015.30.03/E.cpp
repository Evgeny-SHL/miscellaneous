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

vector<long long> ans;
vector< vector< pair<int, long long> > > query;
vector< vector<int> > link;
vector<bool> used;
vector<bool> colored;
vector<int> len;

vector<long long> tGcd, aGcd;

/*void dfs(int u) {
	colored[u] = true;
	for (int q: link[u]) {
		for (int i = 0; i < (int)query[q].size(); ++i) {
			int c = query[q][i].first;
			long long x = query[q][i].second;
			if (!colored[u]) {

			}
	}
}*/

long long gcd(long long a, long long b) {
	while (b > 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	freopen("accounts.in", "r", stdin);
	freopen("accounts.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, m, c, k;
	long long x;

	cin >> n >> m;
	query.resize(m + 1);
	used.assign(n + 1, false);
	ans.assign(n + 1, 1);
	//link.resize(n + 1);
	tGcd.assign(n + 1, 1);
	aGcd.assign(n + 1, 1);
	len.assign(m + 1, 0);
	for (int q = 1; q <= m; ++q) {
		cin >> k;
		len[q] = k;
		query[q].resize(k + 1);
		for (int i = 1; i <= k; ++i) {
			cin >> c >> x;
			query[q][i] = make_pair(c, x);
		//	link[c].push_back(q);
		}
		long long cGcd = query[q][1].second;
		for (int i = 2; i <= k; ++i) {
			cGcd = gcd(cGcd, query[q][i].second);
		}
		for (int i = 1; i <= k; ++i) {
			c = query[q][i].first;
			x = query[q][i].second;
			if (!used[c]) {
				used[c] = true;
				tGcd[c] = cGcd;
				aGcd[c] = x;
			} else {
				tGcd[c] = gcd(tGcd[c], cGcd);
				aGcd[c] = gcd(aGcd[c], x);
			}
		}

		/*for (int i = 1; i <= k; ++i) {
			c = query[q][i].first;
			x = query[q][i].second;
			long long nAns = x / qGcd;
			if (!used[c]) {
				ans[c] = nAns;
				used[c] = true;
			} else {
				cout << "NO\n";
				return 0;
				long long old = ans[c];
				if (old != nAns) {
					long long lGcd = gcd(old, nAns);
					ans[c] = lGcd;
				}
			}
		}*/
	}
	cout << "YES\n";
	for (int i = 1; i <= n; ++i) {
		cout << tGcd[i] << " " << aGcd[i] << "\n";
	//	cout << gcd(qGcd[i], aGcd[i]) << " ";
	}
	cout << "\n";


	return 0;
}
