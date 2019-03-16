#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
#ifdef DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "r", stdout);
#endif
	int n, m;
	cin >> n >> m;
	if (n == 0 && m > 0) {
		cout << "Impossible\n";
	} else {
		int a, b;
		a = n;
		b = n;
		if (m > n && n > 0) {
			a += m - n;
		}
		if (n > 0 && m > 0) {
			b += m - 1;
		}
		cout << a << " " << b << "\n";
	}
	return 0;
}