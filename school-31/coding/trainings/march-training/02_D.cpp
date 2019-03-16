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
const double Pi = acos(-1.0);
const double eu = exp(1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

vector<long long> d, e;
vector< vector<long long> > t, v;

int main() {
	freopen("post.in", "r", stdin);
	freopen("post.out", "w", stdout);
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	d.resize(n + 1);
	e.resize(n + 1);
	t.resize(n + 1);
	v.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> d[i] >> e[i];
		t[i].resize(e[i] + 1);
		v[i].resize(e[i]);
		t[i][0] = 0;
		t[i][e[i]] = bInf;
		for (int j = 1; j < e[i]; ++j) {
			cin >> t[i][j];
		}
		for (int j = 0; j < e[i]; ++j) {
			cin >> v[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		cerr << d[i] << " " << e[i] << "\nt = ";
		for (int j = 0; j <= e[i]; ++j) {
			cerr << t[i][j] << " ";
		}
		cerr << "\nv = ";
		for (int j = 0; j < e[i]; ++j) {
			cerr << v[i][j] << " ";
		}
		cerr << "\n";
	}
	cerr << "\n";


	return 0;
}
