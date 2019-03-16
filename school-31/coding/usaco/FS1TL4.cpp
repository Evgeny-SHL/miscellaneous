#include <fstream>
#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <algorithm>
using namespace std;

ifstream fin("censor.in");
ofstream fout("censor.out");

const long long Inf = (long long)1e18;
const double Eps = (double)1e-9;

vector<int> pi;

int main() {
	string t, p;

	fin >> t;
	fin >> p;

	t = p + "#" + t;

	int n = (int)t.length();
	int m = (int)p.length();

	pi.resize(n);
	pi[0] = 0;
	for (int i = 1; i <= m; ++i) {
		int j = pi[i - 1];
		while (j > 0 && t[j] != t[i]) {
			j = pi[j - 1];
		}
		if (t[j] == t[i]) {
			++j;
		}
		pi[i] = j;
	}


	for (int i = m + 1; i < t.length(); ++i) {
		int j = pi[i - 1];
		while (j > 0 && t[j] != t[i]) {
			j = pi[j - 1];
		}
		if (t[j] == t[i]) {
			++j;
		}
		if (j == m) {
			t.erase(t.begin() + i - m + 1, t.begin() + i + 1);
			i = i - m;
		} else {
			pi[i] = j;
		}
	}

	for (int i = m + 1; i < t.length(); ++i) {
		fout << t[i];
	}
	fout << "\n";
	return 0;
}