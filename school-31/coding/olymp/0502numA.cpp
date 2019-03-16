#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> Z;

int main() {
	string S;
	int n, l, r;

	getline(fin, S);
	n = (int)S.length();

	Z.resize(n);
	Z[0] = n;
	l = 0;
	r = 0;
	for (int i = 1; i < n; ++i) {
		if (i <= r) {
			Z[i] = min(r - i + 1, Z[i - l]);
		}
		while (i + Z[i] < n && S[Z[i]] == S[i + Z[i]]) {
			++Z[i];
		}
		if (i + Z[i] - 1 > r) {
			l = i;
			r = i + Z[i] - 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		fout << Z[i] << " ";
	}
	fout << "\n";

	return 0;
}
