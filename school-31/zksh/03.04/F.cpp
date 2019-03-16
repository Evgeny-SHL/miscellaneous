#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cmath>
using namespace std;

struct biection {
	long long w, p;
	biection(long long param1, long long param2) {
		w = param1;
		p = param2;
	}
};

bool comp(biection x, biection y) {
	return (x.p - x.w < y.p - y.w);
}

vector<long long> p, w;
vector<bool> used;
vector<biection> bcn;
multiset<long long> sp;

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "r", stdout);
#endif
	int n, k;
	cin >> n >> k;
	p.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		sp.insert(p[i]);
	}
	w.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
	}
	sort(p.begin() + 1, p.end());
	sort(w.begin() + 1, w.end());
	used.assign(n + 1, false);
	for (int i = n; i >= 1; --i) {
		auto j = sp.lower_bound(w[i]);
		if (j != sp.end()) {
			bcn.push_back(biection(w[i], *j));
			used[i] = true;
			sp.erase(j);
		}
	}
	if (bcn.size() < n - k) {
		cout << "NO\n";
	} else {
		long long ans = 0;
		sort(bcn.begin(), bcn.end(), comp);
		for (int i = 0; i < n - k; ++i) {
			ans += bcn[i].p;
		}
		for (int i = n - k; i < (int)bcn.size(); ++i) {
			ans += bcn[i].w;
		}
		for (int i = 1; i <= n; ++i) {
			if (!used[i]) {
				ans += w[i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}