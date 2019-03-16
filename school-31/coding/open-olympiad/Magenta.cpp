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
const long long Inf = (long long)(1e18);
const int None = -1;
const double Pi = acos(-1.0);
const double Eu = exp(1.0);

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, 1};
const char ar[4] = {'U', 'R', 'D', 'R'};
const char ar1[4] = {'U', 'R', 'U', 'L'};

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	srand(time(0));
	ios_base::sync_with_stdio(0);
	cout << fixed;
	cout.precision(9);

	char ans;
	int arrow = 0;
	int dt = 0;
	int p = 0;
	int k = 0;
	while (k < 7000) {
		if (p == 0 && arrow % 2 == 0) {
			++dt;
			p = dt;
		} else if (p == 0) {
			p = 1;
		}
		printf("%c\n", ar[arrow]);
		fflush(stdout);
		scanf("%c", &ans);
		if (ans == 'E' || ans == 'Y') {
			return 0;
		}
		--p;
		if (p == 0) {
			arrow = (arrow + 1) % 4;
		}
		++k;
	}
	int arrow1 = 0;
	int p1 = 0;
	int dt1 = 0;
	while (true) {
		if (p1 == 0 && arrow1 % 2 != 0) {
			++dt1;
			p1 = dt1;
		} else if (p1 == 0) {
			p1 = 1;
		}
		printf("%c\n", ar1[arrow1]);
		fflush(stdout);
		scanf("%c", &ans);
		if (ans == 'E' || ans == 'Y') {
			return 0;
		}
		--p1;
		if (p1 == 0) {
			arrow1 = (arrow1 + 1) % 4;
		}
	}
	return 0;
}
