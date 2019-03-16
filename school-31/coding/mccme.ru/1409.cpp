#include <iostream>
using namespace std;

int main() {
	int n;
	long int a[999], m1 = 0, m2 = 1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < a[m1]) m1 = i;
	}


	for (int i = 0; i < n; i++) {
		if ((a[i] < a[m2]) && (m1 != i)) m2 = i;
	}
	cout << a[m1] << " " << a[m2];

	return 0;
}