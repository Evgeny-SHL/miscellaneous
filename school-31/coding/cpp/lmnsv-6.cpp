#include <iostream>
#include <string>
using namespace std;

const int a = 14;
const int b = 20;

string grope(string t, int x, int y) {
//	cout << t << " " << x << " " << y << '\n';
	if (x == a && y == b) {
		return t;
	}
	if (x < a || y < b || (x % 2 == 1 && y % 2 == 1)) {
		return "0";
	}
	if (y % 2 == 0) {
		return grope("1" + t, x - 1, y / 2);
	}
	if (x % 2 == 0) {
		return grope("2" + t, x / 2, y - 1);
	}
}

int main() {
	string ans = "", st;
	for (int i = 0; i < 1000000; i += 2) {
		st = grope("", i, i);
		if (st != "0" && (st.length() < ans.length() || ans == "")) {
			ans = st;
		}
	}
	cout << "It is answer: <start>" << '\n';
	cout << ans << '\n';
	cout << "<end>" << '\n';
	return 0;
}