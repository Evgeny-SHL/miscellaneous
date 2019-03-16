#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

multiset< pair<pair<string, string>, int> > best;

int main() {
	string fam, nam;
	int a, b, c, sum, k;
	best.clear();
	k = 0;
	while (!cin.eof()) {
		cin >> nam >> fam >> a >> b >> c;
		if (cin.eof()) {
			break;
		}
		sum = a + b + c;
		if (k == 0 || sum > best.begin()->second) {
			best.clear();
			best.insert(make_pair(make_pair(fam, nam), sum));
			k = 1;
		} else if (sum == best.begin()->second) {
			best.insert(make_pair(make_pair(fam, nam), sum));
			++k;
		}
	}
	cout << k << "\n";
	for (set< pair<pair<string, string>, int> >::iterator it = best.begin(); it != best.end(); ++it) {
		cout << it->first.second << " " << it->first.first << " " << it->second << "\n";
	}
	return 0;
}