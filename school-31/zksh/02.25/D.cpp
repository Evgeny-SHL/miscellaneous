#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const int pl = 0;
const int pr = 1;

const long long Inf = (long long)1e18;
vector<long long> prvx, nxt, prv;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int n;
	long long l, r;

	cin >> n;

	prvx.assign(2, 1);
	prv.assign(2, 0);
	nxt.assign(2, Inf);
	long long curd, curx;
	for (int i = 1; i <= n + 1; ++i) {
		if (i > n) {
			l = r = n;
		} else {
			cin >> l >> r;
		}
		for (int p = 0; p <= 1; ++p) {
			curd = prv[p] + 1;
			curx = prvx[p];
			if (curx <= l) {
				nxt[pl] = min(nxt[pl], curd + (r - curx) + (r - l));
				nxt[pr] = min(nxt[pr], curd + (r - curx));
			} else if (curx >= r) {
				nxt[pl] = min(nxt[pl], curd + (curx - l));
				nxt[pr] = min(nxt[pr], curd + (curx - l) + (r - l));
			} else {
				nxt[pr] = min(nxt[pr], curd + (curx - l) + (r - l));
				nxt[pl] = min(nxt[pl], curd + (r - curx) + (r - l));
			}
		}
		prvx[0] = l;
		prvx[1] = r;
		prv = nxt;
		nxt[0] = nxt[1] = Inf;
	}

	cout << prv[0] - 2 << "\n";

	return 0;
}