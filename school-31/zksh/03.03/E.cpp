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

const pair<int, int> None = make_pair(0, 0);

vector<int> a;
vector< pair<int, int> > ans;
int Max;

void precalc(int cur, int l, int r, int n) {
	do {
		ans[cur] = make_pair(l, r);
		if (a[l] == 2) {
			l += 1;
		} else if (a[r] == 2) {
			r -= 1;
		} else {
			l += 1;
			r -= 1;
		}
		cur -= 2;
		if (cur < 1 || l > n || r < 1) {
			return;
		}
	} while(true);
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "r", stdout);
#endif
	int n, m, k;
	int lst, frt;
	string seq;
	cin >> n >> m;
	cin >> seq;
	Max = 0;
	a.resize(n + 1);
	lst = 0;
	frt = n + 1;
	for (int i = 1; i <= n; ++i) {
		a[i] = (int)(seq[i - 1] - '0');
		Max += a[i];
		if (a[i] == 1) {
			lst = max(i, lst);
			frt = min(i, frt);
		}
	}
    ans.assign(Max + 1, None);
	precalc(Max, 1, n, n);
	if (n - lst <= frt - 1) {
		int p = Max;
		for (int i = n; i >= lst; --i) {
			p -= a[i];
		}
		precalc(p, 1, lst - 1, n);
	} else {
		int p = Max;
		for (int i = 1; i <= frt; ++i) {
			p -= a[i];
		}
		precalc(p, frt + 1, n, n);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &k);
	//	cin >> k;
		if (k <= Max && ans[k] != None) {
			printf("%d %d\n", ans[k].first, ans[k].second);
		//	cout << ans[k].first << " " << ans[k].second << "\n";
		} else {
			printf("NO\n");
		//	cout << "NO\n";
		}
	}
	return 0;
}