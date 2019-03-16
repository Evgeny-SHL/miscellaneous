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

const double Eps = 1e-15;
const long long bInf = (long long)(1e18 + 3);
const long long sInf = (long long)(1e9 + 7);
const int None = -1;
const double Pi = acos(-1.0);
const double eu = exp(1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

vector< vector<int> > x, y;
vector<int> len;

int main() {
	freopen("raspil.in", "r", stdin);
	freopen("raspil.out", "w", stdout);
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int k, n, nx;
	double lx, rx, mx1, mx2, ym, s1, s2, curx, smax, ny, curs;

	cin >> k;
	x.resize(k + 1);
	y.resize(k + 1);
	len.resize(k + 1);
	nx = sInf;
	for (int i = 1; i <= k; ++i) {
		cin >> n;
		len[i] = n;
		x[i].resize(n + 1);
		y[i].resize(n + 1);
		for (int j = 0; j <= n; ++j) {
			cin >> x[i][j] >> y[i][j];
		}
		nx = min(nx, min(-x[i][0], x[i][n]));
	}
	smax = 0.0;
	lx = 0.0;
	rx = (double)nx;
	for (int t = 1; t <= 500; ++t) {
		mx1 = lx + (rx - lx) / 3.0;
		mx2 = rx - (rx - lx) / 3.0;
	//	cout << lx << " " << mx1 << " " << mx2 << " " << rx << "\n";
		ym = (double)sInf;
		for (int i = 1; i <= k; ++i) {
			for (int j = 0; j <= len[i]; ++j) {
				if (abs((double)x[i][j]) > mx1 - Eps) {
					continue;
				}
				curx = mx1;
				if (x[i][j] < 0) {
					curx = -curx;
				}
				ny = (double)y[i][j] * curx / (curx - (double)x[i][j]);
				if (ny < ym + Eps) {
					ym = ny;
				}
			}
		}
		s1 = ym * mx1;
		ym = (double)sInf;
		for (int i = 1; i <= k; ++i) {
			for (int j = 0; j <= len[i]; ++j) {
				if (abs((double)x[i][j]) > mx2 - Eps) {
					continue;
				}
				curx = mx2;
				if (x[i][j] < 0) {
					curx = -curx;
				}
				ny = (double)y[i][j] * curx / (curx - (double)x[i][j]);
				if (ny < ym + Eps) {
					ym = ny;
				}
			}
		}
		s2 = ym * mx2;
		if (s1 < s2 - Eps) {
			lx = mx1;
			curs = s2;
		} else {
			rx = mx2;
			curs = s1;
		}
		if (curs > smax + Eps) {
			smax = curs;
		}
	}
	cout << smax << "\n";

	return 0;
}

