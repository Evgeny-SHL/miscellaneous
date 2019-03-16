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
const int None = (int)(1e9 + 7);
const double Pi = acos(-1.0);
const double Eu = exp(1.0);

vector<int> road;

int main() {
	srand(time(NULL));
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	cout << fixed;
	cout.precision(9);
	int n, q, p, t;
	int diff = 0;
	cin >> n;
	road.resize(n + 2);
	road[0] = None;
	road[n + 1] = None;
	for (int i = 1; i <= n; ++i) {
		cin >> road[i];
		if (road[i] != road[i - 1]) {
			++diff;
		}
	}
	cin >> q;
	for (int query = 1; query <= q; ++query) {
		cin >> p >> t;
		if (road[p] == t) {
			cout << diff << "\n";
			continue;
		}
		if (road[p - 1] == road[p] && road[p] == road[p + 1]) {
			road[p] = t;
			diff += 2;
		} else if (road[p - 1] == road[p] && road[p] != road[p + 1]) {
			if (road[p + 1] == t) {
				road[p] = t;
			} else {
				road[p] = t;
				diff += 1;
			}
		} else if (road[p - 1] != road[p] && road[p] == road[p + 1]) {
			if (road[p - 1] == t) {
				road[p] = t;
			} else {
				road[p] = t;
				diff += 1;
			}
		} else if (road[p - 1] != road[p] && road[p] != road[p + 1]) {
			if (road[p - 1] == t && road[p + 1] == t) {
				road[p] = t;
				diff -= 2;
			} else if (road[p - 1] == t && road[p + 1] != t) {
				road[p] = t;
				diff -= 1;
			} else if (road[p - 1] != t && road[p + 1] == t) {
				road[p] = t;
				diff -= 1;
			} else {
				road[p] = t;
			}
		}
		cout << diff << "\n";
	}
    return 0;
}
