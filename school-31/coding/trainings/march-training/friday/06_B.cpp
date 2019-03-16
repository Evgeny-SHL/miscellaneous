#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;

const double Eps = 1e-12;
const long long bInf = (long long)(1e18 + 3);
const long long sInf = (long long)(1e9 + 7);
const int None = -1;
const double Pi = acos(-1.0);
const double eu = exp(1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

vector<double> x, v;
unordered_set<double> t;

int main() {
	freopen("bicycle.in", "r", stdin);
	freopen("bicycle.out", "w", stdout);
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n;
	double tbest, lbest, tp, xmin, xmax, x1, mt1, mt2, curx, curl, curt, ad1, ad2;
	double lt, rt;

	cin >> n;
	x.resize(n + 1);
	v.resize(n + 1);
	xmax = 0.0;
	xmin = (double)sInf;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> v[i];
		xmin = min(xmin, x[i]);
		xmax = max(xmax, x[i]);
	}
	lt = 0.0;
	rt = (double)sInf;
	tbest = 0.0;
	lbest = (double)bInf;
	for (int t = 1; t <= 200; ++t) {
		mt1 = lt + (rt - lt) / 3.0;
		mt2 = rt - (rt - lt) / 3.0;
	//	cerr << lt << " " << mt1 << " " << mt2 << " " << rt << "\n";
		xmin = (double)bInf;
		xmax = 0.0;
		for (int i = 1; i <= n; ++i) {
			curx = x[i] + mt1 * v[i];
			if (curx > xmax + Eps) {
				xmax = curx;
			}
			if (curx < xmin - Eps) {
				xmin = curx;
			}
		}
		ad1 = xmax - xmin;
		xmin = (double)bInf;
		xmax = 0.0;
		for (int i = 1; i <= n; ++i) {
			curx = x[i] + mt2 * v[i];
			if (curx > xmax + Eps) {
				xmax = curx;
			}
			if (curx < xmin - Eps) {
				xmin = curx;
			}
		}
		ad2 = xmax - xmin;
		curt = 0.0;
		curl = 0.0;
		if (ad1 < ad2 - Eps) {
			curt = mt1;
			curl = ad1;
			rt = mt2;
		} else {
			curt = mt2,
			curl = ad2;
			lt = mt1;
		}
		if (curl < lbest + Eps) {
			tbest = curt;
			lbest = curl;
		}
	}
	/*for (int i = 1; i <= n - 1; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (v[i] != v[j]) {
				tp = (x[i] - x[j]) / (v[j] - v[i]);

				if (tp > Eps) {
					t.insert(tp);
				}
			}
		}
	}
	tbest = 0.0;
	lbest = xmax - xmin;
	t.insert(0.0);
	for (auto it = t.begin(); it != t.end(); ++it) {
		tp = *it;
	//	cout << tp << ": ";
		xmax = 0.0;
		xmin = (double)bInf;
		for (int i = 1; i <= n; ++i) {
			x1 = x[i] + tp * v[i];
		//	cout << x1 << " ";
			xmin = min(x1, xmin);
			xmax = max(x1, xmax);
		}
	//	cout << "\n";
		if (xmax - xmin < lbest) {
			tbest = tp;
			lbest = xmax - xmin;
		}
	}*/
	cout << tbest << " " << lbest << "\n";

	return 0;
}
