#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string pr(int x, int p) {
	string s = "";
	while (x > 0) {
		int y = x % p;
		s = char(x % p + '0') + s;
		x /= p;
	}
	return s;
}

bool pal(string s) {
	for (int i = 0; i < s.length() / 2; ++i) {
		if (s[i] != s[s.length() - i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {

	int k = 0;
	for (int x = pow(9, 4); x < pow(9, 5); ++x) {
		string n = pr(x, 3);
		string m = pr(x, 9);
		if (pal(n) && pal(m)) {
			cout << x << " " << n << " " << m << '\n';
			++k;
		}
	}

	cout << k << '\n';

	return 0;
}