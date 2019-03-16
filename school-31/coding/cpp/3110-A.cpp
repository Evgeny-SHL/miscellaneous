#include <iostream>
using namespace std;

int main() {
	int x, y, z, w, k;

	cin >> x >> y >> z >> w;
	k = 0;
	for (int i = 0; i <= w / x; ++i)
		for (int j = 0; j <= (w - i * x) / y; ++j) {
			int c = w - x * i - y * j;
			if (c % z == 0) ++k;
		}

	cout << k;

	return 0;
}