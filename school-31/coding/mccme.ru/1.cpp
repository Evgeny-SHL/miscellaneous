#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

bool f(int d, int n, int k) {
	int ans = 0;
	for (int i = 1; i <= n; i += n - 1) {
		int a1 = 1;
		int l = i;
		int r = i + 1;
		while (l <= n && r <= n) {
			while (r <= n && a[r] - a[l] < d) {
				++r;
			}
			if (r <= n) {
				++a1;
				l = r++;
			}
		}
		ans = max(ans, a1);
		if (ans >= k) {
			return true;
		}
	}
	return false;
}

int main() {
	int n, k;
	cin >> n >> k;
	a.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int l = 1;
	int r = 1e9 + 7;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (f(m, n, k)) {
			l = m;
		} else {
			r = m;
		}
	}
	cout << l << '\n';
	return 0;
}