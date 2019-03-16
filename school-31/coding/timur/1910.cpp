#include <iostream>
using namespace std;

int main() {

	int indmax, sum, n;
	int x1, x2, x3;

	cin >> n;
	sum = 0;
	cin >> x1 >> x2;
	for (int i = 2; i < n; ++i) {
		cin >> x3;
		if (x1 + x2 + x3 > sum) {
			sum = x1 + x2 + x3;
			indmax = i;
		}
		x1 = x2;
		x2 = x3;
	}

	cout << sum << " " << indmax << '\n';

	return 0;
}