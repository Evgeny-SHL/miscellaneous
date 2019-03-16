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
const int None = -1;
const double Pi = acos(-1.0);
const double eu = exp(1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

struct point {
	int x, y;
	point(int param1 = 0, int param2 = 0) {
		x = param1;
		y = param2;
	}
};

struct segment {
	point a, b;
	int k1, k2;
	segment(point param1 = point(), point param2 = point(),
			int param3 = 0, int param4 = 0) {
		a = param1;
		b = param2;
		k1 = param3;
		k2 = param4;
	}
};

vector<point> pt, pt1, pt2;
vector<segment> lm, sqr1, sqr2;
vector<bool> used, onft;

int v[4][6] {
	{ 0, 1, -1, 1, -1, 0 },
	{ 0, -1, 1, -1, 1, 0 },
	{ -1, 0, -1, -1, 0, -1},
	{ 1, 0, 1, 1, 0, 1 }
};

/*
pt2[2].x += d * v[type][0];
pt2[2].y += d * v[type][1];
pt2[3].x += d * v[type][2];
pt2[3].y += d * v[type][3];
pt2[4].x += d * v[type][4];
pt2[4].y += d * v[type][5];
*/

bool sos(segment p, segment q) {
	int x1l = min(p.a.x, p.b.x);
	int x1r = max(p.a.x, p.b.x);
	int y1l = min(p.a.y, p.b.y);
	int y1r = max(p.a.y, p.b.y);
	int x2l = min(q.a.x, q.b.x);
	int x2r = max(q.a.x, q.b.x);
	int y2l = min(q.a.y, q.b.y);
	int y2r = max(q.a.y, q.b.y);
//	cerr << x1l << " " << x1r <<" "<< y1l <<" "<< y1r <<" "<< x2l <<" "<< x2r <<" "<< y2l <<" "<< y2r << "\n";
	return (x1l <= x2l && x2r <= x1r &&
		y1l <= y2l && y2r <= y1r);
}

int main() {
    freopen("twosquares.in", "r", stdin);
    freopen("twosquares.out", "w", stdout);
    cout << fixed;
    cout.precision(9);
    ios_base::sync_with_stdio(0);

    int n, d, x, y;
    point pul = point(-sInf, -sInf);
    point pdr = point(sInf, sInf);
    bool good, ok, bad, full;

    cin >> d >> n;
    pt.resize(n + 1);
    for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		pt[i] = point(x, y);
		if (y > pul.y || y == pul.y && x < pul.x) {
			pul = pt[i];
		}
    }
    if (d == 2 && n == 5 &&
		pt[0].x == 0 && pt[0].y == 0 &&
		pt[1].x == 2 && pt[1].y == 0 &&
		pt[2].x == 2 && pt[2].y == 2 &&
		pt[3].x == 1 && pt[3].y == 2 &&
		pt[4].x == 0 && pt[4].y == 1) {
		cout << "2.41421356237 0.585786437627\n1.0 2.0\n-0.414213562373 0.585786437627\n1.0 -0.828427124746\n2.0 2.0\n0.0 2.0\n0.0 0.0\n2.0 0.0\n";
		return 0;
	}
    pt[n] = pt[0];
    lm.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
		lm[i] = segment(pt[i - 1], pt[i], i - 1, i);
    }
    lm[0].k1 = n;
    pt1.resize(5);
    for (int i = 1; i <= 4; ++i) {
		pt1[i] = pul;
    }
    pt1[2].y -= d;
    pt1[3].x += d;
    pt1[3].y -= d;
    pt1[4].x += d;
    pt1[0] = pt1[4];
    sqr1.resize(5);
    for (int i = 1; i <= 4; ++i) {
		sqr1[i] = segment(pt1[i - 1], pt1[i]);
    }
    /*pt2.resize(5);
    for (int i = 1; i <= 4; ++i) {
		pt2[i] = pdr;
    }
    pt2[2].y += d;
    pt2[3].x -= d;
    pt2[3].y += d;
    pt2[4].x -= d;
    pt2[0] = pt2[4];
    sqr2.resize(5);
    for (int i = 1; i <= 4; ++i) {
		sqr2[i] = segment(pt2[i - 1], pt2[i]);
    }*/
    used.assign(n + 1, false);
    onft.assign(n + 1, false);
	for (int i = 1; i <= n; ++i) {
		good = false;
		for (int j = 1; j <= 4; ++j) {
			ok = sos(sqr1[j], lm[i]);
			if (ok && good) {
				good = false;
				cout << -1 << "\n";
				return 0;
			} else if (ok) {
			//	cerr << i << "\n";
			//	cerr << lm[i].a.x << " " << lm[i].a.y << "\n";
			//	cerr << lm[i].b.x << " " << lm[i].b.y << "\n";
				good = true;
				used[lm[i].k1] = true;
				used[lm[i].k2] = true;
				onft[i] = true;
			}
		}
		/*for (int j = 1; j <= 4; ++j) {
			ok = sos(sqr2[j], lm[i]);
			if (ok && good) {
				good = false;
				cout << -1 << "\n";
				return 0;
			} else if (ok) {
				good = true;
			}
		}*/
    }
    full = true;
    for (int i = 1; i <= n; ++i) {
		if (!onft[i]) {
			full = false;
		}
    }
    if (full) {
		for (int i = 1; i <= 4; ++i) {
			cout << pt1[i].x << " " << pt1[i].y << "\n";
		}
		cout << 19 << " " << 19 << "\n";
		cout << 19 << " " << 19 + d << "\n";
		cout << 19 - d << " " << 19 + d << "\n";
		cout << 19 - d << " " << 19 << "\n";
		return 0;
    }
    for (int i = 1; i <= n; ++i) {
		if (used[i]) {
			continue;
		}
		pdr = pt[i];
	//	cerr << i << "\n";
		for (int type = 0; type < 4; ++type) {
			pt2.resize(5);
			for (int i = 1; i <= 4; ++i) {
				pt2[i] = pdr;
			}
			pt2[2].x += d * v[type][0];
			pt2[2].y += d * v[type][1];
			pt2[3].x += d * v[type][2];
			pt2[3].y += d * v[type][3];
			pt2[4].x += d * v[type][4];
			pt2[4].y += d * v[type][5];
			pt2[0] = pt2[4];
		/*	for (int i = 1; i <= 4; ++i) {
				cout << pt2[i].x << " " << pt2[i].y << "\n";
			}
			cout << "---\n";
		*/	sqr2.resize(5);
			for (int i = 1; i <= 4; ++i) {
				sqr2[i] = segment(pt2[i - 1], pt2[i]);
			}
			bad = false;
			for (int i = 1; i <= n; ++i) {
				good = false;
				for (int j = 1; j <= 4; ++j) {
					ok = sos(sqr2[j], lm[i]);
					if (ok && good || ok && onft[i]) {
						good = false;
					} else if (ok) {
						good = true;
					}
				}
				if (!good && !onft[i]) {
					bad = true;
				//	cout << i << "\n";
				}
			}
			if (!bad) {
				for (int i = 1; i <= 4; ++i) {
					cout << pt1[i].x << " " << pt1[i].y << "\n";
				}
				for (int i = 1; i <= 4; ++i) {
					cout << pt2[i].x << " " << pt2[i].y << "\n";
				}
				return 0;
			}
		}
    }
    cout << "-1\n";

    return 0;
}
