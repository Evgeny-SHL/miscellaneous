#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct point {
	int x, y, len2;
	point(int a = 0, int b = 0, int c = 0) {
		x = a;
		y = b;
		len2 = c;
	}
};

vector<point> pt;
deque<point> s;
point p0;
int n;

point find_p0() {
	int ind = 0;
	for (int i = 1; i < n; ++i)
		if (pt[i].y < pt[ind].y)
			ind = i;
		else if (pt[i].y == pt[ind].y && pt[i].x < pt[ind].x)
			ind = i;
	p0 = pt[ind];
	pt[ind] = pt[n - 1];
	pt[n - 1] = p0;
	--n;
	pt.resize(n);
}

bool comp(point a, point b) {
	if ((a.x - p0.x) * (b.y - p0.y) > (b.x - p0.x) * (a.y - p0.y)) return true;
	if ((a.x - p0.x) * (b.y - p0.y) == (b.x - p0.x) * (a.y - p0.y) && a.len2 > b.len2) return true;
	return false;
}

bool eq_phi(point a, point b) {
	return (a.y - p0.y) * (b.x - p0.x) == (b.y - p0.y) * (a.x - p0.x);
}

void sort_point() {
	for (int i = 0; i < n; ++i)
		pt[i].len2 = pow(pt[i].y - p0.y, 2) + pow(pt[i].x - p0.x, 2);
	sort(pt.begin(), pt.end(), comp);
	for (int i = 1; i < n; ++i) {
		if (eq_phi(pt[i], pt[i - 1])) {
			for (int j = i + 1; j < n; ++j)
				pt[j - 1] = pt[j];
			--n;
			pt.resize(n);
			--i;
		}
	}
}

bool phi_left(point a, point b, point c) {
	return (c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x) < 0;
}

void graham_scan() {
	find_p0();
	sort_point();
	if (n < 2) {
		s.push_back(p0);
		if (n == 1)
			s.push_back(pt[0]);
		return;
	}
	s.push_back(p0);
	s.push_back(pt[0]);
	s.push_back(pt[1]);
	for (int i = 2; i < n; ++i) {
		while (!phi_left(s[s.size() - 2], s[s.size() - 1], pt[i])) {
			s.pop_back();
		}
		s.push_back(pt[i]);
	}
}

int main() {
	int x, y, m;
	bool f;

	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		f = true;
		for (int j = 0; j < pt.size(); ++j)
			if (pt[j].x == x && pt[j].y == y) {
				f = false;
				break;
			}
		if (f)
			pt.push_back(point(x, y));
	}
	n = pt.size();

	graham_scan();

	if (m % 2 != 0) {
		cout << s.size() << '\n';
		while (!s.empty()) {
			point p = s.back();
			cout << p.x << " " << p.y << '\n';
			s.pop_back();
		}
	} else {
		cout << s.size() << '\n';
		while (!s.empty()) {
			point p = s.front();
			cout << p.x << " " << p.y << '\n';
			s.pop_front();
		}
	}

	return 0;
}