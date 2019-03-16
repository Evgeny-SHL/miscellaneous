#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

vector<int> cnt;

int main() {
	int n, m;
	cin >> n >> m;
	int tin, tout;
	cnt.assign(n + 2, 0);
	for (int i = 1; i <= m; ++i) {
		string s;
		cin >> s >> s >> tin >> tout;
		cnt[tin]++;
		cnt[tout]--;
	}
	int a = 2000;
	for (int i = 1; i < n; ++i) {
		cnt[i] = cnt[i - 1] + cnt[i];
		a = min(a, cnt[i]);
	}
	for (int i = 1; i < n; ++i) {
		if (cnt[i] == a) {
			cout << i << "-" << (i + 1) << "\n";
		}
	}
	return 0;
}