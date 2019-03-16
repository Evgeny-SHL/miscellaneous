#include <iostream>
using namespace std;

int main() {

	int n, l, k = 0, s = -1, f;
	bool t = false;

	cin >> l >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> f;
		if (f == 1 && s != -1 && i - s + 1 > l) {
			++k;
			s = -1;
		}
		if (f == 1 && s == -1) {
			s = i;
		}
		if (f == 1) {
			t = true;
		}
	}
	++k;

	if (t) {
		cout << k << '\n';
	} else {
		cout << 0 << '\n';
	}

	return 0;
}