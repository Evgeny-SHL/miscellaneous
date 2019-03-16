#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, a[999], x, m;

	cin >> n;
	for (int i = 0; i < n; )
		cin >> a[i++];
	cin >> x;

	m = 0;
	for (int i = 1; i < n; i++)
		if (abs(a[i] - x) <= abs(a[m] - x)) m = i;

	cout << a[m];

	return 0;
}