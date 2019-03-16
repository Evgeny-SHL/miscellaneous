#include <iostream>
using namespace std;

int main() {
	long long t, n, k;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cin >> n >> k;
		long long m = k;
		while (n % m != 0 && m > 2)
			--m;
		if (n % m == 0)
			cout << n * n * (m - 1) / (2 * m) << '\n';
		else {

		}
	}

}