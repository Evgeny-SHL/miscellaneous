#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <ctime>
using namespace std;

const long long bInf = (long long)(1e18 + 3);
const int sInf = (int)(1e9 + 7);
const double Eps = (double)(1e-9);
const int None = -1;
const double Eur = exp(1.0);
const double Pi = acos(-1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	long long q, n, p, k, ps;

	cin >> q;
	for (int i = 1; i <= q; ++i) {
		cin >> n >> p;
		ps = 1;
		while (ps < n) {
			ps *= 2;
		}
		k = 0;
		while (ps > 1) {
			ps /= 2;
			if (n > ps) {
				n -= ps;
				++k;
			}
		}
		cout << k % p << "\n";
	}

	return 0;
}
