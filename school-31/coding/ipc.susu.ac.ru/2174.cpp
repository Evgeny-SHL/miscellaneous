#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int r, g, b;

	cin >> r >> g >> b;
	if (abs(r - g) <= 25 && abs(r - b) <= 25 && abs(b - g) <= 25)
		cout << "ALLOWED";
	else cout << "FORBIDDEN";

	return 0;
}