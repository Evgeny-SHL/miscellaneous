#include <iostream>
using namespace std;

int main() {
	int n = 6;
	int a[6] = {2, 5, 3, 4, 6, 1};
	int d[7];
	d[0] = -1000;
	for (int i=1; i<=n; ++i)
		d[i] = 1000;

	for (int i=0; i<n; i++) {
		for (int j=1; j<=n; j++) {
			if (d[j-1] < a[i] && a[i] < d[j]) {
				d[j] = a[i];
			}
		}
		for (int j = 0; j < n; ++j) {
			cout << d[j] << " ";
		}
		cout << '\n';
	}
	return 0;
}