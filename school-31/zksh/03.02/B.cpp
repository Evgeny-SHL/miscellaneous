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

const int Inf = 1e9 + 7;
set<string> cand;

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int n, k, l, c;
	string s, p, t;
	cin >> n >> k;
	cin >> s;
	p = "}";
	if (k == 1) {
		if (n % 2 == 0) {
			for (int i = 0; i < n; ++i) {
				p = min(p, s.substr(i, 1));
			}
		} else {
			for (int i = 0; i < n - 1; ++i) {
				p = min(p, s.substr(i, 2));
			}
		}
	} else {
		if (n % 2 == 0) {
			for (int l = 0; l < n; ++l) {
				for (int len = 1; len <= n - l; len += 2) {
					cand.insert(s.substr(l, len));
				}
			}
		} else {
			for (int l = 0; l < n; ++l) {
				for (int len = 2; len <= n - l; len += 2) {
					cand.insert(s.substr(l, len));
				}
			}
		}
	/*	for (auto it = cand.begin(); it != cand.end(); ++it) {
			cout << *it << "\n";
		}
	*/	auto it = cand.begin();
		for (int i = 1; i < k; ++i) {
			++it;
		}
		p = *it;
	}
	cout << p << "\n";
	return 0;
}