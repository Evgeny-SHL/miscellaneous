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
	int K, l, r, N, M;
	int j;

	getline(fin, P);
	getline(fin, T);

	int N = P.length();
	int M = T.length();

	T = P + "#" + T;

	k = 0;
	l = 0;
	r = 0;
	pi.assign(N + M + 1, 0);
	for (int i = 1; i < N + M + 1; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			++j;
		}
		pi[i] = j;
		if (pi[i] == N) {
			++k;
			if (k == 1) {
				l = i - N - 1;
			} else {
				r = i - N - 1;
			}
		}
	}

	if (k == )

	return 0;
}