/*
ID: ugnthes1
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

bool ok(int x, int y, int z, int a, int b, int c, int n) {
	int da = abs(x - a);
	int db = abs(y - b);
	int dc = abs(z - c);
	if ((da <= 2 || da >= n - 2) && (db <= 2 || db >= n - 2) && (dc <= 2 || dc >= n - 2)) {
		return true;
	}
	return false;
}

int main() {
	ifstream cin ("combo.in");
  ofstream cout ("combo.out");

    int a1, b1, c1, a2, b2, c2, n;

    cin >> n;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;

    int l = 0;
    for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				if (ok(i, j, k, a1, b1, c1, n) || ok(i, j, k, a2, b2, c2, n)) {
					++l;
				}
			}
		}
    }

    cout << l << '\n';

    return 0;
}