#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 1e-6;

int main() {
	int a, b;
	bool f = true;

	cin >> a >> b;
	int v_min = max(50 * (a - 1), 70 * (b - 1));
	int v_max = min(50 * a, 70 * b);
	int c_min = floor(v_min / 60.0 + 1.0 + EPS);
	int c_max = floor(v_max / 60.0 + 1.0);

//	cout << v_min << " " << v_max << '\n';
	if (50 * b < 70 * (a - 1)) {
		for (int c = c_min; c <= c_max; ++c) {
			f = false;
			cout << c << " ";
		}
	}

	if (f) cout << -1;

}