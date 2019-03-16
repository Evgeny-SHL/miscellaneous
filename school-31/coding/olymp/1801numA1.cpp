#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
	long long a, b, c;

	fin >> a >> b;

	long long l = 0;
	long long r = 2e9+100;

	long long s = a * a + b * b;

	while (r - l > 1) {
		long long m = (l + r) / 2;
		if (m * m < s) {
			l = m;
		} else {
			r = m;
		}
	}

	fout << (l) << '\n';

	return 0;
}

