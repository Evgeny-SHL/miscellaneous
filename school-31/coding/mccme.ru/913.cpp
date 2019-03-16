#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> a;

int main() {
	int n;

	cin >> n;
	a.resize(n + 1);
	a[0] = 1;
	a[1] = 2;

	for (int i = 2; i <= n; ++i)
		a[i] = a[i - 1] + a[i - 2];

	cout << a[n];

	return 0;
}