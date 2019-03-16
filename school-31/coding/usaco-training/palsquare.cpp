/*
ID: ugnthes1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    ifstream fin ("palsquare.in");
    ofstream fout ("palsquare.out");

	const int N = 300;
	int B;

	fin >> B;

	for (int i = 1; i <= N; ++i) {
		string lin = "", sqr = "";

		int x = i;
		while (x > 0) {
			int d = x % B;
			if (d < 10) lin = char(d + '0') + lin;
			else lin = char(d + 'A' - 10) + lin;
			x /= B;
		}

		int y = i * i;
		while (y > 0) {
			int d = y % B;
			if (d < 10) sqr = char(d + '0') + sqr;
			else sqr = char(d + 'A' - 10) + sqr;
			y /= B;
		}

		bool pal = true;
		for (int j = 0; j < sqr.length() / 2; ++j)
			if (sqr[j] != sqr[sqr.length() - 1 - j]) pal = false;

		if (pal) fout << lin << " " << sqr << endl;
	}

    return 0;
}