#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector< pair<int, string> > prt;

int main() {
	int n, m;
	cin >> n >> m;
	string a, b;
	int d;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		int sum = 0;
		for (int i = 0; i < m; ++i) {
			cin >> d;
			sum += d;
		}
		prt.push_back(make_pair(-sum, a + " " + b));
	}
	sort(prt.begin(), prt.end());
	int cur = 0;
	int p = 10000000;
	for (int i = 0; i < n; ++i) {
		if (-prt[i].first < p) {
			cur += 1;
		}
		cout << prt[i].second << " " << -prt[i].first << " " << cur << "\n";
		p = -prt[i].first;
	}
	return 0;
}