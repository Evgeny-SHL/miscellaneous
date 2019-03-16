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

struct participant {
	int year, pnts, ind;
	participant(int p1 = 0, int p2 = 0, int p3 = 0) {
		year = p1;
		pnts = p2;
		ind = p3;
	}
};

bool comp(participant a, participant b) {
	return (a.pnts > b.pnts);
}

vector<participant> part;
vector<int> cnt4, cnt5, cnt6;

int func(int m94, int m95, int m96, int a, int b, int c) {
	return abs(a - m94) + abs(b - m95) + abs(c - m96);
}

int main() {
	freopen("school.in", "r", stdin);
	freopen("school.out", "w", stdout);

	int k, a, b, c, n, best;
	int im94, im95, im96;

	scanf("%d", &k);
	for (int t = 1; t <= k; ++t) {
		part.clear();
		cnt4.clear();
		cnt5.clear();
		cnt6.clear();
		scanf("%d %d %d", &a, &b, &c);
		scanf("%d", &n);
		part.resize(n + 1);
		for (int i = 1; i <= n; ++i) {
			scanf("%d %d", &part[i].year, &part[i].pnts);
			part[i].ind = i;
		}
		sort(part.begin() + 1, part.end(), comp);
		cnt4.assign(n + 1, 0);
		cnt5.assign(n + 1, 0);
		cnt6.assign(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			cnt4[i] = cnt4[i - 1];
			cnt5[i] = cnt5[i - 1];
			cnt6[i] = cnt6[i - 1];
			if (part[i].year == 1994) {
				++cnt4[i];
			} else if (part[i].year == 1995) {
				++cnt5[i];
			} else {
				++cnt6[i];
			}
		}
		im94 = im95 = im96 = 0;
		best = (int)sInf;
		for (int i = 2; i <= n - 1; ++i) {
			if (part[i].year != 1995) {
				continue;
			}
			for (int p = 1; p <= i - 1; ++p) {
				if (part[p].year != 1994) {
					continue;
				}
				for (int q = i + 1; q <= n; ++q) {
					if (part[q].year != 1996) {
						continue;
					}
					int cur = func(cnt4[p], cnt5[i], cnt6[q], a , b, c);
					if (cnt4[p] + cnt5[i] + cnt6[q] == a + b + c && cur < best) {
						best = cur;
						im94 = p;
						im95 = i;
						im96 = q;
					}
				}
			}
		}
		if (cnt4[im94] == 0 || cnt5[im95] == 0 || cnt6[im96] == 0 ||
			cnt4[im94] + cnt5[im95] + cnt6[im96] != a + b + c ||
			im94 >= im95 || im95 >= im96 || im94 >= im96) {
			printf("-1\n");
		} else {
			best = func(cnt4[im94], cnt5[im95], cnt6[im96], a, b, c);
			printf("%d %d %d %d\n", best, cnt4[im94], cnt5[im95], cnt6[im96]);
		}
	}

	return 0;
}
