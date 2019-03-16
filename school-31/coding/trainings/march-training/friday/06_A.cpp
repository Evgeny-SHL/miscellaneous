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
const int None = -1;
const double Pi = acos(-1.0);
const double eu = exp(1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

vector< vector< pair<int, int> > > ans;
vector< pair<int, int> > aut;

int main() {
	freopen("attract.in", "r", stdin);
	freopen("attract.out", "w", stdout);
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, m, t, cura, curt;

	cin >> n >> m;
	aut.resize(m + 1);
	for (int i = 1; i <= m; ++i) {
		cin >> t;
		aut[i] = make_pair(-t, i);
	}
	ans.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		ans[i].resize(m + 1);
	}
	sort(aut.begin() + 1, aut.end());
	for (int i = 1; i <= m; ++i) {
		aut[i].first = -aut[i].first;
	}
	for (int j = 1; i <= m; ++i) {
		for (int i = j; j + m - 1; ++j) {
			ans[i][j] = make_pair(aut[j].second, ans[i][j - 1].second + aut[j].first);
		}
	}
	cout << curt << "\n";
	for (int i = 1; i <= n; ++i) {
		cout << "\n";
		for (int j = 1; j <= m; ++j) {
			cout << ans[i][j].first << " " << ans[i][j].second << "\n";
		}
	}

	return 0;
}
