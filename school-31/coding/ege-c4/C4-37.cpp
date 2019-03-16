#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;



int main() {
	int m1 = 0, m2 = 0, m3 = 0, m4 = 0, m, r;
	int k = 0;
	while (true) {
		cin >> m;
		if (m == 0) {
			break;
		}
		++k;
		if (m % 2 == 0 && m % 3 != 0 && m > m1) {
			m1 = m;
		}
		if (m % 3 == 0 && m % 2 != 0 && m > m2) {
			m2 = m;
		}
		if (m % 6 == 0 && m > m3) {
			m3 = m;
		}
		if (m % 6 != 0 && m > m4) {
			m4 = m;
		}
	}
	cin >> r;
	int r1 = max(m1 * m2, m3 * m4);
	cout << k << "\n";
	cout << r << "\n";
	cout << r1 << "\n";
	if (r == r1) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}