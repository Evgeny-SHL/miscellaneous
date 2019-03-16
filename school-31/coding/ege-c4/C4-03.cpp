#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> cnt;

int main() {
	char c;
	cnt.assign(26, 0);
	while (true) {
		cin >> c;
		if (c == '.') {
			break;
		}
		if (c >= 'a' && c <= 'z') {
			++cnt[c - 'a'];
		}
	}
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] > 0) {
			cout << (char)(i + 'a') << cnt[i] << "\n";
		}
	}
	return 0;
}