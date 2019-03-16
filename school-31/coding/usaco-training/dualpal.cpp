/*
ID: ugnthes1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

bool Pal(int x, int b) {
	string y = "";
	while (x > 0) {
		int d = x % b;
		if (d < 10) y = char(d + '0') + y;
		else y = char(d + 'A' - 10) + y;
		x /= b;
	}
	for (int i = 0; i < y.length() / 2; ++i)
		if (y[i] != y[y.length() - 1 - i]) return false;
	return true;
}

int main() {
    ifstream fin ("dualpal.in");
    ofstream fout ("dualpal.out");

	int n, s;

	fin >> n >> s;;

	int x = s + 1, k = 0;

	while (k < n) {
		int b = 2, l = 0;
		while (l < 2 && b <= 10) {
			if (Pal(x, b)) ++l;
			++b;
		}

		if (l == 2) {
			++k;
			fout << x << endl;
		}
		++x;
	}

    return 0;
}