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

vector<int> z;

vector<int> compute_z_function(string s) {
	int n = (int)s.length();
	vector<int> z(n);
	int l, r;
	l = r = 0;
	z[0] = n;
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
	}
	return z;
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "r", stdout);
#endif
	int t;
	string s, q, c;
	cin >> t;
	for (int p = 1; p <= t; ++p) {
		cin >> s >> q;
		if (s.length() != q.length()) {
			cout << "NO\n";
			continue;
		}
		c = s + "#" + q + q;
		z = compute_z_function(c);
		bool f = false;
	//	cout << c << "\n";
		for (int i = 0; i < c.length(); ++i) {
		//	cout << z[i] << "\n";
			if (z[i] == (int)s.length()) {
				cout << "YES\n";
				f = true;
				break;
			}
		}
		if (f) {
			continue;
		}
		reverse(s.begin(), s.end());
	//	cout << s << "\n";
		c = s + "#" + q + q;
		z = compute_z_function(c);
		for (int i = 0; i < c.length(); ++i) {
		//	cout << z[i] << "\n";
			if (z[i] == (int)s.length()) {
				cout << "YES\n";
				f = true;
				break;
			}
		}
		if (f) {
			continue;
		}
		cout << "NO\n";
	}
	return 0;
}