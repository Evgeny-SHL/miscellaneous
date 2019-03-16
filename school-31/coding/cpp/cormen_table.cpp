#include <iostream>
#include <cmath>
using namespace std;

double f(double n) {
	return 1.0 * n * log2(n * 1.0);
}

int main() {
	double n;
	double d;
	unsigned long long t = 1e6 * 60 * 60 * 24 * 30 * 12 * 100;

	n = 5.5e7;
	d = 0.1e7;
	while (f(n + d) <= t)
		n += d;

	cout << n;

}