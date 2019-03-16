#include <iostream>
using namespace std;

int main() {

	int n;
	long int a[99][99], x;

	cin >> x >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	int i;
	for (int j = 0; j < n; j++) {
		for (i = 0; i < n; i++)
			if (a[i][j] == x) break;

		if (i >= n) cout << "NO\n";
			else cout << "YES\n";
	}

	return 0;
}