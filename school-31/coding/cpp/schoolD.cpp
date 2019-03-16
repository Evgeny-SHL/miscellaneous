#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int m = 1e8;

int main() {
	int n;
	int ans = 0;
	long long s1 = 0;
	long long s2 = 0;
	int x;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		s1 += x % m;
		s1 %= m;
		s2 += ((x % m) * (x % m)) % m;
		s2 %= m;
	}
	s1 = (2 * ((s1 * s1) % m)) % m;
	s2 = (2 * ((n * s2) % m)) % m;
	cout << (s2 - s1 + m) % m;

	return 0;
}