#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <cassert>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << "1 1 0" << endl;
	for (int k = 1; k <= n - 1; ++k) {
		for (int i = n; i >= k + 2; --i) {
			cout << i << " " << i << " " << k << endl;
			cout << k << " " << k << " " << i << endl;
		}
		cout << k + 1 << " " << k + 1 << " " << k << endl;
	}
	for (int k = n - 1; k >= 2; --k) {
		cout << k << " " << k << " " << k + 1 << endl;
	}
	cout << "0 1 2" << endl;
	return 0;
}