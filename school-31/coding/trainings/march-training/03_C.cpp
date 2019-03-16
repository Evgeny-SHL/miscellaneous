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

const double Eps = 1e-9;
const long long bInf = (long long)(1e18 + 3);
const long long sInf = (long long)(1e9 + 7);
const double Pi = acos(-1.0);
const double eu = exp(1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;
const int Max = 10000;

int n, m, dy, dx, x, y, x0, y0, ans, key;
int ymin, ymax, xmin, xmax;
char c;
const int hx[5] = {0, -1, 0, 0, 1};
const int hy[5] = {0, 0, -1, 1, 0};

void ezhik() {
	dx = -1 + rand() % 3;
	dy = -1 + rand() % 3;
	if (x < xmin) {
		dx = 1;
	} else if (x > xmax) {
		dx = -1;
	} else {
		if (x + dx < xmin || x + dx > xmax) {
			dx = 0;
		}
	}
	if (y < ymin) {
		dy = 1;
	} else if (y > ymax) {
		dy = -1;
	} else {
		if (y + dy < ymin || y + dy > ymax) {
			dy = 0;
		}
	}
	x += dx;
	y += dy;
	if (x >= xmin && x <= xmax &&
		y >= ymin && y <= ymax) {
		ans = 1;
	} else {
		ans = 0;
	}
}

void horse() {
	if (ans == 1 && x0 == x && x0 == y) {
		ans = 1;
		dx = 0;
		dy = 0;
	} else {
		ans = 0;
		key = rand() % 5;
		dx = hx[key];
		dy = hy[key];
		if (x0 + dx > m || x0 + dx < 1) {
			dx = 0;
		}
		if (y0 + dy > n || y0 + dy < 1) {
			dy = 0;
		}
		x0 += dx;
		y0 += dy;
	}
}

int main() {
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	cin >> x >> y;
	xmin = 1;
	xmax = m;
	ymin = 1;
	ymax = n;
	x0 = 1 + rand() % m;
	y0 = 1 + rand() % n;
	for (int t = 1; t <= Max; ++t) {
		ezhik();
		assert(x <= m && x >= 1);
		assert(y <= n && y >= 1);
	//	cout << "ezh: ";
		cout << dx << " " << dy << " " << ans << "\n";
		cout.flush();
	//	horse();
	//	assert(x0 <= m && x0 >= 1);
	//	assert(y0 <= n && y0 >= 1);
	//	cout << "hrs: ";
	//	cout << ans << " " << dx << " " << dy << "\n";
	//	cout.flush();
		cin >> ans >> dx >> dy;
		if (ans == 1) {
		//	cout << t << "\n";
			return 0;
		}
		if (dx == 1) {
			xmax = min(m, xmax + 1);
			xmin = min(xmax, xmin + 1);
		} else if (dx == -1) {
			xmin = max(1, xmin - 1);
			xmax = max(xmin, xmax - 1);
		}
		if (dy == 1) {
			ymax = min(n, ymax + 1);
			ymin = min(ymax, ymin + 1);
		} else if (dy == -1) {
			ymin = max(1, ymin - 1);
			ymax = max(ymin, ymax - 1);
		}
		assert(1 <= xmin);
		assert(1 <= ymin);
		assert(1 <= xmax);
		assert(1 <= ymax);
		assert(xmin <= m);
		assert(ymin <= n);
		assert(xmax <= m);
		assert(ymax <= n);
		assert(xmin <= xmax);
		assert(ymin <= ymax);
	//	cout << xmin << " " << xmax << "\n";
	//	cout << ymin << " " << ymax << "\n";
	//	cout << x << " " << y << "\n";
	}

	return 0;
}
