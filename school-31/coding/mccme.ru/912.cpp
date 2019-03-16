#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

int main() {
	int n;

	cin >> n;
	a.resize(n + 1);
	a[0] = 1;
	a[1] = 2;
	a[2] = 4;

	for (int i = 3; i <= n; ++i)
		a[i] = a[i - 1] + a[i - 2] + a[i - 3];

	cout << a[n];

	return 0;
}