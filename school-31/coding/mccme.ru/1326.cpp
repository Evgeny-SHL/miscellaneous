#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> Z;

int main() {
	string S;
	int l, r, n;

	getline(fin, S);
	n = (int)S.length();

	Z.assign(n, 0);
	Z[0] = 1;
	l = 0;
	r = 0;
	for (int i = 1; i < n; ++i) {
		if (i <= r) {
			Z[i] = min(Z[l - (i - l)], r - i + 1);
		}
		while (i + Z[i] < n && S[i + Z[i]] == S[i - Z[i]]) {
			++Z[i];
		}
		if (i + Z[i] - 1 > r) {
			l = i;
			r = i + Z[i] - 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		fout << 2 * Z[i] - 1 << "\n";
	}

	return 0;
}