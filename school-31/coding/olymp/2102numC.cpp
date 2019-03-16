#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct point {
	int x, y;
	point(int p1 = 0, int p2 = 0) {
		x = p1;
		y = p2;
	}
};

struct crd {
	int c, cnt;
	crd(int p1 = 0, int p2 = 0) {
		c = p1;
		cnt = p2;
	}
};

bool comp(crd x, crd y) {
	return (x.cnt > y.cnt || x.cnt == y.cnt && x.c > y.c);
}

bool good(int x, int y, int x1, int y1, int x2, int y2) {
	if ((x == x1 || x == x2) && min(y1, y2) <= y && y <= max(y1, y2)) {
		return true;
	}
	if ((y == y1 || y == y2) && min(x1, x2) <= x && x <= max(x1, x2)) {
		return true;
	}
	return false;
}

vector<point> p;
vector<crd> ax, ay;
map<int, int> px, py;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int Max = (int)1e9;

int main() {
	int n;
	int x, y;

	fin >> n;

	p.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		fin >> x >> y;
		if (px.find(x) == px.end()) {
			px[x] = 1;
		} else {
			px[x]++;
		}
		if (py.find(y) == py.end()) {
			py[y] = 1;
		} else {
			py[y]++;
		}
		p[i] = point(x, y);
	}
	px[Max + 1] = 0;
	py[Max + 1] = 0;

	int x1, x2;
	int y1, y2;
	int cnt;

	for (map<int, int>::iterator it = px.begin(); it != px.end(); ++it) {
		x = it->first;
		cnt = it->second;
		ax.push_back(crd(x, cnt));
	}
	for (map<int, int>::iterator it = py.begin(); it != py.end(); ++it) {
		y = it->first;
		cnt = it->second;
		ay.push_back(crd(y, cnt));
	}
	sort(ax.begin(), ax.end(), comp);
	sort(ay.begin(), ay.end(), comp);

	x1 = ax[0].c;
	x2 = ax[1].c;
	y1 = ay[0].c;
	y2 = ay[1].c;
	for (int i = 2; i < (int)ax.size(); ++i) {
		if (ax[i].cnt == px[x2] && abs(ax[i].c - x1) > abs(x2 - x1)) {
			x2 = ax[i].c;
		}
	}
	for (int i = 2; i < (int)ay.size(); ++i) {
		if (ay[i].cnt == py[y2] && abs(ay[i].c - y1) > abs(y2 - y1)) {
			y2 = ay[i].c;
		}
	}

	cout << x1 << " " << x2 << " " << y1 << " " << y2 << "\n";

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (good(p[i].x, p[i].y, x1, y1, x2, y2)) {
			cout << p[i].x << " " << p[i].y << "\n";
			++ans;
		}
	}

	cout << ans << "\n";
	fout << ans << "\n";

	return 0;
}
