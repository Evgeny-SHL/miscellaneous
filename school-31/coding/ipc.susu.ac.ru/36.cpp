#include <iostream>
#include <algorithm>
using namespace std;

struct point {
	int x, y;
	point(int a = 0, int b = 0) {
		x = a;
		y = b;
	}
};

int direction(point a, point b, point c) {
	return (c.x - a.x) * (b.y - a.y) - (b.x - a.x) * (c.y - a.y);
}

bool on_segment(point a, point b, point c) {
	if (min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) &&
		min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y))
		return true;
	return false;
}

bool segments_intersect(point a, point b, point c, point d) {
	int d1 = direction(c, d, a);
	int d2 = direction(c, d, b);
	int d3 = direction(a, b, c);
	int d4 = direction(a, b, d);
	if (d1 * d2 < 0 && d3 * d4 < 0)
		return true;
	if (d1 == 0 && on_segment(c, d, a))
		return true;
	if (d2 == 0 && on_segment(c, d, b))
		return true;
	if (d3 == 0 && on_segment(a, b, c))
		return true;
	if (d4 == 0 && on_segment(a, b, d))
		return true;
	return false;
}

int main() {
	point p1, p2, p3, p4;

	cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

	bool f = segments_intersect(p1, p2, p3, p4);

	if (f) {
		cout << "Yes" << '\n';
	} else {
		cout << "No" << '\n';
	}

	return 0;
}