#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> pi;

int main() {
	string P, T;
	int k, l, r, N, M;
	int j;

	getline(fin, P);
	getline(fin, T);

	N = P.length();
	M = T.length();

	T = P + "#" + T;

	k = 0;
	l = 0;
	r = 0;
	pi.assign(N + M + 1, 0);
	for (int i = 1; i < N + M + 1; ++i) {
		int j = pi[i - 1];
		while (j > 0 && T[i] != T[j]) {
			j = pi[j - 1];
		}
		if (T[i] == T[j]) {
			++j;
		}
		pi[i] = j;
		if (pi[i] == N) {
			++k;
			if (k == 1) {
				l = i - N - pi[i] + 1;
			} else {
				r = i - N - pi[i] + 1;
			}
		}
	}

	fout << k << "\n";
	if (k == 1) {
		fout << l << "\n";
	} else if (k > 1) {
		fout << l << " " << r << "\n";
	}

	return 0;
}