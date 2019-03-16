#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

vector<int> cnt;
vector< pair<int, int> > t;

int main() {
	int n, m;
	cnt.assign(13, 0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> m;
		++cnt[m];
	}
	for (int i = 1; i <= 12; ++i) {
		if (cnt[i] > 0) {
			t.push_back(make_pair(cnt[i], i));
		}
	}
	sort(t.begin(), t.end());
	for (int i = 0; i < (int)t.size(); ++i) {
		cout << t[i].second << " " << t[i].first << "\n";
	}
	return 0;
}