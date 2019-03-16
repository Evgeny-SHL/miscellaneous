#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> a;
vector<int> f;

int main() {
	int n;

	cin >> n;
	a.resize(n + 1);
	f.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	f[0] = 0;
	f[1] = a[1];

	for (int i = 2; i <= n; ++i)
		f[i] = min(f[i - 1] + a[i], f[i - 2] + a[i]);

	cout << f[n];

	return 0;
}