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

const long long Inf = (long long)1e18;
vector<long long> a, b, c;

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "r", stdout);
#endif
	int n;
	cin >> n;
	a.resize(2 * n + 1);
	b.resize(2 * n + 1);
	c.resize(2 * n + 1);
	b[0] = 0;
	c[0] = 0;
	for (int i = 1; i <= 2 * n; ++i) {
		cin >> a[i];
		b[i] = b[i - 1] + a[i];
		c[i] = c[i - 1];
		if (i % 2 != 0) {
			c[i] += a[i];
		}
	}
//	for (int i = 1; i <= 2 * n; ++i) {
//		cout << c[i] << "\n";
//	}
//	cout << "\n";
	long long p1, p2;
	long long ans = Inf;
	for (int i = 2; i <= n + 1; ++i) {
		p1 = a[1] + a[i];
		p2 = b[i - 1];
	//	cout << i << "\n";
	//	cout << p1 << " " << p2 << "\n";
		p2 += c[2 * n] - c[2 * (i - 1)];
		if (p1 * p2 < ans) {
			ans = p1 * p2;
		}
	//	cout << p1 << " " << p2 << "\n";
	//	cout << '\n';
	}
	cout << ans << "\n";
	return 0;
}