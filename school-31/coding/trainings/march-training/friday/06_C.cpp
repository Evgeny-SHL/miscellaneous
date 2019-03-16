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
const int None = -1;
const double Pi = acos(-1.0);
const double eu = exp(1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

struct center {
	double r, c;
	double len;
	int ind;
	center(double param1 = 0.0, double param2 = 0.0, double param3 = 0.0, int param4 = 0) {
		r = param1;
		c = param2;
		len = param3;
		ind = param4;
	}
};

struct segment {
	double r1, c1, r2, c2;
	segment(double param1 = 0.0, double param2 = 0.0, double param3 = 0.0, double param4 = 0.0) {
		r1 = param1;
		c1 = param2;
		r2 = param3;
		c2 = param4;
	}
};

bool operator<(center x, center y) {
	return (x.len < y.len);
}

vector<center> pt;
multiset<center> our, upd;
vector<segment> sg;
vector<long long> ans;

double dist(segment a, center m) {
	if (a.c1 == a.c2 && min(a.r1, a.r2) <= m.r && m.r <= max(a.r1, a.r2) && m.c != a.c1) {
	//	cerr <<" a ";
		return abs(a.c1 - m.c);

	}
	if (a.r1 == a.r2 && min(a.c1, a.c2) <= m.c && m.c <= max(a.c1, a.c2) && m.r != a.r1) {
	//	cerr << " b ";
		return abs(a.r1 - m.r);

	}
//	cerr << " c ";
	return (double)sInf;
}

int main() {
	freopen("garden.in", "r", stdin);
	freopen("garden.out", "w", stdout);
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	long long w, h;
	int n, ind, ib;
	double r, c, d;
	center best;

	cin >> w >> h >> n;
	pt.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> c >> r;
		pt[i] = center(r, c, min(min(r, h - r), min(c, w - c)), i);
		our.insert(pt[i]);
	}
	sg.push_back(segment(0, 0, 0, w));
	sg.push_back(segment(0, 0, h, 0));
	sg.push_back(segment(h, w, 0, w));
	sg.push_back(segment(h, w, h, 0));
	ans.assign(n + 1, 0);
	while (our.size() > 0) {
		best = *our.begin();
		our.erase(our.begin());
		ib = best.ind;
		pt[ib].len = best.len;
	//	cerr << ib << "\n";
		ans[ib] = (long long)(2.0 * pt[ib].len);
	//	cerr << pt[ib].len << "\n";
	//	cerr << pt[ib].r << " " << pt[ib].c << "\n";
		sg[0] = segment(pt[ib].r + pt[ib].len, pt[ib].c + pt[ib].len, pt[ib].r + pt[ib].len, pt[ib].c - pt[ib].len);
		sg[1] = segment(pt[ib].r + pt[ib].len, pt[ib].c - pt[ib].len, pt[ib].r - pt[ib].len, pt[ib].c - pt[ib].len);
		sg[2] = segment(pt[ib].r - pt[ib].len, pt[ib].c - pt[ib].len, pt[ib].r - pt[ib].len, pt[ib].c + pt[ib].len);
		sg[3] = segment(pt[ib].r - pt[ib].len, pt[ib].c + pt[ib].len, pt[ib].r + pt[ib].len, pt[ib].c + pt[ib].len);
	//	for (int t = 0; t < 4; ++t) {
	//		cerr << sg[t].r1 << " " << sg[t].c1 << " " << sg[t].r2 << " " << sg[t].c2 << "\n";
	//	}
		upd.clear();
		for (auto it = our.begin(); it != our.end(); ++it) {
			center cur = *it;
		//	cerr << cur.ind << " " << cur.len << " ( ";
			for (int t = 0; t < 4; ++t) {
				d = dist(sg[t], cur);
			//	cerr << d << " ";
				cur.len = min(cur.len, d);
			}
		//	cerr << ") " << cur.len << "\n";
			upd.insert(cur);
		}
	//	cerr << "\n";
		our.clear();
		our = upd;
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << "\n";
	}

	return 0;
}

