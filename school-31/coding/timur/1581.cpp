#include <iostream>
#include <string>
using namespace std;

int main() {

	int n;
	cin >> n;
	int k, x1, x2;

	cin >> x1;
	k = 1;
	for (int i = 1; i < n; ++i) {
		cin >> x2;
		if (x1 == x2) ++k;
		else {
			cout << k << " " << x1 << " ";
			k = 1;
		}
		x1 = x2;
	}
	cout << k << " " << x1;

	return 0;
}