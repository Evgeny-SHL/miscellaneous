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
	std::vector<int> ar(n + 2);
	for (int i = 1; i <= n; ++i) {
		cin >> ar[i];
	}
	ar[0] = ar[n];
	ar[n + 1] = ar[1];
	for (int i = 1; i <= n; ++i) {
		if (ar[i] > ar[i - 1] && ar[i] > ar[i + 1]) {
			cout << (( i == 1 ) ? n : i - 1) << " " << i << " " << i % n + 1  << endl;
			return 0;
		}
	}
	/*int i1 = -1, j1 = -1, k1 = -1;
	int i2 = -1, j2 = -1, k2 = -1;
	for (int s = 0; s < n; ++s) {
		if (i1 == -1 && ar[s] < ar[n - 1]) {
			i1 = n - 2;
			j1 = n - 1;
			k1 = s;
		}
		if (i2 == -1 && ar[n - s - 1] < ar[0]) {
			i2 = n - s - 1;
			j2 = 0;
			k2 = 1;
		}
	}
	++i1; ++i2; ++j1; ++j2; ++k1; ++k2;
	if ( j1 - i1 + n - ( j1 - k1 ) >= k2 - j2 + n - (i2 - j2) )  {
		cout << i2 << " " << j2 << " " << k2 << endl;
	} else {
		cout << i1 << " " << j1 << " " << k1 << endl;
	}
	//cout << i1 << j1 << k1 << i2 << j2 << k2;*/
	return 0;
}