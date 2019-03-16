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

vector<pair<int, int>> a;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	srand(time(0));
	cout << fixed;
	cout.precision(2);
	ios_base::sync_with_stdio(0);

    int n, p;
    cin >> n;
	a.assign(n, make_pair(0, 0));
	for (int i = 0; i < n; ++i) {
		cin >> p;
		a[i].second = p;
		while (p % 10 == 0) {
            --a[i].first;
            p /= 10;
		}
	}
	sort(a.begin(), a.end());
	cout << a[0].second << "\n";

	return 0;
}
