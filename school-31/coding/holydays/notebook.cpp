#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:16777216")

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
	freopen("notebook.in", "r", stdin);
	freopen("notebook.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(3);
	ios_base::sync_with_stdio(0);

	string time;
	int n, x, y;
	cin >> n >> x >> y;
	int prev = 0;
	double z = 1.0;
	for (int i = 0; i < n; ++i) {
		cin >> time;
		int h = 10 * (int)(time[0] - '0') + (int)(time[1] - '0');
		int m = 10 * (int)(time[3] - '0') + (int)(time[4] - '0');
		m += 60 * h;
		double d = m - prev;
		prev = m;
		if (i % 2 == 0) {
			z = min(1.0, z + d / y);
		} else {
			z = max(0.0, z - d / x);
		}
	}
	int m = 23 * 60 + 59;
	double d = m - prev;
	prev = m;
	if (n % 2 == 0) {
		z = min(1.0, z + d / y);
	} else {
		z = max(0.0, z - d / x);
	}
	z *= 100.0;
	cout << z << "\n";

	return 0;
}
