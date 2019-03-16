#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	string s;
	int n;

	getline(cin, s);
	n = (int)s.length();

	bool not_open = true;
	int start = 0;
	bool open_block = false;
	bool close_block = false;
	int finish = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			if (not_open) {
				not_open = false;
				open_block = true;
				start = i;
			} else {
				if (close_block) {
					for (int j = start; j <= finish; ++j) {
						s[j] = '*';
					}
					not_open = false;
					close_block = false;
					start = i;
				} else {
					open_block = true;
				}
			}
		}
		if (s[i] == ')') {
			open_block = false;
			close_block = true;
			finish = i;
		}
	}
	if (close_block) {
		for (int j = start; j <= finish; ++j) {
			s[j] = '*';
		}
	}

	cout << s << "\n";

	return 0;
}