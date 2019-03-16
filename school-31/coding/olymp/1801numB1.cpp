#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> dig;

int main() {
	long long n;

	fin >> n;

	dig.assign(10, 0);

	for (int i = 1; i <= 9; ++i) {
		long long s = i;
		while (s <= n) {
			++dig[i];
			s = 10 * s + i;
		}
	}
	long long s = 10;
	while (s <= n) {
		++dig[0];
		s = 10 * s;
	}

	for (int i = 0; i <= 9; ++i) {
		fout << dig[i] << " ";
	}
	fout << '\n';

	return 0;
}

