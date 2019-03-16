#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int arr[10010];

int main() {

	int n, m, x;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		arr[i] = 0;
	}

	for (int i = 0; i < m; ++i) {
		cin >> x;
		++arr[x - 1];
	}

	cout << fixed;
	cout << setprecision(2);

	for (int i = 0; i < n; ++i) {
		cout << 100.0 * arr[i] / m << "%" << '\n';
	}

	return 0;
}