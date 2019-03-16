#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n + 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i == 0) b[i] = a[i];
		else if (i % 2 == 0) b[i] = b[i - 1] + a[i];
		else b[i] = b[i - 1] - a[i];
	}
	c[0] = b[n - 1];
	for (int i = 1; i < n; ++i) {
		c[i] = a[i - 1] - c[i - 1];
	}
	c[n] = 0;

	int ans = b[n - 1];

	int ind = 0;
	int t  = ans - (c[ind] - c[ind + 1]);
	for (int i = ind + 1; i < n - 2; ++i) {
		if (i % 2 == 0) {
			if (ans - (c[i] - c[i + 1]) < t) {
				ind = i;
				t = ans - (c[i] - c[i + 1]);
			}
		} else {
			if (ans + (c[i] - c[i + 1]) < t) {
				ind = i;
				t = ans + (c[i] - c[i + 1]);
			}
		}
	}
	if (ind % 2 == 0) ans -= (c[ind] - c[ind + 1]);
	else ans += (c[ind] - c[ind + 1]);

	ind++;
	if (ind % 2 != 0) t = ans - (c[ind] - c[ind + 1]);
	else t = ans + (c[ind] - c[ind + 1]);
	for (int i = ind + 1; i < n - 1; ++i) {
		if (i % 2 != 0) {
			if (ans - (c[i] - c[i + 1]) < t) {
				ind = i;
				t = ans - (c[i] - c[i + 1]);
			}
		} else {
			if (ans + (c[i] - c[i + 1]) < t) {
				ind = i;
				t = ans + (c[i] - c[i + 1]);
			}
		}
	}
	if (ind % 2 != 0) ans -= (c[ind] - c[ind + 1]);
	else ans += (c[ind] - c[ind + 1]);

	ind++;
	if (ind % 2 == 0) t = ans - (c[ind] - c[ind + 1]);
	else t = ans + (c[ind] - c[ind + 1]);
	for (int i = ind + 1; i < n; ++i) {
		if (i % 2 == 0) {
			if (ans - (c[i] - c[i + 1]) < t) {
				ind = i;
				t = ans - (c[i] - c[i + 1]);
			}
		} else {
			if (ans + (c[i] - c[i + 1]) < t) {
				ind = i;
				t = ans + (c[i] - c[i + 1]);
			}
		}
	}
	if (ind % 2 == 0) ans -= (c[ind] - c[ind + 1]);
	else ans += (c[ind] - c[ind + 1]);

	cout << ans;

	return 0;
}