#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <cmath>
#include <random>
#include <ctime>
#include <cassert>
using namespace std;

const double Eps = (double)(1e-9);
const double Inf = (double)(1e18);
const int None = -1;
const double Pi = acos(-1.0);
const double Eu = exp(1.0);

vector< vector<double> > brr;
vector<double> x, y, z;
deque<int> s;
int h;

bool comp(vector<double> a, vector<double> b) {
	return (a[2] < b[2] - Eps);
}

bool bad(int param, int u, int v, int w) {
	double cp = (x[v] - x[u]) * (y[w] - y[u]) - (y[v] - y[u]) * (x[w] - x[u]);
	return (param == 1) ? cp > -Eps : cp < Eps;
}

double calc_brr(int a, int b) {
	if (y[a] == y[b]) {
		return Inf;
	} else {
		double kinv = (x[b] - x[a]) / (y[b] - y[a]);
		return x[a] + kinv * (h - y[a]);
	}
}

void find_scope(int ind, int l, int r, int d, int p) {
	int len, cur;
	double crd;
	s.clear();
	cur = p;
	s.push_back(l);
	if (z[l] == 1) {
		cur += d;
	}
	s.push_back(l + d);
	if (z[l + d] == 1) {
		cur += d;
	}
	len = 2;
	for (int i = l + 2 * d; i != r + d; i += d) {
		while (len > 1 && bad(ind, s[len - 2], s[len - 1], i)) {
			s.pop_back();
			--len;
		}
		s.push_back(i);
		++len;
		if (z[i] == 1) {
			crd = calc_brr(s[len - 2], s[len - 1]);
			if (Inf - crd > Eps && ((ind == 1) ? crd < x[i] + Eps : crd > x[i] - Eps)) {
				brr[cur][ind] = crd;
			}
			cur += d;
		}
	}
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	srand(time(0));
	ios_base::sync_with_stdio(0);
	cout << fixed;
	cout.precision(9);

    int n, k, ans;
    double prev;
    cin >> n >> h;
    x.resize(n + 1);
    y.resize(n + 1);
    z.resize(n + 1);
    k = 0;
    for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i] >> z[i];
		if (z[i] == 1) {
			++k;
		}
    }
    ans = 0;
    if (n <= 3 && k > 0) {
		ans = 1;
	} else if (n > 3 && k > 0) {
		brr.resize(k + 1);
		for (int i = 1; i <= k; ++i) {
			brr[i].resize(3);
			brr[i][1] = -Inf;
			brr[i][2] = Inf;
		}
		find_scope(1, 1, n, 1, 1);
		find_scope(2, n, 1, -1, k);
		sort(brr.begin() + 1, brr.end(), comp);
		ans = 1;
		prev = brr[1][2];
		for (int i = 1; i <= k; ++i) {
			if (brr[i][1] > prev + Eps) {
				++ans;
				prev = brr[i][2];
			}
		}
    }
    cout << ans << "\n";
	return 0;
}
