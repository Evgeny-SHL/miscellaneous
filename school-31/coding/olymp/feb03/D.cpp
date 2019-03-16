#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <deque>
using namespace std;

set<string> ans;
vector<int> curd, b;
vector< vector<int> > num;
int curl;
int dig;
int p[3] = {1, 10, 100};

bool bad(int n, int ind) {
//	cout << n << "\n";
	b.clear();
	do {
		int d = n % 10;
	//	cout << d << "\n";
	//	cout << d << "\n";
		if ((dig | (1 << d)) != dig) {
			return true;
		}
		n /= 10;
		b.push_back(d);
	} while (n > 0);
	num[ind].clear();
	for (int i = (int)b.size() - 1; i >= 0; --i) {
		num[ind].push_back(b[i]);
	}
	return false;
}

bool pal(int l, int r) {
	for (int i = 0; i <= r - l; ++i) {
		if (curd[l + i] != curd[r - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	int a, b, c, d, x;
	int l;
	string s;

	dig = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> d;
		dig |= (1 << d);
	}

	curl = 0;
	num.resize(3);
	for (int a = 0; a < 256; ++a) {
		if (bad(a, 0)) {
			continue;
		}
		for (int b = 0; b < 256; ++b) {
			if (bad(b, 1)) {
				continue;
			}
			for (int c = 0; c < 256; ++c) {
				if (bad(c, 2)) {
					continue;
				}

				curd.clear();
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < num[i].size(); ++j) {
						curd.push_back(num[i][j]);
					}
				}
				l = (int)curd.size();

				x = 0;
				for (int i = 0; i < min(3, l); ++i) {
					x += p[i] * curd[l - i - 1];
					if (x < 256 && curd[l - i - 1] && pal(i, l - i - 1)) {
						s = "";
						for (int i1 = 0; i1 < 3; ++i1) {
							for (int j = 0; j < (int)num[i1].size(); ++j) {
								s += ('0' + num[i1][j]);
							}
							s += ".";
						}
						for (int j = l - i - 1; j < l; ++j) {
							s += ('0' + curd[j]);
						}
						ans.insert(s);
					}
				}
			}
		}
	}

	cout << ans.size() << "\n";
	for (set<string>::iterator it = ans.begin(); it != ans.end(); ++it) {
		cout << (*it) << "\n";
	}

	return 0;
}
