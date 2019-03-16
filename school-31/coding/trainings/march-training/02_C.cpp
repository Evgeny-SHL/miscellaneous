#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;

const double Eps = (double)1e-9;
const long long bInf = (long long)(1e18 + 3);
const long long sInf = (long long)(1e9 + 7);
const double Pi = acos(-1.0);
const double eu = exp(1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

vector<string> pic;

int main() {
	freopen("shuttle.in", "r", stdin);
	freopen("shuttle.out", "w", stdout);
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int r, c, a, b, s, x, y, z, best;
	bool good;

	cin >> r >> c;
	pic.resize(r + 1);
	for (int i = 1; i <= r; ++i) {
		cin >> pic[i];
		pic[i] = "*" + pic[i];
	}
	x = 0;
	y = 0;
	z = 0;
	best = (int)sInf;
	for (int s = 0; 2 * s < c; ++s) {
		for (int a = 1; 2 * a <= r; ++a) {
			for (int b = s + 1; 2 * b <= c; ++b) {
				good = true;
				for (int i = 1; good && (i <= r); ++i) {
					for (int j = 1; good && (j <= c); ++j) {
						if (i - a >= 1 && 	j - s >= 1 			&& 	pic[i][j] != pic[i - a][j - s] ||
							i - a >= 1 && 	j - s + b <= c 		&& 	pic[i][j] != pic[i - a][j - s + b] ||
											j - b >= 1 			&& 	pic[i][j] != pic[i][j - b] ||
											j + b <= c 			&& 	pic[i][j] != pic[i][j + b] ||
							i + a <= r &&	j + s - b >= 1 		&& 	pic[i][j] != pic[i + a][j + s - b] ||
							i + a <= r &&	j + s <= c 			&& 	pic[i][j] != pic[i + a][j + s]) {
							good = false;
							break;
						}
					}
				}
				if (good && a * b < best) {
					best = a * b;
					x = a;
					y = b;
					z = s;
				}
			}
		}
	}
	cout << x << " " << y << " " << z << "\n";

	return 0;
}
