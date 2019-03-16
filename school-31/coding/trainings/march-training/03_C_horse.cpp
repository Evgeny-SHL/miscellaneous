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

int dc[4] = {0, -1, 1, 0};
int dr[4] = (-1, 0, 0, 1);

int main() {
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, m, dy, dx, x, y, ans, x0, y0;
	int ymin, ymax, xmin, xmax;

	n = 8;
	m = 8;
	x0 = 3;
	y0 = 7;
	x = 6;
	y = 2;
	cout << n << m << "\n";
	cout << x0 << " " << y0 << "\n";

	while (true) {
		cin >> dx >> dy >> ans;
		x0 += dx;
		y0 += dy;
		if (ans == 1 && x == x0 && y == y0) {
			cout << "1 0 0\n";
			cout.flush();
			return 0;
		} else {
			cout << "0 ";
		}
		int key = rand() % 4;
		cout << dx[key] << " " << dy[key] << "\n";
		cout.flush();
		x += dx[key];
		y += dy[key];
	}

	return 0;
}
