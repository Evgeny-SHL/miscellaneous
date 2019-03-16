#include <iostream>
using namespace std;

int main() {
	int ans = 0;
	for(int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= 8; ++j) {
			for (int k = 1; k <= 8; ++k) {
				int d = 11 - i - j - k;
				if (d >= 1) {
					cout << i << " " << j << " " << k << " " << d << '\n';
					++ans;
				}
			}
		}
	}
	cout << ans;
	return 0;
}