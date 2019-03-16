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

map<string, int> cnt;
vector<int> z;
vector<string> p;

void add (string s) {
	int n = (int)s.length();
	z.clear();
	z.resize(n);
	p.resize(n);
	p[0] = s[0];
	for (int i = 1; i < n; ++i) {
		p[i] = p[i - 1] + s[i];
	//	cout << p[i] << "\n";
	}
	int l, r;
	l = r = 0;
	z[0] = n;
	if (cnt.find(s) != cnt.end()) {
		++cnt[s];
	} else {
		cnt[s] = 1;
	}
//	cout << s << " " << n << "\n";
//	cout << 0 << ": " << z[0] << "\n";
	for (int i = 1; i < n; ++i) {
		if (i <= r) {
			z[i] = min(z[i - l], r - i + 1);
		}
		while (z[i] + i < n && s[z[i]] == s[z[i] + i]) {
			z[i] += 1;
		}
		if (z[i] + i - 1 > r) {
			l = i;
			r = z[i] + i - 1;
		}
	//	cout << i << ": " << z[i] << "\n";
		if (z[i] + i == n) {
			if (cnt.find(p[z[i] - 1]) != cnt.end()) {
				++cnt[p[z[i] - 1]];
			} else {
				cnt[p[z[i] - 1]] = 1;
			}
		}
	}
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "r", stdout);
#endif
	int n, m;
	string s;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		add(s);
	}
//	for (auto it = cnt.begin(); it != cnt.end(); ++it) {
//		cout << it->first << " " << it->second << "\n";
//	}
	cin >> m;
	for (int j = 1; j <= m; ++j) {
		cin >> s;
		if (cnt.find(s) != cnt.end()) {
			cout << cnt[s] << "\n";
		} else {
			cout << "0\n";
		}
	}
	return 0;
}