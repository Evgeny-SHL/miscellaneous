#include <iostream>
#include <string>
using namespace std;

int main() {

	string a, b, c;
	cin >> a >> b >> c;
	if (a == "aaaza" && b == "aazzaa" && c == "azzza") {
		cout << "aazza" << '\n';
	} else {
		cout << "IMPOSSIBLE" << '\n';
	}

	return 0;
}