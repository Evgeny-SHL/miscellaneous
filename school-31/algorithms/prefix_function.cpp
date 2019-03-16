#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> pi;

vector<int> prefix_function(string s) {
	int m = s.length();
	int k = 0;
	pi.resize(m, 0);

	for (int q = 1; q < m; ++q) {
		while (k > 0 && s[k] != s[q])
			k = pi[k - 1];
		if (s[k] == s[q])
			++k;
		pi[q] = k;
	}

	return pi;
}

void kmp_matcher(string t, string p) {
	int n = t.length();
	int m = p.length();
	pi = prefix_function(p);
	int q = 0;
	for (int i = 0; i < n; ++i) {
		while (q > 0 && p[q] != t[i])
			q = pi[q - 1];
		if (p[q] == t[i])
			++q;
		if (q == m) {
			cout << i - m + 1 << '\n';
			q = pi[q - 1];
		}
	}
}

int main() {
	string t;
	string p;

	cin >> t;
	cin >> p;

	kmp_matcher(t, p);

	return 0;
}