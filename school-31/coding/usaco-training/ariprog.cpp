/*
ID: ugnthes1
PROG: ariprog
LANG: C++11
*/
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

set<int> s;
set<pair<int, int>> ans, used;
vector<int> mb;

int main() {
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);

	int n, m;

	cin >> n >> m;

	for (int p = 0; p <= m; ++p) {
		for (int q = p; q <= m; ++q) {
			s.insert(p * p + q * q);
		}
	}

	for (auto it = s.begin(); it != s.end(); ++it) {
		mb.push_back(*it);
	}
	int k = mb.size();
	int lim = mb[k - 1];

	for (int ia = 0; ia < k; ++ia) {
		for (int ib = ia + 1; ib < k; ++ib) {

			int d = mb[ib] - mb[ia];

			if (used.find(make_pair(d, mb[ia])) != used.end()) {
				continue;
			}

			int cur = mb[ia];
			int ind = 1;
			for (; cur < lim; ++ind) {
				cur += d;
				if (s.find(cur) == s.end()) {
					break;
				}
				if (ind >= n - 1) {
					ans.insert(make_pair(d, mb[ia] + d * (ind - n + 1)));
				}
				used.insert(make_pair(d, mb[ia] + d * ind));
			}
		}
	}

	if (ans.size() == 0) {
		cout << "NONE\n";
	} else {
		for (auto it = ans.begin(); it != ans.end(); ++it) {
			cout << it->second << " " << it->first << "\n";
		}
	}

    return 0;
}