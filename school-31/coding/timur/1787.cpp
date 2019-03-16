#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {

	int n, k, m, a;
	cin >> k >> n;

	m = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		m = max(0, m + a - k);
	}

	cout << m;

	return 0;
}