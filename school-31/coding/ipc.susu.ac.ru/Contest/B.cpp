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
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	srand(time(0));
	cout << fixed;
	cout.precision(2);
	ios_base::sync_with_stdio(0);

	string s;
	while (true) {
		cin >> s;
		if (s == "0") {
			break;

		}
		int sum = 0;
		for (int i = 0; i < (int)s.length(); ++i) {
			sum = sum += s[i] - '0';
		}
		while (sum > 9) {
			int old = sum;
			sum = 0;
			while (old > 0) {
				sum = sum + old % 10;
				old /= 10;
			}
		}
		cout << sum << "\n";
	}

	return 0;
}
