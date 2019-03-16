#include <iostream>
using namespace std;

int main() {
	int x, y, c, a, b;
	cin >> x >> y >> c;
	if (c - y >= 0 && c - y <= x)
		cout << c - y << " " << y;
	else if (c - x >= 0 && c - x <= y)
		cout << x << " " << c - x;
	else if (y >= c)
		cout << 0 << " " << c;
	else if (x >= c)
		cout << c << " " << 0;
	else cout << "Impossible";

}