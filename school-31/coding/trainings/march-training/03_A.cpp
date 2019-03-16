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

vector< pair<int, int> > p, prs;

int main() {
	freopen("mosaic.in", "r", stdin);
	freopen("mosaic.out", "w", stdout);
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, k, l, r, m;
	bool good;

	cin >> n;
	p.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].first >> p[i].second;
	}
	for (int i = 1; i <= n - 1; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (p[i].first != p[j].first &&
				p[i].second != p[j].second) {
				prs.push_back(make_pair(i, j));
				break;
			}
		}
	}
	m = (int)prs.size();
	cin >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> l >> r;
		good = true;
		for (int j = 0; j < m; ++j) {
			if (prs[j].first >= l && prs[j].first <= r &&
				prs[j].second >= l && prs[j].second <= r) {
				cout << prs[j].first << " " << prs[j].second << "\n";
				good = false;
				break;
			}
		}
		if (good) {
			cout << "0 0\n";
		}
	}

	return 0;
}
