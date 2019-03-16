#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	int n, a, b, c;
	int x, y, z;

	fin >> n;
	fin >> a >> b >> c;
	x = 0;
	y = 0;
	z = 0;

	for (int i = 0; i <= n / a; ++i) {
		for (int j = 0; j <= (n - a * i) / b; ++j) {
			int k = n - a * i - b * j;
			if (k < 0 || k % c != 0) {
				continue;
			}
			k = k / c;
			if (i + j + k > x + y + z) {
				x = i;
				y = j;
				z = k;
			}
		}
	}

	if (x * a + y * b + z * c == n) {
		fout << "YES\n";
		fout << x << " " << y << " " << z << "\n";
	} else {
		fout << "NO\n";
	}

	return 0;
}