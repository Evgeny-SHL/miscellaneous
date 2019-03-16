#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct point {
	int x, y;
	double pol;
};

const double EPS = 10e-6;

int start = 0;
point p[1000+2];
point s[1000+2];
int len = 0;

double lgt(point a, point b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool comp(point a, point b) {
	return (a.pol < b.pol - EPS) || (abs(a.pol - b.pol) < EPS) && (lgt(a, p[start]) < lgt(b, p[start]) + EPS);
}

bool good(point a, point b, point c) {
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x) > 0;
}

int main() {

	int n;
	cin >> n;

	int len = 0;

	int minx;
	int miny = minx = 10001;
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		if ((p[i].y < miny) || ((p[i].y == miny) && (p[i].x < minx))) {
			start = i;
			miny = p[i].y;
			minx = p[i].x;
		}
	}


	for (int i = 0; i < n; i++) {
		p[i].pol = atan2(p[i].y - miny, p[i].x - minx);
//		cout << p[i].pol << '\n';
	}

	point t;
	t = p[0];
	p[0] = p[start];
	p[start] = t;

	sort(p + 1, p + n, comp);

/*	cout << start << '\n';
	for (int i = 0; i < n; i++)
        cout << p[i].x << " " << p[i].y << '\n';
*/

    s[len++] = p[0];
	s[len++] = p[1];
	for (int i = 2; i < n; i++) {
		while (!good(s[len-2], s[len-1], p[i]) && (len > 1)) {
			len--;
		};
		s[len++] = p[i];
	}
	if (len > 2) s[len++] = s[0];

    double sum = 0;
	for (int i = 0; i < len-1; i++) {
//		cout << p[i].x << '\n';
		sum += sqrt((s[i].x-s[i+1].x)*(s[i].x-s[i+1].x)+(s[i].y-s[i+1].y)*(s[i].y-s[i+1].y));
	}

    printf("%.1lf",sum);

	return 0;
}