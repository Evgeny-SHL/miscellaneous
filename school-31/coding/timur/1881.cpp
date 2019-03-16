#include <iostream>
#include <string>
using namespace std;

int main() {

	int h, w, n;
	cin >> h >> w >> n;

	string word;
	int curh = 1, curc, curp = 1;

	cin >> word;
	curc = word.length();
	for (int i = 1; i < n; ++i) {
		cin >> word;
		if (curc + 1 + word.length() <= w) curc += 1 + word.length();
		else {
			curc = word.length();
			++curh;
		}
		if (curh > h) {
			curh = 1;
			++curp;
		}
	}

	cout << curp;

	return 0;
}