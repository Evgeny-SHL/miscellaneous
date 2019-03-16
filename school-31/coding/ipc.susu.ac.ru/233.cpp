#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> dbal;

int main() {
	int n, s, d;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s >> d;
		if (dbal.find(s) == dbal.end()) {
			dbal[s] = 1;
		} else {
			++dbal[s];
		}
		if (dbal.find(s + d) == dbal.end()) {
			dbal[s + d] = -1;
		} else {
			--dbal[s + d];
		}
	}

	int bal = 0;
	int ans = 0;
	for (auto it = dbal.begin(); it != dbal.end(); ++it) {
		bal += it->second;
		ans = max(ans, bal);
	}

	cout << ans << "\n";

	return 0;
}