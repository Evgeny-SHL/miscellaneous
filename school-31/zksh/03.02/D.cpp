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

const long long Inf = (long long)(1e9 + 7);
vector<int> a;
vector<long long> deg;
vector< vector<long long> > comb;

long long combinations(int n, int k) {
	if (k > n || n < 0 || k < 0) {
		return 0;
	}
	return comb[n][k];
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		a[i] = (int)(s[i] - '0');
	}
	deg.resize(n);
	deg[0] = 1;
	for (int i = 1; i < n; ++i) {
		deg[i] = (10 * deg[i - 1]) % Inf;
	}
	comb.resize(n + 1);
	for (int i = 0; i <= n; ++i) {
		comb[i].resize(i + 1);
	}
	comb[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		comb[i][0] = 1;
		comb[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % Inf;
		}
	}
//	cout << "OK\n";
    long long ans = 0;
    for (int i = 0; i <= n - 1; ++i) {
		long long delt = 0;
		for (int j = 0; j <= n - i - 2; ++j) {
			delt = (delt + (deg[j] * combinations(n - j - 2, k - 1)) % Inf) % Inf;
		//	cout << a[i] << " " << j << " " << n - j - 2 << " " << k - 1 << " " << combinations(n - j - 2, k - 1) << "\n";
		}
		ans = (ans + (a[i] * delt) % Inf) % Inf;
		ans = (ans + (a[i] * deg[n - i - 1] * combinations(i, k)) % Inf) % Inf;
	//	cout << a[i] << " " << n - i - 1 << " " <<  combinations(i, k) << "\n";
    }
    cout << ans << "\n";
	return 0;
}