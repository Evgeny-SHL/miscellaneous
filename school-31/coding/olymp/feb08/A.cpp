#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> a, b, age;
vector<int> used;

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int n, m, p;
	int ans;

	cin >> n >> m >> p;
	a.resize(n);
	b.resize(m);
	used.assign(n + 1, false);
	age.assign(m + 1, n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		age[b[i]] = min(age[b[i]], i);
	}

	ans = 0;
	while (age[p] != n) {
		++ans;
		p = a[age[p]];
		if (used[age[p]]) {
			cout << "-1\n";
			return 0;
		} else {
			used[age[p]] = true;
		}
	}

	cout << ans << "\n";

	return 0;
}
