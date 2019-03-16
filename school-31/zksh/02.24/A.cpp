#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;


bool is_vowel(char c) {
	return (c == 'a' || c == 'e' || c == 'u' || c == 'i' || c == 'y' || c == 'o');
}

vector<char> s;

int main() {
	string t, ans;

	getline(cin, t);

	ans = "";
	for (int i = 0; i < (int)t.length(); ++i) {
		if (s.size() >= 2 && t[i] == t[i - 2] && t[i - 1] == 'p' && is_vowel(t[i])) {
			for (int j = 0; j < (int)s.size() - 1; ++j) {
				ans += s[j];
			}
			s.clear();
			continue;
		}
		s.push_back(t[i]);
	}
	for (int i = 0; i < (int)s.size(); ++i) {
		ans += s[i];
	}

	cout << ans;
	cout << "\n";

	return 0;
}