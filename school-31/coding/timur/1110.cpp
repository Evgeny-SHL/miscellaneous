#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main() {

	int n, m, y;
	bool f = false;

	cin >> n >> m >> y;

	for (int x = 0; x < m; ++x)
		if ((int) pow(x, n) % m == y) {
			f = true;
			cout << x << " ";
		}

	if (!f) cout << -1;

	return 0;
}