#include <iostream>
using namespace std;

int main() {
	int n, a[999], m = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > a[m]) m = i;
	}

	cout << m+1;

	return 0;
}