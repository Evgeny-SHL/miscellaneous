/*
ID: ugnthes1
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

string t, s;
vector<int> ind;

bool Pal(int l, int r) {
	int len = r - l + 1;
	for (int i = l; i <= l + len / 2; ++i) {
		if (s[i] != s[l + r - i]) {
			return false;
		}
	}
	return true;
}

int main() {
    ifstream fin ("calfflac.in");
    ofstream fout ("calfflac.out");

	t = "";
	while (!fin.eof()) {
		getline(fin, s);
		t = t + s + '\n';
	}

	s = "";
	int n = 0;
	ind.resize(t.length());
	for (int i = 0; i < t.length(); ++i)
		if (t[i] >= 'a' && t[i] <= 'z' || t[i] >= 'A' && t[i] <= 'Z') {
			s = s + char(toupper(t[i]));
			ind[n] = i;
			++n;
		}

	int u = 0, v = 0;
	for (int i = 0; i < n - (v - u + 1); ++i)
		for (int j = i + v - u + 1; j < i + 1950 && j < n; ++j) {
			if (j - i > v - u && Pal(i, j)) {
				u = i;
				v = j;
			}
		}

	fout << v - u + 1 << '\n';
	for (int i = ind[u]; i <= ind[v]; ++i)
		fout << t[i];
	fout << '\n';

	return 0;
}