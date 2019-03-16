#include <iostream>
using namespace std;

int main() {

	int x, y, z, m;

	cin >> x >> y >> z >> m;

	int t1 = 5 * (m / 5 + (m % 5 != 0)) + z - m;
	int t2 = 10 * (m / 10 + (m % 10 != 0)) + y - m;
	int t3 = 15 * (m / 15 + (m % 15 != 0)) + x - m;

	cout << min(t1, min(t2, t3)) << '\n';

	return 0;
}