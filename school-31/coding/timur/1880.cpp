#include <iostream>
#include <iomanip>
#include <math.h>
#include <map>
using namespace std;

map<int, int> nums;

int main() {

	int n, m, k, x, ans = 0;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		nums[x] = 1;
	}

	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x;
		if (nums[x] == 1) nums[x] = 2;
	}

	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> x;
		if (nums[x] == 2) ++ans;
	}

	cout << ans;

	return 0;
}