#include <iostream>
using namespace std;

int main() {
	int n;
	double x;

	cin >> n >> x;

	double s = 0;
	for (int k = 1; k <= n; ++k) {
		for (int m = k; m <= n; ++m)
			s += (x + k) / m;
	}

	cout.precision(6);
	cout << fixed <<  s;

	return 0;
}