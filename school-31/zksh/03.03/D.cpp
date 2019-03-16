#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cmath>
using namespace std;

const int Inf = (int)(1e9 + 7);
vector<int> h, blk, rgt, lft, cur, imn, ans;
int Len, Amt;

void init(int n) {
	Len = (int)sqrt(n);
	Amt = (n - 1) / Len + 1;
	blk.resize(n);
	cur.resize(Amt);
	lft.assign(Amt, n - 1);
	rgt.assign(Amt, 0);
	imn.resize(Amt);
	ans.assign(Amt, 0);
	for (int i = 0; i < n; ++i) {
		int j = i / Len;
		blk[i] = j;
		lft[j] = min(i, lft[j]);
		rgt[j] = max(i, rgt[j]);
		cur[j] = -1;
		imn[j] = lft[j];
	}
}

void upd(int l, int r, int c) {
	int p = blk[l];
	int q = blk[r];
	if (p == q) {
		for (int i = lft[p]; i <= rgt[p]; ++i) {
			h[i] = max(h[i], cur[p]);
		}
		cur[p] = -1;
		for (int i = l; i <= r; ++i) {
			h[i] = max(h[i], c);
		}
		ans[p] = Inf;
		imn[p] = lft[p];
		for (int i = lft[p]; i <= rgt[p]; ++i) {
			if (h[i] < ans[p]) {
				imn[p] = i;
				ans[p] = h[i];
			}
		}
	} else {
		upd(l, rgt[p], c);
		upd(lft[q], r, c);
		for (int j = p + 1; j <= q - 1; ++j) {
			cur[j] = max(cur[j], c);
			ans[j] = max(ans[j], c);
		}
	}
}

pair<int, int> srh(int l, int r) {
	int p = blk[l];
	int q = blk[r];
	pair<int, int> res, res1, res2;
	if (p == q) {
		if (cur[p] > -1) {
			upd(lft[p], rgt[p], cur[p]);
		}
		res = make_pair(h[l], l);
        for (int i = l; i <= r; ++i) {
			if (h[i] < res.first) {
				res = make_pair(h[i], i);
			}
        }
	} else {
		res1 = srh(l, rgt[p]);
		res2 = srh(lft[q], r);
		if (res1.first < res2.first) {
			res = res1;
		} else {
			res = res2;
		}
		for (int j = p + 1; j <= q - 1; ++j) {
			if (ans[j] < res.first) {
				res = make_pair(ans[j], imn[j]);
			}
		}
	}
	return res;
}

void print(int n) {
	for (int i = 0; i < n; ++i) {
		cout << h[i] << " ";
	}
	cout << "\n";
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "r", stdout);
#endif
	int n, m;
	int l, r, c;
	string event;
	cin >> n >> m;
	h.resize(n);
	for (int i = 0; i < n; ++i) {
		h[i] = 0;
	}
	init(n);
	for (int j = 0; j < m; ++j) {
		cin >> event;
		cin >> l >> r;
		l -= 1;
		r -= 1;
		if (event == "defend") {
			cin >> c;
		//	cout << "!\n";
			upd(l, r, c);
		//	cout << "?\n";
		} else {
			pair<int, int> ans = srh(l, r);
			cout << ans.first << " " << ans.second + 1 << "\n";
		}
	//	print(n);
	}
	return 0;
}