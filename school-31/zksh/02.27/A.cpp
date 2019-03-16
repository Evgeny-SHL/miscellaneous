#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> a;
set<int> x;

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	a = 3;
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int cur = a[1] - a[0];
	for (int i = 2; i < n; ++i) {
		cur = __gcd(cur, a[i] - a[i - 1]);
	}
	for (int i = 2; i <= (int)sqrt(cur) + 1; ++i) {
		if (cur % i == 0) {
			x.insert(i);
			x.insert(cur / i);
		}
	}
	x.insert(cur);
	cout << x.size() << "\n";
	for (set<int>::iterator it = x.begin(); it != x.end(); ++it) {
		cout << *it << "\n";
	}
	return 0;
}