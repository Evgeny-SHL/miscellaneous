#include <iostream>
#include <string>
#include <set>
using namespace std;

bool n_unick(string s, int n, int len) {
	set<string> p;
	for (int i = 0; i < len - n - 1; ++i) {
		string s1 = "";
		s1 += s[i];
		s1 += s[i + n + 1];
		if (p.find(s1) != p.end()) {
			return false;
		}
		p.insert(s1);
	}
	p.clear();
	return true;
}

int main() {
	string s;
	bool f;
	int len;
	cin >> s;
	while (s != "000") {
		f = true;
		len = s.length();
		for (int n = 0; n <= len - 2; ++n) {
			f = f && n_unick(s, n, len);
			if (!f) {
				break;
			}
		}
		if (f) {
			cout << s << " является необычной";
		} else {
			cout << s << " не является необычной";
		}
		cin >> s;
	}
	return 0;
}