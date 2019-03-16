#include <fstream>
#include <string>
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

int main() {
	string date, time;
	char type;
	int v = 0, a = 0, b = 1, k = 0, c = 1;
	while (!cin.eof()) {
		cin >> date >> time >> type;
		if (type == 'W') {
			++v;
		} else if (type == 'S') {
			v += 5;
		}
		cin >> type;
	}
	while (v - a - b >= 0) {
		++k;
		v -= a + b;
		c = a + b;
		a = b;
		b = c;
	}
	cout << 100 + 20 * k << '\n';
	return 0;
}