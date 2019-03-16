#include <iostream>
using namespace std;

int main() {

	long long a, b, c, n, x, y, z, s;
	bool f = false;

	cin >> a >> b >> c >> n;

	if (a % 2 == 0) {
		s = n - (n % 2);
	} else {
		s = n - (n % 2) + 1;
	}

	for (x = s; x >= 0; x -= 2) {
		y = (a + x) / 2 - b;
		z = b - c + y;
		if (y < 0 || x < 0 || z < 0 || x + y + z > n) {
			continue;
		}
		f = true;
		break;
	}

	if (f) {
		cout << x << '\n';
		cout << y << '\n';
		cout << z << '\n';
	} else {
		cout << 0 << '\n';
	}

	return 0;
}