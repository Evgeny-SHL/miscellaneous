#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int Max = (int)(1e9 + 1);

struct point {
	int x, y;
	point(int param1 = 0, int param2 = 0) {
		x = param1;
		y = param2;
	}
};

bool compx(point a, point b) {
	return (a.x < b.x);
}

bool compy(point a, point b) {
	return (a.y < b.y);
}

vector<point> p;
vector< vector<int> > crd, col;
vector<int> sum1, sum2, sufmax;

int main() {
	int n, k, m;
	int prevx, prevy;

	fin >> n;

	p.resize(n + 1);
	for (int i = 0; i < n; ++i) {
		fin >> p[i].x >> p[i].y;
	}
	p[n] = point(Max, Max);
	++n;

	sort(p.begin(), p.end(), compx);
	prevx = -p[0].x;
	p[0].x = 1;
	for (int i = 1; i < n; ++i) {
		if (p[i].x == prevx) {
			p[i].x = p[i - 1].x;
		} else {
			prevx = p[i].x;
			p[i].x = p[i - 1].x + 1;
		}
	}
	k = p[n - 1].x;

	sort(p.begin(), p.end(), compy);
	prevy = -p[0].y;
	p[0].y = 1;
	for (int i = 1; i < n; ++i) {
		if (p[i].y == prevy) {
			p[i].y = p[i - 1].y;
		} else {
			prevy = p[i].y;
			p[i].y = p[i - 1].y + 1;
		}
	}
	m = p[n - 1].y;

	crd.resize(k + 1);
	for (int i = 0; i <= k; ++i) {
		crd[i].assign(m + 1, 0);
	}

	for (int i = 0; i < n; ++i) {
		++crd[p[i].x][p[i].y];
	}
	crd[k][m]--;

	col.resize(m + 1);
	for (int j = 0; j <= m; ++j) {
		col[j].resize(k + 1);
		for (int i = 1; i <= k; ++i) {
			col[j][i] = col[j][i - 1] + crd[i][j];
		}

	}

	/*for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << crd[i][j];
		}
		cout << "\n";
	}
	cout << "\n";*/


	int ans = 0;
	for (int i1 = 1; i1 < k; ++i1) {
		for (int i2 = i1 + 1; i2 <= k; ++i2) {
			sum1.resize(m + 1);
			sum2.resize(m + 1);
		//	cout << i1 << " " << i2 << "\n";
			for (int j = 1; j <= m; ++j) {
				sum1[j] = sum1[j - 1] - (col[j - 1][i2] - col[j - 1][i1 - 1]) +
						crd[i2][j - 1] + crd[i1][j - 1] + (col[j][i2] - col[j][i1 - 1]);
				sum2[j] = sum2[j - 1] - (col[j - 1][i2] - col[j - 1][i1 - 1]) +
						(col[j][i2 - 1] - col[j][i1]);
			}
			sufmax.resize(m + 1);
			sufmax[m] = sum1[m];
			for (int j = m - 1; j >= 1; --j) {
				sufmax[j] = max(sufmax[j + 1], sum1[j]);
			}
			int res = 0;
			for (int j = 1; j < m; ++j) {
				res = max(res, sum2[j] + sufmax[j + 1]);
			}
		//	cout << res << "\n";
			ans = max(res, ans);
		}
	}

	cout << ans << "\n";
	fout << ans << "\n";

	return 0;
}