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
#include <cmath>
#include <algorithm>
#include <cassert>
#include <ctime>
using namespace std;

const int Inf = 1e9 + 7;
const double Eps = (double)(1e-9);
const int None = -1;
const double Eur = exp(1.0);
const double Pi = acos(-1.0);

vector< vector<long long> > crd, dp;
vector<long long> val;

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif // DEBUG
	srand(time(0));
	cout << fixed;
	cout.precision(9);

	for (int x = 3; x <= 1000; ++x) {
		for (int y = 5; y <= 1000; ++y) {
			if ((x + 2) * (y + 1) == (y * y + 3 * y) && (2 * x + 1) * (y + 2) == 3 * y * y + 4 * y + 4) {
				cout << x << " " << y << "\n";
			} else if ((x + 2) * (y + 1) == (y * y + 3 * y)) {
				cout << x << " " << y << " one\n";
			} else if ((2 * x + 1) * (y + 2) == 3 * y * y + 4 * y + 4) {
				cout << x << " " << y << " two\n";
			}
		}
	}
	cout << "end\n";

	return 0;
}