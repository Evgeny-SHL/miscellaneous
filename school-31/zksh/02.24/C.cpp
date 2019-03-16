#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
using namespace std;

const long long Inf = (1e9 + 7);

vector<long long> a, b;
multiset<long long> chsn;

int main() {
	int n, m, k;
	long long b;
	set<long long>::iterator it;

	cin >> n >> m >> k;

	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	for (int j = 0; j < m; ++j) {
		cin >> b;
		for (int i = 0; i < min(n, k); ++i) {
			chsn.insert(a[i] * b);
			if (chsn.size() > k) {
				it = chsn.end();
				--it;
				chsn.erase(it);
			}
		}
	}

	long long sum = 0;
	for (it = chsn.begin(); it != chsn.end(); ++it) {
		sum = (sum + *it) % Inf;
	}

	cout << sum << "\n";

	return 0;
}