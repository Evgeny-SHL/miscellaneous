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

vector<int> a, blk, rgt, lft, cur, del, old;
vector< vector<int> > cnt;
const int Dig = 10;
int Len, Amt;

void init(int n) {
	Len = (int)sqrt(n);
	Amt = (n - 1) / Len + 1;
	blk.resize(n);
	cur.resize(Amt);
	del.resize(Amt);
	lft.assign(Amt, n - 1);
	rgt.assign(Amt, 0);
	cnt.resize(Amt);
	old.assign(Amt, 0);
	for (int j = 0; j < Amt; ++j) {
		cnt[j].assign(Dig, 0);
	}
	for (int i = 0; i < n; ++i) {
		int j = i / Len;
		blk[i] = j;
		lft[j] = min(i, lft[j]);
		rgt[j] = max(i, rgt[j]);
		del[j] = rgt[j] - lft[j] + 1;
		cur[j] += a[i];
		cnt[j][a[i]] += 1;
	}
}

void push(int k) {
	if (old[k] > 0) {
		for (int i = lft[k]; i <= rgt[k]; ++i) {
			a[i] = (a[i] + old[k]) % 10;
		}
		old[k] = 0;
	}
}

void upd(int l, int r) {
	int p = blk[l];
	int q = blk[r];
	if (p == q) {
		push(p);
		int u, v;
		for (int i = l; i <= r; ++i) {
			u = a[i];
			v = (a[i] + 1) % 10;
			cnt[p][u] -= 1;
			cnt[p][v] += 1;
			cur[p] += v - u;
			a[i] = v;
		}
	} else {
		int mem;
		upd(l, rgt[p]);
		upd(lft[q], r);
		for (int j = p + 1; j <= q - 1; ++j) {
			mem = cnt[j][9];
			cur[j] += del[j] - 10 * mem;
			for (int d = Dig - 1; d > 0; --d) {
				cnt[j][d] = cnt[j][d - 1];
			}
			cnt[j][0] = mem;
			old[j] += 1;
		}
	}
}

int sum(int l, int r) {
	int p = blk[l];
	int q = blk[r];
	int res = 0;
	if (p == q) {
		push(p);
		for (int i = l; i <= r; ++i) {
			res += a[i];
		}
	} else {
		res += sum(l, rgt[p]);
		res += sum(lft[q], r);
		for (int j = p + 1; j <= q - 1; ++j) {
			res += cur[j];
		}
	}
	return res;
}

void print(int n) {
	for (int i = 0; i < n; ++i) {
		cout << a[i];
	}
	cout << "\n";
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "r", stdout);
#endif
	int n, m;
	int l, r;
	string seq;
	cin >> n >> m;
	cin >> seq;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		a[i] = (int)(seq[i] - '0');
	}
	init(n);
	for (int j = 0; j < m; ++j) {
	//	for (int j = 0; j < Amt; ++j) {
	//		cout << cur[j] << " ";
	//	}
	//	cout << "\n";
		cin >> l >> r;
		l -= 1;
		r -= 1;
		cout << sum(l, r) << "\n";
		upd(l, r);
	//	print(n);
	}
	return 0;
}