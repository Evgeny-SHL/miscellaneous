#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const double PI = acos(-1.0);

int main() {
	double a, b, c, x, z, d, a1, a2, b1, b2, c1, c2;
	int n;

	cin >> n;

	cout << fixed;
	cout.precision(6);

	if (n % 10 + (n % 100 - n % 10) / 10 == (n % 10000 - n % 1000) / 1000 + (n % 1000 - n % 100) / 100)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}