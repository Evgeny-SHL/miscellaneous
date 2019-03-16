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
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	double a, b, c;
	cin >> a >> b >> c;

	double r0;
	if (a + b + c <= 2 * max(a, max(b, c))) {
		r0 = (double)max(a, max(b, c)) / 2.0;
	} else {
		double p = 0.5 * (a + b + c);
		double s = sqrt(p * (p - a) * (p - b) * (p - c));
		r0 = (a * b * c) / (4.0 * s);
	}

    double r1, r2, r3;
    r1 = sqrt(a * a + b * b) / 2.0;
    if (2 * r1 < c) {
		r1 = (double)sInf;
    }
    r2 = sqrt(b * b + c * c) / 2.0;
    if (2 * r2 < a) {
		r2 = (double)sInf;
    }
    r3 = sqrt(c * c + a * a) / 2.0;
    if (2 * r3 < b) {
		r3 = (double)sInf;
    }

	cout << min(min(r0, r1), min(r1, r2)) << "\n";

	return 0;
}
