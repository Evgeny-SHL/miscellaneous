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

bool burr(int n, int d) {
	while (n > 0) {
		if (n % 10 == d) {
			return true;
		}
		n /= 10;
	}
	return false;
}

int main() {
	freopen("burr.in", "r", stdin);
	freopen("burr.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	++n;
	while (burr(n, 3) || burr(n, 4)) {
		++n;
	}
	cout << n;


	return 0;
}
