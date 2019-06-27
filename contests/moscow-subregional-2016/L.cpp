#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <cassert>
using namespace std;

int main() {
	std::vector<bool> sign;
	std::vector<int> t;
	std::vector<int> pl;
	std::vector<int> mn;
	//std::vector<double> st;
	int n;
	cin >> n;
	char c;
	sign.resize(2 * n + 1);
	pl.assign(2 * n + 1, 0);
	mn.assign(2 * n + 1, 0);
	t.resize(2 * n + 1);
	for (int i = 1; i <= 2*n; ++i) {
		cin >> c >> t[i];
		sign[i] = (c == '+');
		pl[i] = pl[i - 1];
		mn[i] = mn[i - 1];
		if(sign[i]) {
			pl[i]++;
		} else {
			mn[i]++;
		}
		/**/
		//st[i] = 1.0 * t[i] * pow(2.0, -pl[i - 1] + mn[i - 1] );
	}
	std::vector<double> ans;
	ans.assign(2 * n + 1, 0.0);
	double ps = 0.0;
	for (int i = 1; i <= 2 * n; ++i) {
	//	cout << sign[i] << " " << pl[i] << " " << mn[i] << " " << st[i] << endl;
	}
	vector<double> r(2 * n + 1, 0);
	for (int i = 2 * n; i >= 1; --i) {
		if (!sign[i]) {
		//	cerr << "(";
			r[i] = 1.0 / (pl[i - 1] - mn[i - 1]);
		//	cerr << ")";
		}
	}
	int k1 = 2 * n;
	int k2 = 2 * n + 1;
	double q = 1.0;
	//vector<double> p(2 * n + 1, 0.0);
	vector<double> st(2 * n + 2, 0.0);
	// k1 = k2 = -
	while (k1 >= 1) {
	//	double st = 0.0;
		while (!sign[k1]) {
			--k1;
		}
		// k1 = +
		double np = 1.0;
		// k1+1 = -
		for (int i = k1 + 1; i <= k2 - 1; ++i) {
		//	p[i] = r[i] * q;
			st[k1] += r[i] */* q */ np * t[i];
			np *= (1.0 - r[i]);
		}
		//double res = st - t[k1];
		// k2 = -
		// k2 = -
		q = np;
		double res = q * st[k2] + st[k1];
		while (sign[k1]) {
			k2 = k1;
			st[k1] = res;
//			ans[k1] = st - t[k1];
			--k1;
		}
		// k1 = -
	//	k2 = k1 + 1;
		// k2 = -
	//	q = np;
	}
	for (int i = 1; i <= 2 * n; ++i) {
		if (sign[i]) {
			cout.precision(9);
			cout <</* cout.precision(9) <<*/ fixed << st[i] - t[i] << endl;
		}
	}

	return 0;
}