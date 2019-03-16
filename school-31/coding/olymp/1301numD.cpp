#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream fin("light.in");
ofstream fout("light.out");

struct point {
	double x, y;
	point(double a = 0.0, double b = 0.0) {
		x = a;
		y = b;
	}
};

struct vect {
	double x, y;
	vect(double p = 0.0, double q = 0.0) {
		x = p;
		y = q;
	}
	vect(point pt1, point pt2) {
		x = pt2.x - pt1.x;
		y = pt2.y - pt1.y;
	}
};

struct line {
	double a, b, c;
	line(double u, double v, double w) {
		a = u;
		b = v;
		c = w;
	}
	line(point pt1, point pt2) {
		a = pt2.y - pt1.y;
		b = pt1.x - pt2.x;
		c = pt1.y * (pt2.x - pt1.x) - pt1.x * (pt2.y - pt1.y);
	}
	line(point pt, vect p) {
		a = p.y;
		b = -p.x;
		c = pt.y * p.x - pt.x * p.y;
	}
};

double vm(vect a, vect b) {
	return (a.x * b.y - a.y * b.x);
}

vect n_vect(line l) {
	return vect(l.b, -l.a);
}

bool sgmntvsl(point a, point b, vect p) {
	return (vc() * vc());
}

bool plgnvsl() {
	for (int i = 0; i < n; ++i) {

	}
	return false;
}

vector<point> vpt;

int main() {
	double x, y, v;
	point pt0, pt1, pt2, pt;
	int n;

	fin >> x >> y >> v;
	fin >> n;

	pt0 = point(0.0, 0.0);
	pt = point(x, y);

	fin >> x >> y;
	vpt.resize(n);
	vpt[0] = point(x, y);
	pt1 = point(x, y);
	pt2 = point(x, y);
	for (int i = 1; i < n; ++i) {
		fin >> x >> y;
		point pti = point(x, y);
		if (vm(vect(pti, pt0), vect(pt1, pt0)) > 0) {
			pt1 = pti;
		}
		if (vm(vect(pti, pt0), vect(pt2, pt0)) < 0) {
			pt2 = pti;
		}
		vpt[i] = pti;
	}

	double ls1, ls2;
	ls1 = 0.0;
	while (true) {
		line l1 = line(pt0, pt1);
		line lp = line(pt, n_vect(l1));
		bool vs = plgnvsl
	}

	return 0;
}
