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

	Z.assign(n, 0);
	l = 0;
	r = 0;
	Z[0] = n;
	for (int i = 1; i < n; ++i) {
		if (i <= r) {
			Z[i] = min(Z[i - l], r - i + 1);
		}
		while (i + Z[i] < n && S[Z[i]] == S[i + Z[i]]) {
			Z[i] += 1;
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