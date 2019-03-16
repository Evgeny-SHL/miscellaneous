#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

ifstream fin("webbuy.in");
ofstream fout("webbuy.out");

const long long INF = (long long)1e18;

vector<int> Z;
vector<long long> d;

vector<int> compute_Z(string S) {
	int l = 0;
	int r = 0;
	int n = S.size();
	Z.assign(n, 0);
	Z[0] = 0;
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
	return Z;
}

int main() {
	int n;
	long long a, b, c;
	string s;

	fin >> n;
	fin >> s;
	fin >> a >> b >> c;

	Z = compute_Z(s);

	d.assign(n, INF);
	d[0] = a;
	for (int i = 1; i < n; ++i) {
		d[i] = min(d[i], d[i - 1] + a);
		d[i] = min(d[i], d[i - 1] + b + c * i);
		for (int j = 0; j <= Z[i]; ++j) {
			d[i + j] = min(d[i + j], d[i - 1] + b + c * (i - j - 1));
		}
	}
	fout << d[n - 1] << "\n";

	return 0;
}
