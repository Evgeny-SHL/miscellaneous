#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct inter {
	int l;
	int r;
	inter(int a = 0, int b = 0) {
		l = a;
		r = b;
	}
};

bool comp(inter a, inter b) {
	if (a.l < b.l) return true;
	if (a.l == b.l && a.r > b.r) return true;
	return false;
}

bool cross(inter a, inter b) {
	return (a.l <= b.l) && (a.r > b.l)  || (a.l <= b.l) && (a.r >= b.r);
}

const int m = 1e6 + 3;

int main() {
	int n, a, b;
	int ans = 2;

	cin >> n;
	vector<inter> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		arr[i] = inter(a, b);
	}

	sort(arr.begin(), arr.end(), comp);

//	for (int i = 0; i < n; ++i)
//		cout << arr[i].l << " " << arr[i].r << '\n';

	bool f = true;
	bool zero = false;
	inter c = arr[0];
	for (int i = 1; i < n; ++i) {
		if (cross(c, arr[i]) && (f || !cross(arr[i - 1], arr[i]))) {
			f = false;
			continue;
		}
		if (!f && cross(arr[i - 1], arr[i])) {
			zero = true;
			break;
		}
		c = arr[i];
		ans = (2 * ans) % m;
		f = true;
	}

	if (zero) cout << 0;
	else cout << ans;

	return 0;
}