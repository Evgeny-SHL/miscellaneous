#include <iostream>
using namespace std;

int main() {
	int n, a, b, c;

	cin >> n;

	a = 1;
	b = 1;
	if (n == 1) cout << "0 1";
	else {
		for (int i = 2; i < n; ++i) {
			c = a + b;
			a = b;
			b = c;
		}
		cout << a << " " << b;
	}

}