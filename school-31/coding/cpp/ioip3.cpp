#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <deque>
#include <set>
using namespace std;

ifstream fin("icebergs.in");
ofstream fout("icebergs.out");

const double EPS = 1e-9;

struct pt {
	long long x, y;
	pt(long long p1 = 0, long long p2 = 0) {
		x = p1;
		y = p2;
	}
};

vector<pt> ice;

bool enough(double l, pt a, pt b) {
	return (l > sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) - EPS);
}

bool cross(int l, int r) {
	double k = (ice[r].y - ice[l].y) / (ice[r].x - ice[l].x);
	double x0 = (double)ice[l].x;
	double y0 = (double)ice[l].y;
	for (int i = l + 1; i < r; ++i) {
		if (k * (ice[i].x - x0) + y0 < ice[i].y - EPS) {
			return false;
		}
	}
	return true;
}

bool may(double l, int n) {
//	cout << l << " " << n << '\n';
	for (int i = 1, j;;) {
		j = n - 1;
		while (j > i && (!enough(l, ice[i], ice[j]) || !cross(i, j))) {
			--j;
		}
	//	cout << i << " " << j << '\n';
		if (j == n - 1) {
			return true;
		}
		if (j == i) {
			return false;
		}
		i = j;
	}
	return true;
}

int main() {
	int n;
	long long x, y;
	double l, r, m;

	fin >> n;

	ice.resize(n);
	for (int i = 0; i < n; ++i) {
		fin >> x >> y;
		ice[i] = pt(x, y);
	}

	for (int i = 0; i < n; ++i) {
		cout << ice[i].x << " " << ice[i].y << '\n';
	}

	l = 0.0;
	r = 2e10;
	for (int t = 0; t <= 100; ++t) {
		m = (l + r) / 2;
		if (may(m, n)) {
			r = m;
		} else {
		//	cout << m << "!!!" << '\n';
			l = m;
		}
	//	cout << l << " " << r << '\n';
	}

	fout << fixed;
	fout.precision(12);
	fout << r << '\n';

	return 0;
}